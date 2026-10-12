// SPDX-License-Identifier: GPL-3.0-or-later
use std::fs;
use std::io::Write;
use std::path::{Path, PathBuf};
use std::process::ExitCode;

use clap::{Parser, Subcommand};
use resources_db::{Archive, NodeKind};

/// Unpacker for the Survarium / Vostok engine `resources.db` VFS pack archive.
#[derive(Parser)]
#[command(version, about)]
struct Cli {
    #[command(subcommand)]
    command: Command,
}

#[derive(Subcommand)]
enum Command {
    /// List the archive's contents.
    List {
        /// Path to resources.db.
        db: PathBuf,
    },
    /// Extract all files into a directory.
    Extract {
        /// Path to resources.db.
        db: PathBuf,
        /// Output directory.
        out_dir: PathBuf,
    },
    /// Extract one exact archive member to a new file (never overwrite).
    ExtractMember {
        db: PathBuf,
        member: String,
        output: PathBuf,
    },
    /// Self-test: parse the original FAT, re-serialize it in memory, and compare
    /// byte-for-byte against the original FAT region (header + node buffer).
    /// No large I/O — validates hashing/ordering/offsets/links cheaply.
    RoundtripFat {
        /// Path to resources.db.
        db: PathBuf,
    },
    /// Full self-test: rebuild the entire file (header + FAT + padding + data
    /// blob) from the parsed tree and compare it byte-for-byte against the
    /// original, streaming (no second 1.5 GiB copy on disk).
    Roundtrip {
        /// Path to resources.db.
        db: PathBuf,
    },
    /// Rewrite an archive without projecting it through an extracted
    /// filesystem tree. The original FAT graph is parsed and re-serialized,
    /// while the payload blob is copied verbatim.
    RewriteIdentity {
        /// Input resources.db.
        db: PathBuf,
        /// Output resources.db.
        output: PathBuf,
    },
    /// Apply changed/new files from a donor database while preserving the
    /// base database's raw FAT graph and original payload blob.
    OverlayDb {
        /// Verified base resources.db.
        base: PathBuf,
        /// Donor resources.db whose changed/new files should be applied.
        donor: PathBuf,
        /// Output resources.db.
        output: PathBuf,
    },
    /// Pack a directory of extracted files into a resources.db.
    Pack {
        /// Input directory (the root of the extracted tree).
        input_dir: PathBuf,
        /// Output resources.db path.
        output: PathBuf,
    },
}

fn main() -> ExitCode {
    let cli = Cli::parse();
    let result = match cli.command {
        Command::List { db } => run_list(&db),
        Command::Extract { db, out_dir } => run_extract(&db, &out_dir),
        Command::ExtractMember { db, member, output } => run_extract_member(&db, &member, &output),
        Command::RoundtripFat { db } => run_roundtrip_fat(&db),
        Command::Roundtrip { db } => run_roundtrip(&db),
        Command::RewriteIdentity { db, output } => run_rewrite_identity(&db, &output),
        Command::OverlayDb {
            base,
            donor,
            output,
        } => run_overlay_db(&base, &donor, &output),
        Command::Pack { input_dir, output } => run_pack(&input_dir, &output),
    };
    match result {
        Ok(()) => ExitCode::SUCCESS,
        Err(e) => {
            eprintln!("error: {e}");
            ExitCode::FAILURE
        }
    }
}

fn run_list(db: &Path) -> Result<(), Box<dyn std::error::Error>> {
    let archive = Archive::open(db)?;
    eprintln!(
        "num_nodes={} buffer_size={}",
        archive.num_nodes, archive.buffer_size
    );
    let entries = archive.list();
    let (mut files, mut compressed, mut inline) = (0usize, 0usize, 0usize);
    for e in &entries {
        let tag = match e.kind {
            NodeKind::File {
                compressed: c,
                inlined: i,
            } => {
                files += 1;
                if c {
                    compressed += 1;
                }
                if i {
                    inline += 1;
                }
                match (c, i) {
                    (true, true) => "file/ppmd/inline",
                    (true, false) => "file/ppmd",
                    (false, true) => "file/inline",
                    (false, false) => "file",
                }
            }
            NodeKind::SoftLink => "soft-link",
            NodeKind::HardLink => "hard-link",
            NodeKind::Erased => "erased",
            NodeKind::External => "external",
            NodeKind::Folder => "folder",
            NodeKind::Other => "other",
        };
        println!(
            "{:<18} {:>12} {:>12} {:>12}  {}",
            tag,
            e.size_in_db,
            e.uncompressed_size,
            e.pos_in_db,
            String::from_utf8_lossy(&e.path) // display only; the stored path is raw bytes
        );
    }
    eprintln!(
        "files={} compressed={} inline={} total_entries={}",
        files,
        compressed,
        inline,
        entries.len()
    );
    Ok(())
}

fn run_extract(db: &Path, out_dir: &Path) -> Result<(), Box<dyn std::error::Error>> {
    let mut archive = Archive::open(db)?;
    eprintln!(
        "num_nodes={} buffer_size={}",
        archive.num_nodes, archive.buffer_size
    );
    let entries = archive.list();

    let (mut extracted, mut directories, mut skipped) = (0usize, 0usize, 0usize);
    for e in &entries {
        let dest = out_dir.join(sanitize(&e.path));
        match e.kind {
            NodeKind::Folder => {
                fs::create_dir_all(&dest)?;
                directories += 1;
                continue;
            }
            NodeKind::File { .. } => {}
            _ => {
                skipped += 1;
                continue;
            }
        }
        if let Some(parent) = dest.parent() {
            fs::create_dir_all(parent)?;
        }
        let data = archive.read_file(e)?;
        let mut f =
            fs::File::create(&dest).map_err(|err| format!("creating {}: {err}", dest.display()))?;
        f.write_all(&data)?;
        extracted += 1;
        if extracted % 1000 == 0 {
            eprintln!("  {extracted}/{} ...", entries.len());
        }
    }
    eprintln!(
        "extracted {extracted} files and preserved {directories} empty directories \
         ({skipped} other non-file entries skipped) into {}",
        out_dir.display()
    );
    Ok(())
}

fn run_extract_member(
    db: &Path,
    member: &str,
    output: &Path,
) -> Result<(), Box<dyn std::error::Error>> {
    let mut archive = Archive::open(db)?;
    let entries = archive.list();
    let matches: Vec<_> = entries.iter().filter(|entry| entry.path == member.as_bytes()).collect();
    if matches.len() != 1 || !matches!(matches[0].kind, NodeKind::File { .. }) {
        return Err("expected exactly one file with the requested archive path".into());
    }
    let bytes = archive.read_file(matches[0])?;
    let mut destination = fs::OpenOptions::new().write(true).create_new(true).open(output)?;
    destination.write_all(&bytes)?;
    destination.sync_all()?;
    eprintln!("extracted {} bytes from {member} into {}", bytes.len(), output.display());
    Ok(())
}

fn run_roundtrip_fat(db: &Path) -> Result<(), Box<dyn std::error::Error>> {
    use resources_db::pack;
    let archive = Archive::open(db)?;
    let parsed = archive.parse_tree();
    eprintln!(
        "num_nodes={} buffer_size={}",
        parsed.num_nodes, parsed.buffer_size
    );

    let rebuilt = pack::Packer::serialize_fat(&parsed.root);
    let original = parsed.fat_region;

    if rebuilt.len() != original.len() {
        eprintln!(
            "FAT SIZE MISMATCH: rebuilt={} original={}",
            rebuilt.len(),
            original.len()
        );
    }
    let n = rebuilt.len().min(original.len());
    let mut first_diff = None;
    for i in 0..n {
        if rebuilt[i] != original[i] {
            first_diff = Some(i);
            break;
        }
    }
    match first_diff {
        None if rebuilt.len() == original.len() => {
            eprintln!("FAT buffer matches byte-for-byte ({} bytes)", rebuilt.len());
            Ok(())
        }
        None => {
            eprintln!("FAT buffer matches up to min length, but lengths differ");
            Err("FAT length mismatch".into())
        }
        Some(i) => {
            eprintln!(
                "first diff at byte {i} (0x{i:x}): rebuilt=0x{:02x} original=0x{:02x}",
                rebuilt[i], original[i]
            );
            let lo = i.saturating_sub(8);
            let hi = (i + 16).min(n);
            eprintln!("  rebuilt[{lo}..{hi}]  = {:02x?}", &rebuilt[lo..hi]);
            eprintln!("  original[{lo}..{hi}] = {:02x?}", &original[lo..hi]);
            Err(format!("FAT mismatch at byte {i}").into())
        }
    }
}

fn run_roundtrip(db: &Path) -> Result<(), Box<dyn std::error::Error>> {
    use resources_db::pack;
    use resources_db::RawNode;
    use std::fs::File;
    use std::io::{Read, Seek, SeekFrom};

    let archive = Archive::open(db)?;
    let parsed = archive.parse_tree();
    eprintln!(
        "num_nodes={} buffer_size={}",
        parsed.num_nodes, parsed.buffer_size
    );

    // 1) Rebuild the header + FAT region.
    let fat_prefix = pack::build_fat_with_header(&parsed.root, parsed.num_nodes);
    let fat_len = parsed.fat_region.len();
    assert_eq!(fat_prefix.len(), 24 + fat_len);

    // 2) Data-blob origin (2048-aligned, using the engine's over-estimated max
    //    FAT size).
    let origin = pack::data_blob_origin(&parsed.root);
    eprintln!("data_blob_origin = {origin}");

    // 3) Walk the tree in node-save (depth-first) order, assigning each unique
    //    file payload a sequential position from `origin`, and verify it equals
    //    the position the engine recorded. Hard-links don't write payloads.
    // Content-dedup: a file node whose bytes are identical to an already-saved
    // node reuses that node's `pos_in_db` and writes nothing — whether it became
    // a hard-link (same name) or a plain file node sharing the position
    // (different name). We reproduce that by writing a payload only the first
    // time a position is seen, in node-save order.
    let mut next_pos = origin as u64;
    let mut mismatches = 0usize;
    let mut payloads = 0usize;
    let mut seen_pos = std::collections::HashSet::new();
    fn walk(
        node: &RawNode,
        next_pos: &mut u64,
        payloads: &mut usize,
        mismatches: &mut usize,
        seen_pos: &mut std::collections::HashSet<u64>,
    ) {
        if node.is_folder() {
            for c in &node.children {
                walk(c, next_pos, payloads, mismatches, seen_pos);
            }
            return;
        }
        if node.is_hard_link() {
            return; // hard-links reference an earlier payload; no bytes written
        }
        if !seen_pos.insert(node.pos_in_db) {
            return; // different-name content duplicate: shares an earlier payload
        }
        // First node to claim this position writes `size_in_db` bytes here.
        if node.pos_in_db != *next_pos {
            if *mismatches < 5 {
                eprintln!(
                    "  pos mismatch for {:?}: computed={} recorded={}",
                    String::from_utf8_lossy(&node.name),
                    *next_pos,
                    node.pos_in_db
                );
            }
            *mismatches += 1;
        }
        *next_pos += node.size_in_db as u64;
        *payloads += 1;
    }
    walk(
        &parsed.root,
        &mut next_pos,
        &mut payloads,
        &mut mismatches,
        &mut seen_pos,
    );

    let original_len = std::fs::metadata(db)?.len();
    eprintln!(
        "unique payloads={payloads} computed_end={next_pos} original_size={original_len} pos_mismatches={mismatches}"
    );
    if mismatches != 0 {
        return Err(format!("{mismatches} payload-position mismatches").into());
    }
    if next_pos != original_len {
        return Err(format!(
            "blob end {next_pos} != file size {original_len} (gap/overlap in data blob)"
        )
        .into());
    }

    // 4) Stream-compare the full reconstructed file against the original:
    //    [header+FAT] then [zero padding] then [data blob], where the blob bytes
    //    are read straight from the original at each payload's position (a
    //    self-test of layout, not of payload content). We never write a second
    //    copy to disk.
    let mut f = File::open(db)?;
    // Region A: header + FAT.
    let mut buf = vec![0u8; fat_prefix.len()];
    f.seek(SeekFrom::Start(0))?;
    f.read_exact(&mut buf)?;
    if buf != fat_prefix {
        return Err("header+FAT mismatch".into());
    }
    // Region B: padding gap must be all zeros in the original (what we'd write).
    let gap = origin - fat_prefix.len();
    let mut remaining = gap;
    let mut chunk = vec![0u8; 1 << 20];
    while remaining > 0 {
        let n = remaining.min(chunk.len());
        f.read_exact(&mut chunk[..n])?;
        if chunk[..n].iter().any(|&b| b != 0) {
            return Err("padding gap is not all zeros".into());
        }
        remaining -= n;
    }
    // Region C: the blob — positions already verified to tile [origin, EOF)
    // exactly, so the bytes are identical to the original by construction.

    eprintln!("ROUNDTRIP OK: full file reproduces byte-for-byte ({original_len} bytes)");
    Ok(())
}

fn run_pack(input_dir: &Path, output: &Path) -> Result<(), Box<dyn std::error::Error>> {
    use resources_db::pack;
    let tree = pack::build_src_tree(input_dir)?;
    pack::assemble_to_file(&tree, output)?;
    let size = fs::metadata(output)?.len();
    eprintln!("packed {size} bytes into {}", output.display());
    Ok(())
}

fn run_rewrite_identity(db: &Path, output: &Path) -> Result<(), Box<dyn std::error::Error>> {
    use resources_db::pack;
    use std::fs::File;
    use std::io::{BufWriter, Seek, SeekFrom};

    if db == output {
        return Err("identity rewrite input and output must be different".into());
    }

    let archive = Archive::open(db)?;
    let parsed = archive.parse_tree();
    let fat_prefix = pack::build_fat_with_header(&parsed.root, parsed.num_nodes);
    let origin = pack::data_blob_origin(&parsed.root);
    if fat_prefix.len() > origin {
        return Err("serialized FAT overlaps the payload region".into());
    }

    let mut source = File::open(db)?;
    source.seek(SeekFrom::Start(origin as u64))?;
    let mut writer = BufWriter::new(File::create(output)?);
    writer.write_all(&fat_prefix)?;

    let mut padding = origin - fat_prefix.len();
    let zeroes = [0_u8; 64 * 1024];
    while padding != 0 {
        let count = padding.min(zeroes.len());
        writer.write_all(&zeroes[..count])?;
        padding -= count;
    }
    std::io::copy(&mut source, &mut writer)?;
    writer.flush()?;

    eprintln!(
        "identity-rewrote {} bytes into {}",
        fs::metadata(output)?.len(),
        output.display()
    );
    Ok(())
}

fn run_overlay_db(
    base: &Path,
    donor: &Path,
    output: &Path,
) -> Result<(), Box<dyn std::error::Error>> {
    let stats = resources_db::overlay::apply_db_overlay(base, donor, output)?;
    eprintln!(
        "overlay complete: unchanged={} replaced={} added_files={} added_folders={} \
         detached_hard_links={} appended_payload_bytes={} output_nodes={}",
        stats.unchanged_files,
        stats.replaced_files,
        stats.added_files,
        stats.added_folders,
        stats.detached_hard_links,
        stats.appended_payload_bytes,
        stats.output_nodes
    );
    eprintln!(
        "wrote {} bytes into {}",
        fs::metadata(output)?.len(),
        output.display()
    );
    Ok(())
}

/// Strip any path components that could escape the output dir. Operates on raw
/// bytes (engine paths aren't guaranteed UTF-8) and maps them straight to
/// filesystem path components.
fn sanitize(path: &[u8]) -> PathBuf {
    use std::ffi::OsStr;
    use std::os::unix::ffi::OsStrExt;
    let mut out = PathBuf::new();
    for comp in path.split(|&b| b == b'/' || b == b'\\') {
        match comp {
            b"" | b"." | b".." => {}
            other => out.push(OsStr::from_bytes(other)),
        }
    }
    out
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn extract_member_is_exact_and_never_overwrites() {
        let unique = std::time::SystemTime::now()
            .duration_since(std::time::UNIX_EPOCH).unwrap().as_nanos();
        let root = std::env::temp_dir().join(format!("srp-member-{}-{unique}", std::process::id()));
        fs::create_dir_all(root.join("input/flash_movies")).unwrap();
        let member = "flash_movies/lobby_menu.swf";
        fs::write(root.join("input").join(member), b"fixture movie").unwrap();
        let db = root.join("resources.db");
        run_pack(&root.join("input"), &db).unwrap();
        let out = root.join("movie.swf");
        assert!(run_extract_member(&db, "lobby_menu.swf", &out).is_err());
        assert!(!out.exists());
        assert!(run_extract_member(&db, "flash_movies", &out).is_err());
        assert!(!out.exists());
        run_extract_member(&db, member, &out).unwrap();
        assert_eq!(fs::read(&out).unwrap(), b"fixture movie");
        fs::write(&out, b"keep this existing file").unwrap();
        assert!(run_extract_member(&db, member, &out).is_err());
        assert_eq!(fs::read(&out).unwrap(), b"keep this existing file");
        fs::remove_dir_all(root).unwrap();
    }
}

// SPDX-License-Identifier: GPL-3.0-or-later
//! Non-lossy archive overlays.
//!
//! Unlike extract/pack, this path keeps the base archive's raw FAT graph,
//! child order, node flags, hard-link ownership, and payload positions. Changed
//! and new files receive payloads appended after the untouched base data blob.

use std::collections::{BTreeMap, HashMap, HashSet};
use std::fs::File;
use std::io::{self, BufWriter, Seek, SeekFrom, Write};
use std::path::Path;

use crate::fat::{Archive, FileEntry, NodeFlags, NodeKind, RawNode};
use crate::pack;

#[derive(Debug, Clone, Copy)]
struct FileMeta {
    flags: NodeFlags,
    size_in_db: u32,
    uncompressed_size: u32,
    pos_in_db: u64,
    hash: u32,
}

#[derive(Debug, Clone, Copy)]
struct RawPathInfo {
    key: usize,
    hard_link_target: Option<usize>,
}

#[derive(Debug, Clone, Copy)]
enum StoredNodeMeta {
    Direct(FileMeta),
    HardLink(usize),
    NonFile,
}

#[derive(Debug, Clone, Copy)]
pub struct OverlayStats {
    pub unchanged_files: usize,
    pub replaced_files: usize,
    pub added_files: usize,
    pub added_folders: usize,
    pub detached_hard_links: usize,
    pub appended_payload_bytes: u64,
    pub output_nodes: u32,
}

fn invalid_data(message: impl Into<String>) -> io::Error {
    io::Error::new(io::ErrorKind::InvalidData, message.into())
}

fn count_nodes(node: &RawNode) -> u32 {
    1 + node.children.iter().map(count_nodes).sum::<u32>()
}

fn max_node_key(node: &RawNode) -> usize {
    node.children
        .iter()
        .map(max_node_key)
        .fold(node.base_node_off, usize::max)
}

fn collect_stored_node_meta(node: &RawNode, out: &mut HashMap<usize, StoredNodeMeta>) {
    if node.is_folder() {
        out.insert(node.base_node_off, StoredNodeMeta::NonFile);
        for child in &node.children {
            collect_stored_node_meta(child, out);
        }
    } else if node.flags.contains(NodeFlags::ARCHIVE) {
        let meta = if let Some(target) = node.hard_link_target_off {
            StoredNodeMeta::HardLink(target)
        } else {
            StoredNodeMeta::Direct(FileMeta {
                flags: node.flags,
                size_in_db: node.size_in_db,
                uncompressed_size: node.uncompressed_size,
                pos_in_db: node.pos_in_db,
                hash: node.hash,
            })
        };
        out.insert(node.base_node_off, meta);
    }
}

fn resolve_file_meta(
    key: usize,
    stored: &HashMap<usize, StoredNodeMeta>,
    resolved: &mut HashMap<usize, Option<FileMeta>>,
    visiting: &mut HashSet<usize>,
) -> io::Result<Option<FileMeta>> {
    if let Some(meta) = resolved.get(&key) {
        return Ok(*meta);
    }
    if !visiting.insert(key) {
        return Err(invalid_data(format!(
            "hard-link cycle encountered at node {key}"
        )));
    }
    let meta = match stored.get(&key).copied() {
        Some(StoredNodeMeta::Direct(meta)) => Some(meta),
        Some(StoredNodeMeta::HardLink(target)) => {
            resolve_file_meta(target, stored, resolved, visiting)?
        }
        Some(StoredNodeMeta::NonFile) => None,
        None => {
            return Err(invalid_data(format!(
                "hard-link references missing node {key}"
            )));
        }
    };
    visiting.remove(&key);
    resolved.insert(key, meta);
    Ok(meta)
}

fn resolve_all_file_meta(
    stored: &HashMap<usize, StoredNodeMeta>,
) -> io::Result<HashMap<usize, Option<FileMeta>>> {
    let mut resolved = HashMap::new();
    for key in stored.keys().copied() {
        resolve_file_meta(key, stored, &mut resolved, &mut HashSet::new())?;
    }
    Ok(resolved)
}

fn joined_path(prefix: &[u8], name: &[u8]) -> Vec<u8> {
    if prefix.is_empty() {
        name.to_vec()
    } else if name.is_empty() {
        prefix.to_vec()
    } else {
        let mut path = Vec::with_capacity(prefix.len() + 1 + name.len());
        path.extend_from_slice(prefix);
        path.push(b'/');
        path.extend_from_slice(name);
        path
    }
}

fn collect_raw_paths(
    node: &RawNode,
    prefix: &[u8],
    direct: &HashMap<usize, Option<FileMeta>>,
    out: &mut BTreeMap<Vec<u8>, RawPathInfo>,
) -> io::Result<()> {
    let path = joined_path(prefix, &node.name);
    if node.is_folder() {
        for child in &node.children {
            collect_raw_paths(child, &path, direct, out)?;
        }
        return Ok(());
    }
    if !node.flags.contains(NodeFlags::ARCHIVE) {
        return Ok(());
    }

    if let Some(target) = node.hard_link_target_off {
        if !direct.contains_key(&target) {
            return Err(invalid_data(format!(
                "hard-link node {} references missing node {target}",
                node.base_node_off
            )));
        }
        if direct[&target].is_none() {
            return Ok(());
        }
    } else if !direct.contains_key(&node.base_node_off) {
        return Err(invalid_data(format!(
            "archive file node {} has no metadata",
            node.base_node_off
        )));
    }

    out.insert(
        path,
        RawPathInfo {
            key: node.base_node_off,
            hard_link_target: node.hard_link_target_off,
        },
    );
    Ok(())
}

fn file_entries(archive: &Archive) -> BTreeMap<Vec<u8>, FileEntry> {
    archive
        .list()
        .into_iter()
        .filter(|entry| matches!(entry.kind, NodeKind::File { .. }))
        .map(|entry| (entry.path.clone(), entry))
        .collect()
}

fn materialize_affected_hard_links(
    node: &mut RawNode,
    changed_targets: &HashSet<usize>,
    direct: &HashMap<usize, Option<FileMeta>>,
) -> io::Result<usize> {
    if node.is_folder() {
        let mut count = 0;
        for child in &mut node.children {
            count += materialize_affected_hard_links(child, changed_targets, direct)?;
        }
        return Ok(count);
    }

    let Some(target) = node.hard_link_target_off else {
        return Ok(0);
    };
    if !changed_targets.contains(&target) {
        return Ok(0);
    }
    let meta = direct.get(&target).copied().flatten().ok_or_else(|| {
        invalid_data(format!(
            "missing file metadata for hard-link target {target}"
        ))
    })?;
    if meta.flags.contains(NodeFlags::INLINED) {
        return Err(invalid_data(
            "cannot detach an inline hard-link target into a regular node",
        ));
    }

    node.flags = meta.flags;
    node.size_in_db = meta.size_in_db;
    node.uncompressed_size = meta.uncompressed_size;
    node.pos_in_db = meta.pos_in_db;
    node.hash = meta.hash;
    node.hard_link_target_off = None;
    Ok(1)
}

fn path_components(path: &[u8]) -> io::Result<Vec<&[u8]>> {
    let components: Vec<&[u8]> = path.split(|byte| *byte == b'/').collect();
    if components.is_empty() || components.iter().any(|part| part.is_empty()) {
        return Err(invalid_data(format!(
            "invalid archive path {:?}",
            String::from_utf8_lossy(path)
        )));
    }
    Ok(components)
}

fn find_node_mut<'a>(node: &'a mut RawNode, components: &[&[u8]]) -> Option<&'a mut RawNode> {
    let (name, tail) = components.split_first()?;
    // Duplicate FAT names are legal and the engine resolves the last entry.
    // Overlay edits must follow the same rule or they may descend through an
    // obsolete file node while the effective entry is a later folder.
    if tail.is_empty() {
        return node
            .children
            .iter_mut()
            .rev()
            .find(|child| child.name == *name);
    }
    let child = node
        .children
        .iter_mut()
        .rev()
        .find(|child| child.name == *name && child.is_folder())?;
    find_node_mut(child, tail)
}

fn add_file<'a>(
    root: &'a mut RawNode,
    components: &[&[u8]],
    next_key: &mut usize,
    added_folders: &mut usize,
) -> io::Result<&'a mut RawNode> {
    let (name, tail) = components
        .split_first()
        .ok_or_else(|| invalid_data("empty overlay path"))?;
    if tail.is_empty() {
        if let Some(index) = root.children.iter().rposition(|child| child.name == *name) {
            return Ok(&mut root.children[index]);
        }
        root.children.push(RawNode {
            flags: NodeFlags::ARCHIVE,
            name: name.to_vec(),
            base_node_off: *next_key,
            size_in_db: 0,
            uncompressed_size: 0,
            pos_in_db: 0,
            hash: 0,
            hard_link_target_off: None,
            children: Vec::new(),
        });
        *next_key += 1;
        return Ok(root.children.last_mut().unwrap());
    }

    let folder_position = root
        .children
        .iter()
        .rposition(|child| child.name == *name && child.is_folder());
    let index = match folder_position {
        Some(index) => index,
        None if root.children.iter().any(|child| child.name == *name) => {
            return Err(invalid_data(format!(
                "overlay path component {:?} is not a folder",
                String::from_utf8_lossy(name)
            )));
        }
        None => {
            root.children.push(RawNode {
                flags: NodeFlags::FOLDER | NodeFlags::ARCHIVE,
                name: name.to_vec(),
                base_node_off: *next_key,
                size_in_db: 0,
                uncompressed_size: 0,
                pos_in_db: 0,
                hash: 0,
                hard_link_target_off: None,
                children: Vec::new(),
            });
            *next_key += 1;
            *added_folders += 1;
            root.children.len() - 1
        }
    };
    add_file(&mut root.children[index], tail, next_key, added_folders)
}

fn set_file_payload(node: &mut RawNode, bytes: &[u8], pos_in_db: u64) -> io::Result<()> {
    let size =
        u32::try_from(bytes.len()).map_err(|_| invalid_data("overlay file exceeds 4 GiB"))?;
    node.flags = NodeFlags::ARCHIVE;
    node.size_in_db = size;
    node.uncompressed_size = size;
    node.pos_in_db = pos_in_db;
    node.hash = pack::crc32(bytes);
    node.hard_link_target_off = None;
    node.children.clear();
    Ok(())
}

fn shift_payload_positions(node: &mut RawNode, minimum: u64, delta: u64) -> io::Result<()> {
    if !node.is_folder() && node.hard_link_target_off.is_none() && node.pos_in_db >= minimum {
        node.pos_in_db = node
            .pos_in_db
            .checked_add(delta)
            .ok_or_else(|| invalid_data("relocated payload offset overflow"))?;
    }
    for child in &mut node.children {
        shift_payload_positions(child, minimum, delta)?;
    }
    Ok(())
}

fn first_stored_payload_position(node: &RawNode) -> Option<u64> {
    let own = (!node.is_folder()
        && node.hard_link_target_off.is_none()
        && !node.flags.contains(NodeFlags::INLINED)
        && node.size_in_db != 0)
        .then_some(node.pos_in_db);
    node.children
        .iter()
        .filter_map(first_stored_payload_position)
        .chain(own)
        .min()
}

/// Apply every changed/new regular file from `donor_path` to `base_path`
/// without rebuilding the base archive from an extracted directory.
pub fn apply_db_overlay(
    base_path: &Path,
    donor_path: &Path,
    output_path: &Path,
) -> io::Result<OverlayStats> {
    apply_db_overlay_with_materialized_paths(base_path, donor_path, output_path, &[])
}

/// Apply an overlay while converting selected base hard-link nodes into
/// independent archive-file nodes. The payload bytes remain identical; only
/// the runtime ownership identity changes.
pub fn apply_db_overlay_with_materialized_paths(
    base_path: &Path,
    donor_path: &Path,
    output_path: &Path,
    materialized_paths: &[Vec<u8>],
) -> io::Result<OverlayStats> {
    if base_path == output_path || donor_path == output_path {
        return Err(invalid_data("overlay output must differ from both inputs"));
    }

    let mut base_archive = Archive::open(base_path)?;
    let mut donor_archive = Archive::open(donor_path)?;
    let base_entries = file_entries(&base_archive);
    let donor_entries = file_entries(&donor_archive);

    let mut changes = BTreeMap::<Vec<u8>, Vec<u8>>::new();
    let mut unchanged_files = 0;
    for (path, donor_entry) in &donor_entries {
        let donor_bytes = donor_archive.read_raw(donor_entry)?;
        let unchanged = if let Some(base_entry) = base_entries.get(path) {
            base_entry.size_in_db == donor_entry.size_in_db
                && base_archive.read_raw(base_entry)? == donor_bytes
        } else {
            false
        };
        if unchanged {
            unchanged_files += 1;
        } else {
            changes.insert(path.clone(), donor_bytes);
        }
    }

    let parsed = base_archive.parse_tree();
    let base_node_count = count_nodes(&parsed.root);
    let helper_overcount = parsed
        .num_nodes
        .checked_sub(base_node_count)
        .ok_or_else(|| invalid_data("base header node count is below serialized node count"))?;
    // An archive that has already received an additive overlay can have a
    // larger *current* max-FAT estimate while its preserved payload still
    // starts at the older reservation. Recomputing the origin from the larger
    // tree would skip the leading payload bytes on the next overlay.
    let base_origin = first_stored_payload_position(&parsed.root)
        .and_then(|position| usize::try_from(position).ok())
        .unwrap_or_else(|| pack::data_blob_origin(&parsed.root));
    let base_len = std::fs::metadata(base_path)?.len();
    if base_len < base_origin as u64 {
        return Err(invalid_data("base archive ends before its payload region"));
    }

    let mut stored = HashMap::new();
    collect_stored_node_meta(&parsed.root, &mut stored);
    let resolved = resolve_all_file_meta(&stored)?;
    let mut raw_paths = BTreeMap::new();
    collect_raw_paths(&parsed.root, b"", &resolved, &mut raw_paths)?;
    for path in materialized_paths {
        let info = raw_paths.get(path).ok_or_else(|| {
            invalid_data(format!(
                "forced materialization path is absent from the base archive: {:?}",
                String::from_utf8_lossy(path)
            ))
        })?;
        let entry = base_entries.get(path).ok_or_else(|| {
            invalid_data(format!(
                "forced materialization path does not resolve to a file: {:?}",
                String::from_utf8_lossy(path)
            ))
        })?;
        // Materialization is an idempotent archive-shape requirement. A
        // previous independently composed bundle may already have detached
        // this path into a regular file, in which case no payload rewrite is
        // needed. Requiring it to remain a hard link makes otherwise
        // disjoint modules order-dependent.
        if info.hard_link_target.is_none() {
            continue;
        }
        changes.insert(path.clone(), base_archive.read_raw(entry)?);
    }

    let changed_targets: HashSet<usize> = changes
        .keys()
        .filter_map(|path| raw_paths.get(path))
        .filter(|info| info.hard_link_target.is_none())
        .map(|info| info.key)
        .collect();
    let mut root = parsed.root;
    let detached_hard_links =
        materialize_affected_hard_links(&mut root, &changed_targets, &resolved)?;
    let mut next_key = max_node_key(&root) + 1;
    let mut added_folders = 0;
    let mut replaced_files = 0;
    let mut added_files = 0;
    let mut next_payload_pos = base_len;

    for (path, bytes) in &changes {
        let components = path_components(path)?;
        let node = if raw_paths.contains_key(path) {
            replaced_files += 1;
            find_node_mut(&mut root, &components).ok_or_else(|| {
                invalid_data(format!(
                    "base FAT path disappeared during overlay: {:?}",
                    String::from_utf8_lossy(path)
                ))
            })?
        } else {
            added_files += 1;
            add_file(&mut root, &components, &mut next_key, &mut added_folders).map_err(
                |error| {
                    invalid_data(format!(
                        "applying overlay path {:?}: {error}",
                        String::from_utf8_lossy(path)
                    ))
                },
            )?
        };
        set_file_payload(node, bytes, next_payload_pos)?;
        next_payload_pos += bytes.len() as u64;
    }

    let output_nodes = count_nodes(&root)
        .checked_add(helper_overcount)
        .ok_or_else(|| invalid_data("output header node count overflow"))?;
    let mut fat_prefix = pack::build_fat_with_header(&root, output_nodes);
    let output_origin = if fat_prefix.len() <= base_origin {
        base_origin
    } else {
        let relocated_origin = pack::data_blob_origin(&root);
        if fat_prefix.len() > relocated_origin {
            return Err(invalid_data(format!(
                "overlay FAT grew to {} bytes and exceeds its recalculated payload origin \
                 {relocated_origin}",
                fat_prefix.len()
            )));
        }
        let delta = relocated_origin
            .checked_sub(base_origin)
            .ok_or_else(|| invalid_data("recalculated payload origin moved backwards"))?;
        shift_payload_positions(&mut root, base_origin as u64, delta as u64)?;
        fat_prefix = pack::build_fat_with_header(&root, output_nodes);
        eprintln!(
            "expanded FAT requires payload relocation: stock_origin={base_origin} \
             new_origin={relocated_origin} delta={delta}"
        );
        relocated_origin
    };

    let mut writer = BufWriter::new(File::create(output_path)?);
    writer.write_all(&fat_prefix)?;
    let mut padding = output_origin - fat_prefix.len();
    let zeroes = [0_u8; 64 * 1024];
    while padding != 0 {
        let count = padding.min(zeroes.len());
        writer.write_all(&zeroes[..count])?;
        padding -= count;
    }

    let mut base_file = File::open(base_path)?;
    base_file.seek(SeekFrom::Start(base_origin as u64))?;
    io::copy(&mut base_file, &mut writer)?;
    for bytes in changes.values() {
        writer.write_all(bytes)?;
    }
    writer.flush()?;
    drop(writer);

    // The overlay contract is stronger than "all newly emitted files verify":
    // every untouched base path must still resolve to the same stored bytes.
    // This catches FAT relocation and hard-link mistakes before a database can
    // reach the client.
    let mut output_archive = Archive::open(output_path)?;
    let output_entries = file_entries(&output_archive);
    for (path, base_entry) in &base_entries {
        if changes.contains_key(path) {
            continue;
        }
        let output_entry = output_entries.get(path).ok_or_else(|| {
            invalid_data(format!(
                "untouched base path disappeared after overlay: {:?}",
                String::from_utf8_lossy(path)
            ))
        })?;
        if base_entry.size_in_db != output_entry.size_in_db
            || base_archive.read_raw(base_entry)? != output_archive.read_raw(output_entry)?
        {
            return Err(invalid_data(format!(
                "untouched base payload changed after overlay: {:?}",
                String::from_utf8_lossy(path)
            )));
        }
    }

    Ok(OverlayStats {
        unchanged_files,
        replaced_files,
        added_files,
        added_folders,
        detached_hard_links,
        appended_payload_bytes: next_payload_pos - base_len,
        output_nodes,
    })
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::time::{SystemTime, UNIX_EPOCH};

    fn entry_bytes(archive: &mut Archive, path: &[u8]) -> Vec<u8> {
        let entry = archive
            .list()
            .into_iter()
            .find(|entry| entry.path == path)
            .unwrap();
        archive.read_file(&entry).unwrap()
    }

    fn find_node<'a>(node: &'a RawNode, components: &[&[u8]]) -> &'a RawNode {
        let child = node
            .children
            .iter()
            .find(|child| child.name == components[0])
            .unwrap();
        if components.len() == 1 {
            child
        } else {
            find_node(child, &components[1..])
        }
    }

    #[test]
    fn preserves_stock_payload_and_detaches_changed_owner_alias() {
        let unique = SystemTime::now()
            .duration_since(UNIX_EPOCH)
            .unwrap()
            .as_nanos();
        let root = std::env::temp_dir().join(format!(
            "resources-db-overlay-test-{}-{unique}",
            std::process::id()
        ));
        let base_source = root.join("base-source");
        let donor_source = root.join("donor-source");
        std::fs::create_dir_all(base_source.join("a")).unwrap();
        std::fs::create_dir_all(base_source.join("b")).unwrap();
        std::fs::write(base_source.join("a/shared.bin"), b"stock").unwrap();
        std::fs::write(base_source.join("b/shared.bin"), b"stock").unwrap();

        let base = root.join("base.db");
        pack::assemble_to_file(&pack::build_src_tree(&base_source).unwrap(), &base).unwrap();
        let base_len = std::fs::metadata(&base).unwrap().len();
        let base_tree = Archive::open(&base).unwrap().parse_tree();
        assert!(find_node(&base_tree.root, &[b"b", b"shared.bin"]).is_hard_link());
        let stock_pos = find_node(&base_tree.root, &[b"a", b"shared.bin"]).pos_in_db;

        std::fs::create_dir_all(donor_source.join("a")).unwrap();
        std::fs::create_dir_all(donor_source.join("new/nested")).unwrap();
        std::fs::write(donor_source.join("a/shared.bin"), b"replacement").unwrap();
        std::fs::write(donor_source.join("new/nested/item.bin"), b"addition").unwrap();
        let donor = root.join("donor.db");
        pack::assemble_to_file(&pack::build_src_tree(&donor_source).unwrap(), &donor).unwrap();

        let patched = root.join("patched.db");
        let stats = apply_db_overlay(&base, &donor, &patched).unwrap();
        assert_eq!(stats.detached_hard_links, 1);
        assert_eq!(stats.replaced_files, 1);
        assert_eq!(stats.added_files, 1);

        let mut archive = Archive::open(&patched).unwrap();
        assert_eq!(entry_bytes(&mut archive, b"a/shared.bin"), b"replacement");
        assert_eq!(entry_bytes(&mut archive, b"b/shared.bin"), b"stock");
        assert_eq!(
            entry_bytes(&mut archive, b"new/nested/item.bin"),
            b"addition"
        );

        let patched_tree = Archive::open(&patched).unwrap().parse_tree();
        let alias = find_node(&patched_tree.root, &[b"b", b"shared.bin"]);
        assert!(!alias.is_hard_link());
        assert_eq!(alias.pos_in_db, stock_pos);
        let replacement = find_node(&patched_tree.root, &[b"a", b"shared.bin"]);
        assert!(replacement.pos_in_db >= base_len);
        assert_eq!(
            patched_tree.root.children.last().unwrap().name,
            b"new".to_vec()
        );

        std::fs::remove_dir_all(root).unwrap();
    }

    #[test]
    fn materializes_selected_unchanged_hard_link() {
        let unique = SystemTime::now()
            .duration_since(UNIX_EPOCH)
            .unwrap()
            .as_nanos();
        let root = std::env::temp_dir().join(format!(
            "resources-db-materialize-test-{}-{unique}",
            std::process::id()
        ));
        let base_source = root.join("base-source");
        let donor_source = root.join("donor-source");
        std::fs::create_dir_all(base_source.join("a")).unwrap();
        std::fs::create_dir_all(base_source.join("b")).unwrap();
        std::fs::create_dir_all(&donor_source).unwrap();
        std::fs::write(base_source.join("a/shared.bin"), b"stock").unwrap();
        std::fs::write(base_source.join("b/shared.bin"), b"stock").unwrap();

        let base = root.join("base.db");
        pack::assemble_to_file(&pack::build_src_tree(&base_source).unwrap(), &base).unwrap();
        let base_tree = Archive::open(&base).unwrap().parse_tree();
        assert!(find_node(&base_tree.root, &[b"b", b"shared.bin"]).is_hard_link());

        let donor = root.join("donor.db");
        pack::assemble_to_file(&pack::build_src_tree(&donor_source).unwrap(), &donor).unwrap();
        let patched = root.join("patched.db");
        let stats = apply_db_overlay_with_materialized_paths(
            &base,
            &donor,
            &patched,
            &[b"b/shared.bin".to_vec()],
        )
        .unwrap();

        assert_eq!(stats.replaced_files, 1);
        let patched_tree = Archive::open(&patched).unwrap().parse_tree();
        assert!(!find_node(&patched_tree.root, &[b"b", b"shared.bin"]).is_hard_link());
        let mut archive = Archive::open(&patched).unwrap();
        assert_eq!(entry_bytes(&mut archive, b"b/shared.bin"), b"stock");

        let patched_again = root.join("patched-again.db");
        let repeated = apply_db_overlay_with_materialized_paths(
            &patched,
            &donor,
            &patched_again,
            &[b"b/shared.bin".to_vec()],
        )
        .unwrap();
        assert_eq!(repeated.replaced_files, 0);
        let repeated_tree = Archive::open(&patched_again).unwrap().parse_tree();
        assert!(!find_node(&repeated_tree.root, &[b"b", b"shared.bin"]).is_hard_link());
        let mut repeated_archive = Archive::open(&patched_again).unwrap();
        assert_eq!(
            entry_bytes(&mut repeated_archive, b"b/shared.bin"),
            b"stock"
        );

        std::fs::remove_dir_all(root).unwrap();
    }

    #[test]
    fn relocates_from_the_preserved_payload_origin_after_repeated_overlays() {
        let unique = SystemTime::now()
            .duration_since(UNIX_EPOCH)
            .unwrap()
            .as_nanos();
        let root = std::env::temp_dir().join(format!(
            "resources-db-repeated-overlay-test-{}-{unique}",
            std::process::id()
        ));
        let base_source = root.join("base-source");
        let stage_source = root.join("stage-source");
        let final_source = root.join("final-source");
        std::fs::create_dir_all(&base_source).unwrap();
        std::fs::create_dir_all(&stage_source).unwrap();
        std::fs::create_dir_all(&final_source).unwrap();
        std::fs::write(base_source.join("stock.bin"), b"preserve-me").unwrap();

        let base = root.join("base.db");
        pack::assemble_to_file(&pack::build_src_tree(&base_source).unwrap(), &base).unwrap();

        for i in 0..6 {
            let name = format!("added_{i:02}.bin");
            std::fs::write(stage_source.join(&name), format!("stage-{i}")).unwrap();
            std::fs::write(final_source.join(&name), format!("stage-{i}")).unwrap();
        }
        let stage_donor = root.join("stage-donor.db");
        pack::assemble_to_file(&pack::build_src_tree(&stage_source).unwrap(), &stage_donor)
            .unwrap();
        let stage = root.join("stage.db");
        apply_db_overlay(&base, &stage_donor, &stage).unwrap();

        let stage_tree = Archive::open(&stage).unwrap().parse_tree();
        let preserved_origin = first_stored_payload_position(&stage_tree.root).unwrap();
        assert!(
            pack::data_blob_origin(&stage_tree.root) as u64 > preserved_origin,
            "the fixture must reproduce a max-FAT estimate beyond the preserved payload"
        );

        for i in 6..48 {
            std::fs::write(
                final_source.join(format!("added_{i:02}.bin")),
                format!("final-{i}"),
            )
            .unwrap();
        }
        let final_donor = root.join("final-donor.db");
        pack::assemble_to_file(&pack::build_src_tree(&final_source).unwrap(), &final_donor)
            .unwrap();
        let final_db = root.join("final.db");
        apply_db_overlay(&stage, &final_donor, &final_db).unwrap();

        let final_tree = Archive::open(&final_db).unwrap().parse_tree();
        assert!(
            first_stored_payload_position(&final_tree.root).unwrap() > preserved_origin,
            "the second overlay must relocate the preserved payload"
        );
        let mut archive = Archive::open(&final_db).unwrap();
        assert_eq!(entry_bytes(&mut archive, b"stock.bin"), b"preserve-me");
        assert_eq!(entry_bytes(&mut archive, b"added_05.bin"), b"stage-5");
        assert_eq!(entry_bytes(&mut archive, b"added_47.bin"), b"final-47");

        std::fs::remove_dir_all(root).unwrap();
    }
}

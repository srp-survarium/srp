// SPDX-License-Identifier: GPL-3.0-or-later
//! Packer/encoder for the Survarium / Vostok engine `resources.db` VFS pack
//! archive — the inverse of [`crate::fat`].
//!
//! This reproduces the engine's `archive_saver::save_db`
//! (`sources/vostok/vfs/sources/saving_*.cpp`) for the shipped configuration:
//! `compression_rate = 0` (everything RAW, no PPMd), `fat_align = 2048`,
//! `platform = pc` (64-bit pointers, u64 `file_size_type`), and — for a
//! `MASTER_GOLD` build — an empty inline-data config, so **no file is inlined**
//! and there are **no sub-fats / archive parts** (`*_max_size == u32(-1)`).
//!
//! What that leaves the packer responsible for, byte-for-byte:
//! 1. node `hash` = crc32 of the file's raw bytes (stored in every file node);
//! 2. dedup: identical-content files are stored once. A duplicate that has the
//!    **same leaf name** as an already-saved node becomes a `hard_link` node
//!    pointing at it; a duplicate with a **different** name becomes a plain file
//!    node that simply reuses the earlier payload's `pos_in_db` (writes no
//!    bytes). Only the first ("owner") copy of each content writes the payload;
//!    `find_duplicate_file` only matches earlier-saved owners (`saved_node`);
//! 3. child ordering: a stable sort of each folder's children by
//!    `fat_size_with_children` ascending. With empty inline data a file's
//!    fat-size is `sizeof(archive_file_node) + strlen(name)`, so this is
//!    effectively a sort by name length; **ties keep the source's directory
//!    enumeration order**;
//! 4. the packed node buffer (offsets, next/first-child/parent wiring, the
//!    mount-root layout) and 8-byte node alignment;
//! 5. the 24-byte `fat_header` and the 2048-aligned FAT reservation;
//! 6. the data blob: payloads written in node-save (depth-first) order.
//!
//! The on-disk node-class layouts (PC, MSVC `pack(8)`, 64-bit) are the same ones
//! the reader documents: this module reuses [`crate::fat`]'s `BaseNode` /
//! `BaseOff` / `MountRoot` offset namespaces and the `FatHeader` /
//! `ArchiveFileNodeBase` POD structs (written via [`crate::fat::write`]) instead
//! of redeclaring them. See `sources/vostok/vfs/sources/*.h` for the C++ structs.
//!
//! ## Reconstructable vs not
//! [`Packer::serialize_fat`] + [`data_blob_origin`] reproduce the FAT and blob
//! **byte-for-byte** when handed the engine's exact node tree (proven by the
//! `roundtrip` self-test, which feeds the tree parsed from the original).
//! Packing from a freshly-**extracted** directory ([`build_src_tree`] +
//! [`assemble`]) cannot be byte-identical for the shipped archive, because the
//! size-sort tie-break — and therefore which duplicate becomes the payload
//! "owner" vs a hard-link — depends on the original packing host's OS directory
//! enumeration order, which extraction does not preserve. The shipped PC
//! archive's `fat_header::num_nodes` includes four source-mount helper nodes
//! which are counted but not serialized; extracted-tree packing reproduces
//! that over-count. The 2 uninitialised struct-padding bytes after the endian
//! string are not derivable from an extracted tree.

// The on-disk node-class layouts, field offsets, and POD sub-structs are shared
// with the reader: this module reuses fat's `BaseNode` / `BaseOff` / `MountRoot`
// namespaces and `FatHeader` / `ArchiveFileNodeBase` rather than redeclaring the
// offsets, and emits fields with fat's `write::<T>` (the inverse of `read::<T>`).
use crate::fat::{
    write, ArchiveFileNodeBase, BaseNode, BaseOff, FatHeader, MountRoot, NodeFlags, RawNode,
};

/// `fat_align` default from `pack_archive_args` (`pack_archive.h`).
const FAT_ALIGN: u32 = 2048;
/// Node alignment on PC (`save_nodes`: `node_alignment = 8`).
const NODE_ALIGN: usize = 8;
/// `sizeof(string_path)` — the mount-root node's name field is this wide.
/// `string_path` is `fixed_string<260>` → 260 bytes of inline storage.
const STRING_PATH_SIZE: usize = 260;
/// `fat_header::num_nodes` is captured from the source VFS before saving the
/// archive tree. The shipped v0.100b source mount contains four mount-helper
/// nodes which are counted there but are not serialized into the packed FAT.
const SOURCE_MOUNT_HELPER_NODE_COUNT: u32 = 4;

/// crc32 used throughout the engine for file/path hashing:
/// `boost::crc_optimal<32, 0x04C11DB7, init=0, refin=true, refout=false>`.
/// Reflected input bytes, **non-reflected** output, no final xor.
pub fn crc32(data: &[u8]) -> u32 {
    // boost::crc_optimal builds a table over the *reflected* polynomial when
    // refin=true; it processes each byte LSB-first and the running remainder is
    // kept reflected, then (refout=false) the final remainder is bit-reversed.
    // Equivalently: run the standard reflected CRC-32 (poly 0xEDB88320, init 0,
    // no final xor) and bit-reverse the 32-bit result.
    let mut crc: u32 = 0;
    for &b in data {
        crc ^= b as u32;
        for _ in 0..8 {
            let mask = (crc & 1).wrapping_neg();
            crc = (crc >> 1) ^ (0xEDB8_8320 & mask);
        }
    }
    crc.reverse_bits()
}

/// Length of a node's name field, including the NUL. The mount root uses the
/// full `string_path` width; everyone else uses `strlen(name) + 1`.
fn name_len_with_zero(node: &RawNode) -> usize {
    if node.flags.contains(NodeFlags::MOUNT_ROOT) {
        STRING_PATH_SIZE
    } else {
        node.name.len() + 1
    }
}

fn align_up(v: usize, a: usize) -> usize {
    (v + a - 1) & !(a - 1)
}

/// One node laid out at a known buffer offset, ready to serialize.
struct Placed<'a> {
    node: &'a RawNode,
    /// Offset of the node-class start within the FAT buffer.
    node_start: usize,
}

/// The packer: assigns offsets depth-first, then writes the buffer.
pub struct Packer<'a> {
    placed: Vec<Placed<'a>>,
    /// base_node offset of each node, keyed by the node's original
    /// `base_node_off` (used to wire hard-link `referenced` pointers).
    base_off_by_orig: std::collections::HashMap<usize, usize>,
    cur_offs: usize,
    mount_root_base_off: usize,
}

/// Public API.
impl<'a> Packer<'a> {
    /// Serialize the parsed tree into a FAT node buffer (the bytes after the
    /// 24-byte header). The tree's child order must already match the engine's.
    pub fn serialize_fat(root: &'a RawNode) -> Vec<u8> {
        let mut p = Packer {
            placed: Vec::new(),
            base_off_by_orig: std::collections::HashMap::new(),
            cur_offs: 0,
            mount_root_base_off: 0,
        };
        // Pass 1: assign every node a buffer offset, depth-first (the order
        // save_nodes writes them).
        p.place(root);
        let total = p.cur_offs;
        let mut buf = vec![0u8; total];
        // Pass 2: emit bytes now that all offsets (and thus all pointers,
        // including hard-link targets) are known.
        p.emit(root, &mut buf);
        buf
    }
}

/// Internals: depth-first offset placement, then byte emission.
impl<'a> Packer<'a> {
    /// Depth-first offset assignment, mirroring `save_nodes` advancing
    /// `m_env.cur_offs` by each node's padded size before recursing.
    fn place(&mut self, node: &'a RawNode) {
        let node_start = self.cur_offs;
        let base = node_start + BaseOff::for_flags(node.flags);
        self.base_off_by_orig.insert(node.base_node_off, base);
        if node.flags.contains(NodeFlags::MOUNT_ROOT) {
            // m_mount_root_offs points at the mount_root_node_base, which is the
            // mount-root class start (the base sub-object is at offset 0).
            self.mount_root_base_off = node_start;
        }

        let size = BaseOff::class_sizeof(node.flags) + name_len_with_zero(node);
        let padded_size = align_up(size, NODE_ALIGN);
        self.placed.push(Placed { node, node_start });
        self.cur_offs += padded_size;

        if node.is_folder() {
            for child in &node.children {
                self.place(child);
            }
        }
    }

    fn emit(&self, root: &RawNode, buf: &mut [u8]) {
        // Index placed nodes by the node's original base offset so children can
        // be located when wiring next/first-child pointers.
        let mut by_orig: std::collections::HashMap<usize, &Placed> =
            std::collections::HashMap::new();
        for pl in &self.placed {
            by_orig.insert(pl.node.base_node_off, pl);
        }
        self.emit_node(root, buf, 0, &by_orig);
    }

    fn placed_base(&self, orig: usize) -> usize {
        self.base_off_by_orig[&orig]
    }

    fn emit_node(
        &self,
        node: &RawNode,
        buf: &mut [u8],
        parent_ptr: usize,
        by_orig: &std::collections::HashMap<usize, &Placed>,
    ) {
        let pl = by_orig[&node.base_node_off];
        let node_start = pl.node_start;
        let base = node_start + BaseOff::for_flags(node.flags);

        // --- base_node common header ---
        // The union { m_mount_root / m_mount_helper_parent } @ base+0:
        if node.flags.contains(NodeFlags::MOUNT_ROOT) {
            // root: mount_helper_parent = NULL (already zero); set the `node` ptr
            // and the constant `mount_type_archive` in mount_root_node_base.
            write(buf, node_start + MountRoot::NODE_PTR, base as u64);
            write(
                buf,
                node_start + MountRoot::MOUNT_TYPE,
                MountRoot::MOUNT_TYPE_ARCHIVE,
            );
        } else {
            write(
                buf,
                base + BaseNode::MOUNT_ROOT_UNION,
                self.mount_root_base_off as u64,
            );
        }
        // m_next_overlapped / m_hashset_next / m_association stay NULL (0).
        // m_next is wired by the parent when emitting the sibling chain.
        // m_parent (folder_node_pointer; 0 for the root, 936 for everyone else).
        write(buf, base + BaseNode::PARENT, parent_ptr as u64);
        write(buf, base + BaseNode::FLAGS, node.flags.bits());
        write_name(buf, base + BaseNode::NAME, node, name_len_with_zero(node));

        // --- class-specific prefix ---
        if node.is_hard_link() {
            let target_orig = node.hard_link_target_off.expect("hard-link target");
            let target_base = self.placed_base(target_orig);
            write(buf, node_start, target_base as u64);
        } else if node.flags.contains(NodeFlags::FOLDER) {
            // base_folder_node::m_first_child (mount root: folder.m_first_child).
            let fc_off = if node.flags.contains(NodeFlags::MOUNT_ROOT) {
                node_start + MountRoot::FOLDER
            } else {
                node_start // first_child @ class start for a plain folder
            };
            let first_child = node
                .children
                .first()
                .map(|c| self.placed_base(c.base_node_off))
                .unwrap_or(0);
            write(buf, fc_off, first_child as u64);
        } else {
            // archive_file_node_base @ node_start (a fixed 24-byte POD sub-object).
            write(
                buf,
                node_start,
                ArchiveFileNodeBase {
                    size_in_db: node.size_in_db,
                    _pad: 0,
                    pos_in_db: node.pos_in_db,
                    hash: node.hash,
                    _pad2: 0,
                },
            );
            if node.is_compressed() {
                // u32 uncompressed_size right before base_node.
                write(buf, base - 8, node.uncompressed_size);
            }
        }

        // --- recurse into children, wiring the sibling m_next chain ---
        if node.is_folder() {
            // Every non-root node's m_parent points at the mount-root's embedded
            // `folder` (constant 936), NOT its immediate parent. This reproduces
            // an engine quirk: in `save_nodes`,
            //   new_parent_offs = cur_offs + is_mount_root ? folder_offs : 0;
            // parses (C++ precedence) as `(cur_offs + is_mount_root) ? 936 : 0`,
            // which is 936 for every node since `cur_offs + is_mount_root != 0`.
            for i in 0..node.children.len() {
                let child = &node.children[i];
                self.emit_node(child, buf, MountRoot::FOLDER, by_orig);
                let child_base = self.placed_base(child.base_node_off);
                let next = node
                    .children
                    .get(i + 1)
                    .map(|c| self.placed_base(c.base_node_off))
                    .unwrap_or(0);
                write(buf, child_base + BaseNode::NEXT, next as u64);
            }
        }
    }
}

/// Build the full `resources.db` FAT prefix: the 24-byte header followed by the
/// FAT node buffer. The on-disk header records the **real** buffer size (not the
/// padded reservation); the alignment padding lives between the FAT and the data
/// blob and is accounted for by `data_blob_origin` / each file's `pos_in_db`.
pub fn build_fat_with_header(root: &RawNode, num_nodes: u32) -> Vec<u8> {
    let fat = Packer::serialize_fat(root);
    let header = FatHeader {
        endian_string: *b"little-endian\0", // 14 bytes incl. NUL
        // The 2 bytes between `endian_string` and `num_nodes` are struct padding
        // the engine never initialises (`fat_header` zeroes only the 14-byte
        // string, then `set_little_endian` copies 13 chars + NUL). In the shipped
        // archive they happen to be `15 00` — uninitialised stack, NOT derivable
        // from the tree, so we hardcode the observed value to stay byte-identical.
        _pad: [0x15, 0x00],
        num_nodes,
        buffer_size: fat.len() as u32,
    };
    let mut out = Vec::with_capacity(std::mem::size_of::<FatHeader>() + fat.len());
    out.extend_from_slice(bytemuck::bytes_of(&header));
    out.extend_from_slice(&fat);
    out
}

/// The 2048-aligned absolute offset at which the data blob begins:
/// `align_up(max_buffer_size + sizeof(fat_header), fat_align)`.
///
/// Crucially the engine reserves space using the **over-estimated**
/// `get_max_fat_size`, not the real (smaller) buffer size. We reproduce that
/// estimate exactly so the blob lands at the same offset.
pub fn data_blob_origin(root: &RawNode) -> usize {
    align_up(max_fat_size(root) + 24, FAT_ALIGN as usize)
}

/// `get_max_fat_size` (`saving_db.cpp`) for the shipped config (empty inline
/// data): a deliberate over-estimate of the FAT buffer size.
fn max_fat_size(root: &RawNode) -> usize {
    // out_size = total_size_for_extensions_with_limited_size() [0, empty inline]
    //          + sizeof(string_path)
    //          + sizeof(archive_folder_mount_root_node<64>)
    let mut out = STRING_PATH_SIZE + (BaseOff::MOUNT_ROOT + BaseNode::SIZEOF);
    out += max_fat_size_impl(root);
    out
}

/// `max_node_size` per node in `get_max_fat_size_impl`:
/// `max(sizeof(archive_file_node)=80, sizeof(base_folder_node)=72,
///      sizeof(archive_inline_compressed_file_node)=100) = 100`.
///
/// The inline-compressed class is afnb(24) + aifnb(16) + u32 uncompressed_size +
/// base_node; under MSVC pack(8) the base_node sub-object lands at +44 (the u32
/// packs against the aifnb's trailing u32 without re-padding to 8), giving 100.
/// Verified against the shipped archive: this value makes the engine's reserved
/// data-blob origin (2 250 752) come out exactly.
const MAX_NODE_SIZEOF: usize = 100;

fn max_fat_size_impl(node: &RawNode) -> usize {
    // Per node: max_node_size + (strlen(name)+1) + sizeof(pvoid). No inline data
    // in the shipped config, so the no_limit-extension branch never fires.
    let mut size = MAX_NODE_SIZEOF + node.name.len() + 1 + 8;
    for child in &node.children {
        size += max_fat_size_impl(child);
    }
    size
}

// ===========================================================================
// Pack from a directory tree.
//
// Builds the node tree from an extracted directory, reproducing the engine's
// pipeline: hash (crc32 of bytes) → fat-size → stable size-sort → dedup → save.
// The result is a `RawNode` tree (plus the payload bytes) the serializer above
// turns into a byte-identical FAT + blob.
// ===========================================================================

use std::path::{Path, PathBuf};

/// A file/folder gathered from disk, before sorting/dedup.
pub struct SrcNode {
    pub name: Vec<u8>,
    pub is_dir: bool,
    pub path: PathBuf,
    pub size: u32,
    /// crc32 of the file's raw bytes (files only).
    pub hash: u32,
    /// XOR-combined child hashes (folders) — matches `make_info_tree`.
    pub folder_hash: u32,
    /// `fat_size_with_children` for the size-sort.
    pub fat_size_with_children: u32,
    pub children: Vec<SrcNode>,
}

/// Read a directory recursively, lowercasing names, computing hashes and sizes,
/// then applying the engine's stable size-sort to each folder's children.
pub fn build_src_tree(root_dir: &Path) -> std::io::Result<SrcNode> {
    let mut root = read_dir_node(root_dir, Vec::new(), true)?;
    compute_fat_sizes(&mut root);
    sort_tree(&mut root);
    Ok(root)
}

fn read_dir_node(path: &Path, name: Vec<u8>, is_root: bool) -> std::io::Result<SrcNode> {
    let _ = is_root;
    let mut entries: Vec<(Vec<u8>, PathBuf, bool)> = Vec::new();
    for e in std::fs::read_dir(path)? {
        let e = e?;
        let ft = e.file_type()?;
        let raw = file_name_bytes(&e.file_name());
        let lower = raw.to_ascii_lowercase();
        entries.push((lower, e.path(), ft.is_dir()));
    }
    // Initial enumeration order: case-insensitive lexicographic by name. (The
    // engine's order comes from the OS directory iterator; for a NTFS/most
    // tools this is name-sorted. Ties after the later size-sort fall back to
    // this order.)
    entries.sort_by(|a, b| a.0.cmp(&b.0));

    let mut children = Vec::new();
    let mut folder_hash = 0u32;
    for (lower, child_path, is_dir) in entries {
        if is_dir {
            let node = read_dir_node(&child_path, lower, false)?;
            folder_hash ^= node.folder_hash;
            children.push(node);
        } else {
            let bytes = std::fs::read(&child_path)?;
            let hash = crc32(&bytes);
            folder_hash ^= hash;
            children.push(SrcNode {
                name: lower,
                is_dir: false,
                path: child_path,
                size: bytes.len() as u32,
                hash,
                folder_hash: 0,
                fat_size_with_children: 0,
                children: Vec::new(),
            });
        }
    }
    Ok(SrcNode {
        name,
        is_dir: true,
        path: path.to_path_buf(),
        size: 0,
        hash: 0,
        folder_hash,
        fat_size_with_children: 0,
        children,
    })
}

/// Assemble the full `resources.db` bytes from a sorted source tree: builds the
/// `RawNode` tree (running dedup in save order to choose hard-links / shared
/// positions / unique payloads), serializes the FAT, and appends the data blob.
///
/// Returns the complete file image. The caller writes it out (and may sha256 it
/// against the original).
pub fn assemble(root: &SrcNode) -> std::io::Result<Vec<u8>> {
    // Save-order dedup state.
    struct Saved {
        key: usize, // RawNode synthetic id of the node that owns the payload
        size: u32,
        path: PathBuf,
        name: Vec<u8>, // lowercased leaf name (for same-name detection)
        pos: u64,
    }
    // Per-hash buckets of already-saved file nodes (mirrors the vfs hashset).
    let mut by_hash: std::collections::HashMap<u32, Vec<Saved>> = std::collections::HashMap::new();
    let mut next_key = 1usize;
    let mut blob: Vec<u8> = Vec::new();

    // First lay out the FAT to learn the data-blob origin (it uses the size
    // over-estimate, which depends only on names/structure, not payload order).
    // We build the RawNode tree first (without positions), compute origin, then
    // do a save-order pass to assign positions and emit the blob.

    // Build a RawNode skeleton mirroring the source tree; positions filled later.
    fn to_raw(node: &SrcNode, next_key: &mut usize) -> RawNode {
        let key = *next_key;
        *next_key += 1;
        let mut children = Vec::new();
        if node.is_dir {
            for c in &node.children {
                children.push(to_raw(c, next_key));
            }
        }
        RawNode {
            flags: if node.is_dir {
                NodeFlags::FOLDER | NodeFlags::ARCHIVE
            } else {
                NodeFlags::ARCHIVE
            },
            name: node.name.clone(),
            base_node_off: key,
            size_in_db: node.size,
            uncompressed_size: node.size,
            pos_in_db: 0,
            hash: node.hash,
            hard_link_target_off: None,
            children,
        }
    }
    // Mount-root wraps the top folder: its name is empty, flags add MOUNT_ROOT.
    let mut raw_root = to_raw(root, &mut next_key);
    raw_root.flags = NodeFlags::FOLDER | NodeFlags::ARCHIVE | NodeFlags::MOUNT_ROOT;
    raw_root.name = Vec::new();

    let origin = data_blob_origin(&raw_root) as u64;
    let mut cur_pos = origin;

    // Save-order pass: walk depth-first, resolving each file to one of:
    //  - hard-link (identical bytes AND same name as an earlier saved node),
    //  - shared position (identical bytes, different name),
    //  - new payload (write bytes, register in the hashset).
    // We mutate the RawNode tree in place to set kinds/positions/link targets.
    fn save_pass(
        node: &mut RawNode,
        src: &SrcNode,
        by_hash: &mut std::collections::HashMap<u32, Vec<Saved>>,
        cur_pos: &mut u64,
        blob: &mut Vec<u8>,
    ) -> std::io::Result<()> {
        if node.is_folder() {
            for (rc, sc) in node.children.iter_mut().zip(src.children.iter()) {
                save_pass(rc, sc, by_hash, cur_pos, blob)?;
            }
            return Ok(());
        }
        // File node. Look for a duplicate among already-saved nodes of same hash.
        let bytes = std::fs::read(&src.path)?;
        let size = node.size_in_db;
        // (key, pos) of a same-name duplicate, or a different-name one.
        let mut same_name: Option<(usize, u64)> = None;
        let mut other_name: Option<(usize, u64)> = None;
        if let Some(bucket) = by_hash.get(&node.hash) {
            for s in bucket.iter() {
                if s.size != size {
                    continue;
                }
                // Byte-for-byte file compare, like the engine.
                let other = std::fs::read(&s.path)?;
                if other != bytes {
                    continue;
                }
                if s.name == node.name {
                    same_name = Some((s.key, s.pos));
                    break;
                } else if other_name.is_none() {
                    other_name = Some((s.key, s.pos));
                }
            }
        }
        if let Some((key, pos)) = same_name {
            // Hard-link: references the earlier node's saved base_node.
            node.flags = NodeFlags::ARCHIVE | NodeFlags::HARD_LINK;
            node.hard_link_target_off = Some(key);
            node.pos_in_db = pos; // not stored for hard-links, but harmless
            return Ok(());
        }
        if let Some((_, pos)) = other_name {
            // Plain file node that shares an earlier payload's position; writes
            // no new bytes and is NOT registered as a fresh owner.
            node.pos_in_db = pos;
            return Ok(());
        }
        // New unique payload.
        node.pos_in_db = *cur_pos;
        blob.extend_from_slice(&bytes);
        *cur_pos += size as u64;
        by_hash.entry(node.hash).or_default().push(Saved {
            key: node.base_node_off,
            size,
            path: src.path.clone(),
            name: node.name.clone(),
            pos: node.pos_in_db,
        });
        Ok(())
    }
    save_pass(&mut raw_root, root, &mut by_hash, &mut cur_pos, &mut blob)?;

    if std::env::var_os("RDB_PACK_DEBUG").is_some() {
        let (mut hl, mut files, mut folders) = (0usize, 0usize, 0usize);
        fn c(n: &RawNode, hl: &mut usize, files: &mut usize, folders: &mut usize) {
            if n.is_hard_link() {
                *hl += 1;
            } else if n.is_folder() {
                *folders += 1;
            } else {
                *files += 1;
            }
            for ch in &n.children {
                c(ch, hl, files, folders);
            }
        }
        c(&raw_root, &mut hl, &mut files, &mut folders);
        eprintln!(
            "[pack] hardlinks={hl} file_nodes={files} folders={folders} unique_payloads={} blob_len={}",
            by_hash.values().map(|v| v.len()).sum::<usize>(),
            blob.len()
        );
    }

    let num_nodes = packed_num_nodes(&raw_root);
    let fat_prefix = build_fat_with_header(&raw_root, num_nodes);

    let mut out = Vec::with_capacity(origin as usize + blob.len());
    out.extend_from_slice(&fat_prefix);
    out.resize(origin as usize, 0); // zero padding up to the blob origin
    out.extend_from_slice(&blob);
    Ok(out)
}

/// Assemble directly into a file without holding both the payload blob and the
/// final multi-gigabyte archive in memory.
pub fn assemble_to_file(root: &SrcNode, output: &Path) -> std::io::Result<()> {
    struct Saved {
        key: usize,
        size: u32,
        path: PathBuf,
        name: Vec<u8>,
        pos: u64,
    }

    fn to_raw(node: &SrcNode, next_key: &mut usize) -> RawNode {
        let key = *next_key;
        *next_key += 1;
        let children = if node.is_dir {
            node.children
                .iter()
                .map(|child| to_raw(child, next_key))
                .collect()
        } else {
            Vec::new()
        };
        RawNode {
            flags: if node.is_dir {
                NodeFlags::FOLDER | NodeFlags::ARCHIVE
            } else {
                NodeFlags::ARCHIVE
            },
            name: node.name.clone(),
            base_node_off: key,
            size_in_db: node.size,
            uncompressed_size: node.size,
            pos_in_db: 0,
            hash: node.hash,
            hard_link_target_off: None,
            children,
        }
    }

    fn plan_payloads(
        node: &mut RawNode,
        src: &SrcNode,
        by_hash: &mut std::collections::HashMap<u32, Vec<Saved>>,
        cur_pos: &mut u64,
        payloads: &mut Vec<PathBuf>,
    ) -> std::io::Result<()> {
        if node.is_folder() {
            for (raw_child, source_child) in node.children.iter_mut().zip(&src.children) {
                plan_payloads(raw_child, source_child, by_hash, cur_pos, payloads)?;
            }
            return Ok(());
        }

        let bytes = std::fs::read(&src.path)?;
        let size = node.size_in_db;
        let mut same_name = None;
        let mut other_name = None;
        if let Some(bucket) = by_hash.get(&node.hash) {
            for saved in bucket {
                if saved.size != size || std::fs::read(&saved.path)? != bytes {
                    continue;
                }
                if saved.name == node.name {
                    same_name = Some((saved.key, saved.pos));
                    break;
                }
                if other_name.is_none() {
                    other_name = Some(saved.pos);
                }
            }
        }
        if let Some((key, pos)) = same_name {
            node.flags = NodeFlags::ARCHIVE | NodeFlags::HARD_LINK;
            node.hard_link_target_off = Some(key);
            node.pos_in_db = pos;
            return Ok(());
        }
        if let Some(pos) = other_name {
            node.pos_in_db = pos;
            return Ok(());
        }

        node.pos_in_db = *cur_pos;
        *cur_pos += u64::from(size);
        payloads.push(src.path.clone());
        by_hash.entry(node.hash).or_default().push(Saved {
            key: node.base_node_off,
            size,
            path: src.path.clone(),
            name: node.name.clone(),
            pos: node.pos_in_db,
        });
        Ok(())
    }

    let mut next_key = 1;
    let mut raw_root = to_raw(root, &mut next_key);
    raw_root.flags = NodeFlags::FOLDER | NodeFlags::ARCHIVE | NodeFlags::MOUNT_ROOT;
    raw_root.name.clear();
    let origin = data_blob_origin(&raw_root) as u64;
    let mut cur_pos = origin;
    let mut by_hash = std::collections::HashMap::new();
    let mut payloads = Vec::new();
    plan_payloads(
        &mut raw_root,
        root,
        &mut by_hash,
        &mut cur_pos,
        &mut payloads,
    )?;

    let fat_prefix = build_fat_with_header(&raw_root, packed_num_nodes(&raw_root));
    let file = std::fs::File::create(output)?;
    let mut writer = std::io::BufWriter::new(file);
    std::io::Write::write_all(&mut writer, &fat_prefix)?;
    let mut padding = origin
        .checked_sub(fat_prefix.len() as u64)
        .expect("data blob origin precedes FAT");
    let zeroes = [0_u8; 64 * 1024];
    while padding != 0 {
        let count = usize::try_from(padding.min(zeroes.len() as u64)).unwrap();
        std::io::Write::write_all(&mut writer, &zeroes[..count])?;
        padding -= count as u64;
    }
    for path in payloads {
        let mut payload = std::fs::File::open(path)?;
        std::io::copy(&mut payload, &mut writer)?;
    }
    std::io::Write::flush(&mut writer)?;
    Ok(())
}

fn count_nodes(node: &RawNode) -> u32 {
    let mut n = 1;
    for c in &node.children {
        n += count_nodes(c);
    }
    n
}

fn packed_num_nodes(node: &RawNode) -> u32 {
    count_nodes(node)
        .checked_add(SOURCE_MOUNT_HELPER_NODE_COUNT)
        .expect("packed node count overflow")
}

#[cfg(unix)]
fn file_name_bytes(n: &std::ffi::OsStr) -> Vec<u8> {
    use std::os::unix::ffi::OsStrExt;
    n.as_bytes().to_vec()
}
#[cfg(not(unix))]
fn file_name_bytes(n: &std::ffi::OsStr) -> Vec<u8> {
    n.to_string_lossy().as_bytes().to_vec()
}

/// `calculate_sizes_for_info_tree`: a folder's `fat_size_with_children` is its
/// own node size plus its children's; a file's is just its node size. (Inline
/// data is empty in the shipped config, so files never add their payload size.)
fn compute_fat_sizes(node: &mut SrcNode) -> u32 {
    if node.is_dir {
        // base_folder_node::sizeof_with_name() == sizeof(base_folder_node) + len.
        let mut size = (BaseOff::FOLDER + BaseNode::SIZEOF) as u32 + node.name.len() as u32 + 1;
        for c in &mut node.children {
            size += compute_fat_sizes(c);
        }
        node.fat_size_with_children = size;
    } else {
        // sizeof(archive_file_node<>) + strlen(name)  [note: no +1 here, matching
        // calculate_sizes_for_file_node exactly].
        node.fat_size_with_children =
            (BaseOff::FILE + BaseNode::SIZEOF) as u32 + node.name.len() as u32;
    }
    node.fat_size_with_children
}

/// `sort_info_tree`: stable bubble-sort each folder's children ascending by
/// `fat_size_with_children`, then recurse.
fn sort_tree(node: &mut SrcNode) {
    if !node.is_dir {
        return;
    }
    // Stable sort preserves enumeration order for equal sizes, exactly like the
    // engine's repeated adjacent-swap pass (swap only on strict `<`).
    node.children.sort_by_key(|c| c.fat_size_with_children);
    for c in &mut node.children {
        sort_tree(c);
    }
}

/// Write a node's inline name (NUL-terminated) at `off`; the inverse of
/// [`crate::fat::BaseNode::name`]. `field_len` is the field width including the
/// NUL (`STRING_PATH_SIZE` for the mount root, else `strlen + 1`).
fn write_name(buf: &mut [u8], off: usize, node: &RawNode, field_len: usize) {
    let n = node.name.len().min(field_len.saturating_sub(1));
    buf[off..off + n].copy_from_slice(&node.name[..n]);
    // remaining bytes (incl. NUL terminator) are already zero
}

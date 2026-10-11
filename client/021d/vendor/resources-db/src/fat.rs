// SPDX-License-Identifier: GPL-3.0-or-later
//! Parsing of the FAT (file allocation table): the header, and the packed tree
//! of nodes that indexes every file in the archive.
//!
//! All multi-byte fields are little-endian, and the node layout below is the
//! 64-bit PC layout (`archive_platform_pc` → `platform_pointer_64bit`). Since
//! this tool only targets little-endian hosts, fields are read directly with
//! [`bytemuck`] (native-endian); a big-endian archive (PS3/Xbox360) would need
//! byte-swapping, which the header's `endian_string` would flag.

use std::fs::File;
use std::io::{self, Read, Seek, SeekFrom};
use std::path::Path;

use bytemuck::{Pod, Zeroable};

// The FAT stores 64-bit offsets; we read them as u64 and use them as usize for
// indexing the buffer and seeking the file. That truncates on a 32-bit target,
// so require usize == u64 (a 64-bit host).
const _: () = assert!(std::mem::size_of::<usize>() == std::mem::size_of::<u64>());

/// On-disk FAT header — `sources/vostok/vfs/sources/fat_header.h`.
///
/// `fat_header` has no `#pragma pack`, so the two `u32`s are 4-byte aligned and
/// there are 2 padding bytes after the 14-byte endian string (24 bytes total).
/// The header is followed by `buffer_size` bytes of packed node buffer, then the
/// data blob.
#[repr(C)]
#[derive(Clone, Copy, Pod, Zeroable)]
pub struct FatHeader {
    pub endian_string: [u8; 14],
    pub _pad: [u8; 2],
    pub num_nodes: u32,
    pub buffer_size: u32,
}

/// File-payload location — `archive_file_node_base` in
/// `sources/vostok/vfs/sources/archive_file_node_base.h`.
///
/// `pos_in_db` is a `file_size_type` (u64 on 64-bit) and the 4 bytes after
/// `size_in_db` are alignment padding before it.
#[repr(C)]
#[derive(Clone, Copy, Pod, Zeroable)]
pub struct ArchiveFileNodeBase {
    /// Bytes stored in the db (compressed size when compressed).
    pub size_in_db: u32,
    pub _pad: u32,
    /// Absolute file offset of the payload.
    pub pos_in_db: u64,
    pub hash: u32,
    // Trailing padding to the struct's 8-byte alignment (pack(8) makes the C++
    // struct 24 bytes); explicit so bytemuck::Pod accepts it.
    pub _pad2: u32,
}

bitflags::bitflags! {
    /// `vfs_node_enum` — `sources/vostok/vfs/base_node.h`. The node's concrete
    /// class (and thus its byte layout) is selected by these flags.
    #[derive(Clone, Copy, Debug, PartialEq, Eq)]
    pub struct NodeFlags: u16 {
        const FOLDER           = 1 << 0;
        const PHYSICAL         = 1 << 1;
        const ARCHIVE          = 1 << 2;
        const MOUNT_ROOT       = 1 << 3;
        const COMPRESSED       = 1 << 4;
        const REPLICATED       = 1 << 5;
        const INLINED          = 1 << 6;
        const SUB_FAT          = 1 << 7;
        const SOFT_LINK        = 1 << 8;
        const HARD_LINK        = 1 << 9;
        const MOUNT_HELPER     = 1 << 10;
        const ERASED           = 1 << 11;
        const EXTERNAL_SUB_FAT = 1 << 12;
        const UNIVERSAL_FILE   = 1 << 13;
        const MARKED_TO_UNLINK = 1 << 14;
    }
}

/// Read a little-endian POD value from `buf` at `off`.
pub fn read<T: Pod>(buf: &[u8], off: usize) -> T {
    bytemuck::pod_read_unaligned(&buf[off..off + std::mem::size_of::<T>()])
}

/// Write a little-endian POD value into `buf` at `off` — the inverse of [`read`],
/// used by the packer ([`crate::pack`]) to emit node fields and fixed sub-structs.
pub fn write<T: Pod>(buf: &mut [u8], off: usize, val: T) {
    buf[off..off + std::mem::size_of::<T>()].copy_from_slice(bytemuck::bytes_of(&val));
}

// ===========================================================================
// 64-bit node layout (verified by probing the real archive against MSVC pack(8)).
// The C++ structs are reproduced as comments so the offsets can be checked
// against them without modelling every class in Rust.
// ===========================================================================

// base_node<64> — sources/vostok/vfs/base_node.h (pack(8)):
//   off  field                                              size
//   @0   union { m_mount_root; m_mount_helper_parent }        8
//   @8   node_pointer        m_next_overlapped                8
//   @16  node_pointer        m_hashset_next                   8
//   @24  node_pointer        m_next                           8   <- NEXT
//   @32  folder_node_pointer m_parent                         8
//   @40  association_pointer m_association                    8
//   @48  u16                 m_flags                          2   <- FLAGS
//   @50  u8                  m_association_lock               1
//   @51  char                m_name[]                  (flexible) <- NAME
//   => sizeof 56 (51 rounded up to 8-byte alignment)
//
/// The common node header every node embeds. Zero-sized: it just namespaces the
/// field offsets within `base_node` and the readers for the fields we use. A
/// stored node pointer points AT a node's `base_node`, so these are relative to
/// that offset (the reader reads, the packer writes, these fields).
pub struct BaseNode;

impl BaseNode {
    /// `union { m_mount_root; m_mount_helper_parent }` at the base_node start.
    pub const MOUNT_ROOT_UNION: usize = 0;
    pub const NEXT: usize = 24;
    pub const PARENT: usize = 32;
    pub const FLAGS: usize = 48;
    pub const NAME: usize = 51;
    /// `sizeof(base_node)` without the flexible name (51 rounded up to 8).
    pub const SIZEOF: usize = 56;

    /// Node flags at `base_node_off`.
    fn flags(buf: &[u8], base_node_off: usize) -> NodeFlags {
        NodeFlags::from_bits_retain(read::<u16>(buf, base_node_off + Self::FLAGS))
    }

    /// Sibling pointer: buffer offset of the next node (0 == end of list).
    fn next(buf: &[u8], base_node_off: usize) -> usize {
        read::<u64>(buf, base_node_off + Self::NEXT) as usize
    }

    /// Inline NUL-terminated node name, as raw bytes — engine paths are not
    /// guaranteed valid UTF-8, and lossy decoding would corrupt them (and break
    /// a byte-identical repack).
    fn name(buf: &[u8], base_node_off: usize) -> &[u8] {
        let start = base_node_off + Self::NAME;
        let mut end = start;
        while end < buf.len() && buf[end] != 0 {
            end += 1;
        }
        &buf[start..end]
    }
}

// base_off = offset of the embedded `base_node` within each final node class.
// (A stored pointer points AT base_node; subtract base_off for the class start,
//  where archive_file_node_base / inline-data fields live.) Layouts (pack(8)):
//   base_folder_node            { node* m_first_child@0; counters@8; base_node base@16 }                 -> 16
//   archive_file_node           { archive_file_node_base afnb@0 (24); base_node base@24 }                -> 24
//   archive_compressed_file_node{ afnb@0 (24); u32 uncompressed_size@24; <pad>; base_node base@32 }      -> 32
//   archive_inline_file_node    { afnb@0 (24); archive_inline_file_node_base aifnb@24 (16); base@40 }    -> 40
//   archive_inline_compressed.. { afnb@0; aifnb@24; u32 uncompressed_size@40; <pad>; base@48 }           -> 48
//   soft_link_node / hard_link_node { node* referenced@0; base_node base@8 }                             -> 8
//   erased_node                 { base_node base@0 }                                                     -> 0
//   external_subfat_node        { <16-byte prefix>@0; base_node base@16 }                                -> 16
//   archive_folder_mount_root_node:
//       mount_root_node_base(104) + 3*char[260] + char[32] + 2*ptr => folder@936, folder.base@936+16     -> 952
//
/// Zero-sized namespace for the per-class `base_node` offsets and the flag →
/// offset lookup.
pub struct BaseOff;

impl BaseOff {
    pub const FOLDER: usize = 16;
    pub const FILE: usize = 24;
    const COMPRESSED: usize = 32;
    const INLINE: usize = 40;
    const INLINE_COMPRESSED: usize = 48;
    const SOFT_LINK: usize = 8;
    const HARD_LINK: usize = 8;
    const ERASED: usize = 0;
    const EXTERNAL: usize = 16;
    pub const MOUNT_ROOT: usize = 952;

    /// base_off for a node with the given `flags`.
    pub fn for_flags(flags: NodeFlags) -> usize {
        if flags.contains(NodeFlags::MOUNT_ROOT) {
            Self::MOUNT_ROOT
        } else if flags.contains(NodeFlags::FOLDER) {
            Self::FOLDER
        } else if flags.contains(NodeFlags::SOFT_LINK) {
            Self::SOFT_LINK
        } else if flags.contains(NodeFlags::HARD_LINK) {
            Self::HARD_LINK
        } else if flags.contains(NodeFlags::ERASED) {
            Self::ERASED
        } else if flags.contains(NodeFlags::EXTERNAL_SUB_FAT) {
            Self::EXTERNAL
        } else if flags.contains(NodeFlags::INLINED) {
            if flags.contains(NodeFlags::COMPRESSED) {
                Self::INLINE_COMPRESSED
            } else {
                Self::INLINE
            }
        } else if flags.contains(NodeFlags::COMPRESSED) {
            Self::COMPRESSED
        } else {
            Self::FILE
        }
    }

    /// `sizeof(final class)` without the trailing name: the embedded `base_node`
    /// offset plus `sizeof(base_node)`. Used by the packer to advance offsets.
    pub fn class_sizeof(flags: NodeFlags) -> usize {
        Self::for_flags(flags) + BaseNode::SIZEOF
    }
}

// archive_inline_file_node_base — { ptr m_inlined_data@0; u32 m_inlined_size@8 }.
// It follows the 24-byte afnb sub-object in the inline node classes, so the
// aifnb starts at node+24 and m_inlined_data (the payload's buffer offset) is
// at node + AIFNB_OFF.
const AIFNB_OFF: usize = 24;

// archive_folder_mount_root_node — sources/vostok/vfs/sources/*.h (pack(8)):
//   mount_root_node_base(104) { ...; node* node @64; u32 mount_type @92; ... }
//   followed by 3*string_path + char[32] + 2*ptr, so the embedded folder
//   (a base_folder_node) lands at @936 and its base_node at 936+16 = 952
//   (== BaseOff::MOUNT_ROOT). m_first_child is folder+0 = @936.
/// Zero-sized namespace for the mount-root class field offsets, relative to the
/// node-class start (shared by the reader and the packer).
pub struct MountRoot;

impl MountRoot {
    /// `mount_root_node_base::node` — buffer offset of the root folder's base_node.
    pub const NODE_PTR: usize = 64;
    /// `mount_root_node_base::mount_type` (a u32 `mount_type_enum`).
    pub const MOUNT_TYPE: usize = 92;
    /// `archive_folder_mount_root_node::folder` (the embedded base_folder_node;
    /// its `m_first_child` is at +0).
    pub const FOLDER: usize = 936;
    /// `mount_type_archive` (`vostok::vfs::mount_type_enum`).
    pub const MOUNT_TYPE_ARCHIVE: u32 = 2;
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum NodeKind {
    Folder,
    File { compressed: bool, inlined: bool },
    SoftLink,
    HardLink,
    Erased,
    External,
    Other,
}

#[derive(Debug, Clone)]
pub struct FileEntry {
    /// Full virtual path relative to the archive root, as raw bytes (engine
    /// paths are not guaranteed valid UTF-8), e.g. `b"vostok/foo.cfg"`.
    pub path: Vec<u8>,
    pub kind: NodeKind,
    /// Number of bytes stored in the db (compressed size when compressed).
    pub size_in_db: u32,
    /// Uncompressed size (== size_in_db for uncompressed files).
    pub uncompressed_size: u32,
    /// Absolute file offset of the payload (for non-inline files).
    pub pos_in_db: u64,
    /// For inline files: offset of the payload inside the FAT buffer.
    pub inline_buffer_offset: Option<u64>,
}

pub struct Archive {
    file: File,
    /// The FAT node buffer (buffer_size bytes), loaded fully into memory.
    buf: Vec<u8>,
    pub num_nodes: u32,
    pub buffer_size: u32,
}

/// Public API.
impl Archive {
    pub fn open<P: AsRef<Path>>(path: P) -> io::Result<Archive> {
        let mut file = File::open(path)?;
        let mut header_bytes = [0u8; std::mem::size_of::<FatHeader>()];
        file.read_exact(&mut header_bytes)?;
        let header: FatHeader = bytemuck::pod_read_unaligned(&header_bytes);

        if &header.endian_string[0..13] != b"little-endian" {
            return Err(io::Error::new(
                io::ErrorKind::InvalidData,
                format!(
                    "unexpected endian string: {:?}",
                    String::from_utf8_lossy(&header.endian_string)
                ),
            ));
        }

        let mut buf = vec![0u8; header.buffer_size as usize];
        file.read_exact(&mut buf)?;

        Ok(Archive {
            file,
            buf,
            num_nodes: header.num_nodes,
            buffer_size: header.buffer_size,
        })
    }

    /// Build a flat list of every file entry, reconstructing virtual paths by
    /// walking the folder/child tree.
    pub fn list(&self) -> Vec<FileEntry> {
        let mut out = Vec::new();
        let root = self.root_base_node_off();
        // The root mount-root node has an empty name; descend into its children.
        debug_assert!(BaseNode::flags(&self.buf, root).contains(NodeFlags::FOLDER));
        self.walk_folder_children(root, b"", &mut out);
        out
    }

    /// Read the raw (possibly compressed) payload bytes for a file entry.
    pub fn read_raw(&mut self, e: &FileEntry) -> io::Result<Vec<u8>> {
        if let Some(buf_off) = e.inline_buffer_offset {
            let start = buf_off as usize;
            let end = start + e.size_in_db as usize;
            return Ok(self.buf[start..end].to_vec());
        }
        let mut data = vec![0u8; e.size_in_db as usize];
        self.file.seek(SeekFrom::Start(e.pos_in_db))?;
        self.file.read_exact(&mut data)?;
        Ok(data)
    }

    /// Read the payload for a file entry.
    ///
    /// The shipped resources.db stores everything uncompressed. PPMd-compressed
    /// payloads are not handled here — the decoder lives on the `ppmd` branch;
    /// this returns an error for them.
    pub fn read_file(&mut self, e: &FileEntry) -> io::Result<Vec<u8>> {
        let raw = self.read_raw(e)?;
        match e.kind {
            NodeKind::File {
                compressed: true, ..
            } => Err(io::Error::new(
                io::ErrorKind::Unsupported,
                "PPMd-compressed payload — decoder is on the `ppmd` branch",
            )),
            _ => Ok(raw),
        }
    }
}

/// Tree-walking internals.
impl Archive {
    /// Offset (in the FAT buffer) of the root folder's base_node.
    fn root_base_node_off(&self) -> usize {
        // The mount root node sits at buffer offset 0; its `node` field points
        // at the root folder's base_node. Trust that field, falling back to the
        // computed mount-root layout offset.
        let ptr = read::<u64>(&self.buf, MountRoot::NODE_PTR) as usize;
        if ptr != 0 && ptr < self.buf.len() {
            ptr
        } else {
            BaseOff::MOUNT_ROOT
        }
    }

    fn kind_for(&self, flags: NodeFlags) -> NodeKind {
        if flags.contains(NodeFlags::FOLDER) {
            NodeKind::Folder
        } else if flags.contains(NodeFlags::SOFT_LINK) {
            NodeKind::SoftLink
        } else if flags.contains(NodeFlags::HARD_LINK) {
            NodeKind::HardLink
        } else if flags.contains(NodeFlags::ERASED) {
            NodeKind::Erased
        } else if flags.contains(NodeFlags::EXTERNAL_SUB_FAT) {
            NodeKind::External
        } else if flags.contains(NodeFlags::ARCHIVE) {
            NodeKind::File {
                compressed: flags.contains(NodeFlags::COMPRESSED),
                inlined: flags.contains(NodeFlags::INLINED),
            }
        } else {
            NodeKind::Other
        }
    }

    fn first_child_of_folder(&self, base_node_off: usize, flags: NodeFlags) -> usize {
        // base_folder_node: m_first_child is at (base_node - 16) for normal
        // folders, and at (folder.base - 16) for the mount root too (folder
        // is a base_folder_node embedded in the mount root).
        let folder_start = base_node_off - BaseOff::for_flags(flags) + folder_start_within(flags);
        read::<u64>(&self.buf, folder_start) as usize
    }

    fn walk_folder_children(
        &self,
        folder_base_node_off: usize,
        prefix: &[u8],
        out: &mut Vec<FileEntry>,
    ) {
        let flags = BaseNode::flags(&self.buf, folder_base_node_off);
        let mut child = self.first_child_of_folder(folder_base_node_off, flags);
        while child != 0 {
            self.visit_node(child, prefix, out);
            child = BaseNode::next(&self.buf, child);
        }
    }

    fn visit_node(&self, base_node_off: usize, prefix: &[u8], out: &mut Vec<FileEntry>) {
        let flags = BaseNode::flags(&self.buf, base_node_off);
        let name = BaseNode::name(&self.buf, base_node_off);
        let path = if prefix.is_empty() {
            name.to_vec()
        } else {
            let mut p = Vec::with_capacity(prefix.len() + 1 + name.len());
            p.extend_from_slice(prefix);
            p.push(b'/');
            p.extend_from_slice(name);
            p
        };
        let kind = self.kind_for(flags);

        match kind {
            NodeKind::Folder => {
                // A normal extracted filesystem implicitly preserves folders
                // which have children, but it cannot recreate an empty VFS
                // folder unless we expose it as an entry.  These are
                // significant to the game: v0.100b contains empty collision
                // resource nodes which its cooks probe by path.
                if self.first_child_of_folder(base_node_off, flags) == 0 {
                    out.push(FileEntry {
                        path,
                        kind,
                        size_in_db: 0,
                        uncompressed_size: 0,
                        pos_in_db: 0,
                        inline_buffer_offset: None,
                    });
                } else {
                    self.walk_folder_children(base_node_off, &path, out);
                }
            }
            NodeKind::File { .. } => {
                out.push(self.read_file_fields(base_node_off, flags, path));
            }
            NodeKind::HardLink => {
                // hard_link_node: referenced (node pointer) at node_start+0,
                // base_node at node_start+8. The referenced offset points at
                // the referenced node's base_node; resolve it and copy its
                // payload location, but keep this node's own path.
                let node_start = base_node_off - BaseOff::HARD_LINK;
                let ref_base_off = read::<u64>(&self.buf, node_start) as usize;
                if ref_base_off != 0 && ref_base_off < self.buf.len() {
                    let ref_flags = BaseNode::flags(&self.buf, ref_base_off);
                    let mut entry = self.read_file_fields(ref_base_off, ref_flags, path);
                    // Keep the referenced file kind so extraction/decompression
                    // works for the resolved target.
                    entry.kind = self.kind_for(ref_flags);
                    out.push(entry);
                } else {
                    out.push(FileEntry {
                        path,
                        kind,
                        size_in_db: 0,
                        uncompressed_size: 0,
                        pos_in_db: 0,
                        inline_buffer_offset: None,
                    });
                }
            }
            // Soft-links / erased / external nodes do not carry directly
            // extractable payloads; record them as zero-size entries.
            _ => {
                out.push(FileEntry {
                    path,
                    kind,
                    size_in_db: 0,
                    uncompressed_size: 0,
                    pos_in_db: 0,
                    inline_buffer_offset: None,
                });
            }
        }
    }

    /// Read the file-payload fields for a file node given its base_node offset.
    fn read_file_fields(&self, base_node_off: usize, flags: NodeFlags, path: Vec<u8>) -> FileEntry {
        let compressed = flags.contains(NodeFlags::COMPRESSED);
        let inlined = flags.contains(NodeFlags::INLINED);
        let node_start = base_node_off - BaseOff::for_flags(flags);
        // archive_file_node_base sits at the start of every file node class.
        let afnb: ArchiveFileNodeBase = read(&self.buf, node_start);
        let uncompressed_size = if compressed {
            // archive(_inline)_compressed_file_node: u32 uncompressed_size,
            // located right before `base`.
            read::<u32>(&self.buf, base_node_off - 8)
        } else {
            afnb.size_in_db
        };
        let inline_buffer_offset = if inlined {
            // aifnb.m_inlined_data holds the buffer offset of the data.
            Some(read::<u64>(&self.buf, node_start + AIFNB_OFF))
        } else {
            None
        };
        FileEntry {
            path,
            kind: NodeKind::File {
                compressed,
                inlined,
            },
            size_in_db: afnb.size_in_db,
            uncompressed_size,
            pos_in_db: afnb.pos_in_db,
            inline_buffer_offset,
        }
    }
}

/// Offset of `m_first_child` within the final folder class, relative to the
/// node start. For a normal folder the base_folder_node IS the node start
/// (m_first_child @0). For the mount root, the embedded `folder` member sits at
/// offset 936 within the class, so m_first_child is at 936.
fn folder_start_within(flags: NodeFlags) -> usize {
    if flags.contains(NodeFlags::MOUNT_ROOT) {
        MountRoot::FOLDER // m_first_child @ folder+0
    } else {
        0
    }
}

// ===========================================================================
// Structured tree parse (for the packer / round-trip self-test).
//
// `parse_tree` walks the FAT buffer and returns the full node tree in the exact
// child order stored on disk, recovering every field the packer needs to
// reproduce the FAT byte-for-byte: each node's flags, name, payload size/pos,
// hash, and (for hard-links) the buffer offset of the referenced node.
// ===========================================================================

/// A node in the parsed FAT tree (the on-disk structure, not the resolved view
/// that [`Archive::list`] produces). Hard-links are kept as-is.
#[derive(Debug, Clone)]
pub struct RawNode {
    /// The node's raw flags (concrete class selector).
    pub flags: NodeFlags,
    /// Inline node name as raw bytes (no NUL).
    pub name: Vec<u8>,
    /// Buffer offset of this node's `base_node` in the original FAT (the value a
    /// node-pointer would store to point here).
    pub base_node_off: usize,
    /// For file nodes: payload size in db, uncompressed size, absolute file
    /// offset, and the stored crc32 hash. Zero for non-file nodes.
    pub size_in_db: u32,
    pub uncompressed_size: u32,
    pub pos_in_db: u64,
    pub hash: u32,
    /// For hard-links: the original base_node offset of the referenced node.
    pub hard_link_target_off: Option<usize>,
    /// Child nodes, in stored (on-disk) order. Empty for non-folders.
    pub children: Vec<RawNode>,
}

impl RawNode {
    pub fn is_folder(&self) -> bool {
        self.flags.contains(NodeFlags::FOLDER)
    }
    pub fn is_hard_link(&self) -> bool {
        self.flags.contains(NodeFlags::HARD_LINK)
    }
    pub fn is_inlined(&self) -> bool {
        self.flags.contains(NodeFlags::INLINED)
    }
    pub fn is_compressed(&self) -> bool {
        self.flags.contains(NodeFlags::COMPRESSED)
    }
}

/// The whole parsed archive: the FAT region bytes and the root node.
pub struct ParsedFat {
    pub num_nodes: u32,
    pub buffer_size: u32,
    /// The raw FAT region after the 24-byte header (`buffer_size` bytes).
    pub fat_region: Vec<u8>,
    pub root: RawNode,
}

impl Archive {
    /// Slice of the original FAT node buffer.
    pub fn fat_buffer(&self) -> &[u8] {
        &self.buf
    }

    /// Parse the full on-disk node tree, preserving child order and every field
    /// needed to re-serialize the FAT.
    pub fn parse_tree(&self) -> ParsedFat {
        let root_off = self.root_base_node_off();
        let root = self.parse_node(root_off);
        ParsedFat {
            num_nodes: self.num_nodes,
            buffer_size: self.buffer_size,
            fat_region: self.buf.clone(),
            root,
        }
    }

    fn parse_node(&self, base_node_off: usize) -> RawNode {
        let flags = BaseNode::flags(&self.buf, base_node_off);
        let name = BaseNode::name(&self.buf, base_node_off).to_vec();
        let mut node = RawNode {
            flags,
            name,
            base_node_off,
            size_in_db: 0,
            uncompressed_size: 0,
            pos_in_db: 0,
            hash: 0,
            hard_link_target_off: None,
            children: Vec::new(),
        };

        if flags.contains(NodeFlags::HARD_LINK) {
            let node_start = base_node_off - BaseOff::HARD_LINK;
            let target = read::<u64>(&self.buf, node_start) as usize;
            node.hard_link_target_off = Some(target);
            return node;
        }

        if flags.contains(NodeFlags::FOLDER) {
            let mut child = self.first_child_of_folder(base_node_off, flags);
            while child != 0 {
                node.children.push(self.parse_node(child));
                child = BaseNode::next(&self.buf, child);
            }
            return node;
        }

        // File node (archive file; possibly compressed/inlined).
        if flags.contains(NodeFlags::ARCHIVE)
            && !flags.contains(NodeFlags::ERASED)
            && !flags.contains(NodeFlags::EXTERNAL_SUB_FAT)
        {
            let node_start = base_node_off - BaseOff::for_flags(flags);
            let afnb: ArchiveFileNodeBase = read(&self.buf, node_start);
            node.size_in_db = afnb.size_in_db;
            node.pos_in_db = afnb.pos_in_db;
            node.hash = afnb.hash;
            node.uncompressed_size = if flags.contains(NodeFlags::COMPRESSED) {
                read::<u32>(&self.buf, base_node_off - 8)
            } else {
                afnb.size_in_db
            };
        }
        node
    }
}

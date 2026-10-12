// SPDX-License-Identifier: GPL-3.0-or-later
//! Reader/unpacker **and** packer/encoder for the Survarium / Vostok engine
//! `resources.db` VFS pack archive. [`fat`] parses the archive; [`pack`]
//! re-serializes it (the `roundtrip` self-test reproduces the shipped archive
//! byte-for-byte — verified by sha256).
//!
//! The on-disk format (little-endian, built for the 64-bit PC archive layout —
//! `archive_platform_pc` uses `platform_pointer_64bit` in `saving_db.cpp`):
//!
//! ```text
//! [ fat_header (24 bytes) ][ FAT node buffer (buffer_size bytes) ][ data blob ]
//! ```
//!
//! The FAT node buffer is a packed tree of variable-length nodes. Node
//! "pointers" are 64-bit byte offsets relative to the start of the FAT node
//! buffer (offset 0 == NULL). File payloads live in the data blob and are
//! located by absolute file offset (`pos_in_db`).
//!
//! PPMd-compressed payloads (custom Dmitry Shkarin PPMd, order 8) do not occur
//! in the shipped resources.db, so the decoder is kept on the `ppmd` branch
//! rather than here.

pub mod fat;
pub mod overlay;
pub mod pack;

pub use fat::{Archive, FileEntry, NodeKind, ParsedFat, RawNode};

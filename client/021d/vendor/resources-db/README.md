# resources-db

Reader and writer for the Survarium / Vostok engine `resources.db` VFS pack
archive. This copy is vendored with the SRP 0.21d client tooling, including the
resource porter's packer and overlay support. See [dependency provenance](../../NOTICE.md)
and [imported source fingerprints](IMPORT.json).
It is licensed under [GPL-3.0-or-later](LICENSE).

## Build & run

```sh
nix shell nixpkgs#cargo nixpkgs#rustc nixpkgs#gcc --command cargo build --release

# list the contents
./target/release/resources-db list <resources.db>

# extract everything, reconstructing the folder tree
./target/release/resources-db extract <resources.db> <output-dir>

# Extract just the original lobby movie to a new output file.
./target/release/resources-db extract-member <resources.db> flash_movies/lobby_menu.swf <lobby_menu.swf>
```

## How it works (the gist)

`resources.db` is a single file that bundles a **directory index** — which the
engine calls the **FAT** (*file allocation table*) — and the **raw bytes of
every file**, one after another:

```
resources.db
+--------------------------------------------------------------+
| header     "little-endian", num_nodes, buffer_size           |
+--------------------------------------------------------------+
| FAT index  a tree of nodes:                                  |
|                                                              |
|   root                                                       |
|    +-- vostok (folder) --+-- foo.cfg  (file: offset, size)   |
|    |                     +-- bar.dds  (file: offset, size)   |
|    +-- boost  (folder) --+-- ...                             |
+--------------------------------------------------------------+
| data blob  raw bytes of every file, concatenated             |
+--------------------------------------------------------------+
```

> **Why "FAT"?** It's the engine's own term (`fat_header`, `fat_node`, …), kept
> here for that reason. It's the same general idea as the classic **FAT
> filesystem** — a table that locates each file's data — but it is Vostok's VFS
> index, *not* the Windows FAT12/16/32 on-disk format.

A folder node points at its first child; children are chained through a "next"
pointer. A file node records where its bytes live in the data blob (an offset
and a size). So unpacking is: walk the tree to rebuild each file's path, then
copy that file's slice of the data blob to disk. (The index is small — a couple
of MiB — so it is read fully into memory; the multi-GiB data blob is streamed
from the file on demand.)

## On-disk format (the precise version)

Derived from the engine source under `sources/vostok/vfs/`.

```
[ fat_header (24 bytes) ][ FAT node buffer (buffer_size bytes) ][ data blob ]
```

`fat_header` (`vfs/sources/fat_header.h`): `char endian_string[14]`
("little-endian\0"), 2 pad bytes, `u32 num_nodes`, `u32 buffer_size`.

The FAT node buffer is a packed tree of variable-length nodes. Node "pointers"
(`m_next`, `m_parent`, `m_first_child`, `referenced`, …) are byte **offsets into
the FAT node buffer** (offset 0 == NULL). The archive uses the PC layout, which
has **64-bit** pointers and a **u64** `file_size_type` (`saving_db.cpp` selects
`platform_pointer_64bit` for `archive_platform_pc`).

A stored node pointer points at the node's embedded `base_node`. The start of
the final node class is `base_node_offset - base_off(kind)`, where `base_off`
depends on the node flags. The payload fields (`archive_file_node_base`:
`u32 size_in_db; u64 pos_in_db; u32 hash`) sit at the start of the final class;
`pos_in_db` is the **absolute file offset** of the payload.

Inline files store their bytes inside the FAT buffer itself (`m_inlined_data` is
a buffer offset). Hard-link nodes (`is_hard_link`) reference another node's
payload and are resolved during extraction.

### Verified 64-bit struct offsets (MSVC `#pragma pack(8)`)

```
base_node:               m_next @24  m_parent @32  m_flags @48  m_name @51
archive_file_node_base:  size_in_db @0  pos_in_db @8  hash @16
base_off (offset of base_node within the final class):
  folder 16, file 24, compressed 32, inline 40, inline_compressed 48,
  soft_link 8, hard_link 8, erased 0, external 16, mount_root_folder 952
folder: m_first_child @0 (relative to base_folder_node start)
```

The root folder's `base_node` offset is read from the mount-root node's `node`
pointer field at buffer offset 64. (See `src/fat.rs` for the per-class layouts.)

## Compression

The shipped `resources.db` stores every file uncompressed, so this branch does
no decompression. PPMd-compressed payloads (a custom Dmitry Shkarin PPMd
variant, not 7-zip's PPMd7/8) are handled by the decoder on the **`ppmd`**
branch.

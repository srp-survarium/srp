<!-- SPDX-License-Identifier: GPL-3.0-or-later -->

```bash
# Run match-server
cargo build --lib --target=i686-pc-windows-msvc ; cargo run --bin match-server-boot --target=i686-pc-windows-msvc


# Apply patch to match-server-boot.exe (which is renamed survarium.exe)
SURVARIUM_EXE='D:\Projects\Survarium\binaries\win32\match-server-boot.exe' \
    cargo run --bin nasm-decompiler -- \
    --patch-name inject-server-dll \
    patch-survarium


cargo asm --target=i686-pc-windows-msvc --bin match-server-boot
```

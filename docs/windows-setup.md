<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# Windows setup (without Nix)

1. **Rust nightly:** install [rustup](https://rustup.rs). The pinned nightly in
   `rust-toolchain.toml` is selected automatically inside the repo.
2. **OpenSSL:** install it from <https://openssl-library.org/source/> and point
   Rust at it, e.g. in your PowerShell `$PROFILE` (needs
   `Set-ExecutionPolicy RemoteSigned -Scope CurrentUser`, run once as administrator):

   ```powershell
   $env:OPENSSL_DIR     = "C:\Program Files\OpenSSL-Win64"
   $env:OPENSSL_STATIC  = "true"
   $env:OPENSSL_LIB_DIR = 'C:\Program Files\OpenSSL-Win64\lib\VC\x64\MD'
   ```
3. **nasm** on `PATH`, for `nasm-decompiler`.
4. Optional for reverse engineering: Ghidra or IDA, and a Survarium install.

Then `cargo build --workspace` from the repo root.

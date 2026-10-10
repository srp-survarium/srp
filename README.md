<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# SRP - Survarium Restoration Project

### Prerequisites

1. `rustc`
    * Install nightly version from `rustup`: `rustup default nightly`

2. `openssl`
    * Install newest version from here: https://openssl-library.org/source/
    * Set environment variables so that `rust` could find it:
    ```
    # For example in `$PROFILE` for PS.
    # Requires: `Set-ExecutionPolicy RemoteSigned -Scope CurrentUser` to be executed with administrator privileges

    $env:OPENSSL_DIR     = "C:\Program Files\OpenSSL-Win64";
    $env:OPENSSL_STATIC  = "true";
    $env:OPENSSL_LIB_DIR = 'C:\Program Files\OpenSSL-Win64\lib\VC\x64\MD';
    ```

3. Highly recommended to set global environment variables:
    * `GHIDRA_HOME` - Path to installed Ghidra
    * `IDA_HOME` - Path to installed IDA
    * `SURVARIUM_BIN` - Path to installed survarium.exe
    * Otherwise default paths will be used (matching my machine).

## License

The server implementations, Rust crates, tooling, patches, and documentation
contributed by this project are licensed under the
[GNU General Public License, version 3 or later](LICENSE), to the extent the
contributors can do so. Project source files carry a one-line
`SPDX-License-Identifier: GPL-3.0-or-later` tag, following the
[Vostok project](https://github.com/srp-survarium/vostok).

Survarium and the Vostok Engine remain the property of their rights holders.
The GPL covers only the contributors' work; it does not grant rights to the
original game code, assets, or other third-party material. In particular, the
shipped samples in `resources/binary-config-examples/`, the original instruction
listings in `resources/patches/*_og.asm`, the recorded `.journal` file in
`scripts/parse-journal-file/`, and the shipped certificates and keys in `certs/`
are not covered by this license. Reconstructed declarations and instruction
listings within project notes and patches retain their underlying rights; the
SPDX tags apply only to the contributors' work.

Third-party dependencies retain their own licenses. Locally supplied game
binaries and assets, and build outputs that incorporate them, are not covered
by this license.

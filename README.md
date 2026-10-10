<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# SRP - Survarium Restoration Project

A **mock** of the Survarium v0.100b server side (see `CLAUDE.md`). It speaks just
enough of the client's protocol to drive it through login → lobby → match; the
authoritative game logic stays in the C++ Vostok engine. `PLAN.md` tracks the
roadmap, `WORK.md` the decision log.

### Build & run (Linux, via Nix)

The servers build and run on Linux. With Nix (flakes enabled):

```bash
nix develop                      # nightly Rust + system OpenSSL
cargo check --workspace

# Each server is its own binary; all four run together for a full session:
cargo run --bin login-server     # TCP  :1234
cargo run --bin browser-server   # HTTP :80
cargo run --bin lobby-server     # TCP  :1235
cargo run --bin match-server     # UDP  :1236
```

Point the game client at the login server: `survarium.exe -client=<host>:1234`.

### Hosting on your own server

Addresses are configured at runtime (see `vostok::config`). Each server binds
`127.0.0.1` by default, preserving the original local-only behavior. For a
single remote machine, explicitly bind all services to its interfaces and set
the routable host advertised to the client:

```bash
SRP_BIND_HOST=0.0.0.0 SRP_PUBLIC_HOST=your.public.host cargo run --bin lobby-server
# Run the other three servers with the same environment.
```

Per-server overrides: `SRP_<SERVER>_{BIND,PUBLIC_HOST,PORT}` where `<SERVER>` is
`BROWSER`, `LOGIN`, `LOBBY`, or `MATCH`. The stock client always contacts the
browser service on public port 80 because login advertises only its host.
`SRP_BROWSER_PORT` therefore requires external forwarding from public port 80
to the configured bind port.

Open these ports to remote clients: **TCP** 1234 (login), 80 (browser), 1235
(lobby) and **UDP** 1236 (match).

### Prerequisites (manual / Windows toolchain)

If not using the Nix dev shell:

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

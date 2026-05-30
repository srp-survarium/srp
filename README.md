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
`0.0.0.0` by default; the chain advertises a **public host** to the client for
the next hop. For a single machine hosting everything, set its routable address
once:

```bash
SRP_PUBLIC_HOST=your.public.host cargo run --bin lobby-server   # ...and the others
```

Per-server overrides: `SRP_<SERVER>_{BIND,PUBLIC_HOST,PORT}` where `<SERVER>` is
`BROWSER`, `LOGIN`, `LOBBY`, or `MATCH`. With no env vars set, everything
defaults to `127.0.0.1` (the original local-only behaviour).

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

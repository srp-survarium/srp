<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# SRP - Survarium Restoration Project

Replacement servers for Survarium (v0.100b): login, lobby, match and server
browser, with the tools to inspect and patch the game. The engine itself is
reconstructed in [vostok](https://github.com/srp-survarium/vostok).

## Quickstart

```sh
nix develop                     # pinned nightly Rust, OpenSSL, nasm
cargo build --workspace
cargo run -p login-server       # likewise lobby-server, match-server, browser-server
```

On Windows without Nix, see [docs/windows-setup.md](docs/windows-setup.md).

## Layout

- `servers/` - `login-server`, `lobby-server`, `match-server`, `browser-server`.
- `crates/` - shared protocol and data code (`survarium`, `vostok`, `binary-config-parser`).
- `scripts/` - tools: `nasm-decompiler` (builds and applies the `survarium.exe`
  patches in `resources/patches/`), `binary-config-cli`, `parse-journal-file`.
- `docs/notes/` - reverse-engineering notes.

## Account database and website

The [account service](servers/account-server/README.md) provides a version-neutral
SQLite database, a private server API, and a static dark server guide with the
community Discord link. It runs independently of the Rust game services:

```sh
python3 servers/account-server/server.py serve
# http://127.0.0.1:8080
```

Python 3.11+ and SQLite 3.38+ are sufficient; no packages or frontend build are
needed. Game-version adapters and verified retail catalogs can be added later.

## License

The project's own work is [GPL-3.0-or-later](LICENSE). Survarium and the Vostok
Engine remain their rights holders' property; game files used for development
(the lobby `skills_tree.bin` sample, the server certificates in `certs/`, the
original listings in `resources/patches/*_og.asm`) are not covered by the GPL.

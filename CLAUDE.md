<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# SRP - agent working rules

SRP mocks the Survarium v0.100b server side: it returns canned, wire-compatible
responses so the unmodified client (`survarium.exe`) can sign in, use the lobby
and enter a match. It is not a server rewrite; authoritative game logic belongs
to the C++ engine in [vostok](https://github.com/srp-survarium/vostok), and many
dummy values here are intentional mock data. Phase status: `docs/roadmap.md`.

## Build and test

    nix develop                    # nightly pinned in rust-toolchain.toml, OpenSSL, zstd, nasm
    cargo build --workspace
    cargo test --workspace

The workspace is nightly-only (edition 2024, unstable library features). There
is no CI: build and test inside `nix develop` before every commit.

## Run

    cargo run -p login-server      # TCP 1234: TLS sign-in, hands out a session id
    cargo run -p browser-server    # HTTP 80: returns the lobby address
    cargo run -p lobby-server      # TCP 1235: profiles, shop, inventory, chat
    cargo run -p match-server      # UDP 1236: the match

The client starts at the login server:
`survarium.exe -no_splash_screen -client=127.0.0.1:1234`. Addresses come from
`vostok::config` (`SRP_*` environment variables, see `docs/hosting.md`).

## Layout

- `crates/vostok` - protocol library: config, serde traits, TCP/UDP packets and clients.
- `crates/survarium` - game-domain wire types (profiles, inventory, player input).
- `crates/binary-config-parser` - the game's binary config format.
- `servers/*-server` - one crate per server.
- `scripts/` - offline tools: `nasm-decompiler` (the `resources/patches/` exe
  patches), `binary-config-cli`, `parse-journal-file`.
- `certs/` - the original game's TLS keys; the client expects them.
- `docs/notes/` - reverse-engineering notes.

## Conventions

- Little-endian everywhere. (De)serialize through `vostok::serde`;
  `DeserializeError::UnknownMessageType` sniffs which protocol a stream speaks.
- Wire structs live in `raw` submodules, named in `snake_case` after the C++
  types, `#[repr]` with bytemuck `CheckedBitPattern + NoUninit`; `*_enum` keeps
  the game's discriminants. Ergonomic `CamelCase` types stay outside `raw`.
- Extend `vostok::serde` / `network_client` rather than hand-rolling bytes in a server.
- The real client is the test oracle: say when a change alters what it sees.
- Reverse-engineering findings go in `docs/notes/`.
- New files start with `SPDX-License-Identifier: GPL-3.0-or-later`; new crates
  set `license.workspace = true`.

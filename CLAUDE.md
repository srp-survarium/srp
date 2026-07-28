# SRP — Survarium Restoration Project (server side)

## What this is

A **mock**, in Rust, of the **server side** of Survarium v0.100b (an early 2013
build of the Vostok engine). The original game client (`survarium.exe`) is
unmodified; SRP speaks just enough of its network protocol that the client can
connect, browse the lobby/shop/inventory, and drop into a match.

**It is a mock, not a reimplementation.** The real server logic lives — and will
keep living — in the C++ Vostok engine (the sibling `vostok/` repo). SRP does
not simulate the authoritative game; it returns canned/hardcoded responses that
are *wire-compatible* enough to drive the client. Many "dummy" values here are
intentional mock data, not unfinished features. The bar is **"a usable test
server"**, not "a faithful server rewrite".

This repo is the *server* counterpart to the sibling `vostok/` repo (which
binary-matches the *engine itself*). Here we do **not** match bytes — we just
need to produce wire-compatible bytes the real client accepts. Protocol
knowledge comes from reverse-engineering `survarium.exe` (IDA / Ghidra) in the
sibling repos; the findings live in `resources/notes/`.

The parent `surv-decomp/CLAUDE.md` is about the *engine* decompilation and does
**not** govern this directory — this file does.

---

## Build & run

There is **no Windows-only dependency** in the servers themselves; they build
and run on Linux. The original *client* you connect with is Windows (or Wine).

```bash
# Enter the dev shell (nightly Rust + system OpenSSL). See flake.nix.
nix develop

# Build / check everything
cargo check --workspace

# Primary way to run: the unified binary runs login + browser + lobby in ONE
# process sharing a session store (see "Single-process & sessions" below).
cargo run --bin srp              # TCP :1234 (login) + HTTP :80 (browser) + TCP :1235 (lobby)
cargo run --bin match-server     # UDP :1236  — gameplay (still a separate process)

# Per-server logs are written to logs/<server>.log AND echoed to stdout; set the
# level with RUST_LOG (e.g. RUST_LOG=debug). The standalone bins still exist for
# isolated debugging, but only `srp` shares one store across servers:
cargo run --bin login-server     # TCP  :1234
cargo run --bin browser-server   # HTTP :80
cargo run --bin lobby-server     # TCP  :1235
```

`srp` + `match-server` together cover a full client session. Bootstrappers launch
everything at once with per-server log views:
- **Linux:** `./scripts/dev-bootstrap.sh` — a tmux session with a window for `srp`,
  one for the match server, and one `tail -F` per `logs/<server>.log` (run it from
  inside `nix develop`).
- **Windows:** `survarium-dev-bootstrap.bat` — the same layout in Windows Terminal
  tabs, plus IDA/ProcExp and a client tab.

The client's `-client=<addr:port>` argument points it at the **login server**:

```
survarium.exe -no_splash_screen -client=127.0.0.1:1234
```

> **Toolchain note:** the workspace is nightly-only — `edition = "2024"` plus
> `#![feature(generic_atomic)]`, `iter_intersperse`, `slice_split_once`. Use the
> flake's toolchain; stable will not compile it.

---

## Architecture: the connection handshake

The client walks a fixed chain of servers. Each step tells it where to go next,
so addresses are discovered at runtime. Addresses are configurable
(`vostok::config`, read from env): each server has a **bind** host (default
`0.0.0.0`) and a **public** host advertised to the client (default `127.0.0.1`,
override with `SRP_PUBLIC_HOST`). Login + browser + lobby run together inside the
unified `srp` process; the match server is still separate.

```
                      survarium.exe (-client=<login_addr>)
                                 │
   ┌─────────────────────────────┼──────────────────────────────────────────┐
   │ 1. LOGIN SERVER  (TCP :1234)                                            │
   │    - reads sign-in (email + version), upgrades to TLS, reads password   │
   │    - replies servers_connection_info: <browser-server addr> + SESSION_ID│
   └─────────────────────────────┬──────────────────────────────────────────┘
                                 │  client now has SESSION_ID + browser addr
   ┌─────────────────────────────┼──────────────────────────────────────────┐
   │ 2. BROWSER SERVER (HTTP :80)  GET /hello?...                            │
   │    - plain HTTP; body is the lobby-server "addr:port" string            │
   └─────────────────────────────┬──────────────────────────────────────────┘
                                 │
   ┌─────────────────────────────┼──────────────────────────────────────────┐
   │ 3. LOBBY SERVER  (TCP :1235)  — long-lived connection                  │
   │    first byte disambiguates two protocols on the same port:             │
   │      • lobby protocol  → ServerState::run (profiles/shop/inventory/...)  │
   │      • messaging proto → messaging_server (friends list / chat stub)     │
   │    on "ReadyForMatch" replies ConnectToMatchServer{ match_id, team_id }  │
   └─────────────────────────────┬──────────────────────────────────────────┘
                                 │  client opens UDP to the match server
   ┌─────────────────────────────┼──────────────────────────────────────────┐
   │ 4. MATCH SERVER  (UDP :1236)  — the game                               │
   │    custom reliable-UDP layer (sequence ids + ack bitmask), 120 Hz tick  │
   │    spawns players, streams player updates                               │
   └──────────────────────────────────────────────────────────────────────┘
```

TLS (login server) uses the certs in `certs/`. The lobby/login certificates are
the *original game's* keys (also obtainable from the installer's
`resources/ssl/`); the client pins/expects them.

---

## Workspace layout

```
crates/
  vostok/                  # shared protocol library
    src/config.rs          #   per-server { bind_host, public_host, port }, from env
    src/serde.rs           #   Serialize / Deserialize traits + DeserializeError
    src/network_packet/    #   TcpPacket / UdpPacket byte buffers (Packet trait)
    src/network_client/    #   TcpClient (buffered, peek/read) / UdpClient
    src/math.rs            #   float3 etc.
  survarium/               # game-domain types shared across servers
    src/player_profile.rs  #   profiles, inventory_item_instance, slots, factions
    src/player_input.rs    #   player, weapon_core, stamina, player_input/state
    src/account.rs         #   faction_id, player_skill, player_reputation
  session/                 # in-memory Account + SessionStore (shared, single-process)
  binary-config-parser/    # (de)serializer for the game's binary config blobs

servers/
  srp/            src/main.rs   # UNIFIED bin: runs login+browser+lobby threads, shared store
                  src/logger.rs # routes each server's log to logs/<server>.log (+ stdout)
  login-server/   src/lib.rs    # TLS sign-in → resolves account + session in the store
  browser-server/ src/lib.rs    # actix-web HTTP; returns the lobby address
  lobby-server/   src/lobby_server/      # profiles/shop/inventory/skills (per-account)
                  src/messaging_server/  # friends/chat (stub)
  match-server/   src/match_connection.rs      # reliable-UDP transport + acks
                  src/game.rs                  # game logic / tick / spawns
                  src/message/                 # client_message.rs, server_message.rs
                  src/sequence_number.rs       # SN16 wrapping seq-number arithmetic

(each server crate is a lib exposing `run(Arc<SessionStore>)` + a thin standalone main)

scripts/          # offline RE tooling (not servers): binary-config-cli,
                  # build-engine-structure, nasm-decompiler, parse-journal-file

resources/notes/  # reverse-engineering notes (protocol, item ids, FSMs)
certs/            # TLS certs/keys for login + lobby
database/schema.sql  # aspirational Postgres schema (NOT wired up yet)
```

---

## Protocol & serialization conventions

- **Endianness:** little-endian everywhere. The lobby server has a `const _`
  assertion enforcing a little-endian build target.
- **(De)serialization:** the `vostok::serde::{Serialize, Deserialize}` traits.
  `Deserialize::deserialize(&mut &[u8])` advances the slice past one message;
  `DeserializeError::UnknownMessageType(u8)` is used to *sniff* which protocol a
  byte stream is (e.g. lobby-vs-messaging on port 1235).
- **`bytemuck`** drives most fixed-layout (de)serialization. Wire structs are
  `#[repr(...)]`, `CheckedBitPattern + NoUninit`, and conventionally named in
  `snake_case` inside a `raw` submodule (mirroring the C++ names from the PDB).
  Enums named `*_enum` mirror the game's enums with their exact discriminants.
- **Length-prefixing:** strings are `u8` length + bytes (`write_str`); vectors
  use `write_vec`/`write_slice` with an explicit length type.
- **Match transport (UDP):** every datagram carries `local_sequence_id`,
  `remote_sequence_id`, and a 16-bit `ack_bits` window. `SN16` implements
  wrapping comparison/subtraction so sequence numbers compare correctly across
  the `0xFFFF→0` wrap. Reliability = retransmit `unacknowledged_packets` until
  acked; `order_id` is for in-order game-message delivery (only partly handled).

---

## Mock simplifications (the work surface)

Being a mock, the servers currently assume **exactly one client and one match**
and return mostly canned data. The goal is to make the *mock* reachable remotely
and usable by **several clients at once** — **not** to grow it into an
authoritative game server (that stays in the C++ engine). So we lift the
single-client assumptions only as far as "multiple real clients can connect and
see each other"; we do **not** add real game simulation, economy, or persistence.
See `PLAN.md` for the staged approach and `WORK.md` for the running log.

Already addressed (Phases 1–2 — see `PLAN.md`/`WORK.md`):

- ✅ **Addresses** are configurable (`vostok::config`, bind vs public host, env).
- ✅ **Login server** allocates a real per-sign-in `session_id` and an account
  (keyed on IP + email) in the shared `SessionStore`. Still a mock: no password
  check, no DB (the `database/schema.sql` + `sqlx` dep are unused).
- ✅ **Lobby server** builds `ConnectionState` from the resolved `Account`, so
  distinct clients get distinct accounts. *(It snapshots the account; lobby edits
  don't write back to the store yet — Phase 4.)* `ReadyForMatch` still returns the
  constant `match_id: 0x123, team_id: 0x1` (matchmaking is Phase 3).

Still open (the remaining work surface):

- **Match server** is single-connection: `MatchConnection::wait_for_game_start`
  accepts one UDP peer and `connect()`s to it. The second "player" is a hardcoded
  static dummy (`"beauty"`); `is_connected_bitmask` is hardcoded `0b0011`. No
  per-peer table, no relay of one client's updates to another. It's also still a
  **separate process** (not in `srp`). This is Phase 4 — the core multi-client
  work, done as a *relay*, not a simulation.
- **No matchmaking** ties the lobby's `match_id`/`team_id` to the match server
  (Phase 3).
- **Robustness:** handlers still `unwrap()`/`panic!` internally; per-connection
  `catch_unwind` + the `srp` supervisor contain it (no panic can kill the
  process), but the deep unwraps remain.

Lower-priority `@TODO`s are scattered in-code (search `@TODO`): packet
splitting/retries in `match_connection.rs`, `order_id` handling, messaging
server parsing, login-server buffer parsing.

---

## Working conventions

- Keep wire-format types in `raw` submodules; keep ergonomic enums/structs
  outside them. Match the existing `snake_case`-for-wire / `CamelCase`-for-logic
  split.
- Prefer extending `vostok::serde` / `network_client` over hand-rolling byte
  fiddling in a server.
- After any change, `cargo check --workspace` inside `nix develop`. There is no
  CI; this is the gate.
- The original client is the real test oracle. When a change is meant to alter
  what the client sees, say so — it can only be fully verified against the game.
- Reverse-engineering findings go in `resources/notes/`; protocol-affecting
  decisions go in `WORK.md`.

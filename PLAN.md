# PLAN — from "works on localhost" to "works on my server, with multiple clients"

## Goal

SRP is a **mock** server (see `CLAUDE.md`): it returns canned, wire-compatible
responses to drive the real client — the authoritative game logic stays in the
C++ Vostok engine. The goal here is **not** a full server rewrite. It is to make
the mock **usable** in two new ways:

1. **Remote**: a real Survarium client on another machine can connect through the
   mock hosted at a public address (a VPS / "my own server"), not just loopback.
2. **Multi-client**: several clients can be signed in at once and end up in the
   **same match**, seeing each other — implemented as a **mock relay** (fan a
   client's updates out to the others), *not* an authoritative simulation.

Keep it minimal: do the least that makes the mock usable for N clients. Don't
add real game simulation, economy, or persistence — those belong in the engine.

This is staged so each phase is independently shippable and testable against the
real client. Every numbered item below should be **its own commit**. "General
improvement" items (refactors, error handling, logging) are also their own
commits, kept separate from behavioural changes.

Status legend: ⬜ todo · 🔄 doing · ✅ done. Keep this in sync with `WORK.md`.

---

## Phase 0 — Foundations (no behavioural change yet)

- ✅ **0.1** Nix dev shell (`flake.nix`) so the workspace builds on Linux.
- ✅ **0.3** *(improvement)* Switch the ad-hoc `println!` debugging to the `log`
  crate (already a dependency via browser-server) with `env_logger`, so remote
  debugging has levels and timestamps. *(Done before 0.2 — "logged errors" in 0.2
  needs `log` first. Left the match-server `print_debug` file+stdout packet trace
  in `utils.rs` untouched; it's a deliberate trace, not operational logging.)*
- ✅ **0.2** *(improvement)* Connection-accept paths no longer take down the
  server: a failed `accept()` is logged and skipped (was `?`, which killed the
  whole listener), and a panicking per-connection handler is logged as a dropped
  connection instead of swallowed. The match-server restart loop logs on panic
  too. *(Deferred: converting the deep `unwrap()`s inside the handlers to a
  `Result` shape — they mix io/openssl/deserialize error types; the per-handler
  `catch_unwind` + panic hook already contains a bad client. Revisit if needed.)*

## Phase 1 — Make it reachable remotely (the "my own server" half)

The blocker is that every "go here next" address is `127.0.0.1`. A remote client
must be told a **publicly reachable** address, and servers must bind on all
interfaces.

- ✅ **1.1** Make server **bind** addresses configurable. Default bind to
  `0.0.0.0` (all interfaces) instead of `127.0.0.1`, so remote packets arrive.
- ✅ **1.2** Separate **bind address** from **advertised address**. The login →
  browser → lobby → match chain hands the client the *next* server's address;
  that must be the public host the client can route to, which is **not** the
  same as the bind address. `vostok::config` now models per server `{ bind_host,
  public_host, port }`.
- ✅ **1.3** Load config from env overrides (`SRP_PUBLIC_HOST`, and per-server
  `SRP_<SERVER>_{BIND,PUBLIC_HOST,PORT}`) instead of compile-time constants. The
  localhost values remain the default so the local workflow is unchanged. *(A
  config-**file** loader was deferred — env covers the single-host VPS case; add
  a file only if multi-host deployments need it.)*
- 🔄 **1.4** Verify a full remote sign-in → lobby → match handshake against a
  client pointed at the public host. ✅ *Docs half done* — README now covers the
  env config and the firewall/port-forward needs (TCP 1234/1235/80, UDP 1236).
  ⬜ *Live verification still pending* — needs the real client + a host.

**Exit criterion:** one client on a different machine completes the whole chain
and spawns into a match hosted on the VPS.

## Phase 2 — Single-process mock with a shared in-memory session store

Right now every client *is* the same dummy account. Multiplayer needs distinct
identities flowing from login through lobby into the match.

**Agreed design** (scoping decision, see `WORK.md` 2026-05-30): one **unified
`srp` binary** runs the login + lobby + browser servers as threads sharing an
`Arc<SessionStore>`. The **match server stays a separate process for now** (it
joins the shared store in Phase 4; it doesn't need sessions until then). A panic
in one server thread must **not** crash the process. Because the merged servers no
longer each own a terminal tab, each routes its logs to a per-server file that the
bootstrap scripts tail in separate tabs.

- ✅ **2.1** Login server allocates a **unique** `session_id` per sign-in (was the
  constant `0xDD00`). The counter moves into the store in 2.6.
- ✅ **2.2** `crates/session`: `Account` (full per-account state — profiles,
  inventory, money, skills, reputations; defaults = today's dummy values) +
  `SessionStore` (accounts keyed by a unique id derived from **client IP + email**;
  empty email accepted; name = email, or a unique fallback when empty; a
  `session_id → account` map; the session-id counter seeded at `0xDD00`). Pure
  addition, 4 unit tests. *Not wired into the servers yet — that's 2.6/2.7.*
- ✅ **2.3** Per-server **file-routing logger** (`servers/srp/src/logger.rs`): a
  `log::Log` impl that routes each record to `logs/<server>.log` by target prefix
  (`login_server`→login, `lobby_server`/`messaging`→lobby, `browser_server`/`actix`
  →browser, else srp) **and** echoes to stdout. Installed by the unified bin; level
  from `RUST_LOG` (default info). `logs/` is gitignored. Verified by running the
  bin: actix logs landed in `browser.log`, orchestrator lines in `srp.log`.
- ✅ **2.4** *(refactor)* Lib-ify login/lobby/browser — each exposes
  `pub fn run(store: Arc<SessionStore>) -> io::Result<()>` (store unused for now)
  with a thin standalone `main.rs`. Browser's `run` drives a fresh actix runtime
  via `System::new().block_on`. No behaviour change.
- ✅ **2.5** Unified **`srp` binary** (`servers/srp`): builds one shared store,
  spawns a supervised thread per server (`catch_unwind` + restart after a 1s
  delay, so no server can crash the process). Uses `env_logger` for now; the file
  logger lands in 2.3.
- ✅ **2.6** Wire **login → store**: on sign-in the login server resolves the
  account from `(peer IP, email)` and opens a session via the shared store, then
  sends that `session_id`. The local atomic counter from 2.1 is gone (the store
  owns it now, still seeded at `0xDD00`). This completes 2.1's `session → account`
  half.
- ⬜ **2.7** Wire **lobby → store**: `ConnectionState` backed by the shared
  `Account` resolved via `session_id`; fall back to a default account when the
  session is absent (standalone runs).
- ⬜ **2.8** Update **bootstrap scripts** to tail per-server logs in separate tabs.

**Exit criterion:** two clients sign in with distinct IP/email and see *different*
accounts in the lobby; one process where no server can crash another; logs still
separable per server.

## Phase 3 — Matchmaking glue (lobby ↔ match)

- ⬜ **3.1** A match registry: lobby's `ReadyForMatch` allocates/returns a real
  `match_id` + `team_id` that the match server recognises, instead of the
  constant `0x123 / 0x1`. Assign teams (balance two sides).
- ⬜ **3.2** Match server learns the **expected roster** for a `match_id` (who is
  allowed, which team, which session) before/at connect time, replacing the
  hardcoded 2-player setup.

**Exit criterion:** the lobby can route two clients into the *same* match on
opposite (or same) teams.

## Phase 4 — Multi-client match server (mock relay, not a game loop)

`MatchConnection` is one-peer-only. This phase lets the **mock** accept several
peers and relay between them so players see each other. It is explicitly **not**
an authoritative game loop — no real simulation, just enough fan-out to be
usable. Split into several commits as it lands.

- ⬜ **4.1** *(refactor)* Generalise the UDP transport from "the connection" to
  "a connection in a table keyed by `SocketAddr`/`session_id`". One socket,
  `recv_from` demultiplexes to per-peer `MatchConnection` state. Keep the
  existing reliable-UDP logic per peer.
- ⬜ **4.2** One mock `Game` shared by all peers (per-peer channels fan in; the
  game fans out to each peer). Replace the hardcoded second player ("beauty")
  with the **real** connected players.
- ⬜ **4.3** Spawn each connected client as its own player; compute
  `is_connected_bitmask` from the live roster instead of `0b0011`.
- ⬜ **4.4** Relay `ClientPlayerUpdate` from each client to **all the others**,
  so players see each other move/shoot. Handle join/leave mid-match. This is the
  crux of "multi-client" for a mock — a relay, not authoritative reconciliation.
- ⬜ **4.5** *(only if needed)* Tighten the reliability layer for multi-peer:
  per-peer unacked/retransmit, packet splitting when a tick's messages exceed one
  datagram, `order_id` handling. Do the minimum the relay actually needs.

**Exit criterion:** two real clients move around the same map and see each
other; a third can join. (Mock-level fidelity — desync vs. the engine is fine.)

## Phase 5 — Hardening enough to be usable

Keep this light — it's a mock test server, not production.

- ⬜ **5.1** Per-peer timeout / disconnect detection and clean teardown so one
  client dropping doesn't panic the whole mock.
- ⬜ **5.2** Basic guards: cap connections, validate session before allocating
  per-peer state, don't `panic!` on malformed input from a remote peer.

> Explicitly **out of scope**: converting to async/`tokio`, a real database, an
> authoritative simulation. The thread-per-peer model is fine for a mock; revisit
> only if it actually breaks.

---

## Sequencing rationale

- **Phase 1 first** because "remote" is a precondition for the user's own server
  and is cheap & low-risk (config only). It also makes Phase 4 testable with two
  *real* remote machines rather than two loopback clients.
- **Phases 2–3 before 4** because the match server can't tell clients apart or
  know who belongs in a match until identity and matchmaking exist.
- **Phase 4 is the core**; everything before it is plumbing that makes 4 both
  possible and verifiable.
- **Phase 5 last** — don't harden an architecture that's still moving.

## What we are explicitly NOT doing (now)

- Byte-matching the engine (that's the `vostok/` repo).
- Anti-cheat, persistence of match results, clans/economy balancing.
- Rewriting to async up front — only if thread-per-peer proves insufficient.
- A production auth system — a minimal session store is enough for "my server".

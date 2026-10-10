<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
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
- ✅ **2.7** Wire **lobby → store**: `ServerState::run` resolves the `Account`
  from `session_id` and builds `ConnectionState::from_account`; falls back to a
  default account when the session is unknown (standalone runs). Two clients with
  distinct IP/email now get distinct accounts. *(The lobby snapshots the account;
  live write-back to the store — for the match server to see lobby edits — is left
  to Phase 4.)*
- ✅ **2.8** Bootstrap launchers (both OSes): one launches the unified `srp`
  binary, the match server (separate process), and a per-server log view.
  - `survarium-dev-bootstrap.bat` (Windows Terminal tabs; `Get-Content -Wait`).
  - `scripts/dev-bootstrap.sh` (Linux, tmux windows; `tail -F`) — so the server is
    runnable end-to-end from Linux. tmux is provided by the flake dev shell.

**Exit criterion:** two clients sign in with distinct IP/email and see *different*
accounts in the lobby; one process where no server can crash another; logs still
separable per server. *Structurally complete and unit/run-tested on Linux; the
two-real-clients check needs the game client (PLAN 1.4-style live verification).*

## Phase 3 — Matchmaking glue (lobby side)

Separate PR. **Scope note:** matchmaking state is shared in-memory, and the match
server is a *separate process* until Phase 4 — so the match server can't read the
registry yet. Phase 3 therefore does the **lobby side** only; the match server
honouring the assignment (the original 3.2) moves to Phase 4, where the match
server joins the unified process.

- ✅ **3.1** Match registry in `crates/session` (`Matchmaker` inside
  `SessionStore`): `join_match(session_id)` fills one open match at a time,
  balancing the two teams, and is idempotent per session; `match_assignment`
  reads it back. Seeded so the first match is the historic `match_id 0x123`, team
  `1` (single-client flow unchanged). Unit-tested.
- ✅ **3.2** Lobby `ReadyForMatch` returns the **real** `match_id`/`team_id` from
  `store.join_match(session_id)` instead of the constant `0x123 / 0x1`, and logs
  the routing.

**Exit criterion (lobby side):** the lobby allocates a real, team-balanced
`match_id`/`team_id` per session and records it for the match server to consume in
Phase 4. *(The full "two clients in the same match" check is a Phase 4 +
live-client item.)*

## Phase 4 — Multi-client match server (mock relay, not a game loop)

`MatchConnection` is one-peer-only. This phase lets the **mock** accept several
peers and relay between them so players see each other. It is explicitly **not**
an authoritative game loop — no real simulation, just enough fan-out to be
usable. Split into several commits as it lands.

- ✅ **4.0** *(was 3.2)* Match server is now the 4th supervised thread in `srp`,
  sharing the store, and **honours the matchmaking assignment**: on
  `ConnectionRequest { session_id }` it looks up `match_assignment(session_id)` and
  logs the match/team it was routed to (warns, but still accepts, when there's no
  assignment — e.g. match run standalone). *Still single-peer; using the team to
  drive spawns comes with the multi-peer relay (4.2/4.3).* **← paused here.**
- ✅ **4.1** *(refactor)* UDP transport generalised: `transport.rs` holds a
  per-peer `Transport` (the reliable seq/ack logic, unchanged) with no threads or
  socket; `match_server.rs`'s `MatchServer` owns one non-blocking `UdpSocket`,
  demultiplexes `recv_from` to a `HashMap<SocketAddr, Peer>`, and paces a 120 Hz
  loop.
- ✅ **4.2** One shared relay (`MatchServer`) instead of per-peer channels; the
  hardcoded "beauty" bot is gone. `game.rs` is now pure canned content
  (MatchOptions/profile/spawn).
- ✅ **4.3** Each peer is assigned a `player_id` (team from the matchmaker), gets
  a dynamic roster at `GetStartupInfo` (one profile per connected peer, its own
  marked `is_local`), and is spawned to/by the others on join.
  `is_connected_bitmask` is computed from the live roster.
- ✅ **4.4** `ClientPlayerUpdate` is relayed to every other peer as
  `ServerPlayerInput{player_id}` — the dumb broadcast (no reconciliation).
  Disconnect drops the peer and refreshes the others' connected bitmask.
- ⬜ **4.5** *(only if needed)* Per-peer retransmit / packet splitting / `order_id`
  — left as before (the originals never retransmitted either); revisit only if
  in-game testing shows it's needed.

**Exit criterion:** two real clients move around the same map and see each other.
*Structurally complete; verified on-machine via a loopback UDP integration test
(connection handshake → `ConnectionSuccessful`). The real two-client check needs
the game client — roster/late-join timing will likely need in-game iteration.*

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

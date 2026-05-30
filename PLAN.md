# PLAN — from "works on localhost" to "works on my server, with multiple clients"

## Goal

Today the four servers only work for **one client on `127.0.0.1`**. Two things
must become true:

1. **Remote**: a real Survarium client on another machine can connect through a
   server hosted at a public address (a VPS / "my own server").
2. **Multi-client**: several clients can be signed in simultaneously and **play
   the same match together**, seeing each other move and shoot.

This is staged so each phase is independently shippable and testable against the
real client. Every numbered item below should be **its own commit**. "General
improvement" items (refactors, error handling, async) are also their own
commits, kept separate from behavioural changes.

Status legend: ⬜ todo · 🔄 doing · ✅ done. Keep this in sync with `WORK.md`.

---

## Phase 0 — Foundations (no behavioural change yet)

- ✅ **0.1** Nix dev shell (`flake.nix`) so the workspace builds on Linux.
- ⬜ **0.2** *(improvement)* Replace `unwrap()`/`panic!` in connection-accept
  paths with logged errors that drop the one connection instead of killing the
  server. Introduce a small `Result`-returning handler shape. No protocol change.
- ⬜ **0.3** *(improvement)* Switch the ad-hoc `println!` debugging to the `log`
  crate (already a dependency via browser-server) with `env_logger`, so remote
  debugging has levels and timestamps.

## Phase 1 — Make it reachable remotely (the "my own server" half)

The blocker is that every "go here next" address is `127.0.0.1`. A remote client
must be told a **publicly reachable** address, and servers must bind on all
interfaces.

- ⬜ **1.1** Make server **bind** addresses configurable. Default bind to
  `0.0.0.0` (all interfaces) instead of `127.0.0.1`, so remote packets arrive.
- ⬜ **1.2** Separate **bind address** from **advertised address**. The login →
  browser → lobby → match chain hands the client the *next* server's address;
  that must be the public host the client can route to, which is **not** the
  same as the bind address. Introduce a config with, per server, `{ bind, port,
  public_host }`.
- ⬜ **1.3** Load config from a file + env overrides (e.g. `SRP_CONFIG`,
  `SRP_PUBLIC_HOST`) instead of compile-time constants in
  `vostok::config`. Keep the localhost values as the default so the local
  workflow is unchanged.
- ⬜ **1.4** Verify a full remote sign-in → lobby → match handshake against a
  client pointed at the public host. Document the firewall/port-forward needs
  (TCP 1234/1235/80, UDP 1236) in README.

**Exit criterion:** one client on a different machine completes the whole chain
and spawns into a match hosted on the VPS.

## Phase 2 — Identity & sessions (prerequisite for telling clients apart)

Right now every client *is* the same dummy account. Multiplayer needs distinct
identities flowing from login through lobby into the match.

- ⬜ **2.1** Login server: allocate a **unique** `session_id` per sign-in
  (instead of the constant `0xDD00`) and remember `session_id → account`.
- ⬜ **2.2** A shared session store (in-memory first) the lobby and match
  servers can consult to resolve `session_id → account/profile`. Decide on a
  transport (shared process? small internal RPC? shared sqlite?) — see
  `WORK.md` open questions.
- ⬜ **2.3** *(optional / improvement)* Wire `database/schema.sql` + `sqlx` for
  real accounts; keep an in-memory fallback for dev. Only if 2.2 proves it pays
  off; otherwise defer.
- ⬜ **2.4** Lobby server: derive `ConnectionState` from the resolved account
  rather than `new_dummy`, so two clients have two different profiles/inventories.

**Exit criterion:** two clients sign in and see *different* names/profiles in the
lobby.

## Phase 3 — Matchmaking glue (lobby ↔ match)

- ⬜ **3.1** A match registry: lobby's `ReadyForMatch` allocates/returns a real
  `match_id` + `team_id` that the match server recognises, instead of the
  constant `0x123 / 0x1`. Assign teams (balance two sides).
- ⬜ **3.2** Match server learns the **expected roster** for a `match_id` (who is
  allowed, which team, which session) before/at connect time, replacing the
  hardcoded 2-player setup.

**Exit criterion:** the lobby can route two clients into the *same* match on
opposite (or same) teams.

## Phase 4 — Multi-client match server (the hard part)

`MatchConnection` is one-peer-only. This phase turns the match server into an
N-peer authoritative game loop. This is the bulk of the real work and should be
split into several commits as it lands.

- ⬜ **4.1** *(refactor)* Generalise the UDP transport from "the connection" to
  "a connection in a table keyed by `SocketAddr`/`session_id`". One socket,
  `recv_from` demultiplexes to per-peer `MatchConnection` state. Keep the
  existing reliable-UDP logic per peer.
- ⬜ **4.2** A single authoritative `Game` shared by all peers (the per-peer
  channels fan into one game; the game fans out to each peer). Replace the
  hardcoded second player with **real** connected players.
- ⬜ **4.3** Spawn each connected client as its own player; compute
  `is_connected_bitmask` from the live roster instead of `0b0011`.
- ⬜ **4.4** Route `ClientPlayerUpdate` from each client to **all the others**
  (broadcast/relay), so players see each other move/shoot. Handle join/leave
  mid-match.
- ⬜ **4.5** Tighten the reliability layer for multi-peer: per-peer
  unacked/retransmit, packet splitting when a tick's messages exceed one
  datagram, and proper `order_id` handling (currently only partial).

**Exit criterion:** two real clients move around the same map and see each
other; a third can join.

## Phase 5 — Hardening for real use

- ⬜ **5.1** Timeouts / disconnect detection per peer; clean teardown so one
  client dropping doesn't desync or panic the match.
- ⬜ **5.2** Decide threads-vs-async. If peer counts grow, consider `tokio`
  (already pulled in transitively via `sqlx`/`actix`). This is a big refactor —
  only do it if Phase 4 shows the thread-per-peer model straining.
- ⬜ **5.3** Basic load/abuse guards (cap connections, validate session before
  allocating per-peer state).

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

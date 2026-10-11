<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# Roadmap

Goal: a mock usable from a remote host by several clients in one match. The
match server relays between clients; it does not simulate the game.

| Phase | Scope | Status |
|-------|-------|--------|
| 0. Foundations | `log` crate in the servers; a bad connection no longer kills a server | done |
| 1. Remote hosting | bind vs advertised addresses, `SRP_*` env config, hosting docs | done; live remote check pending |
| 2. Sessions | unified `srp` process, in-memory session store, per-server logs, tmux bootstrap | done; two-client check needs the game |
| 3. Matchmaking | lobby assigns a team-balanced match per session | done |
| 4. Match relay | match server joins `srp`, honours the assignment, relays movement between peers | in progress: joins `srp` and honours the assignment, still single-peer |
| 5. Hardening | reap idle peers, drop malformed or stale packets, cap peer count | todo |

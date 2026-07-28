# WORK — running log of decisions (taken and not taken)

Newest entries at the top. Each entry: what changed, why, alternatives
considered, and what it means for the client. Cross-reference `PLAN.md` items.

---

## 2026-05-30 — Decision: in-memory, single-process session sharing

Resolved open question #1. The lobby and match servers will share per-client
session/account state via an **in-memory store in a single process** (the mock
servers can be merged behind one binary), rather than a shared SQLite DB or an
internal RPC. Rationale: it's a mock — the simplest thing that lets the servers
see the same sessions wins, and there's no persistence requirement. This shapes
Phase 2 (identity) and Phase 3 (matchmaking): they become shared-memory lookups,
not cross-process calls. May require merging some `servers/*` bins into one
process with internal threads; to be designed when Phase 2 starts.

## 2026-05-30 — Phase 0.2: accept loops don't kill the server

### Decisions taken
- **A failed `accept()` is logged and skipped, not propagated.** Both the login
  and lobby accept loops did `let stream = stream?;`, so a single transient
  accept error (e.g. fd exhaustion) returned from `main` and killed the whole
  server. Now they `match` and `continue`. This is the concrete "drop the one
  connection instead of killing the server" from the plan.
- **Panicking handlers are logged.** The per-connection `catch_unwind` result was
  discarded with `_ =`; now an `Err` logs "dropped the connection". The match
  server's restart loop logs before restarting. (The default panic hook still
  prints the panic detail to stderr; this just adds an operational marker.)

### Not taken (deliberately)
- **Did not convert the deep `unwrap()`s inside handlers to `Result`.** The plan
  floated "a small Result-returning handler shape", but the handlers mix
  `io::Error`, openssl `ErrorStack`, and `DeserializeError`; a faithful
  conversion is a bigger, riskier change for little gain on a mock, since the
  per-connection `catch_unwind` already isolates a bad client. Left as a future
  pass; noted in PLAN 0.2.
- Kept the existing inline accept-loop style (didn't extract a shared helper into
  `vostok`) per the "match the existing conventions" guidance — the two servers
  already mirror each other.

---

## 2026-05-30 — Phase 0.3: structured logging (println → log)

User asked for general server-implementation improvements as their own commits.
Did logging first because 0.2 ("logged errors") depends on it.

### Decisions taken
- Added `log` + `env_logger` to the login/lobby/match server crates (browser
  server already had them) and `env_logger::init()` to each `main`.
- Converted operational `println!`s to `log::{info,debug,error}!`: connection
  lifecycle → `info`, decode/parse failures → `error`, verbose per-message dumps
  → `debug`. **Kept the original message wording and style** (per user note:
  prefer the existing conventions) — only the mechanism changed.
- **Left `match-server/src/utils.rs` `print_debug` untouched.** It's a bespoke
  packet trace that tees to `./target/debug/match-server-<ts>.log` *and* stdout;
  rerouting it through `log` would change that behaviour for no real gain on a
  mock. Flagged for a later pass if it becomes noisy.

### Verified
`cargo check --workspace` clean (same single pre-existing warning). Default log
output is quieter than before (was unconditional `println!`); set `RUST_LOG`
(e.g. `RUST_LOG=debug`) to restore verbosity.

---

## 2026-05-30 — Phase 1: configurable bind vs advertised addresses

`PLAN.md` 1.1–1.3. Replaced the hardcoded-`127.0.0.1` constants in
`vostok::config` with a runtime `Config` read once from the environment.

### Decisions taken
- **Per-server `{ bind_host, public_host, port }`.** The bind host (where we
  listen) and the public host (what we tell the client to connect to next) are
  genuinely different on a real deployment — the bind is `0.0.0.0`, the public
  host is the VPS's routable address. Both hosts default to `127.0.0.1`, with
  the original ports, so no-env runs remain local-only; remote exposure is an
  explicit opt-in.
- **Env, not a config file (for now).** `SRP_BIND_HOST` and `SRP_PUBLIC_HOST`
  set the shared bind/public hosts for all four servers at once (the common
  "one VPS hosts everything" case);
  `SRP_<SERVER>_{BIND,PUBLIC_HOST,PORT}` override individually. A file loader was
  considered and **deferred** — it adds a parser dependency and only pays off for
  multi-host splits, which aren't a current need.
- **Global `OnceLock` accessor `config::get()`.** Chosen so deep call sites can
  read config without threading a `Config` through every function — notably the
  lobby's `Serialize` impl that advertises the match-server address has no other
  access to runtime state. Initialised lazily from env on first use.
- **Advertised hosts wired through:** login → browser host (host only; HTTP/80,
  client appends the path), browser → lobby `public_addr()`, lobby → match
  `public_host`+`port`. Bind sites (`TcpListener`/`UdpSocket`/actix) use
  `bind_addr()`.

### Verified
`cargo check --workspace` clean (only the pre-existing unused-import warning in
`parse-journal-file`). Behaviour with no env vars is identical to before.
**Not** yet verified against the real client over a network (PLAN 1.4) — needs a
client + host; that's the remaining Phase 1 step.

### Not taken
- Did not touch the match server's single-peer assumption (that's Phase 4).
- Did not add a `--config`/file format or `clap` plumbing — env is enough.

---

## 2026-05-30 — Reframe: this is a *mock*, not a server rewrite

User correction: SRP is a **mock** of the server, deliberately not a full
implementation — the real/authoritative game logic stays in the C++ Vostok
engine (sibling `vostok/` repo). It must stay a **usable** server, just not a
rewrite.

### What this changes
- **`CLAUDE.md`**: reframed "what this is" as a mock; relabelled "Known
  limitations" → "Mock simplifications" and clarified many dummy values are
  intentional mock data, and that the goal is multi-client *usability*, not
  authoritative simulation.
- **`PLAN.md`**: goal restated as "make the mock usable remotely + multi-client";
  Phase 4 de-scoped from "authoritative N-peer game loop" to a **mock relay**
  (fan one client's updates out to others, desync vs. engine is acceptable);
  Phase 5 trimmed; async/`tokio`, a real DB, and authoritative simulation moved
  explicitly **out of scope**.

### Why it matters for the work
The hardest item (Phase 4) shrinks dramatically: we relay rather than simulate.
Identity/matchmaking (Phases 2–3) only need to be good enough to route real
clients into one shared relayed match and tell them apart — not a real account
system. This keeps every commit small and the whole effort proportionate to "a
usable mock".

---

## 2026-05-30 — Session start: orientation + scaffolding

### Context
Picked up the SRP server with the goal of making networking work **remotely**
and for **multiple clients** (see `PLAN.md`). First read the whole server
surface to understand the connection chain and where the single-client
assumptions live; recorded that understanding in `CLAUDE.md`.

### Decisions taken

- **Added a Nix dev shell (`flake.nix`/`flake.lock`)** — `PLAN.md` 0.1.
  - *Why:* there was no Rust toolchain available locally and the workspace is
    nightly-only (`edition 2024` + several `#![feature]` gates). The sibling
    `vostok/` repo already standardises on a flake, so this matches the project's
    conventions and unblocks `cargo check` on Linux.
  - *Shape:* nightly `rust-bin` via `rust-overlay` + system `openssl` exposed
    through `pkg-config` with `OPENSSL_NO_VENDOR=1`. Deliberately **much smaller**
    than vostok's flake — SRP needs none of the Wine/MSVC/objdiff toolchain, only
    Rust + OpenSSL (the `openssl` crate is the one non-pure-Rust dependency).
  - *Verified:* `nix develop --command cargo check --workspace` succeeds (one
    pre-existing unused-import warning in `parse-journal-file`, untouched).
  - *Alternative not taken:* reusing vostok's flake — rejected, it drags in a
    large game/toolchain closure irrelevant to building four Rust servers.

- **Created branch `sushi/0.100b/multiplayer`** off `0.100b`.
  - *Why:* `0.100b` is the default branch; this is multi-commit feature work, so
    it belongs on its own branch (matches the existing `sushi/0.100b/...` and
    `sushi/v0.20e/...` naming on the remote).

- **Wrote `CLAUDE.md`, `PLAN.md`, `WORK.md`.**
  - *Why:* the task is large and will span many commits/sessions; durable docs
    let the work be picked up later. `CLAUDE.md` = how the system works today;
    `PLAN.md` = staged roadmap to the goal; `WORK.md` = this log.

### Decisions deliberately deferred / not taken

- **Did not start code changes to behaviour yet.** Phase 0 docs + build first,
  so later changes can be validated by `cargo check` and the doc'd handshake.
- **Did not wire up `database/schema.sql` / `sqlx`.** Identity (Phase 2) will
  likely start with an in-memory session store; a DB is only worth it if it pays
  off (see open questions). The schema file is also currently incomplete (trailing
  comma, no real columns beyond id/username/email).
- **Did not touch the reliable-UDP logic.** It is the riskiest code and is only
  meaningfully testable against the real client; it will be approached in Phase 4
  with the client in the loop.
- **Did not convert to async.** Explicitly a Phase 5 *maybe* — not worth a big
  refactor until the thread-per-peer model is shown to strain (`PLAN.md` 5.2).

### Open questions (to resolve as phases land)

1. ~~**How do the lobby and match servers share session/account state?**~~
   **RESOLVED** → in-memory, single process (see the dated entry above).
2. **Public-address discovery for the client.** The browser/login responses must
   hand out a routable host. Will the deployment always know its public host via
   config, or do we need the client's-eye-view address? Assume config-provided
   `public_host` for now (Phase 1.2).
3. **Single match vs. many.** Phase 4 first targets one shared match; a registry
   of concurrent matches (Phase 3.1) may stay a stub (always match 0) until 4
   works for one match.
4. **Teardown semantics** when a mid-match client drops — needs the real client
   to observe desync behaviour before committing to an approach (Phase 5.1).

### Next step
Phase 1.1–1.3: make bind/advertised addresses configurable (the smallest change
that delivers the "my own server" half), defaulting to today's localhost values
so the local flow is unchanged.

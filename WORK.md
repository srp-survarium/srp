# WORK — running log of decisions (taken and not taken)

Newest entries at the top. Each entry: what changed, why, alternatives
considered, and what it means for the client. Cross-reference `PLAN.md` items.

---

## 2026-05-30 — Phase 4.0a: match server joins the unified process

Branch `sushi/0.100b/phase4-match` (off Phase 3). Lib-ified the match server
(`main.rs` → `lib.rs`, `run_match_server` → `pub fn run(store) -> io::Result<()>`
that loops forever; thin standalone `main.rs` keeps the restart loop). Added it as
the 4th supervised thread in `srp`, extended the file logger to route
`match_server` → `match.log`, and pointed both bootstrappers' `match` window at
`tail`-ing that log (it's no longer a separate `cargo run`).

Verified: `cargo run --bin srp` starts all four servers in one process, the match
server binds UDP 1236, no panic, all five `logs/*.log` created. `store` is unused
here (`_store`) — honouring the assignment is the next commit.

---

## 2026-05-30 — Phase 3 on its own branch; rescoped lobby-side only

Each phase is now its own PR. Phase 3 lives on `sushi/0.100b/phase3-matchmaking`,
branched off the Phase-2 branch (`sushi/0.100b/multiplayer`) since it builds on
the lobby/store from Phase 2 — a stacked PR.

### Decision: Phase 3 is lobby-side only; match honouring → Phase 4
The original PLAN had the match server learn the roster in 3.2, but matchmaking
state is shared **in-memory** and the match server is a **separate process** until
Phase 4 — so it can't read the registry yet. Rather than drag the whole match-into-
process restructuring into Phase 3, I kept Phase 3 small (lobby side) and moved
"match honours the assignment" to Phase 4.0, next to the match-server work it
belongs with. Cleaner PR boundaries; matches the existing "match joins in Phase 4"
plan.

### 3.2 — lobby `ReadyForMatch` uses the matchmaker
Threaded the store into `handle_client_message` (one new `&SessionStore` param;
`run` already held the `Arc`). The `ReadyForMatch` arm now calls
`store.join_match(connection_state.session_id)` and returns its `match_id`/
`team_id` (was the constant `0x123`/`0x1`), logging the routing. With one client
the values are identical to before, so nothing breaks; the assignment is recorded
for the match server to read in Phase 4. Full `cargo check --workspace` clean.

### 3.1 — matchmaker in `crates/session`
Added a `Matchmaker` inside `SessionStore`: `join_match(session_id)` fills one
open match (cap 20) at a time, puts each new player on the smaller team (first
player → team 1), and is **idempotent per session**; `match_assignment` reads it
back (for the match server in Phase 4). Seeded at the historic `match_id 0x123`,
so the first/only client's match + team (`0x123` / `1`) are unchanged. 3 new unit
tests (7 total in the crate), all passing.

---

## 2026-05-30 — Linux dev bootstrapper

User asked to make the server runnable from Linux. Added `scripts/dev-bootstrap.sh`
— the tmux counterpart to the Windows `.bat`: a `srp` window (unified binary), a
`match` window, and `login`/`lobby`/`browser` windows each `tail -F`-ing
`logs/<server>.log`. `tail -F` retries on a missing file, so no wait loop is
needed. Added `tmux` to the flake dev shell so the script's only prerequisite is
`nix develop`. Verified: tmux creates detached sessions + named windows in this
environment, and `bash -n` passes. (Didn't fully launch the servers under tmux
here — that's interactive and binds ports; the tmux mechanics and the `srp` binary
were each verified separately.)

---

## 2026-05-30 — Phase 2.8: bootstrap tabs tail per-server logs

Updated `survarium-dev-bootstrap.bat`: the four per-server tabs are replaced by
one "srp servers" tab (`cargo run --bin srp`, combined stdout) plus "login log",
"lobby log", "browser log" tabs that wait for `logs\<server>.log` and then
`Get-Content -Wait` it. The match server keeps its own `cargo run --bin
match-server` tab (still a separate process, Phase 4). Used backslash paths and
no nested quotes to keep the `wt` quoting sane.

Windows-only; can't run it from this Linux box — needs a manual check on the dev
machine. This closes the structural part of Phase 2.

---

## 2026-05-30 — Phase 2.7: wire lobby → session store

`ServerState::run` now takes the shared store; after the client's `SignInInfo`
it resolves `account_for_session(session_id)` and builds the connection via the
new `ConnectionState::from_account`, falling back to a default account when the
session is unknown (standalone lobby runs, or a stale id). Deleted
`ConnectionState::new_dummy` — the dummy data lives only in `session::Account`
now (no duplication).

### Decision: snapshot, don't live-share (for now)
`ConnectionState::from_account` **clones** the account into per-connection state;
lobby mutations (equip, shop buys) stay local and don't write back to the store.
Rationale: the exit criterion (two clients see different accounts) only needs a
read, and a snapshot keeps the diff small and avoids holding the account lock
across a whole session. When the match server joins (Phase 4) and needs to see
the lobby's edits, switch the lobby to hold the `Arc<Mutex<Account>>` and mutate
through it. Flagged in PLAN 2.7.

Full `cargo check --workspace` clean; `session` tests still pass.

---

## 2026-05-30 — Phase 2.6: wire login → session store

Login's `run`/`handle_client`/`handle_sign_in` now thread the shared
`Arc<SessionStore>` through. On sign-in it reads the client's `peer_addr().ip()`
plus the email, calls `get_or_create_account(ip, email)` then `create_session`,
and sends the resulting `session_id`. Removed the local `AtomicU32` counter added
in 2.1 — the store owns session-id allocation now (still seeded at `0xDD00`, so
the first local client is unchanged). `cargo check -p login-server` clean.

---

## 2026-05-30 — Phase 2.3: per-server file-routing logger

`servers/srp/src/logger.rs` — a `log::Log` backend that routes each record to
`logs/<server>.log` by `target()` prefix and also echoes to stdout (the user's
"files + tail, also stdout" choice). Routing: `login_server`→login,
`lobby_server`/`messaging`→lobby, `browser_server`/`actix`→browser, everything
else (incl. the orchestrator)→srp. The unified bin installs it; level comes from
`RUST_LOG` as a single filter (default info), parsed simply rather than pulling
in env_logger's full syntax. `logs/` is gitignored.

**Verified live:** ran `RUST_LOG=info SRP_BROWSER_PORT=8080 ./target/debug/srp` —
all three servers started in one process, actix's own logs were folded into
`browser.log`, and killing the browser thread produced a supervisor
"browser server exited; restarting" line in `srp.log` and a clean restart
(crash isolation confirmed end-to-end). login/lobby logs were empty only because
nothing connected.

---

## 2026-05-30 — Phase 2.5: unified `srp` binary with crash isolation

New `servers/srp` bin runs login + browser + lobby in one process sharing one
`Arc<SessionStore>`. Each runs on a named thread under `supervise()`, which loops
`catch_unwind(run)` and restarts (after a 1s delay to avoid a hot loop) on clean
exit, error, or panic — so no server can take the process down (the user's hard
requirement). `AssertUnwindSafe` wraps the closure (`Arc<SessionStore>` is fine
across the boundary). Still `env_logger`; the per-server file logger is 2.3 next.

---

## 2026-05-30 — Phase 2.4: lib-ify login/lobby/browser

Each server crate is now a lib + thin bin. `main.rs` → `lib.rs` (via `git mv`),
`fn main` → `pub fn run(store: Arc<SessionStore>) -> io::Result<()>`, and a small
new `main.rs` does `env_logger::init()` + `<crate>::run(Arc::new(SessionStore::new()))`
for standalone use. The unified `srp` bin (2.5) will instead share one store
across all three.
- `run` does **not** init logging — the caller chooses (standalone main uses
  env_logger; the unified bin installs the file logger).
- Browser's `run` is blocking: `actix_web::rt::System::new().block_on(serve())`,
  so it fits the uniform `run` shape and can be spawned on a thread.
- `store` is `_store` (unused) for now; login wiring is 2.6, lobby 2.7, and the
  browser server never needs it.
- No behaviour change; `cargo check --workspace --bins` clean.

---

## 2026-05-30 — Phase 2.2: `crates/session` (Account + SessionStore)

Two commits.

- **Moved `faction_id`/`player_skill`/`player_reputation` into `survarium`.** They
  were lobby-server-private, so a shared `session` crate couldn't name them.
  Re-exported from the lobby's `raw` modules → lobby call sites unchanged. Pure
  refactor.
- **Added `crates/session`** (depends on `survarium`):
  - `Account` — the full per-account payload the lobby used to fabricate inline
    (money, skills, profiles, inventory, reputations). `Account::new_dummy(id,
    name)` reproduces the historic dummy values verbatim, so the data the client
    sees is unchanged once wired in. (The commented-out inventory entries from the
    lobby's `new_dummy` were dropped, matching the live set.)
  - `SessionStore` — `Mutex<HashMap>` of accounts + sessions, std-only (no new
    deps). `get_or_create_account(ip, email)` (id = non-zero hash of ip+email,
    empty email → `player_<id>` name), `create_session` (counter seeded at the
    historic `0xDD00`), `account_for_session` (hands out `Arc<Mutex<Account>>` so
    the lobby and, later, the match server mutate the *same* account).
  - 4 unit tests, all passing.

### Behaviour note
Once wired (2.6/2.7), the local client's account **id and name change**: id is now
the ip+email hash (was the constant `1`) and name is the email (was
`"dummy_name"`). That's the intended identity behaviour; the `session_id` still
starts at `0xDD00`, and all other account *contents* are byte-identical to the old
dummy.

### Not taken
- `Account::id` keeps doubling as the running "next bought-item id" counter, as in
  the original mock — didn't split that conflation now to keep the wiring diff
  small; can revisit later.

---

## 2026-05-30 — Scoping Phase 2 (single-process mock + session store)

Scoped the in-memory session store with the user. Restructured PLAN Phase 2 into
2.2–2.8. Answers to the three forks and the resulting design:

### Topology → **unified `srp` binary, match deferred**
One process runs login + lobby + browser as threads sharing `Arc<SessionStore>`;
the match server stays a separate process until Phase 4. Two hard requirements
the user added:
- **Crash isolation:** no server thread may take down the process. Each server
  runs under `catch_unwind` with restart, on top of the existing per-connection
  isolation.
- **Per-server logs on separate tabs:** since the merged servers no longer each
  own a terminal tab, each writes to its own log file (`logs/<server>.log`) and
  the bootstrap opens a tab per file that tails it. Implemented as a custom
  `log::Log` that routes by record `target()` prefix (the `log` macros default
  the target to the module path, which carries the originating crate name).

### Identity → **id from IP + email, no real accounts**
No real account system. `account_id` is a unique value derived from
`(client IP, email)`; the **empty email is accepted**; reconnecting from the same
IP+email resolves to the same account (good enough for a mock). Name = the email,
or a unique fallback (derived from the id) when empty. `session_id` stays a
per-sign-in counter mapping to the account.

### State depth → **full account state in the store**
`Account` holds the whole per-account payload the lobby currently fabricates in
`ConnectionState::new_dummy` (profiles, inventory, money, skills, reputations).
Rationale (user): this is what lets the **match server share account state**
later. Default values stay identical to today's dummy, so the local flow is
unchanged.

### Commit plan (each its own commit, `cargo check`-clean)
1. `crates/session` — `Account` + `SessionStore` (pure addition + unit test).
2. file-routing logger.
3. lib-ify login/lobby/browser (extract `run()`), thin mains.
4. unified `srp` bin (shared store, thread-per-server, crash isolation, logger).
5. wire login → store.
6. wire lobby → store (Account-backed `ConnectionState`).
7. bootstrap scripts tail per-server logs.

### Not taken
- No SQLite/RPC (in-memory, single process — earlier decision).
- Match server not merged yet (Phase 4) — it doesn't consult sessions until then.

---

## 2026-05-30 — README docs + Phase 2.1 slice (unique session ids)

Two small follow-ups.

- **README**: added a Nix build/run section and a "Hosting on your own server"
  section (`SRP_PUBLIC_HOST`, per-server env overrides, ports to open). Covers
  the docs half of PLAN 1.4; live remote verification still needs the real
  client + a host.
- **Phase 2.1 (partial): unique session ids.** The login server handed *every*
  client the constant `0xDD00`, so concurrent clients were indistinguishable —
  a blocker for multi-client. Replaced it with an `AtomicU32` counter.
  - *Seeded at `0xDD00`* on purpose: the first/only client still gets the historic
    value, so the single-client local flow is byte-for-byte unchanged; only the
    2nd+ concurrent client sees a different id.
  - *Still a mock:* no account lookup yet. The `session_id → account` half of 2.1
    is deferred to the shared in-memory store (2.2) — flagged in a comment at the
    allocation site and in PLAN.
  - Verified with `cargo check -p login-server`.

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

<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# Survarium 0.26g0 development match server

This endpoint supports retail **0.26g0 build 2777** with the matching development
client patches. It relays native simulation inputs and uses client-generated,
CRC-verified historical checkpoints for late joining, recovery, and results.
It is intended for local development: session tokens are not account
authentication, and a client checkpoint is not an authoritative server simulation.
The default bind address is loopback.

## Current status

| Capability | Evidence and limits |
|---|---|
| Two-client gameplay | User confirmed kills, death/respawn, battery pickup and base deposits. |
| School in rain (`--map 71`) | User preview accepted; 1,797 shared historical ticks matched in a native two-client run. |
| Late join and recovery | Native two-client runs exercised checkpoint transfer, input replay, departures and deliberate dropped relay inputs. |
| Crash/relaunch | Fixed roster identities preserve slot/name/team/squad and prior shot counters while another client remains. One automatic recovery resolved 15 initial mismatches; 1,118 subsequent comparisons matched. Requires `--recover`. Last-player crash resumption is unsupported. |
| Match finish/results | Native time-limit finish and F8 result display/Close tested. Scores use an explicit development preset, not recovered retail reward policy. Kill/deposit result-row acceptance is still pending. |
| Next match | Close results, then F6; two clients completed two consecutive matches in the same processes. Stock lobby Play is not initialized. |
| Battery victory | Opt-in `--finish-objective` tested with controlled native battery events. Ordinary physical collection/deposit of every battery remains pending. |
| Squads | Roster grouping and native squad markers work. **Native lobby invites, acceptance, readiness and joining together are not implemented.** |

The most recent native login diagnostic completed TLS, then exposed an incorrect
IPv4 redirect byte order and Wine's unimplemented `QOSSetFlow`. It did not reach
a functioning lobby. `examples/lobby_probe.rs` and the lobby codec are research
scaffolding, not a supported lobby service.

## Build and run

Use the repository's Rust toolchain. Rust dependencies include `lzma-sys`, which
needs a C compiler and liblzma (or its bundled build prerequisites). The client
builder needs Python 3, GNU binutils and a GCC-compatible x86 compiler. Supply
your own extracted, hash-matched retail client; game executables, resources,
certificates, private keys and generated probes are not included here.

```sh
cargo build --locked -p match-server-026
python3 client/026g/tools/patch_exe.py /path/to/retail/survarium.exe \
  /path/to/game/binaries/x86/survarium-srp.exe \
  --manifest target/026g/client-patches.json \
  --direct-match --snapshots --results --rejoin --cc gcc
```

Create `target/026g/roster.txt` with one fixed identity per client:

```text
000000a1 0 0 Alice
000000b2 1 0 Bob
```

Columns are eight-digit hexadecimal session, team (0/1), squad (0 = none), and
name. To exercise squad markers, use the same team and the same nonzero squad
for both players. A squad supports at most three members.

```sh
cargo run --locked -p match-server-026 -- \
  --bind 127.0.0.1:2236 --players 2 --start-players 1 --map 71 \
  --roster target/026g/roster.txt --snapshots --checkpoints --recover \
  --clock-sync --finish-timed --results
```

From each extracted client's `binaries/x86` directory, set `SRP_MATCH_SESSION`
to the corresponding roster token and launch:

```sh
# Wine example for Alice; use 000000b2 and a separate prefix for Bob.
SRP_MATCH_SESSION=000000a1 wine explorer /desktop=srp026,1280x720 \
  survarium-srp.exe -splash_screen -server=127.0.0.1:2236 \
  -mt_allocator=768 -hash_check_interval_in_ms=50
```

On Windows, set the environment variable before launching the same executable
and arguments without `wine explorer`. Both clients must remain active;
background stalls can disrupt these tests. See the [client guide](../../client/026g/README.md)
for Wine/DXVK setup, patches, reconnection conditions, and diagnostic flags.
Configured relaunch can reuse the previous UDP port after the same five-second
silence guard. During active recovery, a revision at or before the snapshot
baseline causes a fresh donor snapshot retry within the original five-second
deadline. A failed state transfer closes that client's transport while the
survivor continues; recovery clients cannot act as checkpoint donors.
These PR-review corrections have regression coverage and have not been rerun
with native clients.

Use `--help` for the server's full option list. Keep `--finish-after-ms`,
`--drop-relay`, `--clock-fault`, and `--restore-once-after-ms` for diagnostics.

## Verification and evidence

```sh
cargo test --locked -p match-server-026 -p survarium -p vostok
CC=cc python3 -m unittest discover -s client/026g/tests -v
cargo build --locked -p match-server-026
python3 scripts/protocol-research/smoke_server_026.py
```

The smoke test uses two synthetic loopback peers; it does not launch the game.
Checked-in semantic fixtures cover native UDP/framing, LZMA, options, animation,
timing, battery predicates, and scores. Oracle regeneration needs the original
hash-matched game executable and Linux x86-64 compatibility-mode support.

The [research record](../../scripts/protocol-research/026g-findings.md) contains
addresses, experiments and acceptance details. It is chronological: later
entries supersede earlier open questions. Paths under `target/026g` identify
local captures/screenshots/logs and are not included in the PR. Automated tests
are reproducible from the checked-in fixtures without the proprietary client;
native acceptance is separately reported and is not a CI guarantee.

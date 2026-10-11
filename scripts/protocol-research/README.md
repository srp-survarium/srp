<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# Finding functions across retail builds

These tools use the local `vostok-pdb` SQLite evidence schema. They do not
modify executables or databases. Python 3 is required; only the candidate
matcher needs Capstone.

## Function candidates

```sh
python3 scripts/protocol-research/function_candidates.py \
  --database /path/to/retail.sqlite --source /path/to/symbolized.exe \
  --target /path/to/stripped.exe --function 'network_client::' \
  --function 'udp_match_connection::' --output target/candidates.json
```

The source executable must match the database's SHA256. Code signatures mask
PE HIGHLOW relocations and direct call/jump destinations. They preserve registers,
constants, member offsets and instruction lengths. All matching addresses are
reported, including collisions. Shared string references provide candidates
when code has changed. Neither a unique signature nor a shared diagnostic string
proves that two functions are semantically equivalent.

Control result: retail 0.21d versus its patched executable yielded 298 unique
code candidates among 408 selected network/input/profile functions. Against
0.26g0, exact masked code yielded zero matches; shared strings yielded evidence
for 54 functions. Use these as anchors and inspect adjacent functions and calls.

## Source order and physical grouping

```sh
python3 scripts/protocol-research/check_function_order.py \
  /path/to/021d.sqlite /path/to/0100b.sqlite --output target/function-order.json
```

Source file attribution is a proxy for translation units, not proof of compiland
ownership or compiler/linker flags. Source-order metrics exclude headers,
duplicate starting lines and folded address aliases. Physical grouping counts
every indexed function address, including header and ambiguous functions as
intervening entries. Unindexed functions cannot be counted.

Measured locally on 2026-10-11:

| Reference | Eligible files | Entirely source ordered | One physical source-file block |
|---|---:|---:|---:|
| Retail 0.21d | 641 | 403 | 443 |
| Retail 0.100b | 1,168 | 71 | 631 |
| Local reconstruction PDB | 1,203 | 83 | 676 |

The 0.100b `udp_match_connection.cpp` functions are heavily reordered by source
line (80 inverted pairs out of 171), but all 19 occupy one uninterrupted block
of indexed function starts. All four `player_input.cpp` functions likewise stay
together. In 0.21d, UDP has a 24-function block and two static initializers in a
separate block; `game_world_core.cpp` has 41 functions in one source-ordered
block. Neighborhood search is therefore useful, but assigning names by ordinal
position across versions is unreliable.

## Retail header oracle

```sh
python3 scripts/protocol-research/retail_header_oracle.py \
  --exe target/026g/retail/survarium.exe --work target/026g/oracle \
  --output target/026g/evidence/retail-header-vectors.json \
  --tsv crates/vostok/src/network_packet/fixtures/026g-header.tsv
cargo test -p vostok
```

This hash-gated harness runs the actual 0.26g0 header parser at VA `0x3fa0a0`.
It builds a freestanding ELF with GNU `as`/`ld`, maps retail code at its original
addresses, calls it in x86 compatibility mode, and uses 64-bit Linux syscalls
for input/output. It needs Linux x86-64 compatibility-mode support. It calls no
game entry point, Windows imports or networking. Generated binaries contain
retail code and belong in ignored build directories, not in source control.

The 416 deterministic, valid-input cases cover all short control bytes and each
extension length. The checked-in TSV under
`crates/vostok/src/network_packet/fixtures/` contains inputs and results only.
The Rust decoder matches those results and its encoder reproduces the input
bytes. Malformed-input tests separately verify bounds checks; the harness does
not run malformed inputs through the retail parser.

`retail_frame_oracle.py` uses the same harness for the original message parser
and delivery/length getters. Its 77 cases cover every application ID, fixed and
variable lengths, single and bundle modes, and fragmented static/world data:

```sh
python3 scripts/protocol-research/retail_frame_oracle.py \
  --exe target/026g/retail/survarium.exe --work target/026g/frame-oracle \
  --tsv crates/survarium/src/fixtures/026g-frames.tsv
cargo test -p survarium
```

The same harness also executes the original raw LZMA2 decoder and complete
match-options reader, including inventory dictionary lookup. These optional
regeneration commands require the locally supplied, hash-matched executable:

```sh
python3 scripts/protocol-research/retail_lzma_oracle.py \
  --exe target/026g/retail/survarium.exe --work target/026g/lzma-oracle \
  --tsv crates/survarium/src/fixtures/026g-lzma.tsv
python3 scripts/protocol-research/retail_options_oracle.py \
  --exe target/026g/retail/survarium.exe --work target/026g/options-oracle \
  --output crates/survarium/src/fixtures/026g-options.hex
```

The codec and endpoint tests use checked-in semantic fixtures and do not require
game binaries. A separate smoke test runs two synthetic peers over loopback UDP:

```sh
cargo test -p match-server-026 -p survarium -p vostok
cargo build -p match-server-026
python3 scripts/protocol-research/smoke_server_026.py
```

See [026g-findings.md](026g-findings.md) for recovered addresses, formats,
endpoint behavior and the remaining real-client integration work.

## Historical state boundaries

The capture inspector accepts an optional output directory for complete E2
bodies and validates player/animation boundaries plus six world blocks:

```sh
cargo run -p match-server-026 --example inspect_capture -- packets.tsv 2 target/states
python3 scripts/protocol-research/retail_animation_oracle.py \
  --exe /path/to/retail/survarium.exe --work target/animation-oracle \
  --output target/animation-oracle.json --tsv target/animations.tsv \
  target/states/*.bin
```

The oracle uses the same hash-checked ELF harness to execute native
`decode_data` at `0x3a9900`, including its compressed time and float readers.
It accepts trusted captured states only. It supports animation envelopes up to
512 bytes and fails if the native consumption exceeds that window. It checks
that six following length-prefixed blocks end exactly at the snapshot boundary.
The Rust regression fixtures cover 253 distinct native animation envelopes and
two complete School snapshots; malformed/truncated inputs run only through the
bounded Rust reader.

## Native match timers

Reproduce the pinned map table from the locally extracted gameplay configs:

```sh
python3 scripts/protocol-research/extract_mode_timers_026.py \
  --gameplay target/026g/game-configs/overlay/gameplay \
  --cli target/debug/binary-config-cli \
  --json target/026g/evidence/mode-timers.json \
  --tsv servers/match-server-026/fixtures/026g-mode-timers.tsv
python3 scripts/protocol-research/retail_timelimit_oracle.py \
  --exe /path/to/retail/survarium.exe --work target/timelimit-oracle \
  --tsv servers/match-server-026/fixtures/026g-timelimit.tsv
```

The local dictionary has 89 maps: 77 available configs place time-limit rule 93
first, two use other rules, and ten configs are missing. Each timer row includes
the config's SHA256. Inclusion does not establish map playability: test map 115
has a 90-second timer but crashed during native loading. The native predicate
oracle captures 84 cases across rule states and deadline boundaries; Rust checks
those results against its bounded checkpoint reader.

`--finish-timed` requires `--checkpoints` and a map in that table. It evaluates
only recent CRC-verified checkpoints with matching historical membership and
timer identity. It never predicts completion from an earlier checkpoint.
The server also implements conservative battery completion and checkpoint-derived
F8 results. See the [current server status](../../servers/match-server-026/README.md)
for validation limits; native lobby invitations remain unfinished.

## Match statistics

```sh
cargo run -p match-server-026 --example inspect_statistics -- \
  2 10 target/states/*.bin
```

Arguments are the static roster size, configured victory-item count, and complete
snapshot bodies. These counts are not encoded in the statistics block. The
reader checks player-event masks, sparse intermediate data, victory-item event
data, the team summary, and exact consumption. It reports raw event indices and
the native winner enum; neither is treated as a match-completion signal.
Native serialization anchors are `0x2f5ac0`, `0x335750`, `0x3353c0`, and
`0x334dc0`. Live captures cover 365 complete blocks, including nonzero byte event
19 and word event 22. This establishes their layout, not the meaning of every
event. Later F8 results integration is documented in the current server guide.

## Native results UI probe

```sh
python3 scripts/protocol-research/build_results_probe_026.py \
  --exe /path/to/retail/survarium.exe \
  --output /path/to/game/binaries/x86/survarium-results-probe.exe \
  --work target/results-probe --cc /path/to/gcc
```

This deliberately separate diagnostic renders a row named `UI diagnostic` with
zero counters after the server's `--finish-after-ms` trigger. It exercises the
original results window, required data objects, player-list binding, and removal
of the lobby sync overlay. It is **not** live result delivery or reward logic.
The normal client CLI is unaffected. On this toolchain the probe reproduces the
tested executable byte-for-byte, while the canonical builder still produces
its previously verified SHA256. An early Close-button test left the diagnostic window visible. The later
canonical `--results --rejoin` client supports Close followed by F6 and has
completed two consecutive native matches with two clients.

## Battery rule oracle

```sh
python3 scripts/protocol-research/retail_battery_oracle.py \
  --exe /path/to/retail/survarium.exe --work target/battery-oracle \
  --tsv servers/match-server-026/fixtures/026g-battery.tsv
```

The 144 native cases verify deposit/removal updates, live team scores and winner,
the three-second delay after collecting all required items, completion at the
deadline, and ignored later item events once victory has been scheduled.
This establishes native semantics. The server now implements optional
`--finish-objective`; ordinary physical collection of every battery remains an
outstanding acceptance check despite successful controlled native rule tests.

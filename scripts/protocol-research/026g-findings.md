<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# 0.26g0 protocol evidence

This is a chronological research record. For current supported behavior and
remaining work, see the [server guide](../../servers/match-server-026/README.md).
Captures, screenshots, executable-derived harnesses, and decompiler exports
referenced under `target/026g` are local evidence, not checked-in artifacts.

Target: **0.26g0, build 2777**, explicitly selected over 0.26e0.
Retail executable SHA256:
`ac33d9937015c2299bf62cc6b127cb308b48a3475b30fff2ddd65479ae3bf153`.
PE32 image base: `0x10000`. No matching PDB is available locally.
Addresses below are preferred virtual addresses, not file offsets.

The local development server is playable with the patched client. The user
confirmed two-client killing, death, respawn, battery pickup and delivery.
Native-oracle checks cover the UDP codec, framing, compression and match setup.
Real captures verify populated late join, active state replay, automatic fault
recovery, reference timeout/fallback and replacement readmission. Stable local
validation uses separate Xvfb/Wine virtual desktops. Bounded clock correction also has a real fault-test result. Match
completion/results and complete session lifecycle remain unfinished. Later entries below supersede the historical intermediate findings.

The supplied resource archive contains both `flash_movies/lobby_menu.swf` and
`lobby_menu.swf.orig`; do not assume the entire archive is an untouched retail
distribution. The executable used by every oracle is pinned to the hash above.

## Version changes that affect the port

Local update notes live in `../vostok-versions/versions/*/update-note.wiki`.
Read the intermediate versions, not just 0.26:

| Version | Relevant changes in the local changelog |
|---|---|
| 0.22a | Network optimization/QoS, damage changes, signed resource integrity |
| 0.22d/e | Reliable delivery, input deviation and parallel-reality fixes |
| 0.22g | Hit and breath synchronization fixes |
| 0.24a | Battery charging stations and rules |
| 0.25a | Melee, clans, packet sending/synchronization changes, battery modes on all maps |
| 0.26a | Team deathmatch, equipment profiles/change while dead, stopping power, skills, physical chargers, player collisions |
| 0.26c/d/f | Synchronization fixes, TDM base respawns, tutorial |

0.26h/i are later than the selected executable and their fixes must not be
assumed present. Changelogs guide searches; machine code establishes formats.

## Why the 0.21d server cannot be copied directly

The other worker's 0.21d investigation identifies a deterministic input-relay
model with local combat simulation. Its capture includes working combat,
50 ms inputs, 100 ms state CRCs and early snapshot transfers. The modified
0.21d client uploads a snapshot when ready and uses packet `0x47` for fragmented
snapshot uploads; retail used that ID for a leave request. This extension is
part of the patched client/server contract, not the retail protocol.

The 0.26 match dispatcher at `0x27a300` handles server IDs `0xe3..0xf6`.
The client IDs are `0xd8..0xe1`, with `0xe2` unused in the length table.
The transport changed from 16-bit sequence fields and a 64-bit acknowledgement
mask to 8-bit sequence fields and a 128-bit mask container (127 transmitted
positions including the implicit newest ack). Application timestamps are also
more compact. Copying the old packet layout would fail before world setup.

## Identified functions

| VA | Identity / evidence |
|---|---|
| `0x27a300` | Match message dispatcher, 20-entry table at `0x27a738` |
| `0x27b830` | Server E3 handler, reads two u16 fields and requests D9 response |
| `0x27b880` | `process_static_match_info`, exact diagnostic signature |
| `0x1f0e70` | Match-options deserialization called by static-info handler |
| `0x1f1070` | Per-player options deserialization, called 20 times by the above |
| `0x27b570` | E5 clock exchange handler |
| `0x27b770` | E6 timing handler |
| `0x27bff0` | E8 handler, compressed world-state path |
| `0x27c280` | EB/EC individual player input handler |
| `0x27c340` | ED/EE batched player input handler |
| `0x318400` | Individual player input deserializer |
| `0x3184a0` | Player input serializer, diagnostic source `player_input.cpp` |
| `0x318690` | Two-byte local time reader (tick byte plus remainder) |
| `0x279670` | Message length getter, jump table at `0x2799e0` |
| `0x279a60` | Client message delivery metadata |
| `0x279b10` | Server message delivery metadata |
| `0x3fa0a0` | UDP header parser, executed by the local oracle |
| `0x3fa240` | `try_parse_single_message`, exact diagnostic signature |
| `0x3fb390` | Header writer |
| `0x3ff580` | Acknowledgement control-byte packer |

## UDP envelope

First three bytes: sending sequence, acknowledged sequence, first ack control
byte. The newest acknowledgement is implicit. For a control byte with its high
bit set, its low seven bits encode history and the next control byte comes from
the end of the datagram, walking backward. The final control byte has six ack
bits and a low flag: **0 = single message; 1 = multiple messages**. The bytes
between the three-byte prefix and reversed ack tail contain application framing.
Maximum datagram size is 512 bytes.

The Rust implementation is `vostok::network_packet::udp_026::Header`; it accepts
valid retail encodings and rejects excess history bits instead of silently
discarding them as the retail parser does.

## Message framing recovered from code

Fixed payload sizes, excluding message ID and any unique/order byte:

| IDs | Payload bytes |
|---|---|
| D8, DF | 5 |
| D9, E3, E6, F0 | 4 |
| DA, E0, E1 | 0 |
| DB | 6 |
| DC | 9 |
| DD, EB | 10 |
| DE, E7, E9, EA, EF, F2, F4 | 2 |
| E5 | 7 |
| EC | 11 |
| F1, F5 | 1 |
| F3 | 3 |

E4, E8 and F6 have variable payloads. ED/EE derive their length from a timestamp,
the negotiated player bitmask width and eight bytes per set player bit. They
are batched input messages, not state corrections. E4..E8 and F6 carry an extra
unique-ID byte according to delivery metadata; other listed messages do not.

For multi-message datagrams, variable payloads have a one-byte length, or FF
followed by a little-endian u16 length when at least 255 bytes. Fixed payloads
have no length prefix. A single variable message consumes the remaining payload.
FA..FE are low-level IDs; the parser requires no trailing payload for these.
**Do not send FE:** the actual low-level dispatcher at `0x3fdcf0` has only four
entries, FA..FD, despite the framing parser accepting FE. FA requests disconnect,
FB acknowledges it, FC is a heartbeat callback, and FD closes the connection.
FF introduces a fragment: actual message ID, optional unique/order byte,
fragment index, and on fragment zero the fragment count. These framing facts
are implemented in `survarium::protocol_026`. Its tests compare 77 frames with
the original machine-code parser, including every supported application ID,
both single/bundle modes, unique IDs, and first/subsequent fragments. Live-session
validation and inbound snapshot reassembly remain outstanding.

## Compression and match setup

The E4 payload starts with the local player's u8 roster index, followed by a
compressed match-options stream. `0x1f0e70` deserializes all 20 player slots,
then map ID (u8), player count (u8), match ID (u32), match level (u16), 28 floats
and 20 squad bytes. The float array is inferred to extend 0.21d's 24-element
event-score array; individual meanings still need confirmation.

Compression is **raw LZMA2**, not the PPMd compressor identified in the older
PDB. The 0.26 network-client constructor selects dictionary size 32768, lc=4,
lp=0, pb=2 and preset 9. There is no container or property byte in the payload;
the original decoder at `0x3ee810` receives dictionary property 6 out of band.
`retail_lzma_oracle.py` executes that decoder against five streams, including
65,536 expanded bytes. Rust's encoder reproduces the verified fixture bytes.

Each player reader at `0x1f1070` reads a team byte, two length-prefixed strings,
a u32 field and profile/inventory data at `0x1f1120`. The latter includes
profile and inventory counts, a profile field byte, a u32 field, a profile name,
a 23-bit equipment-slot mask, pairs of u16 values per present slot, and a
128-bit mask selecting up to 68 float modifiers. Inventory elements dispatch
through `0x1f1350` according to dictionary item type. Non-stackable items have
three u32 fields; stackable items have one. Both then carry counted switch
and attribute vectors. Field names without established semantics remain
explicitly generic in the writer.

`retail_options_oracle.py` runs the original reader and its original dictionary
lookup with two controlled dictionary entries. Its 436-byte fixture includes
a populated player, the other 19 padded slots, weapon and ammunition, slots
7/8, modifiers on both sides of the 64-bit boundary, and both inventory extension
types. The oracle checks the resulting C++ object fields and exact consumed
length. The Rust writer reproduces this fixture. This establishes the wire
layout; it does not establish that every test loadout value is gameplay-correct.

Local extracted configuration evidence is under `target/026g/game-configs/`:
the selected archive's static dictionary and 79 game-mode definitions, plus
startup.cfg. `binary-config-cli print-binary-config` successfully reads the
dictionary. Its parsed output and full resource index are under
`target/026g/evidence/`. Use these build-specific item/map IDs for setup.

## Development endpoint and remaining gates

`cargo run -p match-server-026 -- --bind 127.0.0.1:2236 --players 2 --map 61`
starts one fixed-roster match endpoint. Map 61 is `level_01_day_2.options` in
this build. The loadout uses dictionary IDs 3 (AK-74M) and 217 (5.45x39 7N10),
paired by this build's `compatibility_47`. ID 7 is incompatible with this rifle
and produced zero usable ammunition. The corrected loadout spawns with 30/90.

Implemented sequence: D8 -> E3 ports, D9 -> compressed E4 setup, all configured
peers' DA notifications -> E5 initial clock and E9 membership events. DC/DD
inputs become EB/EC on other ready peers. Each connection tracks its own sequence
history, pending frame transmissions and acknowledgement generations. E3/E4
retry at 500 ms; E9..EC retry at 50 ms and expire at 250 ms, matching the timing
fields at `0x279b10`. Initial E5 is deliberately retried until acknowledged,
an SRP policy rather than a claim about the original server. FC supplies idle
heartbeats and prompt acknowledgements. FA receives FB before removal.

`smoke_server_026.py` launches the actual server on an ephemeral loopback port,
connects two synthetic UDP peers, decompresses both 480-byte setup streams,
withholds acknowledgements to force retries, acknowledges the original E4
transmission, verifies input relay/retry, and checks disconnect. Results are
recorded locally in `target/026g/evidence/server-smoke.json`. These peers do not
run the game engine. The native-oracle fixtures cover 416 header and 77 frame cases,
rerun after the shared harness mapping changes and matching existing fixtures.

Real-client integration on 2026-10-11: the separately patched 0.26g0 executable
completed D8/E3/D9, decoded the E4 setup, loaded map 61, and sent DA. The default
376 MiB global multithreaded arena exhausted during map loading;
`-mt_allocator=768` allowed it to finish. The client reported collision-world
checksum 696574. E9 at time zero was rejected by `game_world_core::enter_match`
(`0x2d1470`) because the event time must be strictly greater than the last resync.
Without snapshots, the endpoint sends E9 at tick 1 after E5 establishes zero.
See `client/026g/README.md` for startup patches and the development connection
hook; source executables are never modified in place.

### Initial snapshot extension and live spawn

The optional client/server `--snapshots` mode introduces E2, an unused retail
application ID. Stock `Direction::Client` still rejects it; parsing requires
`Direction::ClientSnapshots`. Body: `u32 time, u16 offset, u16 total, <=480 bytes`.
Offsets are multiples of 480. Reassembly accepts reordering and exact duplicates,
rejects conflicts, and caps serialized bytes at 32764 (leaving four bytes for
time in the retail 32768-byte dynamic-state buffer).

The client hook at `0x27ae9a` selects the newest history item, finds the active
player mask at its time, and invokes the original serializer at `0x324be0`.
It uses the original message allocator and sender. Wrappers at `0x279670` and
`0x279a60` define E2 length/delivery metadata while preserving other IDs.
The delivery flags must be `0x1f` (variable body, no unique/order ID), not `0x9f`:
the latter omitted the body length when bundling an upload with DA.

On 2026-10-11 a real client uploaded six fragments totaling 2485 bytes at 50 ms,
with an empty active-player mask. The server prepended the timestamp, compressed
the state with raw LZMA2 and sent E8. Decompressing the recorded E8 exactly
reproduces the upload plus time. The client logged its first synchronization,
started the match, and spawned in first person. A subsequent run verified the
clock-response/state-acknowledgement barrier and compatible 30/90 ammunition.
The earlier live capture contains 834 state-hash messages and movement/stop
inputs. Evidence is under `target/026g/evidence/`, including
`live-bootstrap-validation.json`, `snapshot-bootstrap3-packets.tsv`,
`solo-ammo-packets.tsv`, and screenshots. A mouse-click attempt did not establish
firing: compositor focus was elsewhere, so shooting is still unverified.

Bootstrap selects roster slot zero's initial empty state after every peer has
uploaded and reported ready. E5/DB precedes E8; every E8 fragment must be
acknowledged before E9 is scheduled 300 ms ahead on the 50 ms grid. That lead is
SRP policy, not recovered server behavior. `--packet-log path` records datagram
time, direction, peer and hex bytes for inspection.

A later bounded two-client run used separate Wine prefixes. Both clients
uploaded 2530-byte initial states, accepted the shared E8, and logged match
start at game time 20500. However, peer zero's captured window remained at
login and it sent no DF hashes, while peer one sent hashes normally. Peer zero
was on another compositor workspace at startup; whether presentation/focus
caused the incomplete transition is unproven. The brief focus experiment ran
after that client's timeout. Do not count this as multiplayer acceptance.
Preserved evidence: `two-clients-packets.tsv`, `two-client-peer1-game.log`,
`two-client-peer2-game.log`, and `two-client-first-window.png`. Both bounded
clients exited; the test endpoints were stopped without touching the separate
0.21 worker's server. All 17 focused Rust tests pass, as does the synthetic
two-peer smoke test.

The next two-client run (`two-repeat-packets.tsv`, `two-repeat-peer1-game.log`,
`two-repeat-peer2-game.log`) entered gameplay on both clients. The user manually
walked to the other character, shot them, and confirmed a kill, death on the
other client, and respawn. Early shots did not kill; spawn protection is the
user's hypothesis, not yet proven. The two players are assigned teams 0 and 1.
Both clients uploaded 2,530-byte initial states. Seven shared historical ticks
(780, 820, 1298, 1332, 2360, 2435, 3016) had identical CRCs. Expand the eight-bit
ticks against the match's wall-clock epoch: consecutive-message unwrapping is
invalid across the long gaps in this capture and falsely reports divergence.
The logs show background frame stalls up to 51 seconds, so this is sparse
consistency evidence, not a sustained synchronization or recovery test.
The clients exited after their three-minute test timeout. The reproducible
capture inspector uses the production codecs:

```sh
cargo run -p match-server-026 --example inspect_capture -- \
  target/026g/evidence/two-repeat-packets.tsv
```

Its saved output is `two-repeat-validation.txt`: 10,512 decoded datagrams,
1,606 hash reports and 925 input messages. Clock expansion assumes reports
arrive within 6.4 seconds of their historical state time.

Disconnect cleanup now schedules native EA departure events for the remaining
players. The final departure clears the match epoch, state and hash history,
allowing a fresh cohort. Losing a peer during the initial state barrier closes
the incomplete cohort instead of leaving it stuck. Timeout uses the same cleanup
path. All 18 focused tests pass, and the UDP smoke test confirms departure
delivery and admission after both peers leave. Actual in-game EA removal is
not yet verified with a real client.

Historical snapshot requests now work with the optional server `--checkpoints`
flag and the updated `--snapshots` client. F7 is an SRP extension carrying a
four-byte exact game timestamp; E2 replies retain the existing upload format.
The dispatch hook at `0x27a300` searches retained state items backwards using
`+0xc0ba8`, compares their `+0xc0bb0` timestamps, and invokes the same serializer
as startup. It consumes unavailable requests without substituting another time.
The native range checks precede getter callbacks, so the builder extends the
match getter's inbound range at `0x27a153` and outbound range at `0x27a15b`.
F7 length and delivery wrappers preserve every stock opcode. In particular,
F7 is fixed-size (`0x9f` delivery flags), while E2 remains variable (`0x1f`).

The server selects the lowest active roster slot, requests no more than once
per five seconds, and expires each request after two seconds. It only assembles
the selected peer's requested timestamp and verifies CRC32 of the complete
serialized body against its historical DF report. Stale fragments cannot replace
the current request. This is checkpoint collection, not yet state restoration.
The policy is new SRP behavior; no claim is made that it reproduces the deployed
community server's selection or timing policy.

Live evidence `checkpoint2-packets.tsv`, `checkpoint2-game.log`, and
`checkpoint2-validation.txt` records eight verified active-player snapshots at
1500, 64300, 69400, 74400, 79450, 89450, 94500 and 104700 ms. They contain
3318–3382 bytes and active mask 1. Every completed request matches its reported
CRC. Two other requests expired without a reset loop; the client logged a
58-second background-frame gap. `checkpoint-packets.tsv` preserves the first,
rejected attempt before the opcode-range patch. The canonical client executable
is byte-identical to the successfully tested `survarium-srp-checkpoint2.exe`.

Input-history work must preserve the native timestamp encoding. DD/EC's two
timestamp bytes are **not a little-endian u16**: `0x318620` writes the low eight
bits of `time / 50`, then `time % 50`. `0x318690` expands the first byte against
the reference tick with `0x20ff90`, multiplies by 50, and adds the second byte.
DC/EB contain only the low tick byte. The current relay preserves these bytes
unchanged. E8 calls `0x2d0b70` with mode 1; only mode 0 enters its explicit input
history reset branch. Active mode-1 restoration plus replay has now been
accepted by real clients, as detailed below.

The referenced 0.21 plan also requires late join, recovery through a deliberate
synchronization fault, unique local sessions, and membership/lifecycle behavior.
Those remain part of the 0.26 target; the successful combat test alone does not
complete it. Outstanding: intermittent desktop startup/background stalls,
late join, ongoing clock coordination, live verification of membership removal,
and broader lifecycle support. Automatic recovery through a deliberate relay
fault now passes the two-client check described below.
The current endpoint rejects late joins and generic inbound fragments, records
CRC observations and optionally validates checkpoints, and uses development
sessions without authentication. Keep it
on loopback until those integration gates are handled.

Explicit restoration is available with `--checkpoints --restore-once-after-ms
25000`. This diagnostic restores all peers once from a verified checkpoint at
or after the requested game time. It advances each peer's E8 resync sequence,
waits for every state fragment to be acknowledged, then replays accepted inputs
after that state. History retains six seconds, replaces revisions at the same
player/time key, and refuses incomplete history. Transfers expire after two
seconds. Roster changes are excluded until membership replay is implemented.
This is an explicit restoration test, not automatic disagreement recovery.

The solo run logged a full resync at 93900 ms and continued producing verified
checkpoints. The two-client run logged `FULL RESYNC` at 31950 ms on both clients,
using a 4282-byte checkpoint with CRC `5914fc36`. The server replayed four later
inputs to slot 0 and three to slot 1 after their respective acknowledgements.
Both screenshots show gameplay after restoration. The final capture contains
10,228 decoded datagrams, 1,350 hash reports and 808 input messages. Its one
shared historical tick, 1560 (78000 ms), matches CRC `844be018`; sparse overlap
does not establish sustained convergence. Twelve requested checkpoints passed
CRC verification. Evidence: `restore-two-packets.tsv`,
`restore-two-validation.txt`, `restore-two-peer1-game.log`,
`restore-two-peer2-game.log`, and `restore-two-a.png` / `restore-two-b.png` under
`target/026g/evidence/`.

During this run the user confirmed that battery pickup, killing, and putting
batteries into the base work. The earlier run separately confirmed death on
the other client and respawn. These are manual gameplay confirmations; no
deliberate divergence or late-join test has passed yet.

The two-client run used an experimental binary that bypasses the focus-related
auto-minimize branch at `0x3cf8a8`. It did not eliminate background stalls and
has not been promoted into the canonical patch builder. The solo restoration
used the canonical client.

The direct-match hook now derives a nonzero per-launch development session from
the existing QueryPerformanceCounter import at `0x870158`. It writes that same
value into the D9 session field and passes it to `connect_to_match` for D8.
Do not call `0x1b7b0` as a plain QPC wrapper: that retail helper needs an ESI
clock object. The server rejects zero and active collisions without reserving a
slot, while accepting repeat handshakes from the same endpoint. This is local
session discrimination, not authentication. In the live session test, clients
were admitted with IDs `09a32961` and `0bcafbfd` and both completed D9 setup.
All 24 focused Rust tests and the synthetic two-peer UDP lifecycle check pass.

The denser follow-up (`-hash_check_interval_in_ms=50`,
`session-two-packets.tsv`) exposed a restoration regression hidden by the earlier
sparse overlap. Both clients accepted state at 21800 ms. There were 399 matching
shared ticks, followed by 586 mismatches beginning at tick 449 (22450 ms).
Both native logs report moving their own input from 21850 to 22400 ms just
after resync. The first implementation replayed inputs to their originator as
well as the other client. Replay now follows the normal relay recipient rule
and excludes the originator, whose local history is retained by mode-1 E8.
This is a candidate correction under live validation, not yet proof of recovery.

The bounded follow-up `replay-remote-packets.tsv` could not exercise the fix:
slot 0 emitted only two hashes, slot 1 emitted 467, and neither sent inputs.
The reference produced one checkpoint at 3650 ms, below the 12000 ms restoration
threshold. No active full resync occurred. Both clients reached the initial
state barrier, but background stalls continued despite side-by-side placement
and brief activation. Preserve `replay-remote-peer1-game.log`,
`replay-remote-peer2-game.log`, and `replay-remote-validation.txt` as an
inconclusive run. The replay-recipient regression test and UDP lifecycle smoke
test pass. All bounded clients exited and their 0.26 test servers were stopped.

Reliable unattended validation uses one Xvfb display per client, with Wine
`explorer /desktop=srp026,1280x720` between Xvfb and the game. Bare Xvfb fails
before game initialization: Wine exception logging identifies an integer divide
by zero at DXGI RVA `0x147b63` (`__divdi3`) during monitor timing setup. DXVK
2.7.1's `DxgiOutput::CacheMonitorData` computes refresh timing from the current
display mode. Neither software Vulkan, `-all_resolutions`, nor
`dxgi.forceRefreshRate=60` fixed this early failure. Wine's virtual desktop did;
no game rendering patch was required. Upstream source for the inspected path:
https://github.com/doitsujin/dxvk/blob/v2.7.1/src/dxgi/dxgi_output.cpp#L589

`xvfb-restore-packets.tsv` records 1621 matching shared ticks with zero
mismatches after the recipient correction, including an explicit restore at
15150 ms. This restore had no queued inputs. A movement repeat also stayed
consistent, but its restore was inside the 20-second opening countdown, before
movement inputs were emitted. Those runs establish the stable test environment;
the subsequent post-countdown run exercises the replay correction directly.

`active-replay2-packets.tsv` contains 6252 decoded datagrams, 2607 hashes and
319 input messages. Both clients accepted a 4593-byte state at 25200 ms, CRC
`5ae21ef4`, while movement keys alternated throughout the match. Each then
received three later inputs from the other player. All 1071 shared historical
ticks match, including 634 after restoration, through 64550 ms. Neither client
logged the previous own-input retiming warning. This verifies explicit active
restoration plus remote-input replay for this two-player case. It does not yet
verify deliberate divergence recovery or automatic disagreement handling.
Preserved: `active-replay2-validation.txt`, `active-replay2-peer1-game.log`,
`active-replay2-peer2-game.log`, and the packet capture under `target/026g/evidence`.
The reusable `drive_inputs_026.py` helper reproduces the movement sequence on
explicitly selected test displays; use a restoration threshold after 20500 ms.

The local 0.26g0 map dictionary contains rain variants for levels 01–07. In
particular, `level_01_rain_2.options` is map ID 65; the tested day variant is 61.
Their config files are extracted from this build's `resources.db`. Rain-map
loading has not yet been verified in game.

Automatic recovery is opt-in with `--recover --checkpoints --snapshots`.
`recovery::Monitor` expands reports onto the match clock and compares only
equal historical timestamps after a one-second settling interval. At least
three distinct mismatches spanning 200 ms are required. Duplicate messages do
not add votes; any revised report withdraws overlapping votes, including votes
already evaluated. Changed accepted inputs invalidate affected hash reports,
comparison streaks and cached/requested snapshots. Membership changes clear
the comparison epoch and reference state. Lowest active slot remains the
explicit trusted SRP reference policy, not independent physics validation.

Recovery requests a fresh reference checkpoint at most once per second, sends
E8 only to disagreeing peers, waits for all state-fragment acknowledgements and
replays only remote inputs. Attempts are separated by ten seconds, and each
transfer retains its two-second deadline. Old comparison evidence is cleared
when a new state is sent. These bounds also apply if a transfer fails; a later
fresh disagreement may trigger another attempt. The test-only
`--drop-relay SLOT:FROM_MS:TO_MS` withholds live input relay while retaining
accepted history. No deliberate fault is enabled by default.

Live evidence `auto-recovery-packets.tsv` / `auto-recovery-validation.txt`:
6868 decoded datagrams, 2863 hash reports, 215 input messages. The fault
withheld four relay messages to slot 1 during 23300..24100 ms. Twelve shared
historical ticks disagree between 23350 and 24100 ms. The server detected
sustained disagreement, acquired a verified 4718-byte checkpoint at 24050 ms
(CRC `2ecf4cbd`), restored only slot 1 with sequence 2, then replayed four later
remote inputs. Only that client's log records `FULL RESYNC`. After the last
mismatch, 882 shared ticks match through 72650 ms; there was one recovery and
no repeated-reset loop. Total shared comparisons: 1245 matching, 12 mismatching.
The healthy reference stayed on sequence 1. Both game logs and the input-driver
log are preserved under `target/026g/evidence/auto-recovery-*`.

Use `-hash_check_interval_in_ms=50` on each client for comparison coverage:
the default 100 ms setting can select disjoint odd/even historical ticks.
All 28 focused Rust tests pass, including cooldown, targeted restoration,
fault-history retention, late input invalidation and post-comparison revision
withdrawal. The synthetic UDP lifecycle smoke test passes. The late-revision
guard and manual/automatic-trigger coexistence adjustment were added after the
live fault run and checked by the focused tests.


Late join now separates roster capacity (`--players`) from initial quorum
(`--start-players`, default capacity). A partial quorum requires snapshot and
checkpoint support. Only admitted initial players receive bootstrap membership;
loading peers are excluded from live relay, accepted input and donor selection.
The shared match clock continues unchanged for each later arrival.

A late join selects a CRC-verified reference checkpoint at most 1000 ms old,
with the expected historical active mask and without its own slot. It receives
E5/current shared game time, then E8 only after DB. All E8 fragments must be
ACKed before replay. The bounded six-second journal tracks arrival cursors,
collapses same-slot/time input revisions, and includes E9/EA membership events.
Each replay batch must be ACKed before collecting the next batch; replay
messages cannot simply expire at the ordinary 250 ms live-delivery deadline.
Only an empty, acknowledged backlog permits E9 entry 300 ms ahead and live
broadcast membership. One join activates per poll so another pending join must
observe its entry. A changed input at/before the selected baseline, incomplete
history, excessive queue or five-second transfer timeout fails only that join.
Unactivated departure does not synthesize a world leave event. Active recovery
still waits for a checkpoint after all scheduled membership changes.

Real evidence `late-join-packets.tsv` / `late-join-validation.txt`: 9737 decoded
datagrams, 4240 hash reports, 561 input messages. Slot 0 (port 46547) bootstrapped
alone from time 50; slot 1 (port 38585) loaded later. Reference checkpoint 41000 was
3635 bytes, active mask 1, CRC `4e22b2b4`. The join clock was 41621; four input
changes were replayed and acknowledged before entry 42150. The original player
moved throughout the join, and the joining player later emitted 122 inputs.
All 1443 shared historical ticks match through 129250 ms. Both native logs show
only their first synchronization (0.050 and 41.000); no active FULL RESYNC or
automatic recovery occurred. Screenshot `late-join-peer2.png` shows the local
player with 30/90 ammo and the already-running 14:15 match timer. Both bounded
clients exited, and their server/Xvfb displays were stopped after saving logs.

33 focused Rust tests pass, including reduced-quorum bootstrap, lost state
fragment retry, state/replay ACK barriers, delayed input revisions, departure
replay, stalled/invalidated join isolation and input admission bounds. The
input time admission guard was tightened after the live run: invalid subticks,
pre-activation inputs and timestamps outside retained/future bounds are rejected
before relay, ensuring the accepted journal covers every forwarded change.
This guard has a targeted regression test; it was not part of the live binary.

Remaining end-to-end work includes reference departure/fallback and reconnect
with real clients, ongoing clock coordination, match results and lifecycle.
The successful two-client late join does not complete the full server objective.

The rebuilt executable also passes the UDP startup/relay/retry/departure/fresh-match
smoke test (`late-join-server-smoke.json`).


Reference departure and replacement readmission passed with the final late-join
input admission guard enabled. `reference-packets.tsv` contains 18692 decoded
datagrams, 8510 hash reports and 394 inputs across three connections. Slot 0
(port 59134) bootstrapped alone; slot 1 (54449) joined at 13300 ms from a
12300 ms checkpoint. The original process exited at its bounded lifetime; no
graceful FA was captured. After the 120-second inactivity timeout, the survivor
received EA for slot 0 at 195450 ms. Its verified checkpoint at 199650 has
mask 2, demonstrating that departure changed the actual native world state.

Slot 1 became the reference and supplied the replacement baseline: 211250 ms,
3379 bytes, mask 2, CRC `45c581bf`. The restarted client used a new session and
endpoint (55302), restored that state and entered slot 0 at 212250 ms. The
lowest active slot policy subsequently selected this replacement as reference;
its verified snapshots contain mask 3. Both remaining clients emitted movement
inputs. Shared comparisons: 1148 matches for original/survivor through 74600 ms,
1156 for survivor/replacement through 278050 ms, zero mismatches in either pair.
All three native logs contain only their first synchronization. The harness
saved logs and stopped its server and virtual displays after the clients exited.

`inspect_capture` now reports decoded membership schedules and pairwise hash
coverage, so a replacement connection cannot obscure which peers were compared.
The capture remains one match generation; the tool rejects multiple E5 clock
baselines on one endpoint and must not be used indiscriminately across restarts.

Recovered ongoing clock exchange: E6 handler 0x27b770 reads two u16 fields:
server timestamp and advertised RTT. It records local receipt time and asks
0x27cbf0 to send DB on a later flush. DB contains advertised RTT, server timestamp
plus local processing elapsed time, and current client game time (all u16).
E7 handler 0x27b7f0 passes a signed i16 correction to 0x1ee9e0. That routine
changes the clock's correction rate with the sign of the adjustment and a
bounded duration; it does not clear the world. E5 at 0x27b570 does clear it and
therefore remains restricted to initial/late-join setup.

The optional `--clock-sync` implementation probes once every two seconds and
never retransmits an old E6 timestamp. It subtracts client processing from RTT,
estimates offset using half the measured RTT, and uses the median of three
same-sign samples with a 10 ms deadband. Each E7 adjustment is capped at 100 ms.
Expired, unrelated or impossible replies are rejected, duplicate replies cannot
vote twice, and a missed exchange clears the streak. Corrections use the native
gradual timer path. These bounds and symmetric-delay assumption are SRP policy,
not a claim about the archived service's clock controller.

The first live clock run (`clock-*`) exposed a measurement bug: the executable
sampled receive time before blocking in recv_from, making some computed RTTs
negative by up to the socket timeout. Its injected +250 ms slew only partially
converged; 1660 shared hashes matched but that is not clock-recovery acceptance.
Receipt timestamps now come after recv_from. The controller tolerates only a
2 ms timer quantization margin; the corrected real-client repeat is recorded below.


Corrected ongoing clock acceptance: `clock2-packets.tsv` contains 9055 decoded
datagrams, 3889 hashes and 490 inputs. Slot 0 is endpoint 39498; the faulted
slot 1 is 50417. Both clients used their unchanged canonical snapshot-capable
executable, separate Wine/Xvfb desktops, and 50 ms hash sampling. Server flags:
`--players 2 --snapshots --checkpoints --recover --clock-sync
--clock-fault 1:25000:250`. Both clients moved during the fault and correction.

The native E7 +250 ms command was sent at 25000; the measured error reached
-226 ms before feedback interrupted the outstanding positive slew. E7
corrections were -100 at 29589, -100 at 35644, and -26 at 41627 ms. Retried
transport frames keep the same unique message ID; they are not extra applied
adjustments. Thirty later DB samples from 43500 through 101773 ms are within
[-1,+1] ms of the measured server target. `clock2-timing-summary.json` records
these ranges. All 1688 shared historical ticks match through 101200 ms; no hash
mismatch, active FULL RESYNC or recovery loop occurred. Both native logs contain
only their first synchronization at 50 ms. The harness completed, saved logs,
and stopped its clients/server/displays; remaining Xvfb processes belong to
other work and were left untouched.

37 focused Rust tests pass. New clock tests cover u16 timestamp wrap, client
processing subtraction, correction sign/cap, expired/unrelated/duplicate
responses, timer quantization, missed-exchange streak invalidation, and native
wire scheduling without E5/E8 resets. Packet inspection now includes E6/E7/DB
fields alongside pairwise world-hash and membership evidence.

Remaining full-objective work: match completion/results, clean session exit and
new match lifecycle, plus the final old-server compatibility/build audit and
reproducible delivery. Local timeout departure, replacement readmission and
ongoing bounded clock correction now have direct runtime evidence.


Requested School rain test: local English localization contains
`st_level_02_name\0School\0`; the map dictionary assigns 71 to
`level_02_rain_2.options`. The decoded config selects `level_02/rain_2`, mode 2,
weather ID 2, 900-second match, 20-second countdown and eight-second respawn.
The original localization bytes were read from the uncompressed resource-index
entry (offset 101823670, size 157492); decoded options are saved as
`target/026g/evidence/school-rain-options.txt`.

Two real clients ran with `--map 71 --players 2 --snapshots --checkpoints
--recover --clock-sync`, the canonical client and separate virtual desktops.
Both uploaded 2377-byte empty states at 50 ms, entered and emitted 360 total input
messages. The final capture decodes 9069 datagrams and 3984 hashes; all 1797 shared
historical ticks match from 3500 through 102950 ms. There were no mismatches or
active full resyncs. Both clients spawned with 30/90 ammunition. Screenshots
show the School spawn interiors and a partially open roof; they do not by
themselves prove visible falling-rain particles. An additional outdoor-view
attempt overlapped the configured client timeout and produced no screenshot.
The earlier scheduled screenshots, full native logs and packet capture were
saved successfully; both 115-second clients exited and the harness cleaned up
its server/displays. This verifies loading, rendering and synchronized movement
on the rain variant, not a new School-specific combat or battery-deposit test.
Evidence: `target/026g/evidence/school-rain-*`.

The user subsequently confirmed that the visible rain School preview works.

## Historical state boundaries and finish-path investigation

`servers/match-server-026/src/state.rs` now provides a bounded, read-only
historical-state layout reader. It checks the configured roster mask, skips
each active player's length-prefixed state and optional compressed animation,
then reads six u16-length-prefixed blocks: bullets, statistics, objects,
physics, rules and effects. Trailing and truncated bytes are rejected.
This differs from the four world blocks in 0.21d. It does not validate engine
semantics, animation-tree internals or invent missing state.

Native evidence:

| VA | Role |
|---|---|
| `0x324be0` / `0x324d80` | Historical state writer / reader |
| `0x33fde0` / `0x33fee0` | Player state plus animation writer / reader |
| `0x3a9900` | Animation envelope decode and consumed-byte advancement |
| `0x3a9580` / `0x3a9720` | Compressed time / float decoding |
| `0x324110` | Rules history block writer |
| `0x317f30` / `0x317fd0` | Time-limit rule writer / reader |
| `0x318360` | Time-limit rule completion predicate |
| `0x27c690` | Own-slot EA closes the current match with reason 3 |
| `0x27a790` | Close-match dispatcher; reason 3 calls world finish then results UI |
| `0x1f96f0` / `0x29aaf0` | World finish path / `show_match_statistic` UI invocation |

The animation format remains MSB-first: u16 tree bit count and tree bits,
10-bit time count, optional time dictionary and deltas, then float dictionary
flag, 10-bit count and direct/dictionary float data, rounded to a byte boundary.
The native time and float dictionary index width is max(1, bit_length(count)).
`retail_animation_oracle.py` executes the original envelope decoder and both
native dictionary readers, with fixed-capacity vectors initialized as in the
native constructor. It does not substitute a second implementation of those
readers. Generated ELF files retain the retail code only in ignored `target`.

All 157 reassembled snapshots from School rain, clock correction, automatic
recovery, active replay, late join and reference replacement ended exactly at
their native-derived boundaries. They contain 253 distinct animation envelopes.
The Rust reader matches those 253 native consumed lengths. The empty School
fixture is 2377 bytes; the populated fixture at 98750 ms is 4099 bytes with CRC
`943e6614`, matching the requested historical hash. Its player animation ranges
are 682..854 and 1532..1704; its rules block is 2296..4077. Tests reject every
truncated prefix of both complete fixtures. All 41 focused tests pass.
Evidence: `target/026g/evidence/animation-oracle.json`, `*-state-layout.txt`,
exported `*-states/`, and `target/026g/state-layout-tests.log`.

The time-limit rule serializes 13 bytes: state-start u32, current-time u32,
players-mask u32, state u8. State 1 means waiting, 2 countdown, 3 in progress.
Its native completion predicate subtracts state-start from the supplied current
time and compares against the wait limit in state 1 or match duration in state
3; state 2 does not complete. Constructor `0x317da0` multiplies `match_time` by
1000, **`wait_time` by 60000**, and `countdown_time` by 1000. Thus School's
`wait_time: 5` is a five-minute wait limit, not five seconds. The recovered
School rules prefix at 98750 ms contains start 20500, current 98750, mask 3,
state 3, consistent with the 20-second countdown after entry at 500 ms.

These findings do not yet implement finish scheduling, battery victory,
results population or the lobby transition for the direct-match client.
Lobby helper `0x2717e0` emits opcode 0x31 with a match identifier and a boolean;
the direct path still needs live verification of that finish/results path.
Client E1 is not established as a finish notification: its send site consults
global flag helper `0x1bbe0`, not the time-limit completion predicate.
The user's running preview and its executable were left unchanged.

## Forced-finish transport and first native UI test

The endpoint now has diagnostic `--finish-after-ms GAME_TIME`. It sends each
active client its own-slot EA only after that game timestamp is reached.
The terminal event overrides ordinary EA's 250 ms lifetime: it retries every
250 ms until acknowledged or the terminal generation expires after 30 seconds.
Transport ACK/disconnect processing remains active; inputs, new admission,
checkpoint acquisition, replay and clock updates stop. In-progress loading
joins are cancelled with FD. Disconnects during finishing do not emit remote
leave events; removing the final peer clears the generation and allows a fresh
cohort. There is no automatic rule-completion policy yet.

Two new tests cover dropped first deliveries, delayed retries, ACK suppression,
own-slot addressing, post-finish input/admission rejection, loading cancellation,
FA cleanup, fresh admission and bounded terminal lifetime even when clients keep
pinging. All 43 focused tests pass (`target/026g/finish-tests.log`).

An isolated real client used the canonical executable, the peer2 prefix, a
private Xvfb virtual desktop, map 71, one-player roster, port 2237 and a forced
finish at 30000 ms. The user preview on 2236 and the other worker's processes
were not modified. The server sent EA at game time 30005 ms (encoded tick maps
to 30000); the client completed FA/FB disconnect at capture wall time 40014 ms.
The capture contains 1289 datagrams, 574 hashes and seven assembled states;
all six requested checkpoints match their historical CRCs. A screenshot five
seconds after finish shows the School loading screen, **not a populated results
screen**. The client remained alive until its configured 65-second process
timeout. Therefore transport finish/cleanup has real evidence, but the direct
client's results transition is not accepted as working.

Evidence: `target/026g/evidence/finish-ui-packets.tsv`,
`finish-ui-validation.txt`, `finish-ui-peer1-game.log`, `finish-ui.png`, and
`target/026g/finish-ui-test.log`. The test cleaned up its own server/display.

Further UI tracing found network-client vtable `0x9ffb14`: slot +0x20 is
`0x372420`, which returns true unconditionally, so a failed lobby-readiness
check at that slot does not explain the loading screen. `0x2812e0` is native
`lobby_menu_logic::call`, dispatching the method-name table at `0x9c56c8`;
`show_match_statistic` is index 54 (callback storage +0x22c0).
Lobby response handler `0x2718c0` deserializes match statistics via `0x26e610`
and a player result via `0x26ece0`, invokes `show_match_statistic` again, then
calls `0x29ab20` to populate the UI. Recovering this data path and the missing
direct-client lobby state is the next step; these new addresses alone do not
prove results work.

## Timer policy and results-data investigation

`--finish-timed` now evaluates the native time-limit predicate against a recent,
CRC-verified checkpoint, requiring matching historical membership, checkpoint
time, and timer identity. It uses the pinned config's match seconds and waiting
minutes; it does not extrapolate from old state. The 84 native predicate vectors
cover states 0–3 and deadlines for three configs. A reproducible extractor reads
89 map dictionary entries, finds 77 available modes with leading rule 93, records
ten missing configs and two other modes, and reproduces the checked-in TSV
byte-for-byte. Map 115's short test configuration crashed during native loading;
the full-length School 71 test is the live timer verification instead.

A separate experimental executable at
`target/026g/client/Survarium/game/binaries/x86/survarium-results-diagnostic.exe`
replaces the call at `0x27a81a` with a wrapper that preserves ESI, calls the
original `0x29aaf0`, invokes `0x29eda0` with ECX=lobby and one dummy stack
argument (callee returns with `ret 4`), then invokes `0x2203a0` with EDX=lobby
and AL=0 to hide the loading screen. It resumes at `0x27a81f`. The canonical
client remains unchanged. Reproducible scratch sources and a byte manifest are
in `target/026g/results-diagnostic/`.

The isolated diagnostic used a cloned prefix, private display, port 2238, and
forced finish at 30000 ms. It completed FA/FB disconnect and displayed the
native lobby with the results window and a waiting spinner. This proves that
the direct UI transition can run, **not** that populated results work.
The capture has 1290 datagrams, 581 hashes, and seven complete states with six
verified requested checkpoints. Evidence: `target/026g/evidence/results-ui-*`
and `target/026g/results-ui-test.log`; the harness exited and cleaned up.

The bounded statistics reader follows native `shared_statistics::serialize`
at `0x2f5ac0`. Each static roster slot has three event masks for 28 events;
the byte/word index tables at `0x920588` and `0x9205e0` define value widths.
Intermediate state contains three sparse damage arrays, sparse hit times and
ten scalar bytes, followed by a u16 longest killstreak. Victory-item event data
has three sparse carried-distance arrays and ten scalar bytes per configured
item. The final 11 bytes are two u16 team scores, two u8 battery counts, a u8
winner enum, and a u32 active-in-match mask. The latter is distinct from current
membership and is zero in the observed unfinished matches; native winner is 3.

The reader consumes all 180 saved blocks from eight runs exactly, including
nonzero byte event 19 and word event 22. Two captured fixtures cover those widths;
School fixtures cover truncation and configured-count mismatches. All 48 focused
tests pass (`target/026g/statistics-all-tests.log`). The parser is read-only and
does not yet supply the results window or detect early battery victory.

The canonical client's full-length School test completed successfully: native
match start was 20500 ms, its deadline was 920500 ms, and the first verified
post-deadline checkpoint was 921100 ms (3188 bytes, CRC `0992e3b7`). The server
queued finish at 921664 ms, encoded EA at 921650 ms, and the client completed
FA/FB disconnect at capture wall time 932302 ms. There are 38547 datagrams,
18375 hashes, and 185 complete states (initial plus 184 verified requested
checkpoints). All 185 statistics blocks also pass bounded decoding, bringing
the statistics capture coverage to 365 blocks. The unchanged canonical client
still displays the School loading screen after finish; this is timer/transport
acceptance, not results UI acceptance. Evidence is saved under
`target/026g/evidence/timer-school-*` and `target/026g/timer-school-test.log`.
The synthetic UDP smoke test also passes startup retry, relay/retry, disconnect,
membership removal and fresh-match admission (`target/026g/timer-smoke.log`).

## Populated results UI probe and battery semantics

The native UI ABI is now exercised by the tracked
`native_results_probe_026.c` / `build_results_probe_026.py` diagnostic. Movie
pointer: `lobby+0x690 -> +0x108 -> +4`. `0x511700` creates a GFx object and
`0x511710` creates an array; both use ECX=movie. `0x511600` invokes a movie
method with `(path, result, arguments, count)` and returns with `ret 16`.
GFx Value is 16 bytes: object interface, type, eight-byte payload. The interface
vtable slots used here are +0x08 release, +0x14 set member, and +0x3c array push.
Objects retained by the movie are released correctly after invocation.

`root.victory_screen.setData` accepts the constructed object directly. In
addition to match metadata, scores and players, it needs `score_components`
and `statistics_money`, `statistics_reputation`, `statistics_rating`, and
`statistics_exp` objects. Omitting rating produced an ActionScript exception
at `VictoryScreen::updatePremiumState` line 579; the complete probe has no
TypeError/ReferenceError or native access violation. The visible loading overlay
was the lobby sync layer: `root.close_sync` removes it. `show_loading_wheels`
did not resolve it and is excluded from the final probe.

The `results-data4` native test displays the labeled diagnostic player row,
zero counters, and an unobstructed results window. A separate `results-close`
run clicked Close, but its subsequent screenshot still shows the window, so
return-to-lobby is **not** accepted. Both harnesses exited and cleaned up.
Evidence is in `target/026g/evidence/results-data4-*`, `results-close-*` and
their test logs. This is a UI binding test; it does not supply live match
statistics or grant rewards. Probe SHA256 is
`35af5c01af5d5744c7b5b6911099b7d730ed7b4581e5d6e002fc8efd2e14b4f7`.
The tracked probe builder reproduced that exact file, and the standard builder
still reproduced canonical SHA256 `45baf0a591cf6535a9f7afa073ae59551979d92904670a4e1adf70336c1004e9`.
The client builder's internal API now accepts an alternate assembly source and
explicit extra hooks, keeping the existing hash and byte preconditions.

Battery event handler `0x313a50` increments a team's u8 count for item event
action 0 and decrements it for action 1. It updates live team scores and winner
(0/1, or 2 for equal scores); collecting the configured number of items sets
completion time to event time +3000 ms. Further events are ignored once that
deadline is set. Predicate `0x314230` returns true at/after the deadline and
false for sentinel `0xffffffff`. The hash-gated native oracle captures 144
cases, including both sides of the deadline and the event freeze.

The handler's world-statistics pointer is the outer polymorphic object, whereas
the serializer reads its `shared_statistics` subobject at +8: native wrapper
`0x26db40` does `lea esi,[ecx+8]` before calling `0x2f5ac0`. Therefore event
writes at outer +0x31d4/+0x31d6/+0x31e4 are exactly the serialized scores at
subobject +0x31cc/+0x31ce/+0x31dc. They are **not** separate pending/final score
copies. The oracle verifies those writes; the existing bounded statistics
reader can supply live scores. The early-victory deadline itself is absent
from the recovered gather-rule serializer, so an automatic policy still needs
to preserve the native delay safely across checkpoint revisions/restoration.

## F8 checkpoint-derived results

The opt-in server/client `--results` path now carries actual checkpoint data to
the native results window. All active recipients are encoded before entering
the terminal phase. The checkpoint must be CRC-verified, no more than six
seconds old, match historical membership and pass the map timer's identity
checks. Retransmission lasts until ACK/disconnect, bounded by the existing
30-second terminal phase. Roster capacity 20 exercises four transport fragments.

F8 has no unique ID and a variable body, using the existing generic transport
fragmentation. Version 1 has a 24-byte header and one 80-byte row per static
roster slot. All multibyte values are little-endian:

| Offset | Header field |
|---|---|
| 0..3 | version=1, cutoff tick, local slot, mode=2 |
| 4 | u32 checkpoint cutoff in milliseconds |
| 8 | u32 match ID |
| 12 | u32 participant mask at/before cutoff |
| 16,18 | u16 team scores |
| 20..23 | winner (0/1/2), roster count, local team, zero |

| Offset | Player row field |
|---|---|
| 0 | u32 player key |
| 4,5 | team, zero |
| 6,8,10 | u16 rank, kills, deaths |
| 12 | i16 recomputed score |
| 14,15 | UTF-8 name byte length (0..63), zero |
| 16..79 | name, NUL terminator and padding |

Rank is zero: match level is not account rank. Participant identity follows the
fixed roster; the coordinator retains first-entry times beyond its replay
window, excluding entries scheduled after the cutoff and clearing them on
reset. The serialized statistics field named `m_active_in_match_players_mask`
is zero in live captures, so it cannot supply that list before native finish.

`retail_score_oracle.py` executes native `0x26dc30`. Its 172 vectors cover every
event separately, rounding boundaries and mixed weights/counters. Recompute
wraps each event's three-preset sum to u16, applies factors 0.01 to events
6/17/18 and 1 to the others, accumulates f32 and rounds with floor(total+0.5)
before conversion to i16. The Rust result builder matches every vector. The
server used all-one development placeholders at this stage; the later scoring
policy section below supersedes that configuration.

`client/026g/tools/results.c` bounds-checks the entire packet before closing the
world through the original own-slot EA handler and constructing GFx values.
The native results ABI is shared with the earlier probe. The actual C validator
is compiled as a host library for tests covering every truncated length for
rosters 1..20, trailing data and malformed masks, identities and names.
`inspect_capture` reassembles F8, detects conflicting fragments, reports rows
and optionally writes the wire body as `.f8` alongside checkpoint files.

Live `results4` evidence: cutoff 40700 ms, participant mask 1, Player1, rank 0,
kills/deaths 0/0, score 6. Captured shots and the configured weights explain that
score; this does not establish kill/deposit results or retail scoring weights.
Retail `0x1ed1e0` guards
menu activation on lobby connectivity, and `0x26cff0` guards mouse forwarding
on a profile object. Scoped result-path hooks address those gates. The activation
wrapper enters native `0x1ed222` with its normal ESI/EDI saved-register frame.
The mouse wrapper forwards to `0x26d028` only while native results-window flag
`lobby+0x313a` is set, otherwise preserving the original profile checks.

Tests through `live-results5` left the window visible. Instrumented runs then
proved that clicks reached Scaleform but used native coordinates 50,50 despite
an X pointer over Close. The test harness's absolute pointer warp did not update
the game's cursor. Relative XTest motion does: measured native coordinates are
screen coordinates +3,+3 in this Wine virtual desktop. `live-results9` closed
the window with measured native coordinates 650,585. The uninstrumented
`live-results10` repeated that success using relative motion to screen 647,582.
Its post-Close screenshot shows the lobby, and its native output contains no
TypeError, ReferenceError or native unhandled exception. The unauthenticated
profile still produces a lobby tutorial prompt; this is not an accepted
account/browser or same-process matchmaking flow.

The normal results client has SHA256
`7885469640284cfee41fbfd73c0a378603eb8c9737e2562d4e26a77763bf3dd7`.
The same `live-results10` server then admitted a second fresh client process
with a new session, acknowledged its native startup and collected populated
checkpoints. The saved `live-results10-second-match.png` shows the new School
match at 14:55 with 30/90 ammunition. This proves native server reuse after the
results/disconnect sequence; it does not prove lobby-driven rejoin in one
client process. Split this capture by peer before inspecting: the inspector's
hash comparison assumes one simultaneous match, whereas these peers belong
to sequential match generations.
Both generations completed: their split captures decode 1914 and 1919 datagrams
and ten complete statistics blocks each. F8 cutoffs are 40550 and 40650 ms.
The first contains seven shots and result score 7; the second, without firing,
contains no events and result score 0. This verifies that the fresh match did
not inherit the first match's statistics. Both native logs have no TypeError,
ReferenceError or unhandled native exception. The bounded harness exited and
cleaned up its private server/display; the user preview was left alone.

The 50 focused Rust tests and C validator tests pass. The builder without
`--results` still reproduces canonical SHA256
`45baf0a591cf6535a9f7afa073ae59551979d92904670a4e1adf70336c1004e9`.

## Conservative automatic battery completion

`battery.rs` and `--finish-objective` implement a coordinator policy using the
existing verified checkpoint path. An active timer state (3), matching timer
identity/membership, supported mode metadata, exactly the configured battery
count on the winning team, a smaller opposing count, and an agreeing native
winner field establish a candidate. Confirmation needs another consistent
checkpoint at least 3000 game milliseconds after the first observation.
Wall time or repeated polling of one checkpoint cannot complete it. Candidate
confirmation requests checkpoints at one-second intervals instead of five.

The deadline is intentionally conservative: the first observed winning state
can follow the actual deposit by a checkpoint interval. This reproduces the
native minimum delay without inventing an unserialized event timestamp.
Revised reference history, roster changes, restoration and match reset discard
the candidate. Backwards/revised checkpoint observations, a gap over six seconds,
stale/future state, lost objectives, invalid identity and a changed winner also
prevent carrying old evidence forward.

The threshold matches all 72 oracle vectors that start without a preexisting
native deadline. Tests exercise both winning teams and a coordinator matrix
including successful F8 results, duplicate/short observations, stale/future
state, invalid identity/membership, waiting state, missing data, history revision,
departure, reset and the disabled option. The coordinator fixtures deliberately
edit serialized timer/statistics fields; they do not establish that actual
deposits occurred. Real full-objective victory remains an acceptance gate.
The 53 focused Rust tests pass. With both automatic policies and results enabled,
an ordinary native School run remained active through 71 seconds with no false
finish. Its capture decodes 3089 datagrams, 1429 hashes and 16 complete statistics
blocks; team scores stayed 0:0 while firing counters changed. The native log has
no TypeError, ReferenceError or unhandled native exception. The bounded harness
exited and cleaned up (`battery-no-win-*`).

The tracked `build_battery_probe_026.py` / `native_battery_probe_026.c` exercise
positive completion with synthetic calls to the actual native deposit handler.
The real client uses derived-rule vtable `0xa06ab4`, not core vtable `0xa15b04`;
its event thunk `0x266830` jumps directly to `0x313a50`. The core rule vector is
at +0x18824/+0x18828 (confirmed by `0x23aa10` and `0x2d2570`). An initial probe
called the handler during F7 processing, logged the call, but later checkpoints
remained 0:0. That out-of-tick change did not persist into simulation history.

The accepted probe hooks native `0x2d2570` before it captures a history item.
The first argument is world core; current game time is core+0x18fc0. It verifies
the client rule vtable/type, owner pointer, ten-item configuration, zero scores
and unset deadline, then calls the native handler ten times for team 0. The
original capture subsequently serializes both statistics and rules normally;
the probe does not edit snapshot bytes or CRCs. The routine also writes native
completion flag history+0xc0bba, but that flag is not part of the E2 wire body.

In `battery-probe3`, verified checkpoints at 31300, 32350, 33400 and 34400 ms
all contain points 10:0 and winner 0. The coordinator automatically finished at
34963 ms using cutoff 34400 ms, CRC fa965999. F8 and the visible native window
agree on Victory 10:0, Player1, score 9 and zero kills/deaths. Nine recorded shots
explain the placeholder-weight score used in that run. Close returned to the lobby.
The capture decodes 1528 datagrams; this verifies the native event-to-checkpoint,
completion and results path, not physical collection/delivery of ten items.
Diagnostic executable SHA256:
`b96bfbc733c8a58472e8156f461fb477ef8f882b1e89366dff90d2ccb588fecb`.

## Configurable development scoring policy (2026-10-11)

The server now uses an explicit 28-event policy for both E4 setup and F8 final
recomputation. The first 24 values come from the working local 0.21 server's
`setup::SCORES`, not from recovered retail configuration. The four newer event
weights remain zero until their intended values are established. Provenance:
`/tmp/srp-server-021d/servers/match-server-021d/src/setup.rs`, SHA256
`27fd3177dfd65e04cd3bd9c1c9e6d11adbe8e4b6c9815f636a6bd4980104c71e`.
The annotated fixture is `servers/match-server-026/fixtures/026g-development-scores.txt`.
It awards kills 100, assists 50 and deposits 50; firing/hits/deaths have zero
weight. Event counters 6/17/18 retain native 0.01 scaling.

`--score-weights FILE` accepts exactly 28 finite f32 values, with whitespace and
`#` comments. Invalid files fail before socket binding. The server refuses to
change weights while players are admitted or the match is started. Tests cover
counts, invalid/nonfinite tokens, negative weights, policy arithmetic and the
admission guard. All 56 focused Rust tests pass (`scoring-focused-tests.log`).
CLI probes confirmed 27-value and NaN files are rejected before address parsing;
a valid file reaches address parsing. No network listener was needed for those
negative checks.

Two bounded native School tests used the unchanged production results executable
SHA256 `7885469640284cfee41fbfd73c0a378603eb8c9737e2562d4e26a77763bf3dd7`:

- `scoring-default`: 1931 datagrams, ten complete statistics blocks. The final
  verified checkpoint at 41300 ms, CRC e7aef205, contains event 22 = nine shots.
  F8 and the visible native results window both show score zero.
- `scoring-custom`: 1932 datagrams, ten complete statistics blocks. A diagnostic
  file sets event 22 to 2.5 and other events to zero. The final checkpoint at
  41400 ms, CRC 35af3a5f, contains eight shots. F8 and the visible native window
  both show score 20.

Both accepted Close, returned to the lobby, exited on their configured timeout
and cleaned up their private server/display. Neither native log contains
TypeError, ReferenceError or an unhandled exception. Evidence includes packet
captures, parsed statistics/results, game logs and screenshots under
`target/026g/evidence/scoring-{default,custom}*`; harnesses are in `target/026g/`.
This validates configurable final scoring, not kill/deposit result acceptance
or recovery of the original retail point values.

## Same-process rejoin investigation (2026-10-11)

The direct development hook currently calls native `connect_to_match` at
0x21beb0 once, after `game::set_network_client`. Native connect first compares
its requested match ID against match-client+0x577bc (match-client pointer at
network-client+0x1f1c48); equal IDs skip the connection. A rejoin path therefore
needs an explicit lifecycle/identity policy, not just replaying the launch hook.

Native lobby keyboard handler 0x26cb80 checks for an authenticated profile before
forwarding input. For key 0x40 it constructs a `play_button_clicked` call and
sends it through lobby logic 0x2812e0. The callback name is index 86 in the table
at 0x9c56c8 (entry 0x9c5820); `close_victory_screen` is index 52 (0x9c5798).
Logic stores 32-byte callback records at `(index + 0xe0) * 0x20`.
The normal mouse handler 0x26cff0 has the same profile prerequisite; our existing
results-only bypass applies only while the results flag is set.

`update_play_button_state` at 0x21fd40 consults lobby matchmaking state, queue,
squad and maintenance fields and calls 0x21fa10 to set the button state.
The Play callback target itself has not yet been identified. A scoped masked
FID/string comparison of the 0.21 Play/update methods found no candidates;
`lobby-rejoin-candidates.json` records that negative result. Native exports are
`0026cb80.c`, `0021fd40.c`, `0021fa10.c` and `002812e0.c`.
No rejoin patch or same-process rejoin acceptance is claimed here.

## Optional F6 same-process rejoining (2026-10-11)

The first probe at 0x26cb80 did not receive F6 after returning to the lobby.
The actual input::handler vtable at 0x9ffeb8 uses 0x26cb60 for keyboard input.
That function consults a delegate at input-handler+0x2fbc; the selected delegate
can differ after world teardown. A second probe hooked this entry, recovered
lobby by subtracting 0xec from ECX, and completed two native matches/results
without restarting. The private probe hardcoded port 2238; it is superseded by
the configurable production hook below. Failed/accepted diagnostics remain in
`target/026g/rejoin-probe*` and their evidence captures.

The optional builder flag `--rejoin` requires `--results` and installs the
0x26cb60 wrapper (original bytes `8d81bc2f0000`). Native input stack arguments
are input world, key, action. The wrapper intercepts F6 (0x40), preserves other
input behavior, and calls `rejoin.c`. It copies the launch host/port after
`game::set_network_client`; spectator, empty/overlong hosts and invalid ports
leave the feature unarmed. Valid F8 presentation marks the completed match.
Rejoining requires Close to have cleared lobby+0x313a, no world at
network+0x1f1c40, and native `match_client::is_disconnected` at 0x27a020.
That predicate reads the connection owner at match-client+0x23ce70 and accepts
an absent connection or state 3 at connection+0xb01f4. It rejects an active
handshake as well as an established connection.

Key down is action 1, release 2 and hold 3. A latch prevents duplicate downs
and holds from issuing another request; release permits an explicit retry.
QPC supplies a new nonzero session, with a collision check against the previous
local session. The hook updates the D9 session field and calls 0x21beb0 with
one more than the client's current match ID; this bypasses the equal-ID guard.
The server's E4 supplies its actual ID. Server reset now advances the ID after
the last participant leaves (zero/ffffffff are excluded at wrap). The existing
lifecycle regression verifies the ID stays unchanged until the final departure.
This is still an unauthenticated local development endpoint, not persistent
account identity or replay protection across server restarts.

The builder adds a 512-byte RW `.srpd` section 64 KiB beyond `.srp`, rejects code
that overlaps it, and updates the section count, initialized-data size and image
size. `.srp` remains RX. No writable static storage is folded into code.
The annotated manifest records the data section and original hook bytes.
Baseline and results-only executable hashes remain byte-identical to the prior
45baf0... and 788546... builds. Rejoin executable SHA256:
`e63433289f84db2d3b3e4853f62ad519c994a46808ce833d0d886ff3c9fb97c3`.

`rejoin-live-test.py` ran the production build for 160 seconds against a private
server on port **2239**, demonstrating use of the supplied launch endpoint.
The same native process/window completed two School matches and two F8 results.
F6 before Close caused no admission; a held F6 after Close caused exactly one.
No automatic third admission occurred while the second results remained open.

- Match 1: peer port 58081, 1933 datagrams, ten statistics blocks, F8 match ID 1.
  Final checkpoint 41300 ms, CRC 85badc8f; event 22 contains eight shots and the
  development policy yields score zero.
- Match 2: peer port 44357, 1930 datagrams, ten statistics blocks, F8 match ID 2.
  Final checkpoint 41300 ms, CRC 5561f120; all player event counters are zero.
  Its gameplay screenshot shows fresh 30/90 ammunition and the School timer.

The captures are split by peer into `rejoin-live-match{1,2}-packets.tsv` because
`inspect_capture` expands one match's times per invocation. Parsed reports,
states and F8 bodies, the combined native log, gameplay/results screenshots and
harness outputs are under `target/026g/evidence/rejoin-live*`. The bounded client
and private server/display exited and cleaned up normally. This is solo
same-process lifecycle acceptance; two-client rejoining remains to be tested.
Stock Play/account-profile initialization is separate from this explicit F6
control.

All 56 focused Rust tests pass. Five client tests pass, including the actual C
rejoin policy with only its three native calls substituted. Those tests cover
completion/close/world/connection guards, missing owners, endpoint copying and
bounds, spectator exclusion, duplicate/held keys, explicit retry and repeated
clock-value session rotation. Native and host tests serve different purposes;
host mocks do not establish the retail ABI.

### Repeated-results cleanup correction and final solo acceptance

Inspection of the saved `rejoin-live` log found a second-results TypeError #2007
in `LobbyMenu.close_sync`, although both windows rendered. ABC tag 0 method 211
unconditionally removes `_top_container` children `backblack` and `sync`; the
first result already removed them, and direct rejoin does not recreate them.
The rejoin state now identifies initial results so this one-time overlay cleanup
runs only once. The C policy tests cover that lifecycle flag.

The same audit found the synthetic own-slot EA using F8's historical cutoff,
which the engine rejected as too old. Results now retain that cutoff for their
data while teardown derives its tick from current world+0x191b8, the same clock
read by native 0x27c690. This correction also applies to results-only builds.
It does not modify snapshot bytes, results timing or scoring.

The final `rejoin-live2` run repeated both native matches/results on port 2239,
including the before-Close rejection and held-F6 admission guard. The same client
process stayed alive through both matches, then exited on its 160-second bound;
its private server/display were cleaned up. Neither final native log contains
TypeError, ReferenceError, an unhandled exception or the old leave rejection.
The existing native 'disconnection initiated but new packet has been enqueued'
warning remains once per finish; both transport disconnects completed normally.

- First connection: port 58613, match ID 1, 1927 datagrams, ten statistics blocks.
  Final checkpoint 41450 ms, CRC cd8785ca, eight shots and score zero.
- Second connection: port 45575, match ID 2, 1940 datagrams, ten statistics blocks.
  Final checkpoint 41400 ms, CRC 6f6f77b1, zero carried-over event counters.

Evidence uses prefix `target/026g/evidence/rejoin-live2*`, including the split
per-match captures, parsed F8 bodies, statistics, both results screenshots and
second-match gameplay. This supersedes the first production rejoin run for
solo lifecycle acceptance. Two-client rejoining remains an acceptance gate.
Final executable hashes, reproduced from tracked source:

- Rejoin: `f6b8689e0aa6c8e0660180911060f4bdaab0d45b736247d2433b8719279d348a`
  (`target/026g/client/Survarium/game/binaries/x86/survarium-rejoin2.exe`).
- Results without rejoin: `9bdd560291840a531650a9a7b813545ae0a7ed4d6cdae1f4419f176ff6bd7ef8`.
- Default without results remains `45baf0a591cf6535a9f7afa073ae59551979d92904670a4e1adf70336c1004e9`.

## Two-client same-process rejoining acceptance (2026-10-11)

`target/026g/rejoin-two-test.py` ran two isolated native clients for 210 seconds
against private port 2239 using the final `f6b8689e...` rejoin executable above.
Both completed two School rain matches without restarting. F6 while results
were open caused no admission; Close followed by held F6 admitted each once.
Exactly four admissions occurred; neither client automatically requested a
third match. Both second results screens were visually inspected.

- Match 1: peer ports 50002 and 53349, 4780 datagrams, 976 matching shared
  historical ticks, zero mismatches, 13 complete statistics blocks. F8 match ID
  1, participant mask 3, cutoff 52850 ms, CRC `3f6279bc`. Both players recorded
  nine shots (event 22), with score zero under the development policy.
- Match 2: peer ports 54659 and 52840, 4798 datagrams, 1050 matching shared
  historical ticks, zero mismatches, 13 complete statistics blocks. F8 match ID
  2, participant mask 3, cutoff 50400 ms, CRC `32058d6e`. All event counters
  were zero. No automatic recovery was triggered in either match.

Evidence is under `target/026g/evidence/rejoin-two-*`, including per-match
captures, decoded snapshots/results, validation logs, native logs and images.
Neither native log contains TypeError, ReferenceError, an unhandled exception
or `request REJECTED`. The existing disconnect/enqueued-packet warning remains.
The bounded harness exited successfully and cleaned up its private processes.
This supersedes the earlier pending two-client next-match acceptance gate.

The user additionally requires crash/relaunch recovery into the ongoing match
and working squads. Neither is established by this test. Current admission
assigns the first free slot, uses a per-launch session and leaves all 20 squad
bytes at 255. Native invitation/membership/group-admission behavior and stable
player identity must be implemented and exercised separately.

## Native squad representation and local identity (2026-10-11)

Correction to the earlier interpretation of the 20 setup squad bytes: **zero**
means no squad. The scoreboard at 0x2352a3 tests a byte at options+0x5782c
against zero and exposes that boolean as `squad_state`; it exposes the byte
itself as `squad_id`. HUD code 0x239890..0x2398cb returns false for zero and
otherwise compares the local and other player's bytes before setting
`is_squad_player`. The previous `[255; 20]` default incorrectly gave every
player the same nonzero squad ID; it is now `[0; 20]`.

String cross references recovered native `lobby_client::read_squad_info` at
0x274720 and `lobby_menu::fill_squad_info` at 0x2277c0. The first reads:
u32 squad ID; if nonzero, u8 member count, u8 commander index, then each member's
u32 account ID, u32 profile ID, u32 profile revision, u8-length name, u8 online,
u8 ready; finally u8 is-local-commander and u32 revision. The native storage is
three 0x50-byte members plus revision/ID/count/commander fields; the UI has
exactly three squad rows. The 0.21 PDB types confirm these field names.

The 0.26 lobby dispatch jump table at 0x275138 maps opcode **A1** to the call
of that reader at 0x274e84. Squad requests use opcode **4A**, unlike 0.21's 2A:
0x274580 writes action 1 (disband); 0x2745d0 writes action 2 followed by a
length-prefixed player name (invite); 0x274660 writes action 3 and u32 account
ID (remove member); 0x2746d0 writes action 4 (leave). Native invitation display
uses `root.add_important_message` in 0x226020, with localization
`st_add_to_squad_request` at 0xa01cd0. Acceptance/rejection and the native lobby
bootstrap still need implementation/validation; do not treat a configured squad
as completed invitation support. Evidence: `squad-candidates.json`, native
exports and `squad-*-decompile.log` under `target/026g/`.

The local server now accepts a validated `--roster` file fixing sessions, names,
teams and squad IDs before admission. The rejoin client reads optional
`SRP_MATCH_SESSION` through the existing GetEnvironmentVariableA import
(IAT 0x8701b4); invalid nonempty tokens fail closed. Missing/empty tokens retain
QPC-based sessions. Relaunch can reclaim the configured slot after five seconds
of silence when an active match has a surviving donor. Last-player crash
resumption remains unsupported. Unit tests cover reverse arrival order,
unknown/duplicate/live identities, preserved setup, delayed old endpoint traffic
and match reset. Native crash/relaunch testing is underway.

## Crash/relaunch with preserved squad identity (2026-10-12)

Two real clients used configured sessions `000000a1` (Alice, slot 0) and
`000000b2` (Bob, slot 1), both team 0/squad 1. Bob connected first, verifying
slot assignment is independent of arrival order. The harness killed only the
actual Alice game PID after checking its exact executable and private Wine
prefix, waited six seconds, and relaunched it. Alice returned through ordinary
checkpoint/replay admission in the ongoing School rain match. Screenshots show
both names with the same native A squad marker before/after the crash.

The first run exposed a reference-selection defect: choosing the lowest slot
made the returning Alice immediately replace Bob as the trusted donor. After
15 initial hash disagreements the server restored Bob from Alice. The server
now chooses the longest-active peer, breaking ties by slot, for both checkpoint
selection and mismatch comparison. A unit regression verifies that a returning
lower slot is the suspect when it differs from the surviving reference.

The repeat `identity-crash2` run used the fixed server. Alice re-entered at
58650 ms from Bob's 57650-ms checkpoint; after disagreement at 59500..60200 ms,
only Alice was restored from Bob's 60200-ms checkpoint. Bob was never reset.
The capture has 9257 decoded datagrams: 592 matching shared ticks before the
crash; 15 differing ticks immediately after re-entry; then **1118 matching
shared ticks and zero further mismatches** through 119450 ms. One recovery
occurred. Thus reconnect currently requires `--recover --checkpoints --snapshots`;
the server rejects configured active-match reconnect without recovery enabled.
This does not establish a divergence-free re-entry path without recovery.

Both fired before and after the crash. Verified statistics retain each player's
three pre-crash shots and finish with six each. Both native result screens show
Alice/Bob on the same team, F8 uses the survivor's 115500-ms checkpoint (CRC
`afcf20f8`), and 29 statistics blocks decode. The native logs have no TypeError,
ReferenceError, unhandled exception or `request REJECTED`. The bounded harness
logged completion of both results and client exits; the outer repeat tool
reported exit 143 during cleanup, so do not report a clean zero harness exit.
Captures, screenshots, logs and decoded states use `identity-crash{,2}-*` under
`target/026g/evidence/`; harnesses are in `target/026g/`.

Identity client SHA256:
`3e8c3e3828c8011d18ea8a99d57a1c9f0d4650f4c165c221ec4fda992c625bf1`.
At this stage 45 match-server tests, 13 protocol tests and six client C-harness
tests pass. Native lobby invitation acceptance is still outstanding. The new
`protocol_026::lobby` codec implements the recovered A1 status and four verified
4A actions with native storage bounds; it is not yet connected to a lobby service.

## Lobby transport recovery (2026-10-12)

0.26's lobby uses the same **UDP match-client transport** as matches, rather
than the 0.21 front door's framed TCP lobby. Constructor 0x26f060 creates the
generic match client (0x378a40), with request range 2e..50, response range 80..aa,
and lobby metadata vtable 0xa07fa8. That vtable's first two slots are 0x26e370;
length getter 0x26e390 returns variable length for all application messages.
The metadata switch at 0x26e260 has no valid targets for 86/A7: reject them.

All valid lobby application messages except 9f carry a delivery byte. For flags
20 it is a unique ID (native frame+19); for flags 60 it is an ordering index
(frame+20). The framing codec exposes both as `Frame::unique_id`, documenting
that distinction. The forthcoming lobby sender must implement ordered delivery
semantics, rather than interpreting both as interchangeable duplicate counters.
`retail_lobby_frame_oracle.py` generated 160 valid nonempty single/bundle/fragment
fixtures using the original parser and lobby metadata methods. Rust decoding
and encoding match those fixtures. Initial empty-variable probes asserted in
retail; they are excluded, and our decoder rejects empty variable bodies.

The native login success handler 0x37fb10 reads `08 u32_session IPv4 u16_port`
from its packed reply buffer, unlike the old browser/messaging endpoint reply.
This remains static evidence pending a real local login probe. The initial
lobby connect writer 0x26f650 queues opcode 2e containing u32 session and one
flag byte, then calls generic connect 0x379090. Sign-in handler 0x26fab0 accepts
opcode 80 with two bytes (client state and another flag), switches callbacks,
updates messaging subscriptions and sends query 32 with bytes 00 and 00/ff.

Messaging is integrated into the lobby: A4 reaches `read_important_message`
0x26bbf0, which reads sender type u8, sender ID u32, length-prefixed sender name
(64-byte buffer), clan tag (16-byte buffer), message type u8, length-prefixed
body (256-byte buffer), message ID u32. Native `read_important_message` response
0x26b1b0 removes the stored message and queues opcode 50 with u32 message ID and
u8 answer. Earlier PDB enum values suggest accept=0/decline=1; native acceptance
still needs exercise. A squad-invite-accepted notification (type 3) automatically
calls the invite/add-member method with the sender's name. Do not assume server
membership changes happen solely on the first invitation request.

Next integration work is a local login endpoint plus this UDP lobby bootstrap,
then native invite/accept/member status/readiness and a shared match redirect.
Existing 0.21 tools are reference only; their TCP lobby protocol cannot be copied
directly. Evidence: `lobby-login-candidates.json`, `lobby-*-decompile.log`, native
exports and `026g-lobby-frames.tsv`. No lobby invitation feature is claimed yet.

## Native login probe and handoff (2026-10-12)

The bounded `lobby-login4` probe reached the native login screen and submitted
disposable local credentials. The client sent version `0.26g0`, completed TLS
against the isolated local test certificate, and accepted the login success
reply. It then attempted UDP lobby connection to **1.0.0.127:19042**: the
diagnostic login reply's IPv4 byte order was wrong and must be corrected before
further lobby testing. The client aborted in Wine's unimplemented
`qwave.dll.QOSSetFlow`; no UDP sign-in reached the lobby probe. Login UI input
needed held mouse buttons and slower typing in the virtual desktop.

This verifies the TLS exchange, not a working native lobby. The loopback
`examples/lobby_probe.rs` is a bounded diagnostic without production retry or
ordered-delivery semantics. The scratch Python login server, private test key,
patched executable, and native logs remain outside the PR in ignored `target/`.
Native invites, acceptance, readiness, and joining a match together are still
unimplemented. Development was paused for PR preparation at this point.

## PR review corrections (2026-10-12)

A separate agent reviewed the coordinator, wire codecs and client hooks with
the native acceptance history and unfinished squad scope. Review found that
configured restart on the same UDP endpoint could leave `startup_sent` set
and refresh the dead transport indefinitely. It now uses the existing
five-second silence, recovery and surviving-donor guards to replace that
transport; rejected early D8 retries do not refresh its last activity.

The review also found that revisions at or before an active E8 restoration
baseline invalidated only cached checkpoints, leaving the in-flight state
stale. Restoration now tracks its journal cursor, rejects stale completion,
waits for a strictly newer verified donor checkpoint and retries within its
original five-second deadline. Recovery clients cannot donate checkpoints or
supply comparison votes. History gaps and membership changes also invalidate
restoration; transfer failure closes the affected transport. Regressions cover
same-endpoint reconnect, stale acknowledgements, fresh checkpoint retry, newer
input revisions and bounded failure without resetting the survivor.

These fixes passed the automated suite during PR preparation; they have not
been rerun in native clients. The user requested game shutdown, and the remaining
0.21 client plus the idle 0.26 rain School preview server were stopped. Local
research evidence remains in ignored build directories.

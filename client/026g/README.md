# 0.26g0 development client

Status at PR preparation (2026-10-12): core two-client gameplay and recovery
have native test coverage; native lobby invites and squad matchmaking remain
unimplemented. See the [server guide](../../servers/match-server-026/README.md)
for the current feature matrix, launch steps, and remaining acceptance checks.
The detailed observations below include earlier stages of the investigation;
local `target/026g` evidence is not distributed with this source-only PR.

`tools/patch_exe.py` creates a separate executable from retail build 2777. It
requires SHA256 `ac33d9937015c2299bf62cc6b127cb308b48a3475b30fff2ddd65479ae3bf153`
and verifies each instruction before replacement. Keep binaries and generated
manifests in ignored build directories. Python 3 is required; the optional
direct-match hook also requires GNU binutils (`as`, `ld`, `objcopy`, `nm`).

```sh
python3 client/026g/tools/patch_exe.py /path/to/retail/survarium.exe \
  /path/to/game/binaries/x86/survarium-srp.exe \
  --manifest target/026g/client-patches.json --direct-match --snapshots
```

Default patches:

| Address | Change |
|---|---|
| `0x13509` | Skip the archival resource-signing certificate's PKI chain check. |
| `0x124f9` | Accept an existing instance mutex; retain genuine mutex-creation failures. |
| `0x106411` | Skip the fatal check for detected VRAM below 320 MiB. |

The certificate table and resource RSA signature verification remain present.
The modified executable itself is no longer Authenticode-valid. This patch does
not alter the TLS/login certificate check. The VRAM patch keeps the detected
memory size and the original fallback for an unknown size; it adds no memory.

`--direct-match` adds a development connection hook after normal network-client
and UI initialization. It uses match ID 1 and a nonzero per-launch session
derived from QueryPerformanceCounter, initializes the session field used by the
startup request, and avoids resetting nonexistent lobby profile statistics.
The server rejects active session collisions. This path has no authenticated
login or lobby; the session is only a local connection discriminator.

`--snapshots` additionally uploads the initial engine-created historical state
before DA, using the new E2 extension, and accepts F7 requests for an exact
retained historical timestamp. It requires the matching server's
`--snapshots` option. By default the server waits for every configured player and upload,
sends E5, waits for DB, sends compressed E8, and waits for all E8 fragments to
be acknowledged before scheduling entry.

Use `--players 2 --start-players 1 --snapshots --checkpoints` to start with one
player and admit the second later. `--players` is roster capacity;
`--start-players` defaults to that capacity. A late join selects a verified
reference state no more than one second old, confirms the shared clock, and
waits for all state fragments to be acknowledged. It then replays accepted
input and membership changes, including revisions received during transfer,
with an acknowledgement barrier between batches. Only after catch-up does the
server schedule entry and enable live broadcasts. Loading peers neither send
accepted inputs nor become checkpoint donors. Invalidated or stalled transfers
fail independently after at most five seconds.

A real second client joined from a populated state at 41000 ms, acknowledged
four replayed input changes and entered at 42150 ms while the original player
kept moving. Both clients subsequently sent movement inputs. All 1443 shared
historical ticks matched, through 129250 ms; neither client required an active
full resync. See `target/026g/evidence/late-join-*` for the capture, native logs,
validation output and screenshot. This verifies the two-client late-join path;
a later real-client run also verified timeout departure, donor fallback and a
replacement client joining the vacated slot.

The server's optional `--checkpoints` flag requests historical snapshots from
the longest-active peer (slot order breaks ties) every five seconds, or at most once per second
while automatic recovery or a late join needs a fresh reference state. It checks each
complete response against that timestamp's reported CRC, rejects stale or
conflicting fragments, and expires requests after two seconds. Eight snapshots
from a real client passed CRC verification. This collects verified checkpoints;
it does not automatically restore a divergent client. Use a freshly built `--snapshots`
client: older development executables reject F7.

For explicit restoration testing, add `--restore-once-after-ms 25000` with
`--checkpoints`. The server restores all peers from a verified checkpoint at or
after that game time, waits for state-fragment acknowledgements, then replays
later inputs from its bounded history. A real solo client and two real clients
accepted active full resyncs and continued playing. One shared state hash after
the two-client resync matched; background stalls limited comparison coverage.
A later check with denser hashes exposed divergence while replay echoed inputs
back to their originator. Replay now sends only other players' inputs. The
post-countdown movement repeat produced 1071 matching shared ticks, zero
mismatches, and 634 matching ticks after restoration.

`--recover --checkpoints --snapshots` enables automatic recovery using the
longest-active peer as a trusted local reference (slot order breaks ties).
A returning lower-numbered slot does not replace the surviving donor. The server waits for
same-time hashes to settle for one second, then requires at least three
distinct mismatches spanning 200 ms. Duplicate or revised reports cannot
satisfy that threshold. New inputs invalidate affected historical evidence;
roster changes clear the comparison epoch and cached checkpoint. A verified
checkpoint and complete input backlog are required before the disagreeing
client is restored. Attempts are separated by at least ten seconds.
Launch each client with `-hash_check_interval_in_ms=50` so their historical
samples overlap. The default 100 ms interval can leave clients reporting
different tick phases, preventing detection until shared timestamps appear.

For a bounded fault test, add `--drop-relay 1:23300:24100` and run
`scripts/protocol-research/drive_inputs_026.py` against the two isolated displays.
The diagnostic withholds live relay messages to slot 1 during that game-time
range while retaining accepted inputs for replay. It is disabled by default.
The real two-client fault test withheld four messages, observed twelve
mismatching historical ticks, and automatically restored only slot 1. After
the last mismatch, 882 shared ticks matched through 72650 ms, with no second
restoration. The healthy reference client was not reset.

`--clock-sync` enables ongoing clock coordination. The server sends E6 probes,
subtracts client processing time from the round trip, and uses the native E7
gradual adjustment after three consistent measurements. A 10 ms deadband and
100 ms adjustment cap avoid reacting to small timing noise or making abrupt
world resets. Timing probes expire without retransmitting an old timestamp.
The controller assumes roughly symmetric network delay; measured local tests
do not establish behavior across arbitrary internet links.

`--clock-fault 1:25000:250` requests a diagnostic +250 ms slew in slot 1 at
25 seconds. In the real test, measured error reached 226 ms before correction;
three adjustments (-100, -100, -26 ms) brought it back to within 1 ms. Thirty
later samples stayed within that range through 101773 ms, with 1688 matching
shared world hashes, zero mismatches and no full resync. This diagnostic is
disabled by default. Evidence is saved under `target/026g/evidence/clock2-*`.

The server schedules departures for remaining players and resets the match when
the last peer leaves or times out. If a peer leaves during initial state transfer,
it closes the incomplete cohort so clients can start a fresh match. A real-client test removed the original reference after its 120-second
inactivity timeout, sent the survivor a leave at 195450 ms, and verified new
checkpoints containing only the surviving slot. A replacement restored that
state and entered the vacant slot at 212250 ms. All 2304 shared historical
comparisons matched, including 1156 between the survivor and replacement.
This verifies timeout departure and readmission with a new per-launch session;
a captured graceful client disconnect and match-end UI remain unverified.

```sh
cargo run -p match-server-026 -- --bind 127.0.0.1:2236 --players 2 --start-players 1 --map 61 --snapshots --checkpoints --recover --clock-sync
# Run from the extracted game's binaries/x86 directory:
survarium-srp.exe -splash_screen -server=127.0.0.1:2236 \
  -mt_allocator=768 -hash_check_interval_in_ms=50 \
  -log_to_stdout -write_errors_to_stderr -net_log
```

For **School in rain**, use `--map 71` (`level_02_rain_2.options`, battery mode).
The local English localization maps `st_level_02_name` to School. Two real
clients loaded this variant, spawned and moved, producing 1797 matching shared
historical ticks and zero mismatches through 102950 ms. No active full resync
occurred. Captures, logs and screenshots are in `target/026g/evidence/school-rain-*`.
The user also confirmed that the visible rain School preview works.

`inspect_capture PACKETS.tsv PLAYERS [SNAPSHOT_DIR]` now validates historical
state boundaries and reports the six world-block sizes and rule prefix. The
optional directory receives reassembled E2 bodies. Native animation decoding
verified all 157 saved snapshots from six test runs; 253 distinct animation
vectors and two School snapshots are regression fixtures. This is read-only
inspection used by the match-results work; the inspector does not end matches.

For lifecycle investigation, `--finish-after-ms 30000` forces a finish at game
time 30 seconds. This is a diagnostic trigger, not automatic time-limit or
battery-victory detection. Each active client receives its own-slot EA; delivery
retries until acknowledged, while new play and joins stop. Loading joiners are
cancelled. The terminal transport is retained for at most 30 seconds, then the
server permits a fresh match. A real client accepted the event and completed
FA/FB disconnect, but stayed on the School loading screen rather than showing
results by itself; use the optional results path described below. Evidence is in
`target/026g/evidence/finish-ui-*`; do not enable this diagnostic for normal play.

`--finish-timed` enables automatic native time-limit detection and requires
`--checkpoints`. It reads the time-limit rule from a recent verified checkpoint
and uses the pinned map config's duration, including its waiting state. The
rule's clock and player mask must match the checkpoint; stale or inconsistent
states cannot finish a match. This option is mutually exclusive with the forced
finish diagnostic. Its predicate passes 84 native oracle cases. A full-length
School run reached the 900-second match deadline, supplied a verified completed
checkpoint at 921100 ms (match began at 20500 ms), and accepted the finish event
with FA/FB disconnect. Ordinary full-battery victory acceptance remains
unfinished; automatic finish is opt-in. Evidence is in
`target/026g/evidence/timer-school-*`.

The experimental `--results` option must be enabled in both the client builder
and server. The builder also requires a GCC-compatible x86 compiler (`--cc`).
The server requires checkpoints, a finish policy and a battery-mode map listed
in `servers/match-server-026/fixtures/026g-result-modes.tsv`.
It sends an F8 result derived from one recent verified checkpoint, with its
explicit historical cutoff, team scores, names, kills, deaths and recomputed
scores. Players who participated before that cutoff remain listed after leaving.
The direct path has no account profile, so rank and account rewards are zero.

Real solo clients have accepted F8, disconnected from the match and displayed
the native results window. A firing test recorded six shots in its verified
checkpoint and displayed score six with the earlier uniform placeholder weights.
Native score recomputation itself matches 172 oracle
cases. The normal results build also accepts Close and returns to the lobby.
It activates the native menu after world teardown and allows its mouse handler
to forward clicks while results are open, without requiring an account profile.
The same server also accepted a fresh client launch and spawned a second match
after the first results/disconnect sequence. This verifies server reuse, not
same-process lobby matchmaking. Kill/deposit result rows still need acceptance.
Evidence is under `target/026g/evidence/live-results*`.
The default executable remains unchanged when `--results` is omitted.

Build with `--rejoin` as well as `--direct-match --snapshots --results` to enable
another match from the same client. After the results appear, click **Close**,
then press **F6** in the lobby. It reconnects to the host and port supplied by
`-server=host:port` at launch. No new match is requested automatically. F6 is
ignored while results are open, a world exists or the previous connection has
not disconnected. Release and press F6 again to retry a disconnected attempt.
The server assigns a new match ID when its last participant leaves.

```sh
python3 client/026g/tools/patch_exe.py /path/to/retail/survarium.exe \
  /path/to/game/binaries/x86/survarium-rejoin.exe \
  --manifest target/026g/rejoin-patches.json \
  --direct-match --snapshots --results --rejoin --cc /path/to/gcc
```

The rejoin build adds a separate writable endpoint-state section; hook code
remains read/execute. The default build without results retains its previous bytes.
Two consecutive solo School matches, both results screens and the F6 guards
have native acceptance (`target/026g/evidence/rejoin-live2-*`). The second match
had fresh ammunition and zero previous shot counters. Two clients also completed
two consecutive matches in the same processes: 976 shared historical ticks
matched in the first round and 1050 in the second, with zero mismatches.
Both second-round results had fresh zero event counters. Evidence is under
`target/026g/evidence/rejoin-two-*`. The stock Play button/account lobby is not initialized
on this development path; use F6 for the next match.

For local identity/reconnect testing, `--roster FILE` fixes each slot's session,
team, squad and name. Each noncomment line is `SESSION_HEX TEAM SQUAD NAME`;
session is exactly eight hexadecimal digits, team is 0 or 1, and squad 0 means
unassigned. A squad can have at most three players, all on the same team.
The number of rows must equal `--players`. Launch the `--rejoin` client with
`SRP_MATCH_SESSION` set to its row's session value. Missing/empty values retain
the previous random-session behavior; invalid nonempty values prevent a connection.
These are development admission tokens, not authenticated accounts.

A configured identity keeps its slot on relaunch. An existing endpoint can be
replaced after five seconds without packets; a running match also needs
`--recover --checkpoints --snapshots` and a surviving checkpoint donor.
Checkpoint/replay admission and automatic recovery bring the player back into
the match. A native test killed and relaunched one process while its squadmate
continued: the returning player kept their slot/name/team/squad and pre-crash
shot counters, both continued playing, and both reached results. The returning
client required one automatic resync after 15 initial mismatching samples;
1118 later shared ticks matched, with no further mismatches or survivor reset.
Evidence is under `target/026g/evidence/identity-crash2-*`. The last player's
crash does not yet preserve a resumable match.

Native squad invitations and joining together remain required. Configured
grouping exercises the match representation but does not implement that lobby
flow. The next-match test above does not establish either crash recovery or
lobby invitations.

The server now defaults to the working 0.21 server's development scoring preset
for the first 24 events, with zero weights for the four newer events whose
intended values are not yet established. Kills earn 100, assists 50 and deposits
50; firing, hits and deaths earn no points. These values are development policy,
not recovered retail scoring configuration. The complete annotated preset is
`servers/match-server-026/fixtures/026g-development-scores.txt`.
Use `--score-weights FILE` to supply exactly 28 finite floating-point weights in
event order; whitespace and `#` comments are accepted. The server validates the
file before binding and uses the same weights for native setup and final results.
Weights cannot change while players are admitted.
Native acceptance recorded nine shots and zero final points with the default
preset, then eight shots and 20 points with a diagnostic custom firing weight
of 2.5. Both results screens accepted Close. Captures, parsed statistics and
screenshots are under `target/026g/evidence/scoring-{default,custom}*`.

`--finish-objective --checkpoints` enables experimental battery-victory
confirmation on the supported battery maps. It can accompany `--finish-timed`
and `--results`; it cannot accompany the forced-finish diagnostic. The server
requires a valid active-match checkpoint showing all batteries on one team,
then a consistent winning checkpoint at least three game seconds later. It
requests checkpoints every second while confirming a win. Revisions to the
reference history, roster changes, restoration and match reset discard the
candidate. Stale or inconsistent evidence cannot finish the match.

This policy starts the native three-second delay from the first verified
observation because the original event-time deadline is absent from snapshots.
It can therefore finish later than retail. The threshold matches 72 native
event cases and the coordinator's positive/negative policy tests pass. A separate
native event probe reached 10:0, triggered automatic completion, displayed
Victory 10:0 and returned to the lobby through Close. Ordinary collection and
delivery of all batteries still needs acceptance. This option remains opt-in.

For that controlled diagnostic, `scripts/protocol-research/build_battery_probe_026.py`
builds a separate executable that calls the native team-0 deposit handler ten
times at the simulation's history-capture boundary after 30 seconds. It pins
the retail executable and original hook bytes, and keeps uploaded snapshots
unchanged. Use it only on a private test endpoint; it is not a normal client.

In this build, `-splash_screen` suppresses the splash. The older `-client` and
`-no_splash_screen` flags are invalid. Do not use `-spectator` with this hook:
the normal player path creates UI objects needed by match setup.

Local verification loaded map 61, uploaded 2,485 bytes of initial state at 50 ms,
accepted the returned state, and spawned a player with an AK-74M and 30/90
ammunition. The game logged its first synchronization and match start. A capture
contains movement/stop inputs and continuous state hashes. In a subsequent
two-client run the user confirmed movement, a kill, death on the other client,
and respawn. Both clients uploaded 2,530-byte initial states and entered the
match. Seven shared historical ticks had identical CRCs; coverage was sparse
because unfocused windows stalled and the clients reported different ticks.
An earlier two-client run left one client at login, so startup reliability and
background operation still need work. During the later explicit restoration
run, the user also confirmed battery pickup, depositing batteries at the base,
and killing. The experimental auto-minimize bypass used in that two-client run
did not fix background stalls and is excluded from this builder; the solo
restoration used the canonical client.
The default multithreaded arena exhausted its
376 MiB allocation while loading; the supported `-mt_allocator=768` setting
allowed loading to finish. One earlier
launch crashed before connection, so startup stability remains unverified.

On this workstation Wine 11.8 and DXVK 2.7.1 initialize the renderer. Wine 11.0
failed during executable loading. The installed default NVIDIA Vulkan driver
also differs from the running kernel driver; local tests explicitly select
the installed 595.71.05 ICD matching that kernel. These are environment issues,
not executable patches. Use an isolated Wine prefix with its own Documents
directory because the client writes logs and settings there.

For unattended two-client checks, use a separate Xvfb display and isolated Wine
prefix per client, then launch through Wine's virtual desktop:

```sh
Xvfb :4 -screen 0 1280x720x24 -nolisten tcp
# In another shell, with DISPLAY=:4 and the isolated WINEPREFIX:
wine explorer /desktop=srp026,1280x720 survarium-srp.exe \
  -splash_screen -server=127.0.0.1:2236 -mt_allocator=768 \
  -hash_check_interval_in_ms=50 -terminate_on_timeout=100
```

Choose an unused display number (or use Xvfb's `-displayfd` option). On this
workstation bare Xvfb launches fail in DXVK's monitor-timing initialization;
Wine's virtual desktop avoids that failure and keeps both clients active.
The existing Wine/DXVK/ICD settings above still apply. This setup changes the
test environment, not the game simulation or executable patches.

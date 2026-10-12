<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# Retail menu identity and match admission

This is the client/server integration boundary, dated 2026-10-11. Native
identity guards and HTTP transport passed isolated tests, then ran in the real
retail lobby through a local login/lobby fixture. Two real clients subsequently
created/joined/readied/started the same match through the local allocation
service; the detailed evidence and remaining lifecycle issue appear below.

## Native identity lookup

`dll/native_session.c` reads identity on the Scaleform callback thread. All
offsets target the retail executable fingerprint in the parent README.
It reads no password or account-name fields and invokes no game functions.

| Check/read | Retail layout or instruction evidence |
| --- | --- |
| Callback owner | `flash_external_handler_impl+0x0c`; dispatcher RVA `0x1a576e` reads this before calling owner vtable slot 1 |
| Owner type | Slot 1 must equal module base + lobby callback RVA `0x1615c8`; that routine uses owner minus `0xf4` as the lobby scene |
| Game | Lobby scene + `0xa0`; helper RVA `0x195354` follows this and `game+0x3684` to the network client |
| Current scene ownership | `game+0x3638` must still point to this lobby; network + `0x18` must point back to this game |
| Network type | Its vtable slot at `0x54` must equal the stock close-match RVA `0x1923b8` |
| Login state | Network + `0x20` is login client; its +`0x140` must be signed-in (1) |
| Lobby connected | Network + `0x238` is lobby client; its +`0x1b4` must be true |
| Session | Lobby + `0x44`; sign-in code at RVA `0x18d04f` writes these four bytes after opcode `0x26`; redirect code uses network + `0x27c` for match connection |
| Session cross-check | Login client + `0x13c` points to login implementation; its +`0x188` session must equal the nonzero lobby session |

Reads use `ReadProcessMemory` against the current process so an unreadable
pointer fails the lookup rather than faulting. These checks establish the
expected object graph, not that the server accepts the session. Synthetic
tests cover the rejection checks. A real login-bound lobby session subsequently
passed the lookup and supplied menu operations; broader account-change and
gameplay lifecycle tests remain. Preview bypasses this lookup and is explicitly
identified as preview.

## Control transport and lifecycle

For loopback integration only, the worker sends a native session as:

```text
Authorization: SRP-Native-021d <eight lowercase hexadecimal digits>
```

The value stays in the DLL. It is neither a callback argument nor a Scaleform
variable, and it is not logged. Requests in explicit preview mode have no
Authorization header. Outside preview, missing native identity returns 401
locally without sending the request. The standalone menu fixture rejects native
headers; it cannot validate a login-server session.

The control service must resolve this header against the login service's live
session store. It must ignore the form's `player` field for authorization and
derive the account itself. Its capabilities result must include `player`, an
opaque public ID of 1–40 characters used by roster, ownership and ready fields.
The preview fixture supplies its preview identity in the same response field.
Native session IDs are legacy 32-bit values; this transport is not the remote
release authentication design. Remote deployment still needs TLS and exchange
for a suitably strong API credential bound to the authenticated session.

Each HTTP job captures the native session and an identity epoch. Account
changes invalidate completed and in-flight results even if the numerical token
later returns to the previous value. A pending screen receives 401 and clears
its room, capabilities and retry body; an idle screen is invalidated before its
next request can be sent. A new movie generation also drops old results. An
already transmitted mutation cannot be undone by dropping its response: the
server still needs session-aware reservation cleanup and idempotency.

## Admission uses the stock lobby notification

The server package now includes `native_menu.py` with an authenticated room
registry and per-room match allocation. The older standalone `front_door.py`
still supports fixed-roster probes; use `native_menu.py` for menu admission.
After the creator starts a ready room, the service sends each member the stock
lobby redirect to that room's allocated match:

```text
framed lobby body:
  0x33
  u8 host_length; byte[host_length] host
  u16_le port
  u32_le match_id
  u8 team
```

The retail lobby handler branch at RVA `0x191dec` reads these fields, updates
the lobby match order, installs the match callbacks, resets match state to 0,
and invokes the native match connection with the lobby session. This provides
more of the required setup than assigning a UDP endpoint directly. The DLL
does not inject this packet or call into the middle of that branch.

The local prototype now authenticates against the live lobby session, allocates
separate server processes with room-specific session grants, and sends the
stock redirect after readiness and successful process startup. Remote session
exchange, complete profiles and broader lifecycle/failure verification remain.
A successful HTTP Start alone is not evidence of gameplay admission; the
real-client tests below also checked the UDP handshake and loaded worlds.

The existing game requires static player/map descriptors before resource
loading and stock `0x42` readiness before dynamic state can be applied.
[Running-match research](running-match-research.md) covers those constraints,
snapshot integration and the stock explicit-leave route. Our native snapshot
extension and the server's current community-extension prototype must be
integrated explicitly; stock `0x47` remains Leave in our protocol.
The first explicit adapter passed automatic-redirect startup and stock Leave;
the later allocation service replaces that unconditional redirect with Start
from our menu. See the running-match document for the wire contract.

## Real-client integration run

### Local allocation service

The native lobby service now accepts optional `--match-server` and
`--match-work` arguments. Point the first at the executable built from the
isolated SRP protocol adapter, not the community-protocol prototype. The second
is a private work directory for allocation logs and short-lived native session
grants. Omitting both arguments retains the original menu-only fixture.

```sh
python3 client/021d/tools/lobby_fixture.py \
  --front-door /path/to/server-checkout/servers/match-server-021d/tools/front_door.py \
  --cert /path/to/local-test-login.crt --key /path/to/local-test-login.key \
  --match-server /path/to/srp-server-adapter/target/debug/match-server-021d \
  --match-work /path/to/private/matches
```

`match_registry.py` allocates one loopback UDP server per started room, up to
eight concurrent processes. It requires the creator, every member ready and
every native lobby connection still present. Only the room's native sessions
are written to its mode-0600 grant file, mapped to contiguous player slots.
It also requires each member's DLL to report `X-SRP-Match-Protocol: SRP1-48`
or `SRP1-48-R1` on a request authenticated by that live lobby session. With
`--require-recovery`, only `SRP1-48-R1` is accepted; use that option with the
server adaptation produced by `prepare_server_probe.py --recovery`.
The bridge enables this
header only after its native match hooks initialize successfully. Reconnecting
or disconnecting clears the stored claim. An incompatible roster receives an
error before any process or redirect is created. This is a compatibility check,
not authentication or proof against a modified client.
The process must report its listening port before any redirect is queued.
Start retries use the same request ID and do not allocate twice. Lobby sends
are serialized with keepalive replies. HTTP disconnects after a committed
Start do not cancel its native admission.

Each room currently uses the server's fixed School (`level_02/rain`) setup,
Battery hunt mode and test loadout. Capacity limits the waiting room; Start
loads exactly its present roster. The client capabilities and mode label
reflect this restriction. Active rooms are displayed as “In progress”; the
service rejects late joins until the running-world synchronization path is
implemented and tested.

An expected lobby TCP close during match loading retains the allocation.
When that player next signs into the lobby, the registry removes their active
membership without redirecting them. Other members' process stays alive; the
last return stops it and removes the room and session grant file. Exited child
processes are reaped and their rooms removed. A failed redirect closes that
allocation so partially admitted clients can reconnect rather than joining a
room incorrectly relabeled as waiting.

This is a local development service with disposable accounts, fixed profiles
and the prototype server. It is not the remote authentication or release server.
Five added registry tests cover authorization/readiness, concurrent retries,
independent allocations, departure, startup/redirect failure and child exit.
A real two-grant child-process smoke test verified readiness, private file mode,
termination and grant deletion.

### Two-client menu admission run

On 2026-10-11, two clean-retail installations used separate Wine prefixes,
documents/log directories and private Xvfb displays. Both used our DLL, loader,
movie and local certificate. No community binary or another worker's running
server/client was involved. The service imported the server worker's front-door
module read-only and launched our isolated SRP adapter.

The first client created `Together`; the second found it in the browser and
clicked Join. Both clicked Ready, and the creator refreshed the roster and
clicked Start. One process on port 34147 received both admitted sessions and
sent static descriptors, restored a common snapshot and activated both slots.
Both initial snapshots were 672 bytes at time 50, CRC `6fa8cb1c`. Screenshots
show both clients in their own spawn locations with the match timer running.
The server accepted the creator's fire input and the second player's movement.

The creator then used stock Leave. The server removed slot 0 and sent `0x57`
to slot 1. On the **first** opening of Matches after return, the creator saw
`Together`, occupancy `1 / 8`, and “In progress.” The automatic read-only
capabilities retry resolved the previous session-change notice. The second
client continued playing and firing; its ammunition decreased from 35 to 33
and the server accepted that input after the creator's departure.

When the second player left, its native lobby reconnected and the final room,
child process and private grant file were removed. Its UI retained the old
waiting room, however: joining players do not necessarily have an outstanding
Start response to invalidate on return. The new fix refreshes an open room
when Matches reopens. The service now returns `code: room_unavailable` for a
closed room or removed membership, and the movie clears that room and fetches
the browser. This last fix passed compilation and server contract tests;
its real-client return path still needs a recheck.

The CRC diagnostic produced mostly alternating timestamps (100 ms cadence,
50 ms phase difference). Three common timestamps matched: 58150 (`a214567d`),
58250 (`71296395`) and 60200 (`54c1ada4`). The last is after the creator's fire
input, but before the second player's movement. This is limited consistency
evidence, not sustained CRC agreement or proof of combat/death/respawn.

Evidence directory: `/tmp/srp-021d-menu-run/`. Key files are `menu-cohort.log`,
`cohort-matches/*/server.log`, `cohort-crc-report.json`, `cohort-game-a.log`,
`cohort-game-b.log`, `cohort-ready.png`, `cohort-game-2.png`, `cohort-game-3.png`,
`cohort-after-leave-2.png`, `cohort-after-leave-3.png`, and
`cohort-last-return.png` (the remaining UI bug). The earlier single-client
allocation test is recorded in `menu-admission.log` and `admission-*.png`.

Tested two-client artifacts: DLL SHA256
`013e2fd2d6f0ec175b69d3551b240fe9649a63ca76aea12d6b74856059952c8b`,
movie v11 `7fa1fbbd68509c98ec1c0d26eb7eaf0496a12ebcc7e7a54b71adf96c82ea5426`,
and isolated server with CRC logging
`eb7a0e049b61dcf67906edfd34c77a0d6513253212bb7e5682152445752be716`.
The movie compiler still preserved 5,352 original method bodies and all 2,773
non-ABC tags. Fifteen Python tests passed, including concurrent Start replay,
authorization/readiness, separate allocations, departure and process failure.
The retained-room fix is packaged as movie v12, SHA256
`e6a9b6af61da2244e5e271b3d2e1dfa8626b097f3d5d0a54291d85bd4e02dab2`,
and `target/client-021d/menu-resources-v12.db`. Both private test installations
pointed at that archive for the runtime recheck below.
The final empty browser is recorded in `cohort-empty-browser.png`. Both Wine
prefixes, both private displays and the allocation service were stopped after
the run; no match child remained.

### v12 return and synchronization recheck

The next two-client run on 2026-10-11 validated v12 in both clients. The creator
created `Recheck`, the other client joined, both readied, and Start allocated
one server on port 39492. Both loaded the same game. Each client moved forward
and backward and fired. The creator's stock Leave returned to a browser showing
one remaining player and `In progress`; the other client continued firing.

After the joining client left, its first opening of Matches refreshed the
retained room, received `room_unavailable`, and automatically listed the empty
browser. The service log records `slot=1, op=room, ok=False` followed by
`slot=1, op=list, ok=True`. No extra click, Retry or client restart was needed.
The final departure stopped the server and deleted the session-grant file.

This run enabled the optional `SRP_MATCH_HASH_STEP=1` diagnostic alongside
`SRP_MATCH_PROTOCOL=1`. There were 1,186 paired CRC reports at identical
simulation times from 100 through 60,150 ms, with zero mismatches. Sampling is
not complete coverage of every step, and this run did not exercise player
damage/death, recovery or joining after simulation began. The native probe
also passed the two hash-instruction guard checks and its existing snapshot,
fragmentation and stock-message metadata checks.

Tested DLL SHA256:
`4ae5bd31c5bac8b17c5970e30b68c1d01636b8b765924b237069487a476a547f`.
Movie and server hashes are unchanged from v12 and the adapter recorded above.
Evidence under `/tmp/srp-021d-menu-run/`: `menu-recheck.log`,
`recheck-matches/b01411627f9abae0-8d995028-1/server.log`,
`recheck-crc-report.json`, `recheck-game-a.log`, `recheck-game-b.log`,
`recheck-game-a.png`, `recheck-left-a.png`, `recheck-remaining-b.png`,
`recheck-left-b.png`, and `hash-probe.log`. Both private Wine prefixes, private
displays and the allocation service were stopped after the run.

After that run, admission gained the protocol-capability check described above.
The updated DLL builds as SHA256
`0cad61d3974c802531d3e34f9a5ff06b70df179a36d77dbc697656bce5200920`.
Allocation tests cover rejection with one incompatible member and success once
all members are compatible; actual WinHTTP tests cover the absent/default and
enabled native capability headers. These checks are separate from the preceding
gameplay run, which used the earlier DLL hash.

### Earlier native-lobby fixture run

On 2026-10-11 the retail client logged into `tools/lobby_fixture.py` with preview
disabled. This tool imports the separate server worker's `front_door.py` and
uses isolated ports 19031–19035. It keeps the native lobby connected, validates
the DLL's Authorization header against that connection, and replaces the form's
preview identity with `local-1`. It still uses fixture rooms, accepts disposable
test credentials, and cannot start gameplay or initialize a complete profile.

```sh
python3 client/021d/tools/lobby_fixture.py \
  --front-door /path/to/server-checkout/servers/match-server-021d/tools/front_door.py \
  --cert /path/to/local-test-login.crt --key /path/to/local-test-login.key
```

Use the matching test certificate as the client test installation's loose
`resources/ssl/survarium_login_server.crt`. This run generated its own certificate
from the repository's development login key; it used no community executable
or certificate. Set `SRP_MENU_API=http://127.0.0.1:19035/v1/menu`, leave
`SRP_MENU_PREVIEW` unset, and launch with `-client=127.0.0.1:19031`.

The real native lobby accepted our callback owner/session checks. The UI listed
rooms, accepted typing `Native menu`, created a room on `rudnya`, showed
`local-1 (creator)`, and toggled Ready. After a client restart, the browser
rediscovered that room; Join reopened it with its retained readiness, and Leave
removed it. Logs show each operation bound to slot 0 without logging its token.

Escape initially opened the game's options menu over our panel. The patch now
prepends guards after the scope prologue in two existing SWF methods:
`has_active_window` returns true for an open SRP panel, and `close_active_window`
closes it first. Both retain the complete original bytecode as their fallback.
The other 5,352 original bodies and all 2,773 non-ABC tags remain unchanged.
A background layer blocks mouse clicks behind the panel; closing clears focus
from its hidden text fields.

The fix was verified in the restarted client: Escape closes Matches, and a
second Escape opens the original options menu. The tested final movie SHA256
is `9e112ec0e4793ae944f582d76ec8f3ec8ccc11d03e17c499079c646bac7d2b54`;
the DLL is `00c94de0863e75b1e919520106be636efaaccc243b320f49c52aeac185d5372d`.
Evidence is in `/tmp/srp-021d-menu-run/`: `lobby-fixture.log`,
`native-create-form.png`, `native-created-room.png`, `native-modal-v9.png`,
`native-escape-fixed.png`, `native-options-fallback.png`,
`native-rejoined-room.png`, and `native-left-room.png`.

This verifies coexistence with the native login/lobby and options path, not
complete profile/inventory service behavior or two-client gameplay. The server
worker's source and running clients were not modified. The private test client,
fixture and display are stopped after the run.

## Native visual cleanup (2026-10-11)

The revised menu replaces the existing StatusPanel Play button with Matches.
Its high-priority CLIK click listener consumes the event before stock
matchmaking. All three screens use the original Ranking window frame and its
embedded text style, with stock grey buttons and skinned text inputs. The
frame's summary fields, list heading and footer now align with our content.
Close, X and Escape retain the room and drain pending requests. Retry has its
own space above the footer. Browser pagination consistently uses eight rows.

The v15 movie SHA256 is
`8e52896cec45aa5ac6243cf4c4a26a3f0b2d4692b314bf146a3a623c122da837`.
The build preserved 5,352 original method bodies and 2,773 non-ABC tags.
In the real 1280×720 retail client, verification covered custom name entry,
invalid capacity rejection, corrected capacity submission, Create, rejection
of Start before Ready, Ready, room retention across Close/X/Escape, waiting-room
Leave, another Create/Ready/Start, loading a real match, stock Leave and opening
the browser again. The returning client correctly discarded its unavailable
room. This visual pass did not repeat two-client Join, pagination with many
rooms, or testing at other resolutions.

Local evidence under `/tmp/srp-021d-menu-run/` includes `style-service.log`,
`style-validation.log`, `style-create-valid.log`, `style-room-controls.log`,
`style-leave-start.log`, and the `style-*-v15.png` screenshots. The private
test used login/menu ports 19041/19045; the visible demo uses 19031/19035.

## Disconnect and shutdown lifecycle (2026-10-11)

Native lobby EOF now releases waiting-room membership and Ready state. Creator
EOF closes only that waiting room. The handler acts only if it still owns the
session's current socket, so a superseded connection cannot evict a replacement.
Started rooms retain membership across normal loading-related lobby closure.
SIGTERM now follows the fixture's shutdown path, stopping child match processes
and deleting their grants. Redirect delivery is in the response's `finally`
path even if writing the HTTP response headers fails after a committed Start.

`tests/run_lobby_lifecycle.py` passed against real disposable login/lobby/API
sockets and an actual SRP-adapted match server. It verified final-slot reuse,
removal of Ready state, replacement socket ownership, creator closure with an
independent room unaffected, loading handoff retaining the server and grant,
and SIGTERM releasing the UDP port and deleting the grant. The service exited
with status zero; logs are in `/tmp/srp-021d-menu-lifecycle-v1/`.
The Python suite passes 20 tests with the local retail EXE supplied. Active
match crashes, timeouts and reconnect still need separate lifecycle integration.

## Local package build (2026-10-11)

`tools/prepare_client.py` now builds the archive tool from included source and
its independent lockfile, extracts the retail lobby movie, builds the DLL and
loader, transforms the movie and overlays the original archive. It extracts
the result again and verifies its hash; the overlay compares every untouched
member's stored bytes. Only a fully verified build receives `package.json`.
This remains preparation rather than an install/update/uninstall implementation.

Two local packages produced identical payload hashes. The final manifest and
source fingerprints are in `target/client-021d/package-v2/package.json`:

| File | SHA256 |
| --- | --- |
| Patched executable | `30c43d5878c6e89a061891ab069f771dffe33c2c0e7d6e868a25296de1690f01` |
| DLL with fixed module name/base | `5e842f8cc5d0a6aa2bc40c621346811696cf89a9a29f8860bb75999a8ad4de9e` |
| Patched archive | `a99986107eb345be3cee32a35ea9ddc0f8200adb4c66de8e3e00f839936b8de5` |

The movie hash matches the v15 runtime test above. The DLL also matches a build
to a different directory and filename. Its preferred image base and export
module name are now explicit; the older runtime-tested DLL let the linker
derive them from the output filename. After normalizing all 891 base
relocations, every section except `.edata` matches that older DLL, including
code, data and imports. This comparison establishes the packaging difference;
it is not another full game runtime test. The included archive tool's three
overlay tests and its exact-member/overwrite-refusal test also pass.

## Installation and restoration (2026-10-11)

`tools/install_client.py` provides `check`, `install`, `restore` and `recover`.
It accepts only the fixed three-file contract for the verified retail build.
All replacements and originals are copied, hashed and flushed before the first
game-file replacement. The archive and DLL are installed before the executable.
An atomic journal records preparation, installation and restoration phases;
each rename and its parent directories are flushed on Linux. Restoration keeps
its backup copies until every original file verifies, so interruption during
restoration is also recoverable. The small OS-lock file remains deliberately
to avoid replacing the inode while another installer is acquiring its lock.

The installer rejects linked/reparse paths, unrelated changes to managed files,
corrupt required backups and unknown files in its metadata directory. All
restore preconditions are checked before changing any game file. A repeated
installation of the same payload verifies files and backups without replacing
them again. Updating currently requires restore followed by a fresh install;
composition with other EXE/archive patches is not yet supported.

The Python suite passes 33 tests, including every install and restore checkpoint,
a child process exiting without cleanup after its first game-file replacement,
partial staging writes, interrupted final metadata cleanup, lock contention,
and refusal to touch a mapped game file. Linux process-map inspection is an
additional check; the game must remain closed throughout the operation.
These tests do not establish crash durability on every filesystem or Windows
behavior.

The full CLI check/install/restore cycle also passed on separate real retail
files in `/tmp/srp-021d-install-run/game`, using `package-v2`. An independent
post-restore hash check confirmed the original executable
`def82eeaed9d544b2e1c1e0ec971f7359c24a942dd52ace6b45e6d82e7c34a0a`
and the 3,601,973,776-byte archive
`e28cc2878e0e2f04ab9ab0a1861034622af487a491bf230ea24f44e9af9715a4`.
The installed DLL and backup/journal directory were removed. The evidence is
recorded in `/tmp/srp-021d-install-run/roundtrip.json`. This was a file lifecycle
test, not another game launch or multiplayer test.

## Profile launcher and installed-client run (2026-10-11)

`tools/launch_client.py` verifies the installation journal, patched files and
original backups, then starts the client from its own binary directory. One
profile sets the local service base port; login and menu endpoints are derived
together. Inherited `SRP_*` diagnostics are cleared before explicit profile
settings are applied. Native and Wine examples are in `profiles/`; only Wine
execution has runtime evidence so far.

The launcher holds both the installation lock and a dedicated Wine-prefix lock.
Wine's explorer/start wrapper may forward a command and return early, so the
launcher also waits for `wineserver -w`. A process-supervision test checks that
both locks stay held after an early wrapper exit and release only after the
server waiter finishes. A separate real Wine probe confirmed that virtual
desktop wrapper status does not reliably propagate the child's exit code;
the README documents that limitation. The Python suite now passes 39 tests.

The previously restored `/tmp/srp-021d-install-run/game` was installed again
from `package-v2` and launched using the private profile under
`/tmp/srp-021d-launcher-probe/`. Its service used login/menu ports 19051/19055.
Despite inherited `SRP_MENU_PREVIEW=1` and `SRP_MATCH_CAPTURE=1`, the client
showed native login and produced no capture files. The packaged DLL with SHA256
`5e842f8cc5d0a6aa2bc40c621346811696cf89a9a29f8860bb75999a8ad4de9e`
initialized its native hooks and completed the AS3 callback probe.

The real UI created `Launcher check`, readied, started a match on allocated
port 51568, loaded School, left through the stock options menu, and returned
to an empty usable browser. The last departure removed the session grants.
Normal Quit returned the launcher with status zero and both locks were then
available. `hash_step_50ms` was false: the server recorded 747 CRC reports,
with 722 adjacent intervals of 100 ms and 12 each of 50/150 ms. This is
single-client launch/admission evidence, not a new two-client synchronization
or recovery validation.

Evidence in `/tmp/srp-021d-launcher-probe/` includes `profile.json`,
`client.log`, `service.log`, `tests.log`, `menu-sequence.log`,
`leave-sequence.log`, and `login.png`, `game.png`, `returned.png`, `close.png`.
The installed client's DLL log is in its `binaries/x86` directory. The private
game exited normally; the earlier visible demo was not restarted for this run.

## Native results handoff (2026-10-11)

The isolated allocator now supports `--match-results` and an optional
`--match-seconds` limit. It confirms each process's fresh instance/generation,
records admission order and server slot, and retrieves that slot's retained
native results on lobby return before releasing the last-player allocation.
Results remain available to the authenticated player after the process stops.
Native admission and result packets use the allocation's own match order ID;
starting another match clears the player's previous result. Server fixture
names/loadouts and rewards are still placeholders.

The initial live finish probe exposed a second `0x59` sender introduced for
final statistics. The old adapter only changed the recovery sender, so the
final donor request had no SRP envelope and the client waited for statistics.
`prepare_server_probe.py` now adapts every recognized sender and rejects an
unknown sender shape. Its copied UDP tests assert the envelope on every such
request, including the final-state timeout branch. The original server
checkout remains untouched.

The corrected adapted server passes 46 unit and 5 executable/socket tests.
The client Python suite passes 43 tests with the real executable check enabled;
new cases cover both snapshot senders, unknown sender refusal, per-admission
slot/order selection, results after final departure, stale order rejection and
malformed/missing result cleanup. The real-socket allocator lifecycle test also
passes against the newer server.

The installed package-v2 client, private Wine prefix and profile launcher ran
the finish probe under `/tmp/srp-021d-results-probe/`. The first allocation
demonstrated the missing-envelope failure; the corrected server was installed
at the private fixture's executable path before the next allocation. Match
order 2 loaded School on port 56430, returned a checked final snapshot at
simulation time 45100, and delivered a 97-byte native results packet after
lobby reconnect. The stock results screen displayed the fixture player's
statistics instead of remaining at “Receiving match stats”. No client package
change was needed. This establishes a single-player time-limit handoff; combat
statistics, multi-player finish, objective victory and missing-donor UI remain
separate gates.

After closing those results, the same client created/readied/started match
order 3 on port 50989. It again reached a populated native statistics screen
with a retained snapshot at time 45100 and a 97-byte result packet. Thus orders
2 and 3 form two consecutive complete menu-to-game-to-results cycles, without
restarting the game or lobby service. Each final return removed the match's
session grants and control socket. `third-results.png` records the second
successful results screen.

Closing the third results screen returned to an empty usable Matches browser
(`returned.png`). Normal Quit returned the launcher with status zero; both
installation/prefix locks were released. The private fixture stopped normally,
and its private display was removed. `verification.json` records those checks.

Evidence includes `second-results.png`, `service.log`, per-match `server.log`,
`tests-final.log`, `server-tests-checked.log` and `lifecycle/lifecycle-service.log`
under that probe directory. The checked server source is in
`/tmp/srp-menu-server-021d-results-checked`; its source files match the runtime
build from `/tmp/srp-menu-server-021d-results-v2`.

## Missing and delayed results UI (2026-10-11)

`ui/SrpResults.as` observes the original VictoryScreen's waiting indicator.
After 15 seconds without statistics it explains that the player can close
the screen and return to Matches. It keeps the native Close handler and
does not fabricate scores or rewards. Native `setData` hides the waiting
indicator; the helper then hides its notice. Closing or completing the screen
resets the timer for the next match.

The package-v3 development run under `/tmp/srp-021d-results-fallback/`
deliberately dropped every native results reply for admission order 1, then
delayed order 2's reply by 25 seconds. Its screenshots confirmed the initial
loading message, timeout notice, usable Close followed by another match,
fresh loading period for that next match, and replacement by native results
when the delayed packet arrived. The first screenshot also exposed an empty
text field's default font being copied before native localization ran.
The source now copies the populated loading field's style when showing the
notice. Package-v3 is superseded by package-v4 for that styling correction.

Package-v4's verified movie SHA256 is
`4be3e86587fc39ff6e8efc569fcc1a6e3062e00e83d49747b04e7f7bc5f1487c`;
the archive SHA256 is
`f3ea03d7831697c33c3310f2c76405f5be40cf6e082b7d92122d30aec2c30f9d`.
The executable and DLL match package-v2. All 5,352 unaffected original method
bodies and 2,773 non-ABC tags remain unchanged. The full Python suite still
passes 43 tests with the real executable check enabled. These Python tests
do not exercise Scaleform rendering; the private-client fault runs supply
the UI evidence.

The final package-v4 run under `/tmp/srp-021d-results-fallback-v4/` confirms
the corrected readable native font and color (`missing.png`) after a withheld
reply. `waiting.png` records the initial stock message before timeout. Both
runs used clean installed packages, native login and a private front-door
copy that injected faults only into results delivery; no retail statistics
were synthesized. The original server worker's source was not modified.

Package-v4 also passed the second-match delayed-delivery run:
`second-waiting.png` shows the fresh stock waiting period,
`second-delayed.png` shows the correctly styled fallback, and
`second-arrived.png` shows the complete native statistics after the 25-second
delay. Both missing-result Close and the eventual native results Close worked.
This covers the fallback at 1280×720 in English under Wine; other languages
and resolutions are still separate UI checks.

The final client exited through the stock Quit confirmation with launcher
status zero. Its private service stopped normally; the private display was
stopped afterward. All allocation grants/control sockets were removed and
the installation and Wine-prefix locks were available. Those checks are
recorded in `verification.json`. The private game copy currently has
package-v4 installed; the earlier visible demo was not updated by this run.

## Integrated SRP1 server selection (2026-10-11)

The current server worker exposes `--protocol srp1` directly. `MatchProcess`
now passes that option to the actual binary and refuses a readiness line
without `protocol=srp1`. A wrapper that independently adds the same option
must not be used with this updated allocator. Earlier adapter commands in
this document record historical runs; the current snapshot tool copies the
integrated Rust source and tests unchanged and records their hashes.

An isolated snapshot at `/tmp/srp-menu-server-021d-integrated` passed all
56 server tests (48 unit, seven UDP cohort, one lifecycle). The initial
parallel run had an `AddrInUse` failure before one test server started; the
serial rerun passed, including SRP1 populated late join, dialect rejection,
stock Leave and final-state acquisition. The Python suite passes 43 tests.
This integration does not repeat or replace the worker's recorded native-menu
playtest; its `docs/v021d/SRP1-INTEGRATION.txt` provides that GUI evidence.

The final real-socket menu lifecycle run at `/tmp/srp-021d-integrated-lifecycle-final`
passed native login, cancellation/ping distinction, waiting-room disconnects,
replacement lobby ownership, SRP1 allocation and process/grant cleanup.
It enables generation-bound status/results support and verifies the process
announced SRP1. The corrected lobby handler echoes only opcode `0x28` as
`0x37`; native matchmaking cancellation `0x27` neither generates that reply
nor cancels an SRP menu room. The server worker's `LOBBY-CONTRACT.txt` records
the retail enum/disassembly evidence for that correction.

Test output is in `/tmp/srp-021d-integrated-python-tests.log` and
`/tmp/srp-021d-integrated-server-tests-serial.log`; the initial port-collision
output is retained in `/tmp/srp-021d-integrated-server-tests.log`.
No GUI client or worker-owned server checkout was changed for this step.

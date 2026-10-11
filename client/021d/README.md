<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# Retail 0.21d client menu development

This experimental client targets untouched retail 0.21d build 2010 and works
with the repository's integrated `match-server-021d` and native menu service.
It builds a DLL bridge and a lobby movie with a match browser, create form,
waiting room and missing-results notice. See the
[current PR status](../../docs/v021d/PR-STATUS.txt) for the combined server/client
evidence and limits, and the
[Scaleform match menu plan](../../resources/notes/021d-scaleform-menu-plan.md)
for the original design.

Two clean-retail clients have created/joined one room, readied, and entered the
same real match through the local allocation service. Stock Leave returned the
creator to a usable browser while the other client continued firing; the last
departure stopped the allocated server and deleted its session grants. Both
return-to-browser paths passed, including the joining client's retained-room
refresh. A diagnostic run compared 1,186 same-time simulation hashes during
movement and firing with no mismatch. Native timed results, return to Matches,
and a second match have also been exercised. The current movie's 15-second
missing-statistics notice, Close action and late-arriving results passed in
the real client; see the [integration evidence](docs/native-menu-integration.md).

The integrated service persists local account identities and match-order
counters, but uses development authentication and fixed School/battery-hunt
map/loadout fixtures. Active simulations and results remain ephemeral. The
server coordinates client simulation and trusts a snapshot donor; it does not
run independent game physics. SRP1 late joining/reconnect, native Windows
runtime, real-client clock-drift correction and remote deployment remain
unverified or incomplete. A verified local package can be built, installed
and restored with the tools below; this is not a public binary release.

An opt-in `SRP_MATCH_PROTOCOL=1` DLL hook exports the initial world snapshot
and handles our explicit `0x59 + SRP1 + 01` snapshot request, uploading bounded
populated history through versioned `0x48` messages. Stock Leave remains `0x47`.
An isolated adaptation of the server restored one already-loaded retail client
from another's populated state, with 1,144 paired hashes after
restoration and no mismatch. Late joining and reconnect with this SRP1 client
remain unverified; community-patched-client results do not establish them.
The integrated server now accepts `--protocol srp1`; the menu allocator selects
that dialect explicitly and requires it in the readiness response. Pass the
actual integrated server binary to the server package's `native_menu.py
--match-server`, together with `--require-recovery` and the updated DLL.
The client-side `lobby_fixture.py` remains an ephemeral development fixture.
No protocol wrapper or source rewriting is needed. See the
[recovery evidence](docs/running-match-research.md#srp-requested-snapshots-and-active-recovery).
For synchronization experiments only, `SRP_MATCH_HASH_STEP=1` also changes the
stock hash report interval from 100 to 50 ms; it requires the protocol hook.
Both instruction sites are checked before changing them. Normal pacing remains
unchanged when this diagnostic flag is absent.
`SRP_MATCH_CAPTURE=1` additionally saves two populated history snapshots locally
at 2 and 10 seconds. Adding `SRP_MATCH_ROUNDTRIP=1` decodes those freshly produced
bytes into temporary history items, resolves their animation resources using
the loaded players, and compares the reserialized bytes. Both samples passed
byte-identical round trips in a real single-client match; movement, firing and
Leave still worked afterward. That scratch diagnostic complements the active
recovery test above. See the
[bounded export experiment](docs/running-match-research.md#bounded-export-prototype-and-live-capture)
for its exact scope, file handling and the loaded-game round-trip evidence.
See [protocol and live evidence](docs/running-match-research.md#our-initial-snapshot-hook-and-srp1-framing)
and [menu admission](docs/native-menu-integration.md#local-allocation-service).

The game supplies its own Scaleform runtime. No Scaleform SDK is needed to
compile our DLL. The DLL and tools are GPL-3.0-or-later, consistent with this
repository; original game assets remain external inputs.

## Build a verified local package

On Linux, Python 3.11+, Cargo/Rust, an x86 MinGW-w64 compiler and the complete
FFDec 26.0.0 distribution can build all client patch artifacts in one command:

```sh
python3 client/021d/tools/prepare_client.py /path/to/retail/game \
  /path/to/new/client-package --ffdec /path/to/ffdec/ffdec.jar
```

The game directory must contain `resources.db` and `binaries/x86/survarium.exe`.
The output directory must be new and outside the retail installation. Explicit
`--java`, `--javac`, `--cc`, `--library-dir` and `--cargo` options support tools
outside PATH. By default the command builds the included archive tool with its
own Cargo.lock; `--archive-tool` can reuse that tool's compiled executable.

The command checks the original EXE/archive/movie fingerprints, builds the DLL
and loader, compiles the ActionScript, and overlays the movie. The archive tool
compares every untouched member's stored bytes and the builder extracts the
resulting movie again to check its hash. A successful build writes
`package.json` containing the file replacement hashes, patch dependencies,
source fingerprints and tool fingerprints. It rechecks source and retail
inputs before writing this completion marker; failed output directories have
no marker and must not be installed.

`payload/` contains the generated EXE, DLL and resources.db in game-relative
paths. `work/` contains build intermediates and compiler diagnostics. This
build command does not install or launch the game. The generated EXE/archive
contain retail data and stay local; publish the source and transformations.
Install and restore commands are described below. See [notices](NOTICE.md)
for the included archive source and external tool dependencies.

## Install, update and restore

Close the game first. Use a separate retail installation while this remains a
development build. The installer accepts the exact retail executable/archive;
it refuses an existing DLL or unrelated changes to those files. It also refuses
symlinks/reparse points along managed paths. Other assets and settings are left
in place.

```sh
# Read-only check of the package and original installation.
python3 client/021d/tools/install_client.py check /path/to/game /path/to/client-package

# Stage, verify and install the three files; retain verified originals.
python3 client/021d/tools/install_client.py install /path/to/game /path/to/client-package

# Uninstall and verify the original executable/archive; remove our DLL.
python3 client/021d/tools/install_client.py restore /path/to/game

# The same restoration works after an interrupted install or uninstall.
python3 client/021d/tools/install_client.py recover /path/to/game
```

Installation uses roughly another 7.3 GB temporarily for originals and staged
replacements. Keep `.srp-021d` intact until restoration succeeds. Every managed
file and required backup is checked before restoration changes anything. A
modified file or damaged backup stops the operation for review; there is no
force-overwrite option. Repeating the same install verifies it without replacing
files again. To update, restore first, then install the newly built package.
This initial installer does not compose with another patch to the EXE/archive.

A small `.srp-021d.lock` file remains after uninstall. Its OS lock prevents
concurrent installers and releases automatically if a process exits; the file
alone does not mean an installer is running. On Linux, mapped game files are
also checked to catch a running native/Wine client. Close the game throughout
the operation; this check cannot prevent another program from launching it.
Linux restoration and interruption tests are covered; Windows installation and
power-loss behavior on other filesystems still need validation.

## Launch with a service profile

Copy `profiles/local-wine.example.json` to your own JSON file and set the game
directory, Wine executables and a dedicated Wine prefix. Relative paths are
resolved from the profile's directory. Native Windows has a separate
`profiles/local-windows.example.json` example; its runtime remains unvalidated.

```sh
python3 client/021d/tools/launch_client.py /path/to/profile.json --check
python3 client/021d/tools/launch_client.py /path/to/profile.json
```

`--check` verifies the installed files and backups and prints the exact command
and launcher-controlled environment without starting Wine or the game. The
normal command starts in `binaries/x86`, enables our match protocol, and uses
`service_port` for login plus `service_port + 4` for the menu API. The current
service and DLL support loopback only. Start the integrated menu service
separately with the same base port; the launcher does not start or manage an
existing server. Test accounts remain development fixtures.

```sh
python3 /path/to/server-checkout/servers/match-server-021d/tools/native_menu.py \
  --cert /path/to/local-login.crt --key /path/to/local-login.key \
  --base-port 19031 \
  --match-server /path/to/match-server-021d \
  --match-work /path/to/private/matches \
  --state /path/to/private/accounts.sqlite \
  --require-recovery --match-results
```

The server package supplies its own front door and registry. `--state` retains
account identities, native session tokens and match-order counters across
graceful restarts. Waiting rooms, readiness, results and active simulations
remain ephemeral. After a connection error, sign in again and create or join
a new room. Persistent local identities do not add production password
authentication or remote hosting. Use a current local certificate trusted by
the test client's runtime; the historical repository certificate has expired.

The launcher removes inherited `SRP_*` variables before applying the profile,
so an old shell's preview, capture or round-trip settings cannot silently alter
the session. `hash_step_50ms` explicitly enables the hash-report diagnostic and
defaults to false. Wine's optional `vram_floor` enables the verified workaround
for incorrectly reported video memory. Other host settings, such as DISPLAY
and graphics-driver configuration, are inherited normally.

Keep the launcher running until the game closes. It holds the installation
lock and, for Wine, a prefix lock while the client runs. Wine's explorer wrapper
can return before a forwarded game process, so the launcher also waits for
`wineserver -w`. Use a dedicated prefix without unrelated applications. A Wine
virtual-desktop launch reports the wrapper's exit code, which is not a reliable
game crash status; inspect the game's and DLL's logs if launch fails.

## Build the DLL and loader

Requirements: Python 3, an x86 MinGW-w64 C compiler, and the original retail
executable. `build_dll.py` accepts `--cc` and optional `--library-dir` arguments
for toolchains installed outside PATH. The resulting DLL imports only Windows
KERNEL32, MSVCRT and WinHTTP services.

The DLL build fixes its internal module name and preferred image base and
omits linker timestamps, so changing the output path/name does not change its
bytes with the same compiler and sources. Normal loader relocations remain
available when that preferred address is occupied.

```sh
python3 client/021d/tools/build_dll.py --output target/client-021d/srp-client-021d.dll
python3 client/021d/tools/patch_exe.py /path/to/retail/survarium.exe \
  target/client-021d/survarium-srp.exe
```

The patcher accepts only retail SHA256
`def82eeaed9d544b2e1c1e0ec971f7359c24a942dd52ace6b45e6d82e7c34a0a`
and refuses an existing output file. It leaves the original executable intact.
It appends an executable `.srp` section and redirects the entry point through
a position-independent bootstrap. The bootstrap calls the game's existing
LoadLibraryA/GetProcAddress imports, calls `srp_initialize`, restores the
startup registers/flags and enters the original game. Initialization failure
exits with `0x53525001`. The copy's old signature directory is cleared because
its signature no longer applies.

Keep `srp-client-021d.dll` alongside the patched executable in a test installation.
The DLL verifies the retail timestamp and hook instructions, installs a
trampoline over complete instructions, then forwards original callbacks.
Initialization runs before the game entry point, outside DllMain. The narrow
SetVariable adapter follows the actual LTO ABI: value in EAX, movie/path on the
stack, callee pops eight bytes. Do not replace it with a guessed thiscall cast.

For Wine only, `SRP_WINE_VRAM_FLOOR=1` enables an optional in-memory fix for the
retail rejection of incorrectly reported video memory. It changes only the
too-small-memory branch to return the existing minimum. It verifies relocated
original instructions and does not modify the executable file.

For offline development, `SRP_MENU_PREVIEW=1` replaces the login movie path in
memory with the lobby movie path. This displays the patched lobby without a
working login server. Original movie callbacks are suppressed because the
login scene cannot handle lobby commands. This is a UI diagnostic, not an
authenticated lobby or a playable session; leave it unset for normal use.

## Build the movie patch

Requirements: a JDK (tested with Java 21) and the complete
[FFDec 26.0.0 release](https://github.com/jindrapetrik/jpexs-decompiler/releases/tag/version26.0.0).
Keep its bundled `lib` and `flashlib` directories beside `ffdec.jar`.
The release ZIP `ffdec_26.0.0.zip` used here has SHA256
`e13509d0ed11c6d77bb1588701d803eb2c706e2ba4eaab8bc4477255cfc718f4`.
Preserve its dependency license files when distributing the tool.

Supply the original `flash_movies/lobby_menu.swf`, with SHA256
`1370380ff8029fabbe7f564b44574ccd5aafbd5675868b4f5a140b1b2956c8b9`.
It is an ordinary member of the original resources.db.

```sh
python3 client/021d/tools/patch_swf.py /path/to/retail/lobby_menu.swf \
  target/client-021d/lobby-menu.swf \
  --ffdec /path/to/ffdec/ffdec.jar --work target/client-021d/swf-work
```

`--java` and `--javac` accept explicit tool paths. The patcher records the input
and output hashes beside the result. It rejects unknown input and existing
output. Compiler diagnostics are written to `--work/ffdec.log`.

FFDec does not correctly interpret every display tag in this game movie.
The tool therefore extracts only attributes and ABC into a temporary movie,
compiles our new `SrpJson.as` and `SrpMenu.as` classes, and inserts `SrpMenu.install(this)` before
the original LobbyMenu constructor's return. It also inserts guards into
`has_active_window` and `close_active_window` so the native Escape handler
recognizes our panel. Their original bodies remain as the fallback when our
panel is closed; the other 5,352 method bodies remain byte-identical. It
transplants only the ABC block back into the original SWF.
All 2,773 non-ABC tags, including their original header encodings, remain
byte-for-byte unchanged. Do not re-export the full movie through FFDec.

Matches replaces the original Play button in `StatusPanel`; its priority
listener opens our browser before the stock matchmaking handler runs.
The browser, creation form and waiting room reuse the actual `SrvPlayerRanking`
window frame, embedded text style, `SvButtonWide2` action buttons and
`TextInputSkinnedChar` inputs. The original Close and X controls remain usable.
The Ranking-specific controls are hidden without activating its data requests.
Layout uses the lobby's scaling and recenters when the stage resizes.
`ui/SrpMenu.as` owns the layout; no replacement retail artwork is distributed.

Its probe calls the local `srp_probe` callback, which updates the patch's own
response text field. A bounded frame listener also attempts the probe while a
disconnected lobby blocks mouse input, and acknowledges observing the native
response with `srp_probe_ack`. These callbacks do not contact a server.

## Standalone menu preview fixture

For playable local sessions, use the integrated server's `native_menu.py` and
launcher profile described above. The standalone fixture below is an optional
offline UI diagnostic. Run it separately and set these variables when manually
launching a preview client; the profile launcher clears inherited `SRP_*`
variables and does not enable preview mode.

```sh
python3 client/021d/tools/menu_fixture.py --port 19022
export SRP_MENU_API=http://127.0.0.1:19022/v1/menu
export SRP_MENU_PREVIEW=1
```

Open Matches to load capabilities and rooms. The current controls provide
Refresh, Create, Join, room refresh, Ready, Start and Leave. The fixture models
room membership and creator departure; Start explicitly reports that gameplay
allocation is unavailable. Its preview identities are not real authentication.
The bridge currently accepts only a loopback URL. In preview mode it uses the
fixture identity; outside preview it requires a current native lobby session.
The fixture rejects native Authorization headers because it cannot authenticate
them. Remote deployment requires the planned session exchange and TLS
configuration. See [native menu integration](docs/native-menu-integration.md)
for the guarded session lookup and server boundary.

AS3 sends ASCII form data in named callbacks with zero GFx arguments. This
avoids sharing proprietary GFx value layouts or ownership across DLL boundaries.
A dedicated worker performs bounded WinHTTP requests. Only a UI-thread poll
sets the movie's `wireResponse` string. The worker never retains movie pointers.
Each movie has a generation token; attaching a different generation drops old
completions. Closing the panel keeps processing an in-flight mutation so a
successful Create or Join remains visible when reopened. Retry reuses the
original request ID and body. The fixture rejects an ID reused with a different
body and serializes final-slot admission under a lock.

The UI includes an original, bounded JSON parser so it does not depend on a
native JSON class in the old GFx runtime. The parser and ordinary mouse-driven
screen transitions have run successfully. Text entry and Escape have also passed
in the native lobby. Full keyboard navigation, localization, larger rosters and
remaining failure/lifecycle cases still need validation.

## Test installation and resource archive

Use a separate test copy of retail, with its normal `binaries/x86`, `resources`
and `resources.db` arrangement. Keep the original files for restoration.
The included `resources-db` tool can pack a donor
archive containing just `flash_movies/lobby_menu.swf`, then apply it to retail:

```sh
cargo build --locked --release --manifest-path client/021d/vendor/resources-db/Cargo.toml
# Use client/021d/vendor/resources-db/target/release/resources-db below,
# or add its directory to PATH.
mkdir -p target/client-021d/overlay/flash_movies
cp target/client-021d/lobby-menu.swf target/client-021d/overlay/flash_movies/lobby_menu.swf
resources-db pack target/client-021d/overlay target/client-021d/menu-donor.db
resources-db overlay-db /path/to/retail/resources.db \
  target/client-021d/menu-donor.db target/client-021d/menu-resources.db
```

The archive source, import provenance and dependency lockfile are included in
`vendor/resources-db`; building it does not modify the server workspace's
manifest or lockfile. It currently builds on Linux; Windows archive-tool
portability is still pending. Never overwrite a resource archive used by a
running client.

Waiting-room reservations now follow the native lobby connection. A member's
disconnect removes that slot and Ready state; creator disconnect closes the
waiting room. Replacing a lobby socket does not let the old socket evict the
new connection. Disconnecting the lobby during match loading preserves the
started allocation. SIGTERM shuts down allocated servers and removes grants.
The socket-level lifecycle check runs against isolated local services:

```sh
python3 client/021d/tests/run_lobby_lifecycle.py \
  --front-door /path/to/server-checkout/servers/match-server-021d/tools/front_door.py \
  --match-server /path/to/server-checkout/target/debug/match-server-021d \
  --cert /path/to/local-test-login.crt --key /path/to/local-test-login.key \
  --work /path/to/new/lifecycle-test-directory
```

This test uses disposable accounts, real login/lobby/API sockets and an actual
temporary match process. It verifies final-slot reuse, creator departure,
replacement-connection ownership, loading handoff, and shutdown cleanup. It
does not establish active-match crash recovery or reconnect behavior.

The integrated `native_menu.py` command above enables native results with
`--match-results`; `--match-seconds 30` is useful for a short finish test.
The older `lobby_fixture.py` also supports these flags when supplied with a
matching front door's `match_status` and `match_results` helpers, but retains
only ephemeral identities. Each allocation confirms a fresh server
instance/generation before admission. On return, the allocator retrieves that
player's native results
before stopping the last player's server and retains them for lobby queries.
Match order IDs are unique within the fixture's service lifetime; the
integrated service also persists its order counter when `--state` is supplied.
An earlier match's results cannot answer a later match's query. Missing results
are not fabricated.
These flags are for the local development service, not remote account hosting.

The server can be built directly from this repository; see its
[launch and build instructions](../../servers/match-server-021d/README.txt).
For an isolated diagnostic copy, snapshot its integrated package and tests into
a new directory:

```sh
python3 client/021d/tools/prepare_server_probe.py \
  /path/to/server-checkout/servers/match-server-021d /path/to/new/server-copy
cargo test --manifest-path /path/to/new/server-copy/Cargo.toml -- --test-threads=1
cargo build --manifest-path /path/to/new/server-copy/Cargo.toml
```

Use `/path/to/new/server-copy/target/debug/match-server-021d` as `--match-server`.
The snapshot tool records source hashes and copies Rust source/tests unchanged.
It refuses the older server instead of rewriting its message handlers; the
historical `--recovery` adapter option is retired. The allocator appends
`--protocol srp1` itself, so do not pass a wrapper that also adds that option.
The native lobby echoes ping `0x28` as `0x37`; native cancellation `0x27`
does not alter an SRP room or produce a ping reply.

The menu patch also observes the stock results screen. If statistics have not
arrived after 15 seconds, it replaces the indefinite loading message with an
explanation that the player can close the screen and return to Matches. The
stock Close button and late-result handling remain active; this does not
substitute empty statistics for a missing server result.

## Validation status

The current source-only Python suite runs 43 tests: 42 pass and the retail
executable integration test is skipped unless `SRP_RETAIL_EXE` is supplied.
The PR review reran this suite without launching a game. The sections below
retain earlier validation checkpoints and their exact artifact hashes; those
hashes and temporary evidence paths describe those runs, not the current
package. For the integrated status and remaining gaps, start with
[PR status](../../docs/v021d/PR-STATUS.txt) and the later
[native menu integration record](docs/native-menu-integration.md).

The real retail executable under Wine 11.8/DXVK 2.7.1 rendered the patched
lobby and its Matches button in offline preview mode on 2026-10-11. The
ActionScript probe reached the DLL, the LTO SetVariable adapter updated
`root.srpMenu.response.text`, and ActionScript acknowledged reading the
response. The DLL log contains:

```text
development menu preview enabled; original callbacks suppressed
SRP 0.21d Scaleform bridge initialized
SRP DLL connected: response 1
AS3 observed the native probe response
```

A second response was visible in the captured client window. This tested the
earlier bridge-probe movie, before the browser screens were added. Local evidence:
`/tmp/srp-021d-menu-run/bridge-confirmed.png` and that test installation's
`game/binaries/x86/srp-client.log`. Tested artifact SHA256 values:

| Artifact | SHA256 |
| --- | --- |
| Patched executable | `30c43d5878c6e89a061891ab069f771dffe33c2c0e7d6e868a25296de1690f01` |
| Bridge DLL | `fab6a994def700bcf3e3b911f4afbeb240272b93fa0794f94f7cca1bf8aa6787` |
| Patched lobby movie | `52454b47f93745c1a9258b25d9b139335c8c64b77cfeb2375d7191e277d1ee2f` |

The movie compiler verified preservation of 5,354 original method bodies
outside the constructor change, and the resource overlay replaced one member.
Earlier runs also rendered the original login and lobby UI with the DLL
installed. At this initial stage, authenticated lobby behavior, recreating the
movie, Windows execution, and gameplay were unverified. Preview deliberately
suppresses original callbacks, so its success alone cannot establish those
behaviors; the later native-lobby run is documented below.

The expanded menu was subsequently tested under the same Wine/DXVK versions on
a private Xvfb display with `wine explorer /desktop=SRP,1280x720 survarium.exe …`.
Wine's virtual desktop avoided a DXVK divide-by-zero encountered with Xvfb's
bare monitor. Actual Windows relative mouse input drove the retail cursor and
Scaleform click handlers; requests used the DLL worker and local HTTP fixture.

Verified interactions:

- Empty browser; create `My match` on `rudnya` with capacity eight.
- Read the creator roster; toggle Ready; show the fixture's explicit Start error.
- Creator Leave removes the room and returns to the browser.
- Refresh and Join a room seeded for a second fixture player; display both
  members and omit Start for the non-creator.
- Non-creator Leave releases only that slot; close and reopen the browser.

Independent HTTP reads confirmed the membership/readiness changes. Local
screenshots are in `/tmp/srp-021d-menu-run/`: `browser-response.png`,
`create-form.png`, `created-room.png`, `start-unavailable.png`, `joined-room.png`,
and `panel-reopened.png`. The tested movie SHA256 was
`40f755605547a3b6242b2d28e80f30613319e96719fdeae616dd300985ea1eef`, and DLL SHA256
was `af867a896b045c1c8795ea848f3126a3b43b060956fd7e4c45f32dcc78589b89`.
A subsequent cosmetic change aligns the browser's column headings with its
rows; that movie compiles but has not been recaptured.

See [running-match research](docs/running-match-research.md) for the native
snapshot/admission and explicit-leave investigation that led to the integrated
0.21d server protocol.

Run the format guards and retail executable integration check with:

```sh
SRP_RETAIL_EXE=/path/to/retail/survarium.exe \
  python3 -m unittest discover -s client/021d/tests -v
```

At the earlier format/admission checkpoint, 39 tests passed with
`SRP_RETAIL_EXE` supplied, including rejection of unsupported or
already-patched executables, preservation of every original PE section and
import mapping, rejection of malformed SWF tags, concurrent final-slot admission,
idempotent creation, creator departure and room permissions.

The bridge test runner builds two x86 programs and starts a temporary loopback
HTTP fixture that verifies the native Authorization header:

```sh
python3 client/021d/tests/run_bridge_smoke.py --work target/client-021d/bridge-tests \
  --wine /path/to/wine --wine-prefix /tmp/srp-021d-probe-prefix
```

It accepts `--cc` and repeated `--library-dir`; omit Wine arguments on Windows.
Both programs passed under Wine 11.8: synthetic native object guards reject a
wrong owner, stale lobby, disconnected/sign-out state and mismatched sessions;
WinHTTP tests verify preview/native headers, busy rejection, movie-generation
discard, account-change invalidation/recovery and the initialized match protocol
capability header. Match allocation rejects a roster with a missing capability
before starting a server or redirecting players. The tests use synthetic
credentials and do not log or expose real session tokens. A change away from
and back to the same token cannot revive an old completion.

The updated movie compiles with its original non-ABC tags preserved. Its new
401 handler clears the old room and requests fresh capabilities when reopened;
capabilities now supplies the display identity used for readiness and ownership.
The native lookup and ordinary room flow subsequently passed in the real
retail lobby through `tools/lobby_fixture.py`. That fixture validates native
sessions but accepts disposable test credentials; `--match-server` enables
the isolated gameplay allocator described above.
The account-change 401 screen has not yet been exercised there. See the
[native integration run](docs/native-menu-integration.md#real-client-integration-run)
for commands, exact tested artifacts and screenshots. These checks do not
replace the two-player gameplay gate.

The native snapshot probe runs selected retail history routines in an isolated
process, without entering the game. Its runner rejects an unknown executable
hash before compiling. On Linux, use a dedicated Wine prefix:

```sh
python3 client/021d/tools/run_native_snapshot_probe.py /path/to/retail/survarium.exe \
  --work target/client-021d/native-probe --wine /path/to/wine \
  --wine-prefix /tmp/srp-021d-probe-prefix
```

It also accepts `--cc` and repeated `--library-dir`; on Windows omit the Wine
arguments. Five active-player masks passed exact serialization and native
deserialization under Wine 11.8, including slots 0 and 19 and all 20 slots.
The probe verifies timestamp framing, player ordering, omission of private
player state and four world buffers. Additional serializer tests use present
synthetic trees, compare native bytes, and place undersized outputs against a
protected memory page. These do not demonstrate restoring a populated live
match; the standalone harness lacks its animation assets. Use the runner to enforce the
full-build guard before calling addresses inside the executable.

<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# Retail 0.21d: joining and leaving a running match

Investigation started 2026-10-11. This is client-side evidence for integration
with the separate server worker. The opt-in initial-snapshot hook below has
loaded two clean-retail clients into the same menu-created match. Late joining
is not yet demonstrated. The menu-only fixture has no game server; the optional
allocation service launches real isolated server instances.

All offsets below are RVAs for retail build 2010, executable SHA256
`def82eeaed9d544b2e1c1e0ec971f7359c24a942dd52ace6b45e6d82e7c34a0a`.
The preferred image base is `0x10000`; add the actual module base at runtime.
Names and layouts come from the matching PDB, with behavior checked in the
retail executable's instructions. LTO changes calling conventions.

## Verified receive and leave paths

| Routine | RVA | Evidence relevant to the patch |
| --- | --- | --- |
| `network_client::on_match_packet_received` | `0x191520` | Dispatches stock messages `0x50`–`0x59`; checks match state before handlers |
| `process_static_match_info` | `0x192ddc` | Reads match options, per-player descriptors and local-player index, then queries player resources |
| `on_match_ready` | `0x1925cc` | Binds player objects and local-player identity; sends stock `0x42` after resources are ready |
| `process_dynamic_match_info` | `0x192e88` | Resolves `m_match->game_world_core` and calls its deserializer |
| `game_world_core::deserialize(buffer_reader&)` | `0x1bab3b` | Reads a history item, reconciles history, restores state and advances stored time values |
| `process_player_entered_match` | `0x192fbb` | Reads a player ID byte and a 32-bit simulation time, then calls `enter_match` |
| `process_player_left_match` | `0x19301e` | Reads a player ID byte and a 32-bit simulation time, then calls `leave_match` |
| `network_client::close_current_match` | `0x1923b8` | Explicit user leave sends stock `0x47` with a 32-bit game time and flushes the match client |
| `network_client::unload` | `0x192c82` | Releases player references and the match resource; it is separate from the leave request |

The dispatcher jump table at RVA `0x191908` confirms:

- `0x51`: static match info, accepted in `waiting_for_static_match_info` (1),
  then moves the client to `playing_match` (2).
- `0x53`: dynamic match info, accepted in state 2.
- `0x56` / `0x57`: player entered / left, also accepted in state 2.
- `0x59` remains the stock serialization-debug message. Our patch must not
  silently assume the community snapshot extension under this ID.

State 2 alone is not evidence that asynchronous player/map loading finished.
`on_match_ready` sends `0x42` only after constructing/binding the loaded world
and player objects. A dynamic-state packet dereferences the loaded match
resource; delivering it before that resource exists is unsafe.

The dynamic-state handler uses stack arguments `(network_client, reader)` and
returns with `ret 8`. The world deserializer similarly uses `(core, reader)`
on the stack and `ret 8`. The player-enter/leave handlers use **ECX=reader**,
stack `network_client`, and `ret 4`. These are instruction-derived conventions,
not ordinary thiscall casts of the PDB declarations.

`close_current_match` uses ECX=`network_client`, one stack disconnect reason,
and `ret 4`. Reason 2 is `disconnected_by_initiator`. It clears game status,
builds `0x47`, appends a game-time dword, sends and flushes it, and enters the
existing match-close path. It returns immediately when game status is inactive;
cancellation during initial loading therefore needs separate investigation.
Do not replace it with a UDP disconnect alone or reuse `0x47` for snapshots.

The existing in-game options movie already exposes the leave route. Its native
handler, `game_options::scaleform_callback` (RVA `0x14dd31`), compares callback
name `menu_button` and first string argument `leave_match`. That branch obtains
`game->m_network_client` at `game+0x3684` and calls vtable offset `0x54` with
reason 2. For the network client this reaches `close_current_match` above.
The separate `logoff` action calls the broader disconnect path; it should not
be substituted for leaving a match.

The stock close path calls `game_world::on_finish_match` (RVA `0x14bd44`), which
calls `game_world::unload` (RVA `0x14b51c`) and then `game::switch_to_lobby` (RVA
`0x143fed`). The latter switches scenes only when its network predicate passes.
This establishes a reusable route through the existing options movie; it does
not yet prove the lobby remains usable with our server. Calling `menu_button`
on our patched lobby movie would reach a different native owner and is not an
equivalent way to invoke this operation.

For the first running-match test, use the original in-game Leave action and
verify that the other player continues playing, receives `0x57`, and can admit
the returning player. Only add a new UI/DLL leave entry point if the normal
route proves insufficient. The menu fixture's room Leave is a separate HTTP
operation and currently cannot leave a running game.

## Native snapshot probe and wire format

The isolated [native probe](../tests/native_snapshot_probe.c) calls the original
retail code without running the game entry point, rendering or networking. Its
[runner](../tools/run_native_snapshot_probe.py) checks the full executable SHA256
before building and running it. Wine can map the executable without applying
relocations; the probe applies its declared HIGHLOW relocations inside this
separate process before invoking native code. It does not change the input file.

Verified adapters:

| Routine | RVA | Actual calling convention |
| --- | --- | --- |
| History item constructor | `0x1edb18` | ESI=item; preserve the adapter caller's ESI |
| History item serializer | `0x1ede3e` | EAX=item; stack `(writer, active_mask)`; `ret 8` |
| History item deserializer | `0x1ee021` | Stack `(item, reader)`; `ret 8`; EAX=active mask |
| Event-horizon history lookup | `0x1bab13` | EAX=core; returns item in EAX; instruction inspection only |

With serialization-debug flags disabled, the serializer emits little-endian:

```text
u32 active_player_mask
for each active slot, in increasing slot order (0..19):
    u16 player_state_length
    byte[player_state_length] player_state
    byte has_animation_tree // 00=false, ff=true in retail output
    if present: native animation-tree serialization
u16 bullet_length;     byte[bullet_length] bullets
u16 statistics_length; byte[statistics_length] statistics
u16 objects_length;    byte[objects_length] objects
u16 rules_length;      byte[rules_length] rules
```

The **receive** form needs `u32 history_time_ms` before this output. The history
serializer does not emit that timestamp. The player's `client_specific_state`
buffer is omitted. An absent animation tree contributes one zero byte. The
present-tree branch has been located but has not been exercised by this probe.

On 2026-10-11, the probe passed under Wine 11.8 with masks `0`, `1`, `0x80000`,
`0x80001`, and `0xfffff`. It checked exact bytes, distinct first/last player
states, exclusion of private state, timestamp 50, consumption of the entire
input, returned mask, and restoration of all four world buffers. These are
synthetic history buffers, not a valid captured game world: this verifies the
ABI and framing, not full-world restore or network catch-up.

For live export, the event-horizon lookup uses the history head on a server
core; on a client core it looks up `max_current_time - event_horizon_interval`.
The selected item's timestamp, its corresponding historical membership mask,
and the subsequent input/membership stream must agree. Passing today's active
mask to an older history item would be incorrect. History selection and export
must happen on the simulation thread while those objects remain valid.

## Our initial snapshot hook and SRP1 framing

`SRP_MATCH_PROTOCOL=1` opts into `dll/native_match.c`. Initialization checks
the original instruction bytes before hooking `on_match_ready` and
`get_sending_message_info` (RVA `0x19144c`). Each trampoline copies seven bytes
covering complete instructions with no relative operands. The ready hook first calls the
original function, including player binding and the stock `0x42`, then exports
on the same thread. It does not replace the static setup or loading process.

The export deliberately accepts only history time **50 ms**, current active
mask zero, and a zero historical mask at or before that timestamp. It follows
at most 40 membership nodes. All four world buffers must have their original
inline storage/capacity, null allocator and bounded length. Debug serialization
must be disabled. The preflight computes the exact output size before invoking
the native serializer into a fixed 32 KiB buffer. The largest possible accepted
world payload is 21,004 bytes. Populated or later snapshots are rejected.

Client-to-server application message `0x48` has this body:

```text
byte[4] "SRP1"
u32_le history_time_ms
u16_le offset
u16_le total_serialized_size
byte[1..480] serialized_snapshot_slice
```

The assembled bytes start with the active-player mask; the timestamp is outside
that payload. The server prepends it when sending stock dynamic state `0x53`.
Delivery is reliable/unordered, channel 63, retry 500 ms/deviation 200 ms.
Each application message is at most 493 bytes including opcode and fits the
stock transport. The native `new_packet`, writer (RVA `0x145ebe`, stack
`writer,data,length`, `ret 12`) and enqueue path are reused.

The orderer hook is necessary: stock sending metadata indexes an unchecked
eight-entry jump table for `0x40`–`0x47`. The separate packet statistics array
has **ten** user entries relative to `0x40`, permitting `0x48` but not `0x4a`.
The hook handles only `0x48`, forwarding every stock opcode unchanged. No stock
Leave (`0x47`) or receive-side debug (`0x59`) meaning is changed. The opt-in flag
is a development agreement with our server. The menu allocation service now
checks the initialized DLL's `SRP1-48` HTTP capability claim before Start; this
does not add a negotiated UDP handshake or support other server dialects.

The native probe additionally verifies production export rejection guards,
maximum world buffers, all stock orderer results, the new metadata ABI, and
exact bytes in 44 fragments emitted through the original packet writer.

For integration without altering the server worker's checkout,
`tools/prepare_server_probe.py SOURCE OUTPUT` copies its dependency-free Rust
package into a new directory, records source hashes and applies two checked
edits. It adds `0x48` transport metadata and routes only `SRP1`-prefixed bodies
to the existing bounded assembler; stock `0x47` with four bytes removes the
peer. Unknown versions and unversioned/community uploads are rejected. This
is a disposable integration adapter, not the final combined server patch.
Build/test that isolated package with `cargo test --manifest-path OUTPUT/Cargo.toml`.
The preparer also enables CRC logging when adapting an older server which
discarded those notifications. It now refuses revisions whose coordinator
emits community `0x59` snapshot requests. The parallel server worker has added
that path since our tested copy was made; importing it requires our own receive
extension first. Do not regenerate from that newer source and assume the two
outgoing-message edits suffice. The tested copy and its input hash manifest
remain at `/tmp/srp-menu-server-021d-probe`.

On 2026-10-11 the isolated server received a **592-byte**, mask-zero snapshot
at time 50, CRC `1487c0c8`, from our patched retail client. It sent stock clock
reset, world restore and player entry (`0x52`, `0x53`, `0x56`). The game loaded
`level_02/rain`, completed its countdown, and accepted fire input: ammunition
decreased from 35 to 33 and the server logged the corresponding input actions.
The test used one client, its own local certificate, and no community binary.
This proves initial snapshot export/restore and single-client startup, not
running-world export, a second client's consistency, or menu-triggered admission.

The original Escape → Leave match → Quit action also ran. The client logged
`close_current_match [disconnected_by_initiator]`, the server removed slot 0,
and the client unloaded/reconnected and signed into the lobby again. The
bootstrap front door immediately redirected it into a fresh match: the same
process loaded again and uploaded a second identical initial snapshot. This
verifies the stock departure route and repeated startup, but **not** a stable
return to the match browser or rejoining a world that continued running.
The fixture's unconditional redirect must be replaced with menu admission.

Evidence: `/tmp/srp-021d-menu-run/srp-match-server.log`, `srp-front-door.log`,
`srp-match-loading.png`, `srp-match-fire.png`, and the client's `srp-client.log`.
The Leave sequence is preserved in `srp-match-game.log` and
`srp-match-leave-result.png` (confirmation); `srp-match-left.png` shows the fresh
match caused by the fixture's immediate redirect. All private test processes
were stopped after collecting these results. The isolated server's 26 unit
tests and the client's 10 Python tests passed. Tested DLL SHA256:
`013e2fd2d6f0ec175b69d3551b240fe9649a63ca76aea12d6b74856059952c8b`.

The later [two-client menu admission run](native-menu-integration.md#two-client-menu-admission-run)
verified Create/Join/Ready/Start, both initial uploads and restores, departure
while another player continued firing, and final allocation cleanup. It did
not exercise late joining, shared combat/death/respawn or ongoing state export.
Its CRC samples mostly had opposite 100 ms phases; only three exact timestamps
overlapped, with no disagreement among those three.

`try_send_all` at RVA `0x19310b` contains two 100 ms hash pacing checks at
`0x1931de` and `0x193216`, then selects an event-horizon item and writes stock
`0x46` as `(u32 time, u32 hash)`. The history item's cached hash is at `+0xb993c`
and its computed flag at `+0xb9940`. The optional `SRP_MATCH_HASH_STEP=1`
diagnostic now checks both five-byte instruction sequences before changing
only their immediate constants from 100 to 50. It requires
`SRP_MATCH_PROTOCOL=1`; the default retains stock pacing. The native probe
verifies both changes and rejection without mutation if the second guard fails.

The v12 two-client recheck used this diagnostic and compared 1,186 pairs at
identical timestamps from 100 through 60,150 ms, with no mismatch. Both clients
walked forward/backward and fired; after the first departure the remaining
client could still fire. This is evidence for that short deterministic run,
not validation of combat, recovery, late joining or every simulation step.
The server only logs these reports; it does not yet arbitrate disagreement.
See the [runtime recheck](native-menu-integration.md#v12-return-and-synchronization-recheck).

## Populated-snapshot output bounds

Further instruction inspection on 2026-10-11 found a reason not to relax the
bootstrap-only guard by simply passing a nonzero mask. Each player history item
has a 2,048-byte state buffer, a separate private buffer, an animation-tree
pointer at `+0x1050`, and 32,768 bytes of animation storage at `+0x1054`.
`player_history_item::serialize` (RVA `0x1fc18f`) writes the public state, the
presence byte and, when present, calls
`animation_player::serialize_state_and_compress` (RVA `0x23d2bb`). It does not
copy the animation storage as an already-framed wire buffer.

The compressed tree serializer (RVA `0x23e1ea`) takes a direct cursor into the
destination writer's remaining storage. Its bit append routine at RVA
`0x23d52a` writes through that cursor and clears the following byte when
advancing. That inspected routine does not check the stored end pointer before
those writes. The constructor commits the final byte count afterward. Merely
checking `buffer.size` after returning therefore cannot establish safe bounds
for a populated export. Its leading tree bit-length field is 16 bits; this is
not proof that every possible tree fits our current aggregate snapshot limit.

The bounded export prototype below guards the native tree writes, including
the final cleared byte. Export stays on the simulation thread and uses
historical membership.
The existing 32 KiB `SRP1` upload and adapter transport limits also need explicit
handling: even public player buffers alone can exceed that size at full roster
capacity. Reject an oversized snapshot before serialization/transmission;
do not silently truncate, widen fields independently or infer safety from the
small startup snapshots.

### Bounded export prototype and live capture

`dll/native_tree.c` installs a checked nine-byte trampoline at the bit append
routine. Only calls inside our thread-local export scope acquire output guards;
ordinary native serialization is forwarded unchanged. Before each append, the
guard checks the cursor, bit count, value width and space for the final cleared
byte. On overflow it records failure and suppresses subsequent bit writes while
letting the native serializer return and release its temporary references.
The wrapper reserves the three bytes touched directly by the constructor and
discards partial output on failure. It does not make malformed native tree
objects safe to traverse; callers must own a valid live history item.

`dll/native_snapshot.c` preflights the inline public player/world buffers,
emits the original framing, and uses that guard for each present tree. It
reserves the remaining player/world bytes before each tree call and caps the
body at 32,764 bytes so the timestamp fits the adapter's 32 KiB message limit.
The initial-only network upload remains unchanged.

The isolated probe checks byte equality with the retail serializer for a
synthetic present tree, a two-player body with present trees, and five masks
without trees. It places every undersized output immediately before a protected
page, checks normal failure and unchanged tree reference counts, and rejects
an aggregate body too large for the protocol. The minimal synthetic tree has
no animation nodes; the retail deserializer assumes a nonempty node list, so
that case is deliberately a serializer test, not a restore test.

`SRP_MATCH_CAPTURE=1`, together with `SRP_MATCH_PROTOCOL=1`, enables a diagnostic
hook at `try_send_all` (RVA `0x19310b`, EDI=network, stack=time/hash permission,
`ret 8`). Its adapter preserves registers/flags and tail-calls the original.
On the first eligible history at 2 and 10 seconds, it selects the event-horizon
item and its historical membership, then writes `srp-snapshot-2000.bin` and
`srp-snapshot-10000.bin` in the game's working directory using create-new mode.
Each file is a stock dynamic-state body: timestamp followed by the serialized
history. The diagnostic makes two capture attempts per process; it sends no
populated upload and performs no restore.

The 2026-10-11 real-client run captured:

| History time | Active mask | Complete bytes | Public player bytes | Animation bytes | World block lengths |
| --- | --- | --- | --- | --- | --- |
| 2,000 ms | `00001` | 1,310 | 550 | 143 | 16, 147, 160, 275 |
| 10,000 ms | `00001` | 1,307 | 550 | 140 | 16, 147, 160, 275 |

The server adapter's independent `state::inspect` accepted both complete
payloads. The client continued firing (35 to 33 rounds), then stock Leave
returned it to the empty browser and released the allocated server. This run
also exercised the new native protocol-capability admission check.
Tested DLL SHA256:
`cecbaee0a382dc92c6070235580ce0de7a1ea40c30d6083cf6af81e4f6cc389b`.

A separate experiment on the 2,000 ms capture successfully returned from native
history deserialization, consumed all 1,310 bytes, and recovered the expected
active mask and timestamp. Additional stage logging established that the fault
at RVA `0x23c8ac` in `animation_lexeme_parameters::create_animation_interval`
occurs during subsequent **reserialization**, not decoding. The decoded
animation intervals still have unresolved resource pointers. This verifies
decoding into a scratch history item, not restoration of a running world.
The experiment is retained under
`/tmp/srp-021d-investigation/*with-asset-restore-attempt.*`; this unsupported
standalone capture-restore option is not exposed by the normal probe runner.
The instrumented variant is `native-snapshot-probe-restore-stages.c` in the
same directory; its intentional reserialization attempt exits on the native
fault, so it is not a passing round-trip test.

Disassembly identifies `animation_player::resolve_links` at RVA `0x23cf99`
(491 bytes) as the resource-fixup candidate. Its LTO ABI takes the address of
the tree intrusive pointer in EAX, the animation-player pointer on the stack,
and returns with `ret 4`. It resolves object IDs through the player's callback
at `+0x100a0`, optional time-calculator IDs through `+0x10080`, and animation
resource IDs through `+0x10060`, then rebuilds intervals and event state.
This is not a context-free pointer relocation operation. The stock
`base_player::deserialize` call at RVA `0x1c652e` confirms that the animation
player is embedded at `base_player + 0x350`.

Evidence under `/tmp/srp-021d-menu-run/`: `tree-probe.log`, `capture-service.log`,
`capture-game.log`, `capture-game.png`, `capture-layout.txt`,
`captured-roundtrip-2000.log`, `captured-restore-stages-2000.log`, and
`captured-history-{2000,10000}.bin`.
The capture hashes respectively are
`3c3cdcf02fc6bb69c9ca18275c0f29c5f7d2384cf449e67545e1939889366111` and
`867a19b1ffeb104bdf86c64828eb8826ebb6429cf2545fd6f399e96ee35b6ac4`.
The private game, probe prefixes, display and service were stopped afterward.

### Loaded-game scratch round trip

`dll/native_roundtrip.c` adds a separate `SRP_MATCH_ROUNDTRIP=1` diagnostic,
enabled only alongside the protocol and capture flags. Before using native
functions it verifies the constructor, destructor, decoder and resolver entry
bytes. The capture hook passes only the trusted bytes it has just generated,
on the simulation thread. The diagnostic does not accept files or network
payloads as decoder input.

It verifies the loaded-player vector at `core + 0xc0a8`, each active slot's
player ID and resolver callbacks, constructs a temporary `0xb9954`-byte history
item, and decodes the timestamp-prefixed body. After checking the decoded mask,
timestamp and complete input consumption, it resolves each present scratch
tree against the corresponding loaded player's animation context. It then
uses the bounded serializer, compares the entire body, calls the native
history destructor and frees the temporary allocations. The live world's
history, membership and input stream are not replaced. Capture-file creation
failure does not prevent this in-memory diagnostic from running.

The 2026-10-11 single-client test entered a real match through the Scaleform
Create/Ready/Start flow. Both populated samples passed:

| History time | Decoded active mask | Reserialized body | Result |
| --- | --- | --- | --- |
| 2,000 ms | `00001` | 1,306 bytes | Identical to the complete original body |
| 10,000 ms | `00001` | 1,303 bytes | Identical to the complete original body |

Both scratch destructors returned. Movement and firing continued (29 rounds
remaining in the recorded screenshot); stock Leave returned to an empty
browser, and the allocation service deleted the room's session grants.
The standalone native serializer/bounds regression probe also passed after
linking the new module. The tested DLL SHA256 is
`13c9a42c52052c5fb42df12765ebfaaf5c007171daa87c3ddbe2e3355ca741c4`.

Evidence under `/tmp/srp-021d-menu-run/`: `roundtrip-game.log`,
`roundtrip-service.log`, `roundtrip-native-probe.log`, `roundtrip-game.png`,
`roundtrip-left.png`, and
`roundtrip-matches/263f3aca984d89a9-c7c0c071-1/server.log`.
The fresh capture hashes match the two earlier captures listed above.
This validates the resource-linking adapter for these populated trees in their
original loaded context. It does not validate different loadouts, remote-player
resolvers, applying state to a live world, or joining/rejoining a running match.
Those require a second client and the server's input/membership catch-up sequence.

### SRP requested snapshots and active recovery

The retail DLL now installs a guarded ten-byte hook at
`network_client::on_match_packet_received`, RVA `0x191520` (thiscall, network in
ECX, stack opcode/reader). Under `SRP_MATCH_PROTOCOL=1`, a server `0x59` whose
remaining body is exactly `53 52 50 31 01` requests a snapshot. The four-byte
prefix is `SRP1`, followed by command 1. All other stock traffic is forwarded;
an unknown command in that five-byte envelope is consumed and rejected. This
does not use the community client's bodyless request. A one-second throttle
bounds repeated requests; the adapted server normally requests every five seconds.

`srp_snapshot_current` selects the latest history at or before
`max_current_time - event_horizon_interval`, then finds the membership at that
history's timestamp. Native tests cover newer entries/current masks, cyclic
histories, underflow, stage/command rejection, the actual patched receive ABI,
bounded populated upload and throttling. Both capture and recovery use this
selection helper. The tree hook can be initialized again only for the same
module with its expected installed jump intact.

The DLL advertises `X-SRP-Match-Protocol: SRP1-48-R1` after initialization.
`lobby_fixture.py --require-recovery` requires that capability before admission.
`prepare_server_probe.py --recovery` creates an isolated copy of the current
server, changes its `0x59` request to the SRP envelope, accepts versioned `0x48`
uploads, and preserves stock `0x47` Leave. The source worker's checkout is not
modified. Capability headers remain a local compatibility claim, not client
attestation. Stock receive messages carry the clock, snapshot and replay data.

In the 2026-10-11 two-client run, both clients used the real menu to enter the
same allocated match on port 46479. Requested populated snapshots were accepted
as `Cached` with matching native hashes. After movement and firing, the local
test socket requested recovery for slot 1. The server restored client B from
client A's 50,100 ms state, acknowledged replay, and reported post-restore
agreement. There were 2,139 paired final CRC samples, with zero mismatches;
1,144 pairs were at least one second after the restore timestamp, spanning
51,100–108,700 ms. Both clients subsequently used stock Leave and returned to
the browser; the final departure deleted the session grants.

This is a successful active-world restore between two already loaded retail
clients with the fixed test roster. It does not prove late admission of an
unloaded player, reconnect, combat/death/respawn, or arbitrary loadouts. The
adapted server's 40 tests, the native probe, and actual WinHTTP capability test
passed. The Python menu suite passed 14 tests, with its unchanged optional
retail-loader test skipped in that invocation.

Evidence under `/tmp/srp-021d-menu-run/`: `recovery-game-{a,b}.log`,
`recovery-service.log`, `recovery-native-probe.log`, `recovery-http-smoke.log`,
`recovery-crc-report.json`, `recovery-restored-b.png`, and
`recovery-matches/bb0f42105a831833-48b2ade7-1/server.log`.
Tested DLL SHA256:
`3a13fc6479d0aaa85feec87bc35dda6fde393d4257256e8446ecd65b539c1d16`.
Adapted server SHA256:
`3581ccd718681586ad1bff353e0cbc98ad514ee11744cfe1365e7afbb00fc9e8`.
The hidden test clients/displays were stopped. At the user's request, a visible
demo was then opened with the local service left running.

## Admission timing and loaded players

`game_world_core::enter_match` at RVA `0x1bb9bd` uses stack `(core, slot, time)`
and `ret 12`. Instructions establish that:

- `time <= last_resync_time` returns 2 without inserting an event.
- On a client, `time + event_horizon_interval <= max_current_time` is also
  rejected as too old. These are unsigned comparisons in the native code.
- On a server core, an already-past event is moved to the next 50 ms boundary
  relative to `start_fixed_time`.
- A slot already active in the relevant membership history returns 4.

These checks have been read in instructions, not run in a live admission test.
In particular, restoring a snapshot and then scheduling entry at the same
timestamp is not sufficient. The server must choose a later admissible time
and account for the existing clients' history windows.

Player capacity is not the same as loaded membership. The core constructor at
RVA `0x1ba3ab` copies the supplied player references into `m_clients` (capacity
20, offset `0xc0a8`), then sizes per-player input histories from that loaded
count. `process_events` at RVA `0x1bc3a7` walks this loaded list when applying
enter/leave events. A new mask bit does not create a player object.

The player lookup at RVA `0x1baa65` performs a lower-bound search by player ID
and dereferences its result without checking for a missing ID. IDs, ordering,
loaded resources and input histories must therefore be consistent before
admitting anyone. `on_match_ready` binds the loaded players to the game and
establishes local-player identity; it is not a general add-player callback.

The first controlled test should preload two real player descriptors, start
with only one active, then admit the second later. That isolates synchronization
from loading an entirely new descriptor. It does not provide arbitrary public
late joining. Supporting that requires either descriptors agreed before loading
or our own resource-loading/binding operation on every existing client, including
their input histories, rendering and statistics state. Placeholder slots alone
do not establish support for a new identity or changed equipment.

## Implications and next checks

The retail client already has world-state restore and timestamped enter/leave
operations. This supports investigating a small patch around synchronization
and admission, but does **not** establish that arbitrary new players can join.

The static descriptor list is material: `process_static_match_info` loads
per-player descriptors, and `on_match_ready` loops over the loaded players to
bind them. A later `0x56` contains only ID and time, not a profile/loadout.
Determine whether existing clients require reserved preloaded slots or a new
descriptor/resource-loading operation before receiving an unknown player ID.

Next client-side experiments and integration questions:

1. Exercise snapshot export with a real history item, including animation-tree
   data, and its historical active-player mask. Restore it in a second loaded
   client. Preserve world history, object/weapon state, rules, scores and
   simulation time together; the synthetic probe does not satisfy this check.
2. Establish how a new client catches up from snapshot time to the server's
   current input stream. Define with the server worker the readiness barrier,
   buffered input interval and membership effective time; do not expose a
   client as active while its world is still loading.
3. Determine descriptor/slot reuse behavior on already-running clients. Test
   leave/rejoin with changed loadouts, stale inputs and delayed packets.
4. Trace the game/UI object path into the stock explicit-leave routine and the
   subsequent unload/lobby transition. Test voluntary leave while alive, dead,
   loading and reconnecting; retain the lobby session when appropriate.
5. Add only the hooks proven necessary, with exact-build guards and our own
   versioned extension if stock messages are insufficient. The server owns
   admission, membership and authoritative synchronization decisions.

Runtime acceptance remains two real clients: start a match, join it after
simulation has advanced, observe consistent players/world state, leave cleanly,
then rejoin without restarting either client. Menu-fixture tests cannot satisfy
this gate.

## Integrated server and late-admission boundary (2026-10-11)

The server worker has integrated the native DLL dialect as an explicit
`--protocol srp1` mode. Its common delivery boundary wraps both recovery and
final-statistics requests; the client menu no longer needs to rewrite server
source. `MatchProcess` selects SRP1 and checks the readiness announcement for
that selection. The isolated snapshot helper now copies source and tests
verbatim. The server's own `SRP1-INTEGRATION.txt` records a real native-menu
admission/results run, and its synthetic UDP tests cover SRP1 populated late
join with lost fragments and stock Leave. Those tests do not establish the
clean-retail two-client late-join acceptance gate above.

The current admission limitation is concrete:

- The server reads its session-to-slot grants once at startup. Its static
  roster size comes from that file; slots must be contiguous from zero.
- `Coordinator::admit` accepts an unused slot only within that existing roster.
  Static setup already supplies the fixed fixture descriptors for those slots.
- The menu writes grants only for players present at Start, and sets the
  starting cohort size to that same count. Spare room capacity therefore
  does not create any extra preloaded or authorized server slots.
- The local control socket currently supports status, results and test
  recovery controls. It does not register a new account's grant into a running
  server. Merely refreshing the grants file cannot change the in-memory map.

The next controlled client probe can preload two authenticated descriptors,
start with one required participant and route the other later. General menu
admission additionally needs an explicit account/slot registration contract.
It must confirm the server instance and generation, reject occupied or leased
slots, bind the authenticated account/session before redirect, expire failed
loads, and reject joins after finish. Retries must identify the same grant;
a lost control reply cannot allocate another slot. Departures must revoke the
appropriate grant without affecting other players. Capacity, descriptor and
loadout policy must be settled before an existing client receives a new active
slot. Pre-authorizing every lobby account on every match would bypass room
membership and is not a substitute for this contract.

`late_join` consequently remains false in menu capabilities and running rooms
still have no Join button. This is an outstanding implementation boundary,
not evidence that the native client needs another DLL hook. The server worker's
plan also records the user's combat acceptance; no repeat combat playtest is
required solely to collect additional telemetry.

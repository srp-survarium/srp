# Client hit-report patch

This patch injects a small DLL into the original 32-bit Survarium `0.100b`
client. It replaces the empty
`survarium::network_client::on_player_hit_received(hit_info const&)` vtable
entry and sends the locally detected player hit to the match server.

The patch is version-locked to this executable:

```text
size:      12235264 bytes
timestamp: 0x518e2ed6
sha256:    6cde21fac0fc508c140814c83d8a9d0158c0bff8f99c322cd7454c3d3103f737
```

The DLL also verifies the PE timestamp, image size, original vtable entry, and
the original bytes at both control-flow patch sites. It refuses to load instead
of patching an unknown client.

## Timer-free player control

SRP keeps the demo in a permanent warmup state and never sends
`GameStatusChanged(inprocess)`, because that transition starts the stock match
timer. The stock client normally attaches local controls only when that status
equals `inprocess`.

The DLL removes only that status check from the two attachment paths:

- `network_client::process_sync_response`, preferred VA `0x005c5ab4`;
- `network_client::process_player_respawn`, preferred VA `0x005c5c48`.

The surrounding guards remain intact: a player must still be local, alive,
time-synchronized, and not already attached. Each patch replaces a verified
nine-byte `cmp`/`jne` sequence with NOPs and restores it when the DLL unloads.
This makes initial spawn and later ten-second respawns controllable without
starting a round or its timer.

## Wire message

The synthetic client enum is:

```cpp
client_player_hit = 0x4b
```

The normal match protocol supplies the message opcode and ordered-message ID.
The payload is packed without alignment:

| Field | Type | Meaning |
|---|---:|---|
| `version` | `u8` | Payload version; currently `1` |
| `hit_initiator` | `u8` | Attacking player ID |
| `being_hit` | `u8` | Target player ID |
| `body_part_length` | `u8` | Number of following body-part bytes |
| `body_part` | bytes | Body-part name, without a terminator |
| `damage_type_length` | `u8` | Number of following damage-type bytes |
| `damage_type` | bytes | Damage type, without a terminator |
| `amount` | `f32 LE` | Client-computed pre-protection damage |
| `armor_piercing` | `f32 LE` | Client-computed armor piercing |

Only hits initiated by the locally controlled player are reported. The bullet
pointer in `hit_info` is process-local and is deliberately not serialized.

The report is untrusted input. SRP must validate all fields and turn accepted
reports into ordinary server messages such as `hit_player` (`0x89`).

Although the PDB describes the stock `hit_info::deserialize` player-ID reads as
`bool`, target disassembly confirms that `packet_reader::r<bool>` copies the raw
byte without normalization. Ordinary `hit_player` messages therefore preserve
all fixed-array player IDs `0..19`; no additional deserializer patch is needed.

## Build

Open a 32-bit Visual Studio developer prompt and run:

```bat
build.bat
```

This creates `build\srp_hit_report.dll` and
`build\srp_hit_report_loader.exe`.

## Run

Keep the loader and DLL together, then run:

```bat
srp_hit_report_loader.exe C:\path\to\survarium.exe [game arguments...]
```

The loader starts the client suspended, injects the DLL, and resumes the client
only after the patch installs successfully. Injection failure terminates the
still-suspended client.

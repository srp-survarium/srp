<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# SRP agent guide

SRP restores the server side of Survarium and currently works with the shipped
game client. The client-side artifacts available to this project are:

- the original Survarium executable;
- its debug symbols (PDB);
- the adjacent Vostok repository, which is a partial source reconstruction.

These artifacts serve different purposes. The shipped executable, PDB, and
target disassembly are authoritative for the current client. Vostok source is
useful for discovering names, types, layouts, and likely control flow, but it
may be incomplete or differ from the executable. Verify every address, calling
convention, object offset, vtable slot, and function body against the target
binary before using it in a patch or injected DLL.

The Vostok reconstruction is also the intended long-term client/engine source.
Changes that are appropriate for the final source-built engine should not be
confused with the binary patch or DLL used to demonstrate a feature against the
original executable.

## Client-reported damage demo

The original client already performs bullet collision and constructs
`survarium::hit_info` in both `survarium::player::hit` overloads. The resulting
object contains the hit initiator, target player, body-part name, damage type,
damage amount, and armor-piercing amount. Both overloads dispatch it through:

```cpp
network_client::on_player_hit_received(hit_info const&)
```

In the shipped client this virtual callback is empty, making its vtable slot a
useful seam for an injected DLL that reports the hit to SRP. Target
disassembly shows the call through the `network_client` vtable slot at offset
`0x30`; re-verify this for the exact executable being patched.

Do not detour the empty function body directly. Link-time identical-code folding
can make its `ret 4` body share an address with unrelated empty functions.
Patch the relevant vtable entry on the live `network_client` instance, replace
the class vtable slot with appropriate page protection, or patch the verified
call sites instead.

The demo uses the synthetic `client_player_hit` message (`0x4B`). Target
disassembly confirms that this client version assigns the same ordered,
reliable metadata to every outgoing match opcode, so the new value does not
require an additional packet-orderer patch. Re-verify that behavior for a
different executable.

The timer-free demo does not send `GameStatusChanged(inprocess)`. The injected
DLL therefore bypasses only the target-verified `m_game_status == inprocess`
guards in `network_client::process_sync_response` and
`network_client::process_player_respawn`; all local-player, alive, synchronized,
and already-attached guards remain. Do not reuse those addresses or byte
signatures for another executable without re-verification.

The target's `hit_info::deserialize` calls `packet_reader::r<bool>` for its two
player IDs, but that specialization copies the raw byte and does not normalize
it. The declared `u8` fields consequently retain IDs `0..19`; server
serialization should write the full bytes rather than deliberately reducing
them to booleans.

The match server must parse the report, associate the attacker with the sending
connection, update its demo damage state, and send the ordinary server damage
messages back to clients. Client-reported damage is intentionally untrusted and
demo-only until authoritative validation and synchronization are implemented.

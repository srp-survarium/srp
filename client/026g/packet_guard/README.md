<!-- SPDX-License-Identifier: GPL-3.0-or-later -->

# 0.26g packet guard: Rust integration draft

Incoming login, lobby and match validation, written in **`no_std` Rust** and
exposed as a C ABI static library. Compile with Rust, then link the archive from
the creator's C/C++ patcher. No game executable is modified or included.

**This is not complete client hardening.** Most lobby application schemas,
match-action semantics and snapshot block contents still need validators.
Missing schemas reject traffic; enabling the draft unchanged will prevent
normal lobby/match operation. Native hook installation and live client behavior
have not been tested. The source and build are ready for creator integration.

## Structure and safety boundary

- `src/`: safe Rust core with `#![no_std]` and `#![forbid(unsafe_code)]`. Parsing
  uses checked slices, typed errors, validated player counts, and borrowed frame
  bodies. Safe Rust callers cannot retain a reassembly response while mutating
  its storage.
- `src/compression.rs`: bounded raw-LZMA2 decoding using pinned
  [`lzma-rust2`](https://github.com/hasenbanck/lzma-rust2). All default features,
  including `std` and unsafe optimizations, are disabled. The decoder also
  forbids unsafe code in this configuration. It uses `alloc`; the dictionary
  is fixed at 32 KiB, the decoder memory limit is 256 KiB, and output is capped.
- `capi/`: the only unsafe implementation code. Converts C pointers to checked
  Rust slices, validates numeric discriminants, invokes schema callbacks and
  supplies a host allocator bridge. C pointers must still identify real, live,
  correctly sized, nonaliasing memory. Rust cannot prove those foreign promises.
- `guard.h`: C/C++ declarations. Opaque connection buffers expose size/alignment
  queries and explicit initializers. No Rust enums or references cross the ABI.
- `tests/validation.rs`: native-reference vectors and malformed-input tests.
  `tests/abi.c` tests calling Rust from C; it contains no packet parser.
- `verify_target.py`: development-only, read-only executable identifier.

Without default features, the Rust core uses **neither `std` nor `alloc`** and
has no dependencies. The complete static library includes the Rust decoder and
therefore needs the three host functions declared in `guard.h`:
`pg_host_alloc`, `pg_host_free`, and `pg_host_abort`. The allocator must honor
size/alignment and support concurrent calls. Abort must terminate, never return
or unwind. Builds use aborting panics; memory safety does not imply freedom from
logic bugs, panics, denial of service, or unsafe native-consumer behavior.

## Coverage

| Layer | Implemented checks | Still required |
| --- | --- | --- |
| Login TCP/TLS plaintext | Stage-specific opcode; exact 1/11/14-byte reply; session/address/port; bounded stream accumulation across partial/coalesced reads | TLS validation, phase transitions, deadlines; unknown replies reject |
| Lobby/match UDP | 512-byte maximum; ACK-tail bounds; direction/opcode; fixed/variable lengths; delivery/fragment metadata; ED/EE player masks and input count; whole-bundle validation | Connected peer, replay window, sequence/order/generation policy |
| Fragment assembly | Fixed storage; count/index/size; identity; duplicate/conflict detection; timeout including clock wrap; complete assembly | Bounded connection/slot table; reliable retransmission; reset on reconnect |
| E4 match setup | Bounded decompression; local slot; roster; strings; 3 profiles/69 items; slot references; 68-bit modifier mask; finite floats; dictionary-dependent item layout; extension counts; map; exact end | Trusted local dictionary/map callbacks; gameplay validity of scalar IDs beyond these bounds |
| E8 snapshots | Bounded decompression; mask; nested block lengths; animation bit counts, dictionary indices and finite float values; exact end | Schemas for player/world block contents, tree/value references and native destination capacities |
| Lobby `80` / `A1` | Sign-in exact size; squad count, commander, IDs, strings, flags and exact end | All other lobby schemas |
| Other match actions | Fixed size or ED/EE mask/length before callback | Action-specific indices, packed values, time/phase checks |

`state::envelope` / `pg_state_envelope` only inspect boundaries. They must **never
authorize dispatch**. Deep state validation always invokes a schema for every
block, the animation tree and the complete animation-value bitstream. Unknown
schemas default to rejection, including when C callback pointers are null.

The guard rejects `FE`: recovered framing accepts it but low-level dispatch
supports only `FA`–`FD`. Local SRP extensions `F7`/`F8` are not implemented by
this Skhid executable and are rejected too. Skhid repurposes `F6` to request a
snapshot upload; do not send its body to the retail debug decoder. The creator
must define that schema and a request-rate policy. Its outgoing `E0` snapshot
chunks are outside this incoming-traffic module.

Compatibility is intentionally strict: empty active names, noncontiguous active
slots, noncanonical boolean values, zero instance IDs and some login errors
reject. Review these choices against the creator's server before deployment.

## Integration

1. Feed login **plaintext** to `pg_login_feed` after TLS decryption, or during
   the initial name-response stage. On `PG_MORE`, retain state without calling
   native code. On `PG_OK`, copy the complete response into the native callback
   buffer, provide its verified size, then update the login stage before feeding
   any unconsumed bytes. On error close/reset. Never expose stale trailing bytes.
2. Lobby and match both use UDP in this build. Call `pg_udp` before the first
   native header/frame read. It checks the entire datagram and only publishes
   `written` on success. The returned frames are **transport-validated only**.
3. Reassemble fragmented bodies using `pg_reassemble` instead of native unchecked
   accumulation. Initialize opaque storage with `pg_reassembly_init` and keep
   one bounded slot per active delivery identity, peer and connection generation.
   Fragment zero must arrive first; early nonzero parts are dropped and need
   reliable retransmission. Pending is never permission to dispatch.
4. Run `pg_lobby` or `pg_match` on each complete body, excluding opcode/delivery
   bytes. E4 roster output is staged; commit it only after the whole transaction
   succeeds. Validate all application frames before dispatching any, using staged
   state for dependent frames. Callbacks must be pure and validate the entire
   slice, including nested fields and destination capacities.
5. Only application `PG_OK` permits the corresponding native consumer. Every
   other result blocks it. Keep checked bytes immutable through native use and
   preserve all borrowed-buffer lifetimes. Prefer passing validated expanded
   bytes directly to native object readers, bypassing their old decompressor.
   Serialize access to contexts and scratch, including during callbacks.

Do not use Rust safety as justification for passing unsupported bytes into old
native readers. It protects the validator; native consumers still require an
accurate schema. Do not replace an unsupported-schema callback with unconditional
success to make the client connect.

Reassembly reserves 130,560 data bytes per slot, plus metadata. Options scratch
is 358,560 bytes; state output is at most 32,768 bytes. Allocate large buffers
outside native callback stacks, and bound slot counts and work per connection.
Do not let speculative ACK/state updates escape a rejected bundle; stage them
or discard the connection on failure.

## Target and hook landmarks

The researched Skhid executable SHA-256 is:

```text
166d25bcc49f6e1b83fc0d85c25e822c85c7284d4d846143358ca2f28bd31ddf
```

`python3 verify_target.py /path/to/survarium_skhid.exe` identifies that exact
build and checks known modification bytes. It never installs hooks.

Addresses below are **research landmarks, not verified detour sites**. Preferred
image base is `0x10000`; resolve `module_base + preferred_VA - 0x10000`. Recover
the actual calling convention, displaced instructions, all call sites and safe
error exits before integration. Preserve Skhid's hooks at `0x27a505`/`0x27aea1`.

| Preferred VA | Role |
| --- | --- |
| `0x37fb10` / `0x37ff20` | Login/password callback and name-reply path; password response buffer is `this+0x2aa` |
| `0x3fa0a0` / `0x3fa240` | UDP header and shared message/fragment parsers |
| `0x3fdcf0` | Low-level dispatch |
| `0x26e370` / `0x26e390` | Lobby metadata/length selection |
| `0x275138` | Lobby dispatch table data, not a function entry |
| `0x26fab0` | Sign-in consumer |
| `0x274720` / `0x274e80` | Squad reader / A1 dispatch |
| `0x27a300` | Match dispatch |
| `0x27b880` / `0x1f0e70` | Static setup processing / options reader |
| `0x27bff0` / `0x324d80` | State-sync processing / snapshot reader |
| `0x3ee810` | Original LZMA2 decoder; not used by this Rust module |

## Build and verification

Run inside this directory with the project's pinned nightly toolchain:

```sh
cargo test -p srp-packet-guard --locked
cargo test -p srp-packet-guard --no-default-features --locked
cargo clippy --workspace --all-targets --locked -- -D warnings
cargo build -p srp-packet-guard-capi --release --locked
```

On Linux, exercise the C ABI and protected-page checks:

```sh
cc -std=c99 -Wall -Wextra -Werror -I . tests/abi.c \
  target/release/libsrp_packet_guard_capi.a -o /tmp/packet-guard-abi
/tmp/packet-guard-abi
```

For the 32-bit Windows client, install that target with your Rust toolchain or
build `core`/`alloc` from `rust-src` using nightly (the command used here):

```sh
cargo build -p srp-packet-guard-capi --release --locked \
  --target i686-pc-windows-msvc -Z build-std=core,alloc
```

Link `target/i686-pc-windows-msvc/release/srp_packet_guard_capi.lib` into a 32-bit
C/C++ project, supply the allocator/abort functions and include `guard.h`.
Native hooks still need to be implemented; this library contains none.

Tests cover 416 native-reference headers, 253 animations, two snapshots, options,
five compressed vectors, truncation sweeps, 120,000 random/mutated parser inputs
and 2,000 malformed compressed inputs. The C harness checks actual linkage,
context layout/lifetimes, callback rejection, invalid enums/null pointers and
input ending at an inaccessible page. AddressSanitizer is also run on the Rust
parser and decoder. Leak tracing is disabled in this ptrace-based environment.

Fixtures come from SRP's existing build-2777 research. Headers, compression and
options were checked against native retail routines; animations/snapshots are
from the school-state research. Retail SHA-256:
`ac33d9937015c2299bf62cc6b127cb308b48a3475b30fff2ddd65479ae3bf153`.
No original executable instructions, credentials or certificates are bundled.

Passing these tests does not certify native consumer safety. Before release,
complete the missing schemas and exercise the actual Windows hooks, legitimate
sessions, malformed traffic, TLS segmentation and reconnect/replay behavior.

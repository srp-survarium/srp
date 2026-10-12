<!-- SPDX-License-Identifier: GPL-3.0-or-later -->

# 0.26g client packet validation

The [Rust packet guard](../../client/026g/packet_guard/README.md) is a standalone
`no_std` integration module for login plaintext and lobby/match UDP traffic.
Its README records the exact researched Skhid executable hash, native parser
addresses, recovered field limits, supported schemas, and remaining gaps.

The framing parser accepts `FE`, although the recovered low-level dispatcher
handles only `FA`–`FD`. Skhid also repurposes `F6` for snapshot upload requests;
its body must not be passed into the retail compressed-debug-data reader.

The guard has no installed native hooks. Unsupported application schemas reject
traffic, and snapshot envelope checks alone do not establish safe native parsing.
Native-executable fuzzing is follow-up work, separate from this module's tests.

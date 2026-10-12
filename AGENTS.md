<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# SRP

SRP mocks the Survarium v0.100b protocol. Canned responses and dummy values are
intentional; authoritative game logic belongs to the C++ engine in vostok.

Use the pinned nightly toolchain and dependencies through `nix develop`.
Before committing, run `cargo build --workspace` and `cargo test --workspace`.
See `README.md` for setup and `docs/hosting.md` for server configuration.

- Use `vostok::serde` and `network_client` for little-endian wire data.
- Keep wire structs in `raw` modules with `snake_case` names, explicit `#[repr]`,
  and bytemuck `CheckedBitPattern` / `NoUninit`. Preserve game discriminants.
- Report client-visible protocol changes; the real client is the test oracle.
- Record reverse-engineering findings in `docs/notes/`.
- Start new files with `SPDX-License-Identifier: GPL-3.0-or-later`, followed by
  a blank line. Set `license.workspace = true` in new crates.

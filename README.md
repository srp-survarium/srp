<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# SRP - Survarium Restoration Project

0. Document how UDP low level networking works.
1. Write data structures for messages on 0.001b and 0.20e.
2. Completely parse .journal file for all messages expected by the server.
3. By that, figure out what the client excepts from us after sending `get_startup_info` and `team_bases_initialize_info`.


## License

The server implementations, Rust crates, tooling, patches, and documentation
contributed by this project are licensed under the
[GNU General Public License, version 3 or later](LICENSE), to the extent the
contributors can do so. Project source files carry a one-line
`SPDX-License-Identifier: GPL-3.0-or-later` tag, following the
[Vostok project](https://github.com/srp-survarium/vostok).

Survarium and the Vostok Engine remain the property of their rights holders.
The GPL covers only the contributors' work; it does not grant rights to the
original game code, assets, or other third-party material. In particular, the
shipped samples in `resources/binary-config-examples/`, the original instruction
listings in `resources/patches/*_og.asm`, the recorded `.journal` file in
`scripts/parse-journal-file/`, and the shipped certificates and keys in `certs/`
are not covered by this license. Reconstructed declarations and instruction
listings within project notes and patches retain their underlying rights; the
SPDX tags apply only to the contributors' work.

Third-party dependencies retain their own licenses. Locally supplied game
binaries and assets, and build outputs that incorporate them, are not covered
by this license.

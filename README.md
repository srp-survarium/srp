<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# SRP - Survarium Restoration Project



1. Continue parsing .journal files.
2. Figure out how low-level packages work.
3. Write working match server.

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

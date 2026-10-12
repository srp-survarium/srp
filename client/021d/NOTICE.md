<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# Dependency and asset notices

The original SRP client DLL, ActionScript, Python tools and tests use
GPL-3.0-or-later, as identified by their SPDX headers and the repository LICENSE.
Retail executable and game resources are user-supplied inputs. They are not
included in the source release and do not acquire the tooling's license.

## Archive tool

`vendor/resources-db` contains the GPL-3.0-or-later archive reader/writer by
sheepfleece / sushi-shi, including the resource porter's packer and overlay
support. Its upstream is `srp-survarium/vostok-resources-db`, imported revision
`104ef7b46437aee95a4b85611fd424e3f73c6c32`. This copy was taken from the clean
`deps/vostok-resources-db` directory at resource-porter revision
`4018438b609928c5f5d27980eae9fb4c02300dd8`. `IMPORT.json` records every imported
source fingerprint. The included LICENSE retains GPL-3.0-or-later terms.

Local changes give the package its own Cargo workspace and lockfile, add exact
single-member extraction with overwrite refusal, and update its documentation.
The overlay algorithm still verifies every untouched file's stored bytes after
writing an archive. Its preserved-payload and hard-link tests remain included.

The independent `Cargo.lock` pins the Rust dependencies. Direct dependencies
are bytemuck, bitflags and clap; their packages and transitive dependencies keep
their own license notices. Cargo fetches their sources when building. Any future
binary distribution must retain the relevant dependency notices and provide
corresponding source as required; this directory is a source distribution.

## Movie compiler

The movie patcher uses the external FFDec 26.0.0 distribution. The tested ZIP
fingerprint and build instructions are in README.md. FFDec and its bundled Java
libraries retain their own licenses. Keep the original distribution's license
files when provisioning or redistributing it. The repository contains our
AddMenu.java helper, not a repackaged FFDec distribution or proprietary game art.

## Native build

The DLL builds using MinGW-w64 and Windows import libraries; it does not use a
Scaleform SDK. Compiler/runtime dependencies retain their own license terms.
The build's source and toolchain inputs must accompany any future release
manifest; a locally generated DLL is not yet a public binary release.

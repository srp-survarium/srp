#!/usr/bin/env bash
# SPDX-License-Identifier: GPL-3.0-or-later
# Executable adapter for the native menu's unchanged positional launch API.
set -euo pipefail
script_dir="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
server_binary="${SRP021D_SERVER_BINARY:-$script_dir/../../../target/debug/match-server-021d}"
exec "$server_binary" --protocol srp1 "$@"

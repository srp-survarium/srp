<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# Hosting on your own server

Addresses are configured at runtime (see `vostok::config`). Each server binds
`127.0.0.1` by default, preserving the original local-only behavior. For a
single remote machine, explicitly bind all services to its interfaces and set
the routable host advertised to the client:

```bash
SRP_BIND_HOST=0.0.0.0 SRP_PUBLIC_HOST=your.public.host cargo run --bin lobby-server
# Run the other three servers with the same environment.
```

You can also put the addresses in a TOML file. Copy
[`server.example.toml`](../server.example.toml) to `server.toml`, edit it, and
select the same file for all four server processes:

```bash
SRP_CONFIG=server.toml cargo run --bin lobby-server
```

Top-level `bind_host` and `public_host` apply to all servers. The
`[browser_server]`, `[login_server]`, `[lobby_server]`, and `[match_server]`
tables each accept `bind_host`, `public_host`, and `port`; all fields and tables
are optional. For example:

```toml
bind_host = "0.0.0.0"
public_host = "your.public.host"

[match_server]
public_host = "match.example.com"
port = 4321
```

For each host, precedence is: per-server environment variable, shared
environment variable, per-server TOML value, shared TOML value, then
`127.0.0.1`. Ports use the per-server environment variable, then TOML value,
then the default below. Environment variables therefore override file settings.

No file is loaded unless `SRP_CONFIG` is set. Relative paths are resolved from
the process's working directory. An unreadable file, unknown key, malformed
TOML, or invalid field type stops startup with an error. Configuration is read
once on first use; restart each server after editing it.

Per-server overrides: `SRP_<SERVER>_{BIND,PUBLIC_HOST,PORT}` where `<SERVER>` is
`BROWSER`, `LOGIN`, `LOBBY`, or `MATCH`. The stock client always contacts the
browser service on public port 80 because login advertises only its host.
`SRP_BROWSER_PORT` therefore requires external forwarding from public port 80
to the configured bind port.

Open these ports to remote clients: **TCP** 1234 (login), 80 (browser), 1235
(lobby) and **UDP** 1236 (match).

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

Per-server overrides: `SRP_<SERVER>_{BIND,PUBLIC_HOST,PORT}` where `<SERVER>` is
`BROWSER`, `LOGIN`, `LOBBY`, or `MATCH`. The stock client always contacts the
browser service on public port 80 because login advertises only its host.
`SRP_BROWSER_PORT` therefore requires external forwarding from public port 80
to the configured bind port.

Open these ports to remote clients: **TCP** 1234 (login), 80 (browser), 1235
(lobby) and **UDP** 1236 (match).

<!-- SPDX-License-Identifier: GPL-3.0-or-later -->
# Hosting on your own server

Addresses are configured at runtime (see `vostok::config`). Each server binds
`0.0.0.0` by default; the chain advertises a **public host** to the client for
the next hop. For a single machine hosting everything, set its routable address
once:

```bash
SRP_PUBLIC_HOST=your.public.host cargo run --bin lobby-server   # ...and the others
```

Per-server overrides: `SRP_<SERVER>_{BIND,PUBLIC_HOST,PORT}` where `<SERVER>` is
`BROWSER`, `LOGIN`, `LOBBY`, or `MATCH`. With no env vars set, everything
defaults to `127.0.0.1` (the original local-only behaviour).

Open these ports to remote clients: **TCP** 1234 (login), 80 (browser), 1235
(lobby) and **UDP** 1236 (match).

// SPDX-License-Identifier: GPL-3.0-or-later
//! Runtime configuration for the four mock servers.
//!
//! Historically every address was a hardcoded `127.0.0.1` constant, which meant
//! the mock could only be reached over loopback. To host it on a real machine we
//! need two independent notions per server:
//!
//! * **bind** — the local interface/port the server listens on. It defaults to
//!   `127.0.0.1`; set it to `0.0.0.0` (all interfaces) for a remote-reachable
//!   deployment.
//! * **public host** — the address handed to the *client* so it knows where to
//!   connect next (login → browser → lobby → match). This must be a host the
//!   client can actually route to (e.g. the VPS's public IP/DNS name), which is
//!   generally **not** the bind address.
//!
//! Everything is read from the environment once, lazily, via [`get`]. Defaults
//! reproduce the old localhost behaviour, so the local dev workflow is unchanged
//! when no env vars are set.
//!
//! ## Environment variables
//!
//! * `SRP_BIND_HOST` / `SRP_PUBLIC_HOST` — bind/public hosts applied to **all**
//!   servers (the common case: one machine hosting everything). Both default to
//!   `127.0.0.1`.
//! * Per-server overrides (take precedence over the shared values):
//!   `SRP_<SERVER>_BIND`, `SRP_<SERVER>_PUBLIC_HOST`, `SRP_<SERVER>_PORT`
//!   where `<SERVER>` is one of `BROWSER`, `LOGIN`, `LOBBY`, `MATCH`.
//!   The stock client always reaches the browser on public port 80, so
//!   `SRP_BROWSER_PORT` is only useful with external port forwarding.
//!
//! Example — host the mock on a VPS whose public DNS is `srp.example.com`:
//! ```text
//! SRP_BIND_HOST=0.0.0.0 SRP_PUBLIC_HOST=srp.example.com cargo run --bin lobby-server
//! ```

use std::sync::OnceLock;

/// Address configuration for a single server.
pub struct ServerConfig {
    /// Local interface to bind/listen on (e.g. `0.0.0.0`).
    pub bind_host: String,
    /// Host advertised to the client so it can connect here next.
    pub public_host: String,
    pub port: u16,
}

impl ServerConfig {
    /// `bind_host:port` — pass to `TcpListener::bind` / `UdpSocket::bind`.
    pub fn bind_addr(&self) -> String {
        format!("{}:{}", self.bind_host, self.port)
    }

    /// `public_host:port` — what we tell the client to connect to.
    pub fn public_addr(&self) -> String {
        format!("{}:{}", self.public_host, self.port)
    }
}

pub struct Config {
    pub browser_server: ServerConfig,
    pub login_server: ServerConfig,
    pub lobby_server: ServerConfig,
    pub match_server: ServerConfig,
}

/// Default public host when `SRP_PUBLIC_HOST` is unset — preserves the original
/// loopback-only behaviour for local development.
const DEFAULT_PUBLIC_HOST: &str = "127.0.0.1";
/// Default bind host — preserves the original local-only behaviour. Remote
/// hosting must be opted into explicitly.
const DEFAULT_BIND_HOST: &str = "127.0.0.1";

impl Config {
    /// Build the config from the environment (see module docs). Called once by
    /// [`get`]; reads `std::env` so it must run after the process has its env.
    pub fn from_env() -> Self {
        Self::from_lookup(|name| std::env::var(name).ok())
    }

    fn from_lookup(mut lookup: impl FnMut(&str) -> Option<String>) -> Self {
        let shared_bind_host =
            lookup("SRP_BIND_HOST").unwrap_or_else(|| DEFAULT_BIND_HOST.to_string());
        let shared_public_host =
            lookup("SRP_PUBLIC_HOST").unwrap_or_else(|| DEFAULT_PUBLIC_HOST.to_string());

        let mut server = |name: &str, default_port: u16| ServerConfig {
            bind_host: lookup(&format!("SRP_{name}_BIND"))
                .unwrap_or_else(|| shared_bind_host.clone()),
            public_host: lookup(&format!("SRP_{name}_PUBLIC_HOST"))
                .unwrap_or_else(|| shared_public_host.clone()),
            port: lookup(&format!("SRP_{name}_PORT"))
                .map(|p| p.parse().expect("SRP_*_PORT must be a u16"))
                .unwrap_or(default_port),
        };

        Self {
            browser_server: server("BROWSER", 80),
            login_server: server("LOGIN", 1234),
            lobby_server: server("LOBBY", 1235),
            match_server: server("MATCH", 1236),
        }
    }
}

/// Process-wide configuration, initialised from the environment on first use.
pub fn get() -> &'static Config {
    static CONFIG: OnceLock<Config> = OnceLock::new();
    CONFIG.get_or_init(Config::from_env)
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::collections::HashMap;

    #[test]
    fn defaults_remain_local_only() {
        let config = Config::from_lookup(|_| None);
        assert_eq!(config.login_server.bind_addr(), "127.0.0.1:1234");
        assert_eq!(config.login_server.public_addr(), "127.0.0.1:1234");
    }

    #[test]
    fn shared_hosts_and_per_server_overrides_are_applied() {
        let values = HashMap::from([
            ("SRP_BIND_HOST", "0.0.0.0"),
            ("SRP_PUBLIC_HOST", "srp.example.com"),
            ("SRP_MATCH_BIND", "127.0.0.2"),
            ("SRP_MATCH_PORT", "4321"),
        ]);
        let config = Config::from_lookup(|name| values.get(name).map(ToString::to_string));

        assert_eq!(config.login_server.bind_addr(), "0.0.0.0:1234");
        assert_eq!(config.login_server.public_addr(), "srp.example.com:1234");
        assert_eq!(config.match_server.bind_addr(), "127.0.0.2:4321");
        assert_eq!(config.match_server.public_addr(), "srp.example.com:4321");
    }
}

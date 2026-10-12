// SPDX-License-Identifier: GPL-3.0-or-later
//! Server addresses, read once from `SRP_*` environment variables by [`get`].
//!
//! Bind hosts select local interfaces; public hosts are advertised to clients.
//! Both default to `127.0.0.1`. See `docs/hosting.md` for overrides and setup.

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

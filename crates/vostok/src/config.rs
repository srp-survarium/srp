// SPDX-License-Identifier: GPL-3.0-or-later
//! Server addresses, read once from TOML and `SRP_*` environment variables by [`get`].
//!
//! Bind hosts select local interfaces; public hosts are advertised to clients.
//! Both default to `127.0.0.1`. See `docs/hosting.md` for overrides and setup.

use std::sync::OnceLock;

use ::serde::Deserialize;

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

#[derive(Default, Deserialize)]
#[serde(default, deny_unknown_fields)]
struct FileConfig {
    bind_host: Option<String>,
    public_host: Option<String>,
    browser_server: ServerOverrides,
    login_server: ServerOverrides,
    lobby_server: ServerOverrides,
    match_server: ServerOverrides,
}

#[derive(Default, Deserialize)]
#[serde(default, deny_unknown_fields)]
struct ServerOverrides {
    bind_host: Option<String>,
    public_host: Option<String>,
    port: Option<u16>,
}

/// Default public host when `SRP_PUBLIC_HOST` is unset — preserves the original
/// loopback-only behaviour for local development.
const DEFAULT_PUBLIC_HOST: &str = "127.0.0.1";
/// Default bind host — preserves the original local-only behaviour. Remote
/// hosting must be opted into explicitly.
const DEFAULT_BIND_HOST: &str = "127.0.0.1";

impl Config {
    /// Load the optional TOML file selected by `SRP_CONFIG`, then apply environment
    /// overrides. An unreadable or invalid selected file stops startup.
    pub fn from_env() -> Self {
        let file = std::env::var_os("SRP_CONFIG")
            .map(|path| {
                let path = std::path::PathBuf::from(path);
                let text = std::fs::read_to_string(&path)
                    .unwrap_or_else(|error| panic!("Cannot read {}: {error}", path.display()));
                toml::from_str(&text)
                    .unwrap_or_else(|error| panic!("Invalid config {}: {error}", path.display()))
            })
            .unwrap_or_default();
        Self::from_lookup(file, |name| std::env::var(name).ok())
    }

    fn from_lookup(file: FileConfig, mut lookup: impl FnMut(&str) -> Option<String>) -> Self {
        let shared_bind_host = lookup("SRP_BIND_HOST");
        let shared_public_host = lookup("SRP_PUBLIC_HOST");

        let mut server = |name: &str, overrides: ServerOverrides, default_port: u16| ServerConfig {
            bind_host: lookup(&format!("SRP_{name}_BIND"))
                .or_else(|| shared_bind_host.clone())
                .or(overrides.bind_host)
                .or_else(|| file.bind_host.clone())
                .unwrap_or_else(|| DEFAULT_BIND_HOST.to_string()),
            public_host: lookup(&format!("SRP_{name}_PUBLIC_HOST"))
                .or_else(|| shared_public_host.clone())
                .or(overrides.public_host)
                .or_else(|| file.public_host.clone())
                .unwrap_or_else(|| DEFAULT_PUBLIC_HOST.to_string()),
            port: lookup(&format!("SRP_{name}_PORT"))
                .map(|p| {
                    p.parse()
                        .unwrap_or_else(|error| panic!("Invalid SRP_{name}_PORT: {error}"))
                })
                .or(overrides.port)
                .unwrap_or(default_port),
        };

        Self {
            browser_server: server("BROWSER", file.browser_server, 80),
            login_server: server("LOGIN", file.login_server, 1234),
            lobby_server: server("LOBBY", file.lobby_server, 1235),
            match_server: server("MATCH", file.match_server, 1236),
        }
    }
}

/// Process-wide configuration, initialised from file and environment on first use.
pub fn get() -> &'static Config {
    static CONFIG: OnceLock<Config> = OnceLock::new();
    CONFIG.get_or_init(Config::from_env)
}

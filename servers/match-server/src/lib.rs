#![feature(iter_intersperse)]
// SPDX-License-Identifier: GPL-3.0-or-later

mod game;
mod match_server;
mod message;
mod sequence_number;
mod transport;
mod utils;

use std::sync::Arc;

use session::SessionStore;
use vostok::config;

use crate::match_server::MatchServer;

/// Run the match server: bind UDP and drive the relay loop forever (it never
/// returns). Panics are contained by the caller (the standalone `main`, or the
/// `srp` supervisor thread), which restarts it.
pub fn run(store: Arc<SessionStore>) -> std::io::Result<()> {
    let match_server = &config::get().match_server;
    let addr = format!("{}:{}", match_server.bind_host, match_server.port);
    MatchServer::bind(&addr, store)?.run()
}

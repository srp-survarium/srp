//! Unified mock server: runs the login, browser, lobby and match servers in
//! **one process** sharing a single [`SessionStore`], so a client signed in at
//! the login server is recognised by the lobby, and the match it was routed to is
//! recognised by the match server (see PLAN Phases 2–4).
//!
//! Each server runs on its own supervised thread: a panic or error in one is
//! logged and the server is restarted, so no single server can take down the
//! whole process.

mod logger;

use std::panic::AssertUnwindSafe;
use std::sync::Arc;
use std::thread;
use std::time::Duration;

use log::LevelFilter;
use session::SessionStore;

/// Delay before restarting a server that exited, to avoid a hot crash loop.
const RESTART_DELAY: Duration = Duration::from_secs(1);

type Run = fn(Arc<SessionStore>) -> std::io::Result<()>;

fn main() {
    // A single level from RUST_LOG (e.g. `RUST_LOG=debug`), defaulting to info.
    let level = std::env::var("RUST_LOG")
        .ok()
        .and_then(|value| value.parse().ok())
        .unwrap_or(LevelFilter::Info);
    logger::init(level).expect("failed to install logger");

    let store = Arc::new(SessionStore::new());

    let servers: [(&str, Run); 4] = [
        ("login", login_server::run),
        ("browser", browser_server::run),
        ("lobby", lobby_server::run),
        ("match", match_server::run),
    ];

    let handles: Vec<_> = servers
        .into_iter()
        .map(|(name, run)| {
            let store = store.clone();
            thread::Builder::new()
                .name(name.to_string())
                .spawn(move || supervise(name, store, run))
                .expect("failed to spawn server thread")
        })
        .collect();

    log::info!("srp: started login, browser, lobby and match servers");

    for handle in handles {
        let _ = handle.join();
    }
}

/// Run one server forever, restarting it (after a short delay) if it returns or
/// panics. Keeps a crashing server from bringing down the others.
fn supervise(name: &str, store: Arc<SessionStore>, run: Run) {
    loop {
        let store = store.clone();
        match std::panic::catch_unwind(AssertUnwindSafe(|| run(store))) {
            Ok(Ok(())) => log::warn!("{name} server exited; restarting"),
            Ok(Err(error)) => log::error!("{name} server failed: {error}; restarting"),
            Err(_) => log::error!("{name} server panicked; restarting"),
        }
        thread::sleep(RESTART_DELAY);
    }
}

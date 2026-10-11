// SPDX-License-Identifier: GPL-3.0-or-later
use std::sync::Arc;

use session::SessionStore;

fn main() {
    env_logger::init();

    // Standalone: restart on panic, mirroring the srp supervisor.
    loop {
        log::info!("Starting a match server");
        let store = Arc::new(SessionStore::new());
        match std::panic::catch_unwind(|| match_server::run(store)) {
            Ok(Ok(())) => log::warn!("Match server exited; restarting"),
            Ok(Err(error)) => log::error!("Match server failed: {error}; restarting"),
            Err(_) => log::error!("Match server panicked; restarting"),
        }
        std::thread::sleep(std::time::Duration::from_secs(1));
    }
}

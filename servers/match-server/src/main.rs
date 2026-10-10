// SPDX-License-Identifier: GPL-3.0-or-later
use std::sync::Arc;

use session::SessionStore;

fn main() {
    env_logger::init();

    // Standalone: restart on panic, mirroring the srp supervisor.
    loop {
        log::info!("Starting a match server");
        let store = Arc::new(SessionStore::new());
        if std::panic::catch_unwind(|| match_server::run(store)).is_err() {
            log::error!("Match server panicked; restarting");
        }
    }
}

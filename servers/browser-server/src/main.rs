// SPDX-License-Identifier: GPL-3.0-or-later
use std::sync::Arc;

use session::SessionStore;

fn main() -> std::io::Result<()> {
    env_logger::init();
    browser_server::run(Arc::new(SessionStore::new()))
}

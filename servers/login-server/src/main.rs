use std::sync::Arc;

use session::SessionStore;

fn main() -> std::io::Result<()> {
    env_logger::init();
    login_server::run(Arc::new(SessionStore::new()))
}

// SPDX-License-Identifier: GPL-3.0-or-later
//! A `log` backend that fans records out to **one file per server** (plus
//! stdout), so the unified process stays as inspectable as the old one-tab-per-
//! server setup.
//!
//! Each record is routed by its `target()` — the `log!` macros default the target
//! to the module path, which starts with the originating crate name
//! (`login_server`, `lobby_server`, `browser_server`, …). actix's own logs
//! (target `actix*`) are folded into the browser server's file. Anything else
//! (including this `srp` orchestrator) goes to `srp.log`.
//!
//! The bootstrap scripts open a tab per `logs/<server>.log` and tail it, so logs
//! remain separable even though everything runs in one process.

use std::collections::HashMap;
use std::fs::{File, OpenOptions};
use std::io::{self, Write};
use std::sync::Mutex;

use log::{LevelFilter, Log, Metadata, Record};

const SERVERS: [&str; 5] = ["login", "lobby", "browser", "match", "srp"];

struct FileLogger {
    level: LevelFilter,
    files: HashMap<&'static str, Mutex<File>>,
}

/// Install the file-routing logger. `level` is the maximum level emitted; the
/// `logs/` directory and one `<server>.log` per server are created/appended.
pub fn init(level: LevelFilter) -> io::Result<()> {
    std::fs::create_dir_all("logs")?;

    let mut files = HashMap::new();
    for name in SERVERS {
        let file = OpenOptions::new()
            .create(true)
            .append(true)
            .open(format!("logs/{name}.log"))?;
        files.insert(name, Mutex::new(file));
    }

    log::set_max_level(level);
    log::set_boxed_logger(Box::new(FileLogger { level, files }))
        .map_err(|error| io::Error::new(io::ErrorKind::Other, error))
}

/// Which server's log a record belongs to, decided from its target prefix.
fn server_for_target(target: &str) -> &'static str {
    if target.starts_with("login_server") {
        "login"
    } else if target.starts_with("lobby_server") || target.starts_with("messaging") {
        "lobby"
    } else if target.starts_with("browser_server") || target.starts_with("actix") {
        "browser"
    } else if target.starts_with("match_server") {
        "match"
    } else {
        "srp"
    }
}

impl Log for FileLogger {
    fn enabled(&self, metadata: &Metadata) -> bool {
        metadata.level() <= self.level
    }

    fn log(&self, record: &Record) {
        if !self.enabled(record.metadata()) {
            return;
        }

        let server = server_for_target(record.target());
        let level = record.level();
        let args = record.args();

        // stdout keeps a combined view (prefixed with the server) ...
        println!("[{server}] [{level}] {args}");

        // ... while each server's file holds only its own lines.
        if let Some(file) = self.files.get(server) {
            let _ = writeln!(file.lock().unwrap(), "[{level}] {args}");
        }
    }

    fn flush(&self) {
        for file in self.files.values() {
            let _ = file.lock().unwrap().flush();
        }
    }
}

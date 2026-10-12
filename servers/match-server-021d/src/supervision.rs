// SPDX-License-Identifier: GPL-3.0-or-later
//! A pipe held only by the menu service ties a native child to its supervisor.
use std::{
    io::Read,
    path::PathBuf,
    sync::{
        Arc,
        atomic::{AtomicBool, Ordering},
    },
};

pub struct Supervisor {
    gone: Arc<AtomicBool>,
    grants: PathBuf,
}

impl Supervisor {
    pub fn watch(grants: PathBuf) -> std::io::Result<Self> {
        let gone = Arc::new(AtomicBool::new(false));
        let flag = gone.clone();
        std::thread::Builder::new()
            .name("supervisor-pipe".into())
            .spawn(move || {
                let mut input = std::io::stdin().lock();
                let mut byte = [0];
                loop {
                    match input.read(&mut byte) {
                        Ok(0) => break,
                        Ok(_) => {}
                        Err(e) if e.kind() == std::io::ErrorKind::Interrupted => continue,
                        Err(_) => break,
                    }
                }
                flag.store(true, Ordering::Release);
            })?;
        Ok(Self { gone, grants })
    }

    pub fn gone(&self) -> bool {
        self.gone.load(Ordering::Acquire)
    }
}

impl Drop for Supervisor {
    fn drop(&mut self) {
        let _ = std::fs::remove_file(&self.grants);
    }
}

// SPDX-License-Identifier: GPL-3.0-or-later
//! Optional local lifecycle queries and test controls, never game messages.
use std::{
    fs, io,
    os::unix::{
        fs::PermissionsExt,
        net::{SocketAddr, UnixDatagram},
    },
    path::PathBuf,
};

pub struct Control {
    socket: UnixDatagram,
    path: PathBuf,
}
pub enum Command {
    Recover(u8),
    Blackout(u8, u64),
    StateBlackout(u8, u64),
    Status(u64, SocketAddr),
    Results(u64, u64, u8, SocketAddr),
}
impl Control {
    pub fn bind(path: PathBuf) -> io::Result<Self> {
        let socket = UnixDatagram::bind(&path)?;
        fs::set_permissions(&path, fs::Permissions::from_mode(0o600))?;
        socket.set_nonblocking(true)?;
        Ok(Self { socket, path })
    }
    pub fn poll(&self) -> Vec<Command> {
        let mut out = vec![];
        let mut buffer = [0; 65];
        for _ in 0..8 {
            let (size, source) = match self.socket.recv_from(&mut buffer) {
                Ok(received) => received,
                Err(e) if e.kind() == io::ErrorKind::WouldBlock => break,
                Err(e) => {
                    eprintln!("test control receive error: {e}");
                    break;
                }
            };
            let command = (|| {
                if size > 64 {
                    return None;
                }
                let fields: Vec<_> = std::str::from_utf8(&buffer[..size])
                    .ok()?
                    .split_whitespace()
                    .collect();
                match fields.as_slice() {
                    ["status", nonce] => Some(Command::Status(nonce.parse().ok()?, source)),
                    ["results", nonce, generation, slot] => Some(Command::Results(
                        nonce.parse().ok()?,
                        generation.parse().ok()?,
                        slot.parse().ok()?,
                        source,
                    )),
                    ["recover", slot] => Some(Command::Recover(slot.parse().ok()?)),
                    [kind @ ("blackout" | "state-blackout"), slot, ms] => {
                        let ms: u64 = ms.parse().ok()?;
                        let slot = slot.parse().ok()?;
                        (ms > 0 && ms <= 5000).then_some(if *kind == "blackout" {
                            Command::Blackout(slot, ms)
                        } else {
                            Command::StateBlackout(slot, ms)
                        })
                    }
                    _ => None,
                }
            })();
            if let Some(command) = command {
                out.push(command);
            } else {
                eprintln!(
                    "invalid local control; expected status NONCE, recover SLOT or [state-]blackout SLOT MILLISECONDS (1..5000)"
                );
            }
        }
        out
    }

    pub fn reply(&self, source: &SocketAddr, body: &str) -> io::Result<()> {
        self.socket
            .send_to_addr(body.as_bytes(), source)
            .map(|_| ())
    }
}
impl Drop for Control {
    fn drop(&mut self) {
        let _ = fs::remove_file(&self.path);
    }
}

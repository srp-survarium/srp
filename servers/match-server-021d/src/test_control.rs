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
    Admission(match_server_021d::admission::Change, SocketAddr),
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
        let mut buffer = [0; 193];
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
                if size > 192 {
                    return None;
                }
                let fields: Vec<_> = std::str::from_utf8(&buffer[..size])
                    .ok()?
                    .split_whitespace()
                    .collect();
                match fields.as_slice() {
                    [
                        kind @ ("admit" | "revoke"),
                        revision,
                        instance,
                        generation,
                        slot,
                        account,
                        session,
                    ] => Some(Command::Admission(
                        match_server_021d::admission::Change {
                            grant: *kind == "admit",
                            revision: revision.parse().ok()?,
                            instance: u128::from_str_radix(instance, 16).ok()?,
                            generation: generation.parse().ok()?,
                            slot: slot.parse().ok()?,
                            account: account.parse().ok()?,
                            session: session.parse().ok()?,
                        },
                        source,
                    )),
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

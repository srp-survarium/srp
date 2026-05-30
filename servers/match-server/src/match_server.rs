// Multi-client match server: a dumb relay.
//
// SRP is a mock — this does NOT simulate the game. It owns one UDP socket,
// demultiplexes datagrams to a per-peer `Transport` (reliable-UDP), and:
//   * runs each client through the connect/startup/join handshake, reflecting the
//     live roster (one `PlayerProfile`/`SpawnPlayer` per connected peer), and
//   * relays each client's `ClientPlayerUpdate` to every OTHER peer as a
//     `ServerPlayerInput`, so players see each other move.
//
// It is explicitly not authoritative: nothing validates or reconciles the data,
// it is forwarded as-is. Roster handling is best-effort (see WORK.md) — the clean
// case is clients connecting before either readies up; late joins may render
// imperfectly and need in-game iteration.

use std::collections::HashMap;
use std::io;
use std::net::{SocketAddr, UdpSocket};
use std::sync::Arc;
use std::time::{Duration, Instant};

use session::SessionStore;
use survarium::player_input::weapon_state;
use survarium::player_profile::raw::game_team_id;

use crate::game;
use crate::message::ClientGameMessageKind;
use crate::message::ServerGameMessageKind;
use crate::message::server_message::raw::game_status;
use crate::transport::Transport;

const FRAMES_PER_SECOND: u64 = 120;
const FRAME_DURATION: Duration = Duration::from_millis(1000 / FRAMES_PER_SECOND);
/// Client tracks `m_net_players[20]`, so at most 20 player ids.
const MAX_PLAYERS: u8 = 20;

struct Peer {
    transport: Transport,
    /// `false` until the peer's `ConnectionRequest` assigns it a player id.
    registered: bool,
    player_id: u8,
    team: game_team_id,
    name: String,
    /// `true` once the peer has sent `JoinMatch` (is in the match).
    joined: bool,
}

impl Peer {
    fn new() -> Self {
        Self {
            transport: Transport::new(),
            registered: false,
            player_id: 0,
            team: game_team_id::team_1,
            name: String::new(),
            joined: false,
        }
    }
}

pub struct MatchServer {
    socket: UdpSocket,
    store: Arc<SessionStore>,
    peers: HashMap<SocketAddr, Peer>,
    next_player_id: u8,
}

impl MatchServer {
    pub fn bind(addr: &str, store: Arc<SessionStore>) -> io::Result<Self> {
        let socket = UdpSocket::bind(addr)?;
        socket.set_nonblocking(true)?;
        Ok(Self {
            socket,
            store,
            peers: HashMap::new(),
            next_player_id: 0,
        })
    }

    /// The address the relay is bound to (used by tests to find the ephemeral port).
    pub fn local_addr(&self) -> io::Result<SocketAddr> {
        self.socket.local_addr()
    }

    /// Run the relay loop forever (never returns; panics are contained by the
    /// caller's supervisor).
    pub fn run(mut self) -> ! {
        let mut buf = [0u8; 2048];
        loop {
            let frame_start = Instant::now();

            // Drain everything available this frame.
            loop {
                match self.socket.recv_from(&mut buf) {
                    Ok((len, addr)) => self.handle_datagram(addr, buf[..len].to_vec()),
                    Err(error) if error.kind() == io::ErrorKind::WouldBlock => break,
                    Err(error) => {
                        log::error!("recv_from failed: {error}");
                        break;
                    }
                }
            }

            self.reap_disconnected();

            // Keepalives.
            let socket = &self.socket;
            for (addr, peer) in self.peers.iter_mut() {
                peer.transport.maintain(socket, *addr);
            }

            if let Some(remaining) = FRAME_DURATION.checked_sub(frame_start.elapsed()) {
                std::thread::sleep(remaining);
            }
        }
    }

    fn handle_datagram(&mut self, addr: SocketAddr, datagram: Vec<u8>) {
        let peer = self.peers.entry(addr).or_insert_with(Peer::new);
        let messages = peer.transport.handle_datagram(&datagram, &self.socket, addr);
        for message in messages {
            self.handle_game_message(addr, message);
        }
    }

    fn handle_game_message(&mut self, from: SocketAddr, message: ClientGameMessageKind) {
        match message {
            ClientGameMessageKind::ConnectionRequest { session_id } => {
                self.register_peer(from, session_id);
            }

            ClientGameMessageKind::GetStartupInfo => {
                // Tell this client about the whole current roster: how many players
                // to expect, then a profile per player (its own marked is_local).
                let mut roster: Vec<(u8, game_team_id, String, bool)> = self
                    .peers
                    .iter()
                    .filter(|(_, peer)| peer.registered)
                    .map(|(addr, peer)| {
                        (peer.player_id, peer.team, peer.name.clone(), *addr == from)
                    })
                    .collect();
                roster.sort_by_key(|(player_id, ..)| *player_id);

                self.send_to(from, game::match_options(roster.len() as u8));
                for (player_id, team, name, is_local) in roster {
                    self.send_to(
                        from,
                        ServerGameMessageKind::PlayerProfile {
                            player_profile: Box::new(game::player_profile(
                                player_id, team, &name, is_local,
                            )),
                        },
                    );
                }
            }

            ClientGameMessageKind::JoinMatch => {
                let Some(peer) = self.peers.get_mut(&from) else {
                    return;
                };
                peer.joined = true;
                let player_id = peer.player_id;

                // Spawn the joining player for itself and start the match.
                self.send_to(
                    from,
                    ServerGameMessageKind::GameStatusChanged {
                        game_status: game_status::inprocess,
                    },
                );
                self.send_to(from, self.spawn_message(player_id));

                // Let everyone already in the match see the newcomer.
                self.broadcast_to_others(from, self.spawn_message(player_id));
            }

            ClientGameMessageKind::TeamBasesInitializeInfo => {
                // Spawn every other already-joined player for this client, then
                // tell it who is connected.
                let others: Vec<u8> = self
                    .peers
                    .iter()
                    .filter(|(addr, peer)| **addr != from && peer.joined)
                    .map(|(_, peer)| peer.player_id)
                    .collect();
                for player_id in others {
                    self.send_to(from, self.spawn_message(player_id));
                }
                self.send_to(
                    from,
                    ServerGameMessageKind::SyncResponse {
                        is_connected_bitmask: self.connected_bitmask(),
                    },
                );
            }

            ClientGameMessageKind::ClientPlayerUpdate {
                player_input,
                player_state,
                time_in_ms: _,
            } => {
                let Some(peer) = self.peers.get(&from) else {
                    return;
                };
                let player_id = peer.player_id;
                // Dumb relay: forward this player's movement to everyone else. The
                // client message carries no weapon_state, so we send a default one.
                // @NOTE: best-effort — see ServerPlayerInput serialization note.
                self.broadcast_to_others(
                    from,
                    ServerGameMessageKind::ServerPlayerInput {
                        player_id,
                        player_input,
                        player_state,
                        weapon_state: weapon_state {
                            slot_id: 0,
                            ammo_slot_id: 0,
                            state: 0,
                        },
                    },
                );
            }
        }
    }

    fn register_peer(&mut self, addr: SocketAddr, session_id: u32) {
        if self.next_player_id >= MAX_PLAYERS {
            log::warn!("match full ({MAX_PLAYERS} players); ignoring session {session_id:#x}");
            return;
        }

        let assignment = self.store.match_assignment(session_id);
        let team = match assignment {
            Some(a) if a.team_id == 2 => game_team_id::team_2,
            _ => game_team_id::team_1,
        };

        let player_id = self.next_player_id;
        self.next_player_id += 1;

        let name = self
            .store
            .account_for_session(session_id)
            .map(|account| account.lock().unwrap().name.clone())
            .unwrap_or_else(|| format!("player_{player_id}"));

        if let Some(peer) = self.peers.get_mut(&addr) {
            peer.registered = true;
            peer.player_id = player_id;
            peer.team = team;
            peer.name = name;
        }

        log::info!(
            "session {session_id:#x} is player {player_id} (team {team:?}) at {addr}",
        );
    }

    /// A `SpawnPlayer` for `player_id` at its canned spawn point.
    fn spawn_message(&self, player_id: u8) -> ServerGameMessageKind {
        ServerGameMessageKind::SpawnPlayer {
            player_id,
            player: game::spawn_content(player_id as usize),
        }
    }

    /// Bitmask of registered (connected) players, one bit per player id.
    fn connected_bitmask(&self) -> u32 {
        self.peers
            .values()
            .filter(|peer| peer.registered)
            .fold(0, |mask, peer| mask | (1 << peer.player_id))
    }

    fn send_to(&mut self, addr: SocketAddr, message: ServerGameMessageKind) {
        if let Some(peer) = self.peers.get_mut(&addr) {
            peer.transport.send_game_message(&self.socket, addr, message);
        }
    }

    fn broadcast_to_others(&mut self, except: SocketAddr, message: ServerGameMessageKind) {
        let socket = &self.socket;
        for (addr, peer) in self.peers.iter_mut() {
            if *addr != except && peer.joined {
                peer.transport
                    .send_game_message(socket, *addr, message.clone());
            }
        }
    }

    /// Drop peers that have disconnected, and tell the rest who is left.
    fn reap_disconnected(&mut self) {
        let gone: Vec<SocketAddr> = self
            .peers
            .iter()
            .filter(|(_, peer)| peer.transport.is_disconnected())
            .map(|(addr, _)| *addr)
            .collect();

        if gone.is_empty() {
            return;
        }

        for addr in gone {
            if let Some(peer) = self.peers.remove(&addr) {
                log::info!("player {} ({addr}) disconnected", peer.player_id);
            }
        }

        // Best-effort leave signal: refresh everyone's connected bitmask.
        let bitmask = self.connected_bitmask();
        let socket = &self.socket;
        for (addr, peer) in self.peers.iter_mut() {
            if peer.joined {
                peer.transport.send_game_message(
                    socket,
                    *addr,
                    ServerGameMessageKind::SyncResponse {
                        is_connected_bitmask: bitmask,
                    },
                );
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::time::Duration;

    /// A minimal, valid client "connection" datagram: local_seq 0, remote_seq
    /// 0xFFFF, ack word 0 (→ remote_ack_bits 0x8000, single packet), then a
    /// `connection_request` (0x40) with order_id 0 and the session id.
    fn connection_packet(session_id: u32) -> Vec<u8> {
        let mut packet = vec![0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x40, 0x00, 0x00];
        packet.extend(session_id.to_le_bytes());
        packet
    }

    #[test]
    fn responds_to_a_connection_request() {
        let store = Arc::new(SessionStore::new());
        let server = MatchServer::bind("127.0.0.1:0", store).unwrap();
        let server_addr = server.local_addr().unwrap();
        std::thread::spawn(move || server.run());

        let client = UdpSocket::bind("127.0.0.1:0").unwrap();
        client
            .set_read_timeout(Some(Duration::from_secs(2)))
            .unwrap();
        client.send_to(&connection_packet(0xDD00), server_addr).unwrap();

        let mut buf = [0u8; 2048];
        let (len, _) = client
            .recv_from(&mut buf)
            .expect("relay should answer a connection request");

        // Server packet: 6-byte header, then the first message's type byte.
        // 0x80 = match_server_connection_successful.
        assert!(len >= 7, "response too short: {len} bytes");
        assert_eq!(buf[6], 0x80, "expected ConnectionSuccessful, got {:#x}", buf[6]);
    }
}

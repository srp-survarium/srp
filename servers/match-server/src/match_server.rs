use std::collections::BTreeSet;
use std::thread::JoinHandle;
use std::{collections::BTreeMap, sync::mpsc};

use foundation::config;
use foundation::network_client::UdpClient;
use foundation::network_packet::{Packet, UdpPacket};
use foundation::serde::{Deserialize, Serialize};

use crate::client_message::{GameMessage, UdpMessage, UdpMessageKind};
use crate::server_message::{ServerMessage, ServerMessageKind};
use crate::{client_message, player_profile, server_message};

/// Currently server can only run a single match
/// ```ignore
/// struct MatchServer {
///     connections: Vec<MatchConnection>,
/// }
///
/// impl MatchServer {
///     fn recv(MatchServerMessage) { .. }
/// }
/// ```
//
// 1. LobbyServer -> MatchServer { port, session_id }
// 2. wait for response
// 3. LobbyServer -> LobbyClient { ready }
//
// 1. MatchServer -> LobbyServer { /* match end info */ }

struct MatchConnection {
    handle: std::thread::JoinHandle<()>,
}

struct MatchConnectionState {
    reader_handle: std::thread::JoinHandle<()>,
    writer_handle: std::thread::JoinHandle<()>,

    server_sequence_id: u16,
    server_ack_bits: u16,

    client_sequence_id: u16,
    client_ack_bits: u16,

    server_order_id: u16,
    client_order_id: u16,

    // server packets that weren't acknowledged
    unacknowledged_packets: BTreeMap<u16, UdpPacket>,
    // client packets that were sent not in order
    pendings_packets: BTreeMap<u16, Vec<UdpMessageKind>>,
}

// 1. Client sends packet
// 2. Packet is received by reader
// 3. Reads sends constructed packet to actor
// 4. Actor handles the message (sends it to the game engine)
// 5. Game engine can send a response to the Actor
// 6. Actor sends the packet to the writer
//
// 1. Game engine can send an unprompted response to the Actor
// 2. Actor sends the packet to the writer
//
// Low level messages (handled by Actor)?
// writer | reader | low-level pinger<??>
//
impl MatchConnection {
    pub fn run(address: &str, port: u16) -> Self {
        let mut udp_client = UdpClient::new(format!("{address}:{port}")).unwrap();

        let mut unacknowledged_packets = BTreeMap::new();

        //
        // We handle first connection message ourselves
        //

        let (addr, message) = udp_client.recv_from::<UdpMessage>().unwrap();
        if message.kinds.len() != 1 {
            panic!("Expected a single 'ConnectionRequest' message");
        }
        let UdpMessageKind::Message {
            order_id,
            game_message: GameMessage::ConnectionRequest { session_id: _ },
        } = message.kinds[0]
        else {
            panic!("Received a message which is not 'ConnectionRequest': {message:?}");
        };
        assert_eq!(order_id, 0);

        udp_client.connect(addr).unwrap();

        let mut packet = UdpPacket::new();
        let server_message = ServerMessage {
            remote_sequence_id: 0,
            local_sequence_id: 0, // ?
            local_ack_bits: 0,
            match_packets_count: client_message::raw::udp_match_packets_count_enum::single_packet,
            kind: server_message::ServerMessageKind::ConnectionSuccessful { order_id: 0 },
        }
        .serialize(&mut packet);

        udp_client.send_raw(packet.get_message()).unwrap();
        unacknowledged_packets.insert(0, packet);

        // reader
        let (reader_tx, reader_rx) = mpsc::channel::<Vec<u8>>();
        let reader_handle = std::thread::spawn({
            let mut udp_client = udp_client.try_clone().unwrap();
            move || {
                let packet = udp_client.recv_raw().unwrap();
                reader_tx.send(packet).unwrap();
            }
        });

        // writer
        let (writer_tx, writer_rx) = mpsc::channel::<Vec<u8>>();
        let writer_handle = std::thread::spawn({
            move || {
                let packet = writer_rx.recv().unwrap();
                udp_client.send_raw(&packet).unwrap();
            }
        });

        let state = MatchConnectionState {
            reader_handle,
            writer_handle,

            server_sequence_id: 1,
            server_ack_bits: 0b0000_0000_0000_0000,

            client_sequence_id: 1,
            client_ack_bits: 0b0000_0000_0000_0000,

            server_order_id: 1,
            client_order_id: 1,

            unacknowledged_packets,
            pendings_packets: BTreeMap::new(),
        };

        let handle = std::thread::spawn({
            let mut state = state;
            move || {
                let packet = reader_rx.recv().unwrap();
                let mut buffer = packet.as_slice();

                let UdpMessage {
                    sequence_id,
                    remote_sequence_id,
                    remote_ack_bits,
                    kinds,
                } = UdpMessage::deserialize(&mut buffer).unwrap();
                assert!(buffer.is_empty());

                // TODO: fail if already received

                state.pendings_packets.insert(sequence_id, kinds);

                // TODO: Where confirmation of acknowledged packets
                state.update_acknowledgements(sequence_id, remote_sequence_id, remote_ack_bits);

                let mut responses = Vec::new();
                for i in sequence_id..=state.client_sequence_id {
                    let messages = state.pendings_packets.remove(&i).unwrap();
                    for message in messages {
                        // TODO: Who handles `order_id`
                        match message {
                            UdpMessageKind::Low(_) => (),
                            UdpMessageKind::Message {
                                order_id,
                                game_message,
                            } => {
                                responses.extend(Game::handle_message(game_message));
                            }
                        }
                    }
                }

                //
                // send resposnes
                //
            }
        });

        Self { handle }
    }
}

impl MatchConnectionState {
    pub fn update_acknowledgements(
        &mut self,
        sequence_id: u16,
        remote_sequence_id: u16,
        remote_ack_bits: u16,
    ) {
        todo!()
    }
}

struct Game {}

impl Game {
    pub fn handle_message(message: GameMessage) -> Vec<ServerMessageKind> {
        match message {
            GameMessage::ConnectionRequest { .. } => panic!(),
            GameMessage::GetStartupInfo => {
                // @TODO: remove order id
                vec![
                    server_message::ServerMessageKind::MatchOptions {
                        order_id: 1,
                        map_id: 0,
                        // map_name: "level_03_evn".to_string(),
                        map_name: "lobby_scene".to_string(),
                        match_mode: server_message::raw::game_mode_type::gather_victory_items,
                        player_count: 2,
                        victory_item_count: 10,
                        respawn_time: 10,
                        match_time: 15 * 60,
                    },
                    server_message::ServerMessageKind::PlayerProfile {
                        order_id: 2,
                        player_profile: player_profile::raw::player_profile {
                            team: player_profile::raw::game_team_id::team_1,
                            is_local: true,
                            ..player_profile::raw::player_profile::new_dummy(0, 0, "sheepy")
                        },
                    },
                    server_message::ServerMessageKind::PlayerProfile {
                        order_id: 3,
                        player_profile: player_profile::raw::player_profile {
                            team: player_profile::raw::game_team_id::team_2,
                            is_local: false,
                            ..player_profile::raw::player_profile::new_dummy(0, 0, "beauty")
                        },
                    },
                ]
            }
            GameMessage::ClientPlayerUpdate { unknown } => vec![],
        }
    }
}

// SPDX-License-Identifier: GPL-3.0-or-later
// Per-peer reliable-UDP transport for the match server.
//
// This holds the sequence-number / ack state for ONE peer and (de)serializes
// packets, but owns no socket and no threads: the `MatchServer` loop owns one
// shared `UdpSocket`, demultiplexes datagrams by source address, and drives a
// `Transport` per peer. The reliable-UDP math (`update_acknowledgements`) is
// unchanged from the original single-peer implementation.
//
// @TODO (unchanged from before): proper packet splitter, retries of
// `unacknowledged_packets`, `order_id` handling, richer error handling.

use std::collections::BTreeMap;
use std::net::{SocketAddr, UdpSocket};
use std::time::{Duration, Instant};

use vostok::network_packet::UdpPacket;
use vostok::serde::{Deserialize, Serialize};

use crate::message;
use crate::message::raw::low_level_message_type_enum;
use crate::sequence_number::SN16;
use crate::utils;

#[derive(Copy, Clone, PartialEq)]
pub enum ConnectionState {
    WaitingForConnection,
    Connected,
    Disconnected,
}

pub struct Transport {
    // Last sequence_id sent to the client
    server_sequence_id: SN16,
    server_received_sequence_id: SN16,
    server_received_ack_bits: u16,

    // Last sequence_id recv from the client
    client_sequence_id: SN16,
    client_ack_bits: u16,

    server_order_id: SN16,

    // server packets that weren't acknowledged
    unacknowledged_packets: BTreeMap<SN16, UdpPacket>,
    // client packets that were sent not in order
    pendings_packets: BTreeMap<SN16, Vec<message::ClientGameMessage>>,

    last_send_time: Instant,

    connection_state: ConnectionState,
}

impl Transport {
    pub fn new() -> Self {
        Self {
            server_sequence_id: 0xFFFF.into(),
            server_received_sequence_id: 0xFFFF.into(),
            server_received_ack_bits: 0b0000_0000_0000_0000,

            client_sequence_id: 0xFFFF.into(),
            client_ack_bits: 0b0000_0000_0000_0000,

            server_order_id: 0xFFFF.into(),

            unacknowledged_packets: BTreeMap::new(),
            pendings_packets: BTreeMap::new(),
            last_send_time: Instant::now(),
            connection_state: ConnectionState::WaitingForConnection,
        }
    }

    pub fn is_disconnected(&self) -> bool {
        self.connection_state == ConnectionState::Disconnected
    }

    /// Decode one incoming datagram: update acknowledgements, advance the
    /// connection state machine, send any transport-level reply
    /// (`ConnectionSuccessful`, disconnect confirmation) and return the decoded
    /// client game messages for the relay to act on.
    pub fn handle_datagram(
        &mut self,
        datagram: &[u8],
        socket: &UdpSocket,
        addr: SocketAddr,
    ) -> Vec<message::ClientGameMessageKind> {
        let mut buffer = datagram;

        let Ok(packet) = message::ClientMessage::deserialize(&mut buffer) else {
            utils::print_debug(datagram);
            return vec![];
        };

        packet.print_debug();

        let message::ClientMessage {
            local_sequence_id,
            remote_sequence_id,
            remote_ack_bits,
            kind,
        } = packet;

        // Packet already received. Ignore
        if local_sequence_id == self.client_sequence_id {
            return vec![];
        }

        if self.client_sequence_id < local_sequence_id {
            self.update_acknowledgements(local_sequence_id, remote_sequence_id, remote_ack_bits);
        }

        match self.connection_state {
            ConnectionState::WaitingForConnection => {
                assert_eq!(local_sequence_id, 0x0000.into());
                assert_eq!(remote_sequence_id, 0xFFFF.into());
                assert_eq!(remote_ack_bits, 0b1000_0000_0000_0000);

                let message::ClientMessageKind::Messages(messages) = kind else {
                    panic!("Received incorrect packet on connection")
                };

                let Some(message::ClientGameMessage {
                    order_id: SN16(0),
                    game_message:
                        game_message @ message::ClientGameMessageKind::ConnectionRequest { .. },
                }) = messages.into_iter().next()
                else {
                    panic!("Received incorrect packet on connection")
                };

                self.connection_state = ConnectionState::Connected;
                // Transport-level: acknowledge the connection. The relay learns of
                // the new peer from the returned `ConnectionRequest`.
                self.send_game_message(
                    socket,
                    addr,
                    message::ServerGameMessageKind::ConnectionSuccessful,
                );

                vec![game_message]
            }
            _ => match kind {
                message::ClientMessageKind::Low(msg_type) => {
                    self.handle_low_level_message(msg_type, socket, addr);
                    vec![]
                }
                message::ClientMessageKind::Messages(messages) => {
                    self.pendings_packets.insert(local_sequence_id, messages);

                    let mut game_messages = vec![];
                    let mut i = local_sequence_id;
                    // @TODO: Fix logic; `order_id` is not handled at all.
                    while i <= self.client_sequence_id {
                        let messages = self.pendings_packets.remove(&i).unwrap();
                        for message in messages {
                            game_messages.push(message.game_message);
                        }
                        i += 1.into();
                    }
                    game_messages
                }
            },
        }
    }

    fn handle_low_level_message(
        &mut self,
        msg_type: low_level_message_type_enum,
        socket: &UdpSocket,
        addr: SocketAddr,
    ) {
        match msg_type {
            low_level_message_type_enum::continuous_flow => (),
            low_level_message_type_enum::initiate_disconnection => {
                self.send_packet(
                    socket,
                    addr,
                    message::ServerMessageKind::Low(
                        low_level_message_type_enum::confirm_disconnection,
                    ),
                );
                // Don't panic the whole server: mark this peer disconnected so the
                // loop can drop it and notify the others.
                self.connection_state = ConnectionState::Disconnected;
            }
            low_level_message_type_enum::confirm_disconnection => unimplemented!(),
        }
    }

    /// Send a keepalive if we've been idle, so the client's channel stays alive.
    pub fn maintain(&mut self, socket: &UdpSocket, addr: SocketAddr) {
        const MAX_IDLE_TIME_IN_MS: u64 = 0x21; // Copied from the game
        if Instant::now() - self.last_send_time > Duration::from_millis(MAX_IDLE_TIME_IN_MS) {
            self.send_packet(
                socket,
                addr,
                message::ServerMessageKind::Low(low_level_message_type_enum::continuous_flow),
            );
        }
    }

    pub fn send_game_message(
        &mut self,
        socket: &UdpSocket,
        addr: SocketAddr,
        game_message: message::ServerGameMessageKind,
    ) {
        self.server_order_id += 1.into();

        self.send_packet(
            socket,
            addr,
            message::ServerMessageKind::Messages(vec![message::ServerGameMessage {
                order_id: self.server_order_id,
                game_message,
            }]),
        );
    }

    fn send_packet(
        &mut self,
        socket: &UdpSocket,
        addr: SocketAddr,
        kind: message::ServerMessageKind,
    ) {
        self.server_sequence_id += 1.into();
        self.last_send_time = Instant::now();

        let mut packet = UdpPacket::new();
        let message = message::ServerMessage {
            remote_sequence_id: self.server_sequence_id,
            local_sequence_id: self.client_sequence_id,
            local_ack_bits: self.client_ack_bits,
            kind,
        };

        message.print_debug();
        message.serialize(&mut packet);

        self.unacknowledged_packets
            .insert(self.server_sequence_id, packet);

        // Best-effort send; a dropped datagram is the client's loss to ack/retry.
        let _ = socket.send_to(packet.get_message(), addr);
    }

    pub fn update_acknowledgements(
        &mut self,
        client_sequence_id: SN16, // local here means client
        server_sequence_id: SN16,
        server_ack_bits: u16, // server packets which were acknowledged by the client
    ) {
        //
        // Updates info on the client packages received
        //
        let diff = client_sequence_id - self.client_sequence_id;

        let mut client_ack_bits = 0;
        if diff < 0x10 {
            client_ack_bits = self.client_ack_bits >> diff;
        }
        client_ack_bits |= 0x8000;

        self.client_ack_bits = client_ack_bits;
        self.client_sequence_id = client_sequence_id;

        //
        // Given what client knows about our packets,
        // remove already received unacknowledged packets
        //

        if server_sequence_id > self.server_sequence_id {
            panic!("Packet we didn't send");
        }

        if server_sequence_id == self.server_received_sequence_id {
            // The packet was duplicated. Ignore
            return;
        }

        if server_sequence_id < self.server_received_sequence_id {
            // Packet came out of order, and we already handled a more recent packet.
            // Simply mark this packet as acknowledged.

            let diff = self.server_received_sequence_id - server_sequence_id;
            if diff <= 15 {
                self.server_received_ack_bits |= 1 << (15 - diff);
            }

            self.unacknowledged_packets.remove(&server_sequence_id);
        } else {
            // This is the most recent state about the server from the client

            let diff = server_sequence_id - self.server_received_sequence_id;

            let last_server_received_ack_bits = if diff < 16 {
                self.server_received_ack_bits >> diff
            } else {
                0
            };

            if server_ack_bits & last_server_received_ack_bits != last_server_received_ack_bits {
                // Packet is inconsistent with what the client told us previously
                // Some packet which was told that it was acknowledged is no longer acknowledged
                return;
            }

            self.server_received_ack_bits = server_ack_bits;
            self.server_received_sequence_id = server_sequence_id;

            let mut acknowledgment_bits = server_ack_bits ^ last_server_received_ack_bits;
            let mut sequence_id = server_sequence_id.0;

            while acknowledgment_bits != 0 {
                if (acknowledgment_bits & 0x8000) != 0 {
                    self.unacknowledged_packets.remove(&sequence_id.into());
                }
                sequence_id = sequence_id.wrapping_sub(1);
                acknowledgment_bits <<= 1;
            }
        }
    }
}

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

        // `client_sequence_id` is the newest packet already processed. A late
        // packet is stale; processing it again can duplicate game actions. The
        // old pending-map loop also unwrapped sequence gaps and panicked on the
        // normal UDP arrival order 0 -> 2 -> 1.
        if local_sequence_id < self.client_sequence_id {
            log::debug!(
                "dropping stale client packet {local_sequence_id:?}; newest is {:?}",
                self.client_sequence_id
            );
            return vec![];
        }

        if self.client_sequence_id < local_sequence_id {
            self.update_acknowledgements(local_sequence_id, remote_sequence_id, remote_ack_bits);
        }

        match self.connection_state {
            ConnectionState::WaitingForConnection => {
                let valid_header = local_sequence_id == 0x0000.into()
                    && remote_sequence_id == 0xFFFF.into()
                    && remote_ack_bits == 0b1000_0000_0000_0000;

                let first = match kind {
                    message::ClientMessageKind::Messages(messages) => messages.into_iter().next(),
                    message::ClientMessageKind::Low(_) => None,
                };

                // A malformed first packet must not crash the server (which would
                // restart the whole match and drop every peer): log and drop this
                // would-be peer instead.
                let Some(message::ClientGameMessage {
                    order_id: SN16(0),
                    game_message:
                        game_message @ message::ClientGameMessageKind::ConnectionRequest { .. },
                }) = first.filter(|_| valid_header)
                else {
                    log::warn!("dropping malformed connection attempt from {addr}");
                    self.connection_state = ConnectionState::Disconnected;
                    return vec![];
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
                message::ClientMessageKind::Messages(messages) => messages
                    .into_iter()
                    .map(|message| message.game_message)
                    .collect(),
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
            // We never initiate a disconnect, so a confirmation is unexpected;
            // ignore it rather than crash on a stray/malicious packet.
            low_level_message_type_enum::confirm_disconnection => {
                log::debug!("ignoring unexpected confirm_disconnection");
            }
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
            // The client acked a packet we never sent (malformed/stale): ignore
            // the server-side ack bookkeeping instead of crashing.
            log::warn!("client acked an unsent packet; ignoring");
            return;
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

#[cfg(test)]
mod tests {
    use super::*;

    fn connection_packet() -> Vec<u8> {
        vec![
            0x00, 0x00, // local sequence
            0xFF, 0xFF, // remote sequence
            0x00, 0x00, // single packet / ack bits
            0x40, 0x00, 0x00, // connection request / order ID
            0x00, 0xDD, 0x00, 0x00, // session ID
        ]
    }

    fn game_packet(local_sequence: u16, message_type: u8, order_id: u16) -> Vec<u8> {
        let mut packet = Vec::new();
        packet.extend(local_sequence.to_le_bytes());
        packet.extend(0u16.to_le_bytes());
        packet.extend(0u16.to_le_bytes());
        packet.push(message_type);
        packet.extend(order_id.to_le_bytes());
        packet
    }

    #[test]
    fn drops_a_late_packet_without_panicking() {
        let socket = UdpSocket::bind("127.0.0.1:0").unwrap();
        let peer_socket = UdpSocket::bind("127.0.0.1:0").unwrap();
        let peer_addr = peer_socket.local_addr().unwrap();
        let mut transport = Transport::new();

        assert_eq!(
            transport
                .handle_datagram(&connection_packet(), &socket, peer_addr)
                .len(),
            1
        );
        assert_eq!(
            transport
                .handle_datagram(&game_packet(2, 0x41, 2), &socket, peer_addr)
                .len(),
            1
        );
        assert!(
            transport
                .handle_datagram(&game_packet(1, 0x42, 1), &socket, peer_addr)
                .is_empty()
        );
    }
}

// SPDX-License-Identifier: GPL-3.0-or-later
// @TODO:
// * Proper packet splitter
// * Retries
// * error handling

use std::collections::BTreeMap;
use std::sync::atomic::{Atomic, Ordering};
use std::sync::mpsc::TryRecvError;
use std::sync::{mpsc, Arc};
use std::time::{self, Duration, Instant};

use session::SessionStore;
use vostok::network_client::UdpClient;
use vostok::network_packet::UdpPacket;
use vostok::serde::{Deserialize, Serialize};

use crate::message;
use crate::message::raw::low_level_message_type_enum;
use crate::sequence_number::SN16;
use crate::utils;

pub struct MatchConnection {
    reader_rx: mpsc::Receiver<Vec<u8>>,
    writer_tx: mpsc::Sender<Vec<u8>>,

    udp_client: UdpClient,
    reader_handle: Option<std::thread::JoinHandle<()>>,
    writer_handle: Option<std::thread::JoinHandle<()>>,
    should_stop: Arc<Atomic<bool>>,

    client_game_message_tx: mpsc::Sender<message::ClientGameMessageKind>,
    server_game_message_rx: mpsc::Receiver<message::ServerGameMessageKind>,

    // Last sequence_id sent to the client
    server_sequence_id: SN16,
    server_received_sequence_id: SN16,
    server_received_ack_bits: u16,

    // Last sequence_id recv from the client
    client_sequence_id: SN16,
    client_ack_bits: u16,

    server_order_id: SN16,
    #[expect(dead_code)]
    client_order_id: SN16,

    // server packets that weren't acknowledged
    unacknowledged_packets: BTreeMap<SN16, UdpPacket>,
    // client packets that were sent not in order
    pendings_packets: BTreeMap<SN16, Vec<message::ClientGameMessage>>,

    last_send_time: time::Instant,

    connection_state: ConnectionState,

    store: Arc<SessionStore>,
}

#[expect(dead_code)]
#[derive(Copy, Clone)]
enum ConnectionState {
    WaitingForConnection,
    Connected,
    InitializedDisconnection,
    Disconnected,
}

impl Drop for MatchConnection {
    fn drop(&mut self) {
        {
            let (mut dummy_tx, mut dummy_rx) = mpsc::channel();
            std::mem::swap(&mut self.reader_rx, &mut dummy_rx);
            std::mem::swap(&mut self.writer_tx, &mut dummy_tx);
        }

        self.should_stop.store(true, Ordering::Relaxed);

        if let Some(reader_handle) = self.reader_handle.take() {
            _ = reader_handle.join();
        }
        if let Some(writer_handle) = self.writer_handle.take() {
            _ = writer_handle.join();
        }
    }
}

impl MatchConnection {
    pub fn wait_for_game_start(
        address: &str,
        port: u16,
        store: Arc<SessionStore>,
        client_game_message_tx: mpsc::Sender<message::ClientGameMessageKind>,
        server_game_message_rx: mpsc::Receiver<message::ServerGameMessageKind>,
    ) -> Self {
        let (reader_tx, reader_rx) = mpsc::channel::<Vec<u8>>();
        let (writer_tx, writer_rx) = mpsc::channel::<Vec<u8>>();

        let mut this = Self {
            reader_rx,
            writer_tx,

            udp_client: UdpClient::new(format!("{address}:{port}")).unwrap(),
            should_stop: Arc::new(false.into()),

            client_game_message_tx,
            server_game_message_rx,

            reader_handle: None,
            writer_handle: None,

            server_sequence_id: 0xFFFF.into(),
            server_received_sequence_id: 0xFFFF.into(),
            server_received_ack_bits: 0b0000_0000_0000_0000,

            client_sequence_id: 0xFFFF.into(),
            client_ack_bits: 0b0000_0000_0000_0000,

            server_order_id: 0xFFFF.into(),
            client_order_id: 0.into(),

            unacknowledged_packets: BTreeMap::<SN16, _>::new(),
            pendings_packets: BTreeMap::new(),
            last_send_time: Instant::now(),
            connection_state: ConnectionState::WaitingForConnection,

            store,
        };

        this.init_connection(reader_tx, writer_rx);

        this
    }

    pub fn read_incoming_packets(&mut self) {
        loop {
            match self.reader_rx.try_recv() {
                Ok(message) => self.handle_incoming_packet(message),
                Err(TryRecvError::Empty) => break,
                Err(TryRecvError::Disconnected) => panic!("Channel disconnected"),
            }
        }
    }

    pub fn write_outgoing_packets(&mut self) {
        loop {
            match self.server_game_message_rx.try_recv() {
                // @TODO: Add logic for combining multiple packets into one
                Ok(message) => self.send_game_packet(message),
                Err(TryRecvError::Empty) => break,
                Err(TryRecvError::Disconnected) => panic!("Channel disconnected"),
            }
        }

        self.maintain_connection();
    }
}

impl MatchConnection {
    fn init_connection(
        &mut self,
        reader_tx: mpsc::Sender<Vec<u8>>,
        writer_rx: mpsc::Receiver<Vec<u8>>,
    ) {
        //
        // We handle first connection message ourselves
        // No error checking is done here :shrug:
        //

        let mut udp_client = self.udp_client.try_clone().unwrap();
        let (addr, packet) = udp_client.recv_from_raw().unwrap();

        udp_client
            .set_timeout(Some(Duration::from_secs(1)))
            .unwrap();

        self.handle_incoming_packet(packet);
        udp_client.connect(addr).unwrap();

        //
        // Start writer and reader
        //

        let reader_handle = std::thread::spawn({
            let mut udp_client = udp_client.try_clone().unwrap();
            let should_stop = self.should_stop.clone();
            move || loop {
                let result = udp_client.recv_raw();
                match result {
                    Ok(packet) => reader_tx.send(packet).unwrap(),
                    Err(error) => {
                        let std::io::ErrorKind::TimedOut = error.kind() else {
                            panic!("{error:?}")
                        };
                        if should_stop.load(Ordering::Relaxed) {
                            return;
                        }
                    }
                }
            }
        });
        self.reader_handle = Some(reader_handle);

        let writer_handle = std::thread::spawn({
            let udp_client = udp_client;
            let should_stop = self.should_stop.clone();

            move || loop {
                let packet = writer_rx.recv().unwrap();
                let result = udp_client.send_raw(&packet);
                match result {
                    Ok(_) => (),
                    Err(error) => {
                        let std::io::ErrorKind::TimedOut = error.kind() else {
                            panic!("{error:?}")
                        };
                        if should_stop.load(Ordering::Relaxed) {
                            return;
                        }
                    }
                }
            }
        });
        self.writer_handle = Some(writer_handle);
    }

    fn handle_incoming_packet(&mut self, packet: Vec<u8>) {
        let mut buffer = packet.as_slice();

        let Ok(packet) = message::ClientMessage::deserialize(&mut buffer) else {
            utils::print_debug(packet.as_slice());
            return;
        };

        packet.print_debug();

        // @TODO: Consider renaming to `ClientPacket`
        let message::ClientMessage {
            local_sequence_id,
            remote_sequence_id,
            remote_ack_bits,
            kind,
        } = packet;

        // Packet already received. Ignore
        if local_sequence_id == self.client_sequence_id {
            return;
        }

        if self.client_sequence_id < local_sequence_id {
            // 1. Check remote_ack_bits on which packets were received and delete ones we don't
            //    need to retry anymore
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

                let message::ClientGameMessage {
                    order_id: SN16(0),
                    game_message: message::ClientGameMessageKind::ConnectionRequest { session_id },
                } = messages[0]
                else {
                    panic!("Received incorrect packet on connection")
                };

                // Honour the lobby's matchmaking: the session must have been
                // routed here, and we learn its match + team from the shared store.
                match self.store.match_assignment(session_id) {
                    Some(assignment) => log::info!(
                        "Session {session_id:#x} connected to match {:#x} on team {}",
                        assignment.match_id,
                        assignment.team_id,
                    ),
                    None => log::warn!(
                        "Session {session_id:#x} connected without a match assignment \
                         (lobby not consulted?); accepting anyway"
                    ),
                }

                self.connection_state = ConnectionState::Connected;
                self.send_game_packet(message::ServerGameMessageKind::ConnectionSuccessful);
            }
            _ => match kind {
                message::ClientMessageKind::Low(msg_type) => {
                    self.handle_low_level_message(msg_type)
                }
                message::ClientMessageKind::Messages(messages) => {
                    self.pendings_packets.insert(local_sequence_id, messages);

                    let mut i = local_sequence_id;
                    // @TODO: Fix logic
                    // @TODO: `order_id` is not handled at all
                    while i <= self.client_sequence_id {
                        let messages = self.pendings_packets.remove(&i).unwrap();
                        for message in messages {
                            let message::ClientGameMessage {
                                order_id: _,
                                game_message,
                            } = message;

                            self.client_game_message_tx.send(game_message).unwrap()
                        }
                        i += 1.into();
                    }
                }
            },
        }
    }

    fn handle_low_level_message(&mut self, msg_type: low_level_message_type_enum) {
        match msg_type {
            low_level_message_type_enum::continuous_flow => (),
            low_level_message_type_enum::initiate_disconnection => {
                self.send_packet(message::ServerMessageKind::Low(
                    low_level_message_type_enum::confirm_disconnection,
                ));

                panic!("Done")
            }
            low_level_message_type_enum::confirm_disconnection => unimplemented!(),
        }
    }

    // fn on_packet_received

    fn maintain_connection(&mut self) {
        const MAX_IDLE_TIME_IN_MS: u64 = 0x21; // Copied from the game
        if Instant::now() - self.last_send_time > Duration::from_millis(MAX_IDLE_TIME_IN_MS) {
            self.send_packet(message::ServerMessageKind::Low(
                low_level_message_type_enum::continuous_flow,
            ));
        }
    }

    //
    //
    //

    fn send_game_packet(&mut self, game_message: message::ServerGameMessageKind) {
        self.server_order_id += 1.into();

        self.send_packet(message::ServerMessageKind::Messages(vec![
            message::ServerGameMessage {
                order_id: self.server_order_id,
                game_message,
            },
        ]));
    }

    fn send_packet(&mut self, kind: message::ServerMessageKind) {
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

        self.writer_tx.send(packet.get_message().to_vec()).unwrap();
    }
}

impl MatchConnection {
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

#![allow(dead_code)]
#![allow(unused_imports)]

use std::collections::{BTreeMap, BTreeSet};
use std::sync::mpsc;
use std::thread::JoinHandle;

use survarium::player_profile;
use vostok::config;
use vostok::network_client::UdpClient;
use vostok::network_packet::{Packet, UdpPacket};
use vostok::serde::{Deserialize, Serialize};

use crate::game_server::Game;
use crate::message;
use crate::message::raw::low_level_message_type_enum;
use crate::sequence_number::SN16;

pub struct MatchConnection {
    pub handle: std::thread::JoinHandle<()>,
}

struct MatchConnectionState {
    reader_rx: mpsc::Receiver<Vec<u8>>,
    writer_tx: mpsc::Sender<Vec<u8>>,

    reader_handle: Option<std::thread::JoinHandle<()>>,
    writer_handle: Option<std::thread::JoinHandle<()>>,

    // Last sequence_id sent to the client
    server_sequence_id: SN16,
    server_ack_bits: u16,

    // Last sequence_id recv from the client
    client_sequence_id: SN16,
    client_ack_bits: u16,

    server_order_id: SN16,
    client_order_id: SN16,

    // server packets that weren't acknowledged
    unacknowledged_packets: BTreeMap<SN16, UdpPacket>,
    // client packets that were sent not in order
    pendings_packets: BTreeMap<SN16, message::ClientMessage>,
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
        let (reader_tx, reader_rx) = mpsc::channel::<Vec<u8>>();
        let (writer_tx, writer_rx) = mpsc::channel::<Vec<u8>>();

        let mut state = MatchConnectionState {
            reader_rx,
            writer_tx,

            reader_handle: None,
            writer_handle: None,

            server_sequence_id: 0xFFFF.into(),
            server_ack_bits: 0b0000_0000_0000_0000,

            client_sequence_id: 0xFFFF.into(),
            client_ack_bits: 0b0000_0000_0000_0000,

            server_order_id: 0.into(),
            client_order_id: 0.into(),

            unacknowledged_packets: BTreeMap::<SN16, _>::new(),
            pendings_packets: BTreeMap::new(),
        };

        let udp_client = state.init_connection(address, port);

        //
        // Start writer and reader
        //

        let reader_handle = std::thread::spawn({
            let mut udp_client = udp_client.try_clone().unwrap();
            move || loop {
                let packet = udp_client.recv_raw().unwrap();
                reader_tx.send(packet).unwrap();
            }
        });
        state.reader_handle = Some(reader_handle);

        let writer_handle = std::thread::spawn({
            move || loop {
                let packet = writer_rx.recv().unwrap();
                println!("send -- START");
                udp_client.send_raw(&packet).unwrap();
                println!("send -- DONE");
            }
        });
        state.writer_handle = Some(writer_handle);

        //
        // Start ourselves
        //

        Self {
            handle: std::thread::spawn(move || state.run_match_server()),
        }
    }
}

impl MatchConnectionState {
    pub fn init_connection(&mut self, address: &str, port: u16) -> UdpClient {
        let mut udp_client = UdpClient::new(format!("{address}:{port}")).unwrap();

        //
        // We handle first connection message ourselves
        //

        println!("connect -- START");
        let (addr, message) = udp_client.recv_from::<message::ClientMessage>().unwrap();
        if message.kinds.len() != 1 {
            panic!("Expected a single 'ConnectionRequest' message");
        }
        assert_eq!(message.local_sequence_id, 0x0000.into());
        assert_eq!(message.remote_sequence_id, 0xFFFF.into());
        assert_eq!(message.remote_ack_bits, 0b0000_0000_0000_0000);
        let message::ClientMessageKind::Message {
            order_id: 0,
            game_message: message::ClientGameMessage::ConnectionRequest { session_id: _ },
        } = message.kinds[0]
        else {
            panic!("Received a message which is not 'ConnectionRequest': {message:?}");
        };

        udp_client.connect(addr).unwrap();
        println!("connect -- DONE");

        // @NOTE: Currently is faked
        self.server_sequence_id = 0.into();
        self.client_sequence_id = 0.into();
        self.server_order_id = 0.into();
        self.client_order_id = 0.into();

        let mut packet = UdpPacket::new();
        message::ServerMessage {
            remote_sequence_id: self.server_sequence_id,
            local_sequence_id: self.client_sequence_id,
            local_ack_bits: self.client_ack_bits,
            kinds: vec![message::ServerMessageKind::Message {
                order_id: self.server_order_id,
                game_message: message::ServerGameMessage::ConnectionSuccessful,
            }],
        }
        .serialize(&mut packet);

        udp_client.send_raw(packet.get_message()).unwrap();
        self.unacknowledged_packets.insert(0.into(), packet);

        udp_client
    }

    pub fn run_match_server(mut self) -> ! {
        let game = Game {};

        loop {
            let packet = self.reader_rx.recv().unwrap();
            let mut buffer = packet.as_slice();

            let packet = message::ClientMessage::deserialize(&mut buffer).unwrap();
            let message::ClientMessage {
                local_sequence_id,
                remote_sequence_id,
                remote_ack_bits,
                ..
            } = packet.clone();
            assert!(buffer.is_empty());

            // Packet already received. Ignore
            if local_sequence_id == self.client_sequence_id {
                continue;
            }

            // mask will confirm that first server packet was received
            if local_sequence_id < self.client_sequence_id {
                self.update_acknowledgements(
                    local_sequence_id,
                    remote_sequence_id,
                    remote_ack_bits,
                );
            } else {
                self.client_sequence_id = local_sequence_id;
                self.client_ack_bits = 0b0100_0000_0000_0000;
                // why not here?
            }

            self.pendings_packets.insert(local_sequence_id, packet);

            // TODO: Where confirmation of acknowledged packets

            let mut responses = Vec::new();

            let mut i = local_sequence_id;
            while i <= self.client_sequence_id {
                let packet = self.pendings_packets.remove(&i).unwrap();
                for message in packet.kinds {
                    // TODO: Who handles `order_id`
                    match message {
                        message::ClientMessageKind::Low(_) => (),
                        message::ClientMessageKind::Message {
                            order_id: _,
                            game_message,
                        } => {
                            responses.extend(game.handle_message(game_message));
                        }
                    }
                }
                i += 1.into();
            }

            //
            // send resposnes
            //

            if !responses.is_empty() {
                let mut packet = UdpPacket::new();
                message::ServerMessage {
                    remote_sequence_id: self.server_sequence_id,
                    local_sequence_id: self.client_sequence_id,
                    local_ack_bits: self.client_ack_bits,
                    kinds: vec![message::ServerMessageKind::Low(
                        low_level_message_type_enum::continuous_flow,
                    )],
                }
                .serialize(&mut packet);
                println!("Sending continuous_flow");
                self.writer_tx.send(packet.get_message().to_vec()).unwrap();
            }
            // todo!()
        }
    }

    pub fn update_acknowledgements(
        &mut self,
        sequence_id: SN16,
        remote_sequence_id: SN16,
        remote_ack_bits: u16,
    ) {
        todo!()
    }
}

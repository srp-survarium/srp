#![allow(dead_code)]
#![allow(unused_imports)]

use std::cell::RefCell;
use std::collections::{BTreeMap, BTreeSet};
use std::io::Write;
use std::sync::{mpsc, LazyLock, Mutex};
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
                udp_client.send_raw(&packet).unwrap();
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
        message.print_debug();
        if message.kinds.len() != 1 {
            panic!("Expected a single 'ConnectionRequest' message");
        }
        assert_eq!(message.local_sequence_id, 0x0000.into());
        assert_eq!(message.remote_sequence_id, 0xFFFF.into());
        assert_eq!(message.remote_ack_bits, 0b0000_0000_0000_0000);
        let message::ClientMessageKind::Message {
            order_id: SN16(0),
            game_message: message::ClientGameMessage::ConnectionRequest { session_id: _ },
        } = message.kinds[0]
        else {
            panic!("Received a message which is not 'ConnectionRequest': {message:?}");
        };

        udp_client.connect(addr).unwrap();
        println!("connect -- DONE");

        // @NOTE: Currently is faked
        self.server_sequence_id = 0x00_00.into();
        self.client_sequence_id = 0x00_00.into();
        self.client_ack_bits = 0b0000_0000_0000_0000; // @FIXME !!!!
        self.server_order_id = 0x00_00.into();
        self.client_order_id = 0x00_00.into();

        let mut packet = UdpPacket::new();
        let message = message::ServerMessage {
            remote_sequence_id: self.server_sequence_id,
            local_sequence_id: self.client_sequence_id,
            local_ack_bits: self.client_ack_bits,
            kind: message::ServerMessageKind::Messages(vec![message::ServerGameMessage {
                order_id: self.server_order_id,
                game_message: message::ServerGameMessageKind::ConnectionSuccessful,
            }]),
        };
        message.print_debug(); // @TODO: Rename
        message.serialize(&mut packet);

        udp_client.send_raw(packet.get_message()).unwrap();
        self.unacknowledged_packets.insert(0.into(), packet);

        udp_client
    }

    pub fn run_match_server(mut self) -> ! {
        let game = Game {};

        loop {
            let packet = self.reader_rx.recv().unwrap();
            let mut buffer = packet.as_slice();

            print_debug(buffer);
            let Ok(packet) = message::ClientMessage::deserialize(&mut buffer) else {
                print_debug(buffer);
                continue;
            };

            packet.print_debug();
            // @TODO: Rename to ClientPacket
            let message::ClientMessage {
                local_sequence_id,
                remote_sequence_id,
                remote_ack_bits,
                ..
            } = packet.clone();

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
                self.client_ack_bits = 0b0100_0000_0000_0000; // @FIXME

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

            // // 3 packets, 1 messages
            if !responses.is_empty() {
                self.server_sequence_id += 1.into();

                let mut packet = UdpPacket::new();
                let responses_len = responses.len();

                let mut game_messages = responses
                    .into_iter()
                    .enumerate()
                    .map(|(i, game_message)| message::ServerGameMessage {
                        order_id: self.server_order_id + (i as u16).into() + 1.into(),
                        game_message,
                    })
                    .collect::<Vec<_>>();
                // game_messages.reverse();

                let message = message::ServerMessage {
                    remote_sequence_id: self.server_sequence_id,
                    local_sequence_id: self.client_sequence_id,
                    local_ack_bits: self.client_ack_bits,
                    kind: message::ServerMessageKind::Messages(game_messages),
                };

                self.server_order_id += (responses_len as u16).into();

                message.print_debug();
                message.serialize(&mut packet);
                self.writer_tx.send(packet.get_message().to_vec()).unwrap();
            } else {
                self.server_sequence_id += 1.into();

                let mut packet = UdpPacket::new();
                let message = message::ServerMessage {
                    remote_sequence_id: self.server_sequence_id,
                    local_sequence_id: self.client_sequence_id,
                    local_ack_bits: self.client_ack_bits,
                    kind: message::ServerMessageKind::Low(
                        low_level_message_type_enum::continuous_flow,
                    ),
                };
                message.print_debug(); // @TODO
                message.serialize(&mut packet);
                self.writer_tx.send(packet.get_message().to_vec()).unwrap();
            }
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

static LOG_FILE: LazyLock<Mutex<std::fs::File>> = LazyLock::new(log_file);

fn log_file() -> Mutex<std::fs::File> {
    fn get_current_time() -> u64 {
        use std::time::{SystemTime, UNIX_EPOCH};
        let start = SystemTime::now();
        let since_the_epoch = start
            .duration_since(UNIX_EPOCH)
            .expect("time should go forward");
        since_the_epoch.as_secs()
    }

    let file_name = format!(
        "./target/debug/match-server-{time}.log",
        time = get_current_time()
    );
    Mutex::new(std::fs::File::create(file_name).unwrap())
}

impl message::ClientMessage {
    pub fn print_debug(&self) {
        let Self {
            local_sequence_id,
            remote_sequence_id,
            remote_ack_bits,
            kinds,
        } = self;

        let local_sequence_id = local_sequence_id.0;
        let remote_sequence_id = remote_sequence_id.0;

        let kinds = kinds
            .iter()
            .map(|kind| match &kind {
                message::ClientMessageKind::Low(low_level_message_type_enum) => {
                    format!("{low_level_message_type_enum:?}")
                }
                &message::ClientMessageKind::Message {
                    order_id,
                    game_message,
                } => format!("0x{:04X}:{:?}", order_id.0, game_message.message_type()),
            })
            .intersperse_with(|| ", ".to_string())
            .collect::<String>();

        let log_line = format!(
            "<<< local : 0x{local_sequence_id:04X} | remote: 0x{remote_sequence_id:04X} | remote: 0b{remote_ack_bits:016b} | {kinds}\n"
        );
        LOG_FILE.lock().unwrap().write(log_line.as_bytes()).unwrap();
        print!("{log_line}");
    }
}

impl message::ServerMessage {
    pub fn print_debug(&self) {
        let Self {
            remote_sequence_id,
            local_sequence_id,
            local_ack_bits,
            kind,
        } = self;

        let remote_sequence_id = remote_sequence_id.0;
        let local_sequence_id = local_sequence_id.0;

        let kinds = match &kind {
            message::ServerMessageKind::Low(low_level_message_type_enum) => {
                format!("{low_level_message_type_enum:?}")
            }
            message::ServerMessageKind::Messages(messages) => messages
                .iter()
                .map(|message| {
                    let message::ServerGameMessage {
                        order_id,
                        game_message,
                    } = message;
                    format!("0x{:04X}:{:?}", order_id.0, game_message.message_type())
                })
                .intersperse_with(|| ", ".to_string())
                .collect::<String>(),
        };

        let log_line = format!(
            ">>> remote: 0x{remote_sequence_id:04X} | local : 0x{local_sequence_id:04X} | local : 0b{local_ack_bits:016b} | {kinds}\n"
        );
        LOG_FILE.lock().unwrap().write(log_line.as_bytes()).unwrap();
        print!("{log_line}");
    }
}

pub fn print_debug(incoming_bytes: &[u8]) {
    let log_line = format!("<<< {incoming_bytes:?}\n");
    LOG_FILE.lock().unwrap().write(log_line.as_bytes()).unwrap();
    print!("{log_line}");
}

//
//
//

// // Single packet, 3 messages
// let responses_len = responses.len();
// let packets = responses
//     .into_iter()
//     .enumerate()
//     .map(|(i, game_message)| {
//         let mut packet = UdpPacket::new();

//         let remote_sequence_id =
//             self.server_sequence_id + (i as u16).into() + 1.into();
//         let order_id = self.server_order_id + (i as u16).into() + 1.into();

//         let message = message::ServerMessage {
//             remote_sequence_id,
//             local_sequence_id: self.client_sequence_id,
//             local_ack_bits: self.client_ack_bits,
//             kind: message::ServerMessageKind::Messages(vec![
//                 message::ServerGameMessage {
//                     order_id,
//                     game_message,
//                 },
//             ]),
//         };
//         message.print_debug(); // @TODO
//         message.serialize(&mut packet);
//         packet
//     })
//     .collect::<Vec<_>>();

// self.server_sequence_id += (responses_len as u16).into();
// self.server_order_id += (responses_len as u16).into();

// for packet in packets {
//     self.writer_tx.send(packet.get_message().to_vec()).unwrap();
// }

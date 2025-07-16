#![expect(non_snake_case)]
#![expect(dead_code)]
#![expect(unused_imports)]
#![feature(slice_split_once)]

mod client_message;
mod match_server;
mod player_profile;
mod server_message;

use crate::client_message::{ClientMessage, ClientMessageKind};
use crate::server_message::ServerMessage;

use foundation::serde::Deserialize;

// socket -> send, recv

#[repr(C)]
struct ConnectionRequest {
    packet_id: u16,
    remote_sequence_id: u16,
    remote_ack_bits__match_packets_count: u16,
    packet_type: u8,
    unknown_7: u8,
    unknown_8: u8,
    session_id: u32,
}

fn main() {

    let (addr, message) = client.recv_from::<ClientMessage>().unwrap();
    println!("recv: {message:?}");



    println!("Sending connection successful - START");
    client
        .send(ServerMessage {
            remote_sequence_id: 0,
            local_sequence_id: 0, // ?
            local_ack_bits: 0,
            match_packets_count: client_message::raw::udp_match_packets_count_enum::single_packet,
            kind: server_message::ServerMessageKind::ConnectionSuccessful { order_id: 0 },
        })
        .unwrap();
    println!("Sending connection successful - DONE");

    let mut i = 0;
    loop {
        i += 1;
        let message = client.recv::<ClientMessage>();
        println!("recv: {message:?}");

        if i == 1 {
            println!("Sending match options - START");
            client
                .send(ServerMessage {
                    remote_sequence_id: 1,
                    local_sequence_id: 1, // ?
                    local_ack_bits: 0b0100_0000_0000_0000,
                    match_packets_count:
                        client_message::raw::udp_match_packets_count_enum::single_packet,
                    kind: 
                })
                .unwrap();

            // client
            //     .send(ServerMessage {
            //         remote_sequence_id: 2,
            //         local_sequence_id: 1, // ?
            //         local_ack_bits: 0b0100_0000_0000_0000,
            //         match_packets_count:
            //             client_message::raw::udp_match_packets_count_enum::single_packet,
            //         kind: server_message::ServerMessageKind::MatchOptions {
            //             order_id: 1,
            //             map_id: 0,
            //             map_name: "lobby_scene".to_string(),
            //             match_mode: server_message::raw::game_mode_type::gather_victory_items,
            //             player_count: 2,
            //             victory_item_count: 10,
            //             respawn_time: 10,
            //             match_time: 15 * 60,
            //         },
            //     })
            //     .unwrap();

            client
                .send(ServerMessage {
                    remote_sequence_id: 2,
                    local_sequence_id: 1, // ?
                    local_ack_bits: 0b0100_0000_0000_0000,
                    match_packets_count:
                        client_message::raw::udp_match_packets_count_enum::single_packet,
                    kind: 
                })
                .unwrap();

            client
                .send(ServerMessage {
                    remote_sequence_id: 3,
                    local_sequence_id: 1, // ?
                    local_ack_bits: 0b0100_0000_0000_0000,
                    match_packets_count:
                        client_message::raw::udp_match_packets_count_enum::single_packet,
                    kind: 
                })
                .unwrap();
            println!("Sending match options - DONE");
        }
    }
}

//  UDP    0.0.0.0:56249          127.0.0.1:25100        [survarium.exe] DBB9 |  <> 620C
// [survarium.exe]
//
//  UDP    0.0.0.0:63287          *:*                     | F737
// [survarium.exe]
//
//  UDP    127.0.0.1:1900         *:*                     | 76C

//  UDP    0.0.0.0:56249          127.0.0.1:25100
// [survarium.exe]
//  UDP    0.0.0.0:62479          *:*
// [survarium.exe]
//

// UDP    0.0.0.0:53040          127.0.0.1:25100
// [survarium.exe]
// UDP    0.0.0.0:53042          *:*
// [survarium.exe]

// 0. Check in IDA 25100
// 1. How packet is built
// 2. How packet is sent
// 3. How packet is received
//
// NOTES:
// * `vostok::network_core::udp_match_connection::process_incoming_packet<vostok::network_core::process_packet_predicate>(`
// * happens after error log
//      game <ERROR>	[20:17:47:613]	[R] connect_to_game_server: 127.0.0.1: 1236 game time is 230496

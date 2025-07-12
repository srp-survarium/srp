#![expect(non_snake_case)]
#![expect(dead_code)]
#![expect(unused_imports)]
#![feature(slice_split_once)]

mod client_message;
mod player_profile;
mod server_message;

use crate::client_message::{ClientMessage, ClientMessageKind};
use crate::server_message::ServerMessage;

use foundation::config;
use foundation::network_client::UdpClient;
use foundation::serde::Deserialize;

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
    let mut client = UdpClient::new(format!(
        "{}:{}",
        config::match_server::ADDRESS,
        config::match_server::PORT
    ))
    .unwrap();

    let (addr, message) = client.recv_from::<ClientMessage>().unwrap();
    println!("recv: {message:?}");

    if message.kinds.len() != 1 {
        panic!("Unknown message!");
    }
    let ClientMessageKind::ConnectionRequest {
        sent_order_id: _,
        session_id: _,
    } = message.kinds[0]
    else {
        panic!("Unknown message!");
    };

    client.connect(addr).unwrap();

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
                    kind: server_message::ServerMessageKind::MatchOptions {
                        order_id: 1,
                        map_id: 0,
                        map_name: "level_03".to_string(),
                        match_mode: server_message::raw::game_mode_type::gather_victory_items,
                        player_count: 2,
                        victory_item_count: 10,
                        respawn_time: 10,
                        match_time: 15 * 60,
                    },
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
                    kind: server_message::ServerMessageKind::PlayerProfile {
                        order_id: 2,
                        player_profile: player_profile::raw::player_profile {
                            team: player_profile::raw::game_team_id::team_1,
                            is_local: true,
                            ..player_profile::raw::player_profile::new_dummy(0, 0, "sheepy")
                        },
                    },
                })
                .unwrap();

            client
                .send(ServerMessage {
                    remote_sequence_id: 3,
                    local_sequence_id: 1, // ?
                    local_ack_bits: 0b0100_0000_0000_0000,
                    match_packets_count:
                        client_message::raw::udp_match_packets_count_enum::single_packet,
                    kind: server_message::ServerMessageKind::PlayerProfile {
                        order_id: 3,
                        player_profile: player_profile::raw::player_profile {
                            team: player_profile::raw::game_team_id::team_2,
                            is_local: false,
                            ..player_profile::raw::player_profile::new_dummy(0, 0, "beauty")
                        },
                    },
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

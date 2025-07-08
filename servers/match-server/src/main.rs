#![expect(non_snake_case)]
#![expect(dead_code)]
#![expect(irrefutable_let_patterns)]
#![allow(unused_imports)]

mod client_message;
mod server_message;

use crate::client_message::{ClientMessage, ClientMessageKind};
use crate::server_message::ServerMessage;

use foundation::config;
use foundation::network_client::UdpClient;

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
// *(_WORD *)&packet->m_buffer.elems[4] = (packet_type == udp_match_multiple_packets)
//                                      | (unsigned __int16)(2 * this->m_remote_acknowledgement_bits)

// <  id >  < ?? >  < ?? >  <t>  <dataf  | session_id |
// [00, 00, ff, ff, 00, 00, 40 , 00, 00, 00, dd, 00, 00]
//                           6           9   10  11  12
// 0    1    2   3   4   5        7   8
//
// 127.0.0.1:
// 255 255 255 255
// [01, 00, ff, ff, 01, 00, 01, 02]
// [02, 00, ff, ff, 01, 00, 01, 02]
// [03, 00, ff, ff, 01, 00, 01, 02]
// [04, 00, ff, ff, 01, 00, 01, 02]
// [05, 00, ff, ff, 01, 00, 01, 02]
// [06, 00, ff, ff, 01, 00, 01, 02]
// [07, 00, ff, ff, 01, 00, 01, 02]
// [08, 00, ff, ff, 01, 00, 01, 02]
// [09, 00, ff, ff, 01, 00, 01, 02]
// [0a, 00, ff, ff, 01, 00, 01, 02]
// [0b, 00, ff, ff, 01, 00, 01, 02]
// [0c, 00, ff, ff, 01, 00, 01, 02]
// [0d, 00, ff, ff, 01, 00, 01, 02]
// [0e, 00, ff, ff, 00, 00, 40, 00, 00, 00, dd, 00, 00]
// [0f, 00, ff, ff, 01, 00, 01, 02]
// [10, 00, ff, ff, 01, 00, 01, 02]
// [11, 00, ff, ff, 01, 00, 01, 02]
// [12, 00, ff, ff, 01, 00, 01, 02]
// [13, 00, ff, ff, 01, 00, 01, 02]
// [14, 00, ff, ff, 01, 00, 01, 02]
// [15, 00, ff, ff, 01, 00, 01, 02]
// [16, 00, ff, ff, 01, 00, 01, 02]
// [17, 00, ff, ff, 01, 00, 01, 02]
// [18, 00, ff, ff, 01, 00, 01, 02]
// [19, 00, ff, ff, 01, 00, 01, 02]
// [1a, 00, ff, ff, 01, 00, 01, 02]
// [1b, 00, ff, ff, 01, 00, 01, 02]
// [1c, 00, ff, ff, 01, 00, 01, 02]
// [1d, 00, ff, ff, 00, 00, 40, 00, 00, 00, dd, 00, 00]
// [1e, 00, ff, ff, 01, 00, 01, 02]
// [1f, 00, ff, ff, 01, 00, 01, 02]
// [20, 00, ff, ff, 01, 00, 01, 02]

pub mod raw {
    #![expect(non_camel_case_types)]
    #![expect(dead_code)]

    #[repr(u8)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    #[rustfmt::skip]
    enum udp_match_packets_count_enum {
        udp_match_single_packet    = 0x0,
        udp_match_multiple_packets = 0x1,
    }
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
    let ClientMessageKind::ConnectionRequest {
        unknown_1: _,
        session_id: _,
    } = message.kind
    else {
        panic!("Unknown message!");
    };

    client.connect(addr).unwrap();
    // client
    //     .send(ServerMessage {
    //         remote_sequence_id: 0,
    //         local_sequence_id: 0xFFFF,
    //         bits: 0,
    //         kind: server_message::ServerMessageKind::ConnectionSuccessful,
    //     })
    //     .unwrap();

    loop {
        let message = client.recv_raw().unwrap();
        println!("recv: {message:?}");
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
// 1. how packet is built
//  ???
// 2. how packet is sent
//
//
// 3. How packet is received
// * `vostok::network_core::udp_match_connection::process_incoming_packet<vostok::network_core::process_packet_predicate>(`
// * happens after error log
//      game <ERROR>	[20:17:47:613]	[R] connect_to_game_server: 127.0.0.1: 1236 game time is 230496

// 0b0000_0000_0000_0001
//                     ^ >> 1
// 0b1000_0000_0000_0000
//
// if second bit is 0 => multiple
// if second bit is 1 => single
//
//predicate->m_client->m_on_packet_received
//
//Check if on_packed_received acknowledged our type

//
//     let buffer = &mut buffer.as_mut_slice();
//
//     extend(buffer, 2_u16.to_le_bytes()); // remote_sequence_id
//     extend(buffer, 0xFFFF_u16.to_le_bytes()); // local_sequence_id
//     extend(buffer, 0_u16.to_le_bytes()); // bits
//     push(
//         buffer,
//         match_server_message_types_enum::match_options_message_type as u8,
//     );
//
//     extend(buffer, 0_u16.to_le_bytes());
//     extend(buffer, 0_u16.to_le_bytes());
//
//     // let result = socket.send(&buffer);
//     // println!("{result:?}");
// }

// for i in 0..10 {
//     let buffer = &mut buffer.as_mut_slice();
//
//     extend(buffer, (i + 3_u16).to_le_bytes()); // remote_sequence_id
//     extend(buffer, 0xFFFF_u16.to_le_bytes()); // local_sequence_id
//     extend(buffer, 0_u16.to_le_bytes()); // bits
//     push(buffer, match_server_message_types_enum::spawn_player as u8);
//
//     extend(buffer, 0_u16.to_le_bytes());
//     extend(buffer, 0_u16.to_le_bytes());
//
//     // let result = socket.send(&buffer);
//     // println!("{result:?}");
// }

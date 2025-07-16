use foundation::network_client::NetworkRequest;
use foundation::serde::advance_buffer;
use foundation::serde::{Deserialize, DeserializeError};

use self::raw::*;

#[derive(Debug, PartialEq, Clone)]
pub struct UdpMessage {
    pub sequence_id: u16,        // sequence id of the client
    pub remote_sequence_id: u16, // sequence id of the server
    pub remote_ack_bits: u16,    // ???
    pub kinds: Vec<UdpMessageKind>,
}

#[derive(Debug, PartialEq, Clone)]
pub enum UdpMessageKind {
    Low(UdpLowLevelKind),
    Message {
        order_id: u16,
        game_message: GameMessage,
    },
}

#[derive(Debug, PartialEq, Clone)]
pub enum UdpLowLevelKind {
    InitiateDisconnection,
    ConfirmDisconnection,
    ContinuousFlow,
}

#[derive(Debug, PartialEq, Clone)]
pub enum GameMessage {
    ConnectionRequest { session_id: u32 },
    GetStartupInfo,
    ClientPlayerUpdate { unknown: Box<[u8; 44]> },
}

pub mod raw {
    #![expect(non_camel_case_types)]
    #![expect(dead_code)]

    #[repr(u8)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    #[rustfmt::skip]
    pub enum low_level_message_type_enum {
        initiate_disconnection = 0x0,
        confirm_disconnection  = 0x1,
        continuous_flow        = 0x2,
    }

    #[repr(u8)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    #[rustfmt::skip]
    pub enum match_client_message_types_enum {
        connection_request                 = 0x40, // 64
        get_startup_info                   = 0x41,
        join_match                         = 0x42, // !!!!
        client_player_update               = 0x43,
        client_player_commit_suicide       = 0x44,
        time_synchronization_request       = 0x45, // process_sync_response | sync_response
        time_synchronization_confirmation  = 0x46,
        bullets_info_request               = 0x47,
        team_bases_initialize_info         = 0x48, // !!!!
        force_finish_match                 = 0x49,
        world_synchronization_confirmation = 0x4A, // 74
        match_client_invalid_message_type  = 0x7F,
    }

    #[repr(u8)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    #[rustfmt::skip]
    pub enum udp_match_packets_count_enum {
        single_packet    = 0x0,
        multiple_packets = 0x1,
    }
}

impl NetworkRequest for UdpMessage {}

impl Deserialize for UdpMessage {
    fn deserialize(out_buffer: &mut &[u8]) -> Result<Self, DeserializeError> {
        let sequence_id = advance_buffer::<u16>(out_buffer)?;
        let remote_sequence_id = advance_buffer::<u16>(out_buffer)?;

        let word = advance_buffer::<u16>(out_buffer)?;
        let remote_ack_bits = word >> 1;

        let match_packets_count = (word & 1) as u8;
        let match_packets_count =
            bytemuck::checked::cast::<_, udp_match_packets_count_enum>(match_packets_count);

        let mut kinds = vec![];
        match match_packets_count {
            udp_match_packets_count_enum::single_packet => {
                let kind = UdpMessageKind::parse_kind(out_buffer)?;
                kinds.push(kind);
            }
            udp_match_packets_count_enum::multiple_packets => loop {
                let kind_len = advance_buffer::<u8>(out_buffer)? as usize;
                let kind = UdpMessageKind::parse_kind(&mut out_buffer[0..kind_len].as_ref())?;
                kinds.push(kind);

                *out_buffer = out_buffer[kind_len..].as_ref();
                if out_buffer.is_empty() {
                    break;
                }
            },
        }

        if !out_buffer.is_empty() {
            return Err(DeserializeError::incorrect_input());
        }

        Ok(Self {
            sequence_id,
            remote_sequence_id,
            remote_ack_bits,
            kinds,
        })
    }
}

impl UdpMessageKind {
    fn parse_kind(out_buffer: &mut &[u8]) -> Result<Self, DeserializeError> {
        let kind = if let Ok(msg_type) = advance_buffer::<low_level_message_type_enum>(out_buffer) {
            match msg_type {
                low_level_message_type_enum::initiate_disconnection => {
                    Self::Low(UdpLowLevelKind::InitiateDisconnection)
                }
                low_level_message_type_enum::confirm_disconnection => {
                    Self::Low(UdpLowLevelKind::ConfirmDisconnection)
                }
                low_level_message_type_enum::continuous_flow => {
                    Self::Low(UdpLowLevelKind::ContinuousFlow)
                }
            }
        } else {
            let msg_type = advance_buffer::<match_client_message_types_enum>(out_buffer)?;

            let order_id = advance_buffer::<u16>(out_buffer)?;
            let game_message = match msg_type {
                match_client_message_types_enum::connection_request => {
                    let session_id = advance_buffer::<u32>(out_buffer)?;
                    GameMessage::ConnectionRequest { session_id }
                }
                match_client_message_types_enum::get_startup_info => GameMessage::GetStartupInfo,
                match_client_message_types_enum::client_player_update => {
                    let unknown = advance_buffer::<[u8; 44]>(out_buffer)?;
                    GameMessage::ClientPlayerUpdate {
                        unknown: Box::new(unknown),
                    }
                }
                _ => return Err(DeserializeError::UnknownMessageType(msg_type as u8)),
            };
            Self::Message {
                order_id,
                game_message,
            }
        };

        if !out_buffer.is_empty() {
            return Err(DeserializeError::incorrect_input());
        }

        Ok(kind)
    }
}

// #[cfg(test)]
// mod test {
//     use super::*;

//     #[test]
//     fn parses_connect_request() {
//         let buffer: &[u8] = &[15, 0, 255, 255, 0, 0, 64, 0, 0, 0, 221, 0, 0];
//         let defacto = ClientMessage::deserialize(&mut buffer.as_ref()).unwrap();
//         let dejure = ClientMessage {
//             sequence_id: 15,
//             remote_sequence_id: 0xFFFF,
//             remote_ack_bits: 0,
//             kinds: vec![ClientMessageKind::ConnectionRequest {
//                 sent_order_id: 0,
//                 session_id: 56576,
//             }],
//         };
//         assert_eq!(defacto, dejure);
//     }

//     #[test]
//     fn parses_unknown() {
//         let buffer: &[u8] = &[14, 0, 255, 255, 1, 0, 1, 2];
//         let defacto = ClientMessage::deserialize(&mut buffer.as_ref()).unwrap();
//         let dejure = ClientMessage {
//             sequence_id: 14,
//             remote_sequence_id: 0xFFFF,
//             remote_ack_bits: 0,
//             kinds: vec![ClientMessageKind::ContinuousFlow {}],
//         };
//         assert_eq!(defacto, dejure);
//     }

//     #[test]
//     fn parses_client_player_update() {
//         #[rustfmt::skip]
//         let buffer: &[u8] = &[
//             252, 5, 0, 0, 1, 0,
//             // kind 0
//             47, 67, 81, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 210, 112, 50, 39, 128, 155, 196, 59, 231, 52, 1, 167, 218, 15, 73, 192, 0, 0, 0, 0, 247, 57, 0, 0,
//             // kind 1
//             47, 67, 80, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 210, 112, 50, 39, 128, 155, 196, 59, 231, 52, 1, 167, 218, 15, 73, 192, 0, 0, 0, 0, 241, 57, 0, 0,
//             // kind 2
//             47, 67, 79, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 210, 112, 50, 39, 128, 155, 196, 59, 231, 52, 1, 167, 218, 15, 73, 192, 0, 0, 0, 0, 237, 57, 0, 0,
//             // kind 3
//             47, 67, 78, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 210, 112, 50, 39, 128, 155, 196, 59, 231, 52, 1, 167, 218, 15, 73, 192, 0, 0, 0, 0, 232, 57, 0, 0,
//             // kind 4
//             47, 67, 77, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 210, 112, 50, 39, 128, 155, 196, 59, 231, 52, 1, 167, 218, 15, 73, 192, 0, 0, 0, 0, 227, 57, 0, 0,
//         ];

//         let message = ClientMessage::deserialize(&mut buffer.as_ref()).unwrap();
//         assert_eq!(message.sequence_id, 1532);
//         assert_eq!(message.remote_sequence_id, 0);
//         assert_eq!(message.remote_ack_bits, 0);
//         assert_eq!(message.kinds.len(), 5);
//     }
// }

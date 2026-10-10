// SPDX-License-Identifier: GPL-3.0-or-later
use survarium::player_input::{player_input, player_state};
use vostok::network_client::NetworkRequest;
use vostok::serde::advance_buffer;
use vostok::serde::{Deserialize, DeserializeError};

use crate::message::raw::{low_level_message_type_enum, udp_match_packets_count_enum};
use crate::sequence_number::SN16;

use self::raw::*;

#[derive(Debug, PartialEq, Clone)]
pub struct ClientMessage {
    /// Sequential id for the messages sent by the client
    pub local_sequence_id: SN16,
    /// @TODO: Understand exactly what it means
    /// Maybe: Last sequential id received from the server
    pub remote_sequence_id: SN16,
    /// @TODO: Understand exactly what it means
    pub remote_ack_bits: u16,
    pub kind: ClientMessageKind,
}

#[derive(Debug, PartialEq, Clone)]
pub enum ClientMessageKind {
    Low(low_level_message_type_enum),
    Messages(Vec<ClientGameMessage>),
}

#[derive(Debug, PartialEq, Clone)]
pub struct ClientGameMessage {
    pub order_id: SN16,
    pub game_message: ClientGameMessageKind,
}

#[derive(Debug, PartialEq, Clone)]
pub enum ClientGameMessageKind {
    ConnectionRequest {
        session_id: u32,
    },
    GetStartupInfo,
    JoinMatch,
    ClientPlayerUpdate {
        player_input: player_input,
        player_state: player_state,
        time_in_ms: u32,
    },
    TimeSynchronizationRequest {
        dunno: u32,
    },
    TimeSynchronizationConfirmation,
    TeamBasesInitializeInfo,
}

const _: () = assert!(
    std::mem::size_of::<player_input>()
        + std::mem::size_of::<player_state>()
        + std::mem::size_of::<u32>()
        == 44
);

pub mod raw {
    #![expect(non_camel_case_types)]
    #![expect(dead_code)]

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
}

impl NetworkRequest for ClientMessage {}

impl Deserialize for ClientMessage {
    fn deserialize(out_buffer: &mut &[u8]) -> Result<Self, DeserializeError> {
        let local_sequence_id = advance_buffer::<SN16>(out_buffer)?;
        let remote_sequence_id = advance_buffer::<SN16>(out_buffer)?;

        let word = advance_buffer::<u16>(out_buffer)?;
        let remote_ack_bits = word >> 1 | 0x8000;

        let match_packets_count = (word & 1) as u8;
        let match_packets_count =
            bytemuck::checked::cast::<_, udp_match_packets_count_enum>(match_packets_count);

        let kind = ClientMessageKind::parse(match_packets_count, out_buffer)?;

        if !out_buffer.is_empty() {
            return Err(DeserializeError::incorrect_input());
        }

        Ok(Self {
            local_sequence_id,
            remote_sequence_id,
            remote_ack_bits,
            kind,
        })
    }
}

impl ClientMessageKind {
    fn parse(
        match_packets_count: udp_match_packets_count_enum,
        out_buffer: &mut &[u8],
    ) -> Result<Self, DeserializeError> {
        let kind = match match_packets_count {
            udp_match_packets_count_enum::single_packet => {
                let message = ClientGameMessage::parse(out_buffer)?;
                Self::Messages(vec![message])
            }
            udp_match_packets_count_enum::multiple_packets => {
                let mut messages = vec![];
                let message_len = advance_buffer::<u8>(out_buffer)? as usize;
                if let Ok(msg_type) = advance_buffer::<low_level_message_type_enum>(out_buffer) {
                    Self::Low(msg_type)
                } else {
                    let message =
                        ClientGameMessage::parse(&mut out_buffer[0..message_len].as_ref())?;
                    messages.push(message);
                    *out_buffer = out_buffer[message_len..].as_ref();

                    loop {
                        if out_buffer.is_empty() {
                            break;
                        }
                        let message_len = advance_buffer::<u8>(out_buffer)? as usize;
                        let message =
                            ClientGameMessage::parse(&mut out_buffer[0..message_len].as_ref())?;
                        messages.push(message);
                        *out_buffer = out_buffer[message_len..].as_ref();
                    }

                    Self::Messages(messages)
                }
            }
        };
        Ok(kind)
    }
}

impl ClientGameMessage {
    fn parse(out_buffer: &mut &[u8]) -> Result<Self, DeserializeError> {
        let msg_type = advance_buffer::<match_client_message_types_enum>(out_buffer)?;
        let order_id = advance_buffer::<SN16>(out_buffer)?;
        let game_message = ClientGameMessageKind::parse(msg_type, out_buffer)?;
        Ok(Self {
            order_id,
            game_message,
        })
    }
}

impl ClientGameMessageKind {
    fn parse(
        msg_type: match_client_message_types_enum,
        out_buffer: &mut &[u8],
    ) -> Result<Self, DeserializeError> {
        let msg = match msg_type {
            match_client_message_types_enum::connection_request => {
                let session_id = advance_buffer::<u32>(out_buffer)?;
                Self::ConnectionRequest { session_id }
            }
            match_client_message_types_enum::get_startup_info => Self::GetStartupInfo,
            match_client_message_types_enum::join_match => Self::JoinMatch,
            match_client_message_types_enum::client_player_update => {
                let player_input = advance_buffer::<player_input>(out_buffer)?;
                let player_state = advance_buffer::<player_state>(out_buffer)?;
                let time_in_ms = advance_buffer::<u32>(out_buffer)?;
                Self::ClientPlayerUpdate {
                    player_input,
                    player_state,
                    time_in_ms,
                }
            }
            match_client_message_types_enum::time_synchronization_request => {
                let dunno = advance_buffer::<u32>(out_buffer)?;
                Self::TimeSynchronizationRequest { dunno }
            }
            match_client_message_types_enum::time_synchronization_confirmation => {
                Self::TimeSynchronizationConfirmation
            }

            match_client_message_types_enum::team_bases_initialize_info => {
                Self::TeamBasesInitializeInfo
            }
            _ => return Err(DeserializeError::UnknownMessageType(msg_type as u8)),
        };
        Ok(msg)
    }
}

impl ClientGameMessageKind {
    #[rustfmt::skip]
    pub fn message_type(&self) -> match_client_message_types_enum {
        match self {
            Self::ConnectionRequest { .. }               => match_client_message_types_enum::connection_request,
            Self::GetStartupInfo { .. }                  => match_client_message_types_enum::get_startup_info,
            Self::JoinMatch { .. }                       => match_client_message_types_enum::join_match,
            Self::ClientPlayerUpdate { .. }              => match_client_message_types_enum::client_player_update,
            Self::TimeSynchronizationRequest { .. }      => match_client_message_types_enum::time_synchronization_request,
            Self::TimeSynchronizationConfirmation { .. } => match_client_message_types_enum::time_synchronization_confirmation,
            Self::TeamBasesInitializeInfo { .. }         => match_client_message_types_enum::team_bases_initialize_info,
        }
    }
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn parses_connect_request() {
        let buffer: &[u8] = &[15, 0, 255, 255, 0, 0, 64, 0, 0, 0, 221, 0, 0];
        let defacto = ClientMessage::deserialize(&mut buffer.as_ref()).unwrap();
        let dejure = ClientMessage {
            local_sequence_id: 15.into(),
            remote_sequence_id: 0xFFFF.into(),
            remote_ack_bits: 0x8000,
            kind: ClientMessageKind::Messages(vec![ClientGameMessage {
                order_id: SN16(0),
                game_message: ClientGameMessageKind::ConnectionRequest { session_id: 56576 },
            }]),
        };
        assert_eq!(defacto, dejure);
    }

    #[test]
    fn parses_unknown() {
        let buffer: &[u8] = &[14, 0, 255, 255, 1, 0, 1, 2];
        let defacto = ClientMessage::deserialize(&mut buffer.as_ref()).unwrap();
        let dejure = ClientMessage {
            local_sequence_id: 14.into(),
            remote_sequence_id: 0xFFFF.into(),
            remote_ack_bits: 0x8000,
            kind: ClientMessageKind::Low(low_level_message_type_enum::continuous_flow),
        };
        assert_eq!(defacto, dejure);
    }

    #[test]
    fn parses_client_player_update() {
        #[rustfmt::skip]
        let buffer: &[u8] = &[
            252, 5, 0, 0, 1, 0,
            // kind 0
            47, 67, 81, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 210, 112, 50, 39, 128, 155, 196, 59, 231, 52, 1, 167, 218, 15, 73, 192, 0, 0, 0, 0, 247, 57, 0, 0,
            // kind 1
            47, 67, 80, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 210, 112, 50, 39, 128, 155, 196, 59, 231, 52, 1, 167, 218, 15, 73, 192, 0, 0, 0, 0, 241, 57, 0, 0,
            // kind 2
            47, 67, 79, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 210, 112, 50, 39, 128, 155, 196, 59, 231, 52, 1, 167, 218, 15, 73, 192, 0, 0, 0, 0, 237, 57, 0, 0,
            // kind 3
            47, 67, 78, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 210, 112, 50, 39, 128, 155, 196, 59, 231, 52, 1, 167, 218, 15, 73, 192, 0, 0, 0, 0, 232, 57, 0, 0,
            // kind 4
            47, 67, 77, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 210, 112, 50, 39, 128, 155, 196, 59, 231, 52, 1, 167, 218, 15, 73, 192, 0, 0, 0, 0, 227, 57, 0, 0,
        ];

        let message = ClientMessage::deserialize(&mut buffer.as_ref()).unwrap();
        assert_eq!(message.local_sequence_id, 1532.into());
        assert_eq!(message.remote_sequence_id, 0.into());
        assert_eq!(message.remote_ack_bits, 0x8000);
        let ClientMessageKind::Messages(messages) = message.kind else {
            panic!();
        };
        assert_eq!(messages.len(), 5);
    }

    #[test]
    fn fails_to_parse_new_message_types() {
        #[rustfmt::skip]
        let buffer: &[u8] = &[
            186, 2,
            5, 0,
            1, 248,
            47, 67, 235, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 210, 112, 50, 39, 128, 155, 196, 59, 231, 52, 1, 167, 218, 15, 73, 192, 0, 0, 0, 0, 109, 47, 0, 0,
            47, 67, 236, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 210, 112, 50, 39, 128, 155, 196, 59, 231, 52, 1, 167, 218, 15, 73, 192, 0, 0, 0, 0, 121, 47, 0, 0,
            47, 67, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 210, 112, 50, 39, 128, 155, 196, 59, 231, 52, 1, 167, 218, 15, 73, 192, 0, 0, 0, 0, 94, 49, 0, 0,
            47, 67, 21, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 210, 112, 50, 39, 128, 155, 196, 59, 231, 52, 1, 167, 218, 15, 73, 192, 0, 0, 0, 0, 81, 49, 0, 0,
            47, 67, 225, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 210, 112, 50, 39, 128, 155, 196, 59, 231, 52, 1, 167, 218, 15, 73, 192, 0, 0, 0, 0, 252, 46, 0, 0,
            3, 72, 52, 1,
            3, 66, 53, 1
        ];

        let message = ClientMessage::deserialize(&mut buffer.as_ref()).unwrap_err();
        assert!(matches!(message, DeserializeError::UnknownMessageType(_)));
    }
}

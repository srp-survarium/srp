use foundation::network_client::NetworkRequest;
use foundation::serde::advance_buffer;
use foundation::serde::{Deserialize, DeserializeError};

use self::raw::*;

#[derive(Debug, PartialEq, Copy, Clone)]
pub struct ClientMessage {
    pub local_sequence_id: u16,
    pub remote_sequence_id: u16,
    pub remote_ack_bits__match_packets_count: u16,
    pub kind: ClientMessageKind,
}

#[derive(Debug, PartialEq, Copy, Clone)]
pub enum ClientMessageKind {
    ConnectionRequest { unknown_1: u16, session_id: u32 },
}

pub mod raw {
    #![expect(non_camel_case_types)]
    #![expect(dead_code)]

    #[repr(u8)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    #[rustfmt::skip]
    pub enum match_client_message_types_enum {
        connection_request                 = 0x40,
        get_startup_info                   = 0x41,
        join_match                         = 0x42,
        client_player_update               = 0x43,
        client_player_commit_suicide       = 0x44,
        time_synchronization_request       = 0x45,
        time_synchronization_confirmation  = 0x46,
        bullets_info_request               = 0x47,
        team_bases_initialize_info         = 0x48,
        force_finish_match                 = 0x49,
        world_synchronization_confirmation = 0x4A,
        match_client_invalid_message_type  = 0x7F,
    }
}

impl NetworkRequest for ClientMessage {}

impl Deserialize for ClientMessage {
    fn deserialize(out_buffer: &mut &[u8]) -> Result<Self, DeserializeError> {
        let local_sequence_id = advance_buffer::<u16>(out_buffer)?;
        let remote_sequence_id = advance_buffer::<u16>(out_buffer)?;
        let remote_ack_bits__match_packets_count = advance_buffer::<u16>(out_buffer)?;

        let msg_type = advance_buffer::<match_client_message_types_enum>(out_buffer)?;
        let kind = match msg_type {
            match_client_message_types_enum::connection_request => {
                let unknown_1 = advance_buffer::<u16>(out_buffer)?;
                let session_id = advance_buffer::<u32>(out_buffer)?;

                ClientMessageKind::ConnectionRequest {
                    unknown_1,
                    session_id,
                }
            }
            _ => todo!(),
        };

        if !out_buffer.is_empty() {
            return Err(DeserializeError::incorrect_input());
        }

        Ok(Self {
            local_sequence_id,
            remote_sequence_id,
            remote_ack_bits__match_packets_count,
            kind,
        })
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
            local_sequence_id: 15,
            remote_sequence_id: 0xFFFF,
            remote_ack_bits__match_packets_count: 0,
            kind: ClientMessageKind::ConnectionRequest {
                unknown_1: 0,
                session_id: 56576,
            },
        };
        assert_eq!(defacto, dejure);
    }

    #[test]
    #[should_panic]
    fn not_parses_what() {
        let buffer: &[u8] = &[14, 0, 255, 255, 1, 0, 1, 2];
        ClientMessage::deserialize(&mut buffer.as_ref()).unwrap();
    }
}

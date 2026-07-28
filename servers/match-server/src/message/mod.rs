pub mod client_message;
pub mod server_message;

pub use client_message::{
    ClientGameMessage, ClientGameMessageKind, ClientMessage, ClientMessageKind,
};
pub use server_message::{
    ServerGameMessage, ServerGameMessageKind, ServerMessage, ServerMessageKind,
};

pub const CLIENT_PLAYER_HIT_VERSION: u8 = 1;
pub const MAX_HIT_STRING_LENGTH: usize = 15;

#[derive(Debug, PartialEq, Clone)]
pub struct PlayerHit {
    pub hit_initiator: u8,
    pub being_hit: u8,
    pub body_part: String,
    pub damage_type: String,
    pub amount: f32,
    pub armor_piercing: f32,
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
    pub enum udp_match_packets_count_enum {
        single_packet    = 0x0,
        multiple_packets = 0x1,
    }
}

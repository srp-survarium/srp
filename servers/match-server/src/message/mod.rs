pub mod client_message;
pub mod server_message;

pub use client_message::{
    ClientGameMessage, ClientGameMessageKind, ClientMessage, ClientMessageKind,
};
pub use server_message::{
    ServerGameMessage, ServerGameMessageKind, ServerMessage, ServerMessageKind,
};

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

    // TODO: I think this now means something aka `has_low_level_messages`
    #[repr(u8)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    #[rustfmt::skip]
    pub enum udp_match_packets_count_enum {
        single_packet    = 0x0,
        multiple_packets = 0x1,
    }
}

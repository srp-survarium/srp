pub mod client_message;
pub mod server_message;

pub use client_message::{ClientGameMessage, ClientMessage, ClientMessageKind};
pub use server_message::{
    ServerGameMessage, ServerGameMessageKind, ServerMessage, ServerMessageKind,
};

// #[derive(Debug, PartialEq, Clone)]
// pub enum LowLevelMessage {
//     InitiateDisconnection,
//     ConfirmDisconnection,
//     ContinuousFlow,
// }

pub mod raw {
    #![expect(non_camel_case_types)]

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

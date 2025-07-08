use foundation::network_client::NetworkResponse;
use foundation::network_packet::Packet;
use foundation::serde::Serialize;

use self::raw::*;
use crate::client_message::raw::udp_match_packets_count_enum;

#[derive(Debug, PartialEq, Copy, Clone)]
pub struct ServerMessage {
    pub remote_sequence_id: u16,
    pub local_sequence_id: u16,
    pub local_ack_bits: u16,
    pub match_packets_count: udp_match_packets_count_enum,
    pub kind: ServerMessageKind,
}

#[derive(Debug, PartialEq, Copy, Clone)]
pub enum ServerMessageKind {
    ConnectionSuccessful {
        // Is processed, when bigger than `received_order_id`, which is 0xFF at the beginning?
        order_id: u16,
    },
}

impl ServerMessageKind {
    #[rustfmt::skip]
    fn tag(&self) -> match_server_message_types_enum {
        match self {
            Self::ConnectionSuccessful { .. } => match_server_message_types_enum::match_server_connection_successful,
        }
    }
}

pub mod raw {
    #![expect(non_camel_case_types)]
    #![expect(dead_code)]

    #[repr(u8)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    #[rustfmt::skip]
    pub enum match_server_message_types_enum {
        match_server_connection_successful = 0x80, // changes connection_type to connected
        match_options_message_type         = 0x81,
        server_player_input                = 0x82,
        kill_player                        = 0x83,
        spawn_player                       = 0x84,
        team_base_capture_progress         = 0x85,
        match_time_changed                 = 0x86,
        respawn_time_changed               = 0x87,
        player_kd_stats_changed            = 0x88,
        hit_player                         = 0x89,
        affect_damage_model                = 0x8A,
        sync_response                      = 0x8B,
        match_finished                     = 0x8C,
        server_bullet_added                = 0x8D,
        server_bullet_removed              = 0x8E,
        server_bullet_moved                = 0x8F,
        server_bullet_collided             = 0x90,
        player_visibility_changed          = 0x91,
        player_profile_message_type        = 0x92,
        team_bases_message_type            = 0x93,
        initialize_victory_items           = 0x94,
        victory_item_take_or_put           = 0x95,
        trap_placed                        = 0x96,
        trap_removed                       = 0x97,
        trap_fired                         = 0x98,
        trap_disarmed                      = 0x99,
        game_status_changed                = 0x9A,
        match_wait_time_changed            = 0x9B,
        game_world_object_state            = 0x9C,
        world_synchronization_request      = 0x9D,
        damage_model_state                 = 0x9E,
        match_server_invalid_message_type  = 0xC0,
    }
}

impl NetworkResponse for ServerMessage {}

impl Serialize for ServerMessage {
    fn serialize(self, packet: &mut impl Packet) {
        packet.write(self.remote_sequence_id);
        packet.write(self.local_sequence_id);
        packet.write(self.local_ack_bits << 1 | (self.match_packets_count as u16));
        packet.write(self.kind.tag());

        match self.kind {
            ServerMessageKind::ConnectionSuccessful { order_id } => packet.write(order_id),
        }
    }
}

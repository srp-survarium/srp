// SPDX-License-Identifier: GPL-3.0-or-later
use survarium::player_input::{
    player, player_input, player_inventory_slot, player_stamina, player_state, weapon_core,
    weapon_core_state, weapon_state,
};
use survarium::player_profile::raw::player_profile;
use vostok::network_client::NetworkResponse;
use vostok::network_packet::Packet;
use vostok::serde::Serialize;

use self::raw::*;
use crate::message::raw::{low_level_message_type_enum, udp_match_packets_count_enum};
use crate::sequence_number::SN16;

#[derive(Debug, PartialEq, Clone)]
pub struct ServerMessage {
    /// Sequential id of this message
    pub remote_sequence_id: SN16,
    /// TODO: ?
    pub local_sequence_id: SN16,
    /// TODO: Currently we only can send a single packet.
    /// So this means that the first bit in `local_ack_bits` should always be 0
    pub local_ack_bits: u16,

    pub kind: ServerMessageKind,
}

#[derive(Debug, PartialEq, Clone)]
pub enum ServerMessageKind {
    Low(low_level_message_type_enum),
    Messages(Vec<ServerGameMessage>),
}

#[derive(Debug, PartialEq, Clone)]
pub struct ServerGameMessage {
    pub order_id: SN16,
    pub game_message: ServerGameMessageKind,
}

#[expect(dead_code)]
#[derive(Debug, PartialEq, Clone)]
pub enum ServerGameMessageKind {
    ConnectionSuccessful,
    MatchOptions {
        map_id: u8,
        // 32 chars max
        map_name: String,
        match_mode: game_mode_type,
        player_count: u8,
        victory_item_count: u8,
        respawn_time: u8,
        match_time: u16,
    },
    SpawnPlayer {
        player_id: u8,
        player: player,
    },
    ServerPlayerInput {
        player_id: u8,
        player_input: player_input,
        player_state: player_state,
        weapon_state: weapon_state,
    },
    MatchTimeChanged {
        match_time: u32,
    },
    SyncResponse {
        is_connected_bitmask: u32,
    },
    GameStatusChanged {
        game_status: game_status,
    },

    PlayerProfile {
        player_profile: Box<player_profile>,
    },
}

pub mod raw {
    #![expect(non_camel_case_types)]
    #![expect(dead_code)]

    #[repr(u8)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    #[rustfmt::skip]
    pub enum match_server_message_types_enum {
        match_server_connection_successful = 0x80, // changes connection_type to connected
        match_options_message_type         = 0x81, // [+] - survarium::network_client::on_match_packet_received
        server_player_input                = 0x82, //
        kill_player                        = 0x83, //
        spawn_player                       = 0x84, //
        team_base_capture_progress         = 0x85, //
        match_time_changed                 = 0x86, //
        respawn_time_changed               = 0x87, //
        player_kd_stats_changed            = 0x88, //
        hit_player                         = 0x89, //
        affect_damage_model                = 0x8A, //
        sync_response                      = 0x8B, //
        match_finished                     = 0x8C, //
        server_bullet_added                = 0x8D, //
        server_bullet_removed              = 0x8E, //
        server_bullet_moved                = 0x8F, //
        server_bullet_collided             = 0x90, //
        player_visibility_changed          = 0x91, //
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
        damage_model_state                 = 0x9E, // [+] hidden
        match_server_invalid_message_type  = 0xC0,
    }

    #[repr(u8)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    #[rustfmt::skip]
    pub enum game_mode_type {
        capture_enemy_base   = 0x0,
        capture_neutral_base = 0x1,
        gather_victory_items = 0x2,
        invalid_game_mode    = 0xFF,
    }

    #[repr(u32)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    #[rustfmt::skip]
    pub enum game_status {
        inactive                 = 0x0,
        waiting_for_first_player = 0x1,
        waiting_for_players      = 0x2,
        final_countdown          = 0x3,
        inprocess                = 0x4,
    }
}

impl NetworkResponse for ServerMessage {}

impl Serialize for ServerMessage {
    fn serialize(self, packet: &mut impl Packet) {
        packet.write(self.remote_sequence_id);
        packet.write(self.local_sequence_id);

        let match_packets_count = match &self.kind {
            ServerMessageKind::Low(_) => udp_match_packets_count_enum::multiple_packets,
            ServerMessageKind::Messages(messages) if messages.len() == 1 => {
                udp_match_packets_count_enum::single_packet
            }
            _ => udp_match_packets_count_enum::multiple_packets,
        } as u16;
        packet.write(self.local_ack_bits << 1 | match_packets_count);

        self.kind.serialize(packet);
    }
}

impl Serialize for ServerMessageKind {
    fn serialize(self, packet: &mut impl Packet) {
        match self {
            Self::Low(message_type) => {
                packet.write(1_u8); // low level message type size
                packet.write(message_type)
            }
            Self::Messages(mut messages) if messages.len() == 1 => {
                let message = messages.pop().unwrap();
                message.serialize(packet);
            }

            Self::Messages(messages) => {
                for message in messages {
                    packet.write(0_u8);
                    let len_index = packet.cursor_index();

                    message.serialize(packet);

                    let end_packet_idx = packet.cursor_index();
                    let packet_len = end_packet_idx - len_index;

                    // len     packet
                    // [0] [1, 2, 3, 4, 5]
                    //      ^             ^

                    let packet_len: u8 = packet_len.try_into().unwrap();
                    packet.rewrite_bytes(len_index - 1, [packet_len]);
                }
            }
        }
    }
}

impl Serialize for ServerGameMessage {
    fn serialize(self, packet: &mut impl Packet) {
        let Self {
            order_id,
            game_message,
        } = self;

        packet.write(game_message.message_type());
        packet.write(order_id);
        game_message.serialize(packet);
    }
}

impl ServerGameMessageKind {
    #[rustfmt::skip]
    pub fn message_type(&self) -> match_server_message_types_enum {
        match self {
            Self::ConnectionSuccessful { .. } => match_server_message_types_enum::match_server_connection_successful,
            Self::MatchOptions { .. }         => match_server_message_types_enum::match_options_message_type,
            Self::SpawnPlayer { .. }          => match_server_message_types_enum::spawn_player,
            Self::ServerPlayerInput { .. }    => match_server_message_types_enum::server_player_input,
            Self::MatchTimeChanged { .. }     => match_server_message_types_enum::match_time_changed,
            Self::SyncResponse { .. }         => match_server_message_types_enum::sync_response,
            Self::GameStatusChanged { .. }    => match_server_message_types_enum::game_status_changed,
            Self::PlayerProfile { .. }        => match_server_message_types_enum::player_profile_message_type,
        }
    }
}

impl Serialize for ServerGameMessageKind {
    fn serialize(self, packet: &mut impl Packet) {
        // Note that tag is written before `order_id`, which is not part of the message
        match self {
            Self::ConnectionSuccessful {} => (),
            Self::MatchOptions {
                map_id,
                map_name,
                match_mode,
                player_count,
                victory_item_count,
                respawn_time,
                match_time,
            } => {
                packet.write(map_id);
                assert!(map_name.len() < 30);
                packet.write_str(&map_name);
                packet.write(match_mode);
                packet.write(player_count);
                packet.write(victory_item_count);
                packet.write(respawn_time);
                packet.write(match_time);
            }

            Self::SpawnPlayer { player_id, player } => {
                packet.write(player_id);
                let player {
                    position,
                    orientation,
                    look_pitch,
                    is_alive,
                    server_current_active_slot,
                    server_target_active_slot,
                    player_stamina,
                    player_inventory,
                } = player;

                packet.write(position);
                packet.write(orientation);
                packet.write(look_pitch);
                packet.write(is_alive);
                packet.write(server_current_active_slot);
                packet.write(server_target_active_slot);

                let player_stamina {
                    value,
                    last_spending_time_in_ms,
                    last_tick_time_in_ms,
                    lower_threshold_was_reached,
                } = player_stamina;
                packet.write(value);
                packet.write(last_spending_time_in_ms);
                packet.write(last_tick_time_in_ms);
                packet.write(lower_threshold_was_reached);

                for item in player_inventory {
                    match item {
                        player_inventory_slot::weapon_slot(weapon_core) => {
                            let weapon_core {
                                inventory_item,
                                random_seed,
                                normal_random_seed,
                                weapon_target,
                                old_actions_mask,
                                ammo_in_magazine,
                                bullets_in_queue,
                                fire_queue_type,
                                ammo_slot,
                                is_there_chamber_a_round_state,
                                weapon_core_state,
                            } = weapon_core;

                            packet.write(inventory_item);
                            packet.write(random_seed);
                            packet.write(normal_random_seed);
                            packet.write(weapon_target);
                            packet.write(old_actions_mask);
                            packet.write(ammo_in_magazine);
                            packet.write(bullets_in_queue);
                            packet.write(fire_queue_type);
                            packet.write(ammo_slot);
                            if let Some(is_there_chamber_a_round_state) =
                                is_there_chamber_a_round_state
                            {
                                packet.write(is_there_chamber_a_round_state);
                            }
                            if let Some(weapon_core_state) = weapon_core_state {
                                let weapon_core_state {
                                    is_shown,
                                    active_hands,
                                    start_transition_time_in_ms_lhs,
                                    start_transition_time_in_ms_rhs,
                                    weapon_sound_target_state,
                                    logic_sprint_target_state,
                                } = weapon_core_state;
                                packet.write(is_shown);
                                packet.write(active_hands);
                                packet.write(start_transition_time_in_ms_lhs);
                                packet.write(start_transition_time_in_ms_rhs);

                                packet.write(weapon_sound_target_state.0);
                                if let Some((interval_id, interval_time)) =
                                    weapon_sound_target_state.1
                                {
                                    packet.write(interval_id);
                                    packet.write(interval_time);
                                }

                                packet.write(logic_sprint_target_state.0);
                                if let Some((interval_id, interval_time)) =
                                    logic_sprint_target_state.1
                                {
                                    packet.write(interval_id);
                                    packet.write(interval_time);
                                }
                            }
                        }
                        player_inventory_slot::item_amount(amount) => {
                            packet.write(amount);
                        }
                    }
                }
            }

            Self::ServerPlayerInput { .. } => {
                todo!()
            }
            Self::MatchTimeChanged { match_time } => {
                packet.write(match_time);
            }

            Self::SyncResponse {
                is_connected_bitmask,
            } => packet.write(is_connected_bitmask),

            Self::GameStatusChanged { game_status } => {
                packet.write(game_status);
            }

            Self::PlayerProfile { player_profile } => {
                player_profile.serialize_udp(packet);
            }
        }
    }
}

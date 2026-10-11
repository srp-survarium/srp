// SPDX-License-Identifier: GPL-3.0-or-later
use survarium::player_input::{player, player_input, player_state, weapon_state};
use survarium::player_profile::PlayerProfile;
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
    pub local_ack_bits: u64,

    pub kind: ServerMessageKind,
}

#[derive(Debug, PartialEq, Clone)]
pub enum ServerMessageKind {
    Low(low_level_message_type_enum),
    Messages(Vec<ServerGameMessage>),
}

#[derive(Debug, PartialEq, Clone)]
pub struct ServerGameMessage {
    pub order_id: Option<SN16>,
    pub game_message: ServerGameMessageKind,
}

#[expect(dead_code)]
#[derive(Debug, PartialEq, Clone)]
pub enum ServerGameMessageKind {
    ConnectionSuccessful {
        first_port_in_range: u16,
        last_port_in_range: u16,
    },
    StaticMatchInfo {
        map_id: u8,
        map_name: String, // 32
        match_mode: game_mode_type,
        player_count: u8,
        victory_item_count: u8,
        respawn_time: u8,
        match_time: u16,
        match_id: u32,
        wait_player_perceont: f32,
        wait1_time: u8,
        wait2_time: u8,
        countdown_time: u8,
        events_scores: [u16; 21],
        squads: Vec<u8>,             // squads.len() == player_count
        players: Vec<PlayerProfile>, // players.len() == player_count
    }, // MatchOptions {
       //     map_id: u8,
       //     // 32 chars max
       //     map_name: String,
       //     match_mode: game_mode_type,
       //     player_count: u8,
       //     victory_item_count: u8,
       //     respawn_time: u8,
       //     match_time: u16,
       // },
       // SpawnPlayer {
       //     player_id: u8,
       //     player: player,
       // },
       // ServerPlayerInput {
       //     player_id: u8,
       //     player_input: player_input,
       //     player_state: player_state,
       //     weapon_state: weapon_state,
       // },
       // MatchTimeChanged {
       //     match_time: u32,
       // },

       // PlayerProfile {
       //     player_profile: Box<PlayerProfile>,
       // },
}

pub mod raw {
    #![expect(non_camel_case_types)]
    #![expect(dead_code)]

    #[repr(u8)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    #[rustfmt::skip]
    pub enum match_server_message_types_enum {
        match_server_connection_successful = 0x50,
        static_match_info                  = 0x51,
        set_time_request                   = 0x52,
        dynamic_match_info                 = 0x53,
        player_input_change                = 0x54,
        floating_timer_set_offset          = 0x55,
        player_entered_match               = 0x56,
        player_left_match                  = 0x57,
        local_player_input_discard         = 0x58,
        on_hash_mismatch                   = 0x59,
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
}

impl match_server_message_types_enum {
    // TODO: For now all messages are reliable
    //
    // vostok::network_core::udp_match_message_type_info*
    //  survarium::network_packets_orderer<
    //      enum vostok::match::client::messages_enum,
    //      enum vostok::match::server::messages_enum
    //  >::get_received_message_info
    pub fn is_ordered(&self) -> bool {
        use match_server_message_types_enum::*;
        !matches!(
            self,
            match_server_connection_successful
                | player_input_change
                | player_entered_match
                | player_left_match
                | local_player_input_discard
        )
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
        packet.write(self.local_ack_bits << 1 | match_packets_count as u64);

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

        packet.write(game_message.message_type()); // TODO: Can be set to 0xFF for mutlimessage
        if let Some(order_id) = order_id {
            debug_assert!(game_message.message_type().is_ordered());
            packet.write(order_id);
        }
        game_message.serialize(packet);
    }
}

impl ServerGameMessageKind {
    #[rustfmt::skip]
    pub fn message_type(&self) -> match_server_message_types_enum {
        match self {
            Self::ConnectionSuccessful { .. } => match_server_message_types_enum::match_server_connection_successful,
            Self::StaticMatchInfo { .. }      => match_server_message_types_enum::static_match_info,
            // Self::MatchOptions { .. }         => match_server_message_types_enum::match_options_message_type,
            // Self::SpawnPlayer { .. }          => match_server_message_types_enum::spawn_player,
            // Self::ServerPlayerInput { .. }    => match_server_message_types_enum::server_player_input,
            // Self::MatchTimeChanged { .. }     => match_server_message_types_enum::match_time_changed,
            // Self::PlayerProfile { .. }        => match_server_message_types_enum::player_profile_message_type,
        }
    }
}

impl Serialize for ServerGameMessageKind {
    fn serialize(self, packet: &mut impl Packet) {
        // Note that tag is written before `order_id`, which is not part of the message
        match self {
            Self::ConnectionSuccessful {
                first_port_in_range,
                last_port_in_range,
            } => {
                packet.write(first_port_in_range);
                packet.write(last_port_in_range);
            }
            Self::StaticMatchInfo {
                map_id,
                map_name,
                match_mode,
                player_count,
                victory_item_count,
                respawn_time,
                match_time,
                match_id,
                wait_player_perceont,
                wait1_time,
                wait2_time,
                countdown_time,
                events_scores,
                squads,
                players,
            } => {
                packet.write(map_id);
                packet.write_str(&map_name);
                packet.write(match_mode);
                packet.write(player_count);
                packet.write(victory_item_count);
                packet.write(respawn_time);
                packet.write(match_time);
                packet.write(match_id);
                packet.write(wait_player_perceont);
                packet.write(wait1_time);
                packet.write(wait2_time);
                packet.write(countdown_time);
                packet.write(events_scores);
                debug_assert_eq!(squads.len(), player_count as usize);
                for squad_id in squads {
                    packet.write(squad_id); // TODO: Function to write buffer
                }
                debug_assert_eq!(players.len(), player_count as usize);
                for player in players {
                    player.serialize(packet);
                }
            } // Self::MatchOptions {
              //     map_id,
              //     map_name,
              //     match_mode,
              //     player_count,
              //     victory_item_count,
              //     respawn_time,
              //     match_time,
              // } => {
              //     packet.write(map_id);
              //     assert!(map_name.len() < 30);
              //     packet.write_str(&map_name);
              //     packet.write(match_mode);
              //     packet.write(player_count);
              //     packet.write(victory_item_count);
              //     packet.write(respawn_time);
              //     packet.write(match_time);
              // }

              // Self::SpawnPlayer { player_id, player } => {
              //     packet.write(player_id);
              //     let player {
              //         position,
              //         orientation,
              //         look_pitch,
              //         is_alive,
              //         slot_id,
              //         server_target_active_slot,
              //     } = player;

              //     packet.write(position);
              //     packet.write(orientation);
              //     packet.write(look_pitch);
              //     packet.write(is_alive);
              //     packet.write(slot_id);
              //     packet.write(server_target_active_slot);
              // }

              // Self::ServerPlayerInput { .. } => {
              //     todo!()
              // }
              // Self::MatchTimeChanged { match_time } => {
              //     packet.write(match_time);
              // }

              // Self::PlayerProfile { player_profile } => {
              //     player_profile.serialize(packet);
              // }
        }
    }
}

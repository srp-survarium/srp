use std::sync::mpsc;
use std::sync::mpsc::TryRecvError;

use survarium::player_input::{
    player_inventory_slot, player_stamina, weapon_core, weapon_core_state, weapon_targets,
};
use survarium::player_profile;
use survarium::player_profile::raw::profile_slot_enum;
use vostok::math::float3;

use crate::message;
use crate::message::server_message::raw::{game_mode_type, game_status};
use crate::message::{ClientGameMessageKind, ServerGameMessageKind};

pub struct Game {
    client_game_message_rx: mpsc::Receiver<message::ClientGameMessageKind>,
    server_game_message_tx: mpsc::Sender<message::ServerGameMessageKind>,
}

impl Game {
    pub fn new(
        client_game_message_rx: mpsc::Receiver<message::ClientGameMessageKind>,
        server_game_message_tx: mpsc::Sender<message::ServerGameMessageKind>,
    ) -> Self {
        Self {
            client_game_message_rx,
            server_game_message_tx,
        }
    }

    pub fn tick(&mut self) {
        loop {
            match self.client_game_message_rx.try_recv() {
                Ok(message) => {
                    for message in self.handle_message(message) {
                        self.server_game_message_tx.send(message).unwrap()
                    }
                }
                Err(TryRecvError::Empty) => break,
                Err(TryRecvError::Disconnected) => panic!("Channel disconnected"),
            }
        }
    }
}

impl Game {
    pub fn handle_message(&self, message: ClientGameMessageKind) -> Vec<ServerGameMessageKind> {
        match message {
            ClientGameMessageKind::ConnectionRequest { .. } => {
                unreachable!("Should already be handled")
            }
            ClientGameMessageKind::GetStartupInfo => {
                vec![
                    ServerGameMessageKind::MatchOptions {
                        map_id: 0,
                        map_name: "level_03_evn".to_string(),
                        // map_name: "level_04".to_string(),
                        // map_name: "lobby_scene".to_string(),
                        match_mode: game_mode_type::gather_victory_items,
                        player_count: 2,
                        victory_item_count: 10, // batteries
                        respawn_time: 10,
                        match_time: 15 * 60,
                    },
                    ServerGameMessageKind::PlayerProfile {
                        player_profile: Box::new(player_profile::raw::player_profile {
                            team: player_profile::raw::game_team_id::team_1,
                            is_local: true,
                            ..player_profile::raw::player_profile::new_dummy(0, 0, "sheepy")
                        }),
                    },
                    ServerGameMessageKind::PlayerProfile {
                        player_profile: Box::new(player_profile::raw::player_profile {
                            team: player_profile::raw::game_team_id::team_2,
                            is_local: false,
                            ..player_profile::raw::player_profile::new_dummy(0, 0, "beauty")
                        }),
                    },
                ]
            }
            ClientGameMessageKind::JoinMatch { .. } => {
                vec![
                    ServerGameMessageKind::GameStatusChanged {
                        game_status: game_status::inprocess,
                    },
                    ServerGameMessageKind::SpawnPlayer {
                        player_id: 0,
                        player: survarium::player_input::player {
                            position: float3 {
                                x: -7.76438,
                                y: 13.95794,
                                z: -31.85271,
                            },
                            orientation: 10.,
                            look_pitch: 10.,
                            is_alive: true,
                            server_current_active_slot: profile_slot_enum::weapon1_slot,
                            server_target_active_slot: profile_slot_enum::weapon1_slot,
                            player_stamina: player_stamina {
                                value: 100.,
                                last_spending_time_in_ms: 10,
                                last_tick_time_in_ms: 10,
                                lower_threshold_was_reached: false,
                            },
                            player_inventory: vec![
                                player_inventory_slot::weapon_slot(weapon_core {
                                    inventory_item: 1,
                                    random_seed: 0,
                                    normal_random_seed: 1,
                                    weapon_target: weapon_targets::idle,
                                    old_actions_mask: 0,
                                    ammo_in_magazine: 30,
                                    bullets_in_queue: 30,
                                    fire_queue_type: 0,
                                    ammo_slot: profile_slot_enum::weapon1_slot,
                                    is_there_chamber_a_round_state: None, // ???
                                    weapon_core_state: Some(weapon_core_state {
                                        is_shown: true,
                                        active_hands: 1,
                                        start_transition_time_in_ms_lhs: 10,
                                        start_transition_time_in_ms_rhs: 10,
                                        weapon_sound_target_state: (3, None),
                                        logic_sprint_target_state: (0, None),
                                    }),
                                }),
                                player_inventory_slot::item_amount(300),
                            ],
                        },
                    },
                ]
            }
            ClientGameMessageKind::ClientPlayerUpdate { .. } => vec![],
            ClientGameMessageKind::TeamBasesInitializeInfo { .. } => {
                vec![
                    ServerGameMessageKind::SpawnPlayer {
                        player_id: 1,
                        player: survarium::player_input::player {
                            position: float3 {
                                // x: 12.,
                                // y: 10.,
                                // z: 27.,
                                x: -9.33856,
                                y: 47.47741,
                                z: -25.15140,
                            },
                            orientation: 10.,
                            look_pitch: 0.2,
                            is_alive: true,
                            server_current_active_slot: profile_slot_enum::weapon1_slot,
                            server_target_active_slot: profile_slot_enum::weapon1_slot,
                            player_stamina: player_stamina {
                                value: 100.,
                                last_spending_time_in_ms: 10,
                                last_tick_time_in_ms: 10,
                                lower_threshold_was_reached: false,
                            },
                            player_inventory: vec![
                                player_inventory_slot::weapon_slot(weapon_core {
                                    inventory_item: 1,
                                    random_seed: 0,
                                    normal_random_seed: 1,
                                    weapon_target: weapon_targets::idle,
                                    old_actions_mask: 0,
                                    ammo_in_magazine: 30,
                                    bullets_in_queue: 30,
                                    fire_queue_type: 0,
                                    ammo_slot: profile_slot_enum::weapon1_slot,
                                    is_there_chamber_a_round_state: None, // ???
                                    weapon_core_state: Some(weapon_core_state {
                                        is_shown: true,
                                        active_hands: 1,
                                        start_transition_time_in_ms_lhs: 10,
                                        start_transition_time_in_ms_rhs: 10,
                                        weapon_sound_target_state: (3, None),
                                        // weapon_sound_target_state: (0, None), // behind
                                        logic_sprint_target_state: (0, None),
                                    }),
                                }),
                                player_inventory_slot::item_amount(300),
                            ],
                        },
                    },
                    ServerGameMessageKind::SyncResponse {
                        is_connected_bitmask: 0b0011,
                    },
                ]
            }
        }
    }
}

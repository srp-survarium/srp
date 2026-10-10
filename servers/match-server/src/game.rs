// SPDX-License-Identifier: GPL-3.0-or-later
use std::sync::mpsc;
use std::sync::mpsc::TryRecvError;
use std::time::{self, Duration};

use survarium::player_input::{
    affect_event_type_enum, hit_affects_type_enum, player_inventory_slot, player_stamina,
    weapon_core, weapon_core_state, weapon_targets,
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

    is_match_running: bool,
    match_countdown_secs: u32,
    match_timer: time::Instant,
}

impl Game {
    pub fn new(
        client_game_message_rx: mpsc::Receiver<message::ClientGameMessageKind>,
        server_game_message_tx: mpsc::Sender<message::ServerGameMessageKind>,
    ) -> Self {
        Self {
            client_game_message_rx,
            server_game_message_tx,

            is_match_running: false,
            match_countdown_secs: 15 * 60,
            match_timer: time::Instant::now(),
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

        if self.is_match_running {
            let now = time::Instant::now();
            if now - self.match_timer >= Duration::from_secs(1) {
                self.match_timer = now;
                self.match_countdown_secs -= 1;

                // I hate this timer
                self.server_game_message_tx
                    .send(ServerGameMessageKind::MatchTimeChanged {
                        match_time: self.match_countdown_secs * 1000,
                    })
                    .unwrap();

                if self.match_countdown_secs == 14 * 60 + 50 {
                    self.server_game_message_tx
                        .send(ServerGameMessageKind::AffectDamageModel {
                            played_id: 0,
                            body_part_name: "body".to_string(),
                            hits_affects_type_enum: hit_affects_type_enum::critical_poisoning,
                            affect_event_type: affect_event_type_enum::applying,
                        })
                        .unwrap();

                    // TODO make capkan headshot
                    self.server_game_message_tx
                        .send(ServerGameMessageKind::KillPlayer {
                            victim_id: 1,
                            killer_id: 0,
                            is_headshot: true,
                            item_dict_id: 13,
                        })
                        .unwrap();
                }

                if self.match_countdown_secs == 14 * 60 + 45 {
                    self.server_game_message_tx
                        .send(ServerGameMessageKind::AffectDamageModel {
                            played_id: 0,
                            body_part_name: "body".to_string(),
                            hits_affects_type_enum: hit_affects_type_enum::concussion,
                            affect_event_type: affect_event_type_enum::applying,
                        })
                        .unwrap();

                    // self.server_game_message_tx
                    //     .send(ServerGameMessageKind::PlayerVisibilityChange {
                    //         player_id: 1,
                    //         player_visibility: false,
                    //     })
                    //     .unwrap();
                }

                if self.match_countdown_secs == 14 * 60 + 40 {
                    self.server_game_message_tx
                        .send(ServerGameMessageKind::AffectDamageModel {
                            played_id: 0,
                            body_part_name: "body".to_string(),
                            hits_affects_type_enum: hit_affects_type_enum::blindness,
                            affect_event_type: affect_event_type_enum::applying,
                        })
                        .unwrap();
                    self.server_game_message_tx
                        .send(ServerGameMessageKind::PlayerVisibilityChange {
                            player_id: 1,
                            player_visibility: true,
                        })
                        .unwrap();

                    self.server_game_message_tx
                        .send(ServerGameMessageKind::SpawnPlayer {
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
                        })
                        .unwrap();

                    // self.server_game_message_tx
                    //     .send(ServerGameMessageKind::WorldSynchronizationRequest)
                    //     .unwrap();

                    // self.server_game_message_tx
                    //     .send(ServerGameMessageKind::MatchFinished)
                    //     .unwrap();

                    // self.server_game_message_tx
                    //     .send(ServerGameMessageKind::InitializeVictoryItems {
                    //         position: float3 {
                    //             x: -5.11952,
                    //             y: 6.98356,
                    //             z: -35.21231,
                    //         },
                    //     })
                    //     .unwrap();

                    // self.server_game_message_tx
                    //     .send(ServerGameMessageKind::GameWorldObjectState {
                    //         player_id: 0,
                    //         profile_slot: profile_slot_enum::quick_slot4,
                    //         garbage: [0; 40],
                    //     })
                    //     .unwrap();
                }

                if 14 * 60 < self.match_countdown_secs && self.match_countdown_secs <= 14 * 60 + 30
                {
                    // name: "body"
                    // name: "back"
                    // name: "head"
                    // name: "face"
                    // name: "right_leg"
                    // name: "left_leg"
                    // name: "right_foot"
                    // name: "left_foot"
                    // name: "right_arm"
                    // name: "left_arm"
                    // name: "right_hand"
                    // name: "left_hand"
                    // name: "pain"
                    // name: "infection"
                    // name: "radiation"

                    // hit_types[5]:
                    //       electric_shock[4]
                    //       intoxication[4]
                    //       irradiation[4]
                    //       injury[4]
                    //       ambustion[4]

                    self.server_game_message_tx
                        .send(ServerGameMessageKind::HitPlayer {
                            hit_initiator_id: 1,
                            being_hit_id: 0,
                            body_part_name: "infection".to_string(),
                            damage_type_info: "intoxication".to_string(),
                            amount: 10.,
                            armor_piercing: 10.,
                        })
                        .unwrap();
                }

                if self.match_countdown_secs == 0 {
                    self.is_match_running = false;
                }
            }
        }
    }
}

impl Game {
    pub fn handle_message(&mut self, message: ClientGameMessageKind) -> Vec<ServerGameMessageKind> {
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
            ClientGameMessageKind::JoinMatch => {
                self.is_match_running = true;

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
                    ServerGameMessageKind::PlayerVisibilityChange {
                        player_id: 0,
                        player_visibility: true,
                    },
                    ServerGameMessageKind::PlayerVisibilityChange {
                        player_id: 1,
                        player_visibility: true,
                    },
                ]
            }
            ClientGameMessageKind::TimeSynchronizationRequest { .. } => {
                vec![ServerGameMessageKind::SyncResponse {
                    is_connected_bitmask: 0b0011,
                }]
            }
            ClientGameMessageKind::TimeSynchronizationConfirmation => vec![],
        }
    }
}
// survarium::inventory_item::deserialize_game_world_object

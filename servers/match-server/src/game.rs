use std::sync::mpsc;
use std::sync::mpsc::TryRecvError;

use survarium::player_profile;
use survarium::player_profile::raw::profile_slot_enum;
use vostok::math::float3;

use crate::message;
use crate::message::server_message::raw::game_mode_type;
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
                    // ServerGameMessageKind::MatchOptions {
                    //     map_id: 0,
                    //     map_name: "level_03_evn".to_string(),
                    //     // map_name: "level_04".to_string(),
                    //     // map_name: "lobby_scene".to_string(),
                    //     match_mode: game_mode_type::gather_victory_items,
                    //     player_count: 2,
                    //     victory_item_count: 10, // batteries
                    //     respawn_time: 10,
                    //     match_time: 15 * 60,
                    // },
                    // ServerGameMessageKind::PlayerProfile {
                    //     player_profile: Box::new(player_profile::PlayerProfile {
                    //         team_id: player_profile::raw::game_team_id::team_1,
                    //         is_local: true,
                    //         ..player_profile::PlayerProfile::new_dummy(10, "sheepy")
                    //     }),
                    // },
                    // ServerGameMessageKind::PlayerProfile {
                    //     player_profile: Box::new(player_profile::PlayerProfile {
                    //         team_id: player_profile::raw::game_team_id::team_2,
                    //         is_local: false,
                    //         ..player_profile::PlayerProfile::new_dummy(20, "beauty")
                    //     }),
                    // },
                ]
            }
            ClientGameMessageKind::JoinMatch { .. } => {
                vec![
                    // ServerGameMessageKind::SpawnPlayer {
                    // player_id: 0,
                    // player: survarium::player_input::player {
                    //     position: float3 {
                    //         // x: 10.,
                    //         // y: 10.,
                    //         // z: 25.,
                    //         x: -10.33856,
                    //         y: 47.47741,
                    //         z: -25.15140,
                    //     },
                    //     orientation: 10.,
                    //     look_pitch: 10.,
                    //     is_alive: true,
                    //     slot_id: profile_slot_enum::weapon1_slot,
                    //     server_target_active_slot: profile_slot_enum::weapon1_slot,
                    // },
                // }
                ]
            }
            ClientGameMessageKind::ClientPlayerUpdate { .. } => vec![],
            ClientGameMessageKind::TeamBasesInitializeInfo { .. } => {
                vec![
                    // ServerGameMessageKind::SpawnPlayer {
                    // player_id: 1,
                    // player: survarium::player_input::player {
                    //     position: float3 {
                    //         // x: 12.,
                    //         // y: 10.,
                    //         // z: 27.,
                    //         x: -9.33856,
                    //         y: 47.47741,
                    //         z: -25.15140,
                    //     },
                    //     orientation: 10.,
                    //     look_pitch: 0.2,
                    //     is_alive: true,
                    //     slot_id: profile_slot_enum::weapon1_slot,
                    //     server_target_active_slot: profile_slot_enum::weapon1_slot,
                    // },
                // }
                ]
            }
        }
    }
}

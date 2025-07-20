use std::sync::mpsc;
use std::sync::mpsc::TryRecvError;

use survarium::player_profile;

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
                    ServerGameMessageKind::MatchOptions {
                        map_id: 0,
                        map_name: "level_03_evn".to_string(),
                        // map_name: "lobby_scene".to_string(),
                        match_mode: game_mode_type::gather_victory_items,
                        player_count: 2,
                        victory_item_count: 10,
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
            ClientGameMessageKind::ClientPlayerUpdate { unknown: _ } => vec![],
        }
    }
}

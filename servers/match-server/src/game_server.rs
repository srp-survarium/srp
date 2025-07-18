use survarium::player_profile;

use crate::message::server_message::raw::game_mode_type;
use crate::message::{ClientGameMessage, ServerGameMessage};

pub struct Game {}

impl Game {
    pub fn handle_message(&self, message: ClientGameMessage) -> Vec<ServerGameMessage> {
        match message {
            ClientGameMessage::ConnectionRequest { .. } => {
                unreachable!("Should already be handled")
            }
            ClientGameMessage::GetStartupInfo => {
                vec![
                    ServerGameMessage::MatchOptions {
                        map_id: 0,
                        map_name: "level_03_evn".to_string(),
                        // map_name: "lobby_scene".to_string(),
                        match_mode: game_mode_type::gather_victory_items,
                        player_count: 2,
                        victory_item_count: 10,
                        respawn_time: 10,
                        match_time: 15 * 60,
                    },
                    ServerGameMessage::PlayerProfile {
                        player_profile: player_profile::raw::player_profile {
                            team: player_profile::raw::game_team_id::team_1,
                            is_local: true,
                            ..player_profile::raw::player_profile::new_dummy(0, 0, "sheepy")
                        },
                    },
                    ServerGameMessage::PlayerProfile {
                        player_profile: player_profile::raw::player_profile {
                            team: player_profile::raw::game_team_id::team_2,
                            is_local: false,
                            ..player_profile::raw::player_profile::new_dummy(0, 0, "beauty")
                        },
                    },
                ]
            }
            ClientGameMessage::ClientPlayerUpdate { unknown: _ } => vec![],
        }
    }
}

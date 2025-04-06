mod message;
mod player_profile;

pub use message::client::faction_id;
pub use message::{client, server};

use crate::network_client::NetworkClient;
use crate::ServerState;
use crate::ANSWER_NAME;

use std::sync::Arc;

pub fn run(_server_state: Arc<ServerState>, network_client: NetworkClient) -> ! {
    let mut network_client = network_client;

    let message = network_client.read::<client::Message>().unwrap();
    let client::Message::SignInInfo { session_id } = message else {
        panic!("First message must be 'SignInInfo'")
    };

    network_client
        .send(server::Message::ConnectionSuccessful)
        .unwrap();
    println!("Connected to client: {session_id}");

    let mut state = ConnectionState::new(session_id);

    loop {
        let message = network_client.read::<client::Message>().unwrap();
        let Some(response) = state.handle_message(message) else {
            continue;
        };
        network_client.send(response).unwrap();
    }
}

struct ConnectionState {
    #[allow(dead_code)]
    session_id: u32,
    id: u32,
}
impl ConnectionState {
    fn new(session_id: u32) -> Self {
        Self { session_id, id: 0 }
    }

    pub fn handle_message(&mut self, msg: client::Message) -> Option<server::Message> {
        println!("[writer] Received {msg:?}");

        // CONNECT TO MATCH SERVER
        // packet.push(1 + 1 + lobby_server::ADDRESS.len() as u8 + 4 + 4);
        // packet.push(lobby_server_message_types_enum::connect_to_match_server as u8);
        // packet.push(lobby_server::ADDRESS.len() as u8);
        // packet.extend(lobby_server::ADDRESS.as_bytes());
        // packet.extend(1_u32.to_le_bytes()); // match_id
        // packet.extend(0_u32.to_le_bytes()); // team_id : survarium::game_team_id
        match msg {
            client::Message::ReadyForMatch { profile_id: _ } => todo!(),

            // @TODO: Currently we allow all inventory actions :shrug:
            client::Message::InventoryAction(_) => Some(server::Message::OperationPermitted(
                server::Operation::Inventory,
            )),
            client::Message::SkillsTreeAction(_) => todo!(),

            client::Message::SignInInfo { session_id: _ } => panic!("Shouldn't receive"),
            client::Message::PingServer { alive_seconds: _ } => None,

            client::Message::ShopAction(client::ShopAction::Buy {
                dict_id,
                amount,
                _unknown_1,
                faction_id: _,
            }) => {
                let op = server::Message::OperationPermitted(server::Operation::Shop(
                    server::ShopOperation::ActionBought {
                        dict_id,
                        id: self.id,
                        condition_or_stack: amount as u32,
                    },
                ));
                self.id += 1;
                Some(op)
            }

            client::Message::QueryClientStatus(status) => {
                let status = match status {
                    client::QueryClientStatus::ClientState => server::ClientStatus::ClientState {
                        status: 0,
                        last_status_message: "last_status_message".to_string(),
                    },
                    client::QueryClientStatus::EnumerateProfiles => {
                        server::ClientStatus::EnumerateProfiles(vec![
                            server::Profile {
                                profile_id: 200_000,
                                name: "server_profile_1".to_string(),
                            },
                            server::Profile {
                                profile_id: 400_000,
                                name: "server_profile_2".to_string(),
                            },
                            server::Profile {
                                profile_id: 600_000,
                                name: "server_profile_3".to_string(),
                            },
                        ])
                    }

                    client::QueryClientStatus::ProfileContents { profile_id } => {
                        server::ClientStatus::ProfileContents(player_profile::player_profile::new(
                            100_000_u32,
                            profile_id,
                            match profile_id {
                                200_000 => "server_profile_1",
                                400_000 => "server_profile_2",
                                600_000 => "server_profile_3",
                                _ => unreachable!(),
                            },
                        ))
                    }

                    // @TODO
                    client::QueryClientStatus::EnumerateInventory => {
                        let i = |id, dict_id, condition_or_stack| {
                            player_profile::inventory_item_instance {
                                condition_or_stack,
                                amount_in_inventory: 1,
                                id,
                                dict_id,
                            }
                        };
                        let items = vec![
                            i(1, 24, 10), // boots
                            i(2, 40, 20), // gloves
                            i(3, 46, 30), // legs
                            i(4, 27, 40), // helmet
                            i(5, 43, 50), // resp
                            i(6, 48, 60), // torso
                            i(7, 9, 70),  // back
                            //
                            i(8, 65, 80),   // painkiller
                            i(9, 66, 90),   // bandages
                            i(10, 67, 100), // medkit
                            i(11, 68, 110), // traps
                            //
                            i(12, 55, 120), // uzi
                            i(13, 55, 130), // uzi
                        ];

                        server::ClientStatus::EnumerateInventory(items)
                    }

                    // In which slot what type of weapon can be placed.
                    client::QueryClientStatus::ProfileSlotsRestrictions => {
                        // (category_id, profile_slot_id)
                        #[rustfmt::skip]
                        let restricts: [(u8, u8); 49] = [
                            (1, 0),
                            (2, 1),
                            (3, 2),
                            (4, 3),
                            (5, 4),
                            (6, 5),
                            (7, 6),
                            //
                            (9, 8),
                            (9, 9),
                            (9, 11),
                            (9, 12),
                            //
                            (10, 13), (10, 14), (10, 15), (10, 16), (10, 17), (10, 18),
                            (11, 13), (11, 14), (11, 15), (11, 16), (11, 17), (11, 18),
                            //
                            (13, 7), (13, 10),
                            (14, 7), (14, 10),
                            (15, 7), (15, 10),
                            (17, 7), (17, 10),
                            //
                            (18, 13), (18, 14), (18, 15), (18, 16), (18, 17), (18, 18),
                            (19, 13), (19, 14), (19, 15), (19, 16), (19, 17), (19, 18),
                            (20, 13), (20, 14), (20, 15), (20, 16), (20, 17), (20, 18),
                        ];

                        server::ClientStatus::ProfileSlotsRestrictions(
                            restricts
                                .into_iter()
                                .map(|(category_dict_id, slot_dict_id)| {
                                    server::profile_slot_restriction {
                                        slot_dict_id,
                                        category_dict_id,
                                    }
                                })
                                .collect(),
                        )
                    }

                    // Used to connect ammo and weapons
                    client::QueryClientStatus::ItemsCompatibility => {
                        let compats: [(u16, u16); 18] = [
                            (12, 51),
                            (12, 52),
                            (13, 7),
                            (14, 51),
                            (14, 52),
                            (15, 22),
                            (15, 72),
                            (16, 22),
                            (16, 72),
                            (17, 22),
                            (17, 72),
                            (18, 50),
                            (19, 53),
                            (19, 71),
                            (55, 53),
                            (55, 71),
                            (56, 20),
                            (64, 70),
                        ];

                        server::ClientStatus::ItemsCompatibility(
                            compats
                                .into_iter()
                                .map(|(first_item_dict_id, second_item_dict_id)| {
                                    server::items_compatibility {
                                        first_item_dict_id,
                                        second_item_dict_id,
                                    }
                                })
                                .collect(),
                        )
                    }

                    client::QueryClientStatus::PriceItems(faction_id) => {
                        let dict_ids: &[u16] = match faction_id {
                            faction_id::scavengers => &[
                                7, 9, 12, 13, 14, 15, 16, 17, 18, 19, 20, 34, 35, 36, 37, 38, 39,
                                40, 41, 42, 43, 44, 45, 46, 47,
                            ],
                            faction_id::black_market => &[
                                22, 24, 25, 27, 28, 29, 31, 32, 33, 48, 49, 50, 51, 52, 53, 55, 56,
                                64, 65, 66, 67, 68, 70, 71, 72, 73,
                            ],

                            // Scopes and artefacts: 54, 57, 69

                            // @NOTE: in 001b are not supported
                            faction_id::army => &[],
                            faction_id::fringe_settlers => &[],
                        };

                        server::ClientStatus::PriceItems {
                            faction_id,
                            price_items: dict_ids
                                .iter()
                                .copied()
                                .map(|dict_id| server::price_item {
                                    item_dict_id: dict_id,
                                    cost: dict_id,
                                    reputation_level: 0,
                                    padding: 0,
                                })
                                .collect(),
                        }
                    }

                    client::QueryClientStatus::AccountMoney => server::ClientStatus::AccountMoney {
                        generic_money: 1_000_000,
                        premium_money: 100_000,
                        skill_points: 75,
                        name: ANSWER_NAME.to_string(),
                    },

                    client::QueryClientStatus::PlayerSkills => server::ClientStatus::PlayerSkills {
                        total_experience: 1800,
                        next_level_experience: 3750,
                        prev_level_experience: 1000,
                        player_skills: [
                            server::player_skill {
                                skill_id: 1,
                                skill_points: 0,
                            },
                            server::player_skill {
                                skill_id: 2,
                                skill_points: 0,
                            },
                            server::player_skill {
                                skill_id: 3,
                                skill_points: 0,
                            },
                            server::player_skill {
                                skill_id: 4,
                                skill_points: 0,
                            },
                            server::player_skill {
                                skill_id: 5,
                                skill_points: 0,
                            },
                        ],
                    },

                    client::QueryClientStatus::PlayerSkillsTree => {
                        const SKILLS_TREE: &[u8] =
                            include_bytes!("../../../../resources/skills_tree.bin");
                        server::ClientStatus::PlayerSkillsTree {
                            skills_tree: SKILLS_TREE.to_vec(),
                        }
                    }

                    client::QueryClientStatus::ServicePrices => {
                        server::ClientStatus::ServicePrices {
                            reroll_cost: 100,
                            add_profile_cost: 200,
                            rename_account_cost: 300,
                        }
                    }

                    client::QueryClientStatus::PlayerReputations => {
                        server::ClientStatus::PlayerReputations([
                            server::player_reputation {
                                faction_id: faction_id::scavengers,
                                reputation_points: 100,
                            },
                            server::player_reputation {
                                faction_id: faction_id::black_market,
                                reputation_points: 200,
                            },
                            server::player_reputation {
                                faction_id: faction_id::army,
                                reputation_points: 300,
                            },
                            server::player_reputation {
                                faction_id: faction_id::fringe_settlers,
                                reputation_points: 400,
                            },
                        ])
                    }
                };

                Some(server::Message::ClientStatus(status))
            }
        }
    }
}

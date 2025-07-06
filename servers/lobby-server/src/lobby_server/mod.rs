mod connection_state;
mod message;
mod player_profile;

use self::connection_state::ConnectionState;
pub use self::message::client::raw::faction_id;
pub use self::message::{client, server};

use crate::network_client::NetworkClient;

use std::ffi::CStr;
use std::sync::Arc;

pub struct ServerState {
    restricts: Vec<server::raw::profile_slot_restriction>,
    compats: Vec<server::raw::items_compatibility>,
    price_items: [(faction_id, Vec<server::raw::price_item>); 4],
    skills_tree: Vec<u8>,

    reroll_cost: u32,
    add_profile_cost: u32,
    rename_account_cost: u32,
}

impl ServerState {
    pub fn run(self: Arc<Self>, network_client: NetworkClient) -> ! {
        let mut network_client = network_client;

        let message = network_client.read::<client::Message>().unwrap();
        let client::Message::SignInInfo { session_id } = message else {
            panic!("First message must be 'SignInInfo'")
        };

        network_client
            .send(server::Message::ConnectionSuccessful)
            .unwrap();
        println!("Connected to client: {session_id}");

        let mut state = ConnectionState::new_dummy(session_id);

        loop {
            let message = match network_client.read::<client::Message>() {
                Ok(message) => message,
                Err(error) => {
                    println!("{error}");
                    println!("{:?}", network_client.get_read_buffer());
                    panic!()
                }
            };
            let Some(response) = self.handle_client_message(&mut state, message) else {
                continue;
            };
            network_client.send(response).unwrap();
        }
    }

    pub fn handle_client_message(
        &self,
        connection_state: &mut ConnectionState,
        msg: client::Message,
    ) -> Option<server::Message> {
        println!("[writer] Received {msg:?}");

        match msg {
            client::Message::ReadyForMatch { profile_id: _ } => {
                Some(server::Message::ConnectToMatchServer {
                    match_id: 0x123,
                    team_id: 0x1,
                })
            }

            // @TODO: Currently we allow all inventory actions :shrug:
            client::Message::InventoryAction(actions) if actions.is_empty() => Some(
                server::Message::OperationDenied(server::Operation::Inventory),
            ),

            client::Message::InventoryAction(actions) => {
                let mut profile_contents = connection_state.profile_contents.clone();
                for action in actions {
                    let client::InventoryAction::Equip {
                        profile_id,
                        id,
                        dict_id,
                        kind,
                        amount,
                    } = action;

                    let profile_contents = profile_contents
                        .iter_mut()
                        .find(|profile| profile.profile_id == profile_id)
                        .unwrap();

                    match kind {
                        client::EquipKind::Equip { to_slot } => {
                            profile_contents.slots[to_slot] =
                                player_profile::raw::inventory_item_instance {
                                    condition_or_stack: amount as u32,
                                    amount_in_inventory: amount as u32,
                                    id,
                                    dict_id,
                                    padding: Default::default(),
                                }
                        }
                        client::EquipKind::Unequip { from_slot } => {
                            profile_contents.slots[from_slot] =
                                player_profile::raw::inventory_item_instance::default();
                        }
                        _ => {
                            return Some(server::Message::OperationDenied(
                                server::Operation::Inventory,
                            ));
                        }
                    }
                }

                connection_state.profile_contents = profile_contents;

                Some(server::Message::OperationPermitted(
                    server::Operation::Inventory,
                ))
            }
            client::Message::SkillsTreeAction(_) => todo!(),

            client::Message::SignInInfo { session_id: _ } => panic!("Shouldn't receive"),
            client::Message::PingServer { alive_ms } => Some(server::Message::PingServerAnswer {
                // @TODO: Get alive from our side
                ping_value: alive_ms + 80,
            }),

            client::Message::ShopAction(client::ShopAction::Buy {
                dict_id,
                amount,
                _unknown_1,
                faction_id: _,
            }) => {
                let op = server::Message::OperationPermitted(server::Operation::Shop(
                    server::ShopOperation::ActionBought {
                        dict_id,
                        id: connection_state.id,
                        condition_or_stack: amount as u32,
                    },
                ));
                connection_state.id += 1;
                Some(op)
            }

            client::Message::QueryClientStatus(status) => {
                let status = match status {
                    client::QueryClientStatus::ClientState => server::ClientStatus::ClientState {
                        status: 0,
                        last_status_message: "last_status_message".to_string(),
                    },
                    client::QueryClientStatus::EnumerateProfiles => {
                        server::ClientStatus::EnumerateProfiles(
                            connection_state
                                .profile_contents
                                .iter()
                                .map(|profile| server::Profile {
                                    profile_id: profile.profile_id,
                                    name: CStr::from_bytes_until_nul(&profile.profile_name)
                                        .unwrap()
                                        .to_string_lossy()
                                        .to_string(),
                                })
                                .collect(),
                        )
                    }

                    client::QueryClientStatus::ProfileContents { profile_id } => {
                        server::ClientStatus::ProfileContents(Box::new(
                            *connection_state
                                .profile_contents
                                .iter()
                                .find(|profile| profile.profile_id == profile_id)
                                .unwrap(),
                        ))
                    }

                    // @TODO
                    client::QueryClientStatus::EnumerateInventory => {
                        server::ClientStatus::EnumerateInventory(connection_state.inventory.clone())
                    }

                    // In which slot what type of weapon can be placed.
                    client::QueryClientStatus::ProfileSlotsRestrictions => {
                        server::ClientStatus::ProfileSlotsRestrictions(self.restricts.clone())
                    }

                    // Used to connect ammo and weapons
                    client::QueryClientStatus::ItemsCompatibility => {
                        server::ClientStatus::ItemsCompatibility(self.compats.clone())
                    }

                    client::QueryClientStatus::PriceItems(faction_id) => {
                        server::ClientStatus::PriceItems {
                            faction_id,
                            price_items: self
                                .price_items
                                .iter()
                                .find(|price_item| price_item.0 == faction_id)
                                .unwrap()
                                .1
                                .clone(),
                        }
                    }

                    client::QueryClientStatus::AccountMoney => server::ClientStatus::AccountMoney {
                        generic_money: connection_state.generic_money,
                        premium_money: connection_state.premium_money,
                        skill_points: connection_state.skills_points,
                        name: connection_state.name.clone(),
                    },

                    client::QueryClientStatus::PlayerSkills => server::ClientStatus::PlayerSkills {
                        total_experience: connection_state.total_experience,
                        next_level_experience: connection_state.next_level_experience,
                        prev_level_experience: connection_state.prev_level_experience,
                        player_skills: connection_state.player_skills,
                    },

                    client::QueryClientStatus::PlayerSkillsTree => {
                        server::ClientStatus::PlayerSkillsTree {
                            skills_tree: self.skills_tree.clone(),
                        }
                    }

                    client::QueryClientStatus::ServicePrices => {
                        server::ClientStatus::ServicePrices {
                            reroll_cost: self.reroll_cost,
                            add_profile_cost: self.add_profile_cost,
                            rename_account_cost: self.rename_account_cost,
                        }
                    }

                    client::QueryClientStatus::PlayerReputations => {
                        server::ClientStatus::PlayerReputations(connection_state.reps)
                    }
                };

                Some(server::Message::ClientStatus(status))
            }
        }
    }
}

impl ServerState {
    pub fn new_dummy() -> Self {
        Self {
            restricts: {
                #[rustfmt::skip]
                let restricts: [(u8, u8); 49] = [
                    // (category_id, profile_slot_id)
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

                restricts
                    .into_iter()
                    .map(
                        |(category_dict_id, slot_dict_id)| server::raw::profile_slot_restriction {
                            slot_dict_id,
                            category_dict_id,
                        },
                    )
                    .collect()
            },
            compats: {
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

                compats
                    .into_iter()
                    .map(|(first_item_dict_id, second_item_dict_id)| {
                        server::raw::items_compatibility {
                            first_item_dict_id,
                            second_item_dict_id,
                        }
                    })
                    .collect()
            },
            price_items: {
                let ids = |ids: &[u16]| {
                    ids.iter()
                        .cloned()
                        .map(|item_dict_id| server::raw::price_item {
                            item_dict_id,
                            cost: item_dict_id,
                            reputation_level: 0,
                            padding: Default::default(),
                        })
                        .collect()
                };

                [
                    (
                        faction_id::scavengers,
                        ids(&[
                            7, 9, 12, 13, 14, 15, 16, 17, 18, 19, 20, 34, 35, 36, 37, 38, 39, 40,
                            41, 42, 43, 44, 45, 46, 47,
                        ]),
                    ),
                    (
                        faction_id::black_market,
                        ids(&[
                            22, 24, 25, 27, 28, 29, 31, 32, 33, 48, 49, 50, 51, 52, 53, 55, 56, 64,
                            65, 66, 67, 68, 70, 71, 72, 73,
                        ]),
                    ),
                    // @NOTE: in 001b are not supported
                    (faction_id::army, ids(&[])),
                    (faction_id::fringe_settlers, ids(&[])),
                    // Scopes and artefacts: 54, 57, 69
                ]
            },
            skills_tree: include_bytes!("../../../../resources/skills_tree.bin").to_vec(),

            reroll_cost: 100,
            add_profile_cost: 200,
            rename_account_cost: 300,
        }
    }
}

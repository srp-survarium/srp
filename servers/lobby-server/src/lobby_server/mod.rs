mod connection_state;
mod message;

use self::connection_state::ConnectionState;
pub use self::message::client::raw::faction_id;
pub use self::message::{client, server};

use vostok::network_client::TcpClient;

use std::ffi::CStr;
use std::sync::Arc;

pub struct ServerState {
    price_items: [(faction_id, Vec<server::raw::price_item>); 4],
    skills_tree: Vec<u8>,

    reroll_cost: u32,
    add_profile_cost: u32,
    rename_account_cost: u32,
}

impl ServerState {
    pub fn run(self: Arc<Self>, tcp_client: TcpClient) -> ! {
        let mut tcp_client = tcp_client;

        let message = tcp_client.read::<client::Message>().unwrap();
        let client::Message::SignInInfo { session_id } = message else {
            panic!("First message must be 'SignInInfo'")
        };

        tcp_client
            .send(server::Message::ConnectionSuccessful)
            .unwrap();
        println!("Connected to client: {session_id}");

        let mut state = ConnectionState::new_dummy(session_id);

        loop {
            let message = match tcp_client.read::<client::Message>() {
                Ok(message) => message,
                Err(error) => {
                    println!("{error}");
                    println!("{:?}", tcp_client.get_read_buffer());
                    panic!()
                }
            };
            let Some(response) = self.handle_client_message(&mut state, message) else {
                continue;
            };
            tcp_client.send(response).unwrap();
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
            client::Message::InventoryAction(actions) if actions.is_empty() => {
                Some(server::Message::OperationDenied {
                    operation: server::Operation::Inventory,
                    reason: "Because I don't like you".to_string(),
                })
            }

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
                                survarium::player_profile::raw::inventory_item_instance {
                                    condition_or_stack: amount as u32,
                                    amount_in_inventory: amount as u32,
                                    id,
                                    dict_id,
                                    padding: Default::default(),
                                }
                        }
                        client::EquipKind::Unequip { from_slot } => {
                            profile_contents.slots[from_slot] =
                                survarium::player_profile::raw::inventory_item_instance::default();
                        }
                        _ => {
                            return Some(server::Message::OperationDenied {
                                operation: server::Operation::Inventory,
                                reason: "Unequipped nonequipped".to_string(),
                            });
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
                        state: server::ClientState::SurfLobbyMenu,
                        last_status_message: None,
                    },
                    client::QueryClientStatus::EnumerateProfiles => {
                        server::ClientStatus::EnumerateProfiles(
                            // TODO: Remove profile_contents
                            connection_state
                                .profile_contents
                                .iter()
                                .map(|profile| server::Profile {
                                    profile_id: profile.profile_id,
                                    name: CStr::from_bytes_until_nul(&profile.profile_name)
                                        .unwrap()
                                        .to_string_lossy()
                                        .to_string(),
                                    autobuy_items: false,
                                    skill_points_total: 40,
                                    current_exp: 1000,
                                    prev_level_exp: 800,
                                    next_level_exp: 1300,
                                    revision: 0,
                                })
                                .collect(),
                        )
                    }

                    client::QueryClientStatus::ProfileContents { profile_id } => {
                        /* TODO
                        let profile = connection_state
                            .profile_contents
                            .iter()
                            .find(|profile| profile.profile_id == profile_id)
                            .unwrap();
                        */

                        server::ClientStatus::ProfileContents {
                            profile_id,
                            profile: server::PlayerProfile {
                                team_id: survarium::player_profile::raw::game_team_id::team_1,
                                is_local: true,
                                profile_name: "Clown".to_string(),
                            },
                            revision: 0,
                        }
                    }

                    // @TODO
                    client::QueryClientStatus::EnumerateInventory => {
                        server::ClientStatus::EnumerateInventory(connection_state.inventory.clone())
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
                        name: connection_state.name.clone(),
                    },

                    client::QueryClientStatus::PlayerSkills => server::ClientStatus::PlayerSkills {
                        profile_id: 10,         // TODO
                        skill_points_total: 40, // TODO
                        current_exp: 1000,      // TODO
                        prev_level_exp: 800,    // TODO
                        next_level_exp: 1300,   // TODO
                        player_skills: connection_state.player_skills,
                    },

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

                    // TODO
                    status => {
                        println!("Next: {status:?}");
                        return None;
                    }
                };

                Some(server::Message::ClientStatus(status))
            }
            client::Message::QuerySquadInfo { .. } => {
                // TODO: Ignored for now
                None
            }
        }
    }
}

impl ServerState {
    pub fn new_dummy() -> Self {
        Self {
            // @TODO: Not displayed in game at all
            price_items: {
                let ids = |ids: &[u16]| {
                    ids.iter()
                        .cloned()
                        .map(|item_dict_id| server::raw::price_item {
                            item_dict_id,
                            cost: item_dict_id as u32,
                            reputation_level: 0,
                            padding_1: Default::default(),
                            padding_2: Default::default(),
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
            skills_tree: include_bytes!(
                "../../../../resources/binary-config-examples/skills_tree.bin"
            )
            .to_vec(),

            reroll_cost: 100,
            add_profile_cost: 200,
            rename_account_cost: 300,
        }
    }
}

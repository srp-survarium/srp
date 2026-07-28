mod connection_state;
mod message;

use self::connection_state::ConnectionState;
pub use self::message::client::raw::faction_id;
pub use self::message::{client, server};

use session::{Account, SessionStore};
use vostok::network_client::TcpClient;

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
    pub fn run(self: Arc<Self>, store: Arc<SessionStore>, tcp_client: TcpClient) -> ! {
        let mut tcp_client = tcp_client;

        let message = tcp_client.read::<client::Message>().unwrap();
        let client::Message::SignInInfo { session_id } = message else {
            panic!("First message must be 'SignInInfo'")
        };

        tcp_client
            .send(server::Message::ConnectionSuccessful)
            .unwrap();
        log::info!("Connected to client: {session_id}");

        // Resolve the account this session belongs to. Falls back to a default
        // account when the session is unknown (e.g. the lobby run standalone,
        // without the login server having populated the store).
        let mut state = match store.account_for_session(session_id) {
            Some(account) => ConnectionState::from_account(session_id, &account.lock().unwrap()),
            None => {
                log::warn!("Unknown session {session_id:#x}; using a default account");
                ConnectionState::from_account(
                    session_id,
                    &Account::new_dummy(1, "dummy_name".to_string()),
                )
            }
        };

        loop {
            let message = match tcp_client.read::<client::Message>() {
                Ok(message) => message,
                Err(error) => {
                    log::error!("{error}");
                    log::error!("{:?}", tcp_client.get_read_buffer());
                    panic!()
                }
            };
            let Some(response) = self.handle_client_message(&store, &mut state, message) else {
                continue;
            };
            tcp_client.send(response).unwrap();
        }
    }

    pub fn handle_client_message(
        &self,
        store: &SessionStore,
        connection_state: &mut ConnectionState,
        msg: client::Message,
    ) -> Option<server::Message> {
        log::debug!("[writer] Received {msg:?}");

        match msg {
            client::Message::ReadyForMatch { profile_id } => {
                let Some(selected_profile) = connection_state
                    .profile_contents
                    .iter()
                    .find(|profile| profile.profile_id == profile_id)
                    .copied()
                else {
                    log::warn!(
                        "Session {:#x} selected unknown profile {profile_id}",
                        connection_state.session_id
                    );
                    return Some(server::Message::OperationDenied(
                        server::Operation::Inventory,
                    ));
                };
                use survarium::player_profile::raw::profile_slot_enum;
                if [
                    profile_slot_enum::weapon1_slot,
                    profile_slot_enum::weapon2_slot,
                ]
                .into_iter()
                .all(|slot| selected_profile.slots[slot].id == 0)
                {
                    log::warn!(
                        "Session {:#x} selected a profile without a weapon",
                        connection_state.session_id
                    );
                    return Some(server::Message::OperationDenied(
                        server::Operation::Inventory,
                    ));
                }

                // Place this session into a match (balancing teams) and tell the
                // client where to go. Persist the edited profiles and selected
                // loadout so the match server spawns exactly what the user chose.
                let assignment = store.ready_for_match(
                    connection_state.session_id,
                    selected_profile,
                    &connection_state.profile_contents,
                );
                log::info!(
                    "Session {:#x} -> match {:#x} team {}",
                    connection_state.session_id,
                    assignment.match_id,
                    assignment.team_id
                );
                Some(server::Message::ConnectToMatchServer {
                    match_id: assignment.match_id,
                    team_id: assignment.team_id,
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
                        client::EquipKind::Move { from_slot, to_slot } => {
                            let item = profile_contents.slots[from_slot];
                            if item.id == 0 {
                                return Some(server::Message::OperationDenied(
                                    server::Operation::Inventory,
                                ));
                            }
                            profile_contents.slots[from_slot] =
                                survarium::player_profile::raw::inventory_item_instance::default();
                            profile_contents.slots[to_slot] = item;
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
            // @TODO: Not displayed in game at all
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

#[cfg(test)]
mod tests {
    use super::*;
    use survarium::player_profile::raw::profile_slot_enum;

    #[test]
    fn ready_for_match_preserves_the_chosen_lobby_loadout() {
        let store = SessionStore::new();
        let account = Account::new_dummy(1, "demo_player".to_owned());
        let mut connection = ConnectionState::from_account(0xDD00, &account);
        let selected_id = connection.profile_contents[1].profile_id;
        connection.profile_contents[1].slots[profile_slot_enum::weapon1_slot].dict_id = 55;

        let response = ServerState::new_dummy().handle_client_message(
            &store,
            &mut connection,
            client::Message::ReadyForMatch {
                profile_id: selected_id,
            },
        );

        assert!(matches!(
            response,
            Some(server::Message::ConnectToMatchServer { .. })
        ));
        let selected = store.selected_profile(0xDD00).unwrap();
        assert_eq!(selected.profile_id, selected_id);
        assert_eq!(selected.slots[profile_slot_enum::weapon1_slot].dict_id, 55);
    }
}

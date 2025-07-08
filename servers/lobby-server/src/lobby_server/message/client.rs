use crate::lobby_server::player_profile::raw::profile_slot_enum;
use foundation::network_client::NetworkRequest;
use foundation::serde::{advance_buffer, advance_by, advance_padding};
use foundation::serde::{Deserialize, DeserializeError};

use self::raw::*;

#[derive(Debug, PartialEq)]
pub enum Message {
    ReadyForMatch { profile_id: u32 },
    QueryClientStatus(QueryClientStatus),
    InventoryAction(Vec<InventoryAction>),
    ShopAction(ShopAction),
    SkillsTreeAction(SkillsTreeAction),

    SignInInfo { session_id: u32 },
    PingServer { alive_ms: u32 },
}

#[derive(Debug, PartialEq)]
pub enum QueryClientStatus {
    ClientState,
    EnumerateProfiles,
    ProfileContents { profile_id: u32 },
    EnumerateInventory,
    ProfileSlotsRestrictions,
    ItemsCompatibility,
    PriceItems(faction_id),
    AccountMoney,
    PlayerSkills,
    PlayerSkillsTree,
    ServicePrices,
    PlayerReputations,
}

#[derive(Debug, PartialEq, Clone, Copy)]
pub enum InventoryAction {
    Equip {
        profile_id: u32,
        id: u32,
        dict_id: u16,
        kind: EquipKind,
        amount: u16,
    },
}

#[derive(Debug, PartialEq)]
pub enum SkillsTreeAction {
    Apply { skills: [u8; 5], perks: Vec<u8> },
    Reroll,
}

#[derive(Debug, PartialEq, Clone, Copy)]
pub enum EquipKind {
    Equip {
        to_slot: profile_slot_enum,
    },
    Unequip {
        from_slot: profile_slot_enum,
    },
    Move {
        from_slot: profile_slot_enum,
        to_slot: profile_slot_enum,
    },
}

#[derive(Debug, PartialEq)]
pub enum ShopAction {
    Buy {
        dict_id: u16,
        amount: u16,
        _unknown_1: u16,
        faction_id: faction_id,
    },
}

//
// Raw types received from the wire
//

#[rustfmt::skip]
pub mod raw {
    #![expect(non_camel_case_types)]
    #![expect(dead_code)]

    #[repr(u8)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    pub enum lobby_client_message_types_enum {
        set_status_ready_for_match        = 0x20,
        query_client_status               = 0x21,
        inventory_action                  = 0x23,
        shop_action                       = 0x24,
        skills_tree_action                = 0x25,
        lobby_client_sign_in_info         = 0x26,
        discard_playing_order             = 0x27,
        ping_server                       = 0x28,
        lobby_client_invalid_message_type = 0x2F,
    }

    #[repr(u8)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    pub enum query_info_types_enum {
        q_client_state               = 0x0,
        q_enumerate_profiles         = 0x1,
        q_profile_contents           = 0x2,
        q_enumerate_inventory        = 0x3,
        q_profile_slots_restrictions = 0x4,
        q_items_compatibility        = 0x5,
        q_price_items                = 0x6,
        q_account_money              = 0x7,
        q_player_skills              = 0x8,
        q_player_skills_tree         = 0x9,
        q_service_prices             = 0xA,
        q_player_reputations         = 0xB,
    }

    #[repr(u8)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    pub enum inventory_events_enum {
        item_moved_to_slot = 0x0,
    }

    #[repr(u8)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    pub enum shop_events_enum {
        item_bought = 0x0,
    }

    #[repr(u8)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    pub enum skills_tree_events_enum {
        player_skills_changed = 0x0,
        reroll_skills         = 0x1,
        player_perks_changed  = 0x2,
    }

    #[repr(u8)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    pub enum faction_id {
        scavengers      = 0x1,
        black_market    = 0x2,
        army            = 0x3,
        fringe_settlers = 0x4,
    }

    #[repr(u8)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    pub enum item_moved_to_slot_action_enum {
        failure = 0x0,
        success = 0x1,
    }
}

//
//
//

impl NetworkRequest for Message {}

impl Deserialize for Message {
    /// Process a single message in the array of serialized messages.
    /// Advances `out_buffer` to the next message
    fn deserialize(out_buffer: &mut &[u8]) -> Result<Self, DeserializeError> {
        //
        // [ len | msg_type | ...... ][ len2 | msg_type2 | ...... ]...
        // 0     1          2      1 + len
        //       |<------ len ------>|
        //

        // Don't advance actual `out_buffer` until the message was successfully built.
        let mut tcp_buffer = *out_buffer;
        let tcp_buffer = &mut tcp_buffer;
        let tcp_msg_len = advance_buffer::<u8>(tcp_buffer)? as usize;

        let buffer = *tcp_buffer;
        let buffer = &mut &buffer[..tcp_msg_len];

        let msg_type = advance_buffer::<u8>(buffer)?;
        let msg_type = bytemuck::checked::try_cast(msg_type)
            .map_err(|_| DeserializeError::UnknownMessageType(msg_type))?;

        let msg = match msg_type {
            lobby_client_message_types_enum::set_status_ready_for_match => {
                let profile_id = advance_buffer::<u32>(buffer)?;
                Self::ReadyForMatch { profile_id }
            }

            lobby_client_message_types_enum::query_client_status => {
                let query_info_type = advance_buffer::<query_info_types_enum>(buffer)?;
                let query_client_status = match query_info_type {
                    query_info_types_enum::q_profile_contents => {
                        let profile_id = advance_buffer::<u32>(buffer)?;
                        QueryClientStatus::ProfileContents { profile_id }
                    }

                    query_info_types_enum::q_price_items => {
                        let faction_id = advance_buffer::<faction_id>(buffer)?;
                        QueryClientStatus::PriceItems(faction_id)
                    }

                    query_info_types_enum::q_client_state => {
                        advance_padding::<3>(buffer)?;
                        QueryClientStatus::ClientState
                    }

                    query_info_types_enum::q_enumerate_profiles => {
                        advance_padding::<3>(buffer)?;
                        QueryClientStatus::EnumerateProfiles
                    }

                    query_info_types_enum::q_enumerate_inventory => {
                        advance_padding::<3>(buffer)?;
                        QueryClientStatus::EnumerateInventory
                    }

                    query_info_types_enum::q_profile_slots_restrictions => {
                        advance_padding::<3>(buffer)?;
                        QueryClientStatus::ProfileSlotsRestrictions
                    }

                    query_info_types_enum::q_items_compatibility => {
                        advance_padding::<3>(buffer)?;
                        QueryClientStatus::ItemsCompatibility
                    }

                    query_info_types_enum::q_account_money => {
                        advance_padding::<3>(buffer)?;
                        QueryClientStatus::AccountMoney
                    }

                    query_info_types_enum::q_player_skills => {
                        advance_padding::<3>(buffer)?;
                        QueryClientStatus::PlayerSkills
                    }

                    query_info_types_enum::q_player_skills_tree => {
                        advance_padding::<3>(buffer)?;
                        QueryClientStatus::PlayerSkillsTree
                    }

                    query_info_types_enum::q_service_prices => {
                        advance_padding::<3>(buffer)?;
                        QueryClientStatus::ServicePrices
                    }

                    query_info_types_enum::q_player_reputations => {
                        advance_padding::<3>(buffer)?;
                        QueryClientStatus::PlayerReputations
                    }
                };

                Self::QueryClientStatus(query_client_status)
            }

            // @NOTE: Currently this does only simple checks, but the result would need
            // to be verified even more.
            // So we should either move everything here, or move everything out.
            // Decide which approach will be better. E.g.:
            //  - Moving into an incorrect slot
            //  - Moving non-existing item
            //  - Moving from non-existing profile
            //  - Moving a thing not set in a proper slot
            //  - ... way more
            //
            // Currently this does only type verification, but in the future we would want to wrap
            // `profile_id`, `id` and `dict_id` to their own types as well, so maybe no need to
            // check for kind here?
            lobby_client_message_types_enum::inventory_action => {
                let action_type = advance_buffer::<inventory_events_enum>(buffer)?;
                match action_type {
                    inventory_events_enum::item_moved_to_slot => {
                        let actions_len = advance_buffer::<u8>(buffer)?;
                        let mut actions = vec![];
                        for _ in 0..actions_len {
                            let profile_id = advance_buffer::<u32>(buffer)?;
                            let id = advance_buffer::<u32>(buffer)?;
                            let dict_id = advance_buffer::<u16>(buffer)?;
                            advance_padding::<2>(buffer)?;
                            let from_slot = advance_buffer::<u8>(buffer)?;
                            advance_padding::<3>(buffer)?;
                            let to_slot = advance_buffer::<u8>(buffer)?;
                            advance_padding::<3>(buffer)?;
                            let amount = advance_buffer::<u16>(buffer)?;

                            let kind = match (from_slot, to_slot) {
                                (100, to_slot) => {
                                    let to_slot = bytemuck::checked::try_cast(to_slot)
                                        .map_err(|x| DeserializeError::incorrect_input_from(x))?;
                                    EquipKind::Equip { to_slot }
                                }
                                (from_slot, 100) => {
                                    let from_slot = bytemuck::checked::try_cast(from_slot)
                                        .map_err(|x| DeserializeError::incorrect_input_from(x))?;
                                    EquipKind::Unequip { from_slot }
                                }
                                (from_slot, to_slot) => {
                                    let from_slot = bytemuck::checked::try_cast(from_slot)
                                        .map_err(|x| DeserializeError::incorrect_input_from(x))?;
                                    let to_slot = bytemuck::checked::try_cast(to_slot)
                                        .map_err(|x| DeserializeError::incorrect_input_from(x))?;
                                    EquipKind::Move { from_slot, to_slot }
                                }
                            };

                            actions.push(InventoryAction::Equip {
                                profile_id,
                                id,
                                dict_id,
                                kind,
                                amount,
                            })
                        }
                        Self::InventoryAction(actions)
                    }
                }
            }

            lobby_client_message_types_enum::shop_action => {
                let action_type = advance_buffer::<shop_events_enum>(buffer)?;
                match action_type {
                    shop_events_enum::item_bought => {
                        let dict_id = advance_buffer::<u16>(buffer)?;
                        let amount = advance_buffer::<u16>(buffer)?;
                        let _unknown_1 = advance_buffer::<u16>(buffer)?;
                        let faction_id = advance_buffer::<faction_id>(buffer)?;
                        advance_padding::<1>(buffer)?;

                        Self::ShopAction(ShopAction::Buy {
                            dict_id,
                            amount,
                            _unknown_1,
                            faction_id,
                        })
                    }
                }
            }

            lobby_client_message_types_enum::skills_tree_action => {
                let action_type = advance_buffer::<skills_tree_events_enum>(buffer)?;
                match action_type {
                    skills_tree_events_enum::player_skills_changed => {
                        let [
                            skills_len,
                            skill_1_id,
                            skill_1_points,
                            skill_2_id,
                            skill_2_points,
                            skill_3_id,
                            skill_3_points,
                            skill_4_id,
                            skill_4_points,
                            skill_5_id,
                            skill_5_points,
                            perks_len,
                        ]: [u8; 12] = advance_buffer::<[u8; 12]>(buffer)?;

                        if skills_len != 5
                            || skill_1_id != 1
                            || skill_2_id != 2
                            || skill_3_id != 3
                            || skill_4_id != 4
                            || skill_5_id != 5
                            || skill_1_points > 20
                            || skill_2_points > 20
                            || skill_3_points > 20
                            || skill_4_points > 20
                            || skill_5_points > 20
                        {
                            return Err(DeserializeError::incorrect_input());
                        }

                        let perks = advance_by::<u8>(perks_len as usize, buffer)?;

                        Self::SkillsTreeAction(SkillsTreeAction::Apply {
                            skills: [
                                skill_1_points,
                                skill_2_points,
                                skill_3_points,
                                skill_4_points,
                                skill_5_points,
                            ],
                            perks: perks.to_vec(),
                        })
                    }

                    skills_tree_events_enum::reroll_skills => {
                        Self::SkillsTreeAction(SkillsTreeAction::Reroll)
                    }

                    skills_tree_events_enum::player_perks_changed => todo!(),
                }
            }

            lobby_client_message_types_enum::lobby_client_sign_in_info => {
                let session_id = advance_buffer::<u32>(buffer)?;
                Self::SignInInfo { session_id }
            }

            lobby_client_message_types_enum::discard_playing_order => todo!(),

            lobby_client_message_types_enum::ping_server => {
                let alive_ms = advance_buffer::<u32>(buffer)?;
                Self::PingServer { alive_ms }
            }

            lobby_client_message_types_enum::lobby_client_invalid_message_type => {
                todo!()
            }
        };

        // Unaccounted for trailing bytes.
        if !buffer.is_empty() {
            return Err(DeserializeError::incorrect_input());
        }

        *out_buffer = &out_buffer[tcp_msg_len + 1..];
        Ok(msg)
    }
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn parses_single_query_client_msg() {
        let buffer: &[u8] = &[5, 33, 10, 0, 0, 0];
        let defacto = Message::deserialize(&mut buffer.as_ref()).unwrap();
        let dejure = Message::QueryClientStatus(QueryClientStatus::ServicePrices);
        assert_eq!(defacto, dejure);
    }

    #[test]
    fn parses_multiple_query_client_msg() {
        #[rustfmt::skip]
        let buffer: &[u8] = &[
            5, 33, 5, 0, 0, 0,
            5, 33, 9, 0, 0, 0,
            5, 33, 10, 0, 0, 0,
            3, 33, 6, 1,
            3, 33, 6, 2,
            3, 33, 6, 3,
            3, 33, 6, 4,
            5, 33, 0, 0, 0, 0,
        ];
        let buffer = &mut buffer.as_ref();

        let msg_num_dejure = 8;
        let mut msg_num_defacto = 0;
        let mut msgs = vec![];

        while !buffer.is_empty() {
            msg_num_defacto += 1;
            msgs.push(Message::deserialize(buffer).unwrap());
        }

        assert_eq!(msg_num_defacto, msg_num_dejure);

        assert_eq!(
            msgs[2],
            Message::QueryClientStatus(QueryClientStatus::ServicePrices),
        );

        assert_eq!(
            msgs[4],
            Message::QueryClientStatus(QueryClientStatus::PriceItems(faction_id::black_market)),
        );

        assert_eq!(
            msgs[7],
            Message::QueryClientStatus(QueryClientStatus::ClientState)
        );
    }

    #[test]
    fn parses_inventory_actions() {
        // Move something into an incorrect slot
        let buffer: &[u8] = &[3, 35, 0, 0];
        let defacto = Message::deserialize(&mut buffer.as_ref()).unwrap();
        let dejure = Message::InventoryAction(vec![]);
        assert_eq!(defacto, dejure);

        // Move medkit (x9) from inventory to profile:
        let buffer: &[u8] = &[
            25, 35, 0, 1, 64, 13, 3, 0, 10, 0, 0, 0, 67, 0, 0, 0, 100, 0, 0, 0, 13, 0, 0, 0, 9, 0,
        ];
        let defacto = Message::deserialize(&mut buffer.as_ref()).unwrap();
        let dejure = Message::InventoryAction(vec![InventoryAction::Equip {
            profile_id: 200_000,
            id: 10,
            dict_id: 67,
            kind: EquipKind::Equip {
                to_slot: profile_slot_enum::quick_slot1,
            },
            amount: 9,
        }]);
        assert_eq!(defacto, dejure);

        // Move UZI from profile to inventory (from second profile):
        let buffer: &[u8] = &[
            25, 35, 0, 1, 128, 26, 6, 0, 12, 0, 0, 0, 55, 0, 0, 0, 7, 0, 0, 0, 100, 0, 0, 0, 1, 0,
        ];
        let defacto = Message::deserialize(&mut buffer.as_ref()).unwrap();
        let dejure = Message::InventoryAction(vec![InventoryAction::Equip {
            profile_id: 400_000,
            id: 12,
            dict_id: 55,
            kind: EquipKind::Unequip {
                from_slot: profile_slot_enum::weapon1_slot,
            },
            amount: 1,
        }]);
        assert_eq!(defacto, dejure);
    }

    // Unequips UZI and ammo
    #[test]
    fn parses_multiple_inventory_actions() {
        let buffer: &[u8] = &[
            69, /* tcp_msg_len */
            35, /* inventory_action */
            0,  /* item_moved_to_slot */
            3,  /* action_len */
            64, 13, 3, 0, 12, 0, 0, 0, 55, 0, 0, 0, 7, 0, 0, 0, 100, 0, 0, 0, 1, 0, /* 1 */
            64, 13, 3, 0, 33, 0, 0, 0, 53, 0, 0, 0, 8, 0, 0, 0, 100, 0, 0, 0, 244, 1, /* 2 */
            64, 13, 3, 0, 33, 0, 0, 0, 53, 0, 0, 0, 9, 0, 0, 0, 100, 0, 0, 0, 244, 1, /* 3 */
        ];
        let _defacto = Message::deserialize(&mut buffer.as_ref()).unwrap();
    }

    #[test]
    fn parses_set_ready_for_match() {
        let buffer: &[u8] = &[5, 32, 1, 0, 0, 0];
        let defacto = Message::deserialize(&mut buffer.as_ref()).unwrap();
        let dejure = Message::ReadyForMatch { profile_id: 1 };
        assert_eq!(defacto, dejure);
    }

    #[test]
    fn parses_shop_actions() {
        // Bying item
        let buffer: &[u8] = &[10, 36, 0, 7, 0, 220, 5, 0, 0, 1, 0];
        let defacto = Message::deserialize(&mut buffer.as_ref()).unwrap();
        let dejure = Message::ShopAction(ShopAction::Buy {
            dict_id: 7,
            amount: 1500,
            _unknown_1: 0,
            faction_id: faction_id::scavengers,
        });
        assert_eq!(defacto, dejure);
    }

    #[test]
    fn parses_skills_tree_actions() {
        // Removing all skill points (costs in gold)
        let buffer: &[u8] = &[2, 37, 1];
        let defacto = Message::deserialize(&mut buffer.as_ref()).unwrap();
        let dejure = Message::SkillsTreeAction(SkillsTreeAction::Reroll);
        assert_eq!(defacto, dejure);

        // Applying level points (without skills)
        let buffer: &[u8] = &[14, 37, 0, 5, 1, 2, 2, 0, 3, 0, 4, 0, 5, 0, 0];
        let defacto = Message::deserialize(&mut buffer.as_ref()).unwrap();
        let dejure = Message::SkillsTreeAction(SkillsTreeAction::Apply {
            skills: [2, 0, 0, 0, 0],
            perks: vec![],
        });
        assert_eq!(defacto, dejure);
        // Applying level points (with skills)
        let buffer: &[u8] = &[
            21, 37, 0, 5, 1, 20, 2, 9, 3, 9, 4, 9, 5, 0, 7, 2, 7, 9, 11, 15, 17, 24,
        ];
        let defacto = Message::deserialize(&mut buffer.as_ref()).unwrap();
        let dejure = Message::SkillsTreeAction(SkillsTreeAction::Apply {
            skills: [20, 9, 9, 9, 0],
            perks: vec![2, 7, 9, 11, 15, 17, 24],
        });
        assert_eq!(defacto, dejure);
    }

    // struct price_item {
    //     item_dict_id: u16,
    //     cost: u16,
    //     reputation_level: u8,
    // }
}

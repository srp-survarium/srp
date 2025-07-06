use crate::{
    lobby_server::player_profile,
    network_client::{DeserializeError, NetworkMessage, Packet},
};

use super::client::raw::{faction_id, lobby_client_message_types_enum, query_info_types_enum};

#[derive(Debug)]
pub enum Message {
    ConnectionSuccessful,

    #[allow(dead_code)]
    InvalidSessionId,

    #[allow(dead_code)]
    InvalidPassword,

    ConnectToMatchServer {
        match_id: u32,
        team_id: u8,
    },

    OperationPermitted(Operation),

    #[allow(dead_code)]
    OperationDenied(Operation),

    ClientStatus(ClientStatus),

    #[allow(dead_code)]
    PingServerAnswer {
        ping_value: u32,
    },
}

#[derive(Debug, Clone)]
pub enum Operation {
    Inventory,
    Shop(ShopOperation),
    #[allow(dead_code)]
    SkillsTree,
}

#[derive(Debug, Clone, Copy)]
pub enum ShopOperation {
    ActionBought {
        dict_id: u16,
        id: u32,
        condition_or_stack: u32,
    },
}

#[derive(Debug, Clone)]
pub enum ClientStatus {
    ClientState {
        // @TODO: This should be an enum of some kind.
        // Figure out its values and what they correspond to.
        status: u8,
        // @TODO: This message might be optional.
        last_status_message: String,
    },
    EnumerateProfiles(Vec<Profile>),
    ProfileContents(Box<player_profile::player_profile>),
    EnumerateInventory(Vec<player_profile::inventory_item_instance>),
    ProfileSlotsRestrictions(Vec<profile_slot_restriction>),
    ItemsCompatibility(Vec<items_compatibility>),
    PriceItems {
        faction_id: faction_id,
        price_items: Vec<price_item>,
    },
    AccountMoney {
        generic_money: u32,
        premium_money: u32,
        skill_points: u8,
        name: String,
    },
    PlayerSkills {
        total_experience: u32,
        next_level_experience: u32,
        prev_level_experience: u32,
        player_skills: [player_skill; 5],
        // @TODO: This is currently skipped
        // player_perks
    },
    PlayerSkillsTree {
        // @TODO: Make it into a type
        skills_tree: Vec<u8>,
    },
    ServicePrices {
        reroll_cost: u32,
        add_profile_cost: u32,
        rename_account_cost: u32,
    },
    PlayerReputations([player_reputation; 4]),
}

#[derive(Debug, Clone)]
pub struct Profile {
    pub profile_id: u32,
    // @TODO: Use sized string to 128 bytes
    pub name: String,
}

#[derive(Debug, Clone)]
#[repr(C)]
pub struct profile_slot_restriction {
    pub slot_dict_id: u8,
    pub category_dict_id: u8,
}

impl profile_slot_restriction {
    pub fn serialize(&self) -> &[u8] {
        let ptr = self as *const _ as *const u8;
        let len = std::mem::size_of::<Self>();
        unsafe { std::slice::from_raw_parts(ptr, len) }
    }
}

#[derive(Debug, Clone)]
#[repr(C)]
pub struct items_compatibility {
    pub first_item_dict_id: u16,
    pub second_item_dict_id: u16,
}

impl items_compatibility {
    pub fn serialize(&self) -> &[u8] {
        let ptr = self as *const _ as *const u8;
        let len = std::mem::size_of::<Self>();
        unsafe { std::slice::from_raw_parts(ptr, len) }
    }
}

#[derive(Debug, Clone)]
#[repr(C)]
pub struct price_item {
    pub item_dict_id: u16,
    pub cost: u16,
    pub reputation_level: u8,
    pub padding: u8,
}

impl price_item {
    pub fn serialize(&self) -> &[u8] {
        let ptr = self as *const _ as *const u8;
        let len = std::mem::size_of::<Self>();
        unsafe { std::slice::from_raw_parts(ptr, len) }
    }
}

#[derive(Debug, Clone)]
#[repr(C)]
pub struct player_skill {
    pub skill_id: u8,
    pub skill_points: u8,
}

impl player_skill {
    pub fn serialize(&self) -> &[u8] {
        let ptr = self as *const _ as *const u8;
        let len = std::mem::size_of::<Self>();
        unsafe { std::slice::from_raw_parts(ptr, len) }
    }
}

#[derive(Debug, Clone)]
#[repr(C)]
pub struct player_reputation {
    pub faction_id: faction_id,
    pub reputation_points: u16,
}

impl player_reputation {
    pub fn serialize(&self) -> &[u8] {
        let ptr = self as *const _ as *const u8;
        let len = std::mem::size_of::<Self>();
        unsafe { std::slice::from_raw_parts(ptr, len) }
    }
}

impl Message {
    #[rustfmt::skip]
    fn as_u8(&self) -> u8 {
        match self {
            Self::ConnectionSuccessful { .. } => lobby_server_message_types_enum::connection_successful   as u8,
            Self::InvalidSessionId { .. }     => lobby_server_message_types_enum::invalid_session_id      as u8,
            Self::InvalidPassword { .. }      => lobby_server_message_types_enum::invalid_password        as u8,
            Self::ConnectToMatchServer { .. } => lobby_server_message_types_enum::connect_to_match_server as u8,
            Self::OperationPermitted { .. }   => lobby_server_message_types_enum::operation_permitted     as u8,
            Self::OperationDenied { .. }      => lobby_server_message_types_enum::operation_denied        as u8,
            Self::ClientStatus { .. }         => lobby_server_message_types_enum::client_status           as u8,
            Self::PingServerAnswer { .. }     => lobby_server_message_types_enum::ping_server_answer      as u8,
        }
    }
}

impl Operation {
    #[rustfmt::skip]
    fn as_u8(&self) -> u8 {
        match self {
            Self::Inventory { .. }  => lobby_client_message_types_enum::inventory_action   as u8,
            Self::Shop { .. }       => lobby_client_message_types_enum::shop_action        as u8,
            Self::SkillsTree { .. } => lobby_client_message_types_enum::skills_tree_action as u8,
        }
    }
}

impl ShopOperation {
    #[rustfmt::skip]
    fn as_u8(&self) -> u8 {
        match self {
            Self::ActionBought { .. } => 1,
        }
    }
}

impl ClientStatus {
    #[rustfmt::skip]
    fn as_u8(&self) -> u8 {
        match self {
            Self::ClientState { .. }              => query_info_types_enum::q_client_state               as u8,
            Self::EnumerateProfiles { .. }        => query_info_types_enum::q_enumerate_profiles         as u8,
            Self::ProfileContents { .. }          => query_info_types_enum::q_profile_contents           as u8,
            Self::EnumerateInventory { .. }       => query_info_types_enum::q_enumerate_inventory        as u8,
            Self::ProfileSlotsRestrictions { .. } => query_info_types_enum::q_profile_slots_restrictions as u8,
            Self::ItemsCompatibility { .. }       => query_info_types_enum::q_items_compatibility        as u8,
            Self::PriceItems { .. }               => query_info_types_enum::q_price_items                as u8,
            Self::AccountMoney { .. }             => query_info_types_enum::q_account_money              as u8,
            Self::PlayerSkills { .. }             => query_info_types_enum::q_player_skills              as u8,
            Self::PlayerSkillsTree { .. }         => query_info_types_enum::q_player_skills_tree         as u8,
            Self::ServicePrices { .. }            => query_info_types_enum::q_service_prices             as u8,
            Self::PlayerReputations { .. }        => query_info_types_enum::q_player_reputations         as u8,
        }
    }
}

//
//
//

#[rustfmt::skip]
#[derive(num_derive::FromPrimitive, Debug, PartialEq)]
#[expect(non_camel_case_types)]
#[repr(u8)]
enum lobby_server_message_types_enum {
    connection_successful             = 0x30,
    invalid_session_id                = 0x31,
    invalid_password                  = 0x32,
    connect_to_match_server           = 0x33,
    operation_permitted               = 0x34,
    operation_denied                  = 0x35,
    client_status                     = 0x36,
    ping_server_answer                = 0x37,
    lobby_server_invalid_message_type = 0x3F,
}

//
//
//

impl NetworkMessage for Message {
    fn deserialize(_out_buffer: &mut &[u8]) -> Result<Self, DeserializeError> {
        unimplemented!()
    }

    fn serialize(self, packet: &mut Packet) {
        packet.push(self.as_u8());
        match self {
            Self::ConnectionSuccessful => (),

            Self::InvalidSessionId => todo!(),
            Self::InvalidPassword => todo!(),

            Self::ConnectToMatchServer { match_id, team_id } => {
                let len: u8 = foundation::match_server::ADDRESS.len().try_into().unwrap();
                packet.push(len);
                packet.extend(foundation::match_server::ADDRESS.as_bytes());
                packet.extend(foundation::match_server::PORT.to_le_bytes());
                packet.extend(match_id.to_le_bytes());
                packet.push(team_id);
            }

            Self::OperationPermitted(action) => {
                action.serialize(packet);
            }
            Self::OperationDenied(action) => {
                action.serialize(packet);
            }

            Self::ClientStatus(client_status) => {
                client_status.serialize(packet);
            }

            Self::PingServerAnswer { ping_value } => {
                packet.extend(ping_value.to_le_bytes());
            }
        }
    }
}

impl NetworkMessage for Operation {
    fn deserialize(_out_buffer: &mut &[u8]) -> Result<Self, DeserializeError> {
        unimplemented!()
    }

    fn serialize(self, packet: &mut Packet) {
        packet.push(self.as_u8());

        match self {
            Self::Shop(
                action @ ShopOperation::ActionBought {
                    dict_id,
                    id,
                    condition_or_stack,
                },
            ) => {
                packet.push(action.as_u8());

                packet.extend(dict_id.to_le_bytes());
                packet.extend(id.to_le_bytes());
                packet.extend(condition_or_stack.to_le_bytes());
            }
            Self::Inventory | Self::SkillsTree => (),
        }
    }
}

impl NetworkMessage for ClientStatus {
    fn deserialize(_out_buffer: &mut &[u8]) -> Result<Self, DeserializeError> {
        unimplemented!()
    }

    fn serialize(self, packet: &mut Packet) {
        packet.push(self.as_u8());
        match self {
            Self::ClientState {
                status,
                last_status_message,
            } => {
                packet.push(status);

                let last_status_message_len: u8 = last_status_message.len().try_into().unwrap();
                packet.push(last_status_message_len);
                packet.extend(last_status_message.as_bytes());
            }

            Self::EnumerateProfiles(profiles) => {
                assert!(1 <= profiles.len() && profiles.len() < 4);

                let profiles_len: u8 = profiles.len().try_into().unwrap();
                packet.push(profiles_len);

                for Profile { profile_id, name } in profiles {
                    packet.extend(profile_id.to_le_bytes());

                    let name_len: u8 = name.len().try_into().unwrap();
                    packet.push(name_len);
                    packet.extend(name.as_bytes());
                }
            }

            Self::ProfileContents(player_profile) => packet.extend(player_profile.deserialize()),

            Self::EnumerateInventory(items) => {
                let items_len: u32 = items.len().try_into().unwrap();
                packet.extend(items_len.to_le_bytes());

                for item in items {
                    packet.extend(item.serialize());
                }
            }

            Self::ProfileSlotsRestrictions(restricts) => {
                let restricts_len: u32 = restricts.len().try_into().unwrap();
                packet.extend(restricts_len.to_le_bytes());

                for restrict in restricts {
                    packet.extend(restrict.serialize());
                }
            }

            Self::ItemsCompatibility(compats) => {
                let compats_len: u32 = compats.len().try_into().unwrap();
                packet.extend(compats_len.to_le_bytes());

                for compat in compats {
                    packet.extend(compat.serialize());
                }
            }

            Self::PriceItems {
                faction_id,
                price_items,
            } => {
                packet.push(faction_id as u8);

                let price_items_len: u32 = price_items.len().try_into().unwrap();
                packet.extend(price_items_len.to_le_bytes());

                for price_item in price_items {
                    packet.extend(price_item.serialize());
                }
            }

            Self::AccountMoney {
                generic_money,
                premium_money,
                skill_points,
                name,
            } => {
                packet.extend(generic_money.to_le_bytes());
                packet.extend(premium_money.to_le_bytes());

                packet.push(skill_points);

                let name_len: u8 = name.len().try_into().unwrap();
                packet.push(name_len);
                packet.extend(name.as_bytes());
            }

            Self::PlayerSkills {
                total_experience,
                next_level_experience,
                prev_level_experience,
                player_skills,
            } => {
                packet.extend(total_experience.to_le_bytes());
                packet.extend(next_level_experience.to_le_bytes());
                packet.extend(prev_level_experience.to_le_bytes());

                let player_skills_len: u8 = player_skills.len().try_into().unwrap();
                packet.push(player_skills_len);

                for player_skill in player_skills {
                    packet.extend(player_skill.serialize())
                }

                packet.push(0); // player_perks_len
            }

            Self::PlayerSkillsTree { skills_tree } => packet.extend(skills_tree.as_slice()),

            Self::ServicePrices {
                reroll_cost,
                add_profile_cost,
                rename_account_cost,
            } => {
                packet.extend(reroll_cost.to_le_bytes());
                packet.extend(add_profile_cost.to_le_bytes());
                packet.extend(rename_account_cost.to_le_bytes());
            }

            Self::PlayerReputations(reps) => {
                let reps_len: u8 = reps.len().try_into().unwrap();
                packet.push(reps_len);

                for rep in reps {
                    packet.extend(rep.serialize())
                }
            }
        }
    }
}

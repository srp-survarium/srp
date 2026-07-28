use crate::lobby_server::message::client::raw::{
    faction_id, lobby_client_message_types_enum, query_info_types_enum,
};
use survarium::player_profile;
use vostok::config;
use vostok::network_client::NetworkResponse;
use vostok::network_packet::Packet;
use vostok::serde::Serialize;

use self::raw::*;

#[derive(Debug)]
pub enum Message {
    ConnectionSuccessful,
    InvalidSessionId,
    InvalidPassword,
    ConnectToMatchServer { match_id: u32, team_id: u8 },
    OperationPermitted(Operation),
    OperationDenied(Operation),
    ClientStatus(ClientStatus),
    PingServerAnswer { ping_value: u32 },
}

#[derive(Debug, Clone)]
pub enum Operation {
    Inventory,
    Shop(ShopOperation),
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
    ProfileContents(Box<player_profile::raw::player_profile>),
    EnumerateInventory(Vec<player_profile::raw::inventory_item_instance>),
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

//
// Raw types sent to the wire
//

pub mod raw {
    #![expect(non_camel_case_types)]

    use crate::lobby_server::message::client::raw::faction_id;

    #[rustfmt::skip]
    #[repr(u8)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    pub enum lobby_server_message_types_enum {
        connection_successful             = 0x30,
        invalid_session_id                = 0x31,
        invalid_password                  = 0x32,
        connect_to_match_server           = 0x33,
        operation_permitted               = 0x34,
        operation_denied                  = 0x35,
        client_status                     = 0x36,
        ping_server_answer                = 0x37,
        #[expect(dead_code)]
        lobby_server_invalid_message_type = 0x3F,
    }

    #[repr(C)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    pub struct profile_slot_restriction {
        pub slot_dict_id: u8,
        pub category_dict_id: u8,
    }

    #[repr(C)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    pub struct items_compatibility {
        pub first_item_dict_id: u16,
        pub second_item_dict_id: u16,
    }

    #[repr(C)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    pub struct price_item {
        pub item_dict_id: u16,
        pub cost: u16,
        pub reputation_level: u8,
        pub padding: [u8; 1],
    }

    #[repr(C)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    pub struct player_skill {
        pub skill_id: u8,
        pub skill_points: u8,
    }

    #[repr(C)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    pub struct player_reputation {
        pub faction_id: faction_id,
        pub padding: [u8; 1],
        pub reputation_points: u16,
    }
}

impl Message {
    #[rustfmt::skip]
    fn tag(&self) -> lobby_server_message_types_enum {
        match self {
            Self::ConnectionSuccessful { .. } => lobby_server_message_types_enum::connection_successful  ,
            Self::InvalidSessionId { .. }     => lobby_server_message_types_enum::invalid_session_id     ,
            Self::InvalidPassword { .. }      => lobby_server_message_types_enum::invalid_password       ,
            Self::ConnectToMatchServer { .. } => lobby_server_message_types_enum::connect_to_match_server,
            Self::OperationPermitted { .. }   => lobby_server_message_types_enum::operation_permitted    ,
            Self::OperationDenied { .. }      => lobby_server_message_types_enum::operation_denied       ,
            Self::ClientStatus { .. }         => lobby_server_message_types_enum::client_status          ,
            Self::PingServerAnswer { .. }     => lobby_server_message_types_enum::ping_server_answer     ,
        }
    }
}

impl Operation {
    #[rustfmt::skip]
    fn tag(&self) -> lobby_client_message_types_enum {
        match self {
            Self::Inventory { .. }  => lobby_client_message_types_enum::inventory_action  ,
            Self::Shop { .. }       => lobby_client_message_types_enum::shop_action       ,
            Self::SkillsTree { .. } => lobby_client_message_types_enum::skills_tree_action,
        }
    }
}

impl ShopOperation {
    #[rustfmt::skip]
    fn tag(&self) -> lobby_client_message_types_enum {
        match self {
            Self::ActionBought { .. } => lobby_client_message_types_enum::shop_action,
        }
    }
}

impl ClientStatus {
    #[rustfmt::skip]
    fn tag(&self) -> query_info_types_enum {
        match self {
            Self::ClientState { .. }              => query_info_types_enum::q_client_state              ,
            Self::EnumerateProfiles { .. }        => query_info_types_enum::q_enumerate_profiles        ,
            Self::ProfileContents { .. }          => query_info_types_enum::q_profile_contents          ,
            Self::EnumerateInventory { .. }       => query_info_types_enum::q_enumerate_inventory       ,
            Self::ProfileSlotsRestrictions { .. } => query_info_types_enum::q_profile_slots_restrictions,
            Self::ItemsCompatibility { .. }       => query_info_types_enum::q_items_compatibility       ,
            Self::PriceItems { .. }               => query_info_types_enum::q_price_items               ,
            Self::AccountMoney { .. }             => query_info_types_enum::q_account_money             ,
            Self::PlayerSkills { .. }             => query_info_types_enum::q_player_skills             ,
            Self::PlayerSkillsTree { .. }         => query_info_types_enum::q_player_skills_tree        ,
            Self::ServicePrices { .. }            => query_info_types_enum::q_service_prices            ,
            Self::PlayerReputations { .. }        => query_info_types_enum::q_player_reputations        ,
        }
    }
}

//
//
//

//
//
//

impl NetworkResponse for Message {}
impl Serialize for Message {
    fn serialize(self, packet: &mut impl Packet) {
        packet.write(self.tag());
        match self {
            // @TODO: Why is this skipped?
            Self::ConnectionSuccessful => (),

            Self::InvalidSessionId | Self::InvalidPassword => todo!(),

            Self::ConnectToMatchServer { match_id, team_id } => {
                let match_server = &config::get().match_server;
                packet.write_str(&match_server.public_host);
                packet.write(match_server.port);
                packet.write(match_id);
                packet.write(team_id);
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
                packet.write(ping_value);
            }
        }
    }
}

impl Serialize for Operation {
    fn serialize(self, packet: &mut impl Packet) {
        packet.write(self.tag());

        match self {
            Self::Shop(
                action @ ShopOperation::ActionBought {
                    dict_id,
                    id,
                    condition_or_stack,
                },
            ) => {
                packet.write(action.tag());
                packet.write(dict_id);
                packet.write(id);
                packet.write(condition_or_stack);
            }
            Self::Inventory | Self::SkillsTree => (),
        }
    }
}

impl Serialize for ClientStatus {
    fn serialize(self, packet: &mut impl Packet) {
        packet.write(self.tag());
        match self {
            Self::ClientState {
                status,
                last_status_message,
            } => {
                packet.write(status);
                packet.write_str(&last_status_message);
            }

            Self::EnumerateProfiles(profiles) => {
                debug_assert!(profiles.len() < 4);

                let profiles_len: u8 = profiles.len().try_into().unwrap();
                packet.write(profiles_len);

                for Profile { profile_id, name } in profiles {
                    packet.write(profile_id);
                    packet.write_str(&name);
                }
            }

            Self::ProfileContents(player_profile) => player_profile.serialize_tcp(packet),

            Self::EnumerateInventory(items) => {
                packet.write_vec::<u32, _, _>(items);
            }

            Self::ProfileSlotsRestrictions(restricts) => {
                packet.write_vec::<u32, _, _>(restricts);
            }

            Self::ItemsCompatibility(compats) => {
                packet.write_vec::<u32, _, _>(compats);
            }

            Self::PriceItems {
                faction_id,
                price_items,
            } => {
                packet.write(faction_id);
                packet.write_vec::<u32, _, _>(price_items);
            }

            Self::AccountMoney {
                generic_money,
                premium_money,
                skill_points,
                name,
            } => {
                packet.write(generic_money);
                packet.write(premium_money);
                packet.write(skill_points);
                packet.write_str(&name);
            }

            Self::PlayerSkills {
                total_experience,
                next_level_experience,
                prev_level_experience,
                player_skills,
            } => {
                packet.write(total_experience);
                packet.write(next_level_experience);
                packet.write(prev_level_experience);
                packet.write_slice::<u8, _, _>(&player_skills);
                packet.write(0_u8); // player_perks_len
            }

            Self::PlayerSkillsTree { skills_tree } => packet.append_bytes(skills_tree.as_slice()),

            Self::ServicePrices {
                reroll_cost,
                add_profile_cost,
                rename_account_cost,
            } => {
                packet.write(reroll_cost);
                packet.write(add_profile_cost);
                packet.write(rename_account_cost);
            }

            Self::PlayerReputations(reps) => {
                packet.write_slice::<u8, _, _>(&reps);
            }
        }
    }
}

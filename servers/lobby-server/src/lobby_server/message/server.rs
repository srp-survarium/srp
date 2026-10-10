// SPDX-License-Identifier: GPL-3.0-or-later
use crate::lobby_server::message::client::raw::{
    faction_id, lobby_client_message_types_enum, query_info_types_enum,
};
use survarium::player_profile;
use survarium::player_profile::raw::game_team_id;
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
    ConnectToMatchServer {
        match_id: u32,
        team_id: u8,
    },
    OperationPermitted(Operation),
    OperationDenied {
        operation: Operation,
        reason: String,
    },
    ClientStatus(ClientStatus),
    PingServerAnswer {
        ping_value: u32,
    },
    OnlineStats {
        players: u32,
        matches: u32,
        maintenance_remain: u32,
    },
    SquadInfo {},
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
        state: ClientState,
        last_status_message: Option<String>,
    },
    EnumerateProfiles(Vec<Profile>),
    ProfileContents(survarium::player_profile::PlayerProfile),
    EnumerateInventory(Vec<player_profile::raw::inventory_item_instance>),
    PriceItems {
        faction_id: faction_id,
        price_items: Vec<price_item>,
    },
    AccountMoney {
        generic_money: u32,
        premium_money: u32,
        name: String,
    },
    PlayerSkills {
        profile_id: u32,

        skill_points_total: u8,
        current_exp: u32,
        next_level_exp: u32,
        prev_level_exp: u32,

        player_skills: [player_skill; 5],
        // @TODO: This is currently skipped
        // player_perks
    },
    // PlayerProfileLeveling
    ServicePrices {
        reroll_cost: u32,
        add_profile_cost: u32,
        rename_account_cost: u32,
    },
    PlayerReputations([player_reputation; 4]),
    PlayersTotalCount {
        player_count: u32,
    },
    LastPlayerMatchStats {
        player_match_stats: player_match_stats,
    },
    PlayerEloRating {
        place: u32,
        elo: u16,
        last_elo: u16,
    },
    PlayerEloList {
        player_elo_stats: Vec<PlayerEloStats>,
    },
    PlayerQuestList {
        player_quest_list: Vec<quest_instance>,
    },
    PlayerMatchStats {
        player_match_stats: player_match_stats,
    },
    PlayerServices {
        loaylties: Vec<Loaylty>, // in reality cannot be bigger than 5
    },
    ShopItems {
        shop_items: Vec<ShopItemContainer>,
    },
    UnlockedFactionsMask {
        mask: u8,
    },
}

#[derive(Debug, Clone)]
pub enum ClientState {
    SurfLobbyMenu,
    InMatchMaking {
        match_order_id: u32,
        match_order_place: u32,
        match_orders_total: u32,
        match_order_current_time_sec: u32,
        match_order_avg_wait_sec: u32,
        // fyi sets team_undefined
    },
    InMatch {
        match_order_id: u32,
        match_id: u32,
        team_id: game_team_id,
    },
    Unknown,
}

#[derive(Debug, Clone)]
pub struct Profile {
    pub profile_id: u32,
    pub name: String, // 64

    pub autobuy_items: bool,
    pub skill_points_total: u8,
    pub current_exp: u32,
    pub prev_level_exp: u32,
    pub next_level_exp: u32,
    pub revision: u32,
}

#[derive(Debug, Clone)]
pub struct PlayerEloStats {
    pub place: u32,
    pub name: String, // 64
    pub ranking: u16,
    pub ranking_diff: i16,
}

#[derive(Debug, Clone)]
pub enum Loaylty {
    Premium {
        premium_hours_left: u32,
    },
    Faction {
        faction_id: faction_id,
        loaylty_value: u8,
    },
}

#[derive(Debug, Clone)]
pub struct ShopItemContainer {
    id: u32,
    shelf_id: shop_shelf_enum,
    cost: u32,
    name: String,  // 32
    descr: String, // 32
    currency: currency_type,
    items: Vec<ShopItem>, // u8::MAX
}

#[repr(C)]
#[derive(bytemuck::CheckedBitPattern, Copy, Clone, Debug, PartialEq)]
pub struct ShopItem {
    id: u32,
    base_cost: u32,
    amount: u32,
    base_amount: u32,
    ttl: u32,
    base_ttl: u32,
    ttl_type: shop_item_ttl_type,
    item_type: shop_item_type,
}

/*

struct survarium::shop_items_container
{
  unsigned int id;
  survarium::shop_shelf_enum shelf_id;
  unsigned int cost;
  char name[32];
  char descr[32];
  unsigned __int8 items_count;
  survarium::shop_item items[5];
  survarium::currency_type currency;
};


struct survarium::shop_item
{
  unsigned int id;
  unsigned int base_cost;
  unsigned int cost;
  unsigned int amount;
  unsigned int base_amount;
  unsigned int ttl;
  unsigned int base_ttl;
  survarium::shop_item_ttl_type ttl_type;
  survarium::shop_item_type item_type;
};

*/

//
// Raw types sent to the wire
//

pub mod raw {
    #![expect(non_camel_case_types)]

    use crate::lobby_server::message::client::raw::faction_id;

    // survarium::network_client::on_lobby_packet_received
    #[rustfmt::skip]
    #[repr(u8)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    pub enum lobby_server_message_types_enum {
        connection_successful             = 0x30,
        invalid_session_id                = 0x31,
        invalid_password                  = 0x32,
        connect_to_match_server           = 0x33, // +
        operation_permitted               = 0x34,
        operation_denied                  = 0x35,
        client_status                     = 0x36,
        ping_server_answer                = 0x37,
        online_stats                      = 0x38, // +
        squad_info                        = 0x39, // +
        #[expect(dead_code)]
        lobby_server_invalid_message_type = 0x3F,
    }

    #[rustfmt::skip]
    #[repr(u8)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    pub enum shop_item_type {
        item    = 0x0,
        service = 0x1,
        bundle  = 0x2,
    }

    #[rustfmt::skip]
    #[repr(u8)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    pub enum shop_item_ttl_type {
        permanent             = 0x0,
        time_dependent        = 0x1,
        amount_dependent      = 0x2,
        time_amount_dependent = 0x3,
    }

    #[rustfmt::skip]
    #[repr(u8)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    pub enum shop_shelf_enum {
        premium_shelf = 0x0,
    }

    #[rustfmt::skip]
    #[repr(u8)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    pub enum currency_type {
        generic_money = 0x0,
        premium_money = 0x1,
    }

    #[rustfmt::skip]
    #[repr(u8)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    pub enum client_state_enum {
        surf_lobby_menu = 0x0,
        in_match_making = 0x1,
        in_match        = 0x2,
        unknown         = 0x3,
    }

    //
    //
    //

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
        pub padding_1: [u8; 2],
        pub cost: u32,
        pub reputation_level: u8,
        pub padding_2: [u8; 3],
    }
    const _: () = assert!(std::mem::size_of::<price_item>() == 12);

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
        pub padding_1: [u8; 3],
        pub unlocked: bool,
        pub padding_2: [u8; 1],
        pub reputation_points: u16,
    }
    const _: () = assert!(std::mem::size_of::<player_reputation>() == 8);

    // Servers sends it differently
    #[repr(C)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    pub struct player_elo_stats {
        pub place: u32,
        pub name: [u8; 64],
        pub ranking: u16,
        pub ranking_diff: i16,
    }
    const _: () = assert!(std::mem::size_of::<player_elo_stats>() == 0x48);

    #[repr(C)]
    #[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
    pub struct quest_instance {
        pub id: u32,
        pub dict_id: u32,
        pub progress: u32,
        pub ttl_minutes: i32,
        pub status: u8,
        pub padding_2: [u8; 3],
    }
    const _: () = assert!(std::mem::size_of::<quest_instance>() == 0x14);

    #[repr(C)]
    #[derive(bytemuck::CheckedBitPattern, Copy, Clone, Debug, PartialEq)]
    pub struct player_match_stats {
        pub profile_id: u32,
        pub kills: u16,
        pub deaths: u16,
        pub assists: u16,
        pub healed: u16,
        pub saved: u16,
        pub headshots: u16,
        pub hidden_kills: u16,
        pub melee_kills: u16,
        pub items_brought: u16,
        pub items_defended: u16,
        pub artefacts_collected: u16,
        pub max_killstream: u16,
        pub accuracy: u8,
        pub profile_level: u8,
        pub weapon_1_dict_id: u16,
        pub weapon_2_dict_id: u16,
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
            Self::OnlineStats { .. }          => lobby_server_message_types_enum::online_stats           ,
            Self::SquadInfo { .. }            => lobby_server_message_types_enum::squad_info             ,
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
            Self::PriceItems { .. }               => query_info_types_enum::q_price_items               ,
            Self::AccountMoney { .. }             => query_info_types_enum::q_account_money             ,
            Self::PlayerSkills { .. }             => query_info_types_enum::q_player_skills             ,
            // Self::PlayerProfileLeveling
            Self::ServicePrices { .. }            => query_info_types_enum::q_service_prices            ,
            Self::PlayerReputations { .. }        => query_info_types_enum::q_player_reputations        ,
            Self::PlayersTotalCount { .. }        => query_info_types_enum::q_players_total_count       ,
            Self::LastPlayerMatchStats { .. }     => query_info_types_enum::q_last_played_match_stats   ,
            Self::PlayerEloRating { .. }          => query_info_types_enum::q_player_elo_rating         ,
            Self::PlayerEloList { .. }            => query_info_types_enum::q_players_elo_list          ,
            Self::PlayerQuestList { .. }          => query_info_types_enum::q_player_quest_list         , // 14
            Self::PlayerMatchStats { .. }         => query_info_types_enum::q_player_match_stats        ,
            Self::PlayerServices { .. }           => query_info_types_enum::q_player_services           , // 16
            // Self::SquadMemberProfileContents
            Self::ShopItems { .. }                => query_info_types_enum::q_shop_items                ,
            Self::UnlockedFactionsMask { .. }     => query_info_types_enum::q_unlocked_factions_mask    , // 19
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
                packet.write_str(config::match_server::ADDRESS);
                packet.write(config::match_server::PORT);
                packet.write(match_id);
                packet.write(team_id);
            }

            Self::OperationPermitted(action) => {
                action.serialize(packet);
            }

            Self::OperationDenied { operation, reason } => {
                operation.serialize(packet);
                packet.write_str(&reason);
            }

            Self::ClientStatus(client_status) => {
                client_status.serialize(packet);
            }

            Self::PingServerAnswer { ping_value } => {
                packet.write(ping_value);
            }

            Self::OnlineStats {
                players,
                matches,
                maintenance_remain,
            } => {
                packet.write(players);
                packet.write(matches);
                // packet.write(0_u32);
                packet.write(maintenance_remain);
            }
            Self::SquadInfo { .. } => {
                // survarium::lobby_client::read_squad_info
                packet.write(0_u32); // if ( has_squad_maybe ) { }
                packet.write(0_u32); // squad_revision
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
                state,
                last_status_message,
            } => {
                state.serialize(packet);
                if let Some(last_status_message) = last_status_message {
                    packet.write_str(&last_status_message);
                }
            }

            Self::EnumerateProfiles(profiles) => {
                debug_assert!(profiles.len() < 4);

                let profiles_len: u8 = profiles.len().try_into().unwrap();
                packet.write(profiles_len);

                for Profile {
                    profile_id,
                    name,
                    autobuy_items,
                    skill_points_total,
                    current_exp,
                    prev_level_exp,
                    next_level_exp,
                    revision,
                } in profiles
                {
                    packet.write(profile_id);
                    packet.write_str(&name);
                    packet.write(autobuy_items);
                    packet.write(skill_points_total);
                    packet.write(current_exp);
                    packet.write(prev_level_exp);
                    packet.write(next_level_exp);
                    packet.write(revision);
                }
            }

            Self::ProfileContents(player_profile) => {
                player_profile.serialize(packet);
            }

            Self::EnumerateInventory(items) => {
                packet.write_vec::<u32, _, _>(items);
            }

            Self::PriceItems {
                faction_id,
                price_items,
            } => {
                packet.write(faction_id);
                packet.write_vec::<u16, _, _>(price_items);
            }

            Self::AccountMoney {
                generic_money,
                premium_money,
                name,
            } => {
                packet.write(generic_money);
                packet.write(premium_money);
                packet.write_str(&name);
            }

            Self::PlayerSkills {
                profile_id,

                skill_points_total,
                current_exp,
                next_level_exp,
                prev_level_exp,

                player_skills,
            } => {
                packet.write(profile_id);

                packet.write(skill_points_total);

                packet.write(current_exp);
                packet.write(next_level_exp);
                packet.write(prev_level_exp);

                packet.write_slice::<u8, _, _>(&player_skills);

                packet.write(0_u8); // player_perks_len
            }

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

            Self::PlayersTotalCount { player_count } => {
                packet.write(player_count);
            }

            Self::LastPlayerMatchStats { player_match_stats } => {
                player_match_stats.serialize(packet);
            }

            Self::PlayerEloRating {
                place,
                elo,
                last_elo,
            } => {
                packet.write(place);
                packet.write(elo);
                packet.write(last_elo);
            }

            Self::PlayerEloList { player_elo_stats } => {
                // @TODO: Abstract this guy away
                let len: u8 = player_elo_stats.len().try_into().unwrap();
                packet.write(len);

                for player_elo_stats in player_elo_stats {
                    player_elo_stats.serialize(packet);
                }
            }

            Self::PlayerQuestList { player_quest_list } => {
                packet.write_vec::<u32, _, _>(player_quest_list);
            }

            Self::PlayerMatchStats { player_match_stats } => {
                player_match_stats.serialize(packet);
            }

            Self::PlayerServices { loaylties } => {
                // @TODO: Abstract this guy away
                let len: u8 = loaylties.len().try_into().unwrap();
                packet.write(len);

                for loyalty in loaylties {
                    loyalty.serialize(packet);
                }
            }
            Self::ShopItems { shop_items } => {
                // @TODO: Abstract this guy away
                let len: u8 = shop_items.len().try_into().unwrap();
                packet.write(len);

                for shop_item in shop_items {
                    shop_item.serialize(packet);
                }
            }
            Self::UnlockedFactionsMask { mask } => packet.write(mask),
        }
        /*
        Self::PlayerSkillsTree { skills_tree } => packet.append_bytes(skills_tree.as_slice()),
        */
    }
}

impl Serialize for ClientState {
    fn serialize(self, packet: &mut impl Packet) {
        match self {
            Self::SurfLobbyMenu => {
                packet.write(client_state_enum::surf_lobby_menu);
            }
            Self::InMatchMaking {
                match_order_id,
                match_order_place,
                match_orders_total,
                match_order_current_time_sec,
                match_order_avg_wait_sec,
            } => {
                packet.write(client_state_enum::in_match_making);
                packet.write(match_order_id);
                packet.write(match_order_place);
                packet.write(match_orders_total);
                packet.write(match_order_current_time_sec);
                packet.write(match_order_avg_wait_sec);
            }
            Self::InMatch {
                match_order_id,
                match_id,
                team_id,
            } => {
                packet.write(client_state_enum::in_match);
                packet.write(match_order_id);
                packet.write(match_id);
                packet.write(team_id);
            }
            Self::Unknown => {
                packet.write(client_state_enum::unknown);
            }
        }
    }
}

impl Serialize for PlayerEloStats {
    fn serialize(self, packet: &mut impl Packet) {
        let Self {
            place,
            name,
            ranking,
            ranking_diff,
        } = self;

        packet.write_str(&name);
        packet.write(place);
        packet.write(ranking);
        packet.write(ranking_diff);
    }
}

impl Serialize for player_match_stats {
    fn serialize(self, packet: &mut impl Packet) {
        let Self {
            profile_id,
            kills,
            deaths,
            assists,
            healed,
            saved,
            headshots,
            hidden_kills,
            melee_kills,
            items_brought,
            items_defended,
            artefacts_collected,
            max_killstream,
            accuracy,
            profile_level,
            weapon_1_dict_id,
            weapon_2_dict_id,
        } = self;

        packet.write(profile_id);
        packet.write(kills);
        packet.write(deaths);
        packet.write(assists);
        packet.write(healed);
        packet.write(saved);
        packet.write(headshots);
        packet.write(hidden_kills);
        packet.write(melee_kills);
        packet.write(items_brought);
        packet.write(items_defended);
        packet.write(artefacts_collected);
        packet.write(max_killstream);
        packet.write(accuracy);
        packet.write(profile_level);
        packet.write(weapon_1_dict_id);
        packet.write(weapon_2_dict_id);
    }
}

impl Serialize for Loaylty {
    fn serialize(self, packet: &mut impl Packet) {
        match self {
            Self::Premium { premium_hours_left } => {
                packet.write(0_u8); // faction_id: developers :)
                packet.write(0_u8);

                packet.write(premium_hours_left);

                packet.write(0_u32);
            }
            Self::Faction {
                faction_id,
                loaylty_value,
            } => {
                packet.write(faction_id);
                packet.write(0_u8);

                packet.write(0_u32);

                packet.write(loaylty_value);
                packet.write(0_u8);
                packet.write(0_u8);
                packet.write(0_u8);
            }
        }
    }
}

impl Serialize for ShopItemContainer {
    fn serialize(self, packet: &mut impl Packet) {
        let Self {
            id,
            shelf_id,
            cost,
            name,
            descr,
            currency,
            items,
        } = self;

        packet.write(id);
        packet.write(shelf_id);
        packet.write(cost);
        packet.write_str(&name);
        packet.write_str(&descr);

        // @TODO: Abstract this guy away
        let items_count: u8 = items.len().try_into().unwrap();

        packet.write(items_count);
        packet.write(currency);

        for item in items {
            item.serialize(packet);
        }
    }
}

impl Serialize for ShopItem {
    fn serialize(self, packet: &mut impl Packet) {
        let Self {
            id,
            base_cost,
            amount,
            base_amount,
            ttl,
            base_ttl,
            ttl_type,
            item_type,
        } = self;

        packet.write(id);
        packet.write(base_cost);
        packet.write(amount);
        packet.write(base_amount);
        packet.write(ttl);
        packet.write(base_ttl);
        packet.write(ttl_type);
        packet.write(item_type);
    }
}

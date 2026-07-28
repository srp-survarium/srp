use crate::lobby_server::client::raw::faction_id;
use crate::lobby_server::server;
use survarium::player_profile;

pub struct ConnectionState {
    pub session_id: u32,
    pub id: u32,
    pub name: String,

    pub generic_money: u32,
    pub premium_money: u32,
    pub skills_points: u8,

    pub total_experience: u32,
    pub next_level_experience: u32,
    pub prev_level_experience: u32,

    pub player_skills: [server::raw::player_skill; 5],
    pub profile_contents: Vec<player_profile::raw::player_profile>, // 1..4
    pub inventory: Vec<player_profile::raw::inventory_item_instance>, // 0..
    pub reps: [server::raw::player_reputation; 4],
}

impl ConnectionState {
    pub fn new_dummy(session_id: u32) -> Self {
        let account_id = 1;

        Self {
            session_id,
            id: account_id,
            name: "dummy_name".to_string(),
            generic_money: 1_000_000,
            premium_money: 100_000,
            skills_points: 75,
            total_experience: 1800,
            next_level_experience: 3750,
            prev_level_experience: 1000,
            player_skills: [
                server::raw::player_skill {
                    skill_id: 1,
                    skill_points: 0,
                },
                server::raw::player_skill {
                    skill_id: 2,
                    skill_points: 0,
                },
                server::raw::player_skill {
                    skill_id: 3,
                    skill_points: 0,
                },
                server::raw::player_skill {
                    skill_id: 4,
                    skill_points: 0,
                },
                server::raw::player_skill {
                    skill_id: 5,
                    skill_points: 0,
                },
            ],

            profile_contents: vec![
                player_profile::raw::player_profile::new_dummy(
                    account_id,
                    200_000,
                    "server_profile_1",
                ),
                player_profile::raw::player_profile::new_dummy(
                    account_id,
                    400_000,
                    "server_profile_2",
                ),
                player_profile::raw::player_profile::new_dummy(
                    account_id,
                    600_000,
                    "server_profile_3",
                ),
            ],

            inventory: {
                let i = |id, dict_id, condition_or_stack| {
                    player_profile::raw::inventory_item_instance {
                        condition_or_stack,
                        amount_in_inventory: 1,
                        id,
                        dict_id,
                        padding: Default::default(),
                    }
                };
                vec![
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
                    i(20, 12, 10),
                    i(21, 13, 10),
                    i(22, 14, 10),
                    i(23, 15, 10),
                    i(24, 16, 10),
                    i(25, 17, 10),
                    i(26, 18, 10),
                    i(27, 19, 10),
                    // i(28, 20, 1_000),
                    // i(29, 22, 1_000),
                    // i(30, 50, 1_000),
                    // i(31, 51, 1_000),
                    // i(32, 52, 1_000),
                    i(33, 53, 1_000),
                    i(34, 55, 10),
                    i(35, 56, 10),
                    i(36, 64, 10),
                    i(37, 28, 1),
                    i(38, 29, 1),
                    i(39, 31, 1),
                    i(40, 32, 1),
                    i(41, 33, 1),
                    i(42, 34, 1),
                    i(43, 48, 1),
                    i(44, 44, 1),
                    i(45, 45, 1),
                    i(46, 46, 1),
                    i(47, 47, 1),
                    //
                    i(48, 74, 100),    // AKMN
                    i(49, 75, 10_000), // 7.62x39 ammunition
                    i(50, 76, 100),    // SKS
                ]
            },

            reps: [
                server::raw::player_reputation {
                    faction_id: faction_id::scavengers,
                    padding: Default::default(),
                    reputation_points: 100,
                },
                server::raw::player_reputation {
                    faction_id: faction_id::black_market,
                    padding: Default::default(),
                    reputation_points: 200,
                },
                server::raw::player_reputation {
                    faction_id: faction_id::army,
                    padding: Default::default(),
                    reputation_points: 300,
                },
                server::raw::player_reputation {
                    faction_id: faction_id::fringe_settlers,
                    padding: Default::default(),
                    reputation_points: 400,
                },
            ],
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn ported_weapons_are_added_without_replacing_stock_inventory() {
        let state = ConnectionState::new_dummy(0xDD00);
        let dict_ids: std::collections::HashSet<_> =
            state.inventory.iter().map(|item| item.dict_id).collect();

        assert!(dict_ids.contains(&13), "stock AK-74u must remain available");
        assert!(
            dict_ids.contains(&53),
            "stock ammunition must remain available"
        );
        assert!(dict_ids.contains(&74), "AKMN must be available");
        assert!(dict_ids.contains(&76), "SKS must be available");
        assert!(
            dict_ids.contains(&75),
            "7.62x39 ammunition must be available"
        );
        assert_eq!(
            state
                .inventory
                .iter()
                .filter(|item| item.dict_id == 74)
                .count(),
            1
        );
        assert_eq!(
            state
                .inventory
                .iter()
                .filter(|item| item.dict_id == 76)
                .count(),
            1
        );
        assert_eq!(
            state
                .inventory
                .iter()
                .filter(|item| item.dict_id == 75)
                .count(),
            1
        );
    }
}

use crate::lobby_server::server;
use session::Account;
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
    /// Snapshot the shared [`Account`] into per-connection state for the given
    /// session. Mutations the lobby makes stay local to the connection for now;
    /// the canonical account lives in the session store.
    pub fn from_account(session_id: u32, account: &Account) -> Self {
        Self {
            session_id,
            id: account.id,
            name: account.name.clone(),
            generic_money: account.generic_money,
            premium_money: account.premium_money,
            skills_points: account.skills_points,
            total_experience: account.total_experience,
            next_level_experience: account.next_level_experience,
            prev_level_experience: account.prev_level_experience,
            player_skills: account.player_skills,
            profile_contents: account.profile_contents.clone(),
            inventory: account.inventory.clone(),
            reps: account.reps,
        }
    }
}

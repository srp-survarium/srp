// SPDX-License-Identifier: GPL-3.0-or-later
//! In-memory session/account store shared between the mock servers.
//!
//! It is a **mock** (see the repo `CLAUDE.md`): there is no real authentication
//! or persistence. An account is identified by a value derived from the client's
//! IP plus the email it signed in with, so the same client resolves to the same
//! account for the lifetime of the process. Each sign-in gets a fresh
//! `session_id`; the lobby (and later the match server) map that id back to the
//! shared [`Account`].
//!
//! The store lives in one process and is shared as an `Arc<SessionStore>` across
//! the server threads (see PLAN Phase 2). Accounts are handed out as
//! `Arc<Mutex<Account>>` so a mutation in the lobby is visible everywhere that
//! holds the same account.

use std::collections::HashMap;
use std::collections::hash_map::DefaultHasher;
use std::hash::{Hash, Hasher};
use std::net::IpAddr;
use std::sync::atomic::{AtomicU32, Ordering};
use std::sync::{Arc, Mutex};

use survarium::account::{faction_id, player_reputation, player_skill};
use survarium::player_profile;

/// The first `session_id` handed out. Kept at the historic value so the first
/// client in a fresh process gets the same id it always did.
const FIRST_SESSION_ID: u32 = 0x00_00_DD_00;

/// Full per-account state. This is the payload the lobby serves to the client
/// (and that the match server will later read for spawning). Defaults match the
/// values the lobby used to fabricate inline, so behaviour is unchanged.
pub struct Account {
    /// Account id. Doubles as the running id the lobby hands out for newly
    /// bought item instances (preserved from the original mock behaviour).
    pub id: u32,
    pub name: String,

    pub generic_money: u32,
    pub premium_money: u32,
    pub skills_points: u8,

    pub total_experience: u32,
    pub next_level_experience: u32,
    pub prev_level_experience: u32,

    pub player_skills: [player_skill; 5],
    pub profile_contents: Vec<player_profile::raw::player_profile>, // 1..4
    pub inventory: Vec<player_profile::raw::inventory_item_instance>, // 0..
    pub reps: [player_reputation; 4],
}

impl Account {
    /// Build a default account with the historic dummy contents, tagged with the
    /// given id and display name.
    pub fn new_dummy(id: u32, name: String) -> Self {
        Self {
            id,
            name,
            generic_money: 1_000_000,
            premium_money: 100_000,
            skills_points: 75,
            total_experience: 1800,
            next_level_experience: 3750,
            prev_level_experience: 1000,
            player_skills: [
                player_skill { skill_id: 1, skill_points: 0 },
                player_skill { skill_id: 2, skill_points: 0 },
                player_skill { skill_id: 3, skill_points: 0 },
                player_skill { skill_id: 4, skill_points: 0 },
                player_skill { skill_id: 5, skill_points: 0 },
            ],

            profile_contents: vec![
                player_profile::raw::player_profile::new_dummy(id, 200_000, "server_profile_1"),
                player_profile::raw::player_profile::new_dummy(id, 400_000, "server_profile_2"),
                player_profile::raw::player_profile::new_dummy(id, 600_000, "server_profile_3"),
            ],

            inventory: player_profile::demo_inventory(),

            reps: [
                player_reputation {
                    faction_id: faction_id::scavengers,
                    padding: Default::default(),
                    reputation_points: 100,
                },
                player_reputation {
                    faction_id: faction_id::black_market,
                    padding: Default::default(),
                    reputation_points: 200,
                },
                player_reputation {
                    faction_id: faction_id::army,
                    padding: Default::default(),
                    reputation_points: 300,
                },
                player_reputation {
                    faction_id: faction_id::fringe_settlers,
                    padding: Default::default(),
                    reputation_points: 400,
                },
            ],
        }
    }
}

/// Maps sign-ins to shared accounts. Cheap to clone behind an `Arc`.
pub struct SessionStore {
    accounts: Mutex<HashMap<u32, Arc<Mutex<Account>>>>,
    sessions: Mutex<HashMap<u32, u32>>, // session_id -> account_id
    next_session_id: AtomicU32,
    matchmaker: Mutex<Matchmaker>,
    selected_profiles: Mutex<HashMap<u32, player_profile::raw::player_profile>>,
}

impl SessionStore {
    pub fn new() -> Self {
        Self {
            accounts: Mutex::new(HashMap::new()),
            sessions: Mutex::new(HashMap::new()),
            next_session_id: AtomicU32::new(FIRST_SESSION_ID),
            matchmaker: Mutex::new(Matchmaker::new()),
            selected_profiles: Mutex::new(HashMap::new()),
        }
    }

    /// Resolve the account for a client, creating a default one on first sign-in.
    /// The id is derived from `(ip, email)`, so the same client maps to the same
    /// account. An empty email is accepted; the display name then falls back to a
    /// unique value derived from the id.
    pub fn get_or_create_account(&self, ip: IpAddr, email: &str) -> u32 {
        let account_id = account_id_for(ip, email);
        self.accounts
            .lock()
            .unwrap()
            .entry(account_id)
            .or_insert_with(|| {
                let name = if email.is_empty() {
                    format!("player_{account_id:08x}")
                } else {
                    email.to_string()
                };
                Arc::new(Mutex::new(Account::new_dummy(account_id, name)))
            });
        account_id
    }

    /// Allocate a fresh `session_id` bound to `account_id`.
    pub fn create_session(&self, account_id: u32) -> u32 {
        let session_id = self.next_session_id.fetch_add(1, Ordering::Relaxed);
        self.sessions.lock().unwrap().insert(session_id, account_id);
        session_id
    }

    /// The shared account a `session_id` resolves to, if the session is known.
    pub fn account_for_session(&self, session_id: u32) -> Option<Arc<Mutex<Account>>> {
        let account_id = *self.sessions.lock().unwrap().get(&session_id)?;
        self.accounts.lock().unwrap().get(&account_id).cloned()
    }

    /// Place a session into a match, balancing the two teams, and remember the
    /// assignment. Idempotent: a session that re-readies gets the same match and
    /// team. The lobby calls this on `ReadyForMatch`; the match server will read
    /// it back via [`Self::match_assignment`] (Phase 4).
    pub fn join_match(&self, session_id: u32) -> Assignment {
        self.matchmaker.lock().unwrap().join(session_id)
    }

    /// Persist the lobby's current profile edits, remember the profile selected
    /// for this match connection, and assign the session to a match.
    pub fn ready_for_match(
        &self,
        session_id: u32,
        selected_profile: player_profile::raw::player_profile,
        profile_contents: &[player_profile::raw::player_profile],
    ) -> Assignment {
        self.selected_profiles
            .lock()
            .unwrap()
            .insert(session_id, selected_profile);

        if let Some(account) = self.account_for_session(session_id) {
            account.lock().unwrap().profile_contents = profile_contents.to_vec();
        }

        self.join_match(session_id)
    }

    /// The exact lobby profile selected by this session for its current match.
    pub fn selected_profile(&self, session_id: u32) -> Option<player_profile::raw::player_profile> {
        self.selected_profiles
            .lock()
            .unwrap()
            .get(&session_id)
            .copied()
    }

    /// The match/team a session was assigned, if it has readied up.
    pub fn match_assignment(&self, session_id: u32) -> Option<Assignment> {
        self.matchmaker.lock().unwrap().assignment_for(session_id)
    }

    /// Release a departed session's active-player slot. Account and selected
    /// profile data remain available so the same user may immediately rejoin.
    pub fn leave_match(&self, session_id: u32) -> Option<Assignment> {
        self.matchmaker.lock().unwrap().leave(session_id)
    }
}

/// Where a session was placed: which match, and which team (`1` or `2`).
#[derive(Copy, Clone, Debug, PartialEq, Eq)]
pub struct Assignment {
    pub match_id: u32,
    pub team_id: u8,
}

/// First match id handed out. Kept at the historic constant the lobby used to
/// return, so the first/only client's match is unchanged.
const FIRST_MATCH_ID: u32 = 0x123;
/// Hard protocol/client limit: the stock game stores players in
/// `m_net_players[20]`.
pub const MAX_PLAYERS_PER_MATCH: u8 = 20;

/// Minimal mock matchmaker: fills the most populated match with a vacancy,
/// balancing teams. Departures release their assignment so the demo stays
/// drop-in/drop-out instead of accumulating permanent historical occupants.
struct Matchmaker {
    matches: Vec<Match>,
    next_match_id: u32,
    assignments: HashMap<u32, Assignment>, // session_id -> assignment
}

struct Match {
    id: u32,
    team_counts: [u8; 2],
}

impl Match {
    fn player_count(&self) -> u8 {
        self.team_counts[0] + self.team_counts[1]
    }
}

impl Matchmaker {
    fn new() -> Self {
        Self {
            matches: Vec::new(),
            next_match_id: FIRST_MATCH_ID,
            assignments: HashMap::new(),
        }
    }

    fn join(&mut self, session_id: u32) -> Assignment {
        if let Some(assignment) = self.assignments.get(&session_id) {
            return *assignment;
        }

        let match_index = self
            .matches
            .iter()
            .enumerate()
            .filter(|(_, game_match)| game_match.player_count() < MAX_PLAYERS_PER_MATCH)
            .max_by(|(_, lhs), (_, rhs)| {
                lhs.player_count()
                    .cmp(&rhs.player_count())
                    .then_with(|| rhs.id.cmp(&lhs.id))
            })
            .map(|(index, _)| index)
            .unwrap_or_else(|| {
                let index = self.matches.len();
                self.matches.push(Match {
                    id: self.next_match_id,
                    team_counts: [0, 0],
                });
                self.next_match_id += 1;
                index
            });

        let current = &mut self.matches[match_index];
        if current.player_count() >= MAX_PLAYERS_PER_MATCH {
            unreachable!("match selection must return a vacancy");
        }

        // Put the new player on the smaller team (the first player goes to team 1).
        let team = usize::from(current.team_counts[0] > current.team_counts[1]);
        current.team_counts[team] += 1;

        let assignment = Assignment {
            match_id: current.id,
            team_id: team as u8 + 1,
        };
        self.assignments.insert(session_id, assignment);
        assignment
    }

    fn leave(&mut self, session_id: u32) -> Option<Assignment> {
        let assignment = self.assignments.remove(&session_id)?;
        if let Some(game_match) = self
            .matches
            .iter_mut()
            .find(|game_match| game_match.id == assignment.match_id)
        {
            let team = usize::from(assignment.team_id.saturating_sub(1));
            if let Some(team_count) = game_match.team_counts.get_mut(team) {
                *team_count = team_count.saturating_sub(1);
            }
        }
        self.matches
            .retain(|game_match| game_match.player_count() != 0);
        Some(assignment)
    }

    fn assignment_for(&self, session_id: u32) -> Option<Assignment> {
        self.assignments.get(&session_id).copied()
    }
}

/// Derive a stable, non-zero account id from the client IP and email. Not
/// collision-free (it's a hash), which is acceptable for a mock.
fn account_id_for(ip: IpAddr, email: &str) -> u32 {
    let mut hasher = DefaultHasher::new();
    ip.hash(&mut hasher);
    email.hash(&mut hasher);
    (hasher.finish() as u32).max(1)
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::net::Ipv4Addr;

    fn ip(a: u8, b: u8, c: u8, d: u8) -> IpAddr {
        IpAddr::V4(Ipv4Addr::new(a, b, c, d))
    }

    #[test]
    fn same_client_resolves_to_same_account() {
        let store = SessionStore::new();
        let first = store.get_or_create_account(ip(127, 0, 0, 1), "a@b.c");
        let again = store.get_or_create_account(ip(127, 0, 0, 1), "a@b.c");
        assert_eq!(first, again);
    }

    #[test]
    fn different_email_or_ip_gives_different_account() {
        let store = SessionStore::new();
        let a = store.get_or_create_account(ip(127, 0, 0, 1), "a@b.c");
        let b = store.get_or_create_account(ip(127, 0, 0, 1), "other@b.c");
        let c = store.get_or_create_account(ip(10, 0, 0, 1), "a@b.c");
        assert_ne!(a, b);
        assert_ne!(a, c);
    }

    #[test]
    fn empty_email_is_accepted_with_fallback_name() {
        let store = SessionStore::new();
        let id = store.get_or_create_account(ip(127, 0, 0, 1), "");
        let session = store.create_session(id);
        let account = store.account_for_session(session).unwrap();
        assert_eq!(account.lock().unwrap().name, format!("player_{id:08x}"));
    }

    #[test]
    fn sessions_start_at_the_historic_id_and_resolve() {
        let store = SessionStore::new();
        let id = store.get_or_create_account(ip(127, 0, 0, 1), "a@b.c");
        let first_session = store.create_session(id);
        let second_session = store.create_session(id);
        assert_eq!(first_session, FIRST_SESSION_ID);
        assert_eq!(second_session, FIRST_SESSION_ID + 1);

        let account = store.account_for_session(first_session).unwrap();
        assert_eq!(account.lock().unwrap().id, id);
        assert!(store.account_for_session(0xFFFF_FFFF).is_none());
    }

    #[test]
    fn first_match_keeps_the_historic_match_and_team() {
        let store = SessionStore::new();
        let assignment = store.join_match(1);
        assert_eq!(assignment.match_id, FIRST_MATCH_ID);
        assert_eq!(assignment.team_id, 1);
    }

    #[test]
    fn two_sessions_share_a_match_on_opposite_teams() {
        let store = SessionStore::new();
        let a = store.join_match(1);
        let b = store.join_match(2);
        assert_eq!(a.match_id, b.match_id);
        assert_eq!(a.team_id, 1);
        assert_eq!(b.team_id, 2);
    }

    #[test]
    fn join_match_is_idempotent_per_session() {
        let store = SessionStore::new();
        let first = store.join_match(7);
        let again = store.join_match(7);
        assert_eq!(first, again);
        assert_eq!(store.match_assignment(7), Some(first));
        assert_eq!(store.match_assignment(999), None);
    }

    #[test]
    fn leaving_a_full_match_opens_its_slot_to_the_next_session() {
        let store = SessionStore::new();
        let first_match: Vec<_> = (0..u32::from(MAX_PLAYERS_PER_MATCH))
            .map(|session_id| store.join_match(session_id))
            .collect();
        assert!(
            first_match
                .iter()
                .all(|assignment| assignment.match_id == FIRST_MATCH_ID)
        );

        let overflow = store.join_match(100);
        assert_ne!(overflow.match_id, FIRST_MATCH_ID);
        assert_eq!(store.leave_match(7), Some(first_match[7]));
        assert_eq!(store.match_assignment(7), None);

        let replacement = store.join_match(101);
        assert_eq!(replacement.match_id, FIRST_MATCH_ID);
    }

    #[test]
    fn ready_for_match_preserves_the_selected_edited_profile() {
        let store = SessionStore::new();
        let id = store.get_or_create_account(ip(127, 0, 0, 1), "loadout@test");
        let session_id = store.create_session(id);
        let account = store.account_for_session(session_id).unwrap();
        let mut profiles = account.lock().unwrap().profile_contents.clone();
        profiles[1].slots[player_profile::raw::profile_slot_enum::weapon1_slot].dict_id = 55;

        store.ready_for_match(session_id, profiles[1], &profiles);

        assert_eq!(
            store.selected_profile(session_id).unwrap().profile_id,
            profiles[1].profile_id
        );
        assert_eq!(
            store.selected_profile(session_id).unwrap().slots
                [player_profile::raw::profile_slot_enum::weapon1_slot]
                .dict_id,
            55
        );
        assert_eq!(account.lock().unwrap().profile_contents, profiles);
    }
}

// SPDX-License-Identifier: GPL-3.0-or-later
// Canned game content for the relay.
//
// SRP is a mock (see the repo CLAUDE.md): the match server does NOT simulate the
// game. It relays player updates between clients and, for the bits the client
// needs to start, hands out fixed/dummy content. These helpers build that
// content; the relay wiring lives in `match_server.rs`.

use survarium::player_input::{
    player, player_inventory_slot, player_stamina, weapon_core, weapon_core_state, weapon_targets,
};
use survarium::player_profile;
use survarium::player_profile::raw::{game_team_id, profile_slot_enum};
use vostok::math::float3;

use crate::message::ServerGameMessageKind;
use crate::message::server_message::raw::game_mode_type;

/// `MatchOptions` describing the (mock) match. `player_count` reflects the live
/// roster so the client knows how many `PlayerProfile`s to expect.
pub fn match_options(player_count: u8) -> ServerGameMessageKind {
    ServerGameMessageKind::MatchOptions {
        map_id: 0,
        map_name: "level_03_evn".to_string(),
        match_mode: game_mode_type::gather_victory_items,
        player_count,
        victory_item_count: 10, // batteries
        respawn_time: 10,
        match_time: 15 * 60,
    }
}

/// A dummy profile for `player_id`, tagged with its team and whether it is the
/// recipient's own (local) player.
pub fn player_profile(
    player_id: u8,
    team: game_team_id,
    name: &str,
    is_local: bool,
) -> player_profile::raw::player_profile {
    let name = wire_profile_name(name, player_id);
    player_profile::raw::player_profile {
        team,
        is_local,
        ..player_profile::raw::player_profile::new_dummy(player_id as u32, 0, &name)
    }
}

/// The stock profile payload requires 4–29 bytes and cannot carry an embedded
/// NUL. Login identity is intentionally permissive, so make a safe display name
/// at this wire boundary instead of letting a user-provided email panic the
/// entire match thread.
fn wire_profile_name(name: &str, player_id: u8) -> String {
    let mut end = name.len().min(29);
    while !name.is_char_boundary(end) {
        end -= 1;
    }
    let name = &name[..end];
    if name.len() > 3 && !name.contains('\0') {
        name.to_owned()
    } else {
        format!("player_{player_id}")
    }
}

/// Demo spawn table. Add the remaining map coordinates here when they are
/// available; the match server randomly assigns these points to joining peers.
const SPAWN_POSITIONS: [float3; 2] = [
    float3 {
        x: -7.76438,
        y: 13.95794,
        z: -31.85271,
    },
    float3 {
        x: -9.33856,
        y: 47.47741,
        z: -25.15140,
    },
];

pub fn spawn_position_count() -> usize {
    SPAWN_POSITIONS.len()
}

/// Canned `player` payload for a `SpawnPlayer`, placed at a selected spawn point.
/// All players get the same dummy loadout.
pub fn spawn_content(spawn_index: usize) -> player {
    player {
        position: SPAWN_POSITIONS[spawn_index % SPAWN_POSITIONS.len()],
        orientation: 10.,
        look_pitch: 0.2,
        is_alive: true,
        server_current_active_slot: profile_slot_enum::weapon1_slot,
        server_target_active_slot: profile_slot_enum::weapon1_slot,
        player_stamina: player_stamina {
            value: 100.,
            last_spending_time_in_ms: 10,
            last_tick_time_in_ms: 10,
            lower_threshold_was_reached: false,
        },
        player_inventory: vec![
            player_inventory_slot::weapon_slot(weapon_core {
                inventory_item: 1,
                random_seed: 0,
                normal_random_seed: 1,
                weapon_target: weapon_targets::idle,
                old_actions_mask: 0,
                ammo_in_magazine: 30,
                bullets_in_queue: 30,
                fire_queue_type: 0,
                ammo_slot: profile_slot_enum::weapon1_slot,
                is_there_chamber_a_round_state: None,
                weapon_core_state: Some(weapon_core_state {
                    is_shown: true,
                    active_hands: 1,
                    start_transition_time_in_ms_lhs: 10,
                    start_transition_time_in_ms_rhs: 10,
                    weapon_sound_target_state: (3, None),
                    logic_sprint_target_state: (0, None),
                }),
            }),
            player_inventory_slot::item_amount(300),
        ],
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::ffi::CStr;

    fn profile_name(name: &str) -> String {
        let profile = player_profile(7, game_team_id::team_1, name, true);
        CStr::from_bytes_until_nul(&profile.profile_name)
            .unwrap()
            .to_string_lossy()
            .into_owned()
    }

    #[test]
    fn sanitizes_profile_names_for_the_stock_wire_format() {
        assert_eq!(profile_name("abc"), "player_7");
        assert_eq!(
            profile_name("abcdefghijklmnopqrstuvwxyz0123456789"),
            "abcdefghijklmnopqrstuvwxyz012"
        );
        assert_eq!(profile_name("valid@example.com"), "valid@example.com");
        assert_eq!(profile_name("bad\0name"), "player_7");
    }
}

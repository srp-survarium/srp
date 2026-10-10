// SPDX-License-Identifier: GPL-3.0-or-later
// Canned game content for the relay.
//
// SRP is a mock (see the repo CLAUDE.md): the match server does NOT simulate the
// full game. It relays player updates between clients and translates each
// lobby-selected profile into the runtime state the client needs to spawn.

use survarium::player_input::{
    player, player_inventory_slot, player_stamina, weapon_core, weapon_core_state, weapon_targets,
};
use survarium::player_profile::raw::{
    game_team_id, inventory_item_instance, player_profile as raw_player_profile, profile_slot_enum,
};
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
        // Required match metadata only. The demo never sends the status/time
        // messages that activate or advance the stock client's match timer.
        match_time: 15 * 60,
    }
}

/// Adapt the exact lobby-selected loadout for one recipient's match roster.
pub fn player_profile(
    mut profile: raw_player_profile,
    player_id: u8,
    team: game_team_id,
    name: &str,
    is_local: bool,
) -> raw_player_profile {
    let name = wire_profile_name(name, player_id);
    profile.account_id = u32::from(player_id);
    profile.team = team;
    profile.is_local = is_local;
    profile.profile_name = [0; 32];
    profile.profile_name[..name.len()].copy_from_slice(name.as_bytes());
    profile
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

pub fn active_weapon_slot(profile: &raw_player_profile) -> Option<profile_slot_enum> {
    [
        profile_slot_enum::weapon1_slot,
        profile_slot_enum::weapon2_slot,
    ]
    .into_iter()
    .find(|slot| profile.slots[*slot].id != 0)
}

pub fn active_weapon_dict_id(profile: &raw_player_profile) -> Option<u16> {
    active_weapon_slot(profile).map(|slot| profile.slots[slot].dict_id)
}

fn ammo_slots_for_weapon(weapon_slot: profile_slot_enum) -> [profile_slot_enum; 2] {
    match weapon_slot {
        profile_slot_enum::weapon1_slot => [
            profile_slot_enum::ammo1_weapon1_slot,
            profile_slot_enum::ammo2_weapon1_slot,
        ],
        profile_slot_enum::weapon2_slot => [
            profile_slot_enum::ammo1_weapon2_slot,
            profile_slot_enum::ammo2_weapon2_slot,
        ],
        _ => unreachable!("not a weapon slot"),
    }
}

fn magazine_capacity(dict_id: u16) -> u16 {
    // Minimal 0.100b demo configuration. The final engine-backed server should
    // replace this table with values loaded from the reconstructed item configs.
    match dict_id {
        12 => 10,     // TOZ-122
        13 => 30,     // AK-74u
        14 => 5,      // Remington 700
        15 => 8,      // Remington 870
        16 | 17 => 2, // TOZ-34 / TOZ-66
        18 => 8,      // TT-33
        19 => 30,     // Vityaz
        55 => 32,     // Uzi
        56 => 6,      // Magnum
        64 => 12,     // Fort-17
        _ => 1,
    }
}

fn has_chamber_state(dict_id: u16) -> bool {
    matches!(dict_id, 12 | 14 | 15)
}

fn runtime_amount(item: inventory_item_instance) -> u16 {
    item.condition_or_stack
        .min(item.amount_in_inventory)
        .min(u32::from(u16::MAX)) as u16
}

fn runtime_weapon(
    weapon_slot: profile_slot_enum,
    item: inventory_item_instance,
    profile: &raw_player_profile,
    active_slot: profile_slot_enum,
) -> weapon_core {
    let ammo_slots = ammo_slots_for_weapon(weapon_slot);
    let ammo_slot = ammo_slots
        .into_iter()
        .find(|slot| profile.slots[*slot].id != 0)
        .unwrap_or(profile_slot_enum::max_slots_count);
    let is_active = weapon_slot == active_slot;

    weapon_core {
        // `inventory_item::serialize`: current weapon condition.
        inventory_item: item.condition_or_stack.min(u32::from(u16::MAX)) as u16,
        random_seed: 0,
        normal_random_seed: 1,
        weapon_target: if is_active {
            weapon_targets::idle
        } else {
            weapon_targets::inactive
        },
        old_actions_mask: 0,
        ammo_in_magazine: magazine_capacity(item.dict_id),
        bullets_in_queue: 0,
        fire_queue_type: 0,
        ammo_slot,
        is_there_chamber_a_round_state: has_chamber_state(item.dict_id).then_some(true),
        weapon_core_state: Some(weapon_core_state {
            is_shown: is_active,
            active_hands: u8::from(is_active),
            start_transition_time_in_ms_lhs: 10,
            start_transition_time_in_ms_rhs: 10,
            // All weapon FSMs put inactive at 0 and idle at 3.
            weapon_sound_target_state: (if is_active { 3 } else { 0 }, None),
            logic_sprint_target_state: (0, None),
        }),
    }
}

/// Runtime state matching the lobby-selected profile, at the chosen spawn.
pub fn spawn_content(spawn_index: usize, profile: &raw_player_profile) -> player {
    let active_slot = active_weapon_slot(profile).unwrap_or(profile_slot_enum::weapon1_slot);
    let mut player_inventory = Vec::new();
    for slot_index in
        profile_slot_enum::weapon1_slot as usize..profile_slot_enum::max_slots_count as usize
    {
        let slot = bytemuck::checked::cast::<u8, profile_slot_enum>(slot_index as u8);
        let item = profile.slots[slot];
        if item.id == 0 {
            continue;
        }
        if matches!(
            slot,
            profile_slot_enum::weapon1_slot | profile_slot_enum::weapon2_slot
        ) {
            player_inventory.push(player_inventory_slot::weapon_slot(runtime_weapon(
                slot,
                item,
                profile,
                active_slot,
            )));
        } else {
            player_inventory.push(player_inventory_slot::item_amount(runtime_amount(item)));
        }
    }

    player {
        position: SPAWN_POSITIONS[spawn_index % SPAWN_POSITIONS.len()],
        orientation: 10.,
        look_pitch: 0.2,
        is_alive: true,
        server_current_active_slot: active_slot,
        server_target_active_slot: active_slot,
        player_stamina: player_stamina {
            value: 100.,
            last_spending_time_in_ms: 10,
            last_tick_time_in_ms: 10,
            lower_threshold_was_reached: false,
        },
        player_inventory,
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::ffi::CStr;

    fn profile_name(name: &str) -> String {
        let selected = raw_player_profile::new_dummy(1, 10, "selected");
        let profile = player_profile(selected, 7, game_team_id::team_1, name, true);
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

    #[test]
    fn spawn_loadout_serializes_every_selected_runtime_item() {
        let profile = raw_player_profile::new_dummy(1, 10, "selected");
        let player = spawn_content(0, &profile);
        assert_eq!(player.player_inventory.len(), 10);

        let player_inventory_slot::weapon_slot(weapon) = player.player_inventory[0] else {
            panic!("weapon state must precede its ammo slot states");
        };
        assert_eq!(weapon.inventory_item, 100);
        assert_eq!(weapon.ammo_in_magazine, 30);
        assert_eq!(weapon.bullets_in_queue, 0);
        assert_eq!(weapon.ammo_slot, profile_slot_enum::ammo1_weapon1_slot);
        assert_eq!(
            player.player_inventory[1],
            player_inventory_slot::item_amount(10_000)
        );
        assert_eq!(
            player.player_inventory[2],
            player_inventory_slot::item_amount(10_000)
        );

        let player_inventory_slot::weapon_slot(second_weapon) = player.player_inventory[3] else {
            panic!("second selected weapon must have runtime state");
        };
        assert_eq!(second_weapon.ammo_in_magazine, 5);
        assert_eq!(
            second_weapon.ammo_slot,
            profile_slot_enum::ammo1_weapon2_slot
        );
        assert_eq!(second_weapon.is_there_chamber_a_round_state, Some(true));
        assert_eq!(
            player.player_inventory[4],
            player_inventory_slot::item_amount(10_000)
        );
        assert_eq!(
            player.player_inventory[5],
            player_inventory_slot::item_amount(10_000)
        );
    }

    #[test]
    fn match_profile_preserves_selected_slots() {
        let mut selected = raw_player_profile::new_dummy(1, 10, "selected");
        selected.slots[profile_slot_enum::weapon1_slot].dict_id = 55;
        let adapted = player_profile(selected, 1, game_team_id::team_2, "player", true);

        assert_eq!(adapted.slots, selected.slots);
        assert_eq!(adapted.team, game_team_id::team_2);
        assert!(adapted.is_local);
    }
}

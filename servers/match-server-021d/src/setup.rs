// SPDX-License-Identifier: GPL-3.0-or-later
//! Fixed stock-map setup for the first real-client bootstrap test.
//! Layout: retail VAs 0x1f59a4, 0x1f5c52, 0x1f5b53, 0x1a2ddc.
//! The weapon/ammo dictionary IDs and options are known usable in the captured
//! 0.21d client. Names, instance IDs, roster and match ID are created here.

pub const MATCH_SECONDS: u16 = 600;
pub const COUNTDOWN_SECONDS: u8 = 10;
pub const VICTORY_ITEMS: u8 = 5;
pub const SCORES: [f32; 24] = [
    100., 50., 0., 0., 0., 20., 100., 25., 25., 25., 50., 0., 0., 25., 25., 25., 0., 100., 100.,
    25., 50., 25., 0., 0.,
];

pub fn local_test(players: u8, local_slot: u8) -> Result<Vec<u8>, &'static str> {
    local_test_with_duration(players, local_slot, MATCH_SECONDS)
}

pub fn local_test_with_duration(
    players: u8,
    local_slot: u8,
    seconds: u16,
) -> Result<Vec<u8>, &'static str> {
    if seconds == 0 {
        return Err("match duration must be positive");
    }
    if players == 0 || players > 20 || local_slot >= players {
        return Err("invalid test roster");
    }
    let mut b = Vec::new();
    b.push(21); // level_02/rain, recorded stock map
    string(&mut b, "level_02/rain");
    b.extend([2, players, VICTORY_ITEMS, 10]); // mode, roster, victory items, respawn seconds
    b.extend(seconds.to_le_bytes());
    b.extend(1u32.to_le_bytes()); // new local match ID
    b.extend(0f32.to_le_bytes());
    b.extend([5, 0, COUNTDOWN_SECONDS]); // wait1, wait2, countdown
    b.extend(0u16.to_le_bytes());
    for score in SCORES {
        b.extend(score.to_le_bytes());
    }
    b.extend(std::iter::repeat_n(0, usize::from(players)));
    for slot in 0..players {
        b.extend([slot % 2, u8::from(slot == local_slot)]);
        string(&mut b, &format!("Local {}", slot + 1));
        b.extend(10u32.to_le_bytes());
        b.extend(((1u32 << 7) | (1 << 8)).to_le_bytes());
        // Weapon slot 7: dict 106, fresh instance, condition, no modifications.
        b.extend(106u16.to_le_bytes());
        b.extend((1000u32 + u32::from(slot) * 2).to_le_bytes());
        b.extend(100u16.to_le_bytes());
        b.push(0);
        // Ammo slot 8 additionally serializes amount_in_inventory.
        b.extend(50u16.to_le_bytes());
        b.extend((1001u32 + u32::from(slot) * 2).to_le_bytes());
        b.extend(200u16.to_le_bytes());
        b.extend(550u32.to_le_bytes());
        b.push(0);
        b.extend(0u32.to_le_bytes()); // no profile modifiers
    }
    b.push(local_slot);
    Ok(b)
}
fn string(b: &mut Vec<u8>, s: &str) {
    b.push(s.len() as u8);
    b.extend(s.as_bytes());
}

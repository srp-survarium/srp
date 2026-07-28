//! Per-account progression wire types shared between the lobby (which serves
//! them to the client) and the in-memory session store (which owns them).
//!
//! These were originally defined inside the lobby-server crate; they live here
//! so the shared `session` crate can describe a full `Account` without depending
//! on a server binary. The lobby re-exports them from its `raw` modules, so its
//! existing `faction_id::…` / `player_skill { … }` call sites are unchanged.

#[repr(u8)]
#[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
pub enum faction_id {
    scavengers = 0x1,
    black_market = 0x2,
    army = 0x3,
    fringe_settlers = 0x4,
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

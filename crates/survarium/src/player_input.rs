#![allow(non_camel_case_types)]

use vostok::math::{float2, float3};

use crate::player_profile::raw::profile_slot_enum;

#[repr(C)]
#[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
pub struct player_input {
    pub angular_velocity: float2,
    pub angualr_acceleration: float2,
    pub action_mask: u32,
}

#[repr(C)]
#[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
pub struct player_state {
    pub translation_w: float3,
    pub euler_angle_y: f32,
    pub look_pitch: f32,
}

#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq)]
pub struct player {
    pub position: float3,
    pub orientation: f32,
    pub look_pitch: f32,
    pub is_alive: bool,
    pub slot_id: profile_slot_enum,
    pub server_target_active_slot: profile_slot_enum,
    pub player_stamina: player_stamina,
    pub player_inventory: [weapon_core;
        profile_slot_enum::quick_slot6 as usize - profile_slot_enum::boots_slot as usize],
}

#[repr(C)]
#[derive(bytemuck::CheckedBitPattern, Copy, Clone, Debug, PartialEq)]
pub struct player_stamina {
    pub value: f32,
    pub last_spending_time_in_ms: u32,
    pub last_tick_time_in_ms: u32,
    pub lower_threshold_was_reached: bool,
}

//
//
//

#[repr(C)]
#[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
pub struct weapon_state {
    pub slot_id: u8,
    pub ammo_slot_id: u8,
    pub state: u8,
}

#[derive(Copy, Clone, Debug, PartialEq)]
pub struct weapon_core {
    pub inventory_item: u16,
    pub v2: u32,
    pub normal_random_seed: u32,
    pub weapon_target: weapon_targets,
    pub old_actions_mask: u32,
    pub ammo_in_magazine: u16,
    pub bullets_in_queue: u16,
    pub fire_queue_type: u8,
    pub ammo_slot: profile_slot_enum,
    pub is_there_chamber_a_round_state: Option<bool>,
    pub weapon_core_state: Option<weapon_core_state>,
}

#[derive(Copy, Clone, Debug, PartialEq)]
pub struct weapon_core_state {
    is_shown: bool,
    active_hands: u8,
    start_transition_time_in_ms_lhs: u32,
    start_transition_time_in_ms_rhs: u32,
    target_state_id: u8,
}

#[repr(u8)]
#[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
#[rustfmt::skip]
pub enum weapon_targets {
    idle     = 0x0,
    fire     = 0x1,
    aim      = 0x2,
    aim_fire = 0x3,
    reload   = 0x4,
    inactive = 0x5,
    count    = 0x6,
}

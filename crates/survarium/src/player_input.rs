#![allow(non_camel_case_types)]
// SPDX-License-Identifier: GPL-3.0-or-later

use vostok::math::{float2, float3};

use crate::player_profile::raw::profile_slot_enum;

#[repr(C)]
#[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
#[rustfmt::skip]
pub struct player_input {
    pub angular_velocity: float2,
    pub angualr_acceleration: float2,
    pub action_mask: u32,
}

#[repr(C)]
#[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
#[rustfmt::skip]
pub struct player_state {
    pub translation_w: float3,
    pub euler_angle_y: f32,
    pub look_pitch: f32,
}

#[repr(C)]
#[derive(bytemuck::CheckedBitPattern, Copy, Clone, Debug, PartialEq)]
#[rustfmt::skip]
pub struct player {
    pub position: float3,
    pub orientation: f32,
    pub look_pitch: f32,
    pub is_alive: bool,
    pub slot_id: profile_slot_enum,
    pub server_target_active_slot: profile_slot_enum,
}

//
//
//

#[repr(C)]
#[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
#[rustfmt::skip]
pub struct weapon_state {
    pub slot_id: u8,
    pub ammo_slot_id: u8,
    pub state: u8,
}

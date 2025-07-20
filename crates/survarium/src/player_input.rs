#![allow(non_camel_case_types)]

use vostok::math::{float2, float3};

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

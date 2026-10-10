#![allow(non_camel_case_types)]
// SPDX-License-Identifier: GPL-3.0-or-later

#[repr(C)]
#[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
#[rustfmt::skip]
pub struct float2 {
    pub x: f32,
    pub y: f32,
}

#[repr(C)]
#[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
#[rustfmt::skip]
pub struct float3 {
    pub x: f32,
    pub y: f32,
    pub z: f32,
}

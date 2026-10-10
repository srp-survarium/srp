// SPDX-License-Identifier: GPL-3.0-or-later
use crate::{BinaryConfig, BinaryType, BinaryValue, IdCrc};

use encoding_rs::WINDOWS_1251;
use num_traits::FromPrimitive;
use std::ffi::CStr;

impl BinaryConfig {
    pub fn parse_n_print(&self) {
        let buffer = &self.0;
        let value = BinaryValue::parse(buffer);
        value.print_rec(self, 0, None);
    }
}

impl BinaryValue {
    pub fn parse(buffer: &[u8]) -> Self {
        assert!(buffer.len() >= Self::SIZE);

        let buffer: [u8; Self::SIZE] = buffer[0..Self::SIZE].try_into().unwrap();
        let (data, id, id_crc, type_, count) = arrayref::array_refs![&buffer, 8, 8, 4, 2, 2];

        let data = u64::from_le_bytes(*data);
        let id = u64::from_le_bytes(*id);
        let id_crc = u32::from_le_bytes(*id_crc);
        let type_ = u16::from_le_bytes(*type_);
        let count = u16::from_le_bytes(*count);

        let id_crc = IdCrc(id_crc);
        let type_ = BinaryType::from_u16(type_).unwrap();

        Self {
            data,
            id,
            id_crc,
            type_,
            count,
        }
    }

    fn print_rec(&self, tree: &BinaryConfig, depth: usize, index: Option<usize>) {
        let prefix = match index {
            Some(index) => {
                let tab = tab(depth);

                format!("{tab}{index}")
            }
            None => {
                let tab = tab(depth);

                let id = &tree.0[self.id as usize..];
                let id_crc = CStr::from_bytes_until_nul(id).unwrap().to_str().unwrap();

                format!("{tab}{id_crc}")
            }
        };

        match self.type_ {
            BinaryType::TableNamed | BinaryType::TableIndexed => {
                let offset = self.data as usize;
                let len = self.count as usize;

                println!("{prefix}[{len}]");

                let buffer = &tree.0;
                for i in 0..len {
                    let this = Self::parse(&buffer[offset + i * Self::SIZE..]);

                    let index = match self.type_ {
                        BinaryType::TableNamed => None,
                        BinaryType::TableIndexed => Some(i),
                        _ => unreachable!(),
                    };

                    Self::print_rec(&this, tree, depth + 1, index);
                }
            }

            BinaryType::Boolean => {
                let value = self.data != 0;
                println!("{prefix}: {value}");
            }
            BinaryType::Integer => {
                let value = self.data as i32;
                println!("{prefix}: {value}");
            }
            BinaryType::Float => {
                let value = f32::from_bits(self.data as u32);
                println!("{prefix}: {value}");
            }
            BinaryType::String => {
                let offset = self.data as usize;
                let len = self.count as usize;
                let buffer = &tree.0[offset..offset + len - 1]; // '\0'

                let (value, _, had_errors) = WINDOWS_1251.decode(buffer);
                assert!(!had_errors);

                println!("{prefix}: \"{value}\"");
            }
            BinaryType::Float2 => {
                let offset = self.data as usize;
                let buffer = tree.0[offset..offset + 4 * 2].try_into().unwrap();

                let (float_x, float_y) = arrayref::array_refs![&buffer, 4, 4];
                let float_x = f32::from_le_bytes(*float_x);
                let float_y = f32::from_le_bytes(*float_y);
                println!("{prefix}: {float_x}|{float_y}");
            }
            BinaryType::Float3 => {
                let offset = self.data as usize;
                let buffer = tree.0[offset..offset + 4 * 3].try_into().unwrap();

                let (float_x, float_y, float_z) = arrayref::array_refs![&buffer, 4, 4, 4];
                let float_x = f32::from_le_bytes(*float_x);
                let float_y = f32::from_le_bytes(*float_y);
                let float_z = f32::from_le_bytes(*float_z);
                println!("{prefix}: {float_x}|{float_y}|{float_z}");
            }
            BinaryType::Float4 => {
                let offset = self.data as usize;
                let buffer = tree.0[offset..offset + 4 * 4].try_into().unwrap();

                let (float_x, float_y, float_z, float_w) =
                    arrayref::array_refs![&buffer, 4, 4, 4, 4];
                let float_x = f32::from_le_bytes(*float_x);
                let float_y = f32::from_le_bytes(*float_y);
                let float_z = f32::from_le_bytes(*float_z);
                let float_w = f32::from_le_bytes(*float_w);
                println!("{prefix}: {float_x}|{float_y}|{float_z}|{float_w}");
            }
        }
    }
}

fn tab(depth: usize) -> String {
    (0..depth).map(|_| "  ").collect()
}

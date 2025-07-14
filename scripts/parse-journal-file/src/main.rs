#![allow(unused_assignments)]
#![allow(unused_variables)]
#![allow(dead_code)]
#![allow(non_camel_case_types)]

enum data_chunk_type_enum {
    invalid_type = 0x0,
    logic_tick = 0x1,
    logic_wait = 0x2,
    input_keyboard_action = 0x3,
    input_gamepad_action = 0x4,
    input_mouse_action = 0x5,
    network_packet = 0x6,
    version_chunk = 0x7,
    mouse_sensitivity_chunk = 0x8,
    data_chunk_types_count = 0x9,
}

impl data_chunk_type_enum {
    fn to_string(byte: u8) -> String {
        match byte {
            0x0 => "invalid_type         ".to_string(),
            0x1 => "logic_tick           ".to_string(),
            0x2 => "logic_wait           ".to_string(),
            0x3 => "input_keyboard_action".to_string(),
            0x4 => "input_gamepad_action ".to_string(),
            0x5 => "input_mouse_action   ".to_string(),
            0x6 => "network_packet       ".to_string(),
            0x7 => "version_chunk        ".to_string(),
            0x8 => "mouse_sensitivity_chunk".to_string(),
            0x9 => "data_chunk_types_count ".to_string(),
            _ => byte.to_string(),
        }
    }
}

// vostok::fs_new::device_file_system_interface
// unsigned __int64 (__thiscall *write)(vostok::fs_new::device_file_system_interface *this, void *, const void *, unsigned __int64);

// unsigned __int64 __thiscall vostok::fs_new::windows_hdd_file_system::write(
//        vostok::fs_new::windows_hdd_file_system *this, // not used
//        void *handle,                                  // used
//        const void *data,                              // used
//        unsigned __int64 size)                         // used
// {
//  unsigned int bytes_written; // [esp+0h] [ebp-4h] BYREF

//  bytes_written = 0;
//  WriteFile(handle, data, size, &bytes_written, 0);
//  return bytes_written;
// }

const JOURNAL_FILE: &[u8] = include_bytes!("../Survarium-#763_140222-075828.journal");

fn main() {
    let mut i = 0;
    let bytes = JOURNAL_FILE;

    // let x = bytes[i];
    // i += 1;
    // println!("{x}");

    // let x = u32::from_le_bytes(bytes[i..i + 4].try_into().unwrap());
    // i += 4;
    // println!("{x}");

    while i != JOURNAL_FILE.len() {
        let kind = bytes[i];
        i += 1;

        match kind {
            0x5 => {
                let zero = bytes[i];
                i += 1;

                let x = u32::from_le_bytes(bytes[i..i + 4].try_into().unwrap());
                i += 4;
                let y = u32::from_le_bytes(bytes[i..i + 4].try_into().unwrap());
                i += 4;
                let z = u32::from_le_bytes(bytes[i..i + 4].try_into().unwrap());
                i += 4;
            }
            _ => {
                let kind = data_chunk_type_enum::to_string(kind);

                let len = bytes[i] as usize;
                i += 1;

                let msg = &bytes[i..i + len];
                println!("{kind}: {len}: {msg:02X?}");
                i += len;
            }
        }
    }
}

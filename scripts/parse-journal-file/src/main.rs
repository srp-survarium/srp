#![expect(dead_code)]
#![expect(non_camel_case_types)]

#[repr(u8)]
#[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
#[rustfmt::skip]
pub enum match_server_message_types_enum {
    match_server_connection_successful = 0x50,
    static_match_info                  = 0x51,
    set_time_request                   = 0x52,
    dynamic_match_info                 = 0x53,
    player_input_change                = 0x54,
    floating_timer_set_offset          = 0x55,
    player_entered_match               = 0x56,
    player_left_match                  = 0x57,
    local_player_input_discard         = 0x58,
    on_hash_mismatch                   = 0x59,
}
// server_player_input                = 82, // [+]
// kill_player                        = 83, // [+]
// spawn_player                       = 84, // [+]
// team_base_capture_progress         = 85, // [+]
// match_time_changed                 = 86, // [+]
// respawn_time_changed               = 87, // [+]
// player_kd_stats_changed            = 88, // [+]
// hit_player                         = 89, // [+]
// affect_damage_model                , // [+]
// sync_response                      , // [+]
// match_finished                     , // [+]
// server_bullet_added                , // ??
// server_bullet_removed              , // ??
// server_bullet_moved                , // ??
// server_bullet_collided             , // ??
// player_visibility_changed          , // [+] hidden
// player_profile_message_type        ,
// team_bases_message_type            ,
// initialize_victory_items           ,
// victory_item_take_or_put           ,
// trap_placed                        ,
// trap_removed                       ,
// trap_fired                         ,
// trap_disarmed                      ,
// game_status_changed                ,
// match_wait_time_changed            ,
// game_world_object_state            ,
// world_synchronization_request      ,
// damage_model_state                 , // [+] hidden
// match_server_invalid_message_type  ,
// }

#[repr(u8)]
#[derive(bytemuck::CheckedBitPattern, bytemuck::NoUninit, Copy, Clone, Debug, PartialEq)]
#[rustfmt::skip]
enum data_chunk_type_enum {
    invalid_type            = 0x0,
    logic_tick              = 0x1,
    logic_wait              = 0x2,
    input_keyboard_action   = 0x3,
    input_gamepad_action    = 0x4,
    input_mouse_action      = 0x5,
    network_packet          = 0x6,
    version_chunk           = 0x7,
    mouse_sensitivity_chunk = 0x8,
    data_chunk_types_count  = 0x9,
}

const JOURNAL_FILE: &[u8] = include_bytes!("../Survarium-#763_140222-075828.journal");

fn main() {
    let mut i = 0;
    let bytes = JOURNAL_FILE;

    while i != JOURNAL_FILE.len() {
        let kind =
            bytemuck::checked::try_pod_read_unaligned::<data_chunk_type_enum>(&bytes[i..i + 1])
                .unwrap();
        i += 1;

        match kind {
            /* logic_tick */
            data_chunk_type_enum::logic_tick => {
                // survarium::game::tick
                let current_time_in_ms = u32::from_le_bytes(bytes[i..i + 4].try_into().unwrap());
                i += 4;

                println!("{:?}: {}", kind, current_time_in_ms);
            }
            /* logic_wait */
            data_chunk_type_enum::logic_wait => {
                // survarium::game::on_waiting_for_render
                let current_time_in_ms = u32::from_le_bytes(bytes[i..i + 4].try_into().unwrap());
                i += 4;

                println!("{:?}: {}", kind, current_time_in_ms);
            }

            /* input_keyboard_action */
            data_chunk_type_enum::input_keyboard_action => {
                // vostok::journaling::input_handler::on_keyboard_action
                let keyboard_key = bytes[i];
                i += 1;

                let keyboard_action = bytes[i];
                i += 1;

                println!("{:?}: {}: {}", kind, keyboard_key, keyboard_action,);
            }
            /* input_gamepad_action */
            data_chunk_type_enum::input_gamepad_action => {
                // vostok::journaling::input_handler::on_gamepad_action
                let gamepad_button = bytes[i];
                i += 1;

                let gamepad_action = bytes[i];
                i += 1;

                println!("{:?}: {}: {}", kind, gamepad_button, gamepad_action,);
            }
            /* input_mouse_action */
            data_chunk_type_enum::input_mouse_action => {
                let kind = bytes[i];
                i += 1;

                match kind {
                    // vostok::journaling::input_handler::on_mouse_move
                    0x0 => {
                        let x = u32::from_le_bytes(bytes[i..i + 4].try_into().unwrap());
                        i += 4;
                        let y = u32::from_le_bytes(bytes[i..i + 4].try_into().unwrap());
                        i += 4;
                        let z = u32::from_le_bytes(bytes[i..i + 4].try_into().unwrap());
                        i += 4;

                        println!("{:?}: mouse_move: {}, {}, {}", kind, x, y, z,);
                    }
                    // vostok::journaling::input_handler::on_mouse_key_action
                    0xFF => {
                        let mouse_button = bytes[i];
                        i += 1;

                        let mouse_action = bytes[i];
                        i += 1;

                        println!("{:?}: mouse_key: {}, {}", kind, mouse_button, mouse_action,);
                    }
                    _ => unreachable!(),
                }
            }
            /* network_packet */
            data_chunk_type_enum::network_packet => {
                // vostok::journaling::match_client::write_packet
                let msg_type = bytes[i];
                let msg_type = bytemuck::checked::try_pod_read_unaligned::<
                    match_server_message_types_enum,
                >(&bytes[i..i + 1])
                .map(|msg_type| format!("{msg_type:?}"))
                .unwrap_or_else(|_| format!("{msg_type}"));
                i += 1;

                let len = u32::from_le_bytes(bytes[i..i + 4].try_into().unwrap()) as usize;
                i += 4;

                let msg = &bytes[i..i + len];
                i += len;

                eprintln!("{:?}: {}", kind, msg_type);
                println!("{:?}: {}", kind, msg_type);
            }
            /* version_chunk */
            data_chunk_type_enum::version_chunk => {
                // vostok::journaling::journal::journal
                let version = u32::from_le_bytes(bytes[i..i + 4].try_into().unwrap());
                i += 4;

                println!("{:?}: {}", kind, version);
            }
            /* mouse_sensitivity_chunk */
            data_chunk_type_enum::mouse_sensitivity_chunk => {
                // survarium::game::on_configs_loaded
                let a = u32::from_le_bytes(bytes[i..i + 4].try_into().unwrap());
                i += 4;
                let b = u32::from_le_bytes(bytes[i..i + 4].try_into().unwrap());
                i += 4;

                println!("{:?}: {} {}", kind, a, b);
            }
            _ => unreachable!(),
        }
    }
}

// SPDX-License-Identifier: GPL-3.0-or-later
use std::io::Write;
use std::panic;
use std::sync::{LazyLock, Mutex};

use vostok::serde::advance_buffer;

use crate::message;
use crate::message::client_message::raw::match_client_message_types_enum;
use crate::message::raw::udp_match_packets_count_enum;
use crate::sequence_number::SN16;

static LOG_FILE: LazyLock<Mutex<std::fs::File>> = LazyLock::new(log_file);

fn log_file() -> Mutex<std::fs::File> {
    fn get_current_time() -> u64 {
        use std::time::{SystemTime, UNIX_EPOCH};
        let start = SystemTime::now();
        let since_the_epoch = start
            .duration_since(UNIX_EPOCH)
            .expect("time should go forward");
        since_the_epoch.as_secs()
    }

    let file_name = format!(
        "./target/debug/match-server-{time}.log",
        time = get_current_time()
    );
    Mutex::new(std::fs::File::create(file_name).unwrap())
}

impl message::ClientMessage {
    pub fn print_debug(&self) {
        let Self {
            local_sequence_id,
            remote_sequence_id,
            remote_ack_bits,
            kind,
        } = self;

        let local_sequence_id = local_sequence_id.0;
        let remote_sequence_id = remote_sequence_id.0;

        let kinds = match &kind {
            message::ClientMessageKind::Low(low_level_message_type_enum) => {
                format!("{low_level_message_type_enum:?}")
            }
            message::ClientMessageKind::Messages(messages) => messages
                .iter()
                .map(|message| {
                    let message::ClientGameMessage {
                        order_id,
                        game_message,
                    } = message;
                    format!("0x{:04X}:{:?}", order_id.0, game_message.message_type())
                })
                .collect::<Vec<_>>()
                .join(", "),
        };

        let log_line = format!(
            "<<< local : 0x{local_sequence_id:04X} | remote: 0x{remote_sequence_id:04X} | remote: 0b{remote_ack_bits:016b} | {kinds}\n"
        );
        LOG_FILE
            .lock()
            .unwrap()
            .write_all(log_line.as_bytes())
            .unwrap();
        print!("{log_line}");
    }
}

impl message::ServerMessage {
    pub fn print_debug(&self) {
        let Self {
            remote_sequence_id,
            local_sequence_id,
            local_ack_bits,
            kind,
        } = self;

        let remote_sequence_id = remote_sequence_id.0;
        let local_sequence_id = local_sequence_id.0;

        let kinds = match &kind {
            message::ServerMessageKind::Low(low_level_message_type_enum) => {
                format!("{low_level_message_type_enum:?}")
            }
            message::ServerMessageKind::Messages(messages) => messages
                .iter()
                .map(|message| {
                    let message::ServerGameMessage {
                        order_id,
                        game_message,
                    } = message;
                    format!("0x{:04X}:{:?}", order_id.0, game_message.message_type())
                })
                .collect::<Vec<_>>()
                .join(", "),
        };

        let log_line = format!(
            ">>> remote: 0x{remote_sequence_id:04X} | local : 0x{local_sequence_id:04X} | local : 0b{local_ack_bits:016b} | {kinds}\n"
        );
        LOG_FILE
            .lock()
            .unwrap()
            .write_all(log_line.as_bytes())
            .unwrap();
        print!("{log_line}");
    }
}

pub fn print_debug(incoming_bytes: &[u8]) {
    let _result = panic::catch_unwind(|| try_print_debug(incoming_bytes));
    let log_line = format!("<!! {incoming_bytes:?}\n");
    LOG_FILE
        .lock()
        .unwrap()
        .write_all(log_line.as_bytes())
        .unwrap();
    print!("{log_line}");
}

pub fn try_print_debug(mut incoming_bytes: &[u8]) {
    let out_buffer = &mut incoming_bytes;
    let local_sequence_id = advance_buffer::<SN16>(out_buffer).unwrap().0;
    let remote_sequence_id = advance_buffer::<SN16>(out_buffer).unwrap().0;

    let word = advance_buffer::<u16>(out_buffer).unwrap();
    let remote_ack_bits = word >> 1 | 0x8000;

    let match_packets_count = (word & 1) as u8;
    let match_packets_count =
        bytemuck::checked::cast::<_, udp_match_packets_count_enum>(match_packets_count);

    let kinds = match match_packets_count {
        udp_match_packets_count_enum::single_packet => {
            let msg_type = advance_buffer::<match_client_message_types_enum>(out_buffer).unwrap();
            vec![format!("{msg_type:?}")]
        }
        udp_match_packets_count_enum::multiple_packets => {
            let mut messages = vec![];

            loop {
                let message_len = advance_buffer::<u8>(out_buffer).unwrap() as usize;
                let msg_type =
                    advance_buffer::<match_client_message_types_enum>(out_buffer).unwrap();
                messages.push(format!("{msg_type:?}"));

                *out_buffer = out_buffer[message_len - 1..].as_ref();

                if out_buffer.is_empty() {
                    break;
                }
            }

            messages
        }
    }
    .into_iter()
    .collect::<Vec<_>>()
    .join(", ");

    let log_line = format!(
        "<!< local : 0x{local_sequence_id:04X} | remote: 0x{remote_sequence_id:04X} | remote: 0b{remote_ack_bits:016b} | {kinds}\n"
    );
    LOG_FILE
        .lock()
        .unwrap()
        .write_all(log_line.as_bytes())
        .unwrap();
    print!("{log_line}");
}

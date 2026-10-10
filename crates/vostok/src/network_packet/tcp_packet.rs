// SPDX-License-Identifier: GPL-3.0-or-later
use crate::network_packet::Packet;

pub struct TcpPacket {
    buffer: Vec<u8>,
}

impl Packet for TcpPacket {
    fn append_bytes(&mut self, data: impl AsRef<[u8]>) {
        self.buffer.extend_from_slice(data.as_ref());
    }

    fn rewrite_bytes(&mut self, index: usize, data: impl AsRef<[u8]>) {
        let data = data.as_ref();
        self.buffer[index..index + data.len()].copy_from_slice(data);
    }

    fn cursor_index(&self) -> usize {
        self.buffer.len() - 3
    }
}

impl Default for TcpPacket {
    fn default() -> Self {
        Self::new()
    }
}

impl TcpPacket {
    pub fn new() -> Self {
        let mut buffer = Vec::with_capacity(128);
        buffer.push(0);
        buffer.push(0);
        buffer.push(0);
        Self { buffer }
    }

    pub fn push(&mut self, byte: u8) {
        self.buffer.push(byte)
    }

    pub fn clear(&mut self) {
        self.buffer.clear();
        self.buffer.push(0);
        self.buffer.push(0);
        self.buffer.push(0);
    }

    //
    //
    //

    pub fn get_buffer(&mut self) -> &[u8] {
        let msg_len = self.buffer.len() - 3;

        if msg_len >= 0x100 {
            let msg_len: u16 = msg_len.try_into().expect("All messages must fit into u16");
            let msg_len = msg_len.to_le_bytes();
            self.buffer[1] = msg_len[0];
            self.buffer[2] = msg_len[1];

            self.buffer.as_ref()
        } else {
            let msg_len: u8 = msg_len.try_into().expect("Checked in if");
            self.buffer[2] = msg_len;

            self.buffer[2..].as_ref()
        }
    }
}

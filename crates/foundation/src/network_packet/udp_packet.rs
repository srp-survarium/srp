// SPDX-License-Identifier: GPL-3.0-or-later
use crate::network_packet::Packet;

pub struct UdpPacket {
    buffer: [u8; 256],
    idx: usize,
}
impl Packet for UdpPacket {
    fn append_bytes(&mut self, data: impl AsRef<[u8]>) {
        let data = data.as_ref();
        self.buffer[self.idx..self.idx + data.len()].copy_from_slice(data);
        self.idx += data.len();
    }
}

impl Default for UdpPacket {
    fn default() -> Self {
        Self::new()
    }
}

impl UdpPacket {
    pub fn new() -> Self {
        Self {
            buffer: [0; 256],
            idx: 0,
        }
    }

    pub fn push(&mut self, byte: u8) -> &mut Self {
        self.buffer[self.idx] = byte;
        self.idx += 1;
        self
    }

    pub fn clear(&mut self) {
        self.idx = 0;
    }

    pub fn is_empty(&mut self) -> bool {
        self.idx == 0
    }

    //
    //
    //

    pub fn recv_from(
        &mut self,
        socket: &std::net::UdpSocket,
    ) -> std::io::Result<std::net::SocketAddr> {
        let (bytes_read, addr) = socket.recv_from(&mut self.buffer)?;
        self.idx = bytes_read;
        Ok(addr)
    }

    pub fn recv(&mut self, socket: &std::net::UdpSocket) -> std::io::Result<&[u8]> {
        self.clear();
        let bytes_read = socket.recv(&mut self.buffer)?;
        self.idx = bytes_read;
        Ok(self.get_message())
    }

    pub fn send(&self, socket: &std::net::UdpSocket) -> std::io::Result<()> {
        let bytes_sent = socket.send(self.get_message())?;
        assert_eq!(bytes_sent, self.idx);
        Ok(())
    }

    //
    //
    //

    pub fn get_message(&self) -> &[u8] {
        &self.buffer[0..self.idx]
    }

    pub fn get_buffer(&mut self) -> &mut [u8] {
        &mut self.buffer
    }
}

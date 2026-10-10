// SPDX-License-Identifier: GPL-3.0-or-later
use crate::network_client::{NetworkError, NetworkRequest, NetworkResponse};
use crate::network_packet::UdpPacket;

pub struct UdpClient {
    socket: std::net::UdpSocket,
    buffer: UdpPacket,
}

impl UdpClient {
    pub fn new(addr: impl std::net::ToSocketAddrs) -> Result<Self, NetworkError> {
        let socket = std::net::UdpSocket::bind(addr)?;

        Ok(Self {
            socket,
            buffer: UdpPacket::new(),
        })
    }

    pub fn connect(&self, addr: impl std::net::ToSocketAddrs) -> Result<(), NetworkError> {
        self.socket.connect(addr)?;

        Ok(())
    }

    pub fn recv_from<T: NetworkRequest>(
        &mut self,
    ) -> Result<(std::net::SocketAddr, T), NetworkError> {
        let addr = self.buffer.recv_from(&self.socket)?;
        let request = T::deserialize(&mut self.buffer.get_message())?;
        self.buffer.clear();

        Ok((addr, request))
    }

    pub fn recv<T: NetworkRequest>(&mut self) -> Result<T, NetworkError> {
        self.buffer.recv(&self.socket)?;
        let request = T::deserialize(&mut self.buffer.get_message())?;
        self.buffer.clear();

        Ok(request)
    }

    pub fn send<T: NetworkResponse>(&mut self, message: T) -> Result<(), NetworkError> {
        message.serialize(&mut self.buffer);
        self.buffer.send(&self.socket)?;
        self.buffer.clear();
        Ok(())
    }

    pub fn recv_raw(&mut self) -> Result<Vec<u8>, NetworkError> {
        self.buffer.recv(&self.socket)?;
        Ok(self.buffer.get_message().to_vec())
    }

    pub fn send_raw(&self, buffer: &[u8]) -> Result<(), NetworkError> {
        let bytes_sent = self.socket.send(buffer)?;
        assert_eq!(bytes_sent, buffer.len());
        Ok(())
    }
}

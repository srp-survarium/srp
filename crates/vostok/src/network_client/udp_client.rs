use std::io;
use std::time::Duration;

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

    pub fn try_clone(&self) -> std::io::Result<Self> {
        self.socket.try_clone().map(|socket| Self {
            socket,
            buffer: UdpPacket::new(),
        })
    }

    pub fn set_timeout(&self, duration: Option<Duration>) -> Result<(), NetworkError> {
        self.socket.set_read_timeout(duration)?;
        self.socket.set_write_timeout(duration)?;

        Ok(())
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

    pub fn recv_from_raw(&mut self) -> Result<(std::net::SocketAddr, Vec<u8>), NetworkError> {
        let addr = self.buffer.recv_from(&self.socket)?;
        Ok((addr, self.buffer.get_message().to_vec()))
    }

    pub fn recv_raw(&mut self) -> Result<Vec<u8>, io::Error> {
        self.buffer.recv(&self.socket)?;
        Ok(self.buffer.get_message().to_vec())
    }

    pub fn send_raw(&self, buffer: &[u8]) -> Result<(), io::Error> {
        let bytes_sent = self.socket.send(buffer)?;
        assert_eq!(bytes_sent, buffer.len());
        Ok(())
    }
}

use std::io::{Read, Write};
use std::net::TcpStream;

use crate::network_client::{NetworkError, NetworkRequest, NetworkResponse};
use crate::network_packet::TcpPacket;

pub struct TcpClient {
    stream: TcpStream,
    read_buffer: Vec<u8>,
    read_buffer_len: usize,
    read_buffer_idx: usize,

    write_packet: TcpPacket,
}

impl TcpClient {
    pub fn new(stream: TcpStream) -> Self {
        Self {
            stream,
            // @NOTE: assumes that every single request can fit into 512 bytes
            read_buffer: vec![0; 512],
            read_buffer_len: 0,
            read_buffer_idx: 0,
            write_packet: TcpPacket::new(),
        }
    }

    pub fn get_read_buffer(&self) -> &[u8] {
        &self.read_buffer[self.read_buffer_idx..self.read_buffer_len]
    }

    pub fn read<T: NetworkRequest>(&mut self) -> Result<T, NetworkError> {
        let (msg, read_buffer_idx) = self.peek_impl()?;
        self.read_buffer_idx = read_buffer_idx;
        Ok(msg)
    }

    pub fn peek<T: NetworkRequest>(&mut self) -> Result<T, NetworkError> {
        self.peek_impl().map(|(msg, _)| msg)
    }

    fn peek_impl<T: NetworkRequest>(&mut self) -> Result<(T, usize), NetworkError> {
        if self.read_buffer_len == self.read_buffer_idx {
            self.read_buffer_len = self.stream.read(&mut self.read_buffer)?;
            self.read_buffer_idx = 0;

            if self.read_buffer_len == 0 {
                panic!("Received an empty message") // @TODO
            }

            self.peek_impl()
        } else {
            let read_buffer: &mut &[u8] =
                &mut &self.read_buffer[self.read_buffer_idx..self.read_buffer_len];

            let msg = T::deserialize(read_buffer)?;
            let read_buffer_idx = self.read_buffer_len - read_buffer.len();

            Ok((msg, read_buffer_idx))
        }
    }

    pub fn send<T: NetworkResponse>(&mut self, message: T) -> Result<(), NetworkError> {
        message.serialize(&mut self.write_packet);
        self.stream.write_all(self.write_packet.get_buffer())?;
        self.write_packet.clear();

        Ok(())
    }
}

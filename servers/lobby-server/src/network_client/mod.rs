use std::io::{Read, Write};
use std::net::TcpStream;
use std::panic::Location;

mod packet;
pub use self::packet::Packet;

pub struct NetworkClient {
    stream: TcpStream,
    read_buffer: Vec<u8>,
    read_buffer_len: usize,
    read_buffer_idx: usize,

    write_packet: Packet,
}

#[derive(Debug, thiserror::Error)]
pub enum NetworkClientError {
    #[error("Failed to deserialize the message: {0}")]
    DeserializeError(#[from] DeserializeError),
    #[error("Socket failure: {0}")]
    NetworkError(#[from] std::io::Error),
}

pub trait NetworkMessage: Sized {
    fn deserialize(buffer: &mut &[u8]) -> Result<Self, DeserializeError>;
    fn serialize(self, packet: &mut Packet);
}

#[derive(Debug, PartialEq, Clone, thiserror::Error)]
pub enum DeserializeError {
    #[error("NotEnoughInput")]
    NotEnoughInput,
    #[error("UnknownMessageType: {0}")]
    UnknownMessageType(u8),
    #[error("IncorrectInput: \"{msg}\" at '{location}'")]
    IncorrectInput {
        location: &'static std::panic::Location<'static>,
        msg: String,
    },
}

impl NetworkClient {
    pub fn new(stream: TcpStream) -> Self {
        Self {
            stream,
            // @NOTE: assumes that every single request can fit into 512 bytes
            read_buffer: vec![0; 512],
            read_buffer_len: 0,
            read_buffer_idx: 0,
            write_packet: Packet::new(),
        }
    }

    pub fn get_read_buffer(&self) -> &[u8] {
        &self.read_buffer[self.read_buffer_idx..self.read_buffer_len]
    }

    pub fn read<T: NetworkMessage>(&mut self) -> Result<T, NetworkClientError> {
        let (msg, read_buffer_idx) = self.peek_impl()?;
        self.read_buffer_idx = read_buffer_idx;
        Ok(msg)
    }

    pub fn peek<T: NetworkMessage>(&mut self) -> Result<T, NetworkClientError> {
        self.peek_impl().map(|(msg, _)| msg)
    }

    fn peek_impl<T: NetworkMessage>(&mut self) -> Result<(T, usize), NetworkClientError> {
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

    pub fn send<T: NetworkMessage>(&mut self, message: T) -> Result<(), NetworkClientError> {
        message.serialize(&mut self.write_packet);
        self.stream.write_all(self.write_packet.get_buffer())?;
        self.write_packet.clear();

        Ok(())
    }
}

impl DeserializeError {
    #[track_caller]
    pub fn incorrect_input() -> Self {
        Self::IncorrectInput {
            location: Location::caller(),
            msg: String::new(),
        }
    }

    /// Don't use it pointless style with this function,
    /// as it will return incorrect location
    /// ```ignore
    /// let to_slot = bytemuck::checked::try_cast(to_slot)
    ///     .map_err(DeserializeError::incorrect_input_from)?
    /// // Location { file: "../library/core/src/ops//function.rs", ... }
    /// ```
    ///
    /// Fully expand arguments instead:
    /// ```ignore
    /// let to_slot = bytemuck::checked::try_cast(to_slot)
    ///     .map_err(|x| DeserializeError::incorrect_input_from(x))?
    /// // Location { file: "../lobby_server/message/client.rs", ... }
    #[track_caller]
    pub fn incorrect_input_from(msg: impl ToString) -> Self {
        Self::IncorrectInput {
            location: Location::caller(),
            msg: msg.to_string(),
        }
    }
}

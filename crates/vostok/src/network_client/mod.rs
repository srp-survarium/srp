// SPDX-License-Identifier: GPL-3.0-or-later
mod tcp_client;
mod udp_client;

pub use tcp_client::TcpClient;
pub use udp_client::UdpClient;

use crate::serde::{Deserialize, DeserializeError, Serialize};

pub trait NetworkRequest: Deserialize {}
pub trait NetworkResponse: Serialize {}

#[derive(Debug, thiserror::Error)]
pub enum NetworkError {
    #[error("Failed to deserialize the message: {0}")]
    DeserializeError(#[from] DeserializeError),
    #[error("Socket failure: {0}")]
    NetworkError(#[from] std::io::Error),
}

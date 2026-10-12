#![no_std]
#![forbid(unsafe_code)]

pub mod application;
#[cfg(feature = "lzma")]
pub mod compression;
pub mod login;
pub mod reader;
pub mod state;
pub mod transport;

pub const MAX_DATAGRAM: usize = 512;
pub const MAX_FRAMES: usize = 252;
pub const MAX_PARTS: usize = 255;
pub const MAX_MESSAGE: usize = MAX_PARTS * MAX_DATAGRAM;
pub const MAX_OPTIONS: usize = 0x578a0;
pub const MAX_STATE: usize = 32768;
pub const MAX_PLAYERS: u8 = 20;
pub const FRAGMENT_TIMEOUT_MS: u32 = 5000;

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
#[repr(i32)]
pub enum Error {
    Truncated = 1,
    Limit = 2,
    Invalid = 3,
    Unsupported = 4,
    FragmentConflict = 6,
    Expired = 7,
    Codec = 8,
}
pub type Result<T> = core::result::Result<T, Error>;

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct Players(u8);
impl Players {
    pub fn new(value: u8) -> Result<Self> {
        if (1..=MAX_PLAYERS).contains(&value) {
            Ok(Self(value))
        } else {
            Err(Error::Invalid)
        }
    }
    pub const fn get(self) -> u8 {
        self.0
    }
    pub fn validate_mask(self, mask: u32) -> Result<()> {
        if mask >> self.0 == 0 {
            Ok(())
        } else {
            Err(Error::Invalid)
        }
    }
}

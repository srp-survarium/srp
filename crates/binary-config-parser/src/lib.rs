pub mod deserialize;
pub mod serialize;

use crc32fast::Hasher;

/// Constraints:
/// The data structure should be consistent with all offsets pointing inside it
pub struct BinaryConfig(pub(crate) Vec<u8>);

impl BinaryConfig {
    #[inline]
    pub fn new(binary: &[u8]) -> Self {
        Self(binary.to_vec())
    }

    pub fn as_bytes(&self) -> &[u8] {
        self.0.as_ref()
    }
}

#[repr(C)]
#[derive(Debug, Copy, Clone, Hash, PartialEq, Eq, PartialOrd, Ord)]
pub struct BinaryValue {
    /// Either a value or offset from root to a table
    pub data: u64,
    pub id: u64,
    pub id_crc: IdCrc,
    pub type_: BinaryType,
    pub count: u16,
}
const _: () = assert!(std::mem::size_of::<BinaryValue>() == 0x18);
const _: () = assert!(std::mem::align_of::<BinaryValue>() == 0x8);

impl BinaryValue {
    pub const SIZE: usize = std::mem::size_of::<Self>();

    pub fn as_bytes(&self) -> &[u8] {
        unsafe { std::slice::from_raw_parts(self as *const _ as *const u8, Self::SIZE) }
    }
}

#[repr(u16)]
#[derive(Debug, Copy, Clone, Hash, PartialEq, Eq, PartialOrd, Ord, num_derive::FromPrimitive)]
pub enum BinaryType {
    Boolean,
    Integer,
    Float,
    TableNamed,
    TableIndexed,
    String,
    Float2,
    Float3,
    Float4,
}

#[repr(transparent)]
#[derive(Copy, Clone, Hash, PartialEq, Eq, PartialOrd, Ord, Debug, Default)]
pub struct IdCrc(u32);

impl IdCrc {
    pub fn get(self) -> u32 {
        self.0
    }

    pub fn get_hash(name: &str) -> Self {
        let mut hasher = Hasher::new();
        hasher.update(name.as_bytes());
        Self(hasher.finalize())
    }
}

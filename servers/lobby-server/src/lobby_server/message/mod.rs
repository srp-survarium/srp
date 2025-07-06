pub mod client;
pub mod server;

use crate::network_client::DeserializeError;

#[inline]
#[track_caller]
pub fn advance_padding<const N: usize>(buffer: &mut &[u8]) -> Result<(), DeserializeError> {
    let padding = advance_buffer::<[u8; N]>(buffer)?;
    let empty = [0; N];
    match padding == empty {
        true => Ok(()),
        false => Err(DeserializeError::incorrect_input()),
    }
}

#[inline]
#[track_caller]
pub fn advance_buffer<T: bytemuck::CheckedBitPattern>(
    buffer: &mut &[u8],
) -> Result<T, DeserializeError> {
    let size = std::mem::size_of::<T>();
    if buffer.len() < size {
        return Err(DeserializeError::NotEnoughInput);
    }

    // `map_err` breaks `track_caller`
    let result = match bytemuck::checked::try_pod_read_unaligned(&buffer[0..size]) {
        Ok(value) => Ok(value),
        Err(error) => Err(DeserializeError::incorrect_input_from(error)),
    };
    *buffer = &buffer[size..];
    result
}

/// Requires alignment to be matched
/// TODO: Possibly this function doesn't make sense, because alignment would only allow u8 types here
#[inline]
#[track_caller]
pub fn advance_by<'a, T: bytemuck::CheckedBitPattern>(
    n: usize,
    buffer: &mut &'a [u8],
) -> Result<&'a [T], DeserializeError> {
    let size = std::mem::size_of::<T>() * n;
    if buffer.len() < size {
        return Err(DeserializeError::NotEnoughInput);
    }

    // `map_err` breaks `track_caller`
    let result = match bytemuck::checked::try_cast_slice::<_, T>(&buffer[0..size]) {
        Ok(value) => Ok(value),
        Err(error) => Err(DeserializeError::incorrect_input_from(error)),
    };
    *buffer = &buffer[size..];
    result
}

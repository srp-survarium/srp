use crate::{Error, MAX_MESSAGE, MAX_OPTIONS, Result};
use lzma_rust2::{Action, Lzma2Stream, Status};

/// Safe Rust, no_std + alloc; dictionary is trusted, not read from the peer.
/// Requires one complete raw stream, exact input consumption and bounded output.
pub fn decode(input: &[u8], output: &mut [u8]) -> Result<usize> {
    if input.len() > MAX_MESSAGE || output.len() > MAX_OPTIONS {
        return Err(Error::Limit);
    }
    let mut decoder = Lzma2Stream::new_mem_limit(32768, 256);
    let result = decoder
        .process(input, output, Action::Finish)
        .map_err(|_| Error::Codec)?;
    if result.status != Status::StreamEnd || result.bytes_consumed != input.len() {
        return Err(Error::Codec);
    }
    if result.bytes_produced > output.len() {
        return Err(Error::Codec);
    }
    Ok(result.bytes_produced)
}

// SPDX-License-Identifier: GPL-3.0-or-later
//! Raw LZMA2 for 0.26g0 static match info and world synchronization.
//! The client constructor at 0x219a0c selects dictionary=32768, lc=4, lp=0,
//! pb=2. There is no .xz/.lzma container or dictionary property byte on the wire.

use std::{ffi::c_void, ptr};

/// Capacity of the retail static-info decompression buffer at 0x27b880.
pub const MAX_EXPANDED_SIZE: usize = 0x578a0;

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Error {
    TooLarge,
    InvalidStream,
    Codec(u32),
}

impl std::fmt::Display for Error {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "0.26 LZMA2: {self:?}")
    }
}
impl std::error::Error for Error {}

fn options() -> lzma_sys::lzma_options_lzma {
    // SAFETY: This C options struct permits null pointers and zero integer
    // fields. The preset initializer fills all fields used by liblzma.
    let mut options = unsafe { std::mem::zeroed() };
    let result = unsafe { lzma_sys::lzma_lzma_preset(&mut options, 9) };
    assert_eq!(result, 0, "liblzma must support its standard preset 9");
    options.dict_size = 32768;
    options.lc = 4;
    options.lp = 0;
    options.pb = 2;
    options
}

fn filters(options: &mut lzma_sys::lzma_options_lzma) -> [lzma_sys::lzma_filter; 2] {
    [
        lzma_sys::lzma_filter {
            id: lzma_sys::LZMA_FILTER_LZMA2,
            options: ptr::from_mut(options).cast::<c_void>(),
        },
        lzma_sys::lzma_filter {
            id: lzma_sys::LZMA_VLI_UNKNOWN,
            options: ptr::null_mut(),
        },
    ]
}

pub fn compress(input: &[u8]) -> Result<Vec<u8>, Error> {
    if input.len() > MAX_EXPANDED_SIZE {
        return Err(Error::TooLarge);
    }
    let mut options = options();
    let filters = filters(&mut options);
    // Even an incompressible raw stream fits below this conservative bound.
    let mut output = vec![0; input.len() * 2 + 128];
    let mut written = 0;
    // SAFETY: Both slices remain live, lengths match their allocations, output
    // does not alias input, and the terminated filter chain/options stay live
    // for this synchronous buffer operation. Null selects the default allocator.
    let result = unsafe {
        lzma_sys::lzma_raw_buffer_encode(
            filters.as_ptr(),
            ptr::null(),
            input.as_ptr(),
            input.len(),
            output.as_mut_ptr(),
            &mut written,
            output.len(),
        )
    };
    if result != lzma_sys::LZMA_OK {
        return Err(Error::Codec(result));
    }
    output.truncate(written);
    Ok(output)
}

/// Decode with a caller-selected output limit, additionally capped at the
/// retail buffer size. Require one complete stream with no trailing bytes.
pub fn decompress(input: &[u8], limit: usize) -> Result<Vec<u8>, Error> {
    if limit > MAX_EXPANDED_SIZE || input.len() > MAX_EXPANDED_SIZE * 2 + 128 {
        return Err(Error::TooLarge);
    }
    let mut options = options();
    let filters = filters(&mut options);
    let mut output = vec![0; limit];
    let (mut read, mut written) = (0, 0);
    // SAFETY: Same buffer/filter lifetime and bounds guarantees as compress().
    let result = unsafe {
        lzma_sys::lzma_raw_buffer_decode(
            filters.as_ptr(),
            ptr::null(),
            input.as_ptr(),
            &mut read,
            input.len(),
            output.as_mut_ptr(),
            &mut written,
            output.len(),
        )
    };
    if result != lzma_sys::LZMA_OK {
        return Err(Error::Codec(result));
    }
    if read != input.len() {
        return Err(Error::InvalidStream);
    }
    output.truncate(written);
    Ok(output)
}

#[cfg(test)]
mod tests {
    use super::*;

    fn hex(s: &str) -> Vec<u8> {
        (0..s.len())
            .step_by(2)
            .map(|i| u8::from_str_radix(&s[i..i + 2], 16).unwrap())
            .collect()
    }

    #[test]
    fn streams_verified_by_retail_decoder() {
        for line in include_str!("../fixtures/026g-lzma.tsv").lines() {
            if line.starts_with('#') {
                continue;
            }
            let c: Vec<_> = line.split('\t').collect();
            let original = hex(c[0]).repeat(c[1].parse().unwrap());
            let encoded = hex(c[2]);
            assert_eq!(decompress(&encoded, MAX_EXPANDED_SIZE).unwrap(), original);
            // Matching the fixture bytes proves these actual server encoder
            // outputs were accepted by the retail machine-code oracle.
            assert_eq!(compress(&original).unwrap(), encoded);
        }
    }

    #[test]
    fn enforces_limits_and_complete_streams() {
        let encoded = compress(&[42; 1000]).unwrap();
        assert!(decompress(&encoded, 999).is_err());
        assert!(decompress(&encoded[..encoded.len() - 1], 1000).is_err());
        let mut trailing = encoded.clone();
        trailing.push(0);
        assert_eq!(decompress(&trailing, 1000), Err(Error::InvalidStream));
        assert!(decompress(b"invalid", 1000).is_err());
        assert_eq!(
            compress(&vec![0; MAX_EXPANDED_SIZE + 1]),
            Err(Error::TooLarge)
        );
        assert_eq!(
            decompress(&encoded, MAX_EXPANDED_SIZE + 1),
            Err(Error::TooLarge)
        );
        assert_eq!(decompress(&compress(&[]).unwrap(), 0).unwrap(), []);
    }
}

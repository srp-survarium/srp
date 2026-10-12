// SPDX-License-Identifier: GPL-3.0-or-later
//! Opt-in E2 upload: timestamp, byte offset, total size, up to 480 bytes.
//! This is an SRP extension, not a retail client message.

pub struct Upload {
    pub time: u32,
    pub bytes: Vec<u8>,
    received: Vec<bool>,
}

pub struct Request {
    pub time: u32,
    pub crc: u32,
    pub requested_at: u64,
    pub upload: Option<Upload>,
}

pub struct Checkpoint {
    pub time: u32,
    pub crc: u32,
    pub bytes: Vec<u8>,
}

impl Request {
    pub fn receive(&mut self, body: &[u8]) -> Result<Option<Checkpoint>, &'static str> {
        let time = body.get(..4).ok_or("truncated snapshot timestamp")?;
        if u32::from_le_bytes(time.try_into().unwrap()) != self.time {
            // Delayed fragments from an earlier request must not poison this one.
            return Ok(None);
        }
        if !Upload::receive(&mut self.upload, body)? {
            return Ok(None);
        }
        let upload = self.upload.take().unwrap();
        let crc = crc32fast::hash(&upload.bytes);
        if crc != self.crc {
            return Err("snapshot does not match the reported historical CRC");
        }
        Ok(Some(Checkpoint {
            time: upload.time,
            crc,
            bytes: upload.bytes,
        }))
    }
}

impl Upload {
    pub fn receive(slot: &mut Option<Self>, body: &[u8]) -> Result<bool, &'static str> {
        if body.len() < 9 {
            return Err("truncated snapshot fragment");
        }
        let time = u32::from_le_bytes(body[..4].try_into().unwrap());
        let offset = usize::from(u16::from_le_bytes(body[4..6].try_into().unwrap()));
        let total = usize::from(u16::from_le_bytes(body[6..8].try_into().unwrap()));
        let data = &body[8..];
        if !(4..=32764).contains(&total)
            || offset >= total
            || offset % 480 != 0
            || data.len() != (total - offset).min(480)
            || time % 50 != 0
        {
            return Err("invalid snapshot fragment bounds or timestamp");
        }
        if slot.is_none() {
            *slot = Some(Self {
                time,
                bytes: vec![0; total],
                received: vec![false; total.div_ceil(480)],
            });
        }
        let upload = slot.as_mut().unwrap();
        if upload.time != time || upload.bytes.len() != total {
            return Err("snapshot identity changed during transfer");
        }
        let chunk = offset / 480;
        let destination = &mut upload.bytes[offset..offset + data.len()];
        if upload.received[chunk] && destination != data {
            return Err("conflicting snapshot fragment");
        }
        destination.copy_from_slice(data);
        upload.received[chunk] = true;
        Ok(upload.complete())
    }

    pub fn complete(&self) -> bool {
        self.received.iter().all(|received| *received)
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn requested_snapshot_must_match_timestamp_and_reported_crc() {
        let mut request = Request {
            time: 50,
            crc: 0xcbf43926,
            requested_at: 0,
            upload: None,
        };
        let mut old = fragment(0, 9, b"123456789");
        old[..4].copy_from_slice(&0u32.to_le_bytes());
        assert!(request.receive(&old).unwrap().is_none());
        assert!(request.upload.is_none());
        assert!(request.receive(&fragment(0, 9, b"123456780")).is_err());
        let checked = request
            .receive(&fragment(0, 9, b"123456789"))
            .unwrap()
            .unwrap();
        assert_eq!(checked.time, 50);
        assert_eq!(checked.crc, 0xcbf43926);
        assert_eq!(checked.bytes, b"123456789");
    }
    fn fragment(offset: u16, total: u16, data: &[u8]) -> Vec<u8> {
        [
            50u32.to_le_bytes().as_slice(),
            &offset.to_le_bytes(),
            &total.to_le_bytes(),
            data,
        ]
        .concat()
    }
    #[test]
    fn reordered_duplicates_conflicts_and_bounds() {
        let mut upload = None;
        assert!(!Upload::receive(&mut upload, &fragment(480, 500, &[2; 20])).unwrap());
        assert!(!Upload::receive(&mut upload, &fragment(480, 500, &[2; 20])).unwrap());
        assert!(Upload::receive(&mut upload, &fragment(480, 500, &[3; 20])).is_err());
        assert!(Upload::receive(&mut upload, &fragment(0, 500, &[1; 480])).unwrap());
        assert_eq!(
            upload.unwrap().bytes,
            [&[1; 480][..], &[2; 20][..]].concat()
        );
        for (offset, total, size) in [
            (1, 500, 480),
            (480, 500, 21),
            (0, 32765, 480),
            (500, 500, 1),
        ] {
            assert!(Upload::receive(&mut None, &fragment(offset, total, &vec![0; size])).is_err());
        }
    }
}

// SPDX-License-Identifier: GPL-3.0-or-later
#[rustfmt::skip]
macro_rules! sequence_number {
    ($name:ident : $ty:ty => $mem:ty) => {
        #[derive(
            bytemuck::CheckedBitPattern,
            bytemuck::NoUninit,
            Debug,
            Default,
            PartialEq,
            Eq,
            Clone,
            Copy,
        )]
        #[repr(transparent)]
        pub struct $name(pub $ty);

        impl $name {
            const fn new(value: $ty) -> Self {
                Self(value)
            }
        }

        impl From<$ty> for $name {
            fn from(value: $ty) -> Self {
                Self::new(value)
            }
        }

        impl std::ops::Add for $name {
            type Output = Self;
            fn add(self, rhs: Self) -> Self::Output {
                Self(self.0.wrapping_add(rhs.0))
            }
        }

        impl std::ops::AddAssign for $name {
            fn add_assign(&mut self, rhs: Self) {
                *self = *self + rhs;
            }
        }

        impl PartialOrd for $name {
            fn partial_cmp(&self, rhs: &Self) -> Option<std::cmp::Ordering> {
                Some(self.cmp(rhs))
            }
        }

        impl Ord for $name {
            fn cmp(&self, rhs: &Self) -> std::cmp::Ordering {
                use std::cmp::Ordering::*;
                fn less(this: $ty, other: $ty) -> bool {
                    const HALF: $mem = (<$ty>::MAX / 2 + 1) as $mem;
                    let this = this as $mem;
                    let other = other as $mem;

                    this < other && this + HALF > other || other < this && other + HALF <= this
                }

                if self == rhs {
                    Equal
                } else if less(self.0, rhs.0) {
                    Less
                } else {
                    Greater
                }


            }
        }
    };
}

impl std::ops::Sub for SN16 {
    type Output = i32;

    fn sub(self, rhs: Self) -> Self::Output {
        if rhs <= self {
            let lhs: i32 = self.0.into();
            let rhs: i32 = rhs.0.into();
            (lhs + 0x10000 - rhs) % 0x10000
        } else {
            -rhs.sub(self)
        }
    }
}

sequence_number!(SN8 : u8 => u16);
sequence_number!(SN16: u16 => u32);
sequence_number!(SN32: u32 => u64);
sequence_number!(SN64: u64 => u128);

#[test]
fn test_sequence_number() {
    assert!(SN16::new(0) < SN16::new(1));

    assert!(SN16::new(0) > SN16::new(0xFFFF));

    assert!(SN16::new(0) < SN16::new(0x8000 - 1));
    assert!(SN16::new(0) > SN16::new(0x8000));
    assert!(SN16::new(0) > SN16::new(0x8000 + 1));

    assert!(SN16::new(0x8000 - 1) > SN16::new(0));
    assert!(SN16::new(0x8000) < SN16::new(0));
    assert!(SN16::new(0x8000 + 1) < SN16::new(0));

    let mut times = 0;
    let mut i = SN16::new(u16::MAX - 1);
    while i < SN16::new(10) {
        times += 1;
        i += 1.into()
    }
    assert_eq!(times, 12);
}

#[derive(Debug, Copy, Clone, PartialEq, Eq)]
pub struct MyFieldAttributes(pub u16);

impl MyFieldAttributes {
    pub fn extract(val: pdb::FieldAttributes) -> Self {
        let s = format!("{val:?}",);
        let s = s
            .trim_start_matches("FieldAttributes(")
            .trim_end_matches(')')
            .parse::<u16>()
            .unwrap();
        Self(s)
    }

    #[inline]
    #[must_use]
    fn method_properties(self) -> u8 {
        ((self.0 & 0x001c) >> 2) as u8
    }

    #[inline]
    #[must_use]
    pub fn is_pure(self) -> bool {
        matches!(self.method_properties(), 0x05 | 0x06)
    }

    #[inline]
    #[must_use]
    pub fn is_virtual(self) -> bool {
        matches!(self.method_properties(), 0x01 | 0x04 | 0x05 | 0x06)
    }

    #[inline]
    pub fn is_override(self) -> bool {
        matches!(self.method_properties(), 0x01 | 0x05)
    }

    #[inline]
    #[must_use]
    pub fn is_static(self) -> bool {
        self.method_properties() == 0x02
    }

    #[inline]
    #[must_use]
    pub fn sealed(self) -> bool {
        self.0 & 0x0200 != 0
    }

    //
    //
    //

    #[inline]
    #[must_use]
    pub fn noinherit(self) -> bool {
        self.0 & 0x0040 != 0
    }

    #[inline]
    #[must_use]
    pub fn noconstruct(self) -> bool {
        self.0 & 0x0080 != 0
    }
}

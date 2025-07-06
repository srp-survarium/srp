pub struct Packet {
    buffer: Vec<u8>,
}
impl Extend<u8> for Packet {
    fn extend<T: IntoIterator<Item = u8>>(&mut self, iter: T) {
        self.buffer.extend(iter)
    }
}

impl<'a> Extend<&'a u8> for Packet {
    fn extend<T: IntoIterator<Item = &'a u8>>(&mut self, iter: T) {
        self.buffer.extend(iter)
    }
}

impl Packet {
    pub fn new() -> Self {
        let mut buffer = Vec::with_capacity(128);
        buffer.push(0);
        buffer.push(0);
        buffer.push(0);
        Self { buffer }
    }

    pub fn push(&mut self, byte: u8) {
        self.buffer.push(byte)
    }

    pub fn clear(&mut self) {
        self.buffer.clear();
        self.buffer.push(0);
        self.buffer.push(0);
        self.buffer.push(0);
    }

    //
    //
    //

    pub fn write<T: bytemuck::NoUninit>(&mut self, value: T) {
        self.extend(bytemuck::bytes_of(&value))
    }

    pub fn write_ref<T: bytemuck::NoUninit>(&mut self, value: &T) {
        self.extend(bytemuck::bytes_of(value))
    }

    pub fn write_vec<L, E, T>(&mut self, values: Vec<T>)
    where
        L: TryFrom<usize, Error = E> + bytemuck::NoUninit,
        E: std::fmt::Debug,
        T: bytemuck::NoUninit,
    {
        let len: L = values.len().try_into().unwrap();
        self.write(len);
        for value in values {
            self.write(value)
        }
    }

    pub fn write_slice<L, E, T>(&mut self, values: &[T])
    where
        L: TryFrom<usize, Error = E> + bytemuck::NoUninit,
        E: std::fmt::Debug,
        T: bytemuck::NoUninit,
    {
        let len: L = values.len().try_into().unwrap();
        self.write(len);
        for value in values {
            self.write_ref(value)
        }
    }

    pub fn write_str(&mut self, value: &str) {
        let len: u8 = value.len().try_into().unwrap();
        self.push(len);
        self.extend(value.as_bytes());
    }

    //
    //
    //

    pub fn get_buffer(&mut self) -> &[u8] {
        let msg_len = self.buffer.len() - 3;

        if msg_len >= 0x100 {
            let msg_len: u16 = msg_len.try_into().expect("All messages must fit into u16");
            let msg_len = msg_len.to_le_bytes();
            self.buffer[1] = msg_len[0];
            self.buffer[2] = msg_len[1];

            self.buffer.as_ref()
        } else {
            let msg_len: u8 = msg_len.try_into().expect("Checked in if");
            self.buffer[2] = msg_len;

            self.buffer[2..].as_ref()
        }
    }
}

mod tcp_packet;
mod udp_packet;

pub use tcp_packet::TcpPacket;
pub use udp_packet::UdpPacket;

pub trait Packet {
    fn append_bytes(&mut self, data: impl AsRef<[u8]>);
    fn rewrite_bytes(&mut self, index: usize, data: impl AsRef<[u8]>);
    fn cursor_index(&self) -> usize;

    fn write<T: bytemuck::NoUninit>(&mut self, value: T) {
        self.append_bytes(bytemuck::bytes_of(&value))
    }

    fn write_ref<T: bytemuck::NoUninit>(&mut self, value: &T) {
        self.append_bytes(bytemuck::bytes_of(value))
    }

    fn write_vec<L, E, T>(&mut self, values: Vec<T>)
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

    fn write_slice<L, E, T>(&mut self, values: &[T])
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

    fn write_str(&mut self, value: &str) {
        let len: u8 = value.len().try_into().unwrap();
        self.append_bytes([len]);
        self.append_bytes(value.as_bytes());
    }
}

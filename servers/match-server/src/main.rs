use std::io::Read;
use std::net::{TcpListener, TcpStream, UdpSocket};

fn main() -> std::io::Result<()> {
    let addr = format!(
        "{}:{}",
        foundation::match_server::ADDRESS,
        foundation::match_server::PORT
    );

    let mut buffer = vec![0_u8; 2056];

    let socket = UdpSocket::bind(&addr)?;
    loop {
        let bytes_read = socket.recv(&mut buffer)?;
        println!("{:02x?}", &buffer[0..bytes_read]);
    }

    Ok(())
}

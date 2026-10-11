// SPDX-License-Identifier: GPL-3.0-or-later
//! Bounded, loopback-only native lobby sign-in diagnostic. Not a lobby service.
use std::{
    collections::BTreeMap,
    net::UdpSocket,
    time::{Duration, Instant},
};
use survarium::protocol_026::{self as wire, Direction, Frame};
use vostok::network_packet::udp_026::Header;

#[derive(Default)]
struct Peer {
    send: u8,
    newest: Option<u8>,
    mask: u128,
    last: u64,
    signed: bool,
}
impl Peer {
    fn observe(&mut self, sequence: u8) {
        let Some(newest) = self.newest else {
            self.newest = Some(sequence);
            self.mask = 1 << 127;
            return;
        };
        let forward = sequence.wrapping_sub(newest);
        if forward != 0 && forward < 128 {
            self.mask = (self.mask >> forward) | (1 << 127);
            self.newest = Some(sequence);
        } else {
            let age = newest.wrapping_sub(sequence);
            if age < 127 {
                self.mask |= 1u128 << (127 - age);
            }
        }
    }
    fn packet(&mut self, payload: &[u8], now: u64) -> Vec<u8> {
        let data = Header {
            sequence: self.send,
            ack_sequence: self.newest.unwrap_or(0),
            ack_mask: self.mask,
            ack_bits: 127,
            single_message: true,
        }
        .encode(payload)
        .unwrap();
        self.send = self.send.wrapping_add(1);
        self.last = now;
        data
    }
}

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let port: u16 = std::env::args().nth(1).unwrap_or("19042".into()).parse()?;
    let socket = UdpSocket::bind((std::net::Ipv4Addr::LOCALHOST, port))?;
    socket.set_read_timeout(Some(Duration::from_millis(50)))?;
    let mut peers = BTreeMap::<std::net::SocketAddr, Peer>::new();
    let start = Instant::now();
    let mut packet = [0; 513];
    eprintln!("Lobby diagnostic on {}", socket.local_addr()?);
    while start.elapsed() < Duration::from_secs(240) {
        let now = start.elapsed().as_millis() as u64;
        match socket.recv_from(&mut packet) {
            Ok((n, address)) => {
                let (header, body) = Header::decode(&packet[..n])?;
                let frames =
                    wire::decode_frames(body, header.single_message, Direction::LobbyClient, 20)?;
                let peer = peers.entry(address).or_default();
                peer.observe(header.sequence);
                for frame in frames {
                    if frame.id != 0xfc {
                        eprintln!(
                            "Lobby {address}: {:02x} delivery {:?}, body {:02x?}",
                            frame.id, frame.unique_id, frame.body
                        );
                    }
                    if frame.id == 0x2e
                        && frame.body.len() == 5
                        && u32::from_le_bytes(frame.body[..4].try_into()?) == 0xa1
                    {
                        // Native sign-in response: state zero, no extra flag.
                        let reply = wire::encode_frame(
                            Frame {
                                id: 0x80,
                                unique_id: Some(0),
                                fragment: None,
                                body: &[0, 0],
                            },
                            true,
                            Direction::LobbyServer,
                            20,
                        )?;
                        socket.send_to(&peer.packet(&reply, now), address)?;
                        peer.signed = true;
                    } else if frame.id == 0xfa {
                        socket.send_to(&peer.packet(&[0xfb], now), address)?;
                    }
                }
                socket.send_to(&peer.packet(&[0xfc], now), address)?;
            }
            Err(e)
                if matches!(
                    e.kind(),
                    std::io::ErrorKind::WouldBlock | std::io::ErrorKind::TimedOut
                ) => {}
            Err(e) => return Err(e.into()),
        }
        for (address, peer) in &mut peers {
            if peer.signed && now.saturating_sub(peer.last) >= 500 {
                socket.send_to(&peer.packet(&[0xfc], now), address)?;
            }
        }
    }
    Ok(())
}

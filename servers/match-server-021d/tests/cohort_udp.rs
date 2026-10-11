// SPDX-License-Identifier: GPL-3.0-or-later
//! Executable/socket/transport integration, not an engine gameplay test.
use match_server_021d::{
    transport::Endpoint,
    wire::{self, Direction},
};
use std::{
    collections::BTreeMap,
    fs,
    net::UdpSocket,
    path::PathBuf,
    process::{Child, Command, Stdio},
    thread,
    time::{Duration, Instant, SystemTime, UNIX_EPOCH},
};

struct Process {
    child: Child,
    sessions: PathBuf,
}
impl Drop for Process {
    fn drop(&mut self) {
        let _ = self.child.kill();
        let _ = self.child.wait();
        let _ = fs::remove_file(&self.sessions);
    }
}
struct Client {
    socket: UdpSocket,
    endpoint: Endpoint,
    requested: bool,
    loaded: bool,
    restored: bool,
    activations: BTreeMap<u8, u32>,
    clock: Option<Vec<u8>>,
    clock_wall: u64,
    last_clock_report: u64,
    slews: Vec<i16>,
    inputs: Vec<Vec<u8>>,
    left: bool,
}
fn snapshot(slot: u8) -> Vec<u8> {
    // Structurally valid empty state with one opaque block; never used in a
    // game client. Different candidates prove the server selects ONE baseline.
    [
        vec![0; 4],
        vec![0, 0],
        600u16.to_le_bytes().to_vec(),
        vec![slot; 600],
        vec![0; 4],
    ]
    .concat()
}
fn time(b: &[u8]) -> u32 {
    u32::from_le_bytes(b.try_into().unwrap())
}

#[test]
fn two_udp_clients_share_state_recover_lost_fragment_relay_and_leave() {
    run_cohort(false, false, false, false);
}

#[test]
fn malformed_input_disconnects_its_peer_without_stopping_the_server() {
    run_cohort(true, false, false, false);
}

#[test]
fn time_limit_sends_local_finish_to_both_clients_even_after_packet_loss() {
    run_cohort(false, true, false, false);
}

#[test]
fn late_udp_join_recovers_a_lost_populated_state_fragment_and_then_relays() {
    run_cohort(false, false, true, false);
}

#[test]
fn srp1_late_join_recovers_a_lost_fragment_and_uses_stock_leave() {
    run_cohort(false, false, true, true);
}

#[test]
fn srp1_final_state_requests_and_timed_finish_use_the_selected_dialect() {
    run_cohort(false, true, false, true);
}

#[test]
fn srp1_rejects_community_uploads_without_stopping_the_other_peer() {
    run_cohort(true, false, false, true);
}

#[test]
fn clock_drift_uses_signed_slews_and_retries_a_lost_correction_without_reset() {
    run_cohort_options(false, false, false, true, true);
}

fn send_upload(client: &mut Client, body: &[u8], now: u64, srp1: bool) {
    if srp1 {
        client
            .endpoint
            .send(0x48, &[b"SRP1".as_slice(), body].concat(), now)
            .unwrap();
    } else {
        client.endpoint.send(0x47, body, now).unwrap();
    }
}

fn run_cohort(malformed: bool, finish: bool, late: bool, srp1: bool) {
    run_cohort_options(malformed, finish, late, srp1, false);
}

fn run_cohort_options(malformed: bool, finish: bool, late: bool, srp1: bool, drift: bool) {
    // Reserve an ephemeral loopback port; release immediately before launch.
    let reservation = UdpSocket::bind("127.0.0.1:0").unwrap();
    let addr = reservation.local_addr().unwrap();
    let sessions = std::env::temp_dir().join(format!(
        "srp-cohort-{}-{}.sessions",
        std::process::id(),
        SystemTime::now()
            .duration_since(UNIX_EPOCH)
            .unwrap()
            .as_nanos()
    ));
    fs::write(&sessions, "101 0\n202 1\n").unwrap();
    drop(reservation);
    let child = Command::new(env!("CARGO_BIN_EXE_match-server-021d"))
        .args([
            sessions.to_str().unwrap(),
            &addr.port().to_string(),
            if late { "1" } else { "2" },
            if finish { "1" } else { "600" },
            "--protocol",
            if srp1 { "srp1" } else { "community" },
        ])
        .stdout(Stdio::null())
        .stderr(Stdio::inherit())
        .spawn()
        .unwrap();
    let mut process = Process { child, sessions };
    let mut clients: Vec<_> = (0..2)
        .map(|slot| {
            let socket = UdpSocket::bind("127.0.0.1:0").unwrap();
            socket.set_nonblocking(true).unwrap();
            let mut endpoint = Endpoint::new(Direction::ClientToServer);
            let session = if slot == 0 { 101u32 } else { 202 };
            endpoint
                .send(0x40, &[session.to_le_bytes().to_vec(), vec![0]].concat(), 0)
                .unwrap();
            Client {
                socket,
                endpoint,
                requested: false,
                loaded: false,
                restored: false,
                activations: BTreeMap::new(),
                clock: None,
                clock_wall: 0,
                last_clock_report: 0,
                slews: vec![],
                inputs: vec![],
                left: false,
            }
        })
        .collect();
    let start = Instant::now();
    let mut dropped = false;
    let mut sent_inputs = false;
    let mut sent_leave = false;
    let mut dropped_finish = false;
    let mut dropped_slew = false;
    let mut snapshot_requests = 0;
    let mut buffer = [0; 1024];
    loop {
        assert!(
            start.elapsed()
                < Duration::from_secs(if finish {
                    30
                } else if drift {
                    15
                } else {
                    8
                }),
            "cohort test timed out"
        );
        assert!(
            process.child.try_wait().unwrap().is_none(),
            "server terminated"
        );
        let now = start.elapsed().as_millis() as u64;
        for (slot, client) in clients.iter_mut().enumerate() {
            if late && slot == 1 && now < 1500 {
                continue;
            }
            loop {
                let size = match client.socket.recv_from(&mut buffer) {
                    Ok((size, source)) => {
                        assert_eq!(source, addr);
                        size
                    }
                    Err(e) if e.kind() == std::io::ErrorKind::WouldBlock => break,
                    Err(e) => panic!("recv: {e}"),
                };
                let packet = &buffer[..size];
                let (_, frames) = wire::decode(Direction::ServerToClient, packet).unwrap();
                if slot == 1 && !dropped && frames.iter().any(|f| f.opcode() == 0x53) {
                    dropped = true;
                    continue;
                }
                if finish
                    && slot == 1
                    && !dropped_finish
                    && frames.iter().any(|f| f.opcode() == 0x57)
                {
                    dropped_finish = true;
                    continue;
                }
                if drift && slot == 1 && !dropped_slew && frames.iter().any(|f| f.opcode() == 0x55)
                {
                    dropped_slew = true;
                    continue;
                }
                for message in client.endpoint.receive(packet, now).unwrap() {
                    let b = &message.body;
                    if message.opcode == 0x59 {
                        snapshot_requests += 1;
                        assert_eq!(
                            b.as_slice(),
                            if srp1 {
                                b"SRP1\x01".as_slice()
                            } else {
                                b"".as_slice()
                            }
                        );
                    }
                    match message.opcode {
                        0x50 if !client.requested => {
                            client.requested = true;
                            client
                                .endpoint
                                .send(
                                    0x41,
                                    &if slot == 0 { 101u32 } else { 202 }.to_le_bytes(),
                                    now,
                                )
                                .unwrap();
                        }
                        0x51 if !client.loaded => {
                            client.loaded = true;
                            client.endpoint.send(0x42, &[], now).unwrap();
                            let body = snapshot(slot as u8);
                            for (index, fragment) in body.chunks(480).enumerate() {
                                let upload = [
                                    50u32.to_le_bytes().to_vec(),
                                    ((index * 480) as u16).to_le_bytes().to_vec(),
                                    (body.len() as u16).to_le_bytes().to_vec(),
                                    fragment.to_vec(),
                                ]
                                .concat();
                                send_upload(client, &upload, now, srp1);
                            }
                        }
                        0x52 => {
                            assert!(
                                !drift || client.clock.is_none(),
                                "drift correction reset the world"
                            );
                            client.clock = Some(b.clone());
                            client.clock_wall = now;
                            client.endpoint.send(0x43, b, now).unwrap();
                        }
                        0x53 => {
                            if late && slot == 1 {
                                assert!(time(&b[..4]) > 50);
                                assert_eq!(time(&b[4..8]), 1); // Existing player.
                                assert_eq!(b[8..12], [1, 0, 42, 0]);
                            } else {
                                assert_eq!(time(&b[..4]), 50);
                                assert_eq!(b[4..], snapshot(0));
                            }
                            client.restored = true;
                        }
                        0x56 => {
                            assert!(client.restored, "activation before baseline");
                            assert!(time(&b[1..]) % 50 == 0);
                            client.activations.insert(b[0], time(&b[1..]));
                        }
                        0x54 => {
                            assert_ne!(b[0], slot as u8, "unexpected sender echo");
                            client.inputs.push(b.clone());
                        }
                        0x55 if drift => {
                            assert_eq!(b.len(), 2);
                            let offset = i16::from_le_bytes(b[..2].try_into().unwrap());
                            assert_eq!(offset, if slot == 0 { 100 } else { -100 });
                            client.slews.push(offset);
                        }
                        0x57 => {
                            assert_eq!(b[0], if finish { slot as u8 } else { 0 });
                            if finish {
                                // 10-second countdown, 1-second match, then
                                // bounded 10-second final-state fallback.
                                let deadline = client.activations[&(slot as u8)] + 21000;
                                assert!((deadline..deadline + 500).contains(&time(&b[1..])));
                                assert_eq!(time(&b[1..]) % 50, 0);
                                assert!(now >= 21000);
                            }
                            client.left = true;
                        }
                        0x59 if late && slot == 0 && client.activations.contains_key(&0) => {
                            let game = time(&client.clock.as_ref().unwrap()[4..])
                                + (now - client.clock_wall) as u32;
                            let at = game.saturating_sub(100) / 50 * 50;
                            if at >= client.activations[&0] {
                                // Opaque synthetic state; boundary validation only.
                                let body = [
                                    vec![1, 0, 0, 0, 1, 0, 42, 0],
                                    vec![0; 2],
                                    600u16.to_le_bytes().to_vec(),
                                    vec![0; 600],
                                    vec![0; 4],
                                ]
                                .concat();
                                let crc = match_server_021d::snapshot::crc32(&body);
                                client
                                    .endpoint
                                    .send(
                                        0x46,
                                        &[at.to_le_bytes(), crc.to_le_bytes()].concat(),
                                        now,
                                    )
                                    .unwrap();
                                for (index, fragment) in body.chunks(480).enumerate() {
                                    let upload = [
                                        at.to_le_bytes().to_vec(),
                                        ((index * 480) as u16).to_le_bytes().to_vec(),
                                        (body.len() as u16).to_le_bytes().to_vec(),
                                        fragment.to_vec(),
                                    ]
                                    .concat();
                                    send_upload(client, &upload, now, srp1);
                                }
                            }
                        }
                        1 | 2 | 0x50 | 0x59 => {}
                        opcode => panic!("unexpected server opcode {opcode:02x}"),
                    }
                }
            }
            if drift && client.restored && now >= client.last_clock_report + 1000 {
                let game =
                    time(&client.clock.as_ref().unwrap()[4..]) + (now - client.clock_wall) as u32;
                let reported = if slot == 0 { game - 300 } else { game + 300 };
                client
                    .endpoint
                    .send(0x44, &reported.to_le_bytes(), now)
                    .unwrap();
                client.last_clock_report = now;
            }
            for packet in client.endpoint.poll(now).unwrap() {
                client.socket.send_to(&packet, addr).unwrap();
            }
        }
        if !sent_inputs
            && clients.iter().enumerate().all(|(slot, c)| {
                if late {
                    c.activations.contains_key(&(slot as u8))
                } else {
                    c.activations.len() == 2
                }
            })
        {
            assert!(dropped);
            let activation = clients[1].activations[&1];
            if late {
                assert_ne!(clients[0].clock, clients[1].clock);
                assert!(activation > clients[0].activations[&0]);
            } else {
                assert_eq!(clients[0].clock, clients[1].clock);
                assert_eq!(clients[0].activations, clients[1].activations);
                assert_eq!(activation, clients[0].activations[&0]);
            }
            for (slot, client) in clients.iter_mut().enumerate() {
                let input = [
                    0.25f32.to_le_bytes(),
                    (-0.5f32).to_le_bytes(),
                    (slot as u32 + 1).to_le_bytes(),
                    activation.to_le_bytes(),
                ]
                .concat();
                client.endpoint.send(0x45, &input, now).unwrap();
            }
            sent_inputs = true;
        }
        if !finish
            && sent_inputs
            && !sent_leave
            && clients.iter().all(|c| !c.inputs.is_empty())
            && (!drift || clients.iter().all(|c| c.slews.len() == 1))
        {
            if drift {
                assert!(dropped_slew);
            }
            for (slot, client) in clients.iter().enumerate() {
                assert_eq!(client.inputs[0][0], 1 - slot as u8);
                assert_eq!(time(&client.inputs[0][9..13]), 2 - slot as u32);
            }
            if malformed && srp1 {
                // Community upload opcode/body is invalid for this server.
                clients[0]
                    .endpoint
                    .send(0x47, &[50, 0, 0, 0, 0, 0, 1, 0, 0], now)
                    .unwrap();
            } else if malformed {
                let mut invalid = [0; 16];
                invalid[..4].copy_from_slice(&f32::NAN.to_le_bytes());
                clients[0].endpoint.send(0x45, &invalid, now).unwrap();
            } else if srp1 {
                let at = clients[0].activations[&0].to_le_bytes();
                clients[0].endpoint.send(0x47, &at, now).unwrap();
            } else {
                clients[0].endpoint.send(0, &[], now).unwrap();
            }
            sent_leave = true;
        }
        if finish && clients.iter().all(|c| c.left) {
            assert!(dropped_finish);
            assert!(snapshot_requests > 0);
            break;
        }
        if !finish && clients[1].left {
            if late {
                assert!(snapshot_requests > 0);
            }
            break;
        }
        thread::sleep(Duration::from_millis(2));
    }
}

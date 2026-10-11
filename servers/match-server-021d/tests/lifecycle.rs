// SPDX-License-Identifier: GPL-3.0-or-later
//! The lobby's local status interface observes the real executable lifecycle.
use match_server_021d::{transport::Endpoint, wire::Direction};
use std::{
    fs,
    net::UdpSocket,
    os::unix::net::UnixDatagram,
    path::PathBuf,
    process::{Child, Command, Stdio},
    thread,
    time::{Duration, Instant, SystemTime, UNIX_EPOCH},
};

struct Process {
    child: Child,
    directory: PathBuf,
}
impl Drop for Process {
    fn drop(&mut self) {
        let _ = self.child.kill();
        let _ = self.child.wait();
        let _ = fs::remove_dir_all(&self.directory);
    }
}

fn query(control: &UnixDatagram) -> Vec<String> {
    control.send(b"status 123456789").unwrap();
    let mut buffer = [0; 256];
    let size = control.recv(&mut buffer).unwrap();
    let fields: Vec<_> = std::str::from_utf8(&buffer[..size])
        .unwrap()
        .split_whitespace()
        .map(str::to_owned)
        .collect();
    assert_eq!(fields.len(), 6);
    assert_eq!(&fields[..2], &["v1", "123456789"]);
    assert!(u128::from_str_radix(&fields[2], 16).unwrap() > 0);
    fields
}

#[test]
fn local_status_tracks_occupied_slots_and_advances_generation_when_cohort_empties() {
    let directory = std::env::temp_dir().join(format!(
        "srp-lifecycle-{}-{}",
        std::process::id(),
        SystemTime::now()
            .duration_since(UNIX_EPOCH)
            .unwrap()
            .as_nanos()
    ));
    fs::create_dir(&directory).unwrap();
    let sessions = directory.join("sessions");
    let control_path = directory.join("control");
    fs::write(&sessions, "101 0\n").unwrap();
    let reservation = UdpSocket::bind("127.0.0.1:0").unwrap();
    let address = reservation.local_addr().unwrap();
    drop(reservation);
    let child = Command::new(env!("CARGO_BIN_EXE_match-server-021d"))
        .args([
            sessions.to_str().unwrap(),
            &address.port().to_string(),
            "1",
            "600",
            control_path.to_str().unwrap(),
        ])
        .stdout(Stdio::null())
        .stderr(Stdio::inherit())
        .spawn()
        .unwrap();
    let mut process = Process { child, directory };
    let start = Instant::now();
    while !control_path.exists() {
        assert!(process.child.try_wait().unwrap().is_none());
        assert!(start.elapsed() < Duration::from_secs(2));
        thread::sleep(Duration::from_millis(5));
    }
    let control = UnixDatagram::bind(process.directory.join("reply")).unwrap();
    control
        .set_read_timeout(Some(Duration::from_secs(1)))
        .unwrap();
    control.connect(&control_path).unwrap();
    let initial = query(&control);
    assert_eq!(&initial[3..], &["1", "waiting", "0"]);

    let client = UdpSocket::bind("127.0.0.1:0").unwrap();
    client
        .set_read_timeout(Some(Duration::from_secs(1)))
        .unwrap();
    let mut endpoint = Endpoint::new(Direction::ClientToServer);
    endpoint.send(0x40, &[101, 0, 0, 0, 0], 0).unwrap();
    for packet in endpoint.poll(0).unwrap() {
        client.send_to(&packet, address).unwrap();
    }
    let mut buffer = [0; 1024];
    let size = client.recv(&mut buffer).unwrap();
    assert!(
        endpoint
            .receive(&buffer[..size], 10)
            .unwrap()
            .iter()
            .any(|m| m.opcode == 0x50)
    );
    let occupied = query(&control);
    assert_eq!(occupied[2], initial[2]);
    assert_eq!(&occupied[3..], &["1", "waiting", "1"]);

    endpoint.send(0, &[], 20).unwrap();
    for packet in endpoint.poll(20).unwrap() {
        client.send_to(&packet, address).unwrap();
    }
    loop {
        let empty = query(&control);
        if empty[5] == "0" {
            assert_eq!(empty[2], initial[2]);
            assert_eq!(&empty[3..], &["2", "waiting", "0"]);
            break;
        }
        assert!(start.elapsed() < Duration::from_secs(3));
        thread::sleep(Duration::from_millis(5));
    }
}

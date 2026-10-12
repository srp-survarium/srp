// SPDX-License-Identifier: GPL-3.0-or-later

#[cfg(feature = "lzma")]
use srp_packet_guard as guard;
use srp_packet_guard::{
    Error, Players,
    application::{self, ItemKind, Metadata},
    login, state,
    transport::{self, Channel, Fragment, Frame, Opcode},
};

fn hex(s: &str) -> Vec<u8> {
    let s = s.trim();
    assert_eq!(s.len() % 2, 0);
    (0..s.len())
        .step_by(2)
        .map(|i| u8::from_str_radix(&s[i..i + 2], 16).unwrap())
        .collect()
}
fn rows(s: &str) -> impl Iterator<Item = Vec<&str>> {
    s.lines()
        .filter(|s| !s.is_empty() && !s.starts_with('#'))
        .map(|s| s.split_whitespace().collect())
}
fn options() -> Vec<u8> {
    hex(rows(include_str!("../fixtures/options.hex"))
        .next()
        .unwrap()[0])
}
fn snapshots() -> Vec<Vec<u8>> {
    [
        include_str!("../fixtures/school-initial.hex"),
        include_str!("../fixtures/school-live.hex"),
    ]
    .into_iter()
    .map(|s| [vec![0; 4], hex(rows(s).next().unwrap()[0])].concat())
    .collect()
}
struct LocalMetadata;
impl Metadata for LocalMetadata {
    fn item_kind(&self, id: u16) -> Option<ItemKind> {
        match id {
            3 => Some(ItemKind::NonStackable),
            7 => Some(ItemKind::Stackable),
            _ => None,
        }
    }
    fn map_exists(&self, id: u8) -> bool {
        id == 61
    }
}

#[test]
fn login_stage_sizes_segmentation_and_coalescing() {
    use login::Stage::{Name, Password};
    let success = [8, 1, 0, 0, 0, 127, 0, 0, 1, 210, 4];
    let mut queue = [0; 14];
    queue[0] = 0x25;
    assert_eq!(login::verify(Name, &[11]), Ok(()));
    for reply in [&success[..], &queue] {
        assert_eq!(login::verify(Password, reply), Ok(()));
        for n in 0..reply.len() {
            assert!(login::verify(Password, &reply[..n]).is_err());
        }
        for split in 0..reply.len() {
            let mut stream = login::Accumulator::new();
            let first = stream.feed(Password, &reply[..split]).unwrap();
            assert_eq!(first.consumed, split);
            assert!(first.response.is_none());
            let second = stream.feed(Password, &reply[split..]).unwrap();
            assert_eq!(second.consumed, reply.len() - split);
            assert_eq!(second.response, Some(reply));
        }
    }
    let mut stream = login::Accumulator::new();
    for (i, value) in success.iter().enumerate() {
        let progress = stream.feed(Password, &[*value]).unwrap();
        assert_eq!(progress.consumed, 1);
        assert_eq!(progress.response.is_some(), i == success.len() - 1);
    }
    let both = [success, success].concat();
    assert_eq!(
        stream.feed(Password, &both).unwrap().consumed,
        success.len()
    );
    assert!(login::verify(Password, &both).is_err());
    assert_eq!(login::verify(Name, &[255]), Err(Error::Unsupported));
}

#[test]
fn native_headers_and_whole_bundle_validation() {
    let mut count = 0;
    for row in rows(include_str!("../fixtures/header.tsv")) {
        let bytes = hex(row[0]);
        let h = transport::header(&bytes).unwrap();
        assert_eq!(h.sequence, row[1].parse::<u8>().unwrap());
        assert_eq!(h.acknowledgement, row[2].parse::<u8>().unwrap());
        assert_eq!(h.single, row[4] == "1");
        assert_eq!(h.payload, [254]);
        count += 1;
    }
    assert_eq!(count, 416);
    let players = Some(Players::new(2).unwrap());
    let bundle = [0xe3, 1, 0, 2, 0, 0xe4, 7, 2, 1, 2];
    assert_eq!(
        transport::frames(&bundle, false, Channel::Match, players)
            .unwrap()
            .count(),
        2
    );
    assert!(transport::frames(&bundle[..9], false, Channel::Match, players).is_err());
    assert!(transport::frames(&[0xfe], true, Channel::Match, players).is_err());
    assert!(transport::frames(&[0xfa], true, Channel::Match, players).is_ok());
    for bad in [
        &[0xe4, 1, 255, 1, 0, 42][..],
        &[0xed, 1, 0x80, 0, 0, 0, 0, 0, 0, 0, 0],
        &[255, 0xe8, 0, 0, 0, 1],
    ] {
        assert!(transport::frames(bad, false, Channel::Match, players).is_err());
    }
    let mut overflow = [128; 25];
    overflow[2] = 128;
    assert!(transport::header(&overflow).is_err());
    for n in 0..4 {
        assert!(transport::header(&[0; 4][..n]).is_err());
    }
}

fn fragment(index: u8, count: Option<u8>, bytes: &[u8]) -> Frame<'_> {
    Frame {
        opcode: Opcode::new(0xe8, Channel::Match).unwrap(),
        delivery: Some(7),
        fragment: Some(Fragment { index, count }),
        body: bytes,
    }
}
#[test]
fn fragments_bound_identity_duplicates_reordering_expiry_and_maximum_count() {
    let mut s = Box::new(transport::Reassembly::new());
    assert!(s.feed(fragment(1, None, b"def"), 0).unwrap().is_none());
    assert!(s.feed(fragment(0, Some(3), b"abc"), 1).unwrap().is_none());
    assert!(s.feed(fragment(0, Some(3), b"abc"), 2).unwrap().is_none());
    assert!(s.feed(fragment(2, None, b"ghi"), 3).unwrap().is_none());
    let complete = s.feed(fragment(1, None, b"def"), 4).unwrap().unwrap();
    assert_eq!(complete.body, b"abcdefghi");
    assert!(complete.fragment.is_none());
    s.reset();
    s.feed(fragment(0, Some(2), b"abc"), 0xfffffff0).unwrap();
    assert!(matches!(
        s.feed(fragment(1, None, b"def"), 0x1380),
        Err(Error::Expired)
    ));
    s.feed(fragment(0, Some(2), b"abc"), 0).unwrap();
    assert!(matches!(
        s.feed(fragment(0, Some(2), b"bad"), 1),
        Err(Error::FragmentConflict)
    ));
    for i in 0..255u8 {
        let frame = fragment(i, if i == 0 { Some(255) } else { None }, b"abc");
        let complete = s.feed(frame, u32::from(i)).unwrap();
        if i < 254 {
            assert!(complete.is_none());
        } else {
            assert_eq!(complete.unwrap().body.len(), 765);
        }
    }
    assert!(s.feed(fragment(255, None, b"x"), 0).is_err());
    assert!(s.feed(fragment(0, Some(0), b"x"), 0).is_err());
}

#[test]
fn options_native_reference_all_prefixes_and_trailing_bytes() {
    let mut bytes = options();
    assert_eq!(
        application::options(&bytes, &LocalMetadata),
        Players::new(1)
    );
    for n in 0..bytes.len() {
        assert!(
            application::options(&bytes[..n], &LocalMetadata).is_err(),
            "prefix {n}"
        );
    }
    bytes.push(0);
    assert!(application::options(&bytes, &LocalMetadata).is_err());
    bytes.pop();
    bytes[1] = 64;
    assert!(application::options(&bytes, &LocalMetadata).is_err());
}

#[test]
fn snapshot_envelope_does_not_claim_deep_validation() {
    let players = Players::new(2).unwrap();
    for bytes in snapshots() {
        assert_eq!(state::envelope(&bytes, players), Ok(()));
        assert_eq!(
            state::deep(&bytes, players, &state::Reject),
            Err(Error::Unsupported)
        );
        for n in 0..bytes.len() {
            assert!(state::envelope(&bytes[..n], players).is_err(), "prefix {n}");
        }
    }
    let mut count = 0;
    for row in rows(include_str!("../fixtures/animations.tsv")) {
        let animation = hex(row[0]);
        let mut bytes = vec![0; 11];
        bytes[4] = 1;
        bytes[10] = 255;
        bytes.extend_from_slice(&animation);
        bytes.extend([0; 12]);
        assert_eq!(
            state::envelope(&bytes, players),
            Ok(()),
            "animation {count}"
        );
        for n in 0..animation.len() {
            assert!(state::envelope(&bytes[..11 + n], players).is_err());
        }
        count += 1;
    }
    assert_eq!(count, 253);
    let mut bad = [0; 20];
    bad[4] = 2;
    assert_eq!(
        state::envelope(&bad, Players::new(1).unwrap()),
        Err(Error::Invalid)
    );
}

#[test]
fn squad_limits_and_unknown_lobby_schemas() {
    let squad = [
        1, 0, 0, 0, 1, 0, 7, 0, 0, 0, 8, 0, 0, 0, 9, 0, 0, 0, 5, b'A', b'l', b'i', b'c', b'e', 1,
        0, 1, 10, 0, 0, 0,
    ];
    assert_eq!(
        application::lobby(0xa1, &squad, &application::Reject),
        Ok(())
    );
    for n in 0..squad.len() {
        assert!(application::lobby(0xa1, &squad[..n], &application::Reject).is_err());
    }
    assert_eq!(
        application::lobby(0xa1, &[0; 4], &application::Reject),
        Ok(())
    );
    assert_eq!(
        application::lobby(0x80, &[0; 2], &application::Reject),
        Ok(())
    );
    assert_eq!(
        application::lobby(0x81, &[0], &application::Reject),
        Err(Error::Unsupported)
    );
    let mut bad = squad;
    bad[4] = 4;
    assert!(application::lobby(0xa1, &bad, &application::Reject).is_err());
    bad = squad;
    bad[5] = 1;
    assert!(application::lobby(0xa1, &bad, &application::Reject).is_err());
}

#[cfg(feature = "lzma")]
#[test]
fn rust_decoder_matches_native_vectors_and_enforces_stream_end_and_limit() {
    let mut out = vec![0; guard::MAX_OPTIONS];
    let mut count = 0;
    for row in rows(include_str!("../fixtures/lzma.tsv")) {
        let plain = hex(row[0]).repeat(row[1].parse().unwrap());
        let mut encoded = hex(row[2]);
        assert_eq!(
            guard::compression::decode(&encoded, &mut out[..plain.len()]),
            Ok(plain.len())
        );
        assert_eq!(&out[..plain.len()], &plain);
        assert!(guard::compression::decode(&encoded, &mut out[..plain.len() - 1]).is_err());
        for n in 0..encoded.len() {
            assert!(guard::compression::decode(&encoded[..n], &mut out).is_err());
        }
        encoded.push(0);
        assert!(guard::compression::decode(&encoded, &mut out).is_err());
        count += 1;
    }
    assert_eq!(count, 5);
    let oversized = hex(rows(include_str!("../fixtures/oversized.lzma.hex"))
        .next()
        .unwrap()[0]);
    assert!(guard::compression::decode(&oversized, &mut out).is_err());
}

#[cfg(feature = "lzma")]
#[test]
fn match_setup_checks_local_slot_and_requires_state_action_schemas() {
    let mut scratch = vec![0; guard::MAX_OPTIONS];
    let mut policy = application::Policy {
        players: None,
        metadata: &LocalMetadata,
        messages: &application::Reject,
        state: &state::Reject,
        decoder: &application::Lzma2,
    };
    let mut info = hex(rows(include_str!("../fixtures/static-info.hex"))
        .next()
        .unwrap()[0]);
    assert_eq!(
        application::match_message(0xe4, &info, &policy, &mut scratch),
        Ok(Some(Players::new(1).unwrap()))
    );
    for n in 0..info.len() {
        assert!(application::match_message(0xe4, &info[..n], &policy, &mut scratch).is_err());
    }
    info[0] = 20;
    assert_eq!(
        application::match_message(0xe4, &info, &policy, &mut scratch),
        Err(Error::Invalid)
    );
    policy.players = Some(Players::new(2).unwrap());
    let state = [vec![1, 0], snapshots()[0].clone()].concat();
    assert_eq!(
        application::match_message(0xe8, &state, &policy, &mut scratch),
        Err(Error::Unsupported)
    );
    for op in [0xe3, 0xf6, 0xf7] {
        assert_eq!(
            application::match_message(op, &[0; 4], &policy, &mut scratch),
            Err(Error::Unsupported)
        );
    }
}

fn exercise(p: &[u8]) {
    let players = Players::new(2).unwrap();
    let _ = transport::header(p);
    let _ = transport::frames(p, true, Channel::Match, Some(players));
    let _ = transport::frames(p, false, Channel::Match, Some(Players::new(20).unwrap()));
    let _ = transport::frames(p, false, Channel::Lobby, None);
    let _ = application::options(p, &LocalMetadata);
    let _ = state::envelope(p, players);
    let _ = login::verify(login::Stage::Password, p);
    let _ = application::lobby(0xa1, p, &application::Reject);
}
fn random(value: &mut u32) -> u32 {
    *value ^= *value << 13;
    *value ^= *value >> 17;
    *value ^= *value << 5;
    *value
}
#[test]
fn malformed_and_mutated_corpus_is_bounded_without_panics() {
    let mut seed = 0x37116;
    for _ in 0..100_000 {
        let mut bytes = vec![0; random(&mut seed) as usize % 1025];
        for byte in &mut bytes {
            *byte = random(&mut seed) as u8;
        }
        exercise(&bytes);
    }
    let seeds = [options(), snapshots()[1].clone()];
    for i in 0..20_000 {
        let mut bytes = seeds[i % 2].clone();
        for _ in 0..4 {
            let index = random(&mut seed) as usize % bytes.len();
            bytes[index] = random(&mut seed) as u8;
        }
        exercise(&bytes);
    }
    #[cfg(feature = "lzma")]
    for _ in 0..2_000 {
        let mut bytes = vec![0; random(&mut seed) as usize % 256];
        for byte in &mut bytes {
            *byte = random(&mut seed) as u8;
        }
        let _ = guard::compression::decode(&bytes, &mut [0; 4096]);
    }
}

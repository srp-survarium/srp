#![feature(iter_intersperse)]
#![feature(generic_atomic)]

mod game;
mod match_connection;
mod message;
mod sequence_number;
mod utils;

use std::sync::mpsc;
use std::thread::sleep;
use std::time::{Duration, Instant};

use crate::game::Game;
use crate::match_connection::MatchConnection;
use vostok::config;

fn main() {
    loop {
        println!("\n\nStarting a match server");
        _ = std::panic::catch_unwind(run_match_server);
    }
}

fn run_match_server() {
    let (client_game_message_tx, client_game_message_rx) =
        mpsc::channel::<message::ClientGameMessageKind>();
    let (server_game_message_tx, server_game_message_rx) =
        mpsc::channel::<message::ServerGameMessageKind>();

    let mut connection: MatchConnection = MatchConnection::wait_for_game_start(
        config::match_server::ADDRESS,
        config::match_server::PORT,
        client_game_message_tx,
        server_game_message_rx,
    );
    let mut game: Game = Game::new(client_game_message_rx, server_game_message_tx);

    const FRAMES_PER_SECOND: u64 = 120;
    const FRAME_DURATION: Duration = Duration::from_millis(1000 / FRAMES_PER_SECOND);

    loop {
        let frame_start = Instant::now();

        connection.read_incoming_packets();
        game.tick();
        connection.write_outgoing_packets();

        let frame_end = Instant::now();

        let frame_duration = frame_end - frame_start;
        sleep(FRAME_DURATION.saturating_sub(frame_duration));
    }
}

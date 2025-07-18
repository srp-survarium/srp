mod game_server;
mod match_server;
mod message;
mod sequence_number;

use crate::match_server::MatchConnection;
use vostok::config;

fn main() {
    let connection =
        MatchConnection::run(config::match_server::ADDRESS, config::match_server::PORT);
    connection.handle.join().unwrap();
}

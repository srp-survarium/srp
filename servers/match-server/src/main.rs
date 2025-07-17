#![feature(slice_split_once)]

mod client_message;
mod match_server;
mod player_profile;
mod sequence_number;
mod server_message;

use crate::match_server::MatchConnection;

fn main() {
    let connection = MatchConnection::run(
        foundation::config::match_server::ADDRESS,
        foundation::config::match_server::PORT,
    );
    connection.handle.join().unwrap();
}

// NOTES:
// * UDP: 25100 port is open for something
// * happens after error log
//      game <ERROR>	[20:17:47:613]	[R] connect_to_game_server: 127.0.0.1: 1236 game time is 230496

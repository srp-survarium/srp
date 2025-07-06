mod lobby_server;
mod messaging_server;
mod network_client;

use network_client::{DeserializeError, NetworkClient, NetworkClientError};

use std::net::{TcpListener, TcpStream};
use std::sync::Arc;

const LOCAL_NAME: &str = "sheep";
const ANSWER_NAME: &str = "hello";

const _: () = {
    // `bytemuck` is used for serializing and deserializing messages.
    // And all messages are expected to use little endian.
    assert!(
        cfg!(target_endian = "little"),
        "This code only supports little-endian systems"
    );
};

fn main() -> std::io::Result<()> {
    let state = Arc::new(lobby_server::ServerState::new_dummy());

    let addr = format!(
        "{}:{}",
        foundation::lobby_server::ADDRESS,
        foundation::lobby_server::PORT
    );
    let listener = TcpListener::bind(&addr)?;

    for stream in listener.incoming() {
        std::thread::spawn({
            let stream = stream?;
            let state = state.clone();
            move || {
                _ = std::panic::catch_unwind(|| {
                    handle_connection(state, stream);
                });
            }
        });
    }

    Ok(())
}

pub fn handle_connection(lobby_server: Arc<lobby_server::ServerState>, stream: TcpStream) {
    // @TODO: Write messaging server properly, should get rid of `try_clone`
    let mut network_client = NetworkClient::new(stream.try_clone().unwrap());
    match network_client.peek::<lobby_server::client::Message>() {
        Ok(_) => lobby_server.run(network_client),
        Err(NetworkClientError::DeserializeError(DeserializeError::UnknownMessageType(_))) => {
            let buffer = network_client.get_read_buffer();
            messaging_server::handle(stream, buffer)
        }
        Err(error) => {
            panic!("{error}")
        }
    }
}

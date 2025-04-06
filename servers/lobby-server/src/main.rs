mod lobby_server;
mod messaging_server;
mod network_client;

use network_client::{DeserializeError, NetworkClient, NetworkClientError};

use std::net::{TcpListener, TcpStream};
use std::sync::Arc;

const LOCAL_NAME: &str = "sheep";
const ANSWER_NAME: &str = "hello";

pub struct ServerState {}

fn main() -> std::io::Result<()> {
    let state = Arc::new(ServerState::new());

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
                    state.handle_connection(stream);
                });
            }
        });
    }

    Ok(())
}

impl ServerState {
    pub fn new() -> Self {
        Self {}
    }

    pub fn handle_connection(self: Arc<Self>, stream: TcpStream) {
        // @TODO: Write messaging server properly, should get rid of `try_clone`
        let mut network_client = NetworkClient::new(stream.try_clone().unwrap());
        match network_client.peek::<lobby_server::client::Message>() {
            Ok(_) => lobby_server::run(self, network_client),
            Err(NetworkClientError::DeserializeError(DeserializeError::UnknownMessageType(_))) => {
                let buffer = network_client.get_read_buffer();
                messaging_server::handle(stream, buffer)
            }
            Err(error) => {
                panic!("{error}")
            }
        }
    }
}

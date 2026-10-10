// SPDX-License-Identifier: GPL-3.0-or-later
mod lobby_server;
mod messaging_server;

use session::SessionStore;
use vostok::config;
use vostok::network_client::{NetworkError, TcpClient};
use vostok::serde::DeserializeError;

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

pub fn run(store: Arc<SessionStore>) -> std::io::Result<()> {
    let state = Arc::new(lobby_server::ServerState::new_dummy());

    let listener = TcpListener::bind(config::get().lobby_server.bind_addr())?;

    for stream in listener.incoming() {
        let stream = match stream {
            Ok(stream) => stream,
            // A failed `accept` shouldn't take down the whole server.
            Err(error) => {
                log::error!("Failed to accept connection: {error}");
                continue;
            }
        };
        let state = state.clone();
        let store = store.clone();
        std::thread::spawn(move || {
            if std::panic::catch_unwind(|| handle_connection(store, state, stream)).is_err() {
                log::error!("Connection handler panicked; dropped the connection");
            }
        });
    }

    Ok(())
}

pub fn handle_connection(
    store: Arc<SessionStore>,
    lobby_server: Arc<lobby_server::ServerState>,
    stream: TcpStream,
) {
    // @TODO: Write messaging server properly, should get rid of `try_clone`
    let mut tcp_client = TcpClient::new(stream.try_clone().unwrap());
    match tcp_client.peek::<lobby_server::client::Message>() {
        Ok(_) => lobby_server.run(store, tcp_client),
        Err(NetworkError::DeserializeError(DeserializeError::UnknownMessageType(_))) => {
            let buffer = tcp_client.get_read_buffer();
            messaging_server::handle(stream, buffer)
        }
        Err(error) => {
            panic!("{error}")
        }
    }
}

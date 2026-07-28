use std::sync::Arc;

use actix_web::{
    get, middleware::Logger, web, App, HttpRequest, HttpResponse, HttpServer, Responder,
};

use session::SessionStore;
use vostok::config;

#[derive(serde::Deserialize, Debug)]
#[expect(dead_code)]
struct QueryParams {
    unused: Option<String>,
    r#type: Option<u8>,
    local_ip: Option<String>,
    login_ip: Option<String>,
}

#[get("/hello")]
async fn handle_request_lobby_server(
    _req: HttpRequest,
    query: web::Query<QueryParams>,
) -> impl Responder {
    log::error!("Received: {query:#?}");

    HttpResponse::Ok().body(config::get().lobby_server.public_addr())
}

/// Run the browser server to completion on the current thread (it owns a fresh
/// actix runtime), so it can be launched standalone or as one thread of the
/// unified `srp` binary. The session store is unused — the browser server only
/// hands the client the lobby address.
pub fn run(_store: Arc<SessionStore>) -> std::io::Result<()> {
    actix_web::rt::System::new().block_on(serve())
}

async fn serve() -> std::io::Result<()> {
    HttpServer::new(|| {
        App::new()
            .wrap(Logger::default())
            .service(handle_request_lobby_server)
    })
    .bind(config::get().browser_server.bind_addr())?
    .run()
    .await
}

use actix_web::{
    get, middleware::Logger, web, App, HttpRequest, HttpResponse, HttpServer, Responder,
};

use foundation::config;

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

    HttpResponse::Ok().body(format!(
        "{}:{}",
        config::lobby_server::ADDRESS,
        config::lobby_server::PORT
    ))
}

#[actix_web::main]
async fn main() -> std::io::Result<()> {
    env_logger::init();

    HttpServer::new(|| {
        App::new()
            .wrap(Logger::default())
            .service(handle_request_lobby_server)
    })
    .bind(format!(
        "{}:{}",
        config::browser_server::ADDRESS,
        config::browser_server::PORT
    ))?
    .run()
    .await
}

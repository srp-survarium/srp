pub mod network_client;
pub mod network_packet;
pub mod serde;

pub mod config {
    pub mod browser_server {
        pub const ADDRESS: &str = "127.0.0.1";
        pub const PORT: u16 = 80;
    }

    pub mod login_server {
        pub const ADDRESS: &str = "127.0.0.1";
        pub const PORT: u16 = 1234;
    }

    pub mod lobby_server {
        pub const ADDRESS: &str = "127.0.0.1";
        pub const PORT: u16 = 1235;
    }

    pub mod match_server {
        pub const ADDRESS: &str = "127.0.0.1";
        pub const PORT: u16 = 1236;
    }
}

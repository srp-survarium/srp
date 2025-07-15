void __thiscall vostok::network::tcp_packet_client::connect_impl(
        vostok::network::tcp_packet_client *this,
        const char *host,
        unsigned __int16 port)
{
  vostok::network_core::tcp_packet_client::connect(this->m_client, host, port);
}

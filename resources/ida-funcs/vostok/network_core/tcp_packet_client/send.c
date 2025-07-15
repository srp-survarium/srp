void __thiscall vostok::network_core::tcp_packet_client::send(
        vostok::network_core::tcp_packet_client *this,
        const vostok::network_core::tcp_packet *packet)
{
  vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>>::send(
    &this->m_packet_socket,
    (const vostok::network_core::tcp_packet *)&this->m_packet_socket,
    packet);
}

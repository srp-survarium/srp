void __thiscall vostok::network_core::tcp_packet_client::start_reading(vostok::network_core::tcp_packet_client *this)
{
  vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>>::start_receiving(&this->m_packet_socket);
}

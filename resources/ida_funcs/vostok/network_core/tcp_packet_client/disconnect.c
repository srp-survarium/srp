void __thiscall vostok::network_core::tcp_packet_client::disconnect(vostok::network_core::tcp_packet_client *this)
{
  vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>>::stop_receiving(&this->m_packet_socket);
  if ( this->m_socket.implementation.socket_ != -1 )
    vostok::network_core::tcp_packet_client::close_connection(this);
}

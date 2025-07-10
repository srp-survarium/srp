void __thiscall vostok::network_core::udp_match_client::connect(
        vostok::network_core::udp_match_client *this,
        char *host,
        unsigned __int16 port,
        vostok::network_core::udp_match_packet *packet,
        survarium::game_camera *current_time_in_ms)
{
  boost::asio::ip::address *addr; // [esp+10h] [ebp-514h]
  boost::asio::ip::address result; // [esp+4CCh] [ebp-58h] BYREF
  boost::asio::ip::detail::endpoint v8; // [esp+4E8h] [ebp-3Ch] BYREF
  boost::asio::ip::basic_endpoint<boost::asio::ip::udp> endpoint; // [esp+504h] [ebp-20h] BYREF
  boost::asio::ip::udp protocol; // [esp+520h] [ebp-4h] BYREF

  if ( this->m_socket.implementation.socket_ != -1 )
    boost::asio::basic_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>::close(&this->m_socket);
  protocol.family_ = 2;
  boost::asio::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp>>::open(
    &this->m_socket,
    &protocol);
  *(_DWORD *)&endpoint.impl_.data_.base.sa_family = 2;
  memset(&endpoint.impl_.data_.v6.sin6_flowinfo, 0, 24);
  boost::asio::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp>>::bind(
    &this->m_socket,
    &endpoint);
  addr = boost::asio::ip::address::from_string(&result, host);
  boost::asio::ip::detail::endpoint::endpoint(&v8, addr, port);
  qmemcpy(&this->m_server_endpoint, &v8, sizeof(this->m_server_endpoint));
  vostok::network_core::udp_match_connection::connect(&this->m_connection, packet);
  vostok::network_core::udp_match_client::check_consistency(this);
  vostok::network_core::udp_match_client::start_receiving(this);
  vostok::network_core::udp_match_connection::send_queued_packets(&this->m_connection, current_time_in_ms);
  vostok::network_core::udp_match_client::check_consistency(this);
}

void __thiscall vostok::network_core::tcp_packet_client::close_connection(
        vostok::network_core::tcp_packet_client *this)
{
  boost::system::error_code ec; // [esp+1E4h] [ebp-8h] BYREF

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  ec.m_val = 0;
  ec.m_cat = boost::system::system_category();
  boost::asio::detail::socket_ops::shutdown(this->m_socket.implementation.socket_, 2, &ec);
  boost::asio::basic_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>::close((boost::asio::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp> > *)this);
  vostok::network_core::async_connector::reset(&this->m_async_connector);
}

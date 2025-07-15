void __thiscall vostok::network_core::tcp_packet_client::disconnect(vostok::network_core::tcp_packet_client *this)
{
  const boost::system::error_category *v2; // eax
  boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > *m_socket; // ecx
  boost::asio::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp> > *v4; // ecx
  boost::system::error_code ec; // [esp+8h] [ebp-10h] BYREF
  boost::system::error_code v6; // [esp+10h] [ebp-8h] BYREF

  ec.m_val = 0;
  v2 = boost::system::system_category();
  m_socket = this->m_packet_socket.m_socket;
  ec.m_cat = v2;
  boost::asio::detail::win_iocp_socket_service_base::cancel(
    &m_socket->implementation,
    &ec,
    &m_socket->service->service_impl_,
    &v6);
  if ( this->m_socket.implementation.socket_ != -1 )
  {
    ec.m_val = 0;
    ec.m_cat = boost::system::system_category();
    boost::asio::basic_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>::shutdown(
      &this->m_socket,
      &ec,
      &v6.m_val);
    boost::asio::basic_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>::close(
      v4,
      (int)this);
    this->m_async_connector.m_connection_state = host_name_is_unresolved;
  }
}

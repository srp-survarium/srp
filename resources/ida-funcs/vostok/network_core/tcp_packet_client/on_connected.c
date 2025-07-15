void __thiscall vostok::network_core::tcp_packet_client::on_connected(vostok::network_core::tcp_packet_client *this)
{
  boost::function<void __cdecl(void)> *p_m_on_connected; // eax
  int v3; // ecx

  p_m_on_connected = &this->m_on_connected;
  v3 = -(this->m_on_connected.vtable != 0);
  if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v3) != 0 )
    boost::function0<void>::operator()((boost::function0<bool> *)v3, p_m_on_connected);
  vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>>::start_receiving(
    (vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > > *)v3,
    &this->m_packet_socket);
}

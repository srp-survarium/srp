void __usercall vostok::network_core::http_client::close_connection(
        vostok::network_core::http_client *this@<ecx>,
        int a2@<esi>)
{
  if ( *(_DWORD *)(a2 + 16) != -1 )
    boost::asio::basic_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>::close(
      (boost::asio::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp> > *)this,
      a2 + 12);
  boost::function0<void>::operator()((boost::function0<bool> *)this, (_DWORD *)(a2 + 200));
}

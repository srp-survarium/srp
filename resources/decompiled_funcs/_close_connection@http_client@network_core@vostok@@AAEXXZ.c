void __thiscall vostok::network_core::http_client::close_connection(vostok::network_core::http_client *this)
{
  if ( this->m_socket.implementation.socket_ != -1 )
    boost::asio::basic_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>::close((boost::asio::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp> > *)&this->m_socket);
  boost::function0<void>::operator()(&this->m_on_content_downloaded);
}

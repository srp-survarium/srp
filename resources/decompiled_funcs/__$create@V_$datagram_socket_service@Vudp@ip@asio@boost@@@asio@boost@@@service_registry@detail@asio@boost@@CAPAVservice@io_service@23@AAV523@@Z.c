boost::asio::io_service::service *__cdecl boost::asio::detail::service_registry::create<boost::asio::datagram_socket_service<boost::asio::ip::udp>>(
        boost::asio::io_service *owner)
{
  int v1; // eax
  boost::asio::datagram_socket_service<boost::asio::ip::udp> *v4; // [esp+16Ch] [ebp-4h]

  v4 = (boost::asio::datagram_socket_service<boost::asio::ip::udp> *)operator new(0x3Cu);
  if ( !v4 )
    return 0;
  boost::asio::datagram_socket_service<boost::asio::ip::udp>::datagram_socket_service<boost::asio::ip::udp>(v4, owner);
  return (boost::asio::io_service::service *)v1;
}

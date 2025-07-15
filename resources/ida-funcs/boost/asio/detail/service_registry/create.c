boost::asio::io_service::service *__cdecl boost::asio::detail::service_registry::create<boost::asio::detail::select_reactor>(
        boost::asio::io_service *owner)
{
  int v1; // eax
  boost::asio::detail::select_reactor *v4; // [esp+16Ch] [ebp-4h]

  v4 = (boost::asio::detail::select_reactor *)operator new(0xDCu);
  if ( !v4 )
    return 0;
  boost::asio::detail::select_reactor::select_reactor(v4, owner);
  return (boost::asio::io_service::service *)v1;
}


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


boost::asio::io_service::service *__cdecl boost::asio::detail::service_registry::create<boost::asio::ip::resolver_service<boost::asio::ip::tcp>>(
        boost::asio::io_service *owner)
{
  int v1; // eax
  boost::asio::ip::resolver_service<boost::asio::ip::tcp> *v4; // [esp+180h] [ebp-4h]

  v4 = (boost::asio::ip::resolver_service<boost::asio::ip::tcp> *)operator new(0x40u);
  if ( !v4 )
    return 0;
  boost::asio::ip::resolver_service<boost::asio::ip::tcp>::resolver_service<boost::asio::ip::tcp>(v4, owner);
  return (boost::asio::io_service::service *)v1;
}


boost::asio::io_service::service *__cdecl boost::asio::detail::service_registry::create<boost::asio::ip::resolver_service<boost::asio::ip::udp>>(
        boost::asio::io_service *owner)
{
  int v1; // eax
  boost::asio::ip::resolver_service<boost::asio::ip::udp> *v4; // [esp+180h] [ebp-4h]

  v4 = (boost::asio::ip::resolver_service<boost::asio::ip::udp> *)operator new(0x40u);
  if ( !v4 )
    return 0;
  boost::asio::ip::resolver_service<boost::asio::ip::udp>::resolver_service<boost::asio::ip::udp>(v4, owner);
  return (boost::asio::io_service::service *)v1;
}


boost::asio::io_service::service *__cdecl boost::asio::detail::service_registry::create<boost::asio::stream_socket_service<boost::asio::ip::tcp>>(
        boost::asio::io_service *owner)
{
  int v1; // eax
  boost::asio::stream_socket_service<boost::asio::ip::tcp> *v4; // [esp+16Ch] [ebp-4h]

  v4 = (boost::asio::stream_socket_service<boost::asio::ip::tcp> *)operator new(0x3Cu);
  if ( !v4 )
    return 0;
  boost::asio::stream_socket_service<boost::asio::ip::tcp>::stream_socket_service<boost::asio::ip::tcp>(v4, owner);
  return (boost::asio::io_service::service *)v1;
}

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

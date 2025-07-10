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

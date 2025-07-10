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

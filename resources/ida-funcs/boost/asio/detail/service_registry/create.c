void __cdecl boost::asio::detail::service_registry::create<boost::asio::detail::select_reactor>(
        boost::asio::io_service *a1)
{
  boost::asio::detail::select_reactor *v1; // edi
  boost::asio::detail::win_mutex *v2; // [esp-4h] [ebp-8h]

  v1 = (boost::asio::detail::select_reactor *)operator new(0xDCu);
  if ( v1 )
    boost::asio::detail::select_reactor::select_reactor(v1, a1, v2);
}


boost::asio::io_service::service *__cdecl boost::asio::detail::service_registry::create<boost::asio::datagram_socket_service<boost::asio::ip::udp>>(
        boost::asio::io_service *owner)
{
  char *v1; // esi
  boost::asio::detail::win_mutex *v3; // [esp-4h] [ebp-Ch]

  v1 = (char *)operator new(0x3Cu);
  if ( !v1 )
    return 0;
  *((_DWORD *)v1 + 1) = 0;
  *((_DWORD *)v1 + 2) = 0;
  *((_DWORD *)v1 + 3) = owner;
  *((_DWORD *)v1 + 4) = 0;
  *(_DWORD *)v1 = &boost::asio::datagram_socket_service<boost::asio::ip::udp>::`vftable';
  *((_DWORD *)v1 + 5) = owner;
  *((_DWORD *)v1 + 6) = owner->impl_;
  *((_DWORD *)v1 + 7) = 0;
  boost::asio::detail::win_mutex::win_mutex(v3, (boost::asio::detail::win_mutex *)(v1 + 32));
  *((_DWORD *)v1 + 14) = 0;
  return (boost::asio::io_service::service *)v1;
}


boost::asio::io_service::service *__cdecl boost::asio::detail::service_registry::create<boost::asio::ip::resolver_service<boost::asio::ip::tcp>>(
        boost::asio::io_service *owner)
{
  char *v1; // esi

  v1 = (char *)operator new(0x40u);
  if ( !v1 )
    return 0;
  *((_DWORD *)v1 + 1) = 0;
  *((_DWORD *)v1 + 2) = 0;
  *((_DWORD *)v1 + 3) = owner;
  *((_DWORD *)v1 + 4) = 0;
  *(_DWORD *)v1 = &boost::asio::ip::resolver_service<boost::asio::ip::tcp>::`vftable';
  boost::asio::detail::resolver_service_base::resolver_service_base(
    (boost::asio::detail::resolver_service_base *)(v1 + 20),
    owner,
    0);
  return (boost::asio::io_service::service *)v1;
}


boost::asio::io_service::service *__cdecl boost::asio::detail::service_registry::create<boost::asio::ip::resolver_service<boost::asio::ip::udp>>(
        boost::asio::io_service *owner)
{
  char *v1; // esi

  v1 = (char *)operator new(0x40u);
  if ( !v1 )
    return 0;
  *((_DWORD *)v1 + 1) = 0;
  *((_DWORD *)v1 + 2) = 0;
  *((_DWORD *)v1 + 3) = owner;
  *((_DWORD *)v1 + 4) = 0;
  *(_DWORD *)v1 = &boost::asio::ip::resolver_service<boost::asio::ip::udp>::`vftable';
  boost::asio::detail::resolver_service_base::resolver_service_base(
    (boost::asio::detail::resolver_service_base *)(v1 + 20),
    owner,
    0);
  return (boost::asio::io_service::service *)v1;
}


boost::asio::io_service::service *__cdecl boost::asio::detail::service_registry::create<boost::asio::stream_socket_service<boost::asio::ip::tcp>>(
        boost::asio::io_service *owner)
{
  char *v1; // esi
  boost::asio::detail::win_mutex *v3; // [esp-4h] [ebp-Ch]

  v1 = (char *)operator new(0x3Cu);
  if ( !v1 )
    return 0;
  *((_DWORD *)v1 + 1) = 0;
  *((_DWORD *)v1 + 2) = 0;
  *((_DWORD *)v1 + 3) = owner;
  *((_DWORD *)v1 + 4) = 0;
  *(_DWORD *)v1 = &boost::asio::stream_socket_service<boost::asio::ip::tcp>::`vftable';
  *((_DWORD *)v1 + 5) = owner;
  *((_DWORD *)v1 + 6) = owner->impl_;
  *((_DWORD *)v1 + 7) = 0;
  boost::asio::detail::win_mutex::win_mutex(v3, (boost::asio::detail::win_mutex *)(v1 + 32));
  *((_DWORD *)v1 + 14) = 0;
  return (boost::asio::io_service::service *)v1;
}

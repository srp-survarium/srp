void __cdecl boost::asio::detail::winsock_init_base::startup(
        boost::asio::detail::winsock_init_base::data *d,
        unsigned __int8 major,
        unsigned __int8 minor)
{
  LONG result; // [esp+0h] [ebp-194h]
  WSAData wsa_data; // [esp+4h] [ebp-190h] BYREF

  if ( InterlockedIncrement(&d->init_count_) == 1 )
  {
    result = WSAStartup((minor << 8) | major, &wsa_data);
    InterlockedExchange(&d->result_, result);
  }
}

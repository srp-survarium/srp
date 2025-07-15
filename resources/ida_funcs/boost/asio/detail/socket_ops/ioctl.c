int __cdecl boost::asio::detail::socket_ops::ioctl(
        SOCKET s,
        unsigned __int8 *state,
        int cmd,
        unsigned int *arg,
        boost::system::error_code *ec)
{
  const boost::system::error_category *v5; // edx
  const boost::system::error_category *v7; // edx
  int v8; // [esp+0h] [ebp-2Ch]
  const boost::system::error_category *v9; // [esp+8h] [ebp-24h]

  if ( s == -1 )
  {
    v5 = boost::system::system_category();
    ec->m_val = 10009;
    ec->m_cat = v5;
    return -1;
  }
  else
  {
    WSASetLastError(0);
    v8 = ioctlsocket(s, cmd, arg);
    v9 = boost::system::system_category();
    ec->m_val = WSAGetLastError();
    ec->m_cat = v9;
    if ( v8 >= 0 )
    {
      v7 = boost::system::system_category();
      ec->m_val = 0;
      ec->m_cat = v7;
      if ( cmd == -2147195266 )
      {
        if ( *arg )
          *state |= 1u;
        else
          *state &= 0xFCu;
      }
    }
    return v8;
  }
}

int __cdecl boost::asio::detail::socket_ops::getsockname(
        SOCKET s,
        sockaddr *addr,
        unsigned int *addrlen,
        boost::system::error_code *ec)
{
  const boost::system::error_category *v4; // eax
  const boost::system::error_category *v6; // eax
  const boost::system::error_category *v7; // [esp+4h] [ebp-2Ch]
  int v8; // [esp+10h] [ebp-20h]
  int namelen[4]; // [esp+14h] [ebp-1Ch] BYREF
  int v10; // [esp+24h] [ebp-Ch]
  const boost::system::error_category *v11; // [esp+28h] [ebp-8h]
  int result; // [esp+2Ch] [ebp-4h]

  if ( s == -1 )
  {
    v4 = boost::system::system_category();
    namelen[1] = (int)v4;
    namelen[2] = 10009;
    namelen[3] = (int)v4;
    ec->m_val = 10009;
    ec->m_cat = v4;
    return -1;
  }
  else
  {
    WSASetLastError(0);
    namelen[0] = *addrlen;
    v8 = getsockname(s, addr, namelen);
    *addrlen = namelen[0];
    v7 = boost::system::system_category();
    ec->m_val = WSAGetLastError();
    ec->m_cat = v7;
    result = v8;
    if ( !v8 )
    {
      v10 = 0;
      v6 = boost::system::system_category();
      v11 = v6;
      ec->m_val = v10;
      ec->m_cat = v6;
    }
    return result;
  }
}

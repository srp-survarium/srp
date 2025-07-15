int __cdecl boost::asio::detail::socket_ops::bind(
        SOCKET s,
        const sockaddr *addr,
        unsigned int addrlen,
        boost::system::error_code *ec)
{
  const boost::system::error_category *v4; // edx
  const boost::system::error_category *v6; // edx
  const boost::system::error_category *v7; // [esp+4h] [ebp-28h]
  int v8; // [esp+10h] [ebp-1Ch]

  if ( s == -1 )
  {
    v4 = boost::system::system_category();
    ec->m_val = 10009;
    ec->m_cat = v4;
    return -1;
  }
  else
  {
    WSASetLastError(0);
    v8 = bind(s, addr, addrlen);
    v7 = boost::system::system_category();
    ec->m_val = WSAGetLastError();
    ec->m_cat = v7;
    if ( !v8 )
    {
      v6 = boost::system::system_category();
      ec->m_val = 0;
      ec->m_cat = v6;
    }
    return v8;
  }
}

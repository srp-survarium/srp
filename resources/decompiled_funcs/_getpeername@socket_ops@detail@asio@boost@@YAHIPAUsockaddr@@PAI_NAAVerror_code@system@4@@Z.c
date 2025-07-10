int __cdecl boost::asio::detail::socket_ops::getpeername(
        SOCKET s,
        sockaddr *addr,
        unsigned int *addrlen,
        bool cached,
        boost::system::error_code *ec)
{
  const boost::system::error_category *v5; // eax
  const boost::system::error_category *v7; // eax
  const boost::system::error_category *v8; // eax
  const boost::system::error_category *v9; // eax
  const boost::system::error_category *v10; // [esp+4h] [ebp-A4h]
  int v11; // [esp+10h] [ebp-98h]
  int namelen[30]; // [esp+14h] [ebp-94h] BYREF
  int v13; // [esp+8Ch] [ebp-1Ch]
  const boost::system::error_category *v14; // [esp+90h] [ebp-18h]
  const boost::system::error_category *v15; // [esp+98h] [ebp-10h]
  unsigned int connect_time; // [esp+9Ch] [ebp-Ch] BYREF
  unsigned int connect_time_len; // [esp+A0h] [ebp-8h] BYREF
  int result; // [esp+A4h] [ebp-4h]

  if ( s == -1 )
  {
    v5 = boost::system::system_category();
    namelen[27] = (int)v5;
    namelen[28] = 10009;
    namelen[29] = (int)v5;
    ec->m_val = 10009;
    ec->m_cat = v5;
    return -1;
  }
  else if ( cached )
  {
    connect_time = 0;
    connect_time_len = 4;
    if ( boost::asio::detail::socket_ops::getsockopt(s, 0, 0xFFFF, 28684, (char *)&connect_time, &connect_time_len, ec) == -1 )
    {
      return -1;
    }
    else if ( connect_time == -1 )
    {
      v7 = boost::system::system_category();
      namelen[1] = (int)v7;
      namelen[2] = 10057;
      namelen[3] = (int)v7;
      ec->m_val = 10057;
      ec->m_cat = v7;
      return -1;
    }
    else
    {
      v8 = boost::system::system_category();
      v15 = v8;
      ec->m_val = 0;
      ec->m_cat = v8;
      return 0;
    }
  }
  else
  {
    WSASetLastError(0);
    namelen[0] = *addrlen;
    v11 = getpeername(s, addr, namelen);
    *addrlen = namelen[0];
    v10 = boost::system::system_category();
    ec->m_val = WSAGetLastError();
    ec->m_cat = v10;
    result = v11;
    if ( !v11 )
    {
      v13 = 0;
      v9 = boost::system::system_category();
      v14 = v9;
      ec->m_val = v13;
      ec->m_cat = v9;
    }
    return result;
  }
}

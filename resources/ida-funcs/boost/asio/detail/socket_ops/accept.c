unsigned int __cdecl boost::asio::detail::socket_ops::accept(
        SOCKET s,
        sockaddr *addr,
        unsigned int *addrlen,
        boost::system::error_code *ec)
{
  const boost::system::error_category *v4; // eax
  const boost::system::error_category *v6; // eax
  int v7; // [esp+0h] [ebp-34h]
  const boost::system::error_category *v8; // [esp+8h] [ebp-2Ch]
  SOCKET v9; // [esp+14h] [ebp-20h]
  _DWORD v10[4]; // [esp+18h] [ebp-1Ch] BYREF
  int v11; // [esp+28h] [ebp-Ch]
  unsigned int new_s; // [esp+30h] [ebp-4h]

  if ( s == -1 )
  {
    v4 = boost::system::system_category();
    v10[1] = v4;
    v10[2] = 10009;
    v10[3] = v4;
    ec->m_val = 10009;
    ec->m_cat = v4;
    return -1;
  }
  else
  {
    WSASetLastError(0);
    if ( addrlen )
      v7 = *addrlen;
    else
      v7 = 0;
    v10[0] = v7;
    v9 = accept(s, addr, addrlen != 0 ? v10 : 0);
    if ( addrlen )
      *addrlen = v10[0];
    v8 = boost::system::system_category();
    ec->m_val = WSAGetLastError();
    ec->m_cat = v8;
    new_s = v9;
    if ( v9 == -1 )
    {
      return -1;
    }
    else
    {
      v11 = 0;
      v6 = boost::system::system_category();
      ec->m_val = v11;
      ec->m_cat = v6;
      return new_s;
    }
  }
}

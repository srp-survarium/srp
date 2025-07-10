int __cdecl boost::asio::detail::socket_ops::setsockopt(
        SOCKET s,
        unsigned __int8 *state,
        int level,
        int optname,
        const char *optval,
        unsigned int optlen,
        boost::system::error_code *ec)
{
  const boost::system::error_category *v7; // edx
  const boost::system::error_category *v9; // edx
  const boost::system::error_category *v10; // [esp+Ch] [ebp-40h]
  int v11; // [esp+10h] [ebp-3Ch]
  const boost::system::error_category *v12; // [esp+1Ch] [ebp-30h]
  const boost::system::error_category *v13; // [esp+28h] [ebp-24h]
  const boost::system::error_category *v14; // [esp+3Ch] [ebp-10h]

  if ( s == -1 )
  {
    v7 = boost::system::system_category();
    ec->m_val = 10009;
    ec->m_cat = v7;
    return -1;
  }
  else if ( level == -1525678080 && optname == 2 )
  {
    v13 = boost::system::system_category();
    ec->m_val = 10022;
    ec->m_cat = v13;
    return -1;
  }
  else if ( level == -1525678080 && optname == 1 )
  {
    if ( optlen == 4 )
    {
      if ( *(_DWORD *)optval )
        *state |= 4u;
      else
        *state &= ~4u;
      v9 = boost::system::system_category();
      ec->m_val = 0;
      ec->m_cat = v9;
      return 0;
    }
    else
    {
      v12 = boost::system::system_category();
      ec->m_val = 10022;
      ec->m_cat = v12;
      return -1;
    }
  }
  else
  {
    if ( level == 0xFFFF && optname == 128 )
      *state |= 8u;
    WSASetLastError(0);
    v11 = setsockopt(s, level, optname, optval, optlen);
    v10 = boost::system::system_category();
    ec->m_val = WSAGetLastError();
    ec->m_cat = v10;
    if ( !v11 )
    {
      v14 = boost::system::system_category();
      ec->m_val = 0;
      ec->m_cat = v14;
    }
    return v11;
  }
}

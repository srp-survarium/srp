char __cdecl boost::asio::detail::socket_ops::set_internal_non_blocking(
        SOCKET s,
        unsigned __int8 *state,
        bool value,
        boost::system::error_code *ec)
{
  const boost::system::error_category *v4; // edx
  int v6; // [esp+0h] [ebp-3Ch]
  const boost::system::error_category *v7; // [esp+10h] [ebp-2Ch]
  const boost::system::error_category *v8; // [esp+1Ch] [ebp-20h]
  const boost::system::error_category *v9; // [esp+30h] [ebp-Ch]
  unsigned int arg; // [esp+38h] [ebp-4h] BYREF

  if ( s == -1 )
  {
    v4 = boost::system::system_category();
    ec->m_val = 10009;
    ec->m_cat = v4;
    return 0;
  }
  else if ( value || (*state & 1) == 0 )
  {
    WSASetLastError(0);
    arg = value;
    v6 = ioctlsocket(s, -2147195266, &arg);
    v7 = boost::system::system_category();
    ec->m_val = WSAGetLastError();
    ec->m_cat = v7;
    if ( v6 < 0 )
    {
      return 0;
    }
    else
    {
      v9 = boost::system::system_category();
      ec->m_val = 0;
      ec->m_cat = v9;
      if ( value )
        *state |= 2u;
      else
        *state &= ~2u;
      return 1;
    }
  }
  else
  {
    v8 = boost::system::system_category();
    ec->m_val = 10022;
    ec->m_cat = v8;
    return 0;
  }
}

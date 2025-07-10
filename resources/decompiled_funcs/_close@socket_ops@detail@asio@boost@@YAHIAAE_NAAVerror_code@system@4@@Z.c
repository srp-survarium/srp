int __cdecl boost::asio::detail::socket_ops::close(
        SOCKET s,
        unsigned __int8 *state,
        bool destruction,
        boost::system::error_code *ec)
{
  char v5; // [esp+0h] [ebp-C0h]
  bool v6; // [esp+4h] [ebp-BCh]
  int v7; // [esp+8h] [ebp-B8h]
  const boost::system::error_category *v8; // [esp+10h] [ebp-B0h]
  int v9; // [esp+34h] [ebp-8Ch]
  const boost::system::error_category *v10; // [esp+3Ch] [ebp-84h]
  const boost::system::error_category *v11; // [esp+98h] [ebp-28h]
  unsigned int arg; // [esp+ACh] [ebp-14h] BYREF
  boost::system::error_code ignored_ec; // [esp+B0h] [ebp-10h] BYREF
  linger opt; // [esp+B8h] [ebp-8h] BYREF
  int result; // [esp+BCh] [ebp-4h]

  result = 0;
  if ( s != -1 )
  {
    if ( destruction && (*state & 8) != 0 )
    {
      opt.l_onoff = 0;
      opt.l_linger = 0;
      ignored_ec.m_val = 0;
      ignored_ec.m_cat = boost::system::system_category();
      boost::asio::detail::socket_ops::setsockopt(s, state, 0xFFFF, 128, (const char *)&opt, 4u, &ignored_ec);
    }
    WSASetLastError(0);
    v9 = closesocket(s);
    v10 = boost::system::system_category();
    ec->m_val = WSAGetLastError();
    ec->m_cat = v10;
    result = v9;
    if ( v9 )
    {
      v6 = ec->m_cat == boost::system::system_category() && ec->m_val == 10035;
      if ( v6 || (ec->m_cat != boost::system::system_category() || ec->m_val != 1237 ? (v5 = 0) : (v5 = 1), v5) )
      {
        arg = 0;
        ioctlsocket(s, -2147195266, &arg);
        *state &= 0xFCu;
        WSASetLastError(0);
        v7 = closesocket(s);
        v8 = boost::system::system_category();
        ec->m_val = WSAGetLastError();
        ec->m_cat = v8;
        result = v7;
      }
    }
  }
  if ( !result )
  {
    v11 = boost::system::system_category();
    ec->m_val = 0;
    ec->m_cat = v11;
  }
  return result;
}

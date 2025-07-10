unsigned int __cdecl boost::asio::detail::socket_ops::socket(
        int af,
        int type,
        int protocol,
        boost::system::error_code *ec)
{
  SOCKET v5; // [esp+0h] [ebp-24h]
  const boost::system::error_category *v6; // [esp+10h] [ebp-14h]
  const boost::system::error_category *v7; // [esp+18h] [ebp-Ch]
  unsigned int optval; // [esp+1Ch] [ebp-8h] BYREF
  unsigned int s; // [esp+20h] [ebp-4h]

  WSASetLastError(0);
  v5 = WSASocketA(af, type, protocol, 0, 0, 1u);
  v6 = boost::system::system_category();
  ec->m_val = WSAGetLastError();
  ec->m_cat = v6;
  s = v5;
  if ( v5 == -1 )
    return -1;
  if ( af == 23 )
  {
    optval = 0;
    setsockopt(s, 41, 27, (const char *)&optval, 4);
  }
  v7 = boost::system::system_category();
  ec->m_val = 0;
  ec->m_cat = v7;
  return s;
}

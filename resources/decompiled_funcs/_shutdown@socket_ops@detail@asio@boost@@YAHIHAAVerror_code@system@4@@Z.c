int __cdecl boost::asio::detail::socket_ops::shutdown(SOCKET s, int what, boost::system::error_code *ec)
{
  const boost::system::error_category *v3; // edx
  int v5; // [esp+0h] [ebp-2Ch]
  const boost::system::error_category *v6; // [esp+10h] [ebp-1Ch]
  const boost::system::error_category *v7; // [esp+24h] [ebp-8h]

  if ( s == -1 )
  {
    v3 = boost::system::system_category();
    ec->m_val = 10009;
    ec->m_cat = v3;
    return -1;
  }
  else
  {
    WSASetLastError(0);
    v5 = shutdown(s, what);
    v6 = boost::system::system_category();
    ec->m_val = WSAGetLastError();
    ec->m_cat = v6;
    if ( !v5 )
    {
      v7 = boost::system::system_category();
      ec->m_val = 0;
      ec->m_cat = v7;
    }
    return v5;
  }
}

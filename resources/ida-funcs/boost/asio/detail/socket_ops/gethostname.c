int __cdecl boost::asio::detail::socket_ops::gethostname(char *name, int namelen, boost::system::error_code *ec)
{
  int v4; // [esp+0h] [ebp-20h]
  const boost::system::error_category *v5; // [esp+8h] [ebp-18h]
  const boost::system::error_category *v6; // [esp+18h] [ebp-8h]

  WSASetLastError(0);
  v4 = gethostname(name, namelen);
  v5 = boost::system::system_category();
  ec->m_val = WSAGetLastError();
  ec->m_cat = v5;
  if ( !v4 )
  {
    v6 = boost::system::system_category();
    ec->m_val = 0;
    ec->m_cat = v6;
  }
  return v4;
}

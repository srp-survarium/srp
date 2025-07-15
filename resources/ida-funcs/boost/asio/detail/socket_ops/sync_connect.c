void __cdecl boost::asio::detail::socket_ops::sync_connect(
        SOCKET s,
        const sockaddr *addr,
        unsigned int addrlen,
        boost::system::error_code *ec)
{
  char v4; // [esp+0h] [ebp-30Ch]
  bool v5; // [esp+4h] [ebp-308h]
  const boost::system::error_category *v6; // [esp+Ch] [ebp-300h]
  int connect_error; // [esp+304h] [ebp-8h] BYREF
  unsigned int connect_error_len; // [esp+308h] [ebp-4h] BYREF

  boost::asio::detail::socket_ops::connect(s, addr, addrlen, ec);
  v5 = ec->m_cat == boost::system::system_category() && ec->m_val == 10036;
  if ( v5 || (ec->m_cat != boost::system::system_category() || ec->m_val != 10035 ? (v4 = 0) : (v4 = 1), v4) )
  {
    if ( boost::asio::detail::socket_ops::poll_connect(s, ec) >= 0 )
    {
      connect_error = 0;
      connect_error_len = 4;
      if ( boost::asio::detail::socket_ops::getsockopt(
             s,
             0,
             0xFFFF,
             4103,
             (char *)&connect_error,
             &connect_error_len,
             ec) != -1 )
      {
        v6 = boost::system::system_category();
        ec->m_val = connect_error;
        ec->m_cat = v6;
      }
    }
  }
}

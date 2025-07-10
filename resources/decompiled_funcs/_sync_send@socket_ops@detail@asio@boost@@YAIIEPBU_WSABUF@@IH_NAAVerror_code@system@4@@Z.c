signed int __cdecl boost::asio::detail::socket_ops::sync_send(
        SOCKET s,
        unsigned __int8 state,
        _WSABUF *bufs,
        DWORD count,
        DWORD flags,
        bool all_empty,
        boost::system::error_code *ec)
{
  const boost::system::error_category *v7; // edx
  const boost::system::error_category *v11; // [esp+1ECh] [ebp-8h]
  signed int bytes; // [esp+1F0h] [ebp-4h]

  if ( s == -1 )
  {
    v7 = boost::system::system_category();
    ec->m_val = 10009;
    ec->m_cat = v7;
    return 0;
  }
  else if ( all_empty && (state & 0x10) != 0 )
  {
    v11 = boost::system::system_category();
    ec->m_val = 0;
    ec->m_cat = v11;
    return 0;
  }
  else
  {
    do
    {
      bytes = boost::asio::detail::socket_ops::send(s, bufs, count, flags, ec);
      if ( bytes >= 0 )
        return bytes;
      if ( (state & 1) == 0 )
      {
        if ( ec->m_cat == boost::system::system_category() && ec->m_val == 10035 )
          continue;
        if ( ec->m_cat == boost::system::system_category() && ec->m_val == 1237 )
          continue;
      }
      return 0;
    }
    while ( boost::asio::detail::socket_ops::poll_write(s, 0, ec) >= 0 );
    return 0;
  }
}

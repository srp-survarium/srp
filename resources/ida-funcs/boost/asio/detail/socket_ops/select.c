int __cdecl boost::asio::detail::socket_ops::select(
        int nfds,
        fd_set *readfds,
        fd_set *writefds,
        fd_set *exceptfds,
        timeval *timeout,
        boost::system::error_code *ec)
{
  const boost::system::error_category *v6; // edx
  const boost::system::error_category *v8; // edx
  int v9; // [esp+4h] [ebp-2Ch]
  const boost::system::error_category *v10; // [esp+Ch] [ebp-24h]
  DWORD milliseconds; // [esp+28h] [ebp-8h]

  WSASetLastError(0);
  if ( readfds || writefds || exceptfds || !timeout )
  {
    if ( timeout && !timeout->tv_sec && timeout->tv_usec > 0 && timeout->tv_usec < 1000 )
      timeout->tv_usec = 1000;
    v9 = select(nfds, readfds, writefds, exceptfds, timeout);
    v10 = boost::system::system_category();
    ec->m_val = WSAGetLastError();
    ec->m_cat = v10;
    if ( v9 >= 0 )
    {
      v8 = boost::system::system_category();
      ec->m_val = 0;
      ec->m_cat = v8;
    }
    return v9;
  }
  else
  {
    milliseconds = timeout->tv_usec / 1000 + 1000 * timeout->tv_sec;
    if ( !milliseconds )
      milliseconds = 1;
    Sleep(milliseconds);
    v6 = boost::system::system_category();
    ec->m_val = 0;
    ec->m_cat = v6;
    return 0;
  }
}

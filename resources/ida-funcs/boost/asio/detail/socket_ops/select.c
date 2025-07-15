int __usercall boost::asio::detail::socket_ops::select@<eax>(
        timeval *timeout@<ecx>,
        boost::system::error_code *ec@<eax>,
        int nfds,
        fd_set *readfds,
        fd_set *writefds,
        fd_set *exceptfds)
{
  DWORD v8; // eax
  int tv_usec; // eax
  int v11; // eax
  int v12; // ebx
  const boost::system::error_category *v13; // eax

  WSASetLastError(0);
  if ( readfds || writefds || exceptfds )
  {
    if ( timeout )
    {
      if ( !timeout->tv_sec )
      {
        tv_usec = timeout->tv_usec;
        if ( tv_usec > 0 && tv_usec < 1000 )
          timeout->tv_usec = 1000;
      }
    }
  }
  else if ( timeout )
  {
    v8 = 1000 * timeout->tv_sec + timeout->tv_usec / 1000;
    if ( !v8 )
      v8 = 1;
    Sleep(v8);
    ec->m_cat = boost::system::system_category();
    ec->m_val = 0;
    return 0;
  }
  v11 = ((int (__stdcall *)(int, fd_set *, fd_set *, fd_set *, timeval *))(&off_8E3A98 + 13))(
          nfds,
          readfds,
          writefds,
          exceptfds,
          timeout);
  v12 = boost::asio::detail::socket_ops::error_wrapper<int>(ec, v11);
  if ( v12 >= 0 )
  {
    v13 = boost::system::system_category();
    ec->m_val = 0;
    ec->m_cat = v13;
  }
  return v12;
}

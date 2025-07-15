int __usercall boost::asio::detail::socket_ops::getsockname@<eax>(
        unsigned int *addrlen@<ecx>,
        boost::system::error_code *ec@<eax>,
        SOCKET s,
        sockaddr *addr)
{
  int v7; // eax
  int v8; // ebx
  const boost::system::error_category *v9; // eax
  int namelen; // [esp+8h] [ebp-4h] BYREF

  if ( s == -1 )
  {
    ec->m_cat = boost::system::system_category();
    ec->m_val = 10009;
    return -1;
  }
  else
  {
    WSASetLastError(0);
    namelen = *addrlen;
    v7 = getsockname(s, addr, &namelen);
    *addrlen = namelen;
    v8 = boost::asio::detail::socket_ops::error_wrapper<int>(ec, v7);
    if ( !v8 )
    {
      v9 = boost::system::system_category();
      ec->m_val = 0;
      ec->m_cat = v9;
    }
    return v8;
  }
}

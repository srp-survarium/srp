int __usercall boost::asio::detail::socket_ops::connect@<eax>(
        boost::system::error_code *ec@<eax>,
        int a2@<ebx>,
        unsigned int s,
        const sockaddr *addr,
        unsigned int addrlen)
{
  int v7; // eax
  int v8; // ebx
  const boost::system::error_category *v9; // eax
  int v10; // [esp+0h] [ebp-8h]

  if ( s == -1 )
  {
    ec->m_cat = boost::system::system_category();
    ec->m_val = 10009;
    return -1;
  }
  else
  {
    WSASetLastError(0);
    v7 = ((int (__stdcall *)(unsigned int, const sockaddr *, unsigned int, int, int))(&off_8E3A98 + 8))(
           s,
           addr,
           addrlen,
           a2,
           v10);
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

int __usercall boost::asio::detail::socket_ops::getsockopt@<eax>(
        unsigned int *optlen@<ecx>,
        boost::system::error_code *ec@<eax>,
        unsigned int s,
        int state,
        int level)
{
  int v8; // eax
  int v9; // ebx
  const boost::system::error_category *v10; // eax
  unsigned int v11; // [esp+8h] [ebp-4h] BYREF

  if ( s == -1 )
  {
    ec->m_cat = boost::system::system_category();
    ec->m_val = 10009;
    return -1;
  }
  else
  {
    WSASetLastError(0);
    v11 = *optlen;
    v8 = ((int (__stdcall *)(unsigned int, int, int, int, unsigned int *))(&off_8E3A98 + 14))(
           s,
           0xFFFF,
           state,
           level,
           &v11);
    *optlen = v11;
    v9 = boost::asio::detail::socket_ops::error_wrapper<int>(ec, v8);
    if ( !v9 )
    {
      v10 = boost::system::system_category();
      ec->m_val = 0;
      ec->m_cat = v10;
    }
    return v9;
  }
}

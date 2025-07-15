int __usercall boost::asio::detail::socket_ops::getpeername@<eax>(
        unsigned int *addrlen@<ecx>,
        boost::system::error_code *ec@<eax>,
        unsigned int s,
        sockaddr *addr,
        bool cached)
{
  int v5; // ebx
  int v8; // edi
  int v10; // eax
  const boost::system::error_category *v11; // eax
  int v12; // [esp+0h] [ebp-14h]
  int v13; // [esp+4h] [ebp-10h]
  unsigned int v14; // [esp+Ch] [ebp-8h] BYREF
  unsigned int v15; // [esp+10h] [ebp-4h] BYREF

  v5 = -1;
  if ( s == -1 )
  {
    v8 = 10009;
LABEL_10:
    v11 = boost::system::system_category();
    ec->m_val = v8;
    ec->m_cat = v11;
    return v5;
  }
  if ( cached )
  {
    v15 = 0;
    v14 = 4;
    if ( boost::asio::detail::socket_ops::getsockopt(&v14, ec, s, 28684, (int)&v15) != -1 )
    {
      if ( v15 != -1 )
      {
        ec->m_cat = boost::system::system_category();
        ec->m_val = 0;
        return 0;
      }
      v8 = 10057;
      goto LABEL_10;
    }
  }
  else
  {
    WSASetLastError(0);
    v15 = *addrlen;
    v10 = ((int (__stdcall *)(unsigned int, sockaddr *, unsigned int *, int, int))(&off_8E3A98 + 15))(
            s,
            addr,
            &v15,
            v12,
            v13);
    *addrlen = v15;
    v5 = boost::asio::detail::socket_ops::error_wrapper<int>(ec, v10);
    if ( !v5 )
    {
      v8 = 0;
      goto LABEL_10;
    }
  }
  return v5;
}

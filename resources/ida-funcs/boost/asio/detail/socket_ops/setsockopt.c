int __usercall boost::asio::detail::socket_ops::setsockopt@<eax>(
        unsigned __int8 *state@<eax>,
        boost::system::error_code *ec@<ecx>,
        unsigned int s,
        int level,
        int optname,
        _DWORD *optval,
        unsigned int optlen)
{
  int v7; // ebx
  int v9; // edi
  int v11; // eax

  v7 = -1;
  if ( s == -1 )
  {
    v9 = 10009;
    goto LABEL_17;
  }
  if ( level != -1525678080 )
  {
    if ( level == 0xFFFF && optname == 128 )
      *state |= 8u;
    goto LABEL_15;
  }
  if ( optname == 2 )
  {
LABEL_5:
    v9 = 10022;
    goto LABEL_17;
  }
  if ( optname != 1 )
  {
LABEL_15:
    WSASetLastError(0);
    v11 = ((int (__stdcall *)(unsigned int, int, int, _DWORD *, unsigned int))(&off_8E3A98 + 21))(
            s,
            level,
            optname,
            optval,
            optlen);
    v7 = boost::asio::detail::socket_ops::error_wrapper<int>(ec, v11);
    if ( v7 )
      return v7;
    v9 = 0;
LABEL_17:
    ec->m_cat = boost::system::system_category();
    ec->m_val = v9;
    return v7;
  }
  if ( optlen != 4 )
    goto LABEL_5;
  if ( *optval )
    *state |= 4u;
  else
    *state &= ~4u;
  ec->m_cat = boost::system::system_category();
  ec->m_val = 0;
  return 0;
}

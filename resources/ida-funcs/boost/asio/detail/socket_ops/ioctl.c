int __usercall boost::asio::detail::socket_ops::ioctl@<eax>(
        boost::system::error_code *ec@<eax>,
        unsigned int s,
        unsigned __int8 *state,
        _DWORD *cmd)
{
  int v6; // eax
  int v7; // [esp+0h] [ebp-Ch]
  int v8; // [esp+4h] [ebp-8h]
  int v9; // [esp+14h] [ebp+8h]

  if ( s == -1 )
  {
    ec->m_cat = boost::system::system_category();
    ec->m_val = 10009;
    return -1;
  }
  else
  {
    WSASetLastError(0);
    v6 = ((int (__stdcall *)(unsigned int, int, _DWORD *, int, int))(&off_8E3A98 + 22))(s, -2147195266, cmd, v7, v8);
    v9 = boost::asio::detail::socket_ops::error_wrapper<int>(ec, v6);
    if ( v9 >= 0 )
    {
      ec->m_cat = boost::system::system_category();
      ec->m_val = 0;
      if ( *cmd )
        *state |= 1u;
      else
        *state &= 0xFCu;
    }
    return v9;
  }
}

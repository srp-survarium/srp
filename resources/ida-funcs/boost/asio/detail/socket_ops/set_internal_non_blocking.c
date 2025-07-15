char __usercall boost::asio::detail::socket_ops::set_internal_non_blocking@<al>(
        unsigned __int8 *state@<ecx>,
        boost::system::error_code *ec@<eax>,
        int a3@<ebx>,
        unsigned int s)
{
  int v7; // eax
  int v8; // [esp+0h] [ebp-Ch]
  int v9; // [esp+8h] [ebp-4h] BYREF

  if ( s == -1 )
  {
    ec->m_cat = boost::system::system_category();
    ec->m_val = 10009;
    return 0;
  }
  else
  {
    WSASetLastError(0);
    v9 = 1;
    v7 = ((int (__stdcall *)(unsigned int, int, int *, int, int))(&off_8E3A98 + 22))(s, -2147195266, &v9, a3, v8);
    if ( boost::asio::detail::socket_ops::error_wrapper<int>(ec, v7) < 0 )
    {
      return 0;
    }
    else
    {
      ec->m_cat = boost::system::system_category();
      ec->m_val = 0;
      *state |= 2u;
      return 1;
    }
  }
}

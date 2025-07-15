int __usercall boost::asio::detail::socket_ops::poll_connect@<eax>(
        unsigned int s@<ecx>,
        boost::system::error_code *ec@<eax>)
{
  int v5; // eax
  const boost::system::error_category *v6; // eax
  _DWORD v7[65]; // [esp+8h] [ebp-20Ch] BYREF
  _DWORD v8[65]; // [esp+10Ch] [ebp-108h] BYREF
  int v9; // [esp+210h] [ebp-4h]

  if ( s == -1 )
  {
    ec->m_cat = boost::system::system_category();
    ec->m_val = 10009;
    return -1;
  }
  else
  {
    v7[1] = s;
    v7[0] = 1;
    v8[1] = s;
    v8[0] = 1;
    WSASetLastError(0);
    v5 = ((int (__stdcall *)(unsigned int, _DWORD, _DWORD *, _DWORD *, _DWORD))(&off_8E3A98 + 13))(s, 0, v7, v8, 0);
    v9 = boost::asio::detail::socket_ops::error_wrapper<int>(ec, v5);
    if ( v9 >= 0 )
    {
      v6 = boost::system::system_category();
      ec->m_val = 0;
      ec->m_cat = v6;
    }
    return v9;
  }
}

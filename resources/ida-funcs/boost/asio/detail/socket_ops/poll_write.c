int __usercall boost::asio::detail::socket_ops::poll_write@<eax>(boost::system::error_code *ec@<eax>, unsigned int s)
{
  int v4; // eax
  int v5; // ebx
  _DWORD v6[68]; // [esp+Ch] [ebp-110h] BYREF

  if ( s == -1 )
  {
    ec->m_cat = boost::system::system_category();
    ec->m_val = 10009;
    return -1;
  }
  else
  {
    v6[1] = s;
    v6[0] = 1;
    v6[66] = 0;
    v6[67] = 0;
    WSASetLastError(0);
    v4 = ((int (__stdcall *)(unsigned int, _DWORD, _DWORD *, _DWORD, _DWORD))(&off_8E3A98 + 13))(s, 0, v6, 0, 0);
    v5 = boost::asio::detail::socket_ops::error_wrapper<int>(ec, v4);
    if ( v5 >= 0 )
    {
      ec->m_cat = boost::system::system_category();
      ec->m_val = 0;
    }
    return v5;
  }
}

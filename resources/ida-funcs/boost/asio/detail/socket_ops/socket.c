int __usercall boost::asio::detail::socket_ops::socket@<eax>(
        boost::system::error_code *ec@<esi>,
        int af,
        int type,
        int protocol)
{
  const boost::system::error_category *v4; // edi
  int result; // eax
  int v6; // [esp+8h] [ebp-8h] BYREF
  int v7; // [esp+Ch] [ebp-4h]

  WSASetLastError(0);
  v7 = ((int (__stdcall *)(int, int, int, _DWORD, _DWORD))(&off_8E3A98 + 18))(af, type, protocol, 0, 0);
  v4 = boost::system::system_category();
  ec->m_val = WSAGetLastError();
  result = -1;
  ec->m_cat = v4;
  if ( v7 != -1 )
  {
    if ( af == 23 )
    {
      v6 = 0;
      ((void (__stdcall *)(int, int, int, int *, int))(&off_8E3A98 + 21))(v7, 41, 27, &v6, 4);
    }
    ec->m_cat = boost::system::system_category();
    result = v7;
    ec->m_val = 0;
  }
  return result;
}

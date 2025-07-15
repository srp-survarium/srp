int __usercall boost::asio::detail::socket_ops::send@<eax>(
        boost::system::error_code *ec@<eax>,
        unsigned int s,
        const _WSABUF *bufs,
        unsigned int count)
{
  int v5; // eax
  int v6; // ebx
  int result; // eax
  int v8; // [esp+Ch] [ebp-4h] BYREF
  int v9; // [esp+20h] [ebp+10h]

  WSASetLastError(0);
  v8 = 0;
  v5 = ((int (__stdcall *)(unsigned int, const _WSABUF *, unsigned int, int *, _DWORD))(&off_8E3A98 + 25))(
         s,
         bufs,
         count,
         &v8,
         0);
  v9 = boost::asio::detail::socket_ops::error_wrapper<int>(ec, v5);
  if ( ec->m_val == 64 )
  {
    v6 = 10054;
  }
  else
  {
    if ( ec->m_val != 1234 )
      goto LABEL_6;
    v6 = 10061;
  }
  ec->m_cat = boost::system::system_category();
  ec->m_val = v6;
LABEL_6:
  if ( v9 )
    return -1;
  ec->m_cat = boost::system::system_category();
  result = v8;
  ec->m_val = 0;
  return result;
}

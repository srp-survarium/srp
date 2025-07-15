int __usercall boost::asio::detail::socket_ops::recv@<eax>(
        boost::system::error_code *ec@<eax>,
        unsigned int s,
        _WSABUF *bufs)
{
  int v4; // eax
  int v5; // ebx
  int result; // eax
  int v7; // [esp+Ch] [ebp-Ch]
  int v8; // [esp+10h] [ebp-8h] BYREF
  int v9; // [esp+14h] [ebp-4h] BYREF

  WSASetLastError(0);
  v9 = 0;
  v8 = 0;
  v4 = ((int (__stdcall *)(unsigned int, _WSABUF *, int, int *, int *))(&off_8E3A98 + 16))(s, bufs, 1, &v9, &v8);
  v7 = boost::asio::detail::socket_ops::error_wrapper<int>(ec, v4);
  if ( ec->m_val == 64 )
  {
    v5 = 10054;
  }
  else
  {
    if ( ec->m_val != 1234 )
      goto LABEL_6;
    v5 = 10061;
  }
  ec->m_cat = boost::system::system_category();
  ec->m_val = v5;
LABEL_6:
  if ( v7 )
    return -1;
  ec->m_cat = boost::system::system_category();
  result = v9;
  ec->m_val = 0;
  return result;
}

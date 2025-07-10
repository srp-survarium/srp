unsigned int __cdecl boost::asio::detail::socket_ops::recv(
        SOCKET s,
        _WSABUF *bufs,
        DWORD count,
        unsigned int flags,
        boost::system::error_code *ec)
{
  const boost::system::error_category *v5; // edx
  const boost::system::error_category *v6; // edx
  const boost::system::error_category *v8; // edx
  int v9; // [esp+20h] [ebp-2Ch]
  const boost::system::error_category *v10; // [esp+30h] [ebp-1Ch]
  unsigned int recv_flags; // [esp+44h] [ebp-8h] BYREF
  unsigned int bytes_transferred; // [esp+48h] [ebp-4h] BYREF

  WSASetLastError(0);
  bytes_transferred = 0;
  recv_flags = flags;
  v9 = WSARecv(s, bufs, count, &bytes_transferred, &recv_flags, 0, 0);
  v10 = boost::system::system_category();
  ec->m_val = WSAGetLastError();
  ec->m_cat = v10;
  if ( ec->m_val == 64 )
  {
    v5 = boost::system::system_category();
    ec->m_val = 10054;
    ec->m_cat = v5;
  }
  else if ( ec->m_val == 1234 )
  {
    v6 = boost::system::system_category();
    ec->m_val = 10061;
    ec->m_cat = v6;
  }
  if ( v9 )
    return -1;
  v8 = boost::system::system_category();
  ec->m_val = 0;
  ec->m_cat = v8;
  return bytes_transferred;
}

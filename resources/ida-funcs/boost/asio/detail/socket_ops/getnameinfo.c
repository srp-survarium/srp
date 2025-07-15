boost::system::error_code *__usercall boost::asio::detail::socket_ops::getnameinfo@<eax>(
        int *a1@<edi>,
        SOCKADDR *result,
        const sockaddr *addr,
        char *addrlen,
        char *host,
        INT hostlen,
        boost::system::error_code *serv)
{
  INT v7; // eax
  boost::system::error_code *v8; // eax
  int m_val; // ecx
  int v11; // [esp+8h] [ebp-8h] BYREF

  WSASetLastError(0);
  v7 = getnameinfo(result, (socklen_t)addr, addrlen, 0x401u, host, 0x20u, hostlen);
  v8 = boost::asio::detail::socket_ops::translate_addrinfo_error(v7, &v11);
  *serv = *v8;
  m_val = v8->m_val;
  a1[1] = (int)v8->m_cat;
  *a1 = m_val;
  return (boost::system::error_code *)a1;
}

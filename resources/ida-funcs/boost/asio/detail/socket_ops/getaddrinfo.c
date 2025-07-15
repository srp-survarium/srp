boost::system::error_code *__usercall boost::asio::detail::socket_ops::getaddrinfo@<eax>(
        const char *host@<eax>,
        int *a2@<edi>,
        const char *service,
        const addrinfo *hints,
        addrinfo **result,
        boost::system::error_code *ec)
{
  const char *v6; // esi
  int v7; // eax
  boost::system::error_code *v8; // eax
  int m_val; // ecx
  int v11; // [esp+0h] [ebp-10h]
  int v12; // [esp+8h] [ebp-8h] BYREF

  v6 = host;
  if ( !host || !*host )
    v6 = 0;
  if ( !service || !*service )
    service = 0;
  WSASetLastError(0);
  v7 = ((int (__stdcall *)(const char *, const char *, const addrinfo *, addrinfo **, int))(&off_8E3A98 + 11))(
         v6,
         service,
         hints,
         result,
         v11);
  v8 = boost::asio::detail::socket_ops::translate_addrinfo_error(v7, &v12);
  *ec = *v8;
  m_val = v8->m_val;
  a2[1] = (int)v8->m_cat;
  *a2 = m_val;
  return (boost::system::error_code *)a2;
}

boost::system::error_code *__cdecl boost::asio::detail::socket_ops::getaddrinfo(
        boost::system::error_code *result,
        const char *host,
        const char *service,
        const addrinfo *hints,
        addrinfo **resulta,
        boost::system::error_code *ec)
{
  boost::system::error_code *v6; // eax
  int m_val; // edx
  const boost::system::error_category *m_cat; // eax
  const boost::system::error_category *v9; // ecx
  const char *v11; // [esp+0h] [ebp-7Ch]
  const char *v12; // [esp+4h] [ebp-78h]
  boost::system::error_code v13; // [esp+70h] [ebp-Ch] BYREF
  int error; // [esp+78h] [ebp-4h]

  if ( host && *host )
    v12 = host;
  else
    v12 = 0;
  if ( service && *service )
    v11 = service;
  else
    v11 = 0;
  WSASetLastError(0);
  error = getaddrinfo(v12, v11, hints, resulta);
  v6 = boost::asio::detail::socket_ops::translate_addrinfo_error(&v13, error);
  m_val = v6->m_val;
  m_cat = v6->m_cat;
  ec->m_val = m_val;
  ec->m_cat = m_cat;
  v9 = ec->m_cat;
  result->m_val = ec->m_val;
  result->m_cat = v9;
  return result;
}

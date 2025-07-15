boost::system::error_code *__usercall boost::asio::detail::socket_ops::background_getaddrinfo@<eax>(
        const boost::weak_ptr<void> *cancel_token@<eax>,
        boost::system::error_code *ec@<esi>,
        boost::weak_ptr<void> *a3@<ecx>,
        boost::system::error_code *host,
        const char *service,
        const addrinfo *hints,
        addrinfo **result,
        addrinfo **a8)
{
  const boost::system::error_category *v8; // eax
  int v10; // [esp+8h] [ebp-8h] BYREF

  if ( boost::weak_ptr<void>::expired(a3, (int)cancel_token) )
  {
    v8 = boost::system::system_category();
    ec->m_val = 995;
    ec->m_cat = v8;
  }
  else
  {
    boost::asio::detail::socket_ops::getaddrinfo(service, &v10, (const char *)hints, (const addrinfo *)result, a8, ec);
  }
  *host = *ec;
  return host;
}

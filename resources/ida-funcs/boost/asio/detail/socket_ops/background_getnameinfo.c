boost::system::error_code *__usercall boost::asio::detail::socket_ops::background_getnameinfo@<eax>(
        const boost::weak_ptr<void> *cancel_token@<eax>,
        boost::system::error_code *ec@<esi>,
        boost::weak_ptr<void> *a3@<ecx>,
        boost::system::error_code *addr,
        SOCKADDR *addrlen,
        const sockaddr *host,
        char *hostlen,
        char *serv,
        unsigned int servlen)
{
  const boost::system::error_category *v9; // eax
  INT v10; // ebx
  boost::system::error_code *result; // eax
  int v12[2]; // [esp+4h] [ebp-8h] BYREF

  if ( boost::weak_ptr<void>::expired(a3, (int)cancel_token) )
  {
    v9 = boost::system::system_category();
    ec->m_val = 995;
    ec->m_cat = v9;
  }
  else
  {
    if ( servlen == 2 )
      v10 = 16;
    else
      v10 = 0;
    boost::asio::detail::socket_ops::getnameinfo(v12, addrlen, host, hostlen, serv, v10, ec);
    if ( (ec->m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
      boost::asio::detail::socket_ops::getnameinfo(v12, addrlen, host, hostlen, serv, v10 | 8, ec);
  }
  result = addr;
  *addr = *ec;
  return result;
}

void __usercall boost::asio::detail::socket_ops::sync_connect(
        boost::system::error_code *ec@<esi>,
        int a2@<ebx>,
        unsigned int s,
        const sockaddr *addr,
        unsigned int addrlen)
{
  const boost::system::error_category *v5; // eax
  boost::system::error_code rhs; // [esp+4h] [ebp-Ch] BYREF
  int level; // [esp+Ch] [ebp-4h] BYREF

  boost::asio::detail::socket_ops::connect(ec, a2, s, addr, addrlen);
  rhs.m_cat = boost::system::system_category();
  rhs.m_val = 10036;
  if ( !boost::system::operator!=(ec, &rhs)
    || (rhs.m_cat = boost::system::system_category(), rhs.m_val = 10035, !boost::system::operator!=(ec, &rhs)) )
  {
    if ( boost::asio::detail::socket_ops::poll_connect(s, ec) >= 0 )
    {
      level = 0;
      rhs.m_cat = (const boost::system::error_category *)4;
      if ( boost::asio::detail::socket_ops::getsockopt((unsigned int *)&rhs.m_cat, ec, s, 4103, (int)&level) != -1 )
      {
        v5 = boost::system::system_category();
        ec->m_val = level;
        ec->m_cat = v5;
      }
    }
  }
}

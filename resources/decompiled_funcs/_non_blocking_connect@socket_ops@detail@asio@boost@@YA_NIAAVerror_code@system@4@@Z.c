char __cdecl boost::asio::detail::socket_ops::non_blocking_connect(SOCKET s, boost::system::error_code *ec)
{
  const boost::system::error_category *v3; // [esp+4h] [ebp-78h]
  const boost::system::error_category *v4; // [esp+68h] [ebp-14h]
  int connect_error; // [esp+74h] [ebp-8h] BYREF
  unsigned int connect_error_len; // [esp+78h] [ebp-4h] BYREF

  connect_error = 0;
  connect_error_len = 4;
  if ( !boost::asio::detail::socket_ops::getsockopt(s, 0, 0xFFFF, 4103, (char *)&connect_error, &connect_error_len, ec) )
  {
    if ( connect_error )
    {
      v3 = boost::system::system_category();
      ec->m_val = connect_error;
      ec->m_cat = v3;
    }
    else
    {
      v4 = boost::system::system_category();
      ec->m_val = 0;
      ec->m_cat = v4;
    }
  }
  return 1;
}

char __cdecl boost::asio::detail::reactive_socket_connect_op_base::do_perform(boost::asio::detail::reactor_op *base)
{
  boost::system::error_code *p_ec; // esi
  boost::system::error_code *v2; // eax
  const struct boost::system::error_category *v3; // eax
  unsigned int Internal; // [esp-Ch] [ebp-18h]
  unsigned int v6; // [esp+8h] [ebp-4h] BYREF

  p_ec = &base->ec_;
  Internal = base[1].Internal;
  v2 = &base->ec_;
  base = 0;
  v6 = 4;
  if ( !boost::asio::detail::socket_ops::getsockopt(&v6, v2, Internal, 4103, (int)&base) )
  {
    if ( base )
    {
      v3 = boost::system::system_category();
      p_ec->m_val = (int)base;
    }
    else
    {
      v3 = boost::system::system_category();
      p_ec->m_val = 0;
    }
    p_ec->m_cat = v3;
  }
  return 1;
}

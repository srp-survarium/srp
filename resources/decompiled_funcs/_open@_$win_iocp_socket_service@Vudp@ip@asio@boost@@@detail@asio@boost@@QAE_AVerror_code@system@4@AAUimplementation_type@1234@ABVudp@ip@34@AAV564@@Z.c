boost::system::error_code *__thiscall boost::asio::detail::win_iocp_socket_service<boost::asio::ip::udp>::open(
        boost::asio::detail::win_iocp_socket_service<boost::asio::ip::udp> *this,
        boost::system::error_code *result,
        boost::asio::detail::win_iocp_socket_service<boost::asio::ip::udp>::implementation_type *impl,
        const boost::asio::ip::udp *protocol,
        boost::system::error_code *ec)
{
  const boost::system::error_category *m_cat; // ecx
  _DWORD v7[7]; // [esp+70h] [ebp-24h] BYREF
  boost::system::error_code v8; // [esp+8Ch] [ebp-8h] BYREF

  if ( !boost::asio::detail::win_iocp_socket_service_base::do_open(this, &v8, impl, protocol->family_, 2, 17, ec)->m_val )
  {
    impl->protocol_ = (boost::asio::ip::udp)protocol->family_;
    impl->have_remote_endpoint_ = 0;
    v7[0] = 2;
    memset(&v7[1], 0, 24);
    qmemcpy(&impl->remote_endpoint_, v7, sizeof(impl->remote_endpoint_));
  }
  m_cat = ec->m_cat;
  result->m_val = ec->m_val;
  result->m_cat = m_cat;
  return result;
}

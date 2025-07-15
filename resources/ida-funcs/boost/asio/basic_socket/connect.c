void __userpurge boost::asio::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp>>::connect(
        boost::asio::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp> > *this@<ecx>,
        int a2@<eax>,
        const boost::asio::ip::basic_endpoint<boost::asio::ip::udp> *peer_endpoint)
{
  const boost::system::error_category *v4; // eax
  bool v5; // zf
  boost::system::error_code v6; // [esp+Ch] [ebp-18h] BYREF
  boost::system::error_code ec; // [esp+14h] [ebp-10h] BYREF
  boost::asio::ip::udp v8; // [esp+1Ch] [ebp-8h] BYREF

  ec.m_val = 0;
  v4 = boost::system::system_category();
  v5 = *(_DWORD *)(a2 + 4) == -1;
  ec.m_cat = v4;
  if ( v5 )
  {
    v8.family_ = peer_endpoint->impl_.data_.base.sa_family != 2 ? 23 : 2;
    boost::asio::datagram_socket_service<boost::asio::ip::udp>::open(
      (boost::asio::detail::win_iocp_socket_service_base *)(a2 + 4),
      &ec,
      &v6,
      *(boost::asio::datagram_socket_service<boost::asio::ip::udp> **)a2,
      &v8);
    if ( (ec.m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
      boost::asio::detail::do_throw_error(&ec, "connect");
  }
  boost::asio::detail::socket_ops::sync_connect(
    &ec,
    a2 + 4,
    *(_DWORD *)(a2 + 4),
    &peer_endpoint->impl_.data_.base,
    peer_endpoint->impl_.data_.base.sa_family != 2 ? 28 : 16);
  if ( (ec.m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
    boost::asio::detail::do_throw_error(&ec, "connect");
}

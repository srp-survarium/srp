void __usercall boost::asio::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp>>::cancel(
        boost::asio::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp> > *this@<ecx>,
        int *a2@<eax>)
{
  const boost::system::error_category *v3; // eax
  int v4; // ecx
  boost::system::error_code v5; // [esp+8h] [ebp-10h] BYREF
  boost::system::error_code v6; // [esp+10h] [ebp-8h] BYREF

  v6.m_val = 0;
  v3 = boost::system::system_category();
  v4 = *a2;
  v6.m_cat = v3;
  boost::asio::detail::win_iocp_socket_service_base::cancel(
    (boost::asio::detail::win_iocp_socket_service_base::base_implementation_type *)(a2 + 1),
    &v6,
    (boost::asio::detail::win_iocp_socket_service_base *)(v4 + 20),
    &v5);
  if ( (v6.m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
    boost::asio::detail::do_throw_error(&v6, "cancel");
}

void __usercall boost::asio::basic_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>::close(
        boost::asio::basic_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp> > *this@<ecx>,
        int a2@<edi>)
{
  boost::system::error_code v2; // [esp+8h] [ebp-10h] BYREF
  boost::system::error_code v3; // [esp+10h] [ebp-8h] BYREF

  v3.m_val = 0;
  v3.m_cat = boost::system::system_category();
  boost::asio::detail::win_iocp_socket_service_base::close(
    (boost::asio::detail::win_iocp_socket_service_base *)(*(_DWORD *)a2 + 20),
    (boost::asio::detail::win_iocp_socket_service_base::base_implementation_type *)(a2 + 4),
    &v2,
    &v3);
  if ( (v3.m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
    boost::asio::detail::do_throw_error(&v3, "close");
}

void __usercall boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>::~basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>(
        boost::asio::basic_datagram_socket<boost::asio::ip::udp,boost::asio::datagram_socket_service<boost::asio::ip::udp> > *this@<ecx>,
        int a2@<esi>)
{
  boost::detail::shared_count *v2; // ecx

  boost::asio::detail::win_iocp_socket_service_base::destroy(
    (boost::asio::detail::win_iocp_socket_service_base *)(*(_DWORD *)a2 + 20),
    (boost::asio::detail::win_iocp_socket_service_base::base_implementation_type *)(a2 + 4));
  boost::detail::shared_count::~shared_count(v2, (volatile signed __int32 **)(a2 + 16));
}

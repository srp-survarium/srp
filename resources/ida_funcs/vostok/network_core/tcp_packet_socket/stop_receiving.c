void __thiscall vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp>>>::stop_receiving(
        vostok::network_core::tcp_packet_socket<boost::asio::basic_stream_socket<boost::asio::ip::tcp,boost::asio::stream_socket_service<boost::asio::ip::tcp> > > *this)
{
  boost::system::error_code result; // [esp+98h] [ebp-10h] BYREF
  boost::system::error_code error_code; // [esp+A0h] [ebp-8h] BYREF

  error_code.m_val = 0;
  error_code.m_cat = boost::system::system_category();
  boost::asio::detail::win_iocp_socket_service_base::cancel(
    &this->m_socket->service->service_impl_,
    &result,
    &this->m_socket->implementation,
    &error_code);
}

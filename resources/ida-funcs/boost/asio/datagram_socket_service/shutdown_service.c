void __thiscall boost::asio::datagram_socket_service<boost::asio::ip::udp>::shutdown_service(
        boost::asio::stream_socket_service<boost::asio::ip::tcp> *this)
{
  boost::asio::detail::win_iocp_socket_service_base::shutdown_service(
    (boost::asio::detail::win_iocp_socket_service_base *)this,
    &this->service_impl_);
}

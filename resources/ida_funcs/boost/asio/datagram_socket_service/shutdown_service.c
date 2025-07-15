void __thiscall boost::asio::datagram_socket_service<boost::asio::ip::udp>::shutdown_service(
        boost::asio::datagram_socket_service<boost::asio::ip::udp> *this)
{
  boost::asio::detail::win_iocp_socket_service_base::shutdown_service(&this->service_impl_);
}

void __thiscall boost::asio::datagram_socket_service<boost::asio::ip::udp>::construct(
        boost::asio::datagram_socket_service<boost::asio::ip::udp> *this,
        boost::asio::detail::win_iocp_socket_service<boost::asio::ip::udp>::implementation_type *impl)
{
  boost::asio::detail::win_iocp_socket_service_base::construct(&this->service_impl_, impl);
}

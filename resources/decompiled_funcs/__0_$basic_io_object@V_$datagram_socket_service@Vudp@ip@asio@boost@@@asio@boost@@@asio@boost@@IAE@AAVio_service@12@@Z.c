void __thiscall boost::asio::basic_io_object<boost::asio::datagram_socket_service<boost::asio::ip::udp>>::basic_io_object<boost::asio::datagram_socket_service<boost::asio::ip::udp>>(
        boost::asio::basic_io_object<boost::asio::datagram_socket_service<boost::asio::ip::udp> > *this,
        boost::asio::io_service *io_service)
{
  this->service = boost::asio::detail::service_registry::use_service<boost::asio::datagram_socket_service<boost::asio::ip::udp>>(io_service->service_registry_);
  boost::asio::detail::win_iocp_socket_service<boost::asio::ip::udp>::implementation_type::implementation_type(&this->implementation);
  boost::asio::detail::win_iocp_socket_service_base::construct(&this->service->service_impl_, &this->implementation);
}

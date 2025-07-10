void __thiscall boost::asio::basic_io_object<boost::asio::stream_socket_service<boost::asio::ip::tcp>>::basic_io_object<boost::asio::stream_socket_service<boost::asio::ip::tcp>>(
        boost::asio::basic_io_object<boost::asio::stream_socket_service<boost::asio::ip::tcp> > *this,
        boost::asio::io_service *io_service)
{
  this->service = boost::asio::detail::service_registry::use_service<boost::asio::stream_socket_service<boost::asio::ip::tcp>>(io_service->service_registry_);
  boost::asio::detail::win_iocp_socket_service<boost::asio::ip::udp>::implementation_type::implementation_type((boost::asio::detail::win_iocp_socket_service<boost::asio::ip::udp>::implementation_type *)&this->implementation);
  boost::asio::detail::win_iocp_socket_service_base::construct(&this->service->service_impl_, &this->implementation);
}

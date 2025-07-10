void __thiscall boost::asio::basic_io_object<boost::asio::ip::resolver_service<boost::asio::ip::udp>>::basic_io_object<boost::asio::ip::resolver_service<boost::asio::ip::udp>>(
        boost::asio::basic_io_object<boost::asio::ip::resolver_service<boost::asio::ip::udp> > *this,
        boost::asio::io_service *io_service)
{
  this->service = boost::asio::detail::service_registry::use_service<boost::asio::ip::resolver_service<boost::asio::ip::udp>>(io_service->service_registry_);
  this->implementation.px = 0;
  this->implementation.pn.pi_ = 0;
  boost::shared_ptr<void>::reset<void,boost::asio::detail::socket_ops::noop_deleter>(&this->implementation, 0, 0);
}

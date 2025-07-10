void __thiscall boost::asio::ip::resolver_service<boost::asio::ip::udp>::fork_service(
        boost::asio::ip::resolver_service<boost::asio::ip::udp> *this,
        boost::asio::io_service::fork_event event)
{
  boost::asio::detail::resolver_service_base::fork_service(&this->service_impl_, event);
}

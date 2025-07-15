void __thiscall boost::asio::ip::resolver_service<boost::asio::ip::udp>::fork_service(
        boost::asio::ip::resolver_service<boost::asio::ip::tcp> *this,
        boost::asio::io_service::fork_event event)
{
  boost::asio::detail::resolver_service_base::fork_service(
    (boost::asio::detail::resolver_service_base *)this,
    (boost::asio::detail::resolver_service_base::work_io_service_runner *)&this->service_impl_,
    event);
}

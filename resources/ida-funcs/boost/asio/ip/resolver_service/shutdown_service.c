void __thiscall boost::asio::ip::resolver_service<boost::asio::ip::tcp>::shutdown_service(
        boost::asio::ip::resolver_service<boost::asio::ip::tcp> *this)
{
  boost::asio::detail::resolver_service_base::shutdown_service(&this->service_impl_, (HANDLE **)&this->service_impl_);
}

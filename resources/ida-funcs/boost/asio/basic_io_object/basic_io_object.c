void __thiscall boost::asio::basic_io_object<boost::asio::datagram_socket_service<boost::asio::ip::udp>>::basic_io_object<boost::asio::datagram_socket_service<boost::asio::ip::udp>>(
        boost::asio::basic_io_object<boost::asio::datagram_socket_service<boost::asio::ip::udp> > *this,
        boost::asio::io_service *io_service)
{
  this->service = boost::asio::detail::service_registry::use_service<boost::asio::datagram_socket_service<boost::asio::ip::udp>>(io_service->service_registry_);
  boost::asio::detail::win_iocp_socket_service<boost::asio::ip::udp>::implementation_type::implementation_type(&this->implementation);
  boost::asio::detail::win_iocp_socket_service_base::construct(&this->service->service_impl_, &this->implementation);
}


void __thiscall boost::asio::basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>::basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>(
        boost::asio::basic_io_object<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime> > > *this,
        boost::asio::io_service *io_service)
{
  int *v2; // eax
  int v3; // edx
  int v4; // eax
  boost::posix_time::ptime v6; // [esp+23Ch] [ebp-70h] BYREF

  this->service = boost::asio::detail::service_registry::use_service<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>(io_service->service_registry_);
  boost::asio::detail::deadline_timer_service<boost::asio::time_traits<boost::posix_time::ptime>>::implementation_type::implementation_type(&this->implementation);
  boost::posix_time::ptime::ptime(&v6);
  v3 = *v2;
  v4 = v2[1];
  LODWORD(this->implementation.expiry.time_.time_count_.value_) = v3;
  HIDWORD(this->implementation.expiry.time_.time_count_.value_) = v4;
  this->implementation.might_have_pending_waits = 0;
}


void __thiscall boost::asio::basic_io_object<boost::asio::ip::resolver_service<boost::asio::ip::tcp>>::basic_io_object<boost::asio::ip::resolver_service<boost::asio::ip::tcp>>(
        boost::asio::basic_io_object<boost::asio::ip::resolver_service<boost::asio::ip::tcp> > *this,
        boost::asio::io_service *io_service)
{
  this->service = boost::asio::detail::service_registry::use_service<boost::asio::ip::resolver_service<boost::asio::ip::tcp>>(io_service->service_registry_);
  this->implementation.px = 0;
  this->implementation.pn.pi_ = 0;
  boost::shared_ptr<void>::reset<void,boost::asio::detail::socket_ops::noop_deleter>(&this->implementation, 0, 0);
}


void __thiscall boost::asio::basic_io_object<boost::asio::ip::resolver_service<boost::asio::ip::udp>>::basic_io_object<boost::asio::ip::resolver_service<boost::asio::ip::udp>>(
        boost::asio::basic_io_object<boost::asio::ip::resolver_service<boost::asio::ip::udp> > *this,
        boost::asio::io_service *io_service)
{
  this->service = boost::asio::detail::service_registry::use_service<boost::asio::ip::resolver_service<boost::asio::ip::udp>>(io_service->service_registry_);
  this->implementation.px = 0;
  this->implementation.pn.pi_ = 0;
  boost::shared_ptr<void>::reset<void,boost::asio::detail::socket_ops::noop_deleter>(&this->implementation, 0, 0);
}


void __thiscall boost::asio::basic_io_object<boost::asio::stream_socket_service<boost::asio::ip::tcp>>::basic_io_object<boost::asio::stream_socket_service<boost::asio::ip::tcp>>(
        boost::asio::basic_io_object<boost::asio::stream_socket_service<boost::asio::ip::tcp> > *this,
        boost::asio::io_service *io_service)
{
  this->service = boost::asio::detail::service_registry::use_service<boost::asio::stream_socket_service<boost::asio::ip::tcp>>(io_service->service_registry_);
  boost::asio::detail::win_iocp_socket_service<boost::asio::ip::udp>::implementation_type::implementation_type((boost::asio::detail::win_iocp_socket_service<boost::asio::ip::udp>::implementation_type *)&this->implementation);
  boost::asio::detail::win_iocp_socket_service_base::construct(&this->service->service_impl_, &this->implementation);
}

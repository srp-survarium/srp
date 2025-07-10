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

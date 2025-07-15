boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime> > *__thiscall boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>::`vector deleting destructor'(
        boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime> > *this,
        char a2)
{
  boost::asio::detail::deadline_timer_service<boost::asio::time_traits<boost::posix_time::ptime>>::~deadline_timer_service<boost::asio::time_traits<boost::posix_time::ptime>>(
    (boost::asio::detail::deadline_timer_service<boost::asio::time_traits<boost::posix_time::ptime> > *)this,
    (int)&this->service_impl_);
  this->__vftable = (boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime> >_vtbl *)&boost::asio::io_service::service::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}

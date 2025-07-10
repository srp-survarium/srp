void __thiscall boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>(
        boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime> > *this,
        boost::asio::io_service *io_service)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->key_);
  this->__vftable = (boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime> >_vtbl *)&boost::asio::io_service::service::`vftable';
  this->key_.type_info_ = 0;
  this->key_.id_ = 0;
  this->owner_ = io_service;
  this->next_ = 0;
  this->__vftable = (boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime> >_vtbl *)&boost::asio::detail::service_base<boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>>::`vftable';
  this->__vftable = (boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime> >_vtbl *)&boost::asio::deadline_timer_service<boost::posix_time::ptime,boost::asio::time_traits<boost::posix_time::ptime>>::`vftable';
  boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>(&this->service_impl_.timer_queue_);
  this->service_impl_.scheduler_ = io_service->impl_;
  boost::asio::detail::win_iocp_io_service::add_timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>(
    this->service_impl_.scheduler_,
    &this->service_impl_.timer_queue_);
}

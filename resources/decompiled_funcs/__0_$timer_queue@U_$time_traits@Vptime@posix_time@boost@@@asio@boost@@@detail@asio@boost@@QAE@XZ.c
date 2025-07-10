void __thiscall boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>(
        boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> > *this)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->next_);
  this->__vftable = (boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> >_vtbl *)&boost::asio::detail::timer_queue_base::`vftable';
  this->next_ = 0;
  this->__vftable = (boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> >_vtbl *)&boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::`vftable';
  this->timers_ = 0;
  this->heap_._M_impl._M_start = 0;
  this->heap_._M_impl._M_finish = 0;
  this->heap_._M_impl._M_end_of_storage._M_data = 0;
}

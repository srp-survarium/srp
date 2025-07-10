void __thiscall boost::asio::detail::deadline_timer_service<boost::asio::time_traits<boost::posix_time::ptime>>::implementation_type::implementation_type(
        boost::asio::detail::deadline_timer_service<boost::asio::time_traits<boost::posix_time::ptime> >::implementation_type *this)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  boost::posix_time::ptime::ptime(&this->expiry);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->timer_data);
  this->timer_data.op_queue_.front_ = 0;
  this->timer_data.op_queue_.back_ = 0;
  this->timer_data.next_ = 0;
  this->timer_data.prev_ = 0;
}

void __thiscall boost::asio::detail::deadline_timer_service<boost::asio::time_traits<boost::posix_time::ptime>>::~deadline_timer_service<boost::asio::time_traits<boost::posix_time::ptime>>(
        boost::asio::detail::deadline_timer_service<boost::asio::time_traits<boost::posix_time::ptime> > *this)
{
  boost::asio::detail::win_iocp_io_service::remove_timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>(
    this->scheduler_,
    &this->timer_queue_);
  stlp_std::priv::_Impl_vector<boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::heap_entry,stlp_std::allocator<boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::heap_entry>>::~_Impl_vector<boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::heap_entry,stlp_std::allocator<boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::heap_entry>>(&this->timer_queue_.heap_._M_impl);
  this->timer_queue_.__vftable = (boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> >_vtbl *)&boost::asio::detail::timer_queue_base::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->timer_queue_.next_);
}

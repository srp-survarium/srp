boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> > *__thiscall boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::`scalar deleting destructor'(
        boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> > *this,
        char a2)
{
  stlp_std::priv::_Impl_vector<boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::heap_entry,stlp_std::allocator<boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::heap_entry>>::~_Impl_vector<boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::heap_entry,stlp_std::allocator<boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::heap_entry>>(&this->heap_._M_impl);
  this->__vftable = (boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> >_vtbl *)&boost::asio::detail::timer_queue_base::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->next_);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}

bool __thiscall boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::empty(
        boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> > *this)
{
  return this->timers_ == 0;
}

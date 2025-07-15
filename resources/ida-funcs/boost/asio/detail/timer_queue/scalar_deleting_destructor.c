boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> > *__thiscall boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::`scalar deleting destructor'(
        boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> > *this,
        char a2)
{
  boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::~timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>(
    this,
    this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}

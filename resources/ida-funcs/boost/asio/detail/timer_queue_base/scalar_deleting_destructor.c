boost::asio::detail::timer_queue_base *__thiscall boost::asio::detail::timer_queue_base::`scalar deleting destructor'(
        boost::asio::detail::timer_queue_base *this,
        char a2)
{
  this->__vftable = (boost::asio::detail::timer_queue_base_vtbl *)&boost::asio::detail::timer_queue_base::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}

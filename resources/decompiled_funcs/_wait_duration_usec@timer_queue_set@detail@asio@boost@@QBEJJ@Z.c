int __thiscall boost::asio::detail::timer_queue_set::wait_duration_usec(
        boost::asio::detail::timer_queue_set *this,
        int max_duration)
{
  boost::asio::detail::timer_queue_base *p; // [esp+4h] [ebp-8h]

  for ( p = this->first_; p; p = p->next_ )
    max_duration = p->wait_duration_usec(p, max_duration);
  return max_duration;
}

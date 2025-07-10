void __thiscall boost::asio::detail::timer_queue_set::get_ready_timers(
        boost::asio::detail::timer_queue_set *this,
        boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *ops)
{
  boost::asio::detail::timer_queue_base *p; // [esp+4h] [ebp-4h]

  for ( p = this->first_; p; p = p->next_ )
    p->get_ready_timers(p, ops);
}

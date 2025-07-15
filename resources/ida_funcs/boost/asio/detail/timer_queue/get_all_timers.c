void __thiscall boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::get_all_timers(
        boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> > *this,
        boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *ops)
{
  boost::asio::detail::win_iocp_operation *front; // [esp+28h] [ebp-8h]
  boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> >::per_timer_data *timer; // [esp+2Ch] [ebp-4h]

  while ( this->timers_ )
  {
    timer = this->timers_;
    this->timers_ = timer->next_;
    front = timer->op_queue_.front_;
    if ( timer->op_queue_.front_ )
    {
      if ( ops->back_ )
        ops->back_->next_ = front;
      else
        ops->front_ = front;
      ops->back_ = timer->op_queue_.back_;
      timer->op_queue_.front_ = 0;
      timer->op_queue_.back_ = 0;
    }
    timer->next_ = 0;
    timer->prev_ = 0;
  }
  stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::clear((stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property> > *)&this->heap_);
}

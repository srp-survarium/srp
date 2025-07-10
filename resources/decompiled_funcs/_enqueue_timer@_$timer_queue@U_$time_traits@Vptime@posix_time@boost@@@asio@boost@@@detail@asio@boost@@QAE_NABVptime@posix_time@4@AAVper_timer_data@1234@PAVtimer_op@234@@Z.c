bool __thiscall boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::enqueue_timer(
        boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> > *this,
        const boost::posix_time::ptime *time,
        boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> >::per_timer_data *timer,
        boost::asio::detail::timer_op *op)
{
  int value_high; // eax
  boost::date_time::counted_time_rep<boost::posix_time::millisec_posix_time_system_config> result; // [esp+A8h] [ebp-18h] BYREF
  boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> >::heap_entry entry; // [esp+B0h] [ebp-10h] BYREF

  if ( !timer->prev_ && timer != this->timers_ )
  {
    boost::date_time::counted_time_system<boost::date_time::counted_time_rep<boost::posix_time::millisec_posix_time_system_config>>::get_time_rep(
      &result,
      pos_infin);
    if ( time->time_.time_count_.value_ == result.time_count_.value_ )
    {
      timer->heap_index_ = -1;
    }
    else
    {
      timer->heap_index_ = this->heap_._M_impl._M_finish - this->heap_._M_impl._M_start;
      value_high = HIDWORD(time->time_.time_count_.value_);
      LODWORD(entry.time_.time_.time_count_.value_) = time->time_.time_count_.value_;
      HIDWORD(entry.time_.time_.time_count_.value_) = value_high;
      entry.timer_ = timer;
      stlp_std::priv::_Impl_vector<boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::heap_entry,stlp_std::allocator<boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::heap_entry>>::push_back(
        &this->heap_._M_impl,
        &entry);
      boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::up_heap(
        this,
        this->heap_._M_impl._M_finish - this->heap_._M_impl._M_start - 1);
    }
    timer->next_ = this->timers_;
    timer->prev_ = 0;
    if ( this->timers_ )
      this->timers_->prev_ = timer;
    this->timers_ = timer;
  }
  op->next_ = 0;
  if ( timer->op_queue_.back_ )
  {
    timer->op_queue_.back_->next_ = op;
    timer->op_queue_.back_ = op;
  }
  else
  {
    timer->op_queue_.back_ = op;
    timer->op_queue_.front_ = op;
  }
  return !timer->heap_index_ && timer->op_queue_.front_ == op;
}

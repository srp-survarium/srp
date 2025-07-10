unsigned int __thiscall boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::cancel_timer(
        boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> > *this,
        boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> >::per_timer_data *timer,
        boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *ops,
        unsigned int max_cancelled)
{
  boost::asio::detail::timer_op *v5; // [esp+0h] [ebp-180h]
  boost::asio::detail::timer_op *front; // [esp+160h] [ebp-20h]
  const struct boost::system::error_category *v8; // [esp+170h] [ebp-10h]
  unsigned int num_cancelled; // [esp+17Ch] [ebp-4h]

  num_cancelled = 0;
  if ( timer->prev_ || timer == this->timers_ )
  {
    while ( 1 )
    {
      v5 = num_cancelled == max_cancelled ? 0 : timer->op_queue_.front_;
      if ( !v5 )
        break;
      v8 = boost::system::system_category();
      v5->ec_.m_val = 995;
      v5->ec_.m_cat = v8;
      if ( timer->op_queue_.front_ )
      {
        front = timer->op_queue_.front_;
        timer->op_queue_.front_ = (boost::asio::detail::timer_op *)timer->op_queue_.front_->next_;
        if ( !timer->op_queue_.front_ )
          timer->op_queue_.back_ = 0;
        front->next_ = 0;
      }
      v5->next_ = 0;
      if ( ops->back_ )
      {
        ops->back_->next_ = v5;
        ops->back_ = v5;
      }
      else
      {
        ops->back_ = v5;
        ops->front_ = v5;
      }
      ++num_cancelled;
    }
    if ( !timer->op_queue_.front_ )
      boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::remove_timer(this, timer);
  }
  return num_cancelled;
}

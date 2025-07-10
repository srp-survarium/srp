void __thiscall boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::get_ready_timers(
        boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> > *this,
        boost::asio::detail::op_queue<boost::asio::detail::win_iocp_operation> *ops)
{
  boost::asio::detail::win_iocp_operation *front; // [esp+154h] [ebp-40h]
  boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> >::per_timer_data *timer; // [esp+188h] [ebp-Ch]
  boost::posix_time::ptime now; // [esp+18Ch] [ebp-8h] BYREF

  if ( this->heap_._M_impl._M_start != this->heap_._M_impl._M_finish )
  {
    boost::date_time::microsec_clock<boost::posix_time::ptime>::create_time(&now, boost::date_time::c_time::gmtime);
    while ( this->heap_._M_impl._M_start != this->heap_._M_impl._M_finish
         && now.time_.time_count_.value_ >= this->heap_._M_impl._M_start->time_.time_.time_count_.value_ )
    {
      timer = this->heap_._M_impl._M_start->timer_;
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
      boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::remove_timer(this, timer);
    }
  }
}

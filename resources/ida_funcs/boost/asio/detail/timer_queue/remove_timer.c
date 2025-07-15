void __thiscall boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::remove_timer(
        boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> > *this,
        boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> >::per_timer_data *timer)
{
  unsigned int index; // [esp+180h] [ebp-4h]

  index = timer->heap_index_;
  if ( this->heap_._M_impl._M_start != this->heap_._M_impl._M_finish
    && index < this->heap_._M_impl._M_finish - this->heap_._M_impl._M_start )
  {
    if ( index == this->heap_._M_impl._M_finish - this->heap_._M_impl._M_start - 1 )
    {
      --this->heap_._M_impl._M_finish;
    }
    else
    {
      boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::swap_heap(
        this,
        index,
        this->heap_._M_impl._M_finish - this->heap_._M_impl._M_start - 1);
      --this->heap_._M_impl._M_finish;
      if ( index
        && this->heap_._M_impl._M_start[index].time_.time_.time_count_.value_ < this->heap_._M_impl._M_start[(index - 1) >> 1].time_.time_.time_count_.value_ )
      {
        boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::up_heap(this, index);
      }
      else
      {
        boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::down_heap(this, index);
      }
    }
  }
  if ( this->timers_ == timer )
    this->timers_ = timer->next_;
  if ( timer->prev_ )
    timer->prev_->next_ = timer->next_;
  if ( timer->next_ )
    timer->next_->prev_ = timer->prev_;
  timer->next_ = 0;
  timer->prev_ = 0;
}

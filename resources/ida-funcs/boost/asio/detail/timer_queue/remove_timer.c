void __usercall boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::remove_timer(
        boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> > *this@<eax>,
        boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> >::per_timer_data *timer@<edi>,
        boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> > *a3@<ecx>)
{
  unsigned int heap_index; // ebx
  boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> > *v5; // ecx
  boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> >::per_timer_data *prev; // eax
  boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> >::per_timer_data *next; // eax

  heap_index = timer->heap_index_;
  if ( this->heap_._M_impl._M_start != this->heap_._M_impl._M_finish
    && heap_index < this->heap_._M_impl._M_finish - this->heap_._M_impl._M_start )
  {
    if ( heap_index == this->heap_._M_impl._M_finish - this->heap_._M_impl._M_start - 1 )
    {
      --this->heap_._M_impl._M_finish;
    }
    else
    {
      boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::swap_heap(
        a3,
        (int)this,
        heap_index,
        this->heap_._M_impl._M_finish - this->heap_._M_impl._M_start - 1);
      --this->heap_._M_impl._M_finish;
      if ( heap_index
        && boost::asio::time_traits<boost::posix_time::ptime>::less_than(
             &this->heap_._M_impl._M_start[heap_index].time_,
             &this->heap_._M_impl._M_start[(heap_index - 1) >> 1].time_) )
      {
        boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::up_heap(heap_index, this);
      }
      else
      {
        boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::down_heap(
          v5,
          (int)this,
          heap_index);
      }
    }
  }
  if ( this->timers_ == timer )
    this->timers_ = timer->next_;
  prev = timer->prev_;
  if ( prev )
    prev->next_ = timer->next_;
  next = timer->next_;
  if ( next )
    next->prev_ = timer->prev_;
  timer->next_ = 0;
  timer->prev_ = 0;
}

void __thiscall boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::down_heap(
        boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> > *this,
        unsigned int index)
{
  unsigned int v2; // [esp+4h] [ebp-A4h]
  unsigned int child; // [esp+A4h] [ebp-4h]

  for ( child = 2 * index + 1; child < this->heap_._M_impl._M_finish - this->heap_._M_impl._M_start; child = 2 * v2 + 1 )
  {
    v2 = child + 1 == this->heap_._M_impl._M_finish - this->heap_._M_impl._M_start
      || this->heap_._M_impl._M_start[child].time_.time_.time_count_.value_ < this->heap_._M_impl._M_start[child + 1].time_.time_.time_count_.value_
       ? child
       : child + 1;
    if ( this->heap_._M_impl._M_start[index].time_.time_.time_count_.value_ < this->heap_._M_impl._M_start[v2].time_.time_.time_count_.value_ )
      break;
    boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::swap_heap(this, index, v2);
    index = v2;
  }
}

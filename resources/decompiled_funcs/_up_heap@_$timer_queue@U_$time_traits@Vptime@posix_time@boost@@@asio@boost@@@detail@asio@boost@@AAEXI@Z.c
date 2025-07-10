void __thiscall boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::up_heap(
        boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> > *this,
        unsigned int index)
{
  unsigned int parent; // [esp+60h] [ebp-4h]

  for ( parent = (index - 1) >> 1;
        index
     && this->heap_._M_impl._M_start[index].time_.time_.time_count_.value_ < this->heap_._M_impl._M_start[parent].time_.time_.time_count_.value_;
        parent = (parent - 1) >> 1 )
  {
    boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::swap_heap(this, index, parent);
    index = parent;
  }
}

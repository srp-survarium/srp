void __userpurge boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::up_heap(
        unsigned int index@<eax>,
        boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> > *this)
{
  unsigned int v2; // edi
  unsigned int i; // esi
  boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> > *v4; // ecx
  unsigned int v5; // esi

  v2 = index;
  for ( i = index - 1; ; i = v5 - 1 )
  {
    v5 = i >> 1;
    if ( !v2
      || !boost::asio::time_traits<boost::posix_time::ptime>::less_than(
            &this->heap_._M_impl._M_start[v2].time_,
            &this->heap_._M_impl._M_start[v5].time_) )
    {
      break;
    }
    boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::swap_heap(
      v4,
      (int)this,
      v2,
      v5);
    v2 = v5;
  }
}

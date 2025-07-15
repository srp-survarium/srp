void __userpurge boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::down_heap(
        boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> > *this@<ecx>,
        int a2@<esi>,
        unsigned int index)
{
  unsigned int v3; // ebx
  unsigned int i; // edi
  boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> > *v5; // ecx

  v3 = index;
  for ( i = 2 * index + 1; i < (*(_DWORD *)(a2 + 16) - *(_DWORD *)(a2 + 12)) >> 4; i = 2 * i + 1 )
  {
    if ( i + 1 != (*(_DWORD *)(a2 + 16) - *(_DWORD *)(a2 + 12)) >> 4
      && !boost::asio::time_traits<boost::posix_time::ptime>::less_than(
            (const boost::posix_time::ptime *)(16 * i + *(_DWORD *)(a2 + 12)),
            (const boost::posix_time::ptime *)(16 * i + *(_DWORD *)(a2 + 12) + 16)) )
    {
      ++i;
    }
    if ( boost::asio::time_traits<boost::posix_time::ptime>::less_than(
           (const boost::posix_time::ptime *)(*(_DWORD *)(a2 + 12) + 16 * v3),
           (const boost::posix_time::ptime *)(*(_DWORD *)(a2 + 12) + 16 * i)) )
    {
      break;
    }
    boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::swap_heap(v5, a2, v3, i);
    v3 = i;
  }
}

void __usercall boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::~timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>(
        boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> > *this@<ecx>,
        _DWORD *a2@<esi>)
{
  _STLP_atomic_freelist::item *v2; // eax

  v2 = (_STLP_atomic_freelist::item *)a2[3];
  if ( v2 )
    stlp_std::__node_alloc::deallocate(v2, 16 * ((a2[5] - (int)v2) >> 4));
  *a2 = &boost::asio::detail::timer_queue_base::`vftable';
}

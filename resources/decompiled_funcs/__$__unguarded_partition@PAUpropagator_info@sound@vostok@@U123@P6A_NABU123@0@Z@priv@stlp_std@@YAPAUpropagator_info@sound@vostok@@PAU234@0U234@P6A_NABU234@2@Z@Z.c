vostok::sound::propagator_info *__cdecl stlp_std::priv::__unguarded_partition<vostok::sound::propagator_info *,vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
        vostok::sound::propagator_info *__first,
        vostok::sound::propagator_info *__last,
        vostok::sound::propagator_info __pivot,
        bool (__cdecl *__comp)(const vostok::sound::propagator_info *, const vostok::sound::propagator_info *))
{
  while ( 1 )
  {
    while ( __comp(__first, &__pivot) )
      ++__first;
    for ( --__last; __comp(&__pivot, __last); --__last )
      ;
    if ( __first >= __last )
      break;
    stlp_std::iter_swap<vostok::sound::propagator_info *,vostok::sound::propagator_info *>(__first++, __last);
  }
  return __first;
}

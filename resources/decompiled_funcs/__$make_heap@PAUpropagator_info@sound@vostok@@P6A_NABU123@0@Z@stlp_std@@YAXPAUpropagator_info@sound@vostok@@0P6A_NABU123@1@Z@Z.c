void __cdecl stlp_std::make_heap<vostok::sound::propagator_info *,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
        vostok::sound::propagator_info *__first,
        vostok::sound::propagator_info *__last,
        bool (__cdecl *__comp)(const vostok::sound::propagator_info *, const vostok::sound::propagator_info *))
{
  int __holeIndex; // [esp+14h] [ebp-8h]

  if ( __last - __first >= 2 )
  {
    for ( __holeIndex = (__last - __first - 2) / 2; ; --__holeIndex )
    {
      stlp_std::__adjust_heap<vostok::sound::propagator_info *,int,vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
        __first,
        __holeIndex,
        __last - __first,
        __first[__holeIndex],
        __comp);
      if ( !__holeIndex )
        break;
    }
  }
}

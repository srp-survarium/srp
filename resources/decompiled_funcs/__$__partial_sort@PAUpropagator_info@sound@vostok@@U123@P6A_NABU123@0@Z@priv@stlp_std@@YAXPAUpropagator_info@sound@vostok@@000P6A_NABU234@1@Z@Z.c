void __cdecl stlp_std::priv::__partial_sort<vostok::sound::propagator_info *,vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
        vostok::sound::propagator_info *__first,
        vostok::sound::propagator_info *__middle,
        vostok::sound::propagator_info *__last,
        vostok::sound::propagator_info *__formal,
        bool (__cdecl *__comp)(const vostok::sound::propagator_info *, const vostok::sound::propagator_info *))
{
  vostok::sound::propagator_info *i; // [esp+4h] [ebp-1Ch]
  vostok::sound::propagator_info v6; // [esp+8h] [ebp-18h]
  vostok::sound::propagator_info *__i; // [esp+1Ch] [ebp-4h]

  stlp_std::make_heap<vostok::sound::propagator_info *,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
    __first,
    __middle,
    __comp);
  for ( __i = __middle; __i < __last; ++__i )
  {
    if ( __comp(__i, __first) )
    {
      v6 = *__i;
      *__i = *__first;
      stlp_std::__adjust_heap<vostok::sound::propagator_info *,int,vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
        __first,
        0,
        __middle - __first,
        v6,
        __comp);
    }
  }
  for ( i = __middle; i - __first > 1; --i )
    stlp_std::pop_heap<vostok::sound::propagator_info *,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
      __first,
      i,
      __comp);
}

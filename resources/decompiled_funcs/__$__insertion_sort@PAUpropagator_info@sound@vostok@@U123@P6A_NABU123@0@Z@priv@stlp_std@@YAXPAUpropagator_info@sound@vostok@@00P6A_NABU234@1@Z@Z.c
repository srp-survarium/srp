void __cdecl stlp_std::priv::__insertion_sort<vostok::sound::propagator_info *,vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
        vostok::sound::propagator_info *__first,
        vostok::sound::propagator_info *__last,
        vostok::sound::propagator_info *__formal,
        bool (__cdecl *__comp)(const vostok::sound::propagator_info *, const vostok::sound::propagator_info *))
{
  vostok::sound::propagator_info v4; // [esp+0h] [ebp-24h] BYREF
  vostok::sound::propagator_info *__i; // [esp+20h] [ebp-4h]

  if ( __first != __last )
  {
    for ( __i = __first + 1; __i != __last; ++__i )
    {
      v4 = *__i;
      if ( __comp(&v4, __first) )
      {
        stlp_std::copy_backward<vostok::sound::propagator_info *,vostok::sound::propagator_info *>(
          __first,
          __i,
          __i + 1);
        *__first = v4;
      }
      else
      {
        stlp_std::priv::__unguarded_linear_insert<vostok::sound::propagator_info *,vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
          __i,
          v4,
          __comp);
      }
    }
  }
}

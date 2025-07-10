void __cdecl stlp_std::priv::__introsort_loop<vostok::sound::propagator_info *,vostok::sound::propagator_info,int,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
        vostok::sound::propagator_info *__first,
        vostok::sound::propagator_info *__last,
        vostok::sound::propagator_info *__formal,
        int __depth_limit,
        bool (__cdecl *__comp)(const vostok::sound::propagator_info *, const vostok::sound::propagator_info *))
{
  vostok::sound::propagator_info v5; // [esp-18h] [ebp-30h]
  vostok::sound::propagator_info *__cut; // [esp+14h] [ebp-4h]

  while ( __last - __first > 16 )
  {
    if ( !__depth_limit )
    {
      stlp_std::partial_sort<vostok::sound::propagator_info *,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
        __first,
        __last,
        __last,
        __comp);
      return;
    }
    --__depth_limit;
    v5 = *stlp_std::priv::__median<vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
            __first,
            &__first[(__last - __first) / 2],
            __last - 1,
            __comp);
    __cut = stlp_std::priv::__unguarded_partition<vostok::sound::propagator_info *,vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
              __first,
              __last,
              v5,
              __comp);
    stlp_std::priv::__introsort_loop<vostok::sound::propagator_info *,vostok::sound::propagator_info,int,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
      __cut,
      __last,
      0,
      __depth_limit,
      __comp);
    __last = __cut;
  }
}

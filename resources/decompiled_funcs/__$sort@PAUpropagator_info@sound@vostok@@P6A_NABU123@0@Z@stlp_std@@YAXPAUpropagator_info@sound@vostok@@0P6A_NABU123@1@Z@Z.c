void __cdecl stlp_std::sort<vostok::sound::propagator_info *,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
        vostok::sound::propagator_info *__first,
        vostok::sound::propagator_info *__last,
        bool (__cdecl *__comp)(const vostok::sound::propagator_info *, const vostok::sound::propagator_info *))
{
  int v3; // [esp+0h] [ebp-8h]
  int v4; // [esp+4h] [ebp-4h]

  if ( __first != __last )
  {
    v3 = __last - __first;
    v4 = 0;
    while ( v3 != 1 )
    {
      ++v4;
      v3 >>= 1;
    }
    stlp_std::priv::__introsort_loop<vostok::sound::propagator_info *,vostok::sound::propagator_info,int,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
      __first,
      __last,
      0,
      2 * v4,
      __comp);
    stlp_std::priv::__final_insertion_sort<vostok::sound::propagator_info *,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
      __first,
      __last,
      __comp);
  }
}

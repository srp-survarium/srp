void __cdecl stlp_std::priv::__final_insertion_sort<vostok::sound::propagator_info *,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
        vostok::sound::propagator_info *__first,
        vostok::sound::propagator_info *__last,
        bool (__cdecl *__comp)(const vostok::sound::propagator_info *, const vostok::sound::propagator_info *))
{
  if ( __last - __first <= 16 )
  {
    stlp_std::priv::__insertion_sort<vostok::sound::propagator_info *,vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
      __first,
      __last,
      0,
      __comp);
  }
  else
  {
    stlp_std::priv::__insertion_sort<vostok::sound::propagator_info *,vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
      __first,
      __first + 16,
      0,
      __comp);
    stlp_std::priv::__unguarded_insertion_sort_aux<vostok::sound::propagator_info *,vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
      __first + 16,
      __last,
      0,
      __comp);
  }
}

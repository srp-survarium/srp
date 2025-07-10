void __cdecl stlp_std::priv::__unguarded_linear_insert<vostok::sound::propagator_info *,vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
        vostok::sound::propagator_info *__last,
        vostok::sound::propagator_info __val,
        bool (__cdecl *__comp)(const vostok::sound::propagator_info *, const vostok::sound::propagator_info *))
{
  vostok::sound::propagator_info *__next; // [esp+0h] [ebp-4h]

  for ( __next = __last - 1; __comp(&__val, __next); --__next )
  {
    *__last = *__next;
    __last = __next;
  }
  *__last = __val;
}

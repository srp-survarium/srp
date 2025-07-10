void __usercall stlp_std::priv::__introsort_loop<char const * *,char const *,int,vostok::render::shader_macros_dort_predicate>(
        vostok::render::shader_macros_dort_predicate a1@<dil>,
        const char **__first,
        const char **__last,
        const char **__formal,
        int __depth_limit,
        const char **__comp)
{
  const char **v6; // ebx
  const char **v7; // eax
  const char **v8; // esi

  v6 = __last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 64 )
  {
    while ( __depth_limit )
    {
      --__depth_limit;
      v7 = (const char **)stlp_std::priv::__median<char const *,vostok::render::shader_macros_dort_predicate>(
                            __first,
                            &__first[(v6 - __first) / 2],
                            v6 - 1,
                            (vostok::render::shader_macros_dort_predicate)__comp);
      v8 = stlp_std::priv::__unguarded_partition<char const * *,char const *,vostok::render::shader_macros_dort_predicate>(
             __first,
             v6,
             *v7,
             (vostok::render::shader_macros_dort_predicate)__comp);
      stlp_std::priv::__introsort_loop<char const * *,char const *,int,vostok::render::shader_macros_dort_predicate>(
        v8,
        v6,
        0,
        __depth_limit,
        (vostok::render::shader_macros_dort_predicate)__comp);
      v6 = v8;
      if ( (int)(((char *)v8 - (char *)__first) & 0xFFFFFFFC) <= 64 )
        return;
    }
    stlp_std::priv::__partial_sort<char const * *,char const *,vostok::render::shader_macros_dort_predicate>(
      __first,
      v6,
      v6,
      __comp,
      a1);
  }
}

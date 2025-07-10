void __usercall stlp_std::priv::__introsort_loop<char const * *,char const *,int,vostok::tips_sorting_predicate>(
        vostok::tips_sorting_predicate a1@<esi>,
        const char **__first,
        const char **__last,
        const char **__formal,
        int __depth_limit,
        vostok::tips_sorting_predicate __comp)
{
  const char **v6; // edi
  const char **v8; // eax
  const char **v9; // esi

  v6 = __last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 64 )
  {
    while ( __depth_limit )
    {
      --__depth_limit;
      v8 = (const char **)stlp_std::priv::__median<char const *,vostok::tips_sorting_predicate>(
                            __first,
                            &__first[(v6 - __first) / 2],
                            v6 - 1,
                            __comp);
      v9 = stlp_std::priv::__unguarded_partition<char const * *,char const *,vostok::tips_sorting_predicate>(
             __first,
             v6,
             *v8,
             __comp);
      stlp_std::priv::__introsort_loop<char const * *,char const *,int,vostok::tips_sorting_predicate>(
        v9,
        v6,
        0,
        __depth_limit,
        __comp);
      v6 = v9;
      if ( (int)(((char *)v9 - (char *)__first) & 0xFFFFFFFC) <= 64 )
        return;
    }
    stlp_std::priv::__partial_sort<char const * *,char const *,vostok::tips_sorting_predicate>(
      __first,
      v6,
      v6,
      (const char **)__comp.editor_str,
      a1);
  }
}

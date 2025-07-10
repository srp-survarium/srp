void __usercall stlp_std::priv::__final_insertion_sort<char const * *,vostok::tips_sorting_predicate>(
        const char **__first@<edi>,
        const char **__last,
        vostok::tips_sorting_predicate __comp)
{
  const char **j; // esi
  const char **k; // esi
  const char **i; // esi

  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) <= 64 )
  {
    if ( __first != __last )
    {
      for ( i = __first + 1; i != __last; ++i )
        stlp_std::priv::__linear_insert<char const * *,char const *,vostok::tips_sorting_predicate>(
          __first,
          i,
          *i,
          __comp);
    }
  }
  else
  {
    for ( j = __first + 1; j != __first + 16; ++j )
      stlp_std::priv::__linear_insert<char const * *,char const *,vostok::tips_sorting_predicate>(
        __first,
        j,
        *j,
        __comp);
    for ( k = __first + 16; k != __last; ++k )
      stlp_std::priv::__unguarded_linear_insert<char const * *,char const *,vostok::tips_sorting_predicate>(
        k,
        *k,
        __comp);
  }
}

void __fastcall stlp_std::__adjust_heap<vostok::resources::query_result * *,int,vostok::resources::query_result *,vostok::resources::sorting_predicate>(
        int __holeIndex,
        int __len,
        vostok::resources::query_result **__first,
        vostok::resources::query_result *__val,
        vostok::resources::sorting_predicate __comp)
{
  int v5; // eax
  bool v6; // zf
  int i; // edi

  v5 = 2 * __holeIndex + 2;
  v6 = v5 == __len;
  for ( i = __holeIndex; v5 < __len; v6 = v5 == __len )
  {
    if ( __first[v5]->m_quality_index >= __first[v5 - 1]->m_quality_index )
      --v5;
    __first[__holeIndex] = __first[v5];
    __holeIndex = v5;
    v5 = 2 * v5 + 2;
  }
  if ( v6 )
  {
    __first[__holeIndex] = __first[v5 - 1];
    __holeIndex = v5 - 1;
  }
  stlp_std::__push_heap<vostok::resources::query_result * *,int,vostok::resources::query_result *,vostok::resources::sorting_predicate>(
    __first,
    __holeIndex,
    i,
    __val,
    __comp);
}

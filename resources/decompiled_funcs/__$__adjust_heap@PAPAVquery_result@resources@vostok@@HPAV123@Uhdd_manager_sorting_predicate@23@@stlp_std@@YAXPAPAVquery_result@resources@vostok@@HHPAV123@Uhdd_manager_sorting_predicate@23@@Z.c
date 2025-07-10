void __usercall stlp_std::__adjust_heap<vostok::resources::query_result * *,int,vostok::resources::query_result *,vostok::resources::hdd_manager_sorting_predicate>(
        int __holeIndex@<eax>,
        vostok::resources::query_result **__first,
        int __len,
        vostok::resources::query_result *__val,
        vostok::resources::hdd_manager_sorting_predicate __comp)
{
  int v6; // edi
  int v7; // esi
  bool i; // zf
  vostok::resources::query_result *v10; // [esp+0h] [ebp-14h]

  v6 = __holeIndex;
  v7 = 2 * __holeIndex + 2;
  for ( i = v7 == __len; v7 < __len; i = v7 == __len )
  {
    if ( vostok::resources::hdd_manager_sorting_predicate::operator()(
           __first[v7],
           (vostok::resources::hdd_manager_sorting_predicate *)__first[v7 - 1],
           v10) )
    {
      --v7;
    }
    __first[v6] = __first[v7];
    v6 = v7;
    v7 = 2 * v7 + 2;
  }
  if ( i )
  {
    __first[v6] = __first[v7 - 1];
    v6 = v7 - 1;
  }
  stlp_std::__push_heap<vostok::resources::query_result * *,int,vostok::resources::query_result *,vostok::resources::hdd_manager_sorting_predicate>(
    __first,
    v6,
    __holeIndex,
    __val,
    __comp);
}

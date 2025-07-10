void __usercall stlp_std::__push_heap<vostok::resources::query_result * *,int,vostok::resources::query_result *,vostok::resources::hdd_manager_sorting_predicate>(
        int __holeIndex@<eax>,
        vostok::resources::query_result **__first,
        int __topIndex,
        vostok::resources::query_result *__val)
{
  int v4; // edi
  int v5; // esi
  bool v6; // cc
  vostok::resources::query_result *v7; // [esp+0h] [ebp-14h]

  v4 = __holeIndex;
  v5 = (__holeIndex - 1) / 2;
  if ( __holeIndex > __topIndex )
  {
    do
    {
      if ( !vostok::resources::hdd_manager_sorting_predicate::operator()(
              __first[v5],
              (vostok::resources::hdd_manager_sorting_predicate *)__val,
              v7) )
        break;
      __first[v4] = __first[v5];
      v4 = v5;
      v6 = v5 <= __topIndex;
      v5 = (v5 - 1) / 2;
    }
    while ( !v6 );
  }
  __first[v4] = __val;
}

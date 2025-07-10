void __usercall stlp_std::__make_heap<vostok::resources::query_result * *,vostok::resources::hdd_manager_sorting_predicate,vostok::resources::query_result *,int>(
        vostok::resources::query_result **__first@<edi>,
        vostok::resources::query_result **__last,
        vostok::resources::hdd_manager_sorting_predicate *a3)
{
  int v3; // ebx
  int v4; // esi
  vostok::resources::query_result *v5; // eax

  v3 = __last - __first;
  v4 = (v3 - 2) / 2;
  stlp_std::__adjust_heap<vostok::resources::query_result * *,int,vostok::resources::query_result *,vostok::resources::hdd_manager_sorting_predicate>(
    __first,
    v4,
    v3,
    __first[v4],
    *a3);
  while ( v4 )
  {
    v5 = __first[--v4];
    stlp_std::__adjust_heap<vostok::resources::query_result * *,int,vostok::resources::query_result *,vostok::resources::hdd_manager_sorting_predicate>(
      __first,
      v4,
      v3,
      v5,
      *a3);
  }
}

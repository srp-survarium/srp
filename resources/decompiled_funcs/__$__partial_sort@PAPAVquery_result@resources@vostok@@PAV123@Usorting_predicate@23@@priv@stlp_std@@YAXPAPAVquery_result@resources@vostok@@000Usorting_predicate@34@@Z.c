void __usercall stlp_std::priv::__partial_sort<vostok::resources::query_result * *,vostok::resources::query_result *,vostok::resources::sorting_predicate>(
        vostok::resources::query_result **__first@<ecx>,
        vostok::resources::query_result **__middle@<eax>,
        vostok::resources::query_result **__last,
        vostok::resources::query_result **__formal)
{
  int v6; // ebp
  vostok::resources::query_result **i; // ebx
  vostok::resources::query_result *v8; // eax

  v6 = __middle - __first;
  if ( v6 >= 2 )
    stlp_std::__make_heap<vostok::resources::query_result * *,vostok::resources::sorting_predicate,vostok::resources::query_result *,int>(
      __first,
      __middle);
  for ( i = __middle; i < __last; ++i )
  {
    v8 = *i;
    if ( (*i)->m_quality_index >= (*__first)->m_quality_index )
    {
      *i = *__first;
      stlp_std::__adjust_heap<vostok::resources::query_result * *,int,vostok::resources::query_result *,vostok::resources::sorting_predicate>(
        __first,
        0,
        v6,
        v8,
        (vostok::resources::sorting_predicate)__formal);
    }
  }
  stlp_std::sort_heap<vostok::resources::query_result * *,vostok::resources::sorting_predicate>(
    __first,
    __middle,
    (vostok::resources::sorting_predicate)__formal);
}

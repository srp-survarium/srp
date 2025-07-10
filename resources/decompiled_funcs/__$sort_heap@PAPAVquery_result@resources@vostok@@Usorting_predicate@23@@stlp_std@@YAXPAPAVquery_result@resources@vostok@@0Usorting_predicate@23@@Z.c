void __usercall stlp_std::sort_heap<vostok::resources::query_result * *,vostok::resources::sorting_predicate>(
        vostok::resources::query_result **__first@<esi>,
        vostok::resources::query_result **__last@<eax>,
        vostok::resources::sorting_predicate __comp)
{
  int v3; // eax
  vostok::resources::query_result *v4; // ecx
  int v5; // edi

  v3 = (char *)__last - (char *)__first;
  if ( (int)(v3 & 0xFFFFFFFC) > 4 )
  {
    do
    {
      v4 = *(vostok::resources::query_result **)((char *)__first + v3 - 4);
      *(vostok::resources::query_result **)((char *)__first + v3 - 4) = *__first;
      v5 = v3 - 4;
      stlp_std::__adjust_heap<vostok::resources::query_result * *,int,vostok::resources::query_result *,vostok::resources::sorting_predicate>(
        __first,
        0,
        (v3 - 4) >> 2,
        v4,
        __comp);
      v3 = v5;
    }
    while ( (int)(v5 & 0xFFFFFFFC) > 4 );
  }
}

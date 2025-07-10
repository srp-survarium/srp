void __usercall stlp_std::sort_heap<vostok::resources::resource_base * *,vostok::resources::sorting_predicate>(
        vostok::resources::resource_base **__first@<esi>,
        vostok::resources::resource_base **__last@<eax>,
        vostok::resources::sorting_predicate __comp)
{
  int v3; // eax
  vostok::resources::resource_base *v4; // ecx
  int v5; // edi

  v3 = (char *)__last - (char *)__first;
  if ( (int)(v3 & 0xFFFFFFFC) > 4 )
  {
    do
    {
      v4 = *(vostok::resources::resource_base **)((char *)__first + v3 - 4);
      v5 = v3 - 4;
      *(vostok::resources::resource_base **)((char *)__first + v3 - 4) = *__first;
      stlp_std::__adjust_heap<vostok::resources::resource_base * *,int,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
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

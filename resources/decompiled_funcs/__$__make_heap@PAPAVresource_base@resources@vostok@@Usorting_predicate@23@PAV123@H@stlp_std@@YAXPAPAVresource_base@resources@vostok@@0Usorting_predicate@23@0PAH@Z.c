void __usercall stlp_std::__make_heap<vostok::resources::resource_base * *,vostok::resources::sorting_predicate,vostok::resources::resource_base *,int>(
        vostok::resources::resource_base **__first@<edi>,
        vostok::resources::resource_base **__last,
        vostok::resources::sorting_predicate *a3)
{
  int v3; // ebx
  int v4; // esi
  vostok::resources::resource_base *v5; // eax

  v3 = __last - __first;
  v4 = (v3 - 2) / 2;
  stlp_std::__adjust_heap<vostok::resources::resource_base * *,int,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
    __first,
    v4,
    v3,
    __first[v4],
    *a3);
  while ( v4 )
  {
    v5 = __first[--v4];
    stlp_std::__adjust_heap<vostok::resources::resource_base * *,int,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
      __first,
      v4,
      v3,
      v5,
      *a3);
  }
}

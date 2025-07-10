void __cdecl stlp_std::__adjust_heap<vostok::render::render_surface_instance * *,int,vostok::render::render_surface_instance *,vostok::render::sort_by_vs_predicate>(
        vostok::render::render_surface_instance **__first,
        int __holeIndex,
        int __len,
        vostok::render::render_surface_instance *__val,
        vostok::render::sort_by_ps_predicate __comp)
{
  int v5; // ebx
  int v6; // esi
  bool i; // zf

  v5 = __holeIndex;
  v6 = 2 * __holeIndex + 2;
  for ( i = v6 == __len; v6 < __len; i = v6 == __len )
  {
    if ( vostok::render::sort_by_vs_predicate::operator()(&__comp, __first[v6], __first[v6 - 1]) )
      --v6;
    __first[v5] = __first[v6];
    v5 = v6;
    v6 = 2 * v6 + 2;
  }
  if ( i )
  {
    __first[v5] = __first[v6 - 1];
    v5 = v6 - 1;
  }
  stlp_std::__push_heap<vostok::render::render_surface_instance * *,int,vostok::render::render_surface_instance *,vostok::render::sort_by_vs_predicate>(
    __first,
    v5,
    __holeIndex,
    __val,
    __comp);
}

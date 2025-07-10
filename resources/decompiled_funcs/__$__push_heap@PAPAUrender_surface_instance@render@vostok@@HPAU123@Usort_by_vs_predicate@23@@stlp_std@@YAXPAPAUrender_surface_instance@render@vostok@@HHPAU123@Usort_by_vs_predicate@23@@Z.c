void __cdecl stlp_std::__push_heap<vostok::render::render_surface_instance * *,int,vostok::render::render_surface_instance *,vostok::render::sort_by_vs_predicate>(
        vostok::render::render_surface_instance **__first,
        int __holeIndex,
        int __topIndex,
        vostok::render::render_surface_instance *__val,
        vostok::render::sort_by_ps_predicate __comp)
{
  int v5; // ebx
  int v6; // esi
  bool v7; // cc

  v5 = __holeIndex;
  v6 = (__holeIndex - 1) / 2;
  if ( __holeIndex <= __topIndex )
  {
    __first[__holeIndex] = __val;
  }
  else
  {
    while ( vostok::render::sort_by_vs_predicate::operator()(&__comp, __first[v6], __val) )
    {
      __first[v5] = __first[v6];
      v5 = v6;
      v7 = v6 <= __topIndex;
      v6 = (v6 - 1) / 2;
      if ( v7 )
      {
        __first[v5] = __val;
        return;
      }
    }
    __first[v5] = __val;
  }
}

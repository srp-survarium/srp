void __usercall stlp_std::__make_heap<vostok::render::render_surface_instance * *,vostok::render::sort_by_vs_predicate,vostok::render::render_surface_instance *,int>(
        vostok::render::render_surface_instance **__first@<edi>,
        vostok::render::render_surface_instance **__last,
        vostok::render::sort_by_ps_predicate *a3)
{
  int v3; // ebp
  int v4; // esi
  vostok::render::render_surface_instance *v5; // edx

  v3 = __last - __first;
  v4 = (v3 - 2) / 2;
  stlp_std::__adjust_heap<vostok::render::render_surface_instance * *,int,vostok::render::render_surface_instance *,vostok::render::sort_by_vs_predicate>(
    __first,
    v4,
    v3,
    __first[v4],
    *a3);
  while ( v4 )
  {
    v5 = __first[--v4];
    stlp_std::__adjust_heap<vostok::render::render_surface_instance * *,int,vostok::render::render_surface_instance *,vostok::render::sort_by_vs_predicate>(
      __first,
      v4,
      v3,
      v5,
      *a3);
  }
}

void __usercall stlp_std::sort_heap<vostok::render::render_surface_instance * *,vostok::render::sort_by_distance_predicate>(
        vostok::render::render_surface_instance **__first@<esi>,
        vostok::render::render_surface_instance **__last@<eax>,
        vostok::render::sort_by_distance_predicate __comp)
{
  int v3; // eax
  vostok::render::render_surface_instance *v4; // ecx
  int v5; // edi

  v3 = (char *)__last - (char *)__first;
  if ( (int)(v3 & 0xFFFFFFFC) > 4 )
  {
    do
    {
      v4 = *(vostok::render::render_surface_instance **)((char *)__first + v3 - 4);
      *(vostok::render::render_surface_instance **)((char *)__first + v3 - 4) = *__first;
      v5 = v3 - 4;
      stlp_std::__adjust_heap<vostok::render::render_surface_instance * *,int,vostok::render::render_surface_instance *,vostok::render::sort_by_distance_predicate>(
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

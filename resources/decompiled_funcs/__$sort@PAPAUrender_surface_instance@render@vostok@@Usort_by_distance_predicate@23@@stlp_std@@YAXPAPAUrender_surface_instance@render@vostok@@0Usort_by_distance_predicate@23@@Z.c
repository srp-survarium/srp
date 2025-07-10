void __usercall stlp_std::sort<vostok::render::render_surface_instance * *,vostok::render::sort_by_distance_predicate>(
        vostok::render::render_surface_instance **__first@<edi>,
        vostok::render::render_surface_instance **__last@<esi>,
        vostok::render::sort_by_distance_predicate __comp)
{
  int v3; // eax
  int i; // ecx

  if ( __first != __last )
  {
    v3 = __last - __first;
    for ( i = 0; v3 != 1; ++i )
      v3 >>= 1;
    stlp_std::priv::__introsort_loop<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance *,int,vostok::render::sort_by_distance_predicate>(
      __first,
      __last,
      0,
      2 * i,
      __comp);
    stlp_std::priv::__final_insertion_sort<vostok::render::render_surface_instance * *,vostok::render::sort_by_distance_predicate>(
      __first,
      __last,
      __comp);
  }
}

void __usercall stlp_std::sort<vostok::render::render_surface_instance * *,vostok::render::sort_by_vs_predicate>(
        vostok::render::render_surface_instance **__first@<esi>,
        vostok::render::render_surface_instance **__last@<eax>,
        vostok::render::sort_by_ps_predicate __comp)
{
  int v4; // eax
  int i; // ecx

  if ( __first != __last )
  {
    v4 = __last - __first;
    for ( i = 0; v4 != 1; ++i )
      v4 >>= 1;
    stlp_std::priv::__introsort_loop<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance *,int,vostok::render::sort_by_ps_predicate>(
      __first,
      __last,
      0,
      2 * i,
      __comp);
    stlp_std::priv::__final_insertion_sort<vostok::render::render_surface_instance * *,vostok::render::sort_by_ps_predicate>(
      __first,
      __last,
      __comp);
  }
}

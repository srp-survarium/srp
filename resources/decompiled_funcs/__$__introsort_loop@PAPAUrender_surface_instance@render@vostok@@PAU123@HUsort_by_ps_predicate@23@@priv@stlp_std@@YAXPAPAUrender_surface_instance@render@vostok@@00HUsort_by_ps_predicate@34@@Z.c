void __cdecl stlp_std::priv::__introsort_loop<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance *,int,vostok::render::sort_by_ps_predicate>(
        vostok::render::render_surface_instance **__first,
        vostok::render::render_surface_instance **__last,
        vostok::render::render_surface_instance **__formal,
        int __depth_limit,
        vostok::render::sort_by_ps_predicate __comp)
{
  vostok::render::render_surface_instance **v5; // edi
  vostok::render::render_surface_instance **v7; // eax
  vostok::render::render_surface_instance **v8; // esi
  vostok::render::sort_by_ps_predicate v9; // [esp-4h] [ebp-18h]

  v5 = __last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 64 )
  {
    while ( __depth_limit )
    {
      --__depth_limit;
      v7 = (vostok::render::render_surface_instance **)stlp_std::priv::__median<vostok::render::render_surface_instance *,vostok::render::sort_by_vs_predicate>(
                                                         __first,
                                                         &__first[(v5 - __first) / 2],
                                                         v5 - 1,
                                                         __comp);
      v8 = (vostok::render::render_surface_instance **)stlp_std::priv::__unguarded_partition<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance *,vostok::render::sort_by_vs_predicate>(
                                                         (const vostok::render::render_surface_instance **)__first,
                                                         v5,
                                                         *v7,
                                                         __comp);
      stlp_std::priv::__introsort_loop<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance *,int,vostok::render::sort_by_ps_predicate>(
        v8,
        v5,
        0,
        __depth_limit,
        __comp);
      v5 = v8;
      if ( (int)(((char *)v8 - (char *)__first) & 0xFFFFFFFC) <= 64 )
        return;
    }
    v9.m_stage_type = __comp.m_tech_index;
    stlp_std::priv::__partial_sort<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance *,vostok::render::sort_by_ps_predicate>(
      __first,
      v5,
      v5,
      (vostok::render::render_surface_instance **)__comp.m_stage_type,
      v9);
  }
}

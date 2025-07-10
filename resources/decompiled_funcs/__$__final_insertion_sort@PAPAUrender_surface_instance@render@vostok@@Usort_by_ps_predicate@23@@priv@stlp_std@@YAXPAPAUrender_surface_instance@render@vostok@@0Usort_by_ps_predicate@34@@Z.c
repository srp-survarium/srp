void __usercall stlp_std::priv::__final_insertion_sort<vostok::render::render_surface_instance * *,vostok::render::sort_by_ps_predicate>(
        vostok::render::render_surface_instance **__first@<eax>,
        vostok::render::render_surface_instance **__last@<edi>,
        vostok::render::sort_by_ps_predicate __comp)
{
  vostok::render::render_surface_instance **v3; // esi
  vostok::render::enum_render_stage_type m_stage_type; // ebx
  unsigned int i; // ebp
  vostok::render::sort_by_ps_predicate v6; // [esp+0h] [ebp-1Ch]
  vostok::render::sort_by_ps_predicate v7; // [esp+10h] [ebp-Ch] BYREF

  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) <= 64 )
  {
    v7 = __comp;
    if ( __first != __last )
      stlp_std::priv::__insertion_sort<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance *,vostok::render::sort_by_vs_predicate>(
        __first,
        __last,
        (vostok::render::render_surface_instance **)&v7,
        v6);
  }
  else
  {
    v3 = __first + 16;
    stlp_std::priv::__insertion_sort<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance *,vostok::render::sort_by_vs_predicate>(
      __first,
      __first + 16,
      (vostok::render::render_surface_instance **)&__comp,
      v6);
    m_stage_type = __comp.m_stage_type;
    for ( i = __comp.m_tech_index; v3 != __last; ++v3 )
      stlp_std::priv::__unguarded_linear_insert<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance *,vostok::render::sort_by_ps_predicate>(
        v3,
        *v3,
        (vostok::render::sort_by_ps_predicate)__PAIR64__(i, m_stage_type));
  }
}

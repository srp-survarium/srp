void __thiscall vostok::render::stage_view_mode::~stage_view_mode(
        vostok::render::stage_view_mode *this,
        vostok::render::stage_view_mode *thisa)
{
  vostok::render::res_effect *m_object; // eax
  vostok::render::res_effect *v3; // eax
  vostok::render::res_effect *v4; // eax
  vostok::resources::unmanaged_resource **p_m_object; // esi
  int i; // edi
  int v7; // eax
  vostok::render::res_effect *v8; // eax
  vostok::resources::unmanaged_resource **v9; // esi
  int j; // edi
  int v11; // eax
  vostok::resources::unmanaged_resource **v12; // esi
  int k; // edi
  int v14; // eax
  vostok::resources::unmanaged_resource **v15; // esi
  int m; // edi
  int v17; // eax
  vostok::resources::unmanaged_resource **v18; // esi
  int n; // edi
  int v20; // eax
  vostok::resources::unmanaged_resource **v21; // esi
  int ii; // edi
  int v23; // eax

  m_object = thisa->m_editor_show_overdraw_shader.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &thisa->m_editor_show_overdraw_shader.m_object->vostok::resources::unmanaged_intrusive_base,
      thisa->m_editor_show_overdraw_shader.m_object);
  v3 = thisa->m_editor_apply_wireframe_shader.m_object;
  if ( v3 && !_InterlockedExchangeAdd(&v3->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &thisa->m_editor_apply_wireframe_shader.m_object->vostok::resources::unmanaged_intrusive_base,
      thisa->m_editor_apply_wireframe_shader.m_object);
  v4 = thisa->m_editor_vertex_alpha_effect.m_object;
  p_m_object = &thisa->m_editor_vertex_alpha_effect.m_object;
  if ( v4 && !_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &(*p_m_object)->vostok::resources::unmanaged_intrusive_base,
      *p_m_object);
  for ( i = 14; i >= 0; --i )
  {
    v7 = (int)*--p_m_object;
    if ( v7 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v7 + 208), 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &(*p_m_object)->vostok::resources::unmanaged_intrusive_base,
        *p_m_object);
  }
  v8 = thisa->m_editor_show_geometry_effect.m_object;
  v9 = &thisa->m_editor_show_geometry_effect.m_object;
  if ( v8 && !_InterlockedExchangeAdd(&v8->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&(*v9)->vostok::resources::unmanaged_intrusive_base, *v9);
  for ( j = 14; j >= 0; --j )
  {
    v11 = (int)*--v9;
    if ( v11 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v11 + 208), 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&(*v9)->vostok::resources::unmanaged_intrusive_base, *v9);
  }
  v12 = &thisa->m_editor_geometry_complexity_effect[0].m_object;
  for ( k = 14; k >= 0; --k )
  {
    v14 = (int)*--v12;
    if ( v14 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v14 + 208), 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&(*v12)->vostok::resources::unmanaged_intrusive_base, *v12);
  }
  v15 = &thisa->m_editor_show_miplevel_effect[0].m_object;
  for ( m = 14; m >= 0; --m )
  {
    v17 = (int)*--v15;
    if ( v17 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v17 + 208), 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&(*v15)->vostok::resources::unmanaged_intrusive_base, *v15);
  }
  v18 = &thisa->m_editor_shader_complexity_effect[0].m_object;
  for ( n = 14; n >= 0; --n )
  {
    v20 = (int)*--v18;
    if ( v20 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v20 + 208), 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&(*v18)->vostok::resources::unmanaged_intrusive_base, *v18);
  }
  v21 = &thisa->m_editor_texture_density_effect[0].m_object;
  for ( ii = 14; ii >= 0; --ii )
  {
    v23 = (int)*--v21;
    if ( v23 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v23 + 208), 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&(*v21)->vostok::resources::unmanaged_intrusive_base, *v21);
  }
  thisa->__vftable = (vostok::render::stage_view_mode_vtbl *)&vostok::render::stage::`vftable';
}

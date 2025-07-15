void __thiscall vostok::render::grass_template::~grass_template(
        vostok::render::grass_template *this,
        vostok::render::grass_template *thisa)
{
  vostok::resources::unmanaged_resource **p_m_object; // edx
  vostok::render::grass_render_model *m_object; // ecx
  void **M_finish; // ebp
  char **i; // edi
  char *v6; // eax
  malloc_state *m_reconstruction_info_actuality_tick_high; // esi
  char *v8; // eax
  malloc_state *v9; // esi

  p_m_object = &thisa->m_render_model.m_object;
  m_object = vostok::render::g_allocator.m_object;
  M_finish = thisa->m_instances._M_impl._M_finish;
  for ( i = (char **)thisa->m_instances._M_impl._M_start; i != (char **)M_finish; ++i )
  {
    v6 = *i;
    if ( *i )
    {
      m_reconstruction_info_actuality_tick_high = (malloc_state *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
      BYTE2(m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v6);
      m_object = vostok::render::g_allocator.m_object;
      p_m_object = &thisa->m_render_model.m_object;
    }
  }
  v8 = (char *)p_m_object[2];
  if ( v8 )
  {
    v9 = (malloc_state *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
    BYTE2(m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v9, v8);
    p_m_object = &thisa->m_render_model.m_object;
  }
  if ( *p_m_object )
  {
    if ( !_InterlockedExchangeAdd(&(*p_m_object)->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &(*p_m_object)->vostok::resources::unmanaged_intrusive_base,
        *p_m_object);
  }
}

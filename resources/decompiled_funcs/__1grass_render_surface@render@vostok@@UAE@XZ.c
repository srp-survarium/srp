void __thiscall vostok::render::grass_render_surface::~grass_render_surface(vostok::render::grass_render_surface *this)
{
  char *m_vertices; // eax
  vostok::render::grass_render_model *m_object; // ecx
  malloc_state *m_reconstruction_info_actuality_tick_high; // esi
  unsigned __int16 *m_indices; // eax
  malloc_state *v6; // esi

  this->__vftable = (vostok::render::grass_render_surface_vtbl *)&stru_966A14.m_name.m_string.m_buffer[8];
  m_vertices = (char *)this->m_vertices;
  m_object = vostok::render::g_allocator.m_object;
  if ( m_vertices )
  {
    m_reconstruction_info_actuality_tick_high = (malloc_state *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, m_vertices);
    this->m_vertices = 0;
    m_object = vostok::render::g_allocator.m_object;
  }
  m_indices = this->m_indices;
  if ( m_indices )
  {
    v6 = (malloc_state *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
    BYTE2(m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v6, (char *)m_indices);
    this->m_indices = 0;
  }
  vostok::render::render_surface::~render_surface(this);
}

void __usercall vostok::render::game::renderer::~renderer(vostok::render::game::renderer *this@<ecx>, _DWORD *a2@<edi>)
{
  char *v2; // eax
  vostok::render::grass_render_model *m_object; // ecx
  malloc_state *m_reconstruction_info_actuality_tick_high; // esi
  char *v5; // eax
  malloc_state *v6; // esi
  char *v7; // eax
  malloc_state *v8; // esi

  v2 = (char *)a2[4];
  m_object = vostok::render::g_allocator.m_object;
  if ( v2 )
  {
    m_reconstruction_info_actuality_tick_high = (malloc_state *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v2);
    a2[4] = 0;
    m_object = vostok::render::g_allocator.m_object;
  }
  v5 = (char *)a2[3];
  if ( v5 )
  {
    v6 = (malloc_state *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
    BYTE2(m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v6, v5);
    a2[3] = 0;
    m_object = vostok::render::g_allocator.m_object;
  }
  v7 = (char *)a2[2];
  if ( v7 )
  {
    v8 = (malloc_state *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
    BYTE2(m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v8, v7);
    a2[2] = 0;
  }
}

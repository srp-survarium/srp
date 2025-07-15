void __thiscall vostok::render::texture_pool::~texture_pool(
        vostok::render::texture_pool *this,
        vostok::render::texture_pool *thisa)
{
  vostok::render::texture_pool *v2; // ecx
  vostok::render::texture_pool::slot *M_start; // eax
  unsigned int i; // ebp
  vostok::render::res_texture *texture; // esi
  vostok::render::grass_render_model *m_object; // edi
  char *v7; // ebx
  malloc_state *m_reconstruction_info_actuality_tick_high; // esi
  char *p_occupied; // eax
  malloc_state *v10; // esi

  v2 = thisa;
  M_start = thisa->m_textures._M_impl._M_start;
  for ( i = 0; i < v2->m_textures._M_impl._M_finish - v2->m_textures._M_impl._M_start; ++i )
  {
    texture = M_start[i].texture;
    m_object = vostok::render::g_allocator.m_object;
    if ( texture )
    {
      v7 = __RTCastToVoid((void **)&M_start[i].texture->__vftable);
      ((void (__thiscall *)(vostok::render::res_texture *, _DWORD))texture->~vostok::render::res_texture)(texture, 0);
      if ( v7 )
      {
        m_reconstruction_info_actuality_tick_high = (malloc_state *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
        BYTE2(m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v7);
      }
      v2 = thisa;
    }
    M_start = v2->m_textures._M_impl._M_start;
  }
  p_occupied = (char *)&v2->m_textures._M_impl._M_start->occupied;
  if ( v2->m_textures._M_impl._M_start )
  {
    v10 = (malloc_state *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v10, p_occupied);
  }
}

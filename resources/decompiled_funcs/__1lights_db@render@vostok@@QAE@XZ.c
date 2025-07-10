void __thiscall vostok::render::lights_db::~lights_db(
        vostok::render::lights_db *this,
        stlp_std::reverse_iterator<vostok::render::light_data *> *thisa)
{
  vostok::render::light **i; // esi
  vostok::render::light_data *current; // esi
  unsigned int m_reference_count; // edi
  _BYTE *v5; // ebx
  vostok::render::light_data *v6; // eax
  vostok::render::light_data *v7; // edi
  vostok::render::grass_render_model *m_object; // esi
  vostok::render::light_data *v9; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi

  for ( i = &thisa->current->light.m_object; i != (vostok::render::light **)thisa[1].current; i += 2 )
    vostok::render::light::remove_collision((vostok::render::light *)this, *i);
  current = thisa[4].current;
  if ( current )
  {
    m_reference_count = current[2].light.m_object->m_reference_count;
    v5 = __RTCastToVoid((void **)&thisa[4].current->light.m_object);
    ((void (__thiscall *)(vostok::render::light_data *, _DWORD))LODWORD(current->light.m_object->m_plane_spot_xform.i.x))(
      current,
      0);
    (*(void (__thiscall **)(unsigned int, _BYTE *))(*(_DWORD *)m_reference_count + 24))(m_reference_count, v5);
  }
  v6 = thisa[3].current;
  if ( v6 )
  {
    if ( !--v6->light.m_object )
    {
      v7 = thisa[3].current;
      m_object = vostok::render::g_allocator.m_object;
      if ( v7 )
      {
        vostok::render::light::~light((vostok::render::light *)this, (int)v7);
        BYTE2(m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free((void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick), v7);
      }
    }
  }
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::render::light_data *>,vostok::render::light_data>(
    thisa[1],
    (stlp_std::reverse_iterator<vostok::render::light_data *>)thisa->current);
  v9 = thisa->current;
  if ( thisa->current )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v9);
  }
}

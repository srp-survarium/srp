void __thiscall vostok::render::user_mesh_cook::destroy_resource(
        vostok::render::user_mesh_cook *this,
        vostok::resources::unmanaged_resource *resource)
{
  vostok::render::grass_render_model *m_object; // ebp
  void **m_target_quality_level; // esi
  _BYTE *v4; // ebx
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::grass_render_model *v6; // ebp
  _BYTE *v7; // esi
  void *v8; // eax
  void *v9; // esi

  m_object = vostok::render::g_allocator.m_object;
  m_target_quality_level = (void **)resource[1].m_target_quality_level;
  if ( m_target_quality_level )
  {
    v4 = __RTCastToVoid(m_target_quality_level);
    (*(void (__thiscall **)(void **, _DWORD))*m_target_quality_level)(m_target_quality_level, 0);
    if ( v4 )
    {
      m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
      BYTE2(m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v4);
    }
  }
  v6 = vostok::render::g_allocator.m_object;
  v7 = __RTCastToVoid((void **)&resource->__vftable);
  ((void (__thiscall *)(vostok::resources::unmanaged_resource *, _DWORD))resource->~vostok::resources::resource_base)(
    resource,
    0);
  if ( v7 )
  {
    v8 = v7;
    v9 = (void *)HIDWORD(v6->m_reconstruction_info_actuality_tick);
    BYTE2(v6->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v9, v8);
  }
}

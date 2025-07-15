void __usercall vostok::render::stage_visibility::~stage_visibility(
        vostok::render::stage_visibility *this@<ecx>,
        _DWORD *a2@<edi>)
{
  void *m_reconstruction_info_actuality_tick_high; // esi
  void *v3; // eax
  void *v4; // esi
  void *v5; // eax
  vostok::render::hw_hiz_occlusion_manager *v6; // ecx
  void *v7; // esi
  vostok::render::grass_render_model *m_object; // ebp
  void *v9; // eax
  void *v10; // esi

  *a2 = &vostok::render::stage_visibility::`vftable';
  m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
  v3 = (void *)(a2[6] - 8);
  BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
  vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v3);
  v4 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
  v5 = (void *)(a2[7] - 8);
  BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
  vostok_mspace_free(v4, v5);
  v7 = (void *)a2[5];
  m_object = vostok::render::g_allocator.m_object;
  if ( v7 )
  {
    vostok::render::hw_hiz_occlusion_manager::~hw_hiz_occlusion_manager(v6);
    v9 = v7;
    v10 = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
    BYTE2(m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v10, v9);
    a2[5] = 0;
  }
  *a2 = &vostok::render::stage::`vftable';
}

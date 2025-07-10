void __usercall vostok::render::cloud_simulation::~cloud_simulation(
        vostok::render::cloud_simulation *this@<ecx>,
        int a2@<edi>)
{
  void *m_reconstruction_info_actuality_tick_high; // esi
  void *v3; // eax
  void *v4; // esi
  void *v5; // eax

  m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
  v3 = (void *)(*(_DWORD *)(a2 + 80) - 8);
  BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
  vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v3);
  v4 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
  v5 = (void *)(*(_DWORD *)(a2 + 84) - 8);
  BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
  vostok_mspace_free(v4, v5);
}

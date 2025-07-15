void __usercall vostok::render::environment_temp::~environment_temp(
        vostok::render::environment_temp *this@<ecx>,
        _DWORD *a2@<eax>)
{
  void *m_reconstruction_info_actuality_tick_high; // esi
  void *v3; // eax

  m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
  v3 = (void *)(*a2 - 8);
  BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
  vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v3);
}

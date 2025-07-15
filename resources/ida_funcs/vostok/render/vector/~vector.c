void __usercall vostok::render::vector<vostok::render::render_surface_instance *>::~vector<vostok::render::render_surface_instance *>(
        vostok::render::vector<vostok::render::render_surface_instance *> *this@<ecx>,
        void **a2@<eax>)
{
  void *v2; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi

  v2 = *a2;
  if ( v2 )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v2);
  }
}

void __thiscall vostok::render::shader_binary_source_cook::deallocate_resource(
        vostok::render::shader_binary_source_cook *this,
        void *buffer)
{
  void *m_reconstruction_info_actuality_tick_high; // esi

  if ( buffer )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, buffer);
  }
}

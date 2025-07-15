void __thiscall vostok::render::speed_tree_allocator::Free(vostok::render::speed_tree_allocator *this, void *block)
{
  void *m_reconstruction_info_actuality_tick_high; // esi

  if ( block )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, block);
  }
}

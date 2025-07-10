void __thiscall vostok::render::effect_constant_storage::clear(
        vostok::render::effect_constant_storage *this,
        vostok::render::effect_constant_storage *thisa)
{
  vostok::render::fixed_constants_data_buffer *m_constant_buffer; // edi
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::fixed_constants_data_buffer *v4; // eax

  m_constant_buffer = thisa->m_constant_buffer;
  while ( m_constant_buffer )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    v4 = m_constant_buffer;
    m_constant_buffer = m_constant_buffer->next;
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v4);
  }
  thisa->m_constant_buffer = 0;
}

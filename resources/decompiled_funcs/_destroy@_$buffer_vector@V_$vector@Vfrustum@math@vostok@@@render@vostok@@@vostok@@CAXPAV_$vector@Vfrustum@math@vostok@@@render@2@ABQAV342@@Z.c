void __usercall vostok::buffer_vector<vostok::render::vector<vostok::math::frustum>>::destroy(
        vostok::render::vector<vostok::math::frustum> *begin@<eax>,
        vostok::render::vector<vostok::math::frustum> **end)
{
  vostok::render::vector<vostok::math::frustum> *i; // edi
  vostok::math::frustum *M_start; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi

  for ( i = begin; i != *end; ++i )
  {
    M_start = i->_M_impl._M_start;
    if ( i->_M_impl._M_start )
    {
      m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, M_start);
    }
  }
}

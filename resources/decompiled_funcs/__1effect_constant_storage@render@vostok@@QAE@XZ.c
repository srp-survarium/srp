void __usercall vostok::render::effect_constant_storage::~effect_constant_storage(
        vostok::render::effect_constant_storage *this@<ecx>,
        vostok::render::effect_constant_storage *a2@<eax>)
{
  vostok::render::data_indexer *M_start; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi

  vostok::render::effect_constant_storage::clear(this, a2);
  M_start = a2->m_indexers._M_impl._M_start;
  if ( a2->m_indexers._M_impl._M_start )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, M_start);
  }
  vostok::quasi_singleton<vostok::render::effect_constant_storage>::pinst = 0;
}

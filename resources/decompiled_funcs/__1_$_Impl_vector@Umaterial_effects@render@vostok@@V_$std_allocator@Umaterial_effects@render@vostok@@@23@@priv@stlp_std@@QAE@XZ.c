void __thiscall stlp_std::priv::_Impl_vector<vostok::render::material_effects,vostok::render::std_allocator<vostok::render::material_effects>>::~_Impl_vector<vostok::render::material_effects,vostok::render::std_allocator<vostok::render::material_effects>>(
        stlp_std::priv::_Impl_vector<vostok::render::material_effects,vostok::render::std_allocator<vostok::render::material_effects> > *this,
        stlp_std::priv::_Impl_vector<vostok::render::material_effects,vostok::render::std_allocator<vostok::render::material_effects> > *thisa)
{
  vostok::render::material_effects *M_finish; // eax
  vostok::render::material_effects *M_start; // edi
  vostok::render::material_effects *v4; // esi
  vostok::render::material_effects *v5; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi

  M_finish = thisa->_M_finish;
  M_start = thisa->_M_start;
  if ( M_finish != thisa->_M_start )
  {
    do
    {
      v4 = M_finish - 1;
      vostok::render::material_effects::~material_effects((vostok::render::material_effects *)this, (int)&M_finish[-1]);
      M_finish = v4;
    }
    while ( v4 != M_start );
  }
  v5 = thisa->_M_start;
  if ( thisa->_M_start )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v5);
  }
}

void __userpurge stlp_std::priv::_Impl_vector<vostok::math::frustum,vostok::render::std_allocator<vostok::math::frustum>>::_M_insert_overflow(
        vostok::math::frustum *__pos@<eax>,
        stlp_std::priv::_Impl_vector<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters>,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> > > *a2@<ecx>,
        stlp_std::priv::_Impl_vector<vostok::math::frustum,vostok::render::std_allocator<vostok::math::frustum> > *this,
        const vostok::math::frustum *__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned __int8 *v9; // ebp
  unsigned int v10; // esi
  int v11; // eax
  vostok::math::frustum *v12; // eax
  vostok::math::frustum *v13; // edi
  vostok::math::frustum *M_start; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  stlp_std::priv::_STLP_alloc_proxy<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *,stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters>,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> > > *v16; // [esp+0h] [ebp-10h]
  unsigned int thisa; // [esp+14h] [ebp+4h]

  thisa = (unsigned int)stlp_std::priv::_Impl_vector<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters>,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters>>>::_M_compute_next_size(
                          a2,
                          this);
  v9 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<vostok::math::frustum *,vostok::math::frustum,vostok::render::std_allocator<vostok::math::frustum>>::allocate(
                            thisa,
                            v16);
  v10 = (char *)__pos - (char *)this->_M_start;
  if ( v10 )
  {
    memmove(v9, (unsigned __int8 *)this->_M_start, v10);
    v12 = (vostok::math::frustum *)(v10 + v11);
  }
  else
  {
    v12 = (vostok::math::frustum *)v9;
  }
  qmemcpy(v12, __x, sizeof(vostok::math::frustum));
  v13 = v12 + 1;
  M_start = this->_M_start;
  if ( this->_M_start )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, M_start);
  }
  this->_M_finish = v13;
  this->_M_start = (vostok::math::frustum *)v9;
  this->_M_end_of_storage._M_data = (vostok::math::frustum *)&v9[120 * thisa];
}

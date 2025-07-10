void __userpurge stlp_std::priv::_Impl_vector<vostok::render::lpv_vertex,vostok::render::std_allocator<vostok::render::lpv_vertex>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<vostok::render::trample_desc,vostok::render::std_allocator<vostok::render::trample_desc> > *this@<edi>,
        const vostok::render::trample_desc *__x@<eax>,
        stlp_std::priv::_Impl_vector<vostok::render::trample_desc,vostok::render::std_allocator<vostok::render::trample_desc> > *a3@<ecx>,
        vostok::render::trample_desc *__pos,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned __int8 *v9; // ebp
  unsigned int v10; // ebx
  int v11; // eax
  unsigned __int8 *v12; // eax
  vostok::render::trample_desc *v13; // ebx
  vostok::render::trample_desc *M_start; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  unsigned int v16; // [esp+0h] [ebp-Ch]
  stlp_std::priv::_STLP_alloc_proxy<vostok::render::trample_desc *,vostok::render::trample_desc,vostok::render::std_allocator<vostok::render::trample_desc> > *v17; // [esp+0h] [ebp-Ch]
  unsigned int __posa; // [esp+10h] [ebp+4h]

  __posa = stlp_std::priv::_Impl_vector<vostok::render::shader_constant_binding,vostok::render::std_allocator<vostok::render::shader_constant_binding>>::_M_compute_next_size(
             a3,
             v16);
  v9 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<vostok::render::trample_desc *,vostok::render::trample_desc,vostok::render::std_allocator<vostok::render::trample_desc>>::allocate(
                            v17,
                            __posa);
  v10 = (char *)__pos - (char *)this->_M_start;
  if ( v10 )
  {
    memmove(v9, (unsigned __int8 *)this->_M_start, v10);
    v12 = (unsigned __int8 *)(v10 + v11);
  }
  else
  {
    v12 = v9;
  }
  *(_QWORD *)v12 = *(_QWORD *)&__x->position.x;
  *((_QWORD *)v12 + 1) = *(_QWORD *)&__x->position.elements[2];
  *((_DWORD *)v12 + 4) = LODWORD(__x->multiplier);
  v13 = (vostok::render::trample_desc *)(v12 + 20);
  M_start = this->_M_start;
  if ( this->_M_start )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, M_start);
  }
  this->_M_start = (vostok::render::trample_desc *)v9;
  this->_M_finish = v13;
  this->_M_end_of_storage._M_data = (vostok::render::trample_desc *)&v9[20 * __posa];
}

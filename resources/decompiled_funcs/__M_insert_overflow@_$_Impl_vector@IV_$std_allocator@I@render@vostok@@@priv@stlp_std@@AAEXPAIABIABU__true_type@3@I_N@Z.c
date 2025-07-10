void __userpurge stlp_std::priv::_Impl_vector<unsigned int,vostok::render::std_allocator<unsigned int>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<unsigned int,vostok::render::std_allocator<unsigned int> > *this@<edi>,
        char *__pos@<eax>,
        stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *a3@<ecx>,
        const unsigned int *__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned __int8 *v8; // ebx
  unsigned int v9; // esi
  int v10; // eax
  unsigned __int8 *v11; // eax
  unsigned int *v12; // ebp
  unsigned int *M_start; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  unsigned int v15; // [esp+0h] [ebp-10h]
  stlp_std::priv::_STLP_alloc_proxy<unsigned int *,unsigned int,vostok::render::std_allocator<unsigned int> > *v16; // [esp+0h] [ebp-10h]
  unsigned int size; // [esp+Ch] [ebp-4h]

  size = stlp_std::priv::_Impl_vector<enum survarium::game_action_id,survarium::std_allocator<enum survarium::game_action_id>>::_M_compute_next_size(
           a3,
           v15);
  v8 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>,vostok::render::std_allocator<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>>>::allocate(
                            size,
                            v16);
  v9 = __pos - (char *)this->_M_start;
  if ( v9 )
  {
    memmove(v8, (unsigned __int8 *)this->_M_start, v9);
    v11 = (unsigned __int8 *)(v9 + v10);
  }
  else
  {
    v11 = v8;
  }
  *(_DWORD *)v11 = *__x;
  v12 = (unsigned int *)(v11 + 4);
  M_start = this->_M_start;
  if ( this->_M_start )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, M_start);
  }
  this->_M_finish = v12;
  this->_M_start = (unsigned int *)v8;
  this->_M_end_of_storage._M_data = (unsigned int *)&v8[4 * size];
}

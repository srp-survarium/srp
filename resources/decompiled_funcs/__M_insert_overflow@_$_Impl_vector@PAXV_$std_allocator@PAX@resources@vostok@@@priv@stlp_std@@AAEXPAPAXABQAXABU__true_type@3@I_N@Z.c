void __userpurge stlp_std::priv::_Impl_vector<void *,vostok::resources::std_allocator<void *>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<void *,vostok::resources::std_allocator<void *> > *this@<edi>,
        void **__pos@<eax>,
        stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *a3@<ecx>,
        void **__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned int size; // ebp
  unsigned __int8 *v9; // ebx
  unsigned int v10; // esi
  int v11; // eax
  void **v12; // eax
  void **M_start; // eax
  unsigned int v14; // [esp+0h] [ebp-Ch]
  stlp_std::priv::_STLP_alloc_proxy<void * *,void *,vostok::resources::std_allocator<void *> > *v15; // [esp+0h] [ebp-Ch]
  void **__xa; // [esp+10h] [ebp+4h]

  size = stlp_std::priv::_Impl_vector<enum survarium::game_action_id,survarium::std_allocator<enum survarium::game_action_id>>::_M_compute_next_size(
           a3,
           v14);
  v9 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<void * *,void *,vostok::resources::std_allocator<void *>>::allocate(
                            v15,
                            size);
  v10 = (char *)__pos - (char *)this->_M_start;
  if ( v10 )
  {
    memmove(v9, (unsigned __int8 *)this->_M_start, v10);
    v12 = (void **)(v10 + v11);
  }
  else
  {
    v12 = (void **)v9;
  }
  *v12 = *__x;
  __xa = v12 + 1;
  M_start = this->_M_start;
  if ( this->_M_start )
  {
    vostok::memory::g_resources_helper_allocator.m_out_of_memory = 0;
    vostok_mspace_free(vostok::memory::g_resources_helper_allocator.m_arena, M_start);
  }
  this->_M_start = (void **)v9;
  this->_M_finish = __xa;
  this->_M_end_of_storage._M_data = (void **)&v9[4 * size];
}

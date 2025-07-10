void __userpurge stlp_std::priv::_Impl_vector<int,survarium::std_allocator<int>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<void const *,survarium::std_allocator<void const *> > *this@<edi>,
        const void **__pos@<eax>,
        stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *a3@<ecx>,
        const void **__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  unsigned int size; // ebp
  unsigned __int8 *v9; // ebx
  unsigned int v10; // esi
  int v11; // eax
  const void **v12; // eax
  const void **M_start; // eax
  void *v14; // esi
  unsigned int v15; // [esp+0h] [ebp-Ch]
  stlp_std::priv::_STLP_alloc_proxy<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *v16; // [esp+0h] [ebp-Ch]
  const void **__xa; // [esp+10h] [ebp+4h]

  size = stlp_std::priv::_Impl_vector<enum survarium::game_action_id,survarium::std_allocator<enum survarium::game_action_id>>::_M_compute_next_size(
           a3,
           v15);
  v9 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<enum survarium::game_action_id *,enum survarium::game_action_id,survarium::std_allocator<enum survarium::game_action_id>>::allocate(
                            v16,
                            size);
  v10 = (char *)__pos - (char *)this->_M_start;
  if ( v10 )
  {
    memmove(v9, (unsigned __int8 *)this->_M_start, v10);
    v12 = (const void **)(v10 + v11);
  }
  else
  {
    v12 = (const void **)v9;
  }
  *v12 = *__x;
  __xa = v12 + 1;
  M_start = this->_M_start;
  if ( this->_M_start )
  {
    v14 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v14, M_start);
  }
  this->_M_start = (const void **)v9;
  this->_M_finish = __xa;
  this->_M_end_of_storage._M_data = (const void **)&v9[4 * size];
}

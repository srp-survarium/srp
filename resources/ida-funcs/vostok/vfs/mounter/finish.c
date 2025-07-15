void __thiscall vostok::vfs::mounter::finish(
        vostok::vfs::mounter *this,
        vostok::vfs::mount_result *result,
        vostok::vfs::mounter *reused_from_history,
        char a4)
{
  vostok::vfs::mount_result *v4; // ebx
  vostok::vfs::base_node<1> *m_object; // eax
  vostok::vfs::vfs_mount *v6; // eax
  vostok::vfs::mount_result *v7; // eax
  vostok::vfs::vfs_mount *v8; // ecx
  vostok::vfs::result_enum v9; // ecx
  vostok::intrusive_double_linked_list<vostok::vfs::vfs_intrusive_mount_base,vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>,4,8,vostok::threading::simple_lock,vostok::size_policy,vostok::debug_policy> *v10; // ecx
  boost::function1<void,vostok::vfs::mount_result> *v11; // ecx
  vostok::vfs::vfs_mount *v12; // eax
  void (__thiscall *v13)(vostok::vfs::mounter *); // eax
  vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *v14; // ecx
  _DWORD *v15; // eax
  vostok::vfs::mount_result v16; // [esp-Ch] [ebp-20h] BYREF
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v17; // [esp-4h] [ebp-18h] BYREF
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v18; // [esp+10h] [ebp-4h] BYREF

  v4 = result;
  if ( LOBYTE(result[163].mount.m_object) )
  {
    vostok::vfs::unlock_branch((vostok::vfs::base_node<1> *)result[160].result, lock_type_write);
    this = (vostok::vfs::mounter *)v17.m_object;
  }
  if ( !a4 )
  {
    m_object = (vostok::vfs::base_node<1> *)v4[161].mount.m_object;
    if ( m_object )
    {
      this = reused_from_history;
      if ( (&reused_from_history->__vftable)[1] == (vostok::vfs::mounter_vtbl *)1 )
      {
        v6 = vostok::vfs::mount_of_node<1>(m_object);
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
          (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&result,
          v6);
        v7 = (vostok::vfs::mount_result *)v4[8].mount.m_object;
        if ( result != v7 )
        {
          v7[6].mount.m_object = (vostok::vfs::vfs_mount *)result;
          vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
            &v18,
            &v4[8].mount);
          v17.m_object = v8;
          vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
            &v17,
            &v18);
          v16.result = v9;
          vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
            (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&v16.result,
            0);
          vostok::intrusive_double_linked_list<vostok::vfs::vfs_intrusive_mount_base,vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>,4,8,vostok::threading::simple_lock,vostok::size_policy,vostok::debug_policy>::insert(
            v10,
            (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>)&result[3].result,
            (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>)v16.result,
            (bool *)v17.m_object);
          vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&v18);
        }
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&result);
      }
    }
  }
  if ( (v4[147].mount.m_object != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
  {
    v17.m_object = (vostok::vfs::vfs_mount *)this;
    v16.result = (vostok::vfs::result_enum)this;
    vostok::vfs::mount_result::mount_result(
      (vostok::vfs::mount_result *)&v16.result,
      (const vostok::vfs::mount_result *)reused_from_history);
    v16.mount.m_object = (vostok::vfs::vfs_mount *)&v4[147];
    boost::function1<void,vostok::vfs::mount_result>::operator()(
      v11,
      v16,
      (boost::function1<void,vostok::vfs::mount_result> *)v17.m_object);
  }
  if ( (v4[152].result != result_success || (v12 = v4[161].mount.m_object) == 0 || ((int)v12->parent & 1) == 0)
    && reused_from_history->__vftable
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    && !a4 )
  {
    v13 = reused_from_history->__vftable[13].~vostok::vfs::mounter;
    if ( v13 )
      v14 = (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)*((_DWORD *)v13 + 16);
    else
      v14 = 0;
    v15 = (int *)((char *)&dword_201C8 + v4[164].result);
    if ( (*v15 != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
      boost::function1<void,vostok::collision::object const &>::operator()(&v14->m_on_out_of_memory, v15, v14);
  }
}

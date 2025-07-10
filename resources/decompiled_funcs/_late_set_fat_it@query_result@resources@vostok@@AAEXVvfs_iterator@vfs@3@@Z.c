void __userpurge vostok::resources::query_result::late_set_fat_it(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>,
        vostok::vfs::vfs_iterator new_it)
{
  _QWORD *v4; // ebx
  vostok::vfs::base_node<1> *mount_root_user_data; // eax
  vostok::vfs::vfs_iterator *v6; // esi
  vostok::vfs::vfs_iterator *v7; // esi
  vostok::vfs::vfs_iterator *v8; // esi
  vostok::vfs::vfs_iterator *v9; // esi
  vostok::vfs::vfs_iterator *v10; // edi
  vostok::vfs::vfs_iterator v11; // [esp+8h] [ebp-10h] BYREF

  v4 = (_QWORD *)(a2 + 160);
  if ( !vostok::vfs::vfs_iterator::operator==((vostok::vfs::vfs_iterator *)(a2 + 160), &new_it) )
  {
    mount_root_user_data = vostok::mutable_buffer::size(&new_it);
    if ( mount_root_user_data )
      mount_root_user_data = (vostok::vfs::base_node<1> *)vostok::vfs::base_node<1>::get_mount_root_user_data(mount_root_user_data);
    vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
      (vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *)mount_root_user_data,
      (vostok::resources::unmanaged_resource **)(a2 + 604));
    *v4 = *(_QWORD *)&new_it.m_hashset;
    *(_QWORD *)(a2 + 168) = *(_QWORD *)&new_it.m_link_target;
    vostok::threading::interlocked_or((volatile int *)(a2 + 688), 0x10u);
    vostok::threading::interlocked_exchange_add(
      (int *)((char *)&dword_201B8 + (unsigned int)vostok::resources::g_resources_manager.m_variable),
      1u);
    v6 = *(vostok::vfs::vfs_iterator **)(a2 + 632);
    if ( v6 )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        vostok::vfs::vfs_iterator::vfs_iterator(&v11, &new_it);
        v7 = v6 + 10;
        if ( !vostok::vfs::vfs_iterator::operator==(&v11, v7) )
          *v7 = v11;
      }
    }
    v8 = *(vostok::vfs::vfs_iterator **)(a2 + 216);
    if ( v8 )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        vostok::vfs::vfs_iterator::vfs_iterator(&v11, &new_it);
        v9 = v8 + 10;
        if ( !vostok::vfs::vfs_iterator::operator==(&v11, v9) )
          *v9 = v11;
      }
    }
    v10 = *(vostok::vfs::vfs_iterator **)(a2 + 220);
    if ( v10 )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        vostok::vfs::vfs_iterator::vfs_iterator(&v11, &new_it);
        v10[10] = v11;
      }
    }
  }
}

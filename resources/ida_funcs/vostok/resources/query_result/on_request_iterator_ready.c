void __userpurge vostok::resources::query_result::on_request_iterator_ready(
        vostok::resources::query_result *this@<ecx>,
        int a2@<edi>,
        vostok::vfs::vfs_iterator *it,
        bool try_sync_way_only)
{
  vostok::vfs::base_node<1> *mount_root_user_data; // eax

  if ( (*(_DWORD *)(a2 + 688) & 0x100) == 0 )
  {
    *(vostok::vfs::vfs_association *)(a2 + 160) = this->vostok::vfs::vfs_association;
    *(_QWORD *)(a2 + 168) = *(_QWORD *)&this->vostok::resources::query_result_for_cook::vostok::resources::query_result_for_user::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::query_result_for_cook::vostok::resources::query_result_for_user::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
    mount_root_user_data = vostok::mutable_buffer::size((vostok::vfs::vfs_iterator *)this);
    if ( mount_root_user_data )
      mount_root_user_data = (vostok::vfs::base_node<1> *)vostok::vfs::base_node<1>::get_mount_root_user_data(mount_root_user_data);
    vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
      (vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *)mount_root_user_data,
      (vostok::resources::unmanaged_resource **)(a2 + 604));
    if ( *(_DWORD *)(a2 + 164) )
    {
      vostok::threading::interlocked_or((volatile int *)(a2 + 688), 0x10u);
      vostok::threading::interlocked_exchange_add(
        (int *)((char *)&dword_201B8 + (unsigned int)vostok::resources::g_resources_manager.m_variable),
        1u);
    }
    vostok::threading::interlocked_or((volatile int *)(a2 + 688), 0x100u);
  }
  if ( !(_BYTE)it )
    vostok::resources::resources_manager::continue_init_new_query(
      vostok::resources::g_resources_manager.m_variable,
      (vostok::resources::query_result *)a2);
}

void __thiscall vostok::resources::resources_manager::on_mounted(
        vostok::resources::resources_manager *this,
        vostok::vfs::base_node<1> *const node)
{
  char *v2; // eax
  _DWORD *v3; // eax
  vostok::resources::unmanaged_resource *v4; // ecx
  _DWORD *v5; // edi
  DWORD CurrentThreadId; // eax
  vostok::vfs::vfs_mount *v7; // eax
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v8; // ecx
  vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *v9; // ecx
  int v10; // eax
  vostok::resources::game_resources_manager *v11; // ecx

  v2 = type_info::raw_name(&vostok::resources::vfs_sub_fat_resource `RTTI Type Descriptor');
  v3 = vostok::memory::g_resources_helper_allocator.call_malloc(
         &vostok::memory::g_resources_helper_allocator,
         272,
         v2,
         "vostok::resources::resources_manager::on_mounted",
         ".\\resources_manager.cpp",
         392);
  v5 = v3;
  if ( v3 )
  {
    vostok::resources::unmanaged_resource::unmanaged_resource(v4, v3, fs_iterator_class);
    *v5 = &vostok::resources::vfs_sub_fat_resource::`vftable';
    v5[66] = 0;
    v5[67] = 0;
  }
  else
  {
    v5 = 0;
  }
  CurrentThreadId = GetCurrentThreadId();
  vostok::resources::unmanaged_resource::set_deleter_object(
    (vostok::resources::unmanaged_resource *)v5,
    &s_sub_fat_cook,
    CurrentThreadId);
  v7 = vostok::vfs::mount_of_node<1>(node);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator=(
    v8,
    v5 + 66,
    v7);
  v10 = *(_DWORD *)(v5[66] + 48);
  if ( v10 )
    vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
      v9,
      v5 + 67,
      *(vostok::resources::vfs_sub_fat_resource **)(v10 + 24));
  v5[23] = *(_DWORD *)(*(_DWORD *)(v5[66] + 52) + 88);
  v5[48] = 4;
  v5[22] = &vostok::resources::unmanaged_memory;
  vostok::vfs::base_node<1>::get_mount_root(
    (vostok::vfs::base_node<1> *)&vostok::resources::unmanaged_memory,
    (int)node)->mount.pointer->user_data = v5;
  if ( vostok::resources::g_game_resources_manager.m_initialized )
    vostok::resources::game_resources_manager::capture_resource(
      v11,
      vostok::resources::g_game_resources_manager.m_variable,
      (vostok::resources::resource_flags *)v5);
}

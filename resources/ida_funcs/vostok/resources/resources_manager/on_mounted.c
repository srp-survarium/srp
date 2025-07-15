void __userpurge vostok::resources::resources_manager::on_mounted(
        vostok::resources::resources_manager *this@<ecx>,
        double a2@<st0>,
        vostok::vfs::base_node<1> *const node)
{
  _DWORD *v3; // edi
  vostok::resources::cook_base *CurrentThreadId; // eax
  vostok::vfs::vfs_mount *v5; // eax
  vostok::vfs::vfs_mount *m_object; // eax
  int v7; // eax
  unsigned int mount_size; // eax
  vostok::vfs::vfs_mount *v9; // ecx
  unsigned int v10; // eax
  unsigned int v11; // [esp+0h] [ebp-18h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v12; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int v13; // [esp+14h] [ebp-4h]

  v3 = vostok::memory::g_resources_helper_allocator.call_malloc(&vostok::memory::g_resources_helper_allocator, 272);
  if ( v3 )
  {
    vostok::resources::unmanaged_resource::unmanaged_resource((vostok::resources::unmanaged_resource *)v3, 1u);
    *v3 = &stru_95BE78.m_string.m_buffer[120];
    v3[66] = 0;
    v3[67] = 0;
  }
  else
  {
    v3 = 0;
  }
  CurrentThreadId = (vostok::resources::cook_base *)GetCurrentThreadId();
  vostok::resources::unmanaged_resource::set_deleter_object(
    (vostok::resources::unmanaged_resource *)&s_sub_fat_cook,
    v3,
    CurrentThreadId,
    v11);
  v5 = vostok::vfs::mount_of_node<1>(node);
  v12.m_object = 0;
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::set(
    &v12,
    v5);
  m_object = v12.m_object;
  v12.m_object = (vostok::vfs::vfs_mount *)v3[66];
  v3[66] = m_object;
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&v12);
  v7 = *(_DWORD *)(v3[66] + 48);
  if ( v7 )
    vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
      *(vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> **)(v7 + 24),
      (vostok::resources::unmanaged_resource **)v3 + 67);
  mount_size = vostok::vfs::vfs_mount::get_mount_size((vostok::vfs::vfs_mount *)v3[66]);
  v9 = (vostok::vfs::vfs_mount *)v3[66];
  v13 = mount_size;
  vostok::vfs::vfs_mount::get_virtual_path(v9);
  v10 = v13;
  v3[48] = 4;
  v3[22] = &vostok::resources::unmanaged_memory;
  v3[23] = v10;
  vostok::vfs::base_node<1>::set_mount_root_user_data(node, v3);
  if ( vostok::resources::g_game_resources_manager.m_initialized )
    vostok::resources::game_resources_manager::capture_resource(
      (vostok::intrusive_double_linked_list<vostok::resources::resource_base,vostok::resources::resource_base *,156,152,vostok::threading::single_threading_policy,vostok::size_policy,vostok::debug_policy> *)v3,
      a2,
      vostok::resources::g_game_resources_manager.m_variable);
}

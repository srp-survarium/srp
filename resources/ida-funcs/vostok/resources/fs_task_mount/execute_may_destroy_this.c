void __thiscall vostok::resources::fs_task_mount::execute_may_destroy_this(vostok::resources::fs_task_mount *this)
{
  vostok::vfs::query_mount_arguments *v2; // ecx
  vostok::vfs::query_mount_arguments *v3; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::function<void __cdecl(void)> *v5; // ecx
  vostok::resources::fs_task *v6; // ecx
  char *v7; // eax
  void *v8; // eax
  vostok::resources::fs_task_unmount *v9; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v10; // ecx
  _BYTE v11[48]; // [esp-28h] [ebp-A08h] BYREF
  vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> v12; // [esp+14h] [ebp-9CCh] BYREF
  int v13; // [esp+18h] [ebp-9C8h]
  vostok::vfs::mount_result result; // [esp+1Ch] [ebp-9C4h] BYREF
  void (__thiscall *v15)(vostok::resources::resources_manager *, vostok::resources::allocate_functionality *); // [esp+24h] [ebp-9BCh]
  vostok::resources::resources_manager *v16; // [esp+28h] [ebp-9B8h]
  int v17; // [esp+2Ch] [ebp-9B4h]
  vostok::vfs::query_mount_arguments args; // [esp+30h] [ebp-9B0h] BYREF
  _BYTE v19[1104]; // [esp+508h] [ebp-4D8h] BYREF
  int v20[34]; // [esp+958h] [ebp-88h] BYREF

  vostok::vfs::query_mount_arguments::query_mount_arguments((vostok::vfs::query_mount_arguments *)this, (int)&args);
  if ( this->m_type == type_mount_physical )
  {
    *(_DWORD *)&v11[16] = 0;
    *(_DWORD *)&v11[12] = this->m_watcher_enabled;
    *(_DWORD *)&v11[8] = 1;
    v3 = vostok::vfs::query_mount_arguments::mount_physical_path(
           v2,
           (int)v19,
           (vostok::vfs::query_mount_arguments *)&vostok::memory::g_resources_unmanaged_allocator,
           &this->m_virtual_path.m_string,
           (const vostok::fs_new::virtual_path_string *)&this->m_physical_path,
           (vostok::fs_new::native_path_string *)this->m_descriptor.m_begin,
           s_resources_manager_buffer.m_hdd->m_queries.m_forward_queue.m_static_memory,
           0,
           (vostok::fs_new::synchronous_device_interface *)this->m_recursive,
           *(boost::function<void __cdecl(vostok::vfs::mount_result)> *)&v11[8]);
  }
  else
  {
    *(_DWORD *)&v11[16] = 0;
    v3 = vostok::vfs::query_mount_arguments::mount_archive(
           v2,
           (int)v19,
           (vostok::vfs::query_mount_arguments *)&vostok::memory::g_resources_unmanaged_allocator,
           &this->m_virtual_path.m_string,
           (const vostok::fs_new::virtual_path_string *)&this->m_archive_physical_path,
           this->m_fat_physical_path,
           (vostok::fs_new::native_path_string *)this->m_descriptor.m_begin,
           s_resources_manager_buffer.m_hdd->m_queries.m_forward_queue.m_static_memory,
           0,
           (vostok::fs_new::synchronous_device_interface *)1,
           *(boost::function<void __cdecl(vostok::vfs::mount_result)> *)&v11[16]);
  }
  vostok::vfs::query_mount_arguments::operator=(&args, v3);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v4, v20);
  v16 = &s_resources_manager_buffer;
  LOBYTE(v13) = 0;
  v17 = v13;
  v15 = vostok::resources::resources_manager::dispatch_callbacks;
  *(_DWORD *)&v11[4] = vostok::resources::resources_manager::dispatch_callbacks;
  *(_DWORD *)&v11[8] = &s_resources_manager_buffer;
  *(_DWORD *)v11 = &v11[16];
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    v5,
    *(boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::resources_manager,bool>,boost::_bi::list2<boost::_bi::value<vostok::resources::resources_manager *>,boost::_bi::value<bool> > > *)v11,
    v13);
  vostok::vfs::query_mount_and_wait(
    &result,
    &s_resources_manager_buffer.m_vfs,
    &args,
    *(boost::function<void __cdecl(void)> *)&v11[16]);
  if ( result.mount.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    *(_DWORD *)&v11[44] = v6;
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
      (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&v11[44],
      &result.mount);
    vostok::resources::get_sub_fat_resource(
      &v12,
      *(vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&v11[44]);
    v7 = type_info::raw_name(&vostok::resources::fs_task_unmount `RTTI Type Descriptor');
    v8 = vostok::memory::g_resources_helper_allocator.call_malloc(
           &vostok::memory::g_resources_helper_allocator,
           40,
           v7,
           "vostok::resources::fs_task_mount::execute_may_destroy_this",
           ".\\resources_fs_task_mount.cpp",
           99);
    if ( v8 )
      vostok::resources::fs_task_unmount::fs_task_unmount((vostok::resources::fs_task_unmount *)&v12, (int)v8, &v12);
    else
      v9 = 0;
    vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>::operator=(
      &this->m_mount_ptr,
      v9);
    vostok::intrusive_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v12);
  }
  vostok::resources::fs_task::on_task_ready_may_destroy_this(v6, (survarium::player_params_modifier *)this);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&result.mount);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v10,
    (int *)&args.callback);
}

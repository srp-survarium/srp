void __thiscall vostok::resources::resources_manager::do_mount_mounts_path(vostok::resources::resources_manager *this)
{
  vostok::vfs::query_mount_arguments *v1; // ecx
  boost::function<void __cdecl(void)> *v2; // ecx
  char *v3; // eax
  void *v4; // eax
  vostok::resources::fs_task_unmount *v5; // eax
  vostok::fs_new::path_string_impl *v6; // ecx
  vostok::fixed_string<260> *v7; // ecx
  vostok::vfs::query_mount_arguments *v8; // ecx
  boost::function<void __cdecl(void)> *v9; // ecx
  char *v10; // eax
  void *v11; // eax
  vostok::resources::fs_task_unmount *v12; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v13; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v14; // ecx
  _BYTE v15[48]; // [esp-30h] [ebp-C50h] BYREF
  vostok::vfs::query_mount_arguments args; // [esp+10h] [ebp-C10h] BYREF
  vostok::vfs::query_mount_arguments v17; // [esp+4E8h] [ebp-738h] BYREF
  vostok::fs_new::native_path_string v18; // [esp+9C0h] [ebp-260h] BYREF
  vostok::fixed_string<260> v19; // [esp+ADCh] [ebp-144h] BYREF
  char v20; // [esp+BECh] [ebp-34h]
  void (__thiscall *v21)(vostok::resources::resources_manager *, vostok::resources::allocate_functionality *); // [esp+BF0h] [ebp-30h]
  vostok::resources::resources_manager *v22; // [esp+BF4h] [ebp-2Ch]
  vostok::resources::vfs_sub_fat_resource *m_object; // [esp+BF8h] [ebp-28h]
  vostok::vfs::mount_result result; // [esp+BFCh] [ebp-24h] BYREF
  vostok::vfs::mount_result v25; // [esp+C04h] [ebp-1Ch] BYREF
  vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> v26; // [esp+C10h] [ebp-10h] BYREF
  void (__thiscall *v27)(vostok::resources::resources_manager *, vostok::resources::allocate_functionality *); // [esp+C14h] [ebp-Ch]
  vostok::resources::resources_manager *v28; // [esp+C18h] [ebp-8h]
  vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> v29; // [esp+C1Ch] [ebp-4h] BYREF

  vostok::fixed_string<260>::fixed_string<260>((vostok::fixed_string<260> *)this, &v19, "mounts.sources");
  *(_DWORD *)&v15[12] = 1;
  *(_DWORD *)&v15[8] = 1;
  v20 = 47;
  *(_DWORD *)&v15[16] = 0;
  vostok::vfs::query_mount_arguments::mount_physical_path(
    v1,
    (int)&args,
    (vostok::vfs::query_mount_arguments *)&vostok::memory::g_resources_unmanaged_allocator,
    &v19,
    (const vostok::fs_new::virtual_path_string *)&s_resources_manager_buffer.m_mounts_path,
    (vostok::fs_new::native_path_string *)"mounts.sources",
    s_resources_manager_buffer.m_hdd->m_queries.m_forward_queue.m_static_memory,
    0,
    0,
    *(boost::function<void __cdecl(vostok::vfs::mount_result)> *)&v15[8]);
  v28 = &s_resources_manager_buffer;
  LOBYTE(v26.m_object) = 0;
  v29.m_object = v26.m_object;
  v27 = vostok::resources::resources_manager::dispatch_callbacks;
  *(_DWORD *)&v15[4] = vostok::resources::resources_manager::dispatch_callbacks;
  *(_DWORD *)&v15[8] = &s_resources_manager_buffer;
  *(_DWORD *)v15 = &v15[16];
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    v2,
    *(boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::resources_manager,bool>,boost::_bi::list2<boost::_bi::value<vostok::resources::resources_manager *>,boost::_bi::value<bool> > > *)v15,
    (int)v26.m_object);
  vostok::vfs::query_mount_and_wait(
    &result,
    &s_resources_manager_buffer.m_vfs,
    &args,
    *(boost::function<void __cdecl(void)> *)&v15[16]);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&v15[44],
    &result.mount);
  vostok::resources::get_sub_fat_resource(
    &v26,
    *(vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&v15[44]);
  v3 = type_info::raw_name(&vostok::resources::fs_task_unmount `RTTI Type Descriptor');
  v4 = vostok::memory::g_resources_helper_allocator.call_malloc(
         &vostok::memory::g_resources_helper_allocator,
         40,
         v3,
         "vostok::resources::resources_manager::do_mount_mounts_path",
         ".\\resources_manager_helper.cpp",
         98);
  if ( v4 )
    vostok::resources::fs_task_unmount::fs_task_unmount((vostok::resources::fs_task_unmount *)&v26, (int)v4, &v26);
  else
    v5 = 0;
  vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>::operator=(
    &s_resources_manager_buffer.m_mounts_ptr,
    v5);
  vostok::fs_new::native_path_string::native_path_string(&v18);
  vostok::fs_new::path_string_impl::assignf_with_conversion(
    v6,
    &v18,
    (vostok::fs_new::path_string_impl *)"%s/platforms/%s",
    s_resources_manager_buffer.m_mounts_path.m_string.m_begin,
    "pc_dx11");
  vostok::fs_new::create_folder_r((char *)&v18, &s_resources_manager_buffer.m_sync_device, &v18, 1);
  vostok::fixed_string<260>::fixed_string<260>(v7, &v19, "mounts");
  *(_DWORD *)&v15[12] = 1;
  *(_DWORD *)&v15[8] = 1;
  v20 = 47;
  *(_DWORD *)&v15[16] = 0;
  vostok::vfs::query_mount_arguments::mount_physical_path(
    v8,
    (int)&v17,
    (vostok::vfs::query_mount_arguments *)&vostok::memory::g_resources_unmanaged_allocator,
    &v19,
    (const vostok::fs_new::virtual_path_string *)&v18,
    (vostok::fs_new::native_path_string *)"mounts",
    s_resources_manager_buffer.m_hdd->m_queries.m_forward_queue.m_static_memory,
    0,
    0,
    *(boost::function<void __cdecl(vostok::vfs::mount_result)> *)&v15[8]);
  v22 = &s_resources_manager_buffer;
  LOBYTE(v29.m_object) = 0;
  m_object = v29.m_object;
  v21 = vostok::resources::resources_manager::dispatch_callbacks;
  *(_DWORD *)&v15[4] = vostok::resources::resources_manager::dispatch_callbacks;
  *(_DWORD *)&v15[8] = &s_resources_manager_buffer;
  *(_DWORD *)v15 = &v15[16];
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    v9,
    *(boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::resources_manager,bool>,boost::_bi::list2<boost::_bi::value<vostok::resources::resources_manager *>,boost::_bi::value<bool> > > *)v15,
    (int)v29.m_object);
  vostok::vfs::query_mount_and_wait(
    &v25,
    &s_resources_manager_buffer.m_vfs,
    &v17,
    *(boost::function<void __cdecl(void)> *)&v15[16]);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&v15[44],
    &v25.mount);
  vostok::resources::get_sub_fat_resource(
    &v29,
    *(vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&v15[44]);
  v10 = type_info::raw_name(&vostok::resources::fs_task_unmount `RTTI Type Descriptor');
  v11 = vostok::memory::g_resources_helper_allocator.call_malloc(
          &vostok::memory::g_resources_helper_allocator,
          40,
          v10,
          "vostok::resources::resources_manager::do_mount_mounts_path",
          ".\\resources_manager_helper.cpp",
          124);
  if ( v11 )
    vostok::resources::fs_task_unmount::fs_task_unmount((vostok::resources::fs_task_unmount *)&v29, (int)v11, &v29);
  else
    v12 = 0;
  vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>::operator=(
    &s_resources_manager_buffer.m_mounts_converted_ptr,
    v12);
  vostok::intrusive_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v29);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&v25.mount);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v13,
    (int *)&v17.callback);
  vostok::intrusive_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v26);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&result.mount);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v14,
    (int *)&args.callback);
}

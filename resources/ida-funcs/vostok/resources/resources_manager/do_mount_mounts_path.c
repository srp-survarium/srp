void __thiscall vostok::resources::resources_manager::do_mount_mounts_path(
        vostok::resources::resources_manager *this,
        vostok::resources::resources_manager *thisa)
{
  char *m_buffer; // eax
  const char *v3; // ecx
  bool v4; // zf
  vostok::vfs::vfs_mount *m_object; // ecx
  vostok::resources::vfs_sub_fat_resource *user_data; // eax
  vostok::resources::fs_task_unmount *v7; // eax
  vostok::resources::fs_task_unmount *v8; // ecx
  vostok::resources::fs_task_unmount *v9; // eax
  const char *m_begin; // eax
  char *v11; // eax
  char *v12; // ecx
  vostok::vfs::vfs_mount *v13; // ecx
  vostok::resources::vfs_sub_fat_resource *v14; // eax
  vostok::resources::unmanaged_resource *v15; // edi
  vostok::resources::fs_task_unmount *v16; // eax
  vostok::resources::fs_task_unmount *v17; // ecx
  vostok::resources::fs_task_unmount *v18; // eax
  vostok::resources::vfs_sub_fat_resource *v19; // eax
  vostok::resources::unmanaged_intrusive_base *v20; // ecx
  _BYTE v21[44]; // [esp-2Ch] [ebp-C44h] BYREF
  vostok::resources::intrusive_fs_task_unmount_base *v22; // [esp+0h] [ebp-C18h]
  vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> sub_fat_resource; // [esp+14h] [ebp-C04h] BYREF
  vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> converted_sub_fat_resource; // [esp+18h] [ebp-C00h] BYREF
  int v25; // [esp+1Ch] [ebp-BFCh]
  void (__thiscall *v26)(vostok::resources::resources_manager *, BOOL); // [esp+20h] [ebp-BF8h]
  vostok::resources::resources_manager *m_variable; // [esp+24h] [ebp-BF4h]
  vostok::vfs::mount_result result; // [esp+2Ch] [ebp-BECh] BYREF
  vostok::vfs::mount_result result_converted; // [esp+34h] [ebp-BE4h] BYREF
  vostok::fs_new::virtual_path_string virtual_path; // [esp+3Ch] [ebp-BDCh] BYREF
  vostok::fs_new::native_path_string mounts_converted_path; // [esp+150h] [ebp-AC8h] BYREF
  vostok::vfs::query_mount_arguments mounts_converted_args; // [esp+268h] [ebp-9B0h] BYREF
  vostok::vfs::query_mount_arguments mounts_args; // [esp+740h] [ebp-4D8h] BYREF

  m_buffer = virtual_path.m_string.m_buffer;
  virtual_path.m_string.m_max_end = &virtual_path.m_separator;
  virtual_path.m_string.m_begin = virtual_path.m_string.m_buffer;
  virtual_path.m_string.m_end = virtual_path.m_string.m_buffer;
  virtual_path.m_string.m_buffer[0] = 0;
  v3 = "mounts.sources";
  do
  {
    if ( m_buffer >= virtual_path.m_string.m_max_end )
      break;
    *m_buffer = *v3;
    m_buffer = virtual_path.m_string.m_end + 1;
    v4 = *++v3 == 0;
    ++virtual_path.m_string.m_end;
  }
  while ( !v4 );
  *(_DWORD *)&v21[40] = 1;
  *(_DWORD *)&v21[36] = 1;
  *(_DWORD *)&v21[32] = 0;
  *m_buffer = 0;
  virtual_path.m_separator = 47;
  boost::function<void __cdecl (vostok::vfs::mount_result)>::function<void __cdecl (vostok::vfs::mount_result)>(
    (boost::function<void __cdecl(vostok::vfs::mount_result)> *)v21,
    0);
  vostok::vfs::query_mount_arguments::mount_physical_path(
    &mounts_args,
    &vostok::memory::g_resources_unmanaged_allocator,
    &virtual_path,
    &thisa->m_mounts_path,
    "mounts.sources",
    *(vostok::fs_new::asynchronous_device_interface **)((char *)&loc_205F8 + (_DWORD)thisa),
    0,
    *(boost::function<void __cdecl(vostok::vfs::mount_result)> *)v21,
    *(vostok::vfs::recursive_bool *)&v21[32],
    *(vostok::vfs::lock_operation_enum *)&v21[36],
    *(vostok::fs_new::watcher_enabled_bool *)&v21[40]);
  m_variable = vostok::resources::g_resources_manager.m_variable;
  LOBYTE(v25) = 0;
  v26 = vostok::resources::resources_manager::dispatch_callbacks;
  *(_DWORD *)&v21[4] = vostok::resources::g_resources_manager.m_variable;
  *(_DWORD *)&v21[12] = 0;
  *(_DWORD *)&v21[8] = v25;
  if ( boost::detail::function::basic_vtable1<void,bool>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::resources::device_manager,vostok::resources::query_result *,bool>,boost::_bi::list3<boost::_bi::value<vostok::resources::device_manager *>,boost::_bi::value<vostok::resources::query_result *>,boost::arg<1>>>>(
         (boost::detail::function::function_buffer *)&v21[20],
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)vostok::resources::resources_manager::dispatch_callbacks,
         *(boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::animated_model_instance_cook,vostok::resources::queries_result &,survarium::animated_model_instance *>,boost::_bi::list3<boost::_bi::value<survarium::animated_model_instance_cook *>,boost::arg<1>,boost::_bi::value<survarium::animated_model_instance *> > > *)&v21[4]) )
  {
    *(_DWORD *)&v21[12] = &stru_95BE78.m_string.m_buffer[13];
  }
  else
  {
    *(_DWORD *)&v21[12] = 0;
  }
  vostok::vfs::query_mount_and_wait(
    &result,
    (vostok::vfs::virtual_file_system *)((char *)&loc_20600 + (_DWORD)thisa),
    &mounts_args,
    *(boost::function<void __cdecl(void)> *)&v21[12]);
  m_object = 0;
  if ( result.mount.m_object )
  {
    m_object = result.mount.m_object;
    _InterlockedExchangeAdd(&result.mount.m_object->m_reference_count, 1u);
  }
  user_data = (vostok::resources::vfs_sub_fat_resource *)m_object->user_data;
  sub_fat_resource.m_object = 0;
  if ( user_data )
  {
    sub_fat_resource.m_object = user_data;
    _InterlockedExchangeAdd(&user_data->m_reference_count, 1u);
  }
  if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::vfs::vfs_intrusive_mount_base::destroy(m_object, m_object);
  if ( vostok::memory::g_resources_helper_allocator.call_malloc(&vostok::memory::g_resources_helper_allocator, 40) )
    vostok::resources::fs_task_unmount::fs_task_unmount(
      (vostok::resources::fs_task_unmount *)&sub_fat_resource,
      &sub_fat_resource);
  else
    v7 = 0;
  v8 = 0;
  if ( v7 )
  {
    v8 = v7;
    _InterlockedExchangeAdd(&v7->m_reference_count, 1u);
  }
  v9 = thisa->m_mounts_ptr.m_object;
  thisa->m_mounts_ptr.m_object = v8;
  if ( v9 && !_InterlockedExchangeAdd(&v9->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::intrusive_fs_task_unmount_base::destroy(v22, v9);
  mounts_converted_path.m_string.m_begin = mounts_converted_path.m_string.m_buffer;
  m_begin = thisa->m_mounts_path.m_string.m_begin;
  mounts_converted_path.m_string.m_end = mounts_converted_path.m_string.m_buffer;
  mounts_converted_path.m_string.m_max_end = &mounts_converted_path.m_separator;
  mounts_converted_path.m_string.m_buffer[0] = 0;
  mounts_converted_path.m_separator = 92;
  vostok::fs_new::path_string_impl::assignf_with_conversion(
    &mounts_converted_path,
    (vostok::fs_new::path_string_impl *)&stru_95BE78,
    m_begin,
    &stru_95BE78.m_string.m_buffer[60]);
  vostok::fs_new::create_folder_r(
    (const vostok::fs_new::synchronous_device_interface *)((char *)thisa + (_DWORD)&loc_205EB + 1),
    &mounts_converted_path,
    1);
  v11 = virtual_path.m_string.m_buffer;
  virtual_path.m_string.m_max_end = &virtual_path.m_separator;
  virtual_path.m_string.m_begin = virtual_path.m_string.m_buffer;
  virtual_path.m_string.m_end = virtual_path.m_string.m_buffer;
  virtual_path.m_string.m_buffer[0] = 0;
  v12 = &stru_95BE78.m_string.m_buffer[4];
  do
  {
    if ( v11 >= virtual_path.m_string.m_max_end )
      break;
    *v11 = *v12;
    v11 = virtual_path.m_string.m_end + 1;
    v4 = *++v12 == 0;
    ++virtual_path.m_string.m_end;
  }
  while ( !v4 );
  *(_DWORD *)&v21[40] = 1;
  *(_DWORD *)&v21[36] = 1;
  *(_DWORD *)&v21[32] = 0;
  *v11 = 0;
  virtual_path.m_separator = 47;
  boost::function<void __cdecl (vostok::vfs::mount_result)>::function<void __cdecl (vostok::vfs::mount_result)>(
    (boost::function<void __cdecl(vostok::vfs::mount_result)> *)v21,
    0);
  vostok::vfs::query_mount_arguments::mount_physical_path(
    &mounts_converted_args,
    &vostok::memory::g_resources_unmanaged_allocator,
    &virtual_path,
    &mounts_converted_path,
    &stru_95BE78.m_string.m_buffer[4],
    *(vostok::fs_new::asynchronous_device_interface **)((char *)&loc_205F8 + (_DWORD)thisa),
    0,
    *(boost::function<void __cdecl(vostok::vfs::mount_result)> *)v21,
    *(vostok::vfs::recursive_bool *)&v21[32],
    *(vostok::vfs::lock_operation_enum *)&v21[36],
    *(vostok::fs_new::watcher_enabled_bool *)&v21[40]);
  m_variable = vostok::resources::g_resources_manager.m_variable;
  LOBYTE(v25) = 0;
  v26 = vostok::resources::resources_manager::dispatch_callbacks;
  *(_DWORD *)&v21[4] = vostok::resources::g_resources_manager.m_variable;
  *(_DWORD *)&v21[12] = 0;
  *(_DWORD *)&v21[8] = v25;
  if ( boost::detail::function::basic_vtable1<void,bool>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::resources::device_manager,vostok::resources::query_result *,bool>,boost::_bi::list3<boost::_bi::value<vostok::resources::device_manager *>,boost::_bi::value<vostok::resources::query_result *>,boost::arg<1>>>>(
         (boost::detail::function::function_buffer *)&v21[20],
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)vostok::resources::resources_manager::dispatch_callbacks,
         *(boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::animated_model_instance_cook,vostok::resources::queries_result &,survarium::animated_model_instance *>,boost::_bi::list3<boost::_bi::value<survarium::animated_model_instance_cook *>,boost::arg<1>,boost::_bi::value<survarium::animated_model_instance *> > > *)&v21[4]) )
  {
    *(_DWORD *)&v21[12] = &stru_95BE78.m_string.m_buffer[13];
  }
  else
  {
    *(_DWORD *)&v21[12] = 0;
  }
  vostok::vfs::query_mount_and_wait(
    &result_converted,
    (vostok::vfs::virtual_file_system *)((char *)&loc_20600 + (_DWORD)thisa),
    &mounts_converted_args,
    *(boost::function<void __cdecl(void)> *)&v21[12]);
  v13 = 0;
  if ( result_converted.mount.m_object )
  {
    v13 = result_converted.mount.m_object;
    _InterlockedExchangeAdd(&result_converted.mount.m_object->m_reference_count, 1u);
  }
  v14 = (vostok::resources::vfs_sub_fat_resource *)v13->user_data;
  v15 = 0;
  converted_sub_fat_resource.m_object = 0;
  if ( v14 )
  {
    v15 = v14;
    converted_sub_fat_resource.m_object = v14;
    _InterlockedExchangeAdd(&v14->m_reference_count, 1u);
  }
  if ( !_InterlockedExchangeAdd(&v13->m_reference_count, 0xFFFFFFFF) )
    vostok::vfs::vfs_intrusive_mount_base::destroy(v13, v13);
  if ( vostok::memory::g_resources_helper_allocator.call_malloc(&vostok::memory::g_resources_helper_allocator, 40) )
    vostok::resources::fs_task_unmount::fs_task_unmount(
      (vostok::resources::fs_task_unmount *)&converted_sub_fat_resource,
      &converted_sub_fat_resource);
  else
    v16 = 0;
  v17 = 0;
  if ( v16 )
  {
    v17 = v16;
    _InterlockedExchangeAdd(&v16->m_reference_count, 1u);
  }
  v18 = thisa->m_mounts_converted_ptr.m_object;
  thisa->m_mounts_converted_ptr.m_object = v17;
  if ( v18 && !_InterlockedExchangeAdd(&v18->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::intrusive_fs_task_unmount_base::destroy(v22, v18);
  if ( v15 && !_InterlockedExchangeAdd(&v15->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v15->vostok::resources::unmanaged_intrusive_base, v15);
  vostok::vfs::mount_result::~mount_result(&result_converted);
  vostok::vfs::query_mount_arguments::~query_mount_arguments(&mounts_converted_args);
  v19 = sub_fat_resource.m_object;
  if ( sub_fat_resource.m_object )
  {
    v20 = &sub_fat_resource.m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&sub_fat_resource.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v20, v19);
  }
  vostok::vfs::mount_result::~mount_result(&result);
  vostok::vfs::query_mount_arguments::~query_mount_arguments(&mounts_args);
}

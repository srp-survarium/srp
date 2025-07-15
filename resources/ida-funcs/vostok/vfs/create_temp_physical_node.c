vostok::vfs::base_node<1> *__usercall vostok::vfs::create_temp_physical_node@<eax>(
        const vostok::fs_new::native_path_string *physical_path@<eax>,
        vostok::fs_new::synchronous_device_interface *device,
        vostok::vfs::query_mount_arguments *allocator)
{
  vostok::vfs::base_node<1> *p_base; // ebx
  vostok::vfs::query_mount_arguments *v6; // ecx
  char *v7; // edi
  vostok::vfs::physical_file_mount_root_node<1> *v8; // eax
  boost::function<void __cdecl(vostok::vfs::mount_result)> v9; // [esp-28h] [ebp-630h]
  vostok::fs_new::virtual_path_string *v10; // [esp-4h] [ebp-60Ch]
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v11; // [esp-4h] [ebp-60Ch]
  vostok::vfs::query_mount_arguments args; // [esp+10h] [ebp-5F8h] BYREF
  vostok::fixed_string<260> v13; // [esp+4ECh] [ebp-11Ch] BYREF
  unsigned __int64 out_file_size; // [esp+600h] [ebp-8h] BYREF

  if ( physical_path->m_string.m_begin == physical_path->m_string.m_end )
    return 0;
  p_base = 0;
  out_file_size = 0;
  if ( !vostok::fs_new::calculate_file_size(device, &out_file_size, physical_path, assert_on_fail_true) )
    return 0;
  vostok::fs_new::virtual_path_string::virtual_path_string(v10, (int)&v13);
  *(_QWORD *)&v9.vtable = 0x100000000LL;
  v9.functor.obj_ptr = 0;
  vostok::vfs::query_mount_arguments::mount_physical_path(
    v6,
    (int)&args,
    allocator,
    &v13,
    (const vostok::fs_new::virtual_path_string *)physical_path,
    (vostok::fs_new::native_path_string *)uri,
    0,
    (vostok::fs_new::asynchronous_device_interface *)device,
    0,
    v9);
  v7 = vostok::fs_new::file_name_from_path<vostok::fs_new::native_path_string>(physical_path);
  v8 = vostok::vfs::mount_root_node_functions::create<vostok::vfs::physical_file_mount_root_node,1>(
         strlen(v7),
         &args,
         v7,
         0);
  if ( v8 )
    p_base = &v8->file.base;
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v11,
    (int *)&args.callback);
  return p_base;
}

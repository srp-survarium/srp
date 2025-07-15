char __thiscall vostok::vfs::archive_mounter::read_sub_fat(
        vostok::vfs::archive_mounter *this,
        vostok::fs_new::synchronous_device_interface *device)
{
  vostok::vfs::query_mount_arguments *v3; // ecx
  vostok::fixed_string<260> *v4; // ecx
  char v5; // bl
  vostok::fs_new::device_file_system_proxy_base *v6; // ecx
  unsigned int v8; // eax
  vostok::fs_new::device_file_system_proxy_base *v9; // ecx
  vostok::fs_new::synchronous_device_interface *v10; // [esp+10h] [ebp-240h] BYREF
  void **v11; // [esp+14h] [ebp-23Ch] BYREF
  unsigned __int64 file; // [esp+18h] [ebp-238h]
  vostok::fs_new::native_path_string v13; // [esp+24h] [ebp-22Ch] BYREF
  vostok::fs_new::native_path_string v14; // [esp+138h] [ebp-118h] BYREF

  file = vostok::vfs::get_file_offs<1>(this->m_args.submount_node);
  vostok::vfs::query_mount_arguments::get_physical_path(v3, (int)&this->m_args, &v14);
  vostok::fixed_string<260>::fixed_string<260>(v4, &v13.m_string, v14.m_string.m_begin);
  v5 = 0;
  v13.m_separator = 92;
  v10 = device;
  vostok::fs_new::open_cached_file(device, &v11, &v13, open_existing, read, assert_on_fail_false, notify_watcher_true);
  if ( v11 )
  {
    vostok::fs_new::device_file_system_proxy_base::seek(
      v6,
      &device->m_device.m_device_file_system,
      v11,
      file,
      seek_file_begin);
    v8 = vostok::vfs::get_file_size<1>(this->m_args.submount_node);
    vostok::fs_new::device_file_system_proxy_base::read(
      v9,
      &device->m_device.m_device_file_system,
      v11,
      this->m_nodes_buffer,
      v8);
    v5 = 1;
  }
  vostok::fs_new::file_type_pointer::close((vostok::fs_new::file_type_pointer *)v6, &v10);
  return v5;
}

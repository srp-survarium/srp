char __cdecl vostok::fs_new::calculate_file_size(
        const vostok::fs_new::synchronous_device_interface *device,
        unsigned __int64 *const out_file_size,
        vostok::fs_new::native_path_string *physical_path,
        assert_on_fail_bool assert_on_fail)
{
  int v5; // edx
  void **file; // [esp+0h] [ebp-4h] BYREF

  file = 0;
  if ( !vostok::fs_new::device_file_system_no_watcher_proxy::open(
          &device->m_device,
          &file,
          physical_path,
          open_existing,
          read,
          assert_on_fail,
          notify_watcher_true,
          use_buffering_true) )
    return 0;
  vostok::fs_new::device_file_system_proxy_base::seek(&device->m_device, file, 0, seek_file_end);
  *(_DWORD *)out_file_size = vostok::fs_new::device_file_system_proxy_base::tell(&device->m_device, file);
  *((_DWORD *)out_file_size + 1) = v5;
  vostok::fs_new::device_file_system_no_watcher_proxy::close(&device->m_device, file);
  return 1;
}

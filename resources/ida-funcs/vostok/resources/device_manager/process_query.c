char __thiscall vostok::resources::device_manager::process_query(
        vostok::resources::device_manager *this,
        vostok::resources::query_result *query,
        vostok::fs_new::synchronous_device_interface *device)
{
  char result; // al
  vostok::animation::mixing::animation_interval *v4; // eax
  vostok::fs_new::device_file_system_no_watcher_proxy *v5; // eax
  void **v6; // [esp-4h] [ebp-14h]
  const vostok::fs_new::synchronous_device_interface *v7; // [esp+0h] [ebp-10h]
  void **file; // [esp+Ch] [ebp-4h] BYREF

  file = 0;
  result = vostok::resources::device_manager::open_file(
             device,
             (vostok::resources::query_result *)this,
             this,
             &file,
             query);
  if ( result )
  {
    if ( (query->m_flags & 2) != 0 )
      vostok::resources::device_manager::process_read_query(
        (vostok::vfs::vfs_iterator *)query,
        (vostok::resources::device_manager *)file,
        device,
        v7);
    else
      vostok::resources::device_manager::process_write_query(
        (vostok::vfs::vfs_iterator *)query,
        (vostok::resources::device_manager *)file,
        device,
        v7);
    v6 = file;
    v4 = (vostok::animation::mixing::animation_interval *)vostok::fs_new::synchronous_device_interface::operator->(device);
    v5 = (vostok::fs_new::device_file_system_no_watcher_proxy *)vostok::animation::mixing::animation_interval::animation(v4);
    vostok::fs_new::device_file_system_no_watcher_proxy::close(v5, v6);
    return 1;
  }
  return result;
}

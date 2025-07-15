vostok::fs_new::physical_path_info *__usercall vostok::resources::get_physical_path_info@<eax>(
        const vostok::vfs::vfs_iterator *it@<eax>,
        vostok::fs_new::physical_path_info *a2@<ecx>)
{
  vostok::fs_new::device_file_system_proxy_base *v3; // ecx
  vostok::fs_new::native_path_string v5; // [esp+8h] [ebp-118h] BYREF

  if ( it->m_node )
  {
    vostok::vfs::vfs_iterator::get_physical_path((vostok::vfs::vfs_iterator *)&v5, (int)it, &v5);
    vostok::fs_new::device_file_system_proxy_base::get_physical_path_info(
      v3,
      &s_resources_manager_buffer.m_sync_device.m_device.m_device_file_system,
      a2,
      &v5);
  }
  else
  {
    vostok::fs_new::physical_path_info::physical_path_info(a2, a2);
  }
  return a2;
}

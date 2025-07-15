void __userpurge vostok::resources::resources_manager::push_to_device_manager(
        vostok::resources::query_result *query@<esi>,
        vostok::resources::resources_manager *this)
{
  vostok::fs_new::native_path_string *v2; // ecx
  vostok::fs_new::native_path_string *physical_path; // eax
  vostok::resources::device_manager *capable_device_manager; // eax
  vostok::resources::resources_manager *v5; // ecx
  vostok::fs_new::native_path_string v6; // [esp+0h] [ebp-22Ch] BYREF
  vostok::fs_new::native_path_string v7; // [esp+114h] [ebp-118h] BYREF

  vostok::fs_new::native_path_string::native_path_string(&v7);
  if ( query->m_fat_it.m_node )
  {
    physical_path = vostok::vfs::vfs_iterator::get_physical_path(
                      (vostok::vfs::vfs_iterator *)v2,
                      (int)&query->m_fat_it,
                      &v6);
    v2 = &v7;
    if ( &v7 != physical_path )
      vostok::buffer_string::operator=(&physical_path->m_string, &v7.m_string);
  }
  capable_device_manager = vostok::resources::resources_manager::find_capable_device_manager(
                             (vostok::resources::resources_manager *)v2,
                             (const char *)&s_resources_manager_buffer,
                             (int)v7.m_string.m_begin);
  capable_device_manager->push_query_impl(capable_device_manager, query);
  vostok::resources::resources_manager::wakeup_resources_thread(v5, (int)this);
}

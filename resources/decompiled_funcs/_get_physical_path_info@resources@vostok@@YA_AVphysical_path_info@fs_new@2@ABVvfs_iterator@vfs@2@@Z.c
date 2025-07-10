vostok::fs_new::physical_path_info *__usercall vostok::resources::get_physical_path_info@<eax>(
        vostok::vfs::vfs_iterator *it@<ecx>,
        vostok::fs_new::physical_path_info *a2@<esi>)
{
  vostok::animation::mixing::animation_interval *v3; // eax
  vostok::fs_new::device_file_system_proxy_base *v4; // eax
  vostok::fs_new::native_path_string physical_path; // [esp+4h] [ebp-118h] BYREF

  if ( it->m_node )
  {
    vostok::vfs::vfs_iterator::get_physical_path(it, &physical_path);
    v3 = (vostok::animation::mixing::animation_interval *)vostok::fs_new::synchronous_device_interface::operator->((vostok::fs_new::synchronous_device_interface *)((char *)&loc_205EB + (unsigned int)vostok::resources::g_resources_manager.m_variable + 1));
    v4 = (vostok::fs_new::device_file_system_proxy_base *)vostok::animation::mixing::animation_interval::animation(v3);
    vostok::fs_new::device_file_system_proxy_base::get_physical_path_info(v4, a2, &physical_path);
  }
  else
  {
    vostok::fs_new::physical_path_info::physical_path_info(a2);
  }
  return a2;
}

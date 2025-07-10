vostok::resources::device_manager *__usercall vostok::resources::query_result::find_capable_device_manager@<eax>(
        vostok::resources::query_result *this@<ecx>,
        vostok::vfs::vfs_iterator *a2@<eax>)
{
  bool v2; // zf
  vostok::fs_new::virtual_path_string *physical_path; // eax
  vostok::fs_new::native_path_string file_path; // [esp+0h] [ebp-228h] BYREF
  vostok::fs_new::native_path_string result; // [esp+114h] [ebp-114h] BYREF

  v2 = a2[10].m_node == 0;
  file_path.m_string.m_begin = file_path.m_string.m_buffer;
  file_path.m_string.m_end = file_path.m_string.m_buffer;
  file_path.m_string.m_max_end = &file_path.m_separator;
  file_path.m_string.m_buffer[0] = 0;
  file_path.m_separator = 92;
  if ( !v2 )
  {
    physical_path = (vostok::fs_new::virtual_path_string *)vostok::vfs::vfs_iterator::get_physical_path(
                                                             a2 + 10,
                                                             &result);
    vostok::fs_new::virtual_path_string::operator=((vostok::fs_new::virtual_path_string *)&file_path, physical_path);
  }
  return vostok::resources::resources_manager::find_capable_device_manager(
           vostok::resources::g_resources_manager.m_variable,
           vostok::resources::g_resources_manager.m_variable,
           file_path.m_string.m_begin);
}

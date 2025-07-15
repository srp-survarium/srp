bool __thiscall vostok::vfs::query_notification_operation::mounts_filter(
        vostok::vfs::query_notification_operation *this,
        const char *descriptor,
        char *physical_path,
        char *virtual_path)
{
  bool result; // al

  result = vostok::fs_new::path_starts_with(this->m_physical_path->m_string.m_begin, physical_path);
  if ( result )
    return vostok::fs_new::path_starts_with(this->m_virtual_path->m_string.m_begin, virtual_path);
  return result;
}

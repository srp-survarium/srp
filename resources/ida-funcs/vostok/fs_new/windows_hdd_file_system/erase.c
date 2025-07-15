bool __thiscall vostok::fs_new::windows_hdd_file_system::erase(
        vostok::fs_new::windows_hdd_file_system *this,
        const vostok::fs_new::native_path_string *absolute_physical_path)
{
  return !_unlink(absolute_physical_path->m_string.m_begin) || !_rmdir(absolute_physical_path->m_string.m_begin);
}

bool __thiscall vostok::fs_new::windows_hdd_file_system::create_folder(
        vostok::fs_new::windows_hdd_file_system *this,
        const vostok::fs_new::native_path_string *absolute_physical_path)
{
  const vostok::fs_new::native_path_string *v2; // esi

  v2 = absolute_physical_path;
  _unlink(absolute_physical_path->m_string.m_begin);
  if ( _mkdir(v2->m_string.m_begin) != -1 )
    return 1;
  _get_errno((int *)&absolute_physical_path);
  return absolute_physical_path == (const vostok::fs_new::native_path_string *)17;
}

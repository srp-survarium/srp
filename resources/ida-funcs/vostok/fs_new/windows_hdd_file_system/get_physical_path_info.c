vostok::fs_new::physical_path_info *__thiscall vostok::fs_new::windows_hdd_file_system::get_physical_path_info(
        vostok::fs_new::windows_hdd_file_system *this,
        vostok::fs_new::physical_path_info *result,
        const vostok::fs_new::native_path_string *native_physical_path)
{
  vostok::fs_new::physical_path_info *v4; // ecx
  vostok::fs_new::physical_path_info *v6; // ecx
  char *m_begin; // edx
  _stat32i64 buf; // [esp+8h] [ebp-288h] BYREF
  vostok::fs_new::physical_path_initializer initializer; // [esp+38h] [ebp-258h] BYREF
  vostok::fs_new::native_path_string out_result; // [esp+178h] [ebp-118h] BYREF

  vostok::fs_new::native_path_string::native_path_string(&out_result);
  vostok::fs_new::convert_to_absolute_path<vostok::fs_new::native_path_string>(
    native_physical_path,
    &out_result,
    assert_on_fail_true);
  if ( _stat32i64(out_result.m_string.m_begin, &buf) == -1 )
  {
    vostok::fs_new::physical_path_info::physical_path_info(v4, result);
    return result;
  }
  else
  {
    vostok::fs_new::physical_path_initializer::physical_path_initializer(
      (vostok::fs_new::physical_path_initializer *)v4,
      &initializer);
    m_begin = out_result.m_string.m_begin;
    initializer.device = this;
    if ( initializer.data.path.m_string.m_begin != out_result.m_string.m_begin )
    {
      initializer.data.path.m_string.m_end = initializer.data.path.m_string.m_begin;
      *initializer.data.path.m_string.m_begin = 0;
      vostok::buffer_string::operator+=(&initializer.data.path.m_string, m_begin);
    }
    initializer.parent = 0;
    initializer.data.path_type = path_type_contains_full_path;
    initializer.data.type = ((buf.st_mode & 0x4000) != 0) + 1;
    initializer.data.file_size = buf.st_size;
    initializer.data.last_time_of_write = buf.st_mtime;
    vostok::fs_new::physical_path_info::physical_path_info(v6, &result->device, &initializer);
    return result;
  }
}

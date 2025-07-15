char *__thiscall vostok::engine::engine_world::get_user_data_directory(vostok::engine::engine_world *this)
{
  const vostok::fs_new::native_path_string *v1; // eax
  vostok::fs_new::native_path_string result; // [esp+8h] [ebp-218h] BYREF
  char pszPath[260]; // [esp+11Ch] [ebp-104h] BYREF

  if ( (_S5_7 & 1) == 0 )
  {
    _S5_7 |= 1u;
    vostok::fs_new::native_path_string::native_path_string(&s_user_data_directory);
  }
  if ( !BYTE5(vostok::testing::suite_base<vostok::engine_test_suite>::s_suite_creation_flag.m_mutex[0]) )
  {
    SHGetFolderPathA(0, 5, 0, 0, pszPath);
    _strlwr_s(pszPath, 0x104u);
    if ( s_user_data_directory.m_string.m_begin != pszPath )
    {
      s_user_data_directory.m_string.m_end = s_user_data_directory.m_string.m_begin;
      *s_user_data_directory.m_string.m_begin = 0;
      vostok::buffer_string::operator+=(&s_user_data_directory.m_string, pszPath);
    }
    v1 = vostok::fs_new::native_path_string::convert(&result, "survarium");
    vostok::fs_new::append_relative_path<vostok::fs_new::native_path_string,vostok::fs_new::native_path_string>(
      &s_user_data_directory,
      v1);
    BYTE5(vostok::testing::suite_base<vostok::engine_test_suite>::s_suite_creation_flag.m_mutex[0]) = 1;
  }
  return s_user_data_directory.m_string.m_begin;
}

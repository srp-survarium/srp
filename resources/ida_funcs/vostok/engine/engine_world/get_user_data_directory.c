char *__thiscall vostok::engine::engine_world::get_user_data_directory(vostok::engine::engine_world *this)
{
  char *m_end; // ecx
  char *v2; // eax
  bool v3; // zf
  vostok::fs_new::native_path_string *v4; // eax
  char path[260]; // [esp+0h] [ebp-218h] BYREF
  vostok::fs_new::path_string_impl v7; // [esp+104h] [ebp-114h] BYREF

  if ( (_S3_9 & 1) == 0 )
  {
    _S3_9 |= 1u;
    s_user_data_directory.m_string.m_begin = s_user_data_directory.m_string.m_buffer;
    s_user_data_directory.m_string.m_end = s_user_data_directory.m_string.m_buffer;
    s_user_data_directory.m_string.m_max_end = &s_user_data_directory.m_separator;
    s_user_data_directory.m_string.m_buffer[0] = 0;
    s_user_data_directory.m_separator = 92;
  }
  if ( !s_initialized_4 )
  {
    SHGetFolderPathA(0, 5, 0, 0, path);
    _strlwr_s(path, 0x104u);
    if ( s_user_data_directory.m_string.m_begin != path )
    {
      s_user_data_directory.m_string.m_end = s_user_data_directory.m_string.m_begin;
      *s_user_data_directory.m_string.m_begin = 0;
      m_end = s_user_data_directory.m_string.m_end;
      v2 = path;
      if ( path[0] )
      {
        do
        {
          if ( m_end >= s_user_data_directory.m_string.m_max_end )
            break;
          *m_end = *v2;
          m_end = s_user_data_directory.m_string.m_end + 1;
          v3 = *++v2 == 0;
          ++s_user_data_directory.m_string.m_end;
        }
        while ( !v3 );
      }
      *m_end = 0;
    }
    v4 = vostok::fs_new::native_path_string::convert("survarium", &v7);
    vostok::fs_new::append_relative_path<vostok::fs_new::native_path_string,vostok::fs_new::native_path_string>(
      &s_user_data_directory,
      v4);
    s_initialized_4 = 1;
  }
  return s_user_data_directory.m_string.m_begin;
}

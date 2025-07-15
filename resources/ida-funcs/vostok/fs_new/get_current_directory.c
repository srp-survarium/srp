const vostok::fs_new::native_path_string *__cdecl vostok::fs_new::get_current_directory()
{
  vostok::buffer_string *v1; // ecx
  char *m_end; // ecx
  char path[260]; // [esp+4h] [ebp-108h] BYREF

  if ( s_initialized_0 )
    return &s_current_directory;
  GetCurrentDirectoryA(0x104u, path);
  vostok::fs_new::path_string_impl::assign_with_conversion<char [260]>(
    &s_current_directory,
    (vostok::fixed_string<16> *)path);
  vostok::buffer_string::make_lowercase(v1, (int)&s_current_directory);
  while ( s_current_directory.m_string.m_end > s_current_directory.m_string.m_begin
       && *(s_current_directory.m_string.m_end - 1) == 92 )
    --s_current_directory.m_string.m_end;
  m_end = s_current_directory.m_string.m_end;
  *s_current_directory.m_string.m_end = 0;
  vostok::buffer_string::make_lowercase((vostok::buffer_string *)m_end, (int)&s_current_directory);
  s_initialized_0 = 1;
  return &s_current_directory;
}

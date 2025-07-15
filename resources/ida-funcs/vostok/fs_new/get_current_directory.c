const vostok::fs_new::native_path_string *__usercall vostok::fs_new::get_current_directory@<eax>(char *a1@<esi>)
{
  const vostok::fs_new::native_path_string *result; // eax
  char *m_begin; // ecx
  vostok::fs_new::path_string_impl *v3; // ecx
  vostok::fs_new::path_string_impl *v4; // [esp-8h] [ebp-10Ch]
  char Buffer[260]; // [esp+0h] [ebp-104h] BYREF

  if ( s_initialized )
    return &s_current_directory;
  GetCurrentDirectoryA(0x104u, Buffer);
  m_begin = s_current_directory.m_string.m_begin;
  if ( s_current_directory.m_string.m_begin != Buffer )
  {
    s_current_directory.m_string.m_end = s_current_directory.m_string.m_begin;
    *s_current_directory.m_string.m_begin = 0;
    vostok::buffer_string::operator+=(&s_current_directory.m_string, Buffer);
    m_begin = s_current_directory.m_string.m_begin;
  }
  vostok::fs_new::path_string_impl::convert(
    (vostok::fs_new::path_string_impl *)m_begin,
    (int)&s_current_directory,
    (vostok::fs_new::path_string_impl *)s_current_directory.m_string.m_end,
    a1);
  v3 = (vostok::fs_new::path_string_impl *)(s_current_directory.m_string.m_end - s_current_directory.m_string.m_begin);
  if ( s_current_directory.m_string.m_end != s_current_directory.m_string.m_begin )
  {
    _strlwr_s(s_current_directory.m_string.m_begin, (unsigned int)&v3->m_string.m_begin + 1);
    v3 = v4;
  }
  vostok::fs_new::path_string_impl::rtrim(v3, &s_current_directory, 92);
  if ( s_current_directory.m_string.m_end != s_current_directory.m_string.m_begin )
    _strlwr_s(
      s_current_directory.m_string.m_begin,
      s_current_directory.m_string.m_end - s_current_directory.m_string.m_begin + 1);
  result = &s_current_directory;
  s_initialized = 1;
  return result;
}

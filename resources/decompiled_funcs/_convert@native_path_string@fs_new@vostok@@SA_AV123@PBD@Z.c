vostok::fs_new::native_path_string *__usercall vostok::fs_new::native_path_string::convert@<eax>(
        const char *path@<ecx>,
        vostok::fs_new::path_string_impl *a2@<esi>)
{
  const char *m_begin; // eax

  a2->m_string.m_begin = a2->m_string.m_buffer;
  a2->m_string.m_end = a2->m_string.m_buffer;
  a2->m_string.m_max_end = &a2->m_separator;
  a2->m_string.m_buffer[0] = 0;
  a2->m_string.m_buffer[0] = 0;
  m_begin = a2->m_string.m_begin;
  a2->m_separator = 92;
  if ( m_begin != path )
  {
    a2->m_string.m_end = (char *)m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(&a2->m_string, path);
  }
  vostok::fs_new::path_string_impl::convert(a2, a2->m_string.m_begin, a2->m_string.m_end);
  return (vostok::fs_new::native_path_string *)a2;
}

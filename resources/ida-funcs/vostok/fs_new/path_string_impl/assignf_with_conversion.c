const vostok::fs_new::path_string_impl *__usercall vostok::fs_new::path_string_impl::assignf_with_conversion@<eax>(
        vostok::fs_new::path_string_impl *a1@<esi>,
        vostok::fs_new::path_string_impl *this,
        const char *const format,
        ...)
{
  char *m_begin; // eax

  m_begin = a1->m_string.m_begin;
  a1->m_string.m_end = a1->m_string.m_begin;
  *m_begin = 0;
  vostok::buffer_string::appendf_va_list(&a1->m_string, (const char *const)this, (char *)&format);
  vostok::fs_new::path_string_impl::convert(a1, a1->m_string.m_begin, a1->m_string.m_end);
  return a1;
}

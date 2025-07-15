const vostok::fs_new::path_string_impl *__usercall vostok::fs_new::path_string_impl::operator=<char const [1]>@<eax>(
        vostok::fs_new::path_string_impl *this@<ecx>,
        const vostok::fs_new::path_string_impl *result@<eax>)
{
  char *m_begin; // ecx

  m_begin = result->m_string.m_begin;
  if ( result->m_string.m_begin != uri )
  {
    result->m_string.m_end = m_begin;
    *m_begin = 0;
    return (const vostok::fs_new::path_string_impl *)vostok::buffer_string::operator+=(&result->m_string, (char *)uri);
  }
  return result;
}

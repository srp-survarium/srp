const vostok::fs_new::virtual_path_string *__usercall vostok::fs_new::virtual_path_string::operator=<char const *>@<eax>(
        vostok::fs_new::virtual_path_string *this@<ecx>,
        const vostok::fs_new::virtual_path_string *result@<eax>)
{
  char *m_begin; // edx
  char *v3; // ecx

  m_begin = this->m_string.m_begin;
  v3 = result->m_string.m_begin;
  if ( result->m_string.m_begin != m_begin )
  {
    result->m_string.m_end = v3;
    *v3 = 0;
    return (const vostok::fs_new::virtual_path_string *)vostok::buffer_string::operator+=(&result->m_string, m_begin);
  }
  return result;
}

const vostok::fs_new::virtual_path_string *__usercall vostok::fs_new::virtual_path_string::operator=<char const *>@<eax>(
        vostok::fs_new::virtual_path_string *this@<esi>,
        const char **s@<eax>)
{
  const char *v2; // ecx
  char *m_begin; // eax

  v2 = *s;
  m_begin = this->m_string.m_begin;
  if ( this->m_string.m_begin != v2 )
  {
    this->m_string.m_end = m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(&this->m_string, v2);
  }
  return this;
}

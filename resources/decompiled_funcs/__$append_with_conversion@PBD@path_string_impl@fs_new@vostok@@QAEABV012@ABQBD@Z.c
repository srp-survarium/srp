const vostok::fs_new::path_string_impl *__usercall vostok::fs_new::path_string_impl::append_with_conversion<char const *>@<eax>(
        vostok::fs_new::path_string_impl *this@<esi>,
        const char **s@<eax>)
{
  char *v2; // ecx
  unsigned __int8 *m_end; // ebx
  unsigned int v4; // edi

  v2 = (char *)*s;
  m_end = (unsigned __int8 *)this->m_string.m_end;
  v4 = strlen(*s);
  memcpy(m_end, (unsigned __int8 *)v2, v4);
  this->m_string.m_end += v4;
  *this->m_string.m_end = 0;
  vostok::fs_new::path_string_impl::convert(this, (char *)m_end, this->m_string.m_end);
  return this;
}

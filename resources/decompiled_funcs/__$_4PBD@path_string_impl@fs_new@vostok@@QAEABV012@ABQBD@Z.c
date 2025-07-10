const vostok::fs_new::path_string_impl *__thiscall vostok::fs_new::path_string_impl::operator=<char const *>(
        vostok::fs_new::path_string_impl *this,
        char **s)
{
  char *m_begin; // eax
  const char *v5; // [esp-4h] [ebp-8h]

  m_begin = this->m_string.m_begin;
  if ( this->m_string.m_begin != *s )
  {
    v5 = *s;
    this->m_string.m_end = m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(&this->m_string, v5);
  }
  return this;
}

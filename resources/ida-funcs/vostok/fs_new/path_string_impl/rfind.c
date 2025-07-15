unsigned int __fastcall vostok::fs_new::path_string_impl::rfind(vostok::fs_new::path_string_impl *this, const char c)
{
  char *m_end; // eax
  char *m_begin; // ecx
  char *v4; // eax

  m_end = this->m_string.m_end;
  m_begin = this->m_string.m_begin;
  v4 = m_end - 1;
  if ( v4 >= m_begin )
  {
    if ( *v4 == c )
      return v4 - m_begin;
    while ( v4 != m_begin )
    {
      if ( *--v4 == c )
        return v4 - m_begin;
    }
  }
  return -1;
}

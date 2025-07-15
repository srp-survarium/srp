const vostok::fs_new::path_string_impl *__usercall vostok::fs_new::path_string_impl::assign_with_conversion<char const *>@<eax>(
        vostok::fs_new::path_string_impl *this@<ecx>,
        char **s@<eax>)
{
  char *v2; // edx
  char *m_begin; // eax
  char *v6; // [esp+0h] [ebp-4h]

  v2 = *s;
  m_begin = this->m_string.m_begin;
  if ( this->m_string.m_begin != v2 )
  {
    this->m_string.m_end = m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(&this->m_string, v2);
  }
  vostok::fs_new::path_string_impl::convert(
    (vostok::fs_new::path_string_impl *)this->m_string.m_begin,
    (int)this,
    (vostok::fs_new::path_string_impl *)this->m_string.m_end,
    v6);
  return this;
}

vostok::fs_new::path_string_impl *__usercall vostok::fs_new::path_string_impl::assign_replace@<eax>(
        vostok::fs_new::path_string_impl *this@<eax>,
        char *source@<edx>)
{
  char *m_begin; // eax
  vostok::buffer_string *v4; // ecx

  m_begin = this->m_string.m_begin;
  this->m_string.m_end = m_begin;
  *m_begin = 0;
  vostok::buffer_string::operator+=(&this->m_string, source);
  vostok::buffer_string::replace(v4, &this->m_string, "resources/", "resources.sources/");
  return this;
}

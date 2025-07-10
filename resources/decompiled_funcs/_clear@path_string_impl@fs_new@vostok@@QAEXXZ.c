void __thiscall vostok::fs_new::path_string_impl::clear(vostok::buffer_string *this)
{
  char *m_begin; // eax

  m_begin = this->m_begin;
  this->m_end = this->m_begin;
  *m_begin = 0;
}

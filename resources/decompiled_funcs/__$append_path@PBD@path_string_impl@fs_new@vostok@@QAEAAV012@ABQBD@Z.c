vostok::fs_new::path_string_impl *__thiscall vostok::fs_new::path_string_impl::append_path<char const *>(
        vostok::fs_new::path_string_impl *this,
        char **s)
{
  char m_separator; // [esp+5h] [ebp-Bh]

  if ( vostok::fs_new::path_string_impl::length(this) )
    vostok::fs_new::path_string_impl::operator+=<char>((vostok::fs_new::native_path_string *)this, &this->m_separator);
  vostok::buffer_string::append(&this->m_string, *s);
  m_separator = this->m_separator;
  while ( this->m_string.m_end > this->m_string.m_begin && *(this->m_string.m_end - 1) == m_separator )
    --this->m_string.m_end;
  *this->m_string.m_end = 0;
  return this;
}

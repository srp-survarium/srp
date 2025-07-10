void __thiscall vostok::fs_new::path_string_impl::path_string_impl(
        vostok::fs_new::path_string_impl *this,
        char separator,
        const char **src)
{
  const char *v4; // [esp-4h] [ebp-8h]

  v4 = *src;
  this->m_string.m_begin = this->m_string.m_buffer;
  this->m_string.m_end = this->m_string.m_buffer;
  this->m_string.m_max_end = &this->m_separator;
  this->m_string.m_buffer[0] = 0;
  vostok::buffer_string::operator+=(&this->m_string, v4);
  this->m_separator = separator;
}

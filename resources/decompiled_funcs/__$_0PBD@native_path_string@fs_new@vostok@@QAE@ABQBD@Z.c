void __usercall vostok::fs_new::native_path_string::native_path_string(
        vostok::fs_new::native_path_string *this@<esi>,
        const char **other@<eax>)
{
  const char *v2; // [esp-4h] [ebp-4h]

  v2 = *other;
  this->m_string.m_begin = this->m_string.m_buffer;
  this->m_string.m_end = this->m_string.m_buffer;
  this->m_string.m_max_end = &this->m_separator;
  this->m_string.m_buffer[0] = 0;
  vostok::buffer_string::operator+=(&this->m_string, v2);
  this->m_separator = 92;
}

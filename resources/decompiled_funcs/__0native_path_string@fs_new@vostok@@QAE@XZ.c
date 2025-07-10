void __thiscall vostok::fs_new::native_path_string::native_path_string(vostok::fs_new::native_path_string *this)
{
  char *m_buffer; // ecx

  m_buffer = this->m_string.m_buffer;
  this->m_string.m_begin = m_buffer;
  this->m_string.m_end = m_buffer;
  this->m_string.m_max_end = m_buffer + 260;
  *m_buffer = 0;
  *m_buffer = 0;
  this->m_separator = 92;
}

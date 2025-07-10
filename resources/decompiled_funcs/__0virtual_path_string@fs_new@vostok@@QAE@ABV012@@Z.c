void __usercall vostok::fs_new::virtual_path_string::virtual_path_string(
        vostok::fs_new::virtual_path_string *this@<esi>,
        const vostok::fs_new::virtual_path_string *other@<eax>)
{
  unsigned __int8 *m_begin; // edx
  unsigned int v3; // ecx
  unsigned int v4; // edi

  m_begin = (unsigned __int8 *)other->m_string.m_begin;
  v3 = other->m_string.m_end - other->m_string.m_begin;
  this->m_string.m_max_end = &this->m_separator;
  v4 = v3;
  this->m_string.m_begin = this->m_string.m_buffer;
  this->m_string.m_end = this->m_string.m_buffer;
  memcpy((unsigned __int8 *)this->m_string.m_buffer, m_begin, v3);
  this->m_string.m_end += v4;
  *this->m_string.m_end = 0;
  this->m_separator = 47;
}

void __usercall vostok::fs_new::native_path_string::native_path_string(
        vostok::fs_new::native_path_string *this@<ecx>,
        int a2@<eax>)
{
  vostok::fixed_string<260>::fixed_string<260>(&this->m_string, (vostok::buffer_string *)a2, (char *)uri);
  *(_BYTE *)(a2 + 272) = 92;
}


void __usercall vostok::fs_new::native_path_string::native_path_string(
        vostok::fs_new::native_path_string *this@<ecx>,
        char **other@<eax>)
{
  vostok::fixed_string<260>::fixed_string<260>(&this->m_string, &this->m_string, *other);
  this->m_separator = 92;
}


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

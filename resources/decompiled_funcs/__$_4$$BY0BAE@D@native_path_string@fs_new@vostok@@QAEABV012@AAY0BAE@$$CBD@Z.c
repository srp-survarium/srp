const vostok::fs_new::native_path_string *__usercall vostok::fs_new::native_path_string::operator=<char [260]>@<eax>(
        vostok::fs_new::native_path_string *this@<ecx>,
        vostok::buffer_string *a2@<esi>)
{
  char *m_begin; // eax

  m_begin = a2->m_begin;
  if ( (vostok::fs_new::native_path_string *)a2->m_begin != this )
  {
    a2->m_end = m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(a2, (const char *)this);
  }
  return (const vostok::fs_new::native_path_string *)a2;
}

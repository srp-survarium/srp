vostok::fs_new::virtual_path_string *__usercall vostok::render::get_fixed_request_path@<eax>(
        vostok::fs_new::virtual_path_string *a1@<ecx>,
        vostok::buffer_string *a2@<esi>,
        vostok::fs_new::virtual_path_string *result)
{
  char *m_begin; // eax

  vostok::fs_new::virtual_path_string::virtual_path_string(a1, (int)a2);
  m_begin = a2->m_begin;
  if ( (vostok::fs_new::virtual_path_string *)a2->m_begin != result )
  {
    a2->m_end = m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(a2, (char *)result);
  }
  return (vostok::fs_new::virtual_path_string *)a2;
}

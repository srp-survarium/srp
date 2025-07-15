void __usercall vostok::fs_new::path_part_iterator::assign_to_string<vostok::fs_new::virtual_path_string>(
        vostok::fs_new::path_part_iterator *this@<ecx>,
        vostok::fs_new::virtual_path_string *out_string@<eax>)
{
  char *m_begin; // eax
  const char *m_cur_end; // eax
  const char *m_cur_str; // edi

  m_begin = out_string->m_string.m_begin;
  out_string->m_string.m_end = m_begin;
  *m_begin = 0;
  m_cur_end = this->m_cur_end;
  m_cur_str = this->m_cur_str;
  if ( m_cur_str != m_cur_end )
    vostok::buffer_string::append(&out_string->m_string, m_cur_end, (char *)&m_cur_str[*m_cur_str == this->m_separator]);
}

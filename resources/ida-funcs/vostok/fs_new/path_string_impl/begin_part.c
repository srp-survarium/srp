vostok::fs_new::path_part_iterator *__usercall vostok::fs_new::path_string_impl::begin_part@<eax>(
        vostok::fs_new::path_string_impl *this@<ecx>,
        int a2@<esi>)
{
  char *m_begin; // eax
  char m_separator; // dl
  char *m_end; // ecx

  m_begin = this->m_string.m_begin;
  m_separator = this->m_separator;
  m_end = this->m_string.m_end;
  *(_DWORD *)(a2 + 4) = m_begin;
  *(_DWORD *)(a2 + 12) = m_begin;
  *(_DWORD *)(a2 + 16) = m_begin;
  *(_DWORD *)a2 = 1;
  *(_BYTE *)(a2 + 20) = m_separator;
  *(_DWORD *)(a2 + 8) = m_end;
  vostok::fs_new::path_part_iterator::operator++((vostok::fs_new::path_part_iterator *)m_end, a2);
  return (vostok::fs_new::path_part_iterator *)a2;
}

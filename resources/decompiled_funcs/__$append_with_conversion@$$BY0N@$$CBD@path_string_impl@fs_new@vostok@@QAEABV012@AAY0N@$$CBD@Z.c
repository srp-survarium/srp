const vostok::fs_new::path_string_impl *__usercall vostok::fs_new::path_string_impl::append_with_conversion<char const [13]>@<eax>(
        vostok::fs_new::path_string_impl *this@<ecx>,
        vostok::fs_new::path_string_impl *a2@<esi>)
{
  unsigned __int8 *m_end; // ebx
  unsigned int v3; // edi

  m_end = (unsigned __int8 *)a2->m_string.m_end;
  v3 = strlen("/replication");
  memcpy(m_end, "/replication", v3);
  a2->m_string.m_end += v3;
  *a2->m_string.m_end = 0;
  vostok::fs_new::path_string_impl::convert(a2, (char *)m_end, a2->m_string.m_end);
  return a2;
}

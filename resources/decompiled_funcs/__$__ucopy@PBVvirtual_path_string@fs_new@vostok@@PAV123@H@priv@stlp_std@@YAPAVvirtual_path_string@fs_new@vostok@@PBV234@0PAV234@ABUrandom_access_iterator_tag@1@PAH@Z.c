vostok::fs_new::virtual_path_string *__usercall stlp_std::priv::__ucopy<vostok::fs_new::virtual_path_string const *,vostok::fs_new::virtual_path_string *,int>@<eax>(
        vostok::fs_new::virtual_path_string *__last@<eax>,
        vostok::fs_new::virtual_path_string *__result@<ecx>,
        vostok::fs_new::virtual_path_string *__first)
{
  vostok::fs_new::virtual_path_string *v3; // ebp
  int v4; // eax
  vostok::fs_new::virtual_path_string *v5; // edi
  unsigned __int8 *m_buffer; // esi
  unsigned __int8 *m_begin; // ecx
  unsigned int v8; // ebx
  int __n; // [esp+Ch] [ebp-4h]
  vostok::fs_new::virtual_path_string *__cur; // [esp+14h] [ebp+4h]

  v3 = __first;
  v4 = __last - __first;
  v5 = __result;
  __cur = __result;
  __n = v4;
  if ( v4 > 0 )
  {
    m_buffer = (unsigned __int8 *)__result->m_string.m_buffer;
    do
    {
      if ( v5 )
      {
        m_begin = (unsigned __int8 *)v3->m_string.m_begin;
        v8 = v3->m_string.m_end - v3->m_string.m_begin;
        v5->m_string.m_begin = (char *)m_buffer;
        *((_DWORD *)m_buffer - 2) = m_buffer;
        *((_DWORD *)m_buffer - 1) = m_buffer + 260;
        memcpy(m_buffer, m_begin, v8);
        *((_DWORD *)m_buffer - 2) += v8;
        **((_BYTE **)m_buffer - 2) = 0;
        v4 = __n;
        m_buffer[260] = 47;
        v5 = __cur;
      }
      --v4;
      ++v5;
      ++v3;
      m_buffer += 276;
      __cur = v5;
      __n = v4;
    }
    while ( v4 > 0 );
  }
  return v5;
}

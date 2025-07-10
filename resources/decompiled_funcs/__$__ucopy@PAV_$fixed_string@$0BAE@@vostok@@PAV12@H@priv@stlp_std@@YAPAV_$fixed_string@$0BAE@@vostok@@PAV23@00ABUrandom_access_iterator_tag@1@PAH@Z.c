vostok::fixed_string<260> *__usercall stlp_std::priv::__ucopy<vostok::fixed_string<260> *,vostok::fixed_string<260> *,int>@<eax>(
        vostok::fixed_string<260> *__last@<eax>,
        vostok::fixed_string<260> *__result@<ecx>,
        vostok::fixed_string<260> *__first)
{
  vostok::fixed_string<260> *v3; // ebx
  int v4; // edi
  vostok::fixed_string<260> *v5; // ebp
  unsigned __int8 *m_buffer; // esi
  unsigned __int8 *m_begin; // ecx
  unsigned int v8; // eax
  unsigned int v9; // ebp
  vostok::fixed_string<260> *__cur; // [esp+14h] [ebp+4h]

  v3 = __first;
  v4 = __last - __first;
  v5 = __result;
  __cur = __result;
  if ( v4 > 0 )
  {
    m_buffer = (unsigned __int8 *)__result->m_buffer;
    do
    {
      if ( v5 )
      {
        m_begin = (unsigned __int8 *)v3->m_begin;
        v8 = v3->m_end - v3->m_begin;
        v5->m_begin = (char *)m_buffer;
        v9 = v8;
        *((_DWORD *)m_buffer - 2) = m_buffer;
        *((_DWORD *)m_buffer - 1) = m_buffer + 260;
        memcpy(m_buffer, m_begin, v8);
        *((_DWORD *)m_buffer - 2) += v9;
        v5 = __cur;
        **((_BYTE **)m_buffer - 2) = 0;
      }
      ++v5;
      --v4;
      ++v3;
      m_buffer += 272;
      __cur = v5;
    }
    while ( v4 > 0 );
  }
  return v5;
}

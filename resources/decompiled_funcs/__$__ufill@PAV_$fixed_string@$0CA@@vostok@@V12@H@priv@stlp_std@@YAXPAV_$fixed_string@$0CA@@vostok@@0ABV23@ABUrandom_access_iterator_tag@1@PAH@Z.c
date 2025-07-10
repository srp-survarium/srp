void __usercall stlp_std::priv::__ufill<vostok::fixed_string<32> *,vostok::fixed_string<32>,int>(
        vostok::fixed_string<32> *__first@<ecx>,
        vostok::fixed_string<32> *__last@<eax>,
        const vostok::fixed_string<32> *__x)
{
  int v3; // edi
  unsigned __int8 *m_buffer; // esi
  unsigned int v5; // ebx
  unsigned __int8 *m_begin; // [esp-Ch] [ebp-18h]

  v3 = __last - __first;
  if ( v3 > 0 )
  {
    m_buffer = (unsigned __int8 *)__first->m_buffer;
    do
    {
      if ( m_buffer != (unsigned __int8 *)12 )
      {
        v5 = __x->m_end - __x->m_begin;
        m_begin = (unsigned __int8 *)__x->m_begin;
        *((_DWORD *)m_buffer - 3) = m_buffer;
        *((_DWORD *)m_buffer - 2) = m_buffer;
        *((_DWORD *)m_buffer - 1) = m_buffer + 32;
        memcpy(m_buffer, m_begin, v5);
        *((_DWORD *)m_buffer - 2) += v5;
        **((_BYTE **)m_buffer - 2) = 0;
      }
      --v3;
      m_buffer += 44;
    }
    while ( v3 > 0 );
  }
}

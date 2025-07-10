void __usercall stlp_std::priv::__ufill<survarium::account_list_item *,survarium::account_list_item,int>(
        survarium::account_list_item *__first@<ecx>,
        survarium::account_list_item *__last@<eax>,
        const survarium::account_list_item *__x@<edi>)
{
  int v3; // eax
  unsigned __int8 *m_buffer; // esi
  unsigned int v5; // ebp
  unsigned __int8 *m_begin; // [esp-10h] [ebp-18h]
  int __n; // [esp+4h] [ebp-4h]

  v3 = __last - __first;
  __n = v3;
  if ( v3 > 0 )
  {
    m_buffer = (unsigned __int8 *)__first->account_name.m_buffer;
    do
    {
      if ( m_buffer != (unsigned __int8 *)16 )
      {
        *((_DWORD *)m_buffer - 4) = __x->account_id;
        v5 = __x->account_name.m_end - __x->account_name.m_begin;
        m_begin = (unsigned __int8 *)__x->account_name.m_begin;
        *((_DWORD *)m_buffer - 3) = m_buffer;
        *((_DWORD *)m_buffer - 2) = m_buffer;
        *((_DWORD *)m_buffer - 1) = m_buffer + 32;
        memcpy(m_buffer, m_begin, v5);
        *((_DWORD *)m_buffer - 2) += v5;
        **((_BYTE **)m_buffer - 2) = 0;
        m_buffer[32] = __x->online;
        v3 = __n;
      }
      --v3;
      m_buffer += 52;
      __n = v3;
    }
    while ( v3 > 0 );
  }
}

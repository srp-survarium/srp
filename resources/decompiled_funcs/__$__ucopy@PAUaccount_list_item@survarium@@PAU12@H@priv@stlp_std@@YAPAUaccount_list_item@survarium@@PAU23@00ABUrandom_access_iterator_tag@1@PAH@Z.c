survarium::account_list_item *__usercall stlp_std::priv::__ucopy<survarium::account_list_item *,survarium::account_list_item *,int>@<eax>(
        survarium::account_list_item *__last@<eax>,
        survarium::account_list_item *__result@<ecx>,
        survarium::account_list_item *__first)
{
  survarium::account_list_item *v3; // edi
  int v4; // ebx
  unsigned __int8 *m_buffer; // esi
  unsigned __int8 *m_begin; // [esp-Ch] [ebp-1Ch]
  unsigned int v8; // [esp-8h] [ebp-18h]
  unsigned int v9; // [esp+Ch] [ebp-4h]
  survarium::account_list_item *__cur; // [esp+14h] [ebp+4h]

  v3 = __first;
  v4 = __last - __first;
  __cur = __result;
  if ( v4 > 0 )
  {
    m_buffer = (unsigned __int8 *)__result->account_name.m_buffer;
    do
    {
      if ( __result )
      {
        __result->account_id = v3->account_id;
        v8 = v3->account_name.m_end - v3->account_name.m_begin;
        m_begin = (unsigned __int8 *)v3->account_name.m_begin;
        *((_DWORD *)m_buffer - 3) = m_buffer;
        *((_DWORD *)m_buffer - 2) = m_buffer;
        *((_DWORD *)m_buffer - 1) = m_buffer + 32;
        v9 = v8;
        memcpy(m_buffer, m_begin, v8);
        *((_DWORD *)m_buffer - 2) += v9;
        __result = __cur;
        **((_BYTE **)m_buffer - 2) = 0;
        m_buffer[32] = v3->online;
      }
      ++__result;
      --v4;
      ++v3;
      m_buffer += 52;
      __cur = __result;
    }
    while ( v4 > 0 );
  }
  return __result;
}

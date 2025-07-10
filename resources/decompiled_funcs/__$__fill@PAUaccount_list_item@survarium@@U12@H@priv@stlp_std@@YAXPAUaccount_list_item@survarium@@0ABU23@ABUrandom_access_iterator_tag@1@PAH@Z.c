void __usercall stlp_std::priv::__fill<survarium::account_list_item *,survarium::account_list_item,int>(
        survarium::account_list_item *__last@<eax>,
        survarium::account_list_item *__first,
        const survarium::account_list_item *__val)
{
  survarium::account_list_item *v3; // ecx
  int v4; // ebx
  const survarium::account_list_item *v5; // edi
  char **p_m_end; // esi
  char *v7; // eax
  unsigned int v8; // edi

  v3 = __first;
  v4 = __last - __first;
  if ( v4 > 0 )
  {
    v5 = __val;
    p_m_end = &__first->account_name.m_end;
    do
    {
      v3->account_id = v5->account_id;
      if ( p_m_end - 1 != (char **)&__val->account_name )
      {
        v7 = *(p_m_end - 1);
        *p_m_end = v7;
        *v7 = 0;
        v8 = __val->account_name.m_end - __val->account_name.m_begin;
        memcpy((unsigned __int8 *)*p_m_end, (unsigned __int8 *)__val->account_name.m_begin, v8);
        v3 = __first;
        *p_m_end += v8;
        v5 = __val;
        **p_m_end = 0;
      }
      *((_BYTE *)p_m_end + 40) = v5->online;
      ++v3;
      --v4;
      p_m_end += 13;
      __first = v3;
    }
    while ( v4 > 0 );
  }
}

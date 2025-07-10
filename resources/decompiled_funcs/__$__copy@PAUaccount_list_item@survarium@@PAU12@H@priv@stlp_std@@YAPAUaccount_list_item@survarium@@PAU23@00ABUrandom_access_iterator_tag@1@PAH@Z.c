survarium::account_list_item *__usercall stlp_std::priv::__copy<survarium::account_list_item *,survarium::account_list_item *,int>@<eax>(
        survarium::account_list_item *__last@<eax>,
        survarium::account_list_item *__first,
        survarium::account_list_item *__result)
{
  survarium::account_list_item *v3; // ecx
  int v4; // ebp
  survarium::account_list_item *v5; // edi
  vostok::fixed_string<32> *p_account_name; // ebx
  char **p_m_end; // esi
  char *v8; // eax
  unsigned int v9; // edi

  v3 = __first;
  v4 = __last - __first;
  if ( v4 <= 0 )
    return __result;
  v5 = __result;
  p_account_name = &__first->account_name;
  p_m_end = &__result->account_name.m_end;
  do
  {
    v5->account_id = v3->account_id;
    if ( p_m_end - 1 != (char **)p_account_name )
    {
      v8 = *(p_m_end - 1);
      *p_m_end = v8;
      *v8 = 0;
      v9 = p_account_name->m_end - p_account_name->m_begin;
      memcpy((unsigned __int8 *)*p_m_end, (unsigned __int8 *)p_account_name->m_begin, v9);
      v3 = __first;
      *p_m_end += v9;
      v5 = __result;
      **p_m_end = 0;
    }
    *((_BYTE *)p_m_end + 40) = p_account_name[1].m_begin;
    ++v3;
    ++v5;
    --v4;
    p_account_name = (vostok::fixed_string<32> *)((char *)p_account_name + 52);
    p_m_end += 13;
    __first = v3;
    __result = v5;
  }
  while ( v4 > 0 );
  return v5;
}

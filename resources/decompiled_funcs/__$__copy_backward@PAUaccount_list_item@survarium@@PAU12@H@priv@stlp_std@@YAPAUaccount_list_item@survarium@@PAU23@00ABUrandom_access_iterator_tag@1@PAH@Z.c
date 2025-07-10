survarium::account_list_item *__cdecl stlp_std::priv::__copy_backward<survarium::account_list_item *,survarium::account_list_item *,int>(
        survarium::account_list_item *__first,
        survarium::account_list_item *__last,
        survarium::account_list_item *__result)
{
  survarium::account_list_item *v3; // edi
  survarium::account_list_item *result; // eax
  int v5; // ebp
  vostok::fixed_string<32> *p_account_name; // ebx
  char **p_m_end; // esi
  unsigned int account_id; // ecx
  char *v9; // eax
  unsigned int v10; // edi
  survarium::account_list_item *__lasta; // [esp+10h] [ebp+8h]
  survarium::account_list_item *__resulta; // [esp+14h] [ebp+Ch]

  v3 = __last;
  result = __result;
  v5 = __last - __first;
  if ( v5 > 0 )
  {
    p_account_name = &__last->account_name;
    p_m_end = &__result->account_name.m_end;
    do
    {
      account_id = v3[-1].account_id;
      --v3;
      p_m_end -= 13;
      --result;
      p_account_name = (vostok::fixed_string<32> *)((char *)p_account_name - 52);
      __lasta = v3;
      __resulta = result;
      result->account_id = account_id;
      if ( p_m_end - 1 != (char **)p_account_name )
      {
        v9 = *(p_m_end - 1);
        *p_m_end = v9;
        *v9 = 0;
        v10 = p_account_name->m_end - p_account_name->m_begin;
        memcpy((unsigned __int8 *)*p_m_end, (unsigned __int8 *)p_account_name->m_begin, v10);
        *p_m_end += v10;
        v3 = __lasta;
        **p_m_end = 0;
        result = __resulta;
      }
      --v5;
      *((_BYTE *)p_m_end + 40) = p_account_name[1].m_begin;
    }
    while ( v5 > 0 );
  }
  return result;
}

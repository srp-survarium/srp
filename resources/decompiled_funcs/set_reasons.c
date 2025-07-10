int __cdecl set_reasons(asn1_string_st **preas, char *value)
{
  int v2; // ebp
  stack_st_CONF_VALUE *v3; // eax
  stack_st *p_stack; // ebx
  asn1_string_st **v6; // esi
  const char *v7; // edi
  asn1_string_st *v8; // eax
  const BIT_STRING_BITNAME_st *v9; // esi
  int v10; // [esp+8h] [ebp-4h]

  v2 = 0;
  v10 = 0;
  v3 = X509V3_parse_list(value);
  p_stack = &v3->stack;
  if ( !v3 )
    return 0;
  v6 = preas;
  if ( *preas )
    return 0;
  if ( sk_num(&v3->stack) <= 0 )
  {
LABEL_17:
    v10 = 1;
  }
  else
  {
    while ( 1 )
    {
      v7 = (const char *)*((_DWORD *)sk_value(p_stack, v2) + 1);
      if ( !*v6 )
      {
        v8 = ASN1_BIT_STRING_new();
        *v6 = v8;
        if ( !v8 )
          break;
      }
      v9 = reason_flags;
      if ( reason_flags[0].lname )
      {
        while ( strcmp(v9->sname, v7) )
        {
          ++v9;
          if ( !v9->lname )
            goto LABEL_15;
        }
        if ( !ASN1_BIT_STRING_set_bit(*preas, v9->bitnum, 1) )
          break;
      }
LABEL_15:
      if ( !v9->lname )
        break;
      if ( ++v2 >= sk_num(p_stack) )
        goto LABEL_17;
      v6 = preas;
    }
  }
  sk_pop_free(p_stack, (void (__cdecl *)(void *))X509V3_conf_free);
  return v10;
}

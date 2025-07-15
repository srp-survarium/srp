int __cdecl X509V3_NAME_from_section(X509_name_st *nm, stack_st_CONF_VALUE *dn_sk, int chtype)
{
  int v4; // edi
  char *v5; // eax
  char *v6; // esi
  char v7; // cl
  char *v8; // edx
  char *v9; // edx
  int v10; // ecx

  if ( !nm )
    return 0;
  v4 = 0;
  if ( sk_num(&dn_sk->stack) <= 0 )
    return 1;
  while ( 1 )
  {
    v5 = sk_value(&dn_sk->stack, v4);
    v6 = (char *)*((_DWORD *)v5 + 1);
    v7 = *v6;
    v8 = v6;
    if ( *v6 )
    {
      while ( v7 != 58 && v7 != 44 && v7 != 46 )
      {
        v7 = *++v8;
        if ( !v7 )
          goto LABEL_12;
      }
      v9 = v8 + 1;
      if ( *v9 )
        v6 = v9;
    }
LABEL_12:
    if ( *v6 == 43 )
    {
      v10 = -1;
      ++v6;
    }
    else
    {
      v10 = 0;
    }
    if ( !X509_NAME_add_entry_by_txt((int)dn_sk, nm, v6, chtype, *((__m128i **)v5 + 2), -1, -1, v10) )
      return 0;
    if ( ++v4 >= sk_num(&dn_sk->stack) )
      return 1;
  }
}

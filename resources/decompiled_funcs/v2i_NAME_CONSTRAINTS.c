stack_st **__cdecl v2i_NAME_CONSTRAINTS(const v3_ext_method *method, v3_ext_ctx *ctx, stack_st_CONF_VALUE *nval)
{
  GENERAL_NAME_st **v3; // edi
  stack_st **v4; // ebx
  int v5; // ebp
  char *v6; // esi
  int v7; // eax
  char *v8; // eax
  int v9; // eax
  stack_st *v10; // eax
  stack_st **v12; // [esp+10h] [ebp-10h]
  CONF_VALUE cnf; // [esp+14h] [ebp-Ch] BYREF

  v3 = 0;
  v4 = (stack_st **)ASN1_item_new(&local_it_0);
  v12 = v4;
  if ( v4 )
  {
    v5 = 0;
    if ( sk_num(&nval->stack) <= 0 )
      return v4;
    while ( 1 )
    {
      v6 = sk_value(&nval->stack, v5);
      if ( !strncmp(*((const char **)v6 + 1), "permitted", 9u) && (v7 = *((_DWORD *)v6 + 1), *(_BYTE *)(v7 + 9)) )
      {
        v8 = (char *)(v7 + 10);
      }
      else
      {
        if ( strncmp(*((const char **)v6 + 1), "excluded", 8u) || (v9 = *((_DWORD *)v6 + 1), !*(_BYTE *)(v9 + 8)) )
        {
          ERR_put_error(0x22u, 147, 143, ".\\crypto\\x509v3\\v3_ncons.c", 135);
          goto err_8;
        }
        ++v4;
        v8 = (char *)(v9 + 9);
      }
      cnf.name = v8;
      cnf.value = (char *)*((_DWORD *)v6 + 2);
      v3 = (GENERAL_NAME_st **)ASN1_item_new(&local_it);
      if ( !v2i_GENERAL_NAME_ex(*v3, method, ctx, &cnf, 1) )
        break;
      if ( !*v4 && (v10 = sk_new_null(), (*v4 = v10) == 0) || !sk_push(*v4, (char *)v3) )
      {
        v4 = v12;
        goto memerr;
      }
      v3 = 0;
      ++v5;
      v4 = v12;
      if ( v5 >= sk_num(&nval->stack) )
        return v4;
    }
    v4 = v12;
  }
  else
  {
memerr:
    ERR_put_error(0x22u, 147, 65, ".\\crypto\\x509v3\\v3_ncons.c", 152);
  }
err_8:
  if ( v4 )
    ASN1_item_free((struct ASN1_VALUE_st *)v4, &local_it_0);
  if ( v3 )
    ASN1_item_free((struct ASN1_VALUE_st *)v3, &local_it);
  return 0;
}

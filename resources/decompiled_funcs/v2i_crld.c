stack_st *__cdecl v2i_crld(const v3_ext_method *method, v3_ext_ctx *ctx, stack_st_CONF_VALUE *nval)
{
  int v3; // edi
  char *v4; // ebp
  CONF_VALUE *v5; // eax
  stack_st_CONF_VALUE *section; // eax
  stack_st_CONF_VALUE *v7; // esi
  struct ASN1_VALUE_st *v8; // edi
  stack_st_GENERAL_NAME *v9; // eax
  char *v10; // esi
  struct ASN1_VALUE_st *v11; // eax
  stack_st_GENERAL_NAME *a; // [esp+10h] [ebp-Ch]
  stack_st *v14; // [esp+14h] [ebp-8h]
  int v15; // [esp+18h] [ebp-4h]

  v3 = 0;
  a = 0;
  v4 = 0;
  v14 = sk_new_null();
  if ( !v14 )
    goto merr;
  v15 = 0;
  if ( sk_num(&nval->stack) <= 0 )
    return v14;
  while ( 1 )
  {
    v5 = (CONF_VALUE *)sk_value(&nval->stack, v3);
    if ( v5->value )
      break;
    section = X509V3_get_section(ctx, v5->name);
    v7 = section;
    if ( !section )
      goto err_31;
    v8 = (struct ASN1_VALUE_st *)crldp_from_section(ctx, section);
    X509V3_section_free(ctx, v7);
    if ( !v8 )
      goto err_31;
    if ( !sk_push(v14, (char *)v8) )
    {
      ASN1_item_free(v8, &local_it_12);
      goto merr;
    }
    v3 = v15;
LABEL_15:
    v15 = ++v3;
    if ( v3 >= sk_num(&nval->stack) )
      return v14;
  }
  v4 = (char *)v2i_GENERAL_NAME(method, ctx, v5);
  if ( !v4 )
    goto err_31;
  v9 = GENERAL_NAMES_new();
  a = v9;
  if ( !v9 )
    goto merr;
  if ( !sk_push(&v9->stack, v4) )
    goto merr;
  v4 = 0;
  v10 = (char *)ASN1_item_new(&local_it_12);
  if ( !v10 )
    goto merr;
  if ( sk_push(v14, v10) )
  {
    v11 = ASN1_item_new(&local_it_11);
    *(_DWORD *)v10 = v11;
    if ( !v11 )
      goto merr;
    *((_DWORD *)v11 + 1) = a;
    **(_DWORD **)v10 = 0;
    a = 0;
    goto LABEL_15;
  }
  ASN1_item_free((struct ASN1_VALUE_st *)v10, &local_it_12);
merr:
  ERR_put_error(0x22u, 134, 65, ".\\crypto\\x509v3\\v3_crld.c", 365);
err_31:
  GENERAL_NAME_free((GENERAL_NAME_st *)v4);
  GENERAL_NAMES_free(a);
  sk_pop_free(v14, (void (__cdecl *)(void *))DIST_POINT_free);
  return 0;
}

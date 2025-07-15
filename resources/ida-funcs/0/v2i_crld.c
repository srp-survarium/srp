stack_st *__usercall v2i_crld@<eax>(
        v3_ext_ctx *a1@<ebx>,
        const v3_ext_method *method,
        v3_ext_ctx *ctx,
        stack_st_CONF_VALUE *nval)
{
  int v4; // edi
  char *v5; // ebp
  CONF_VALUE *v6; // eax
  stack_st_CONF_VALUE *section; // eax
  stack_st_CONF_VALUE *v8; // esi
  struct ASN1_VALUE_st *v9; // edi
  stack_st_GENERAL_NAME *v10; // eax
  char *v11; // esi
  struct ASN1_VALUE_st *v12; // eax
  stack_st_GENERAL_NAME *a; // [esp+10h] [ebp-Ch]
  stack_st *v15; // [esp+14h] [ebp-8h]
  int v16; // [esp+18h] [ebp-4h]

  v4 = 0;
  a = 0;
  v5 = 0;
  v15 = sk_new_null();
  if ( !v15 )
    goto merr;
  v16 = 0;
  if ( sk_num(&nval->stack) <= 0 )
    return v15;
  a1 = ctx;
  while ( 1 )
  {
    v6 = (CONF_VALUE *)sk_value(&nval->stack, v4);
    if ( v6->value )
      break;
    section = X509V3_get_section(ctx);
    v8 = section;
    if ( !section )
      goto err_33;
    v9 = (struct ASN1_VALUE_st *)crldp_from_section(ctx, section);
    X509V3_section_free(ctx, v8);
    if ( !v9 )
      goto err_33;
    if ( !sk_push(v15, (char *)v9) )
    {
      ASN1_item_free(v9, &local_it_12);
      goto merr;
    }
    v4 = v16;
LABEL_16:
    v16 = ++v4;
    if ( v4 >= sk_num(&nval->stack) )
      return v15;
  }
  v5 = (char *)v2i_GENERAL_NAME(method, ctx, v6);
  if ( !v5 )
    goto err_33;
  v10 = GENERAL_NAMES_new();
  a = v10;
  if ( !v10 )
    goto merr;
  if ( !sk_push(&v10->stack, v5) )
    goto merr;
  v5 = 0;
  v11 = (char *)ASN1_item_new(&local_it_12);
  if ( !v11 )
    goto merr;
  if ( sk_push(v15, v11) )
  {
    v12 = ASN1_item_new(&local_it_11);
    *(_DWORD *)v11 = v12;
    if ( !v12 )
      goto merr;
    *((_DWORD *)v12 + 1) = a;
    **(_DWORD **)v11 = 0;
    a = 0;
    goto LABEL_16;
  }
  ASN1_item_free((struct ASN1_VALUE_st *)v11, &local_it_12);
merr:
  ERR_put_error((int)a1, 0x22u, 134, 65, ".\\crypto\\x509v3\\v3_crld.c", 365);
err_33:
  GENERAL_NAME_free((GENERAL_NAME_st *)v5);
  GENERAL_NAMES_free(a);
  sk_pop_free(v15, (void (__cdecl *)(void *))DIST_POINT_free);
  return 0;
}

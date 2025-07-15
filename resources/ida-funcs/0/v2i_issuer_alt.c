stack_st_GENERAL_NAME *__usercall v2i_issuer_alt@<eax>(
        int a1@<ebx>,
        v3_ext_method *method,
        v3_ext_ctx *ctx,
        stack_st_CONF_VALUE *nval)
{
  stack_st *v4; // esi
  stack_st_CONF_VALUE *v6; // ebx
  int v7; // edi
  CONF_VALUE *v8; // esi
  const char *value; // eax
  char *v10; // eax
  stack_st_GENERAL_NAME *gens; // [esp+4h] [ebp-4h]

  v4 = sk_new_null();
  gens = (stack_st_GENERAL_NAME *)v4;
  if ( !v4 )
  {
    ERR_put_error(a1, 0x22u, 153, 65, ".\\crypto\\x509v3\\v3_alt.c", 250);
    return 0;
  }
  v6 = nval;
  v7 = 0;
  if ( sk_num(&nval->stack) <= 0 )
    return (stack_st_GENERAL_NAME *)v4;
  while ( 1 )
  {
    v8 = (CONF_VALUE *)sk_value(&v6->stack, v7);
    if ( name_cmp(v8->name, "issuer") )
      break;
    value = v8->value;
    if ( !value || strcmp(value, "copy") )
      break;
    if ( !copy_issuer(ctx, gens) )
      goto err_39;
    v6 = nval;
LABEL_11:
    if ( ++v7 >= sk_num(&v6->stack) )
      return gens;
  }
  v10 = (char *)v2i_GENERAL_NAME_ex((int)v6, 0, method, ctx, v8, 0);
  if ( v10 )
  {
    sk_push(&gens->stack, v10);
    goto LABEL_11;
  }
err_39:
  sk_pop_free(&gens->stack, (void (__cdecl *)(void *))GENERAL_NAME_free);
  return 0;
}

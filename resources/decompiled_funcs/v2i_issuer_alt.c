stack_st_GENERAL_NAME *__cdecl v2i_issuer_alt(v3_ext_method *method, v3_ext_ctx *ctx, stack_st_CONF_VALUE *nval)
{
  stack_st *v3; // esi
  stack_st_CONF_VALUE *v5; // ebx
  int v6; // edi
  CONF_VALUE *v7; // esi
  const char *value; // eax
  char *v9; // eax
  stack_st_GENERAL_NAME *gens; // [esp+4h] [ebp-4h]

  v3 = sk_new_null();
  gens = (stack_st_GENERAL_NAME *)v3;
  if ( !v3 )
  {
    ERR_put_error(0x22u, 153, 65, ".\\crypto\\x509v3\\v3_alt.c", 250);
    return 0;
  }
  v5 = nval;
  v6 = 0;
  if ( sk_num(&nval->stack) <= 0 )
    return (stack_st_GENERAL_NAME *)v3;
  while ( 1 )
  {
    v7 = (CONF_VALUE *)sk_value(&v5->stack, v6);
    if ( name_cmp(v7->name, "issuer") )
      break;
    value = v7->value;
    if ( !value || strcmp(value, "copy") )
      break;
    if ( !copy_issuer(ctx, gens) )
      goto err_37;
    v5 = nval;
LABEL_11:
    if ( ++v6 >= sk_num(&v5->stack) )
      return gens;
  }
  v9 = (char *)v2i_GENERAL_NAME_ex(0, method, ctx, v7, 0);
  if ( v9 )
  {
    sk_push(&gens->stack, v9);
    goto LABEL_11;
  }
err_37:
  sk_pop_free(&gens->stack, (void (__cdecl *)(void *))GENERAL_NAME_free);
  return 0;
}

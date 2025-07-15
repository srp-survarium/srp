stack_st_GENERAL_NAME *__cdecl v2i_GENERAL_NAMES(
        const v3_ext_method *method,
        v3_ext_ctx *ctx,
        stack_st_CONF_VALUE *nval)
{
  stack_st *v3; // ebx
  int v5; // esi
  char *v6; // eax
  char *v7; // eax

  v3 = sk_new_null();
  if ( v3 )
  {
    v5 = 0;
    if ( sk_num(&nval->stack) <= 0 )
    {
      return (stack_st_GENERAL_NAME *)v3;
    }
    else
    {
      while ( 1 )
      {
        v6 = sk_value(&nval->stack, v5);
        v7 = (char *)v2i_GENERAL_NAME_ex((int)ctx, 0, method, ctx, (CONF_VALUE *)v6, 0);
        if ( !v7 )
          break;
        sk_push(v3, v7);
        if ( ++v5 >= sk_num(&nval->stack) )
          return (stack_st_GENERAL_NAME *)v3;
      }
      sk_pop_free(v3, (void (__cdecl *)(void *))GENERAL_NAME_free);
      return 0;
    }
  }
  else
  {
    ERR_put_error(0, 0x22u, 118, 65, ".\\crypto\\x509v3\\v3_alt.c", 404);
    return 0;
  }
}

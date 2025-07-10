stack_st_GENERAL_NAME *__cdecl v2i_subject_alt(v3_ext_method *method, X509_name_st *ctx, stack_st_CONF_VALUE *nval)
{
  stack_st_GENERAL_NAME *v3; // ebp
  int v5; // ebx
  CONF_VALUE *v6; // esi
  const char *value; // eax
  int v8; // eax
  const char *v9; // eax
  char *v10; // eax

  v3 = (stack_st_GENERAL_NAME *)sk_new_null();
  if ( !v3 )
  {
    ERR_put_error(0x22u, 154, 65, ".\\crypto\\x509v3\\v3_alt.c", 315);
    return 0;
  }
  v5 = 0;
  if ( sk_num(&nval->stack) > 0 )
  {
    while ( 1 )
    {
      v6 = (CONF_VALUE *)sk_value(&nval->stack, v5);
      if ( !name_cmp(v6->name, "email") )
      {
        value = v6->value;
        if ( value )
        {
          if ( !strcmp(value, "copy") )
            break;
        }
      }
      if ( !name_cmp(v6->name, "email") )
      {
        v9 = v6->value;
        if ( v9 )
        {
          if ( !strcmp(v9, "move") )
          {
            v8 = copy_email(ctx, v3, 1);
LABEL_12:
            if ( !v8 )
              goto err_38;
            goto LABEL_16;
          }
        }
      }
      v10 = (char *)v2i_GENERAL_NAME_ex(0, method, (v3_ext_ctx *)ctx, v6, 0);
      if ( !v10 )
      {
err_38:
        sk_pop_free(&v3->stack, (void (__cdecl *)(void *))GENERAL_NAME_free);
        return 0;
      }
      sk_push(&v3->stack, v10);
LABEL_16:
      if ( ++v5 >= sk_num(&nval->stack) )
        return v3;
    }
    v8 = copy_email(ctx, v3, 0);
    goto LABEL_12;
  }
  return v3;
}

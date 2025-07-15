stack_st_GENERAL_NAME *__usercall v2i_subject_alt@<eax>(
        int a1@<ebx>,
        v3_ext_method *method,
        X509_name_st *ctx,
        stack_st_CONF_VALUE *nval)
{
  stack_st_GENERAL_NAME *v4; // ebp
  int v6; // ebx
  CONF_VALUE *v7; // esi
  const char *value; // eax
  int v9; // eax
  const char *v10; // eax
  char *v11; // eax

  v4 = (stack_st_GENERAL_NAME *)sk_new_null();
  if ( !v4 )
  {
    ERR_put_error(a1, 0x22u, 154, 65, ".\\crypto\\x509v3\\v3_alt.c", 315);
    return 0;
  }
  v6 = 0;
  if ( sk_num(&nval->stack) > 0 )
  {
    while ( 1 )
    {
      v7 = (CONF_VALUE *)sk_value(&nval->stack, v6);
      if ( !name_cmp(v7->name, "email") )
      {
        value = v7->value;
        if ( value )
        {
          if ( !strcmp(value, "copy") )
            break;
        }
      }
      if ( !name_cmp(v7->name, "email") )
      {
        v10 = v7->value;
        if ( v10 )
        {
          if ( !strcmp(v10, "move") )
          {
            v9 = copy_email(ctx, v4, 1);
LABEL_12:
            if ( !v9 )
              goto err_40;
            goto LABEL_16;
          }
        }
      }
      v11 = (char *)v2i_GENERAL_NAME_ex(v6, 0, method, (v3_ext_ctx *)ctx, v7, 0);
      if ( !v11 )
      {
err_40:
        sk_pop_free(&v4->stack, (void (__cdecl *)(void *))GENERAL_NAME_free);
        return 0;
      }
      sk_push(&v4->stack, v11);
LABEL_16:
      if ( ++v6 >= sk_num(&nval->stack) )
        return v4;
    }
    v9 = copy_email(ctx, v4, 0);
    goto LABEL_12;
  }
  return v4;
}

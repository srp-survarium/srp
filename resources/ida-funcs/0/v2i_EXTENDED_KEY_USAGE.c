stack_st *__usercall v2i_EXTENDED_KEY_USAGE@<eax>(
        int a1@<ebx>,
        const v3_ext_method *method,
        v3_ext_ctx *ctx,
        stack_st_CONF_VALUE *nval)
{
  stack_st *v4; // ebp
  int v6; // esi
  char *v7; // edi
  char *v8; // eax
  char *v9; // eax

  v4 = sk_new_null();
  if ( v4 )
  {
    v6 = 0;
    if ( sk_num(&nval->stack) <= 0 )
    {
      return v4;
    }
    else
    {
      while ( 1 )
      {
        v7 = sk_value(&nval->stack, v6);
        v8 = (char *)*((_DWORD *)v7 + 2);
        if ( !v8 )
          v8 = (char *)*((_DWORD *)v7 + 1);
        v9 = (char *)OBJ_txt2obj((int)nval, v8, 0);
        if ( !v9 )
          break;
        sk_push(v4, v9);
        if ( ++v6 >= sk_num(&nval->stack) )
          return v4;
      }
      sk_pop_free(v4, (void (__cdecl *)(void *))ASN1_OBJECT_free);
      ERR_put_error((int)nval, 0x22u, 103, 110, ".\\crypto\\x509v3\\v3_extku.c", 137);
      ERR_add_error_data(6, "section:", *(_DWORD *)v7, ",name:", *((_DWORD *)v7 + 1), ",value:", *((_DWORD *)v7 + 2));
      return 0;
    }
  }
  else
  {
    ERR_put_error(a1, 0x22u, 103, 65, ".\\crypto\\x509v3\\v3_extku.c", 127);
    return 0;
  }
}

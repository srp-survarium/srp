stack_st *__cdecl v2i_EXTENDED_KEY_USAGE(const v3_ext_method *method, v3_ext_ctx *ctx, stack_st_CONF_VALUE *nval)
{
  stack_st *v3; // ebp
  int v5; // esi
  char *v6; // edi
  char *v7; // eax
  char *v8; // eax

  v3 = sk_new_null();
  if ( v3 )
  {
    v5 = 0;
    if ( sk_num(&nval->stack) <= 0 )
    {
      return v3;
    }
    else
    {
      while ( 1 )
      {
        v6 = sk_value(&nval->stack, v5);
        v7 = (char *)*((_DWORD *)v6 + 2);
        if ( !v7 )
          v7 = (char *)*((_DWORD *)v6 + 1);
        v8 = (char *)OBJ_txt2obj(v7, 0);
        if ( !v8 )
          break;
        sk_push(v3, v8);
        if ( ++v5 >= sk_num(&nval->stack) )
          return v3;
      }
      sk_pop_free(v3, (void (__cdecl *)(void *))ASN1_OBJECT_free);
      ERR_put_error(0x22u, 103, 110, ".\\crypto\\x509v3\\v3_extku.c", 137);
      ERR_add_error_data(6, "section:", *(_DWORD *)v6, ",name:", *((_DWORD *)v6 + 1), ",value:", *((_DWORD *)v6 + 2));
      return 0;
    }
  }
  else
  {
    ERR_put_error(0x22u, 103, 65, ".\\crypto\\x509v3\\v3_extku.c", 127);
    return 0;
  }
}

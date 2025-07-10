stack_st_ACCESS_DESCRIPTION *__cdecl v2i_AUTHORITY_INFO_ACCESS(
        v3_ext_method *method,
        v3_ext_ctx *ctx,
        stack_st_CONF_VALUE *nval)
{
  char *v4; // ebx
  struct ASN1_VALUE_st *v5; // ebp
  int v6; // eax
  unsigned int v7; // esi
  unsigned __int8 *v8; // eax
  char *v9; // edi
  asn1_object_st *v10; // eax
  int v11; // [esp-14h] [ebp-28h]
  int i; // [esp+0h] [ebp-14h]
  stack_st *v13; // [esp+4h] [ebp-10h]
  CONF_VALUE cnf; // [esp+8h] [ebp-Ch] BYREF

  v13 = sk_new_null();
  if ( v13 )
  {
    i = 0;
    if ( sk_num(&nval->stack) <= 0 )
    {
      return (stack_st_ACCESS_DESCRIPTION *)v13;
    }
    else
    {
      while ( 1 )
      {
        v4 = sk_value(&nval->stack, i);
        v5 = ASN1_item_new(&local_it_70);
        if ( !v5 || !sk_push(v13, (char *)v5) )
          break;
        strchr(*((char **)v4 + 1), 0x3Bu);
        if ( !v6 )
        {
          ERR_put_error(0x22u, 139, 143, ".\\crypto\\x509v3\\v3_info.c", 156);
          goto err_94;
        }
        v7 = v6 - *((_DWORD *)v4 + 1);
        cnf.name = (char *)(v6 + 1);
        cnf.value = (char *)*((_DWORD *)v4 + 2);
        if ( !v2i_GENERAL_NAME_ex(*((GENERAL_NAME_st **)v5 + 1), method, ctx, &cnf, 0) )
          goto err_94;
        v8 = (unsigned __int8 *)CRYPTO_malloc(v7 + 1, ".\\crypto\\x509v3\\v3_info.c", 164);
        v9 = (char *)v8;
        if ( !v8 )
        {
          v11 = 165;
          goto LABEL_16;
        }
        strncpy(v8, *((unsigned __int8 **)v4 + 1), v7);
        v9[v7] = 0;
        v10 = OBJ_txt2obj(v9, 0);
        *(_DWORD *)v5 = v10;
        if ( !v10 )
        {
          ERR_put_error(0x22u, 139, 119, ".\\crypto\\x509v3\\v3_info.c", 172);
          ERR_add_error_data(2, "value=", v9);
          CRYPTO_free(v9);
          goto err_94;
        }
        CRYPTO_free(v9);
        if ( ++i >= sk_num(&nval->stack) )
          return (stack_st_ACCESS_DESCRIPTION *)v13;
      }
      v11 = 151;
LABEL_16:
      ERR_put_error(0x22u, 139, 65, ".\\crypto\\x509v3\\v3_info.c", v11);
err_94:
      sk_pop_free(v13, (void (__cdecl *)(void *))ACCESS_DESCRIPTION_free);
      return 0;
    }
  }
  else
  {
    ERR_put_error(0x22u, 139, 65, ".\\crypto\\x509v3\\v3_info.c", 144);
    return 0;
  }
}

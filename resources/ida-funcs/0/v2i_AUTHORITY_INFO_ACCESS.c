stack_st_ACCESS_DESCRIPTION *__usercall v2i_AUTHORITY_INFO_ACCESS@<eax>(
        int a1@<ebx>,
        v3_ext_method *method,
        v3_ext_ctx *ctx,
        stack_st_CONF_VALUE *nval)
{
  char *v5; // ebx
  struct ASN1_VALUE_st *v6; // ebp
  int v7; // eax
  unsigned int v8; // esi
  unsigned __int8 *v9; // eax
  char *v10; // edi
  asn1_object_st *v11; // eax
  int v12; // [esp-14h] [ebp-28h]
  int v13; // [esp+0h] [ebp-14h]
  stack_st *v14; // [esp+4h] [ebp-10h]
  CONF_VALUE cnf; // [esp+8h] [ebp-Ch] BYREF

  v14 = sk_new_null();
  if ( v14 )
  {
    v13 = 0;
    if ( sk_num(&nval->stack) <= 0 )
    {
      return (stack_st_ACCESS_DESCRIPTION *)v14;
    }
    else
    {
      while ( 1 )
      {
        v5 = sk_value(&nval->stack, v13);
        v6 = ASN1_item_new(&local_it_70);
        if ( !v6 || !sk_push(v14, (char *)v6) )
          break;
        strchr(*((char **)v5 + 1), 0x3Bu);
        if ( !v7 )
        {
          ERR_put_error((int)v5, 0x22u, 139, 143, ".\\crypto\\x509v3\\v3_info.c", 156);
          goto err_96;
        }
        v8 = v7 - *((_DWORD *)v5 + 1);
        cnf.name = (char *)(v7 + 1);
        cnf.value = (char *)*((_DWORD *)v5 + 2);
        if ( !v2i_GENERAL_NAME_ex((int)v5, *((GENERAL_NAME_st **)v6 + 1), method, ctx, &cnf, 0) )
          goto err_96;
        v9 = (unsigned __int8 *)CRYPTO_malloc(v8 + 1, ".\\crypto\\x509v3\\v3_info.c", 164);
        v10 = (char *)v9;
        if ( !v9 )
        {
          v12 = 165;
          goto LABEL_16;
        }
        strncpy(v9, *((unsigned __int8 **)v5 + 1), v8);
        v10[v8] = 0;
        v11 = OBJ_txt2obj((int)v5, v10, 0);
        *(_DWORD *)v6 = v11;
        if ( !v11 )
        {
          ERR_put_error((int)v5, 0x22u, 139, 119, ".\\crypto\\x509v3\\v3_info.c", 172);
          ERR_add_error_data(2, "value=", v10);
          CRYPTO_free(v10);
          goto err_96;
        }
        CRYPTO_free(v10);
        if ( ++v13 >= sk_num(&nval->stack) )
          return (stack_st_ACCESS_DESCRIPTION *)v14;
      }
      v12 = 151;
LABEL_16:
      ERR_put_error((int)v5, 0x22u, 139, 65, ".\\crypto\\x509v3\\v3_info.c", v12);
err_96:
      sk_pop_free(v14, (void (__cdecl *)(void *))ACCESS_DESCRIPTION_free);
      return 0;
    }
  }
  else
  {
    ERR_put_error(a1, 0x22u, 139, 65, ".\\crypto\\x509v3\\v3_info.c", 144);
    return 0;
  }
}

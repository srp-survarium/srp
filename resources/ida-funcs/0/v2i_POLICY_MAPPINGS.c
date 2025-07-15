stack_st *__usercall v2i_POLICY_MAPPINGS@<eax>(
        int a1@<ebx>,
        const v3_ext_method *method,
        v3_ext_ctx *ctx,
        stack_st_CONF_VALUE *nval)
{
  int v5; // ebx
  char *v6; // eax
  char *v7; // esi
  char *v8; // eax
  asn1_object_st *v9; // edi
  asn1_object_st *v10; // eax
  asn1_object_st *v11; // ebp
  struct ASN1_VALUE_st *v12; // eax
  stack_st *v13; // [esp+0h] [ebp-4h]

  v13 = sk_new_null();
  if ( v13 )
  {
    v5 = 0;
    if ( sk_num(&nval->stack) <= 0 )
    {
      return v13;
    }
    else
    {
      while ( 1 )
      {
        v6 = sk_value(&nval->stack, v5);
        v7 = v6;
        if ( !*((_DWORD *)v6 + 2) )
          break;
        v8 = (char *)*((_DWORD *)v6 + 1);
        if ( !v8 )
          break;
        v9 = OBJ_txt2obj(v5, v8, 0);
        v10 = OBJ_txt2obj(v5, *((char **)v7 + 2), 0);
        v11 = v10;
        if ( !v9 || !v10 )
        {
          sk_pop_free(v13, (void (__cdecl *)(void *))POLICY_MAPPING_free);
          ERR_put_error(v5, 0x22u, 145, 110, ".\\crypto\\x509v3\\v3_pmaps.c", 140);
          ERR_add_error_data(
            6,
            "section:",
            *(_DWORD *)v7,
            ",name:",
            *((_DWORD *)v7 + 1),
            ",value:",
            *((_DWORD *)v7 + 2));
          return 0;
        }
        v12 = ASN1_item_new(&local_it_67);
        if ( !v12 )
        {
          sk_pop_free(v13, (void (__cdecl *)(void *))POLICY_MAPPING_free);
          ERR_put_error(v5, 0x22u, 145, 65, ".\\crypto\\x509v3\\v3_pmaps.c", 147);
          return 0;
        }
        *(_DWORD *)v12 = v9;
        *((_DWORD *)v12 + 1) = v11;
        sk_push(v13, (char *)v12);
        if ( ++v5 >= sk_num(&nval->stack) )
          return v13;
      }
      sk_pop_free(v13, (void (__cdecl *)(void *))POLICY_MAPPING_free);
      ERR_put_error(v5, 0x22u, 145, 110, ".\\crypto\\x509v3\\v3_pmaps.c", 132);
      ERR_add_error_data(6, "section:", *(_DWORD *)v7, ",name:", *((_DWORD *)v7 + 1), ",value:", *((_DWORD *)v7 + 2));
      return 0;
    }
  }
  else
  {
    ERR_put_error(a1, 0x22u, 145, 65, ".\\crypto\\x509v3\\v3_pmaps.c", 124);
    return 0;
  }
}

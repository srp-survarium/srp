stack_st *__cdecl v2i_POLICY_MAPPINGS(const v3_ext_method *method, v3_ext_ctx *ctx, stack_st_CONF_VALUE *nval)
{
  int v4; // ebx
  char *v5; // eax
  char *v6; // esi
  char *v7; // eax
  asn1_object_st *v8; // edi
  asn1_object_st *v9; // eax
  asn1_object_st *v10; // ebp
  struct ASN1_VALUE_st *v11; // eax
  stack_st *v12; // [esp+0h] [ebp-4h]

  v12 = sk_new_null();
  if ( v12 )
  {
    v4 = 0;
    if ( sk_num(&nval->stack) <= 0 )
    {
      return v12;
    }
    else
    {
      while ( 1 )
      {
        v5 = sk_value(&nval->stack, v4);
        v6 = v5;
        if ( !*((_DWORD *)v5 + 2) )
          break;
        v7 = (char *)*((_DWORD *)v5 + 1);
        if ( !v7 )
          break;
        v8 = OBJ_txt2obj(v7, 0);
        v9 = OBJ_txt2obj(*((char **)v6 + 2), 0);
        v10 = v9;
        if ( !v8 || !v9 )
        {
          sk_pop_free(v12, (void (__cdecl *)(void *))POLICY_MAPPING_free);
          ERR_put_error(0x22u, 145, 110, ".\\crypto\\x509v3\\v3_pmaps.c", 140);
          ERR_add_error_data(
            6,
            "section:",
            *(_DWORD *)v6,
            ",name:",
            *((_DWORD *)v6 + 1),
            ",value:",
            *((_DWORD *)v6 + 2));
          return 0;
        }
        v11 = ASN1_item_new(&local_it_67);
        if ( !v11 )
        {
          sk_pop_free(v12, (void (__cdecl *)(void *))POLICY_MAPPING_free);
          ERR_put_error(0x22u, 145, 65, ".\\crypto\\x509v3\\v3_pmaps.c", 147);
          return 0;
        }
        *(_DWORD *)v11 = v8;
        *((_DWORD *)v11 + 1) = v10;
        sk_push(v12, (char *)v11);
        if ( ++v4 >= sk_num(&nval->stack) )
          return v12;
      }
      sk_pop_free(v12, (void (__cdecl *)(void *))POLICY_MAPPING_free);
      ERR_put_error(0x22u, 145, 110, ".\\crypto\\x509v3\\v3_pmaps.c", 132);
      ERR_add_error_data(6, "section:", *(_DWORD *)v6, ",name:", *((_DWORD *)v6 + 1), ",value:", *((_DWORD *)v6 + 2));
      return 0;
    }
  }
  else
  {
    ERR_put_error(0x22u, 145, 65, ".\\crypto\\x509v3\\v3_pmaps.c", 124);
    return 0;
  }
}

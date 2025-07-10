asn1_string_st *__cdecl v2i_ASN1_BIT_STRING(v3_ext_method *method, v3_ext_ctx *ctx, stack_st_CONF_VALUE *nval)
{
  asn1_string_st *v3; // edi
  stack_st_CONF_VALUE *v5; // esi
  int v6; // ebp
  char *v7; // edi
  char *usr_data; // esi
  const char *v9; // eax
  const char *v10; // edi
  asn1_string_st *a; // [esp+4h] [ebp-8h]
  char *v12; // [esp+8h] [ebp-4h]

  v3 = ASN1_STRING_type_new(3);
  a = v3;
  if ( v3 )
  {
    v5 = nval;
    v6 = 0;
    if ( sk_num(&nval->stack) <= 0 )
    {
      return v3;
    }
    else
    {
      while ( 1 )
      {
        v7 = sk_value(&v5->stack, v6);
        usr_data = (char *)method->usr_data;
        v9 = (const char *)*((_DWORD *)usr_data + 1);
        v12 = v7;
        if ( v9 )
          break;
LABEL_12:
        if ( !*((_DWORD *)usr_data + 1) )
        {
          ERR_put_error(0x22u, 101, 111, ".\\crypto\\x509v3\\v3_bitst.c", 132);
          ERR_add_error_data(
            6,
            "section:",
            *(_DWORD *)v7,
            ",name:",
            *((_DWORD *)v7 + 1),
            ",value:",
            *((_DWORD *)v7 + 2));
          ASN1_STRING_free(a);
          return 0;
        }
        v5 = nval;
        if ( ++v6 >= sk_num(&nval->stack) )
          return a;
      }
      v10 = (const char *)*((_DWORD *)v7 + 1);
      while ( strcmp(*((const char **)usr_data + 2), v10) && strcmp(v9, v10) )
      {
        v9 = (const char *)*((_DWORD *)usr_data + 4);
        usr_data += 12;
        if ( !v9 )
          goto LABEL_11;
      }
      if ( ASN1_BIT_STRING_set_bit(a, *(_DWORD *)usr_data, 1) )
      {
LABEL_11:
        v7 = v12;
        goto LABEL_12;
      }
      ERR_put_error(0x22u, 101, 65, ".\\crypto\\x509v3\\v3_bitst.c", 123);
      ASN1_STRING_free(a);
      return 0;
    }
  }
  else
  {
    ERR_put_error(0x22u, 101, 65, ".\\crypto\\x509v3\\v3_bitst.c", 113);
    return 0;
  }
}

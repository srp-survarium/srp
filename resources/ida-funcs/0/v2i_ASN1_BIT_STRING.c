asn1_string_st *__usercall v2i_ASN1_BIT_STRING@<eax>(
        unsigned __int8 a1@<bl>,
        v3_ext_method *method,
        v3_ext_ctx *ctx,
        stack_st_CONF_VALUE *nval)
{
  asn1_string_st *v4; // edi
  stack_st_CONF_VALUE *v6; // esi
  int v7; // ebp
  char *v8; // edi
  int *usr_data; // esi
  const char *v10; // eax
  const char *v11; // edi
  const char *v12; // ecx
  const char *v13; // edx
  bool v14; // cf
  int v15; // ecx
  asn1_string_st *a; // [esp+4h] [ebp-8h]
  char *v17; // [esp+8h] [ebp-4h]

  v4 = ASN1_STRING_type_new(a1, 3);
  a = v4;
  if ( v4 )
  {
    v6 = nval;
    v7 = 0;
    if ( sk_num(&nval->stack) <= 0 )
    {
      return v4;
    }
    else
    {
      while ( 1 )
      {
        v8 = sk_value(&v6->stack, v7);
        usr_data = (int *)method->usr_data;
        v10 = (const char *)usr_data[1];
        v17 = v8;
        if ( v10 )
          break;
LABEL_19:
        if ( !usr_data[1] )
        {
          ERR_put_error(a1, 0x22u, 101, 111, ".\\crypto\\x509v3\\v3_bitst.c", 132);
          ERR_add_error_data(
            6,
            "section:",
            *(_DWORD *)v8,
            ",name:",
            *((_DWORD *)v8 + 1),
            ",value:",
            *((_DWORD *)v8 + 2));
          ASN1_STRING_free(a);
          return 0;
        }
        v6 = nval;
        if ( ++v7 >= sk_num(&nval->stack) )
          return a;
      }
      v11 = (const char *)*((_DWORD *)v8 + 1);
      while ( 1 )
      {
        v12 = (const char *)usr_data[2];
        v13 = v11;
        while ( 1 )
        {
          a1 = *v12;
          v14 = *v12 < (unsigned int)*v13;
          if ( *v12 != *v13 )
            break;
          if ( !a1 )
            goto LABEL_11;
          a1 = v12[1];
          v14 = a1 < (unsigned int)v13[1];
          if ( a1 != v13[1] )
            break;
          v12 += 2;
          v13 += 2;
          if ( !a1 )
          {
LABEL_11:
            v15 = 0;
            goto LABEL_13;
          }
        }
        v15 = -v14 - (v14 - 1);
LABEL_13:
        if ( !v15 || !strcmp(v10, v11) )
          break;
        v10 = (const char *)usr_data[4];
        usr_data += 3;
        if ( !v10 )
          goto LABEL_18;
      }
      if ( ASN1_BIT_STRING_set_bit(a, *usr_data, 1) )
      {
LABEL_18:
        v8 = v17;
        goto LABEL_19;
      }
      ERR_put_error(a1, 0x22u, 101, 65, ".\\crypto\\x509v3\\v3_bitst.c", 123);
      ASN1_STRING_free(a);
      return 0;
    }
  }
  else
  {
    ERR_put_error(a1, 0x22u, 101, 65, ".\\crypto\\x509v3\\v3_bitst.c", 113);
    return 0;
  }
}

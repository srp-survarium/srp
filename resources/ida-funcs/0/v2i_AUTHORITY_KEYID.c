AUTHORITY_KEYID_st *__usercall v2i_AUTHORITY_KEYID@<eax>(
        char *a1@<edi>,
        v3_ext_method *method,
        v3_ext_ctx *ctx,
        stack_st_CONF_VALUE *values)
{
  int v4; // ebp
  char v5; // bl
  const char *v6; // eax
  const char *v7; // eax
  stack_st_X509_ATTRIBUTE *issuer_cert; // esi
  int ext_by_NID; // eax
  X509_extension_st *ext; // eax
  X509_name_st *issuer_name; // eax
  const asn1_string_st *v13; // eax
  asn1_string_st *v14; // eax
  AUTHORITY_KEYID_st *v15; // esi
  stack_st *v16; // ebx
  char *v17; // eax
  char *v18; // edi
  char v19; // [esp+13h] [ebp-11h]
  asn1_string_st *v20; // [esp+14h] [ebp-10h]
  X509_name_st *a; // [esp+18h] [ebp-Ch]
  asn1_string_st *i; // [esp+1Ch] [ebp-8h]
  stack_st_GENERAL_NAME *v23; // [esp+20h] [ebp-4h]

  v4 = 0;
  v19 = 0;
  v5 = 0;
  v20 = 0;
  a = 0;
  v23 = 0;
  for ( i = 0; v4 < sk_num(&values->stack); ++v4 )
  {
    a1 = sk_value(&values->stack, v4);
    if ( !strcmp(*((const char **)a1 + 1), "keyid") )
    {
      v6 = (const char *)*((_DWORD *)a1 + 2);
      v19 = 1;
      if ( v6 && !strcmp(v6, "always") )
        v19 = 2;
    }
    else
    {
      if ( strcmp(*((const char **)a1 + 1), "issuer") )
      {
        ERR_put_error(v5, 0x22u, 119, 120, ".\\crypto\\x509v3\\v3_akey.c", 143);
        ERR_add_error_data(2, "name=", *((_DWORD *)a1 + 1));
        return 0;
      }
      v7 = (const char *)*((_DWORD *)a1 + 2);
      v5 = 1;
      if ( v7 && !strcmp(v7, "always") )
        v5 = 2;
    }
  }
  if ( !ctx )
  {
LABEL_38:
    ERR_put_error(v5, 0x22u, 119, 121, ".\\crypto\\x509v3\\v3_akey.c", 153);
    return 0;
  }
  issuer_cert = (stack_st_X509_ATTRIBUTE *)ctx->issuer_cert;
  if ( !issuer_cert )
  {
    if ( ctx->flags == 1 )
      return AUTHORITY_KEYID_new();
    goto LABEL_38;
  }
  if ( !v19 )
    goto LABEL_25;
  ext_by_NID = X509_get_ext_by_NID(issuer_cert, 82, -1);
  if ( ext_by_NID >= 0 )
  {
    ext = X509_get_ext((x509_st *)issuer_cert, ext_by_NID);
    if ( ext )
      v20 = (asn1_string_st *)X509V3_EXT_d2i((int)a1, ext);
  }
  if ( v19 != 2 || v20 )
  {
LABEL_25:
    if ( (!v5 || v20) && v5 != 2
      || (issuer_name = X509_get_issuer_name((x509_st *)issuer_cert),
          a = X509_NAME_dup(issuer_name),
          v13 = EVP_CIPHER_CTX_block_size((x509_st *)issuer_cert),
          v14 = ASN1_STRING_dup(v5, v13),
          i = v14,
          a)
      && v14 )
    {
      v15 = AUTHORITY_KEYID_new();
      if ( v15 )
      {
        if ( a )
        {
          v16 = sk_new_null();
          v23 = (stack_st_GENERAL_NAME *)v16;
          if ( !v16 || (v17 = (char *)GENERAL_NAME_new(), (v18 = v17) == 0) || !sk_push(v16, v17) )
          {
            ERR_put_error((unsigned __int8)v16, 0x22u, 119, 65, ".\\crypto\\x509v3\\v3_akey.c", 190);
            goto err_98;
          }
          *(_DWORD *)v18 = 4;
          *((_DWORD *)v18 + 1) = a;
        }
        v15->serial = i;
        v15->issuer = v23;
        v15->keyid = v20;
        return v15;
      }
    }
    else
    {
      ERR_put_error(v5, 0x22u, 119, 122, ".\\crypto\\x509v3\\v3_akey.c", 177);
    }
err_98:
    X509_NAME_free(a);
    ASN1_STRING_free(i);
    ASN1_STRING_free(v20);
    return 0;
  }
  ERR_put_error(v5, 0x22u, 119, 123, ".\\crypto\\x509v3\\v3_akey.c", 166);
  return 0;
}

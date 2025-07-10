PROXY_CERT_INFO_EXTENSION_st *__cdecl r2i_pci(v3_ext_method *method, v3_ext_ctx *ctx, char *value)
{
  int v3; // edi
  stack_st_CONF_VALUE *v4; // ebp
  char *v5; // ebx
  _BYTE *v6; // eax
  int v7; // esi
  stack_st_CONF_VALUE *section; // edi
  int v9; // ebp
  char *v10; // eax
  asn1_object_st *v11; // esi
  int v12; // eax
  asn1_string_st *v13; // edi
  PROXY_CERT_INFO_EXTENSION_st *v14; // eax
  asn1_string_st *pathlen; // [esp+10h] [ebp-18h] BYREF
  asn1_object_st *language; // [esp+14h] [ebp-14h] BYREF
  asn1_string_st *policy; // [esp+18h] [ebp-10h] BYREF
  int v19; // [esp+1Ch] [ebp-Ch]
  stack_st *st; // [esp+20h] [ebp-8h]
  PROXY_CERT_INFO_EXTENSION_st *v21; // [esp+24h] [ebp-4h]

  v3 = 0;
  v21 = 0;
  language = 0;
  pathlen = 0;
  policy = 0;
  v4 = X509V3_parse_list(value);
  st = &v4->stack;
  v19 = 0;
  if ( sk_num(&v4->stack) <= 0 )
  {
LABEL_15:
    ERR_put_error(0x22u, 155, 154, ".\\crypto\\x509v3\\v3_pci.c", 299);
    goto LABEL_28;
  }
  do
  {
    v5 = sk_value(&v4->stack, v3);
    v6 = (_BYTE *)*((_DWORD *)v5 + 1);
    if ( !v6 )
    {
LABEL_18:
      ERR_put_error(0x22u, 155, 153, ".\\crypto\\x509v3\\v3_pci.c", 259);
      goto LABEL_19;
    }
    if ( *v6 == 64 )
      goto LABEL_6;
    if ( !*((_DWORD *)v5 + 2) )
      goto LABEL_18;
    if ( *v6 == 64 )
    {
LABEL_6:
      v7 = 1;
      section = X509V3_get_section(ctx);
      if ( section )
      {
        v9 = 0;
        do
        {
          if ( v9 >= sk_num(&section->stack) )
            break;
          v10 = sk_value(&section->stack, v9);
          v7 = process_pci_value((CONF_VALUE *)v10, &language, &policy, &pathlen);
          ++v9;
        }
        while ( v7 );
        X509V3_section_free(ctx, section);
        v4 = (stack_st_CONF_VALUE *)st;
        if ( !v7 )
          goto err_89;
        v3 = v19;
        goto LABEL_13;
      }
      ERR_put_error(0x22u, 155, 135, ".\\crypto\\x509v3\\v3_pci.c", 271);
LABEL_19:
      ERR_add_error_data(6, "section:", *(_DWORD *)v5, ",name:", *((_DWORD *)v5 + 1), ",value:", *((_DWORD *)v5 + 2));
      goto err_89;
    }
    if ( !process_pci_value((CONF_VALUE *)v5, &language, &policy, &pathlen) )
    {
      ERR_add_error_data(6, "section:", *(_DWORD *)v5, ",name:", *((_DWORD *)v5 + 1), ",value:", *((_DWORD *)v5 + 2));
      goto err_89;
    }
LABEL_13:
    v19 = ++v3;
  }
  while ( v3 < sk_num(&v4->stack) );
  v11 = language;
  if ( !language )
    goto LABEL_15;
  v12 = OBJ_obj2nid(language);
  v13 = policy;
  if ( (v12 == 667 || v12 == 665) && policy )
  {
    ERR_put_error(0x22u, 155, 159, ".\\crypto\\x509v3\\v3_pci.c", 305);
  }
  else
  {
    v14 = PROXY_CERT_INFO_EXTENSION_new();
    v21 = v14;
    if ( v14 )
    {
      v14->proxyPolicy->policyLanguage = v11;
      v14->proxyPolicy->policy = v13;
      v14->pcPathLengthConstraint = pathlen;
      pathlen = 0;
      goto end_4;
    }
    ERR_put_error(0x22u, 155, 65, ".\\crypto\\x509v3\\v3_pci.c", 312);
  }
err_89:
  if ( language )
    ASN1_OBJECT_free(language);
LABEL_28:
  if ( pathlen )
  {
    ASN1_INTEGER_free(pathlen);
    pathlen = 0;
  }
  if ( policy )
    ASN1_OCTET_STRING_free(policy);
end_4:
  sk_pop_free(&v4->stack, (void (__cdecl *)(void *))X509V3_conf_free);
  return v21;
}

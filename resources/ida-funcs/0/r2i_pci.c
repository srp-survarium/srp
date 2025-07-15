PROXY_CERT_INFO_EXTENSION_st *__usercall r2i_pci@<eax>(
        CONF_VALUE *a1@<ebx>,
        v3_ext_method *method,
        v3_ext_ctx *ctx,
        char *value)
{
  int v4; // edi
  stack_st_CONF_VALUE *v5; // ebp
  char *name; // eax
  int v7; // esi
  stack_st_CONF_VALUE *section; // edi
  int v9; // ebp
  asn1_object_st *v10; // esi
  void *v11; // eax
  asn1_string_st *v12; // edi
  PROXY_CERT_INFO_EXTENSION_st *v13; // eax
  asn1_string_st *pathlen; // [esp+10h] [ebp-18h] BYREF
  asn1_object_st *language; // [esp+14h] [ebp-14h] BYREF
  asn1_string_st *policy; // [esp+18h] [ebp-10h] BYREF
  int v18; // [esp+1Ch] [ebp-Ch]
  stack_st *st; // [esp+20h] [ebp-8h]
  PROXY_CERT_INFO_EXTENSION_st *v20; // [esp+24h] [ebp-4h]

  v4 = 0;
  v20 = 0;
  language = 0;
  pathlen = 0;
  policy = 0;
  v5 = X509V3_parse_list(value);
  st = &v5->stack;
  v18 = 0;
  if ( sk_num(&v5->stack) <= 0 )
  {
LABEL_15:
    ERR_put_error((int)a1, 0x22u, 155, 154, ".\\crypto\\x509v3\\v3_pci.c", 299);
    goto LABEL_28;
  }
  do
  {
    a1 = (CONF_VALUE *)sk_value(&v5->stack, v4);
    name = a1->name;
    if ( !name )
    {
LABEL_18:
      ERR_put_error((int)a1, 0x22u, 155, 153, ".\\crypto\\x509v3\\v3_pci.c", 259);
      goto LABEL_19;
    }
    if ( *name == 64 )
      goto LABEL_6;
    if ( !a1->value )
      goto LABEL_18;
    if ( *name == 64 )
    {
LABEL_6:
      v7 = 1;
      section = X509V3_get_section((int)a1, ctx);
      if ( section )
      {
        v9 = 0;
        do
        {
          if ( v9 >= sk_num(&section->stack) )
            break;
          a1 = (CONF_VALUE *)sk_value(&section->stack, v9);
          v7 = process_pci_value(a1, &language, &policy, &pathlen);
          ++v9;
        }
        while ( v7 );
        X509V3_section_free(ctx, section);
        v5 = (stack_st_CONF_VALUE *)st;
        if ( !v7 )
          goto err_91;
        v4 = v18;
        goto LABEL_13;
      }
      ERR_put_error((int)a1, 0x22u, 155, 135, ".\\crypto\\x509v3\\v3_pci.c", 271);
LABEL_19:
      ERR_add_error_data(6, "section:", a1->section, ",name:", a1->name, ",value:", a1->value);
      goto err_91;
    }
    if ( !process_pci_value(a1, &language, &policy, &pathlen) )
    {
      ERR_add_error_data(6, "section:", a1->section, ",name:", a1->name, ",value:", a1->value);
      goto err_91;
    }
LABEL_13:
    v18 = ++v4;
  }
  while ( v4 < sk_num(&v5->stack) );
  v10 = language;
  if ( !language )
    goto LABEL_15;
  v11 = OBJ_obj2nid(language);
  v12 = policy;
  if ( (v11 == (void *)667 || v11 == (void *)665) && policy )
  {
    ERR_put_error((int)a1, 0x22u, 155, 159, ".\\crypto\\x509v3\\v3_pci.c", 305);
  }
  else
  {
    v13 = PROXY_CERT_INFO_EXTENSION_new();
    v20 = v13;
    if ( v13 )
    {
      v13->proxyPolicy->policyLanguage = v10;
      v13->proxyPolicy->policy = v12;
      v13->pcPathLengthConstraint = pathlen;
      pathlen = 0;
      goto end_4;
    }
    ERR_put_error((int)a1, 0x22u, 155, 65, ".\\crypto\\x509v3\\v3_pci.c", 312);
  }
err_91:
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
  sk_pop_free(&v5->stack, (void (__cdecl *)(void *))X509V3_conf_free);
  return v20;
}

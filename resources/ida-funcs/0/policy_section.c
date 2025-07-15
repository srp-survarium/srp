POLICYINFO_st *__cdecl policy_section(v3_ext_ctx *ctx, stack_st_CONF_VALUE *polstrs, stack_st_CONF_VALUE *ia5org)
{
  struct ASN1_VALUE_st *v3; // ebx
  int v4; // ebp
  char *v5; // edi
  asn1_object_st *v6; // eax
  struct ASN1_VALUE_st *v7; // esi
  asn1_string_st *v8; // eax
  int v9; // eax
  stack_st_CONF_VALUE *section; // esi
  char *v11; // edi

  v3 = ASN1_item_new(&local_it_76);
  if ( !v3 )
  {
merr_3:
    ERR_put_error((int)v3, 0x22u, 131, 65, ".\\crypto\\x509v3\\v3_cpols.c", 263);
    goto err_101;
  }
  v4 = 0;
  if ( sk_num(&polstrs->stack) <= 0 )
  {
LABEL_21:
    if ( !*(_DWORD *)v3 )
    {
      ERR_put_error((int)v3, 0x22u, 131, 139, ".\\crypto\\x509v3\\v3_cpols.c", 256);
      goto err_101;
    }
    return (POLICYINFO_st *)v3;
  }
  while ( 1 )
  {
    v5 = sk_value(&polstrs->stack, v4);
    if ( strcmp(*((const char **)v5 + 1), "policyIdentifier") )
      break;
    v6 = OBJ_txt2obj((int)v3, *((char **)v5 + 2), 0);
    if ( !v6 )
    {
      ERR_put_error((int)v3, 0x22u, 131, 110, ".\\crypto\\x509v3\\v3_cpols.c", 211);
      goto LABEL_25;
    }
    *(_DWORD *)v3 = v6;
LABEL_20:
    if ( ++v4 >= sk_num(&polstrs->stack) )
      goto LABEL_21;
  }
  if ( !name_cmp(*((char **)v5 + 1), "CPS") )
  {
    if ( !*((_DWORD *)v3 + 1) )
      *((_DWORD *)v3 + 1) = sk_new_null();
    v7 = ASN1_item_new(&local_it_77);
    if ( !v7 || !sk_push(*((stack_st **)v3 + 1), (char *)v7) )
      goto merr_3;
    *(_DWORD *)v7 = OBJ_nid2obj((int)v3, 0xA4u);
    v8 = ASN1_STRING_type_new((int)v3, 22);
    *((_DWORD *)v7 + 1) = v8;
    v9 = ASN1_STRING_set(v8, *((const __m128i **)v5 + 2), strlen(*((const char **)v5 + 2)));
LABEL_19:
    if ( !v9 )
      goto merr_3;
    goto LABEL_20;
  }
  if ( !name_cmp(*((char **)v5 + 1), "userNotice") )
  {
    if ( **((_BYTE **)v5 + 2) != 64 )
    {
      ERR_put_error((int)v3, 0x22u, 131, 137, ".\\crypto\\x509v3\\v3_cpols.c", 230);
      goto LABEL_25;
    }
    section = X509V3_get_section((int)v3, ctx);
    if ( !section )
    {
      ERR_put_error((int)v3, 0x22u, 131, 135, ".\\crypto\\x509v3\\v3_cpols.c", 236);
      goto LABEL_25;
    }
    v11 = (char *)notice_section((stack_st_ASN1_INTEGER *)v3, &section->stack, ia5org);
    X509V3_section_free(ctx, section);
    if ( !v11 )
      goto err_101;
    if ( !*((_DWORD *)v3 + 1) )
      *((_DWORD *)v3 + 1) = sk_new_null();
    v9 = sk_push(*((stack_st **)v3 + 1), v11);
    goto LABEL_19;
  }
  ERR_put_error((int)v3, 0x22u, 131, 138, ".\\crypto\\x509v3\\v3_cpols.c", 249);
LABEL_25:
  ERR_add_error_data(6, "section:", *(_DWORD *)v5, ",name:", *((_DWORD *)v5 + 1), ",value:", *((_DWORD *)v5 + 2));
err_101:
  ASN1_item_free(v3, &local_it_76);
  return 0;
}

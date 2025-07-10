POLICYQUALINFO_st *__cdecl notice_section(stack_st *ctx, stack_st_CONF_VALUE *unot)
{
  struct ASN1_VALUE_st *v2; // esi
  struct ASN1_VALUE_st *v3; // ebp
  char *v4; // ebx
  asn1_string_st *v5; // eax
  char *v6; // esi
  char *v7; // edi
  unsigned int v8; // ecx
  struct ASN1_VALUE_st *v9; // eax
  struct ASN1_VALUE_st *v10; // esi
  struct ASN1_VALUE_st *v11; // eax
  stack_st_CONF_VALUE *v12; // eax
  stack_st_CONF_VALUE *v13; // edi
  int v14; // esi
  struct ASN1_VALUE_st *v15; // eax
  int i; // [esp+10h] [ebp-8h]
  struct ASN1_VALUE_st *val; // [esp+14h] [ebp-4h]

  v2 = ASN1_item_new(&local_it_77);
  val = v2;
  if ( !v2 || (*(_DWORD *)v2 = OBJ_nid2obj(0xA5u), (v3 = ASN1_item_new(&local_it_78)) == 0) )
  {
merr_2:
    ERR_put_error(0x22u, 132, 65, ".\\crypto\\x509v3\\v3_cpols.c", 332);
    goto err_98;
  }
  *((_DWORD *)v2 + 1) = v3;
  i = 0;
  if ( sk_num(ctx) > 0 )
  {
    while ( 1 )
    {
      v4 = sk_value(ctx, i);
      if ( !strcmp(*((const char **)v4 + 1), "explicitText") )
        break;
      if ( !strcmp(*((const char **)v4 + 1), "organization") )
      {
        v9 = *(struct ASN1_VALUE_st **)v3;
        if ( !*(_DWORD *)v3 )
        {
          v9 = ASN1_item_new(&local_it_79);
          if ( !v9 )
            goto merr_2;
          *(_DWORD *)v3 = v9;
        }
        if ( unot )
          *(_DWORD *)(*(_DWORD *)v9 + 4) = 22;
        else
          *(_DWORD *)(*(_DWORD *)v9 + 4) = 26;
        v6 = (char *)*((_DWORD *)v4 + 2);
        v7 = v6 + 1;
        v8 = (unsigned int)&v6[strlen(v6) + 1];
        v5 = *(asn1_string_st **)v9;
LABEL_14:
        if ( !ASN1_STRING_set(v5, v6, v8 - (_DWORD)v7) )
          goto merr_2;
        goto LABEL_23;
      }
      if ( strcmp(*((const char **)v4 + 1), "noticeNumbers") )
      {
        ERR_put_error(0x22u, 132, 138, ".\\crypto\\x509v3\\v3_cpols.c", 317);
LABEL_30:
        ERR_add_error_data(6, "section:", *(_DWORD *)v4, ",name:", *((_DWORD *)v4 + 1), ",value:", *((_DWORD *)v4 + 2));
err_98:
        ASN1_item_free(val, &local_it_77);
        return 0;
      }
      v10 = *(struct ASN1_VALUE_st **)v3;
      if ( !*(_DWORD *)v3 )
      {
        v11 = ASN1_item_new(&local_it_79);
        v10 = v11;
        if ( !v11 )
          goto merr_2;
        *(_DWORD *)v3 = v11;
      }
      v12 = X509V3_parse_list(*((char **)v4 + 2));
      v13 = v12;
      if ( !v12 || !sk_num(&v12->stack) )
      {
        ERR_put_error(0x22u, 132, 141, ".\\crypto\\x509v3\\v3_cpols.c", 308);
        goto LABEL_30;
      }
      v14 = nref_nos(*((stack_st_ASN1_INTEGER **)v10 + 1), v13);
      sk_pop_free(&v13->stack, (void (__cdecl *)(void *))X509V3_conf_free);
      if ( !v14 )
        goto err_98;
LABEL_23:
      if ( ++i >= sk_num(ctx) )
        goto LABEL_24;
    }
    v5 = ASN1_STRING_type_new(26);
    *((_DWORD *)v3 + 1) = v5;
    v6 = (char *)*((_DWORD *)v4 + 2);
    v7 = v6 + 1;
    v8 = (unsigned int)&v6[strlen(v6) + 1];
    goto LABEL_14;
  }
LABEL_24:
  v15 = *(struct ASN1_VALUE_st **)v3;
  if ( *(_DWORD *)v3 && (!*((_DWORD *)v15 + 1) || !*(_DWORD *)v15) )
  {
    ERR_put_error(0x22u, 132, 142, ".\\crypto\\x509v3\\v3_cpols.c", 325);
    goto err_98;
  }
  return (POLICYQUALINFO_st *)val;
}

POLICYQUALINFO_st *__usercall notice_section@<eax>(
        stack_st_ASN1_INTEGER *a1@<ebx>,
        stack_st *ctx,
        stack_st_CONF_VALUE *unot)
{
  struct ASN1_VALUE_st *v3; // esi
  struct ASN1_VALUE_st *v4; // ebp
  asn1_string_st *v5; // eax
  const __m128i *sorted; // esi
  char *v7; // edi
  unsigned int v8; // ecx
  struct ASN1_VALUE_st *v9; // eax
  struct ASN1_VALUE_st *v10; // esi
  struct ASN1_VALUE_st *v11; // eax
  stack_st_CONF_VALUE *v12; // eax
  stack_st_CONF_VALUE *v13; // edi
  int v14; // esi
  struct ASN1_VALUE_st *v15; // eax
  int v17; // [esp+10h] [ebp-8h]
  struct ASN1_VALUE_st *val; // [esp+14h] [ebp-4h]

  v3 = ASN1_item_new(&local_it_77);
  val = v3;
  if ( !v3 || (*(_DWORD *)v3 = OBJ_nid2obj((int)a1, 0xA5u), (v4 = ASN1_item_new(&local_it_78)) == 0) )
  {
merr_2:
    ERR_put_error((int)a1, 0x22u, 132, 65, ".\\crypto\\x509v3\\v3_cpols.c", 332);
    goto err_100;
  }
  *((_DWORD *)v3 + 1) = v4;
  v17 = 0;
  if ( sk_num(ctx) > 0 )
  {
    while ( 1 )
    {
      a1 = (stack_st_ASN1_INTEGER *)sk_value(ctx, v17);
      if ( !strcmp((const char *)a1->stack.data, "explicitText") )
        break;
      if ( !strcmp((const char *)a1->stack.data, "organization") )
      {
        v9 = *(struct ASN1_VALUE_st **)v4;
        if ( !*(_DWORD *)v4 )
        {
          v9 = ASN1_item_new(&local_it_79);
          if ( !v9 )
            goto merr_2;
          *(_DWORD *)v4 = v9;
        }
        if ( unot )
          *(_DWORD *)(*(_DWORD *)v9 + 4) = 22;
        else
          *(_DWORD *)(*(_DWORD *)v9 + 4) = 26;
        sorted = (const __m128i *)a1->stack.sorted;
        v7 = &sorted->m128i_i8[1];
        v8 = (unsigned int)sorted->m128i_u32 + strlen(sorted->m128i_i8) + 1;
        v5 = *(asn1_string_st **)v9;
LABEL_14:
        if ( !ASN1_STRING_set(v5, sorted, v8 - (_DWORD)v7) )
          goto merr_2;
        goto LABEL_23;
      }
      if ( strcmp((const char *)a1->stack.data, "noticeNumbers") )
      {
        ERR_put_error((int)a1, 0x22u, 132, 138, ".\\crypto\\x509v3\\v3_cpols.c", 317);
LABEL_30:
        ERR_add_error_data(6, "section:", a1->stack.num, ",name:", a1->stack.data, ",value:", a1->stack.sorted);
err_100:
        ASN1_item_free(val, &local_it_77);
        return 0;
      }
      v10 = *(struct ASN1_VALUE_st **)v4;
      if ( !*(_DWORD *)v4 )
      {
        v11 = ASN1_item_new(&local_it_79);
        v10 = v11;
        if ( !v11 )
          goto merr_2;
        *(_DWORD *)v4 = v11;
      }
      v12 = X509V3_parse_list((char *)a1->stack.sorted);
      v13 = v12;
      if ( !v12 || !sk_num(&v12->stack) )
      {
        ERR_put_error((int)a1, 0x22u, 132, 141, ".\\crypto\\x509v3\\v3_cpols.c", 308);
        goto LABEL_30;
      }
      a1 = (stack_st_ASN1_INTEGER *)*((_DWORD *)v10 + 1);
      v14 = nref_nos(a1, v13);
      sk_pop_free(&v13->stack, (void (__cdecl *)(void *))X509V3_conf_free);
      if ( !v14 )
        goto err_100;
LABEL_23:
      if ( ++v17 >= sk_num(ctx) )
        goto LABEL_24;
    }
    v5 = ASN1_STRING_type_new((int)a1, 26);
    *((_DWORD *)v4 + 1) = v5;
    sorted = (const __m128i *)a1->stack.sorted;
    v7 = &sorted->m128i_i8[1];
    v8 = (unsigned int)sorted->m128i_u32 + strlen(sorted->m128i_i8) + 1;
    goto LABEL_14;
  }
LABEL_24:
  v15 = *(struct ASN1_VALUE_st **)v4;
  if ( *(_DWORD *)v4 && (!*((_DWORD *)v15 + 1) || !*(_DWORD *)v15) )
  {
    ERR_put_error((int)a1, 0x22u, 132, 142, ".\\crypto\\x509v3\\v3_cpols.c", 325);
    goto err_100;
  }
  return (POLICYQUALINFO_st *)val;
}

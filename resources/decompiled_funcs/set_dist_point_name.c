int __cdecl set_dist_point_name(DIST_POINT_NAME_st **pdp, v3_ext_ctx *ctx)
{
  CONF_VALUE *cnf; // ecx
  CONF_VALUE *v3; // edi
  stack_st_GENERAL_NAME *entries; // ebp
  stack_st_GENERAL_NAME *v5; // edi
  X509_name_st *v6; // esi
  stack_st_CONF_VALUE *section; // eax
  stack_st_CONF_VALUE *v8; // edi
  int v10; // ebx
  int v11; // eax
  DIST_POINT_NAME_st *v12; // eax

  v3 = cnf;
  entries = 0;
  if ( !strncmp(cnf->name, "fullname", 9u) )
  {
    v5 = gnames_from_sectname(ctx, v3->value);
    if ( !v5 )
      return -1;
    goto LABEL_14;
  }
  if ( strcmp(v3->name, "relativename") )
    return 0;
  v6 = X509_NAME_new();
  if ( !v6 )
    return -1;
  section = X509V3_get_section(ctx, v3->value);
  v8 = section;
  if ( !section )
  {
    ERR_put_error(0x22u, 158, 150, ".\\crypto\\x509v3\\v3_crld.c", 138);
    return -1;
  }
  v10 = X509V3_NAME_from_section(v6, section, 0x1001u);
  X509V3_section_free(ctx, v8);
  entries = (stack_st_GENERAL_NAME *)v6->entries;
  v6->entries = 0;
  X509_NAME_free(v6);
  if ( !v10 || sk_num(&entries->stack) <= 0 )
  {
LABEL_18:
    if ( entries )
      sk_pop_free(&entries->stack, (void (__cdecl *)(void *))X509_NAME_ENTRY_free);
    return -1;
  }
  v11 = sk_num(&entries->stack);
  if ( *((_DWORD *)sk_value(&entries->stack, v11 - 1) + 2) )
  {
    ERR_put_error(0x22u, 158, 161, ".\\crypto\\x509v3\\v3_crld.c", 155);
    goto LABEL_18;
  }
  v5 = 0;
LABEL_14:
  if ( *pdp )
  {
    ERR_put_error(0x22u, 158, 160, ".\\crypto\\x509v3\\v3_crld.c", 165);
    goto err_29;
  }
  v12 = (DIST_POINT_NAME_st *)ASN1_item_new(&local_it_11);
  *pdp = v12;
  if ( !v12 )
  {
err_29:
    if ( v5 )
      sk_pop_free(&v5->stack, (void (__cdecl *)(void *))GENERAL_NAME_free);
    goto LABEL_18;
  }
  if ( v5 )
  {
    v12->type = 0;
    (*pdp)->name.fullname = v5;
  }
  else
  {
    v12->type = 1;
    (*pdp)->name.fullname = entries;
  }
  return 1;
}

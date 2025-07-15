int __usercall set_dist_point_name@<eax>(int a1@<ecx>, int a2@<ebx>, DIST_POINT_NAME_st **pdp, v3_ext_ctx *ctx)
{
  stack_st_GENERAL_NAME *entries; // ebp
  v3_ext_ctx *v6; // ebx
  stack_st_GENERAL_NAME *v7; // edi
  X509_name_st *v8; // esi
  stack_st_CONF_VALUE *section; // eax
  stack_st_CONF_VALUE *v10; // edi
  int v12; // eax
  DIST_POINT_NAME_st *v13; // eax

  entries = 0;
  if ( !strncmp(*(const char **)(a1 + 4), "fullname", 9u) )
  {
    v6 = ctx;
    v7 = gnames_from_sectname(ctx, *(char **)(a1 + 8));
    if ( !v7 )
      return -1;
    goto LABEL_14;
  }
  if ( strcmp(*(const char **)(a1 + 4), "relativename") )
    return 0;
  v8 = X509_NAME_new();
  if ( !v8 )
    return -1;
  section = X509V3_get_section(ctx);
  v10 = section;
  if ( !section )
  {
    ERR_put_error(a2, 0x22u, 158, 150, ".\\crypto\\x509v3\\v3_crld.c", 138);
    return -1;
  }
  v6 = (v3_ext_ctx *)X509V3_NAME_from_section(v8, section, 4097);
  X509V3_section_free(ctx, v10);
  entries = (stack_st_GENERAL_NAME *)v8->entries;
  v8->entries = 0;
  X509_NAME_free(v8);
  if ( !v6 || sk_num(&entries->stack) <= 0 )
  {
LABEL_18:
    if ( entries )
      sk_pop_free(&entries->stack, (void (__cdecl *)(void *))X509_NAME_ENTRY_free);
    return -1;
  }
  v12 = sk_num(&entries->stack);
  if ( *((_DWORD *)sk_value(&entries->stack, v12 - 1) + 2) )
  {
    ERR_put_error((int)v6, 0x22u, 158, 161, ".\\crypto\\x509v3\\v3_crld.c", 155);
    goto LABEL_18;
  }
  v7 = 0;
LABEL_14:
  if ( *pdp )
  {
    ERR_put_error((int)v6, 0x22u, 158, 160, ".\\crypto\\x509v3\\v3_crld.c", 165);
    goto err_31;
  }
  v13 = (DIST_POINT_NAME_st *)ASN1_item_new(&local_it_11);
  *pdp = v13;
  if ( !v13 )
  {
err_31:
    if ( v7 )
      sk_pop_free(&v7->stack, (void (__cdecl *)(void *))GENERAL_NAME_free);
    goto LABEL_18;
  }
  if ( v7 )
  {
    v13->type = 0;
    (*pdp)->name.fullname = v7;
  }
  else
  {
    v13->type = 1;
    (*pdp)->name.fullname = entries;
  }
  return 1;
}

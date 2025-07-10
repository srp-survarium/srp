DIST_POINT_st *__cdecl crldp_from_section(v3_ext_ctx *ctx, stack_st_CONF_VALUE *nval)
{
  struct ASN1_VALUE_st *v2; // ebp
  stack_st_CONF_VALUE *v3; // esi
  int v4; // ebx
  char *v5; // edi
  int v6; // eax
  stack_st_GENERAL_NAME *v8; // eax
  int i; // [esp+10h] [ebp-4h]

  v2 = ASN1_item_new(&local_it_12);
  if ( !v2 )
    return 0;
  v3 = nval;
  v4 = 0;
  for ( i = 0; v4 < sk_num(&nval->stack); i = ++v4 )
  {
    v5 = sk_value(&v3->stack, v4);
    v6 = set_dist_point_name((DIST_POINT_NAME_st **)v2, ctx);
    if ( v6 <= 0 )
    {
      if ( v6 < 0 )
        goto err_30;
      if ( !strcmp(*((const char **)v5 + 1), "reasons") )
      {
        if ( !set_reasons((asn1_string_st **)v2 + 1, *((char **)v5 + 2)) )
          goto err_30;
      }
      else if ( !strcmp(*((const char **)v5 + 1), "CRLissuer") )
      {
        v8 = gnames_from_sectname(ctx, *((char **)v5 + 2));
        *((_DWORD *)v2 + 2) = v8;
        if ( !v8 )
        {
err_30:
          ASN1_item_free(v2, &local_it_12);
          return 0;
        }
        v4 = i;
      }
    }
    v3 = nval;
  }
  return (DIST_POINT_st *)v2;
}

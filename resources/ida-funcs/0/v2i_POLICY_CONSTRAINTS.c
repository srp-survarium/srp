asn1_string_st **__usercall v2i_POLICY_CONSTRAINTS@<eax>(
        int a1@<ebx>,
        const v3_ext_method *method,
        v3_ext_ctx *ctx,
        stack_st_CONF_VALUE *values)
{
  asn1_string_st **v4; // esi
  int i; // ebx
  CONF_VALUE *v7; // edi
  int value_int; // eax

  v4 = (asn1_string_st **)ASN1_item_new(&local_it_69);
  if ( !v4 )
  {
    ERR_put_error(a1, 0x22u, 146, 65, ".\\crypto\\x509v3\\v3_pcons.c", 113);
    return 0;
  }
  for ( i = 0; i < sk_num(&values->stack); ++i )
  {
    v7 = (CONF_VALUE *)sk_value(&values->stack, i);
    if ( !strcmp(v7->name, "requireExplicitPolicy") )
    {
      value_int = X509V3_get_value_int(i, v7, v4);
    }
    else
    {
      if ( strcmp(v7->name, "inhibitPolicyMapping") )
      {
        ERR_put_error(i, 0x22u, 146, 106, ".\\crypto\\x509v3\\v3_pcons.c", 125);
        ERR_add_error_data(6, "section:", v7->section, ",name:", v7->name, ",value:", v7->value);
err_95:
        ASN1_item_free((struct ASN1_VALUE_st *)v4, &local_it_69);
        return 0;
      }
      value_int = X509V3_get_value_int(i, v7, v4 + 1);
    }
    if ( !value_int )
      goto err_95;
  }
  if ( !v4[1] && !*v4 )
  {
    ERR_put_error(i, 0x22u, 146, 151, ".\\crypto\\x509v3\\v3_pcons.c", 131);
    goto err_95;
  }
  return v4;
}

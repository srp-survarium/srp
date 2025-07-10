asn1_string_st **__cdecl v2i_POLICY_CONSTRAINTS(
        const v3_ext_method *method,
        v3_ext_ctx *ctx,
        stack_st_CONF_VALUE *values)
{
  asn1_string_st **v3; // esi
  int i; // ebx
  CONF_VALUE *v6; // edi
  int value_int; // eax

  v3 = (asn1_string_st **)ASN1_item_new(&local_it_69);
  if ( !v3 )
  {
    ERR_put_error(0x22u, 146, 65, ".\\crypto\\x509v3\\v3_pcons.c", 113);
    return 0;
  }
  for ( i = 0; i < sk_num(&values->stack); ++i )
  {
    v6 = (CONF_VALUE *)sk_value(&values->stack, i);
    if ( !strcmp(v6->name, "requireExplicitPolicy") )
    {
      value_int = X509V3_get_value_int(v6, v3);
    }
    else
    {
      if ( strcmp(v6->name, "inhibitPolicyMapping") )
      {
        ERR_put_error(0x22u, 146, 106, ".\\crypto\\x509v3\\v3_pcons.c", 125);
        ERR_add_error_data(6, "section:", v6->section, ",name:", v6->name, ",value:", v6->value);
err_93:
        ASN1_item_free((struct ASN1_VALUE_st *)v3, &local_it_69);
        return 0;
      }
      value_int = X509V3_get_value_int(v6, v3 + 1);
    }
    if ( !value_int )
      goto err_93;
  }
  if ( !v3[1] && !*v3 )
  {
    ERR_put_error(0x22u, 146, 151, ".\\crypto\\x509v3\\v3_pcons.c", 131);
    goto err_93;
  }
  return v3;
}

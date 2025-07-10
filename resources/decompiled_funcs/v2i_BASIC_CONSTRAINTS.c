BASIC_CONSTRAINTS_st *__cdecl v2i_BASIC_CONSTRAINTS(
        v3_ext_method *method,
        v3_ext_ctx *ctx,
        stack_st_CONF_VALUE *values)
{
  struct ASN1_VALUE_st *v3; // esi
  int v5; // ebx
  CONF_VALUE *v6; // edi
  int value_bool; // eax

  v3 = ASN1_item_new(&local_it_34);
  if ( !v3 )
  {
    ERR_put_error(0x22u, 102, 65, ".\\crypto\\x509v3\\v3_bcons.c", 104);
    return 0;
  }
  v5 = 0;
  if ( sk_num(&values->stack) <= 0 )
    return (BASIC_CONSTRAINTS_st *)v3;
  while ( 1 )
  {
    v6 = (CONF_VALUE *)sk_value(&values->stack, v5);
    if ( !strcmp(v6->name, "CA") )
    {
      value_bool = X509V3_get_value_bool(v6, (int *)v3);
      goto LABEL_8;
    }
    if ( strcmp(v6->name, "pathlen") )
      break;
    value_bool = X509V3_get_value_int(v6, (asn1_string_st **)v3 + 1);
LABEL_8:
    if ( !value_bool )
      goto err_33;
    if ( ++v5 >= sk_num(&values->stack) )
      return (BASIC_CONSTRAINTS_st *)v3;
  }
  ERR_put_error(0x22u, 102, 106, ".\\crypto\\x509v3\\v3_bcons.c", 114);
  ERR_add_error_data(6, "section:", v6->section, ",name:", v6->name, ",value:", v6->value);
err_33:
  ASN1_item_free(v3, &local_it_34);
  return 0;
}

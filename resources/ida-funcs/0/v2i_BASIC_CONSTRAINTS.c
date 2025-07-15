BASIC_CONSTRAINTS_st *__usercall v2i_BASIC_CONSTRAINTS@<eax>(
        int a1@<ebx>,
        v3_ext_method *method,
        v3_ext_ctx *ctx,
        stack_st_CONF_VALUE *values)
{
  struct ASN1_VALUE_st *v4; // esi
  int v6; // ebx
  CONF_VALUE *v7; // edi
  int value_bool; // eax

  v4 = ASN1_item_new(&local_it_34);
  if ( !v4 )
  {
    ERR_put_error(a1, 0x22u, 102, 65, ".\\crypto\\x509v3\\v3_bcons.c", 104);
    return 0;
  }
  v6 = 0;
  if ( sk_num(&values->stack) <= 0 )
    return (BASIC_CONSTRAINTS_st *)v4;
  while ( 1 )
  {
    v7 = (CONF_VALUE *)sk_value(&values->stack, v6);
    if ( !strcmp(v7->name, "CA") )
    {
      value_bool = X509V3_get_value_bool(v7, (int *)v4);
      goto LABEL_8;
    }
    if ( strcmp(v7->name, "pathlen") )
      break;
    value_bool = X509V3_get_value_int(v7, (asn1_string_st **)v4 + 1);
LABEL_8:
    if ( !value_bool )
      goto err_35;
    if ( ++v6 >= sk_num(&values->stack) )
      return (BASIC_CONSTRAINTS_st *)v4;
  }
  ERR_put_error(v6, 0x22u, 102, 106, ".\\crypto\\x509v3\\v3_bcons.c", 114);
  ERR_add_error_data(6, "section:", v7->section, ",name:", v7->name, ",value:", v7->value);
err_35:
  ASN1_item_free(v4, &local_it_34);
  return 0;
}

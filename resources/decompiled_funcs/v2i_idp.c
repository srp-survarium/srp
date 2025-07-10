struct ASN1_VALUE_st *__cdecl v2i_idp(const v3_ext_method *method, v3_ext_ctx *ctx, stack_st_CONF_VALUE *nval)
{
  struct ASN1_VALUE_st *v3; // ebx
  CONF_VALUE *v4; // edi
  const char *name; // esi
  char *value; // ebp
  int v7; // eax
  int value_bool; // eax
  int i; // [esp+10h] [ebp-4h]

  v3 = ASN1_item_new(&local_it_14);
  if ( !v3 )
  {
    ERR_put_error(0x22u, 157, 65, ".\\crypto\\x509v3\\v3_crld.c", 501);
    goto err_32;
  }
  i = 0;
  if ( sk_num(&nval->stack) <= 0 )
    return v3;
  while ( 1 )
  {
    v4 = (CONF_VALUE *)sk_value(&nval->stack, i);
    name = v4->name;
    value = v4->value;
    v7 = set_dist_point_name((DIST_POINT_NAME_st **)v3, ctx);
    if ( v7 <= 0 )
      break;
LABEL_17:
    if ( ++i >= sk_num(&nval->stack) )
      return v3;
  }
  if ( v7 < 0 )
    goto err_32;
  if ( !strcmp(name, "onlyuser") )
  {
    value_bool = X509V3_get_value_bool(v4, (int *)v3 + 1);
    goto LABEL_16;
  }
  if ( !strcmp(name, "onlyCA") )
  {
    value_bool = X509V3_get_value_bool(v4, (int *)v3 + 2);
    goto LABEL_16;
  }
  if ( !strcmp(name, "onlyAA") )
  {
    value_bool = X509V3_get_value_bool(v4, (int *)v3 + 5);
    goto LABEL_16;
  }
  if ( !strcmp(name, "indirectCRL") )
  {
    value_bool = X509V3_get_value_bool(v4, (int *)v3 + 4);
    goto LABEL_16;
  }
  if ( !strcmp(name, "onlysomereasons") )
  {
    value_bool = set_reasons((asn1_string_st **)v3 + 3, value);
LABEL_16:
    if ( !value_bool )
      goto err_32;
    goto LABEL_17;
  }
  ERR_put_error(0x22u, 157, 106, ".\\crypto\\x509v3\\v3_crld.c", 493);
  ERR_add_error_data(6, "section:", v4->section, ",name:", v4->name, ",value:", v4->value);
err_32:
  ASN1_item_free(v3, &local_it_14);
  return 0;
}

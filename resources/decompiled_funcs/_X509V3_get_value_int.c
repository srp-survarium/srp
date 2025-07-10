int __cdecl X509V3_get_value_int(CONF_VALUE *value, asn1_string_st **aint)
{
  asn1_string_st *v2; // eax

  v2 = s2i_ASN1_INTEGER(0, value->value);
  if ( v2 )
  {
    *aint = v2;
    return 1;
  }
  else
  {
    ERR_add_error_data(6, "section:", value->section, ",name:", value->name, ",value:", value->value);
    return 0;
  }
}

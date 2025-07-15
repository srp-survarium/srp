int __usercall X509V3_get_value_int@<eax>(int a1@<ebx>, CONF_VALUE *value, asn1_string_st **aint)
{
  asn1_string_st *v3; // eax

  v3 = s2i_ASN1_INTEGER(a1, 0, value->value);
  if ( v3 )
  {
    *aint = v3;
    return 1;
  }
  else
  {
    ERR_add_error_data(6, "section:", value->section, ",name:", value->name, ",value:", value->value);
    return 0;
  }
}

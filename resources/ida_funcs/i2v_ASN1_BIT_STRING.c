stack_st_CONF_VALUE *__cdecl i2v_ASN1_BIT_STRING(v3_ext_method *method, asn1_string_st *bits, stack_st_CONF_VALUE *ret)
{
  const char **i; // esi

  for ( i = (const char **)method->usr_data; i[1]; i += 3 )
  {
    if ( ASN1_BIT_STRING_get_bit(bits, (int)*i) )
      X509V3_add_value(i[1], 0, &ret);
  }
  return ret;
}

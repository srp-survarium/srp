stack_st_CONF_VALUE *__usercall i2v_ASN1_BIT_STRING@<eax>(
        stack_st_CONF_VALUE **a1@<ebx>,
        v3_ext_method *method,
        asn1_string_st *bits,
        stack_st_CONF_VALUE *ret)
{
  char **i; // esi

  for ( i = (char **)method->usr_data; i[1]; i += 3 )
  {
    if ( ASN1_BIT_STRING_get_bit(bits, (int)*i) )
      X509V3_add_value(a1, i[1], 0, &ret);
  }
  return ret;
}

int __usercall X509V3_add_value_int@<eax>(
        stack_st_CONF_VALUE **a1@<ebx>,
        char *name,
        asn1_string_st *aint,
        stack_st_CONF_VALUE **extlist)
{
  int result; // eax
  void *v5; // esi
  int v6; // edi

  if ( !aint )
    return 1;
  result = (int)i2s_ASN1_INTEGER((int)a1, 0, aint);
  v5 = (void *)result;
  if ( result )
  {
    v6 = X509V3_add_value(a1, name, (char *)result, extlist);
    CRYPTO_free(v5);
    return v6;
  }
  return result;
}

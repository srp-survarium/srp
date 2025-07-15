int __cdecl X509V3_add_value_int(const char *name, asn1_string_st *aint, stack_st_CONF_VALUE **extlist)
{
  int result; // eax
  void *v4; // esi
  int v5; // edi

  if ( !aint )
    return 1;
  result = (int)i2s_ASN1_INTEGER(0, aint);
  v4 = (void *)result;
  if ( result )
  {
    v5 = X509V3_add_value(name, (const char *)result, extlist);
    CRYPTO_free(v4);
    return v5;
  }
  return result;
}

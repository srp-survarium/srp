int __cdecl i2r_PKEY_USAGE_PERIOD(v3_ext_method *method, PKEY_USAGE_PERIOD_st *usage, bio_st *out, int indent)
{
  BIO_printf(out, "%*s", indent, (const char *)&buf);
  if ( usage->notBefore )
  {
    BIO_write(out, "Not Before: ", 12);
    ASN1_GENERALIZEDTIME_print(out, usage->notBefore);
    if ( !usage->notAfter )
      return 1;
    BIO_write(out, (const char *)&stru_95AF78.m_key_bindings[32], 2);
  }
  if ( usage->notAfter )
  {
    BIO_write(out, "Not After: ", 11);
    ASN1_GENERALIZEDTIME_print(out, usage->notAfter);
  }
  return 1;
}

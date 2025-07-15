int __usercall i2r_PKEY_USAGE_PERIOD@<eax>(
        int a1@<ebx>,
        v3_ext_method *method,
        PKEY_USAGE_PERIOD_st *usage,
        bio_st *out,
        int indent)
{
  BIO_printf(out, "%*s", indent, uri);
  if ( usage->notBefore )
  {
    BIO_write(a1, out, "Not Before: ", 12);
    ASN1_GENERALIZEDTIME_print(out, usage->notBefore);
    if ( !usage->notAfter )
      return 1;
    BIO_write(a1, out, ", ", 2);
  }
  if ( usage->notAfter )
  {
    BIO_write(a1, out, "Not After: ", 11);
    ASN1_GENERALIZEDTIME_print(out, usage->notAfter);
  }
  return 1;
}

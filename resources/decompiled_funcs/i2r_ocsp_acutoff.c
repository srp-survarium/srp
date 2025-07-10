BOOL __cdecl i2r_ocsp_acutoff(const v3_ext_method *method, const asn1_string_st *cutoff, bio_st *bp, int ind)
{
  return (int)BIO_printf(bp, "%*s", ind, (const char *)&buf) > 0 && ASN1_GENERALIZEDTIME_print(bp, cutoff) != 0;
}

BOOL __cdecl i2r_ocsp_acutoff(const v3_ext_method *method, asn1_string_st *cutoff, bio_st *bp, int ind)
{
  return BIO_printf(bp, "%*s", ind, uri) > 0 && ASN1_GENERALIZEDTIME_print(bp, cutoff);
}

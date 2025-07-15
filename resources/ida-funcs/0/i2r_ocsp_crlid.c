BOOL __cdecl i2r_ocsp_crlid(const v3_ext_method *method, void *in, bio_st *bp, int ind)
{
  return (!*(_DWORD *)in
       || BIO_printf(bp, "%*scrlUrl: ", ind, uri) > 0
       && ASN1_STRING_print(bp, *(const asn1_string_st **)in)
       && BIO_write(ind, bp, "\n", 1) > 0)
      && (!*((_DWORD *)in + 1)
       || BIO_printf(bp, "%*scrlNum: ", ind, uri) > 0
       && i2a_ASN1_INTEGER(bp, *((asn1_string_st **)in + 1)) > 0
       && BIO_write(ind, bp, "\n", 1) > 0)
      && (!*((_DWORD *)in + 2)
       || BIO_printf(bp, "%*scrlTime: ", ind, uri) > 0
       && ASN1_GENERALIZEDTIME_print(bp, *((const asn1_string_st **)in + 2))
       && BIO_write(ind, bp, "\n", 1) > 0);
}

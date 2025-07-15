BOOL __cdecl i2r_ocsp_crlid(const v3_ext_method *method, void *in, bio_st *bp, int ind)
{
  return (!*(_DWORD *)in
       || (int)BIO_printf(bp, "%*scrlUrl: ", ind, (const char *)&buf) > 0
       && ASN1_STRING_print(bp, *(const asn1_string_st **)in)
       && BIO_write(bp, "\n", 1) > 0)
      && (!*((_DWORD *)in + 1)
       || (int)BIO_printf(bp, "%*scrlNum: ", ind, (const char *)&buf) > 0
       && i2a_ASN1_INTEGER(bp, *((asn1_string_st **)in + 1)) > 0
       && BIO_write(bp, "\n", 1) > 0)
      && (!*((_DWORD *)in + 2)
       || (int)BIO_printf(bp, "%*scrlTime: ", ind, (const char *)&buf) > 0
       && ASN1_GENERALIZEDTIME_print(bp, *((const asn1_string_st **)in + 2))
       && BIO_write(bp, "\n", 1) > 0);
}

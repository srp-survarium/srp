BOOL __cdecl i2r_ocsp_nonce(const v3_ext_method *method, asn1_string_st *nonce, bio_st *out, int indent)
{
  return BIO_printf(out, "%*s", indent, uri) > 0 && i2a_ASN1_STRING(out, nonce) > 0;
}

// attributes: thunk
void __cdecl ocsp_nonce_free(asn1_string_st *a)
{
  ASN1_STRING_free(a);
}

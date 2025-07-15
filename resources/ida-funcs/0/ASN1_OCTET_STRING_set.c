// attributes: thunk
int __cdecl ASN1_OCTET_STRING_set(asn1_string_st *x, unsigned __int8 *d, int len)
{
  return ASN1_STRING_set(x, d, len);
}

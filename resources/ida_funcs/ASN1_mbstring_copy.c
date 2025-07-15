int __cdecl ASN1_mbstring_copy(asn1_string_st **out, unsigned __int8 *in, int len, int inform, unsigned int mask)
{
  return ASN1_mbstring_ncopy(out, in, len, inform, mask, 0, 0);
}

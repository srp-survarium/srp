int __cdecl X509_REVOKED_cmp(const asn1_string_st ***a, const asn1_string_st ***b)
{
  return ASN1_STRING_cmp(**a, **b);
}

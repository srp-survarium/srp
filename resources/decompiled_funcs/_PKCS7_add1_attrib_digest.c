int __cdecl PKCS7_add1_attrib_digest(pkcs7_signer_info_st *si, char *md, int mdlen)
{
  asn1_string_st *v3; // esi

  v3 = ASN1_OCTET_STRING_new();
  if ( v3 )
  {
    if ( ASN1_STRING_set(v3, md, mdlen) && PKCS7_add_signed_attribute(si, 0x33u, 4, v3) )
      return 1;
    ASN1_OCTET_STRING_free(v3);
  }
  return 0;
}

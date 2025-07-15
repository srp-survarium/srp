int __cdecl old_hmac_decode(evp_pkey_st *pkey, unsigned __int8 **pder, int derlen)
{
  asn1_string_st *v3; // esi

  v3 = ASN1_OCTET_STRING_new();
  if ( !v3 || !ASN1_OCTET_STRING_set(v3, *pder, derlen) )
    return 0;
  EVP_PKEY_assign(pkey, (void *)0x357, (char *)v3);
  return 1;
}

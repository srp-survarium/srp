int __cdecl PKCS7_add0_attrib_signing_time(pkcs7_signer_info_st *si, asn1_string_st *t)
{
  asn1_string_st *v2; // eax

  v2 = t;
  if ( t )
    return PKCS7_add_signed_attribute(si, 0x34u, 23, v2);
  v2 = X509_gmtime_adj(0, 0);
  if ( v2 )
    return PKCS7_add_signed_attribute(si, 0x34u, 23, v2);
  ERR_put_error(0x21u, 135, 65, ".\\crypto\\pkcs7\\pk7_attr.c", 143);
  return 0;
}

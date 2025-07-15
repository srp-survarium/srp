int __usercall PKCS7_add0_attrib_signing_time@<eax>(int a1@<ebx>, pkcs7_signer_info_st *si, asn1_string_st *t)
{
  asn1_string_st *v3; // eax

  v3 = t;
  if ( t )
    return PKCS7_add_signed_attribute(si, (void *)0x34, 23, (int)v3);
  v3 = X509_gmtime_adj(0, 0);
  if ( v3 )
    return PKCS7_add_signed_attribute(si, (void *)0x34, 23, (int)v3);
  ERR_put_error(a1, 0x21u, 135, 65, ".\\crypto\\pkcs7\\pk7_attr.c", 143);
  return 0;
}

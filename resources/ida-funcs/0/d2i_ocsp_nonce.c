asn1_string_st *__cdecl d2i_ocsp_nonce(asn1_string_st **a, unsigned __int8 **pp, int length)
{
  asn1_string_st *v3; // edi

  if ( !a || (v3 = *a) == 0 )
    v3 = ASN1_OCTET_STRING_new();
  if ( ASN1_OCTET_STRING_set(v3, *pp, length) )
  {
    *pp += length;
    if ( a )
      *a = v3;
    return v3;
  }
  else
  {
    if ( v3 && (!a || *a != v3) )
      ASN1_STRING_free(v3);
    ERR_put_error((int)a, 0x27u, 102, 65, ".\\crypto\\x509v3\\v3_ocsp.c", 236);
    return 0;
  }
}

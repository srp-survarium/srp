int __cdecl CMS_stream(unsigned __int8 ***boundary, asn1_string_st *cms)
{
  asn1_string_st **v2; // eax
  asn1_string_st **v3; // esi
  asn1_string_st *v4; // eax

  v2 = CMS_get0_content(cms);
  v3 = v2;
  if ( v2 )
  {
    if ( *v2 || (v4 = ASN1_OCTET_STRING_new(), (*v3 = v4) != 0) )
    {
      (*v3)->flags |= 0x10u;
      (*v3)->flags &= ~0x20u;
      *boundary = &(*v3)->data;
      return 1;
    }
    ERR_put_error(0x2Eu, 155, 65, ".\\crypto\\cms\\cms_io.c", 76);
  }
  return 0;
}

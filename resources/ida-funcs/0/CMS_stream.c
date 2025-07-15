int __usercall CMS_stream@<eax>(int a1@<ebx>, unsigned __int8 ***boundary, asn1_string_st *cms)
{
  asn1_string_st **v3; // eax
  asn1_string_st **v4; // esi
  asn1_string_st *v5; // eax

  v3 = CMS_get0_content(a1, cms);
  v4 = v3;
  if ( v3 )
  {
    if ( *v3 || (v5 = ASN1_OCTET_STRING_new(), (*v4 = v5) != 0) )
    {
      (*v4)->flags |= 0x10u;
      (*v4)->flags &= ~0x20u;
      *boundary = &(*v4)->data;
      return 1;
    }
    ERR_put_error(a1, 0x2Eu, 155, 65, ".\\crypto\\cms\\cms_io.c", 76);
  }
  return 0;
}

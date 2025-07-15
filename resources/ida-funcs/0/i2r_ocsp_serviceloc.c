int __cdecl i2r_ocsp_serviceloc(const v3_ext_method *method, const stack_st **in, bio_st *bp, int ind)
{
  int v4; // edi
  char *v5; // ebx

  if ( (int)BIO_printf(bp, "%*sIssuer: ", ind, (const char *)&buf) > 0
    && X509_NAME_print_ex(bp, (X509_name_st *)*in, 0, (unsigned int)&unk_82031F) > 0 )
  {
    v4 = 0;
    if ( sk_num(in[1]) <= 0 )
      return 1;
    while ( 1 )
    {
      v5 = sk_value(in[1], v4);
      if ( (int)BIO_printf(bp, "\n%*s", 2 * ind, (const char *)&buf) <= 0
        || i2a_ASN1_OBJECT(bp, *(asn1_object_st **)v5) <= 0
        || BIO_puts(bp, " - ") <= 0
        || GENERAL_NAME_print(bp, *((GENERAL_NAME_st **)v5 + 1)) <= 0 )
      {
        break;
      }
      if ( ++v4 >= sk_num(in[1]) )
        return 1;
    }
  }
  return 0;
}

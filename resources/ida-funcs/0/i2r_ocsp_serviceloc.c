int __cdecl i2r_ocsp_serviceloc(const v3_ext_method *method, X509_name_st **in, bio_st *bp, int ind)
{
  int v4; // edi
  char *v5; // ebx

  if ( BIO_printf(bp, "%*sIssuer: ", ind, uri) > 0 && X509_NAME_print_ex(bp, *in, 0, 0x82031Fu) > 0 )
  {
    v4 = 0;
    if ( sk_num((const stack_st *)in[1]) <= 0 )
      return 1;
    while ( 1 )
    {
      v5 = sk_value((const stack_st *)in[1], v4);
      if ( BIO_printf(bp, "\n%*s", 2 * ind, uri) <= 0
        || i2a_ASN1_OBJECT((int)v5, bp, *(asn1_object_st **)v5) <= 0
        || BIO_puts((int)v5, bp, " - ") <= 0
        || GENERAL_NAME_print((int)v5, bp, *((GENERAL_NAME_st **)v5 + 1)) <= 0 )
      {
        break;
      }
      if ( ++v4 >= sk_num((const stack_st *)in[1]) )
        return 1;
    }
  }
  return 0;
}

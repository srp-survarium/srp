bio_st *__usercall cms_content_bio@<eax>(int a1@<ebx>, asn1_string_st *cms)
{
  bio_st *result; // eax
  bio_method_st *method; // eax
  bio_method_st *v4; // eax
  bio_method_st *v5; // eax

  result = (bio_st *)CMS_get0_content(a1, cms);
  if ( result )
  {
    method = result->method;
    if ( method )
    {
      if ( method->bread == (int (__cdecl *)(bio_st *, char *, int))32 )
      {
        v5 = BIO_s_mem();
        return BIO_new(a1, v5);
      }
      else
      {
        return BIO_new_mem_buf(a1, (const char *)method->bwrite, method->type);
      }
    }
    else
    {
      v4 = BIO_s_null();
      return BIO_new(a1, v4);
    }
  }
  return result;
}

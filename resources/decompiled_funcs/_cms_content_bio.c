bio_st *__cdecl cms_content_bio(asn1_string_st *cms)
{
  bio_st *result; // eax
  bio_method_st *method; // eax
  bio_method_st *v3; // eax
  bio_method_st *v4; // eax

  result = (bio_st *)CMS_get0_content(cms);
  if ( result )
  {
    method = result->method;
    if ( method )
    {
      if ( method->bread == (int (__cdecl *)(bio_st *, char *, int))32 )
      {
        v4 = BIO_s_mem();
        return BIO_new(v4);
      }
      else
      {
        return BIO_new_mem_buf((const char *)method->bwrite, method->type);
      }
    }
    else
    {
      v3 = BIO_s_null();
      return BIO_new(v3);
    }
  }
  return result;
}

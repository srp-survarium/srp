asn1_string_st *__usercall ASN1_STRING_type_new@<eax>(int a1@<ebx>, int type)
{
  asn1_string_st *result; // eax

  result = (asn1_string_st *)CRYPTO_malloc(16, ".\\crypto\\asn1\\asn1_lib.c", 425);
  if ( result )
  {
    result->length = 0;
    result->type = type;
    result->data = 0;
    result->flags = 0;
  }
  else
  {
    ERR_put_error(a1, 0xDu, 130, 65, ".\\crypto\\asn1\\asn1_lib.c", 428);
    return 0;
  }
  return result;
}

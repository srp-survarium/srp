asn1_object_st *__usercall ASN1_OBJECT_new@<eax>(int a1@<ebx>)
{
  asn1_object_st *result; // eax

  result = (asn1_object_st *)CRYPTO_malloc(24, ".\\crypto\\asn1\\a_object.c", 351);
  if ( result )
  {
    result->length = 0;
    result->data = 0;
    result->nid = 0;
    result->sn = 0;
    result->ln = 0;
    result->flags = 1;
  }
  else
  {
    ERR_put_error(a1, 0xDu, 123, 65, ".\\crypto\\asn1\\a_object.c", 354);
    return 0;
  }
  return result;
}

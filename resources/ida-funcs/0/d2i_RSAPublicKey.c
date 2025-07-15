rsa_st *__cdecl d2i_RSAPublicKey(rsa_st **a, unsigned __int8 **in, const unsigned __int8 **len)
{
  return (rsa_st *)ASN1_item_d2i((struct ASN1_VALUE_st **)a, in, len, &stru_6CF4B8);
}

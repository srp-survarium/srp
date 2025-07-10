rsa_st *__cdecl d2i_RSAPrivateKey(rsa_st **a, unsigned __int8 **in, unsigned __int8 *len)
{
  return (rsa_st *)ASN1_item_d2i((struct ASN1_VALUE_st **)a, in, len, &stru_83D7B4);
}

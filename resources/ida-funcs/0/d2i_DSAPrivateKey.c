dsa_st *__cdecl d2i_DSAPrivateKey(dsa_st **a, unsigned __int8 **in, const unsigned __int8 **len)
{
  return (dsa_st *)ASN1_item_d2i((struct ASN1_VALUE_st **)a, in, len, &stru_6CF56C);
}

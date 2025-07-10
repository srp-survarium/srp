int __cdecl i2d_RSAPrivateKey(rsa_st *a, unsigned __int8 **out)
{
  return ASN1_item_i2d((struct ASN1_VALUE_st *)a, out, &stru_83D7B4);
}

rsa_st *__usercall RSAPrivateKey_dup@<eax>(int a1@<ebx>, rsa_st *rsa)
{
  return (rsa_st *)ASN1_item_dup(a1, &stru_6CF45C, (struct ASN1_VALUE_st *)rsa);
}

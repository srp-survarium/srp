rsa_st *__cdecl RSAPrivateKey_dup(rsa_st *rsa)
{
  return (rsa_st *)ASN1_item_dup(&stru_83D7B4, (unsigned __int8 *)rsa);
}

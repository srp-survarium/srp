int __cdecl RSA_public_encrypt(int flen, const unsigned __int8 *from, unsigned __int8 *to, rsa_st *rsa)
{
  return ((int (*)(void))rsa->meth->rsa_pub_enc)();
}

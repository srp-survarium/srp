int __cdecl ECDSA_sign(
        int type,
        const unsigned __int8 *dgst,
        int dlen,
        unsigned __int8 *sig,
        unsigned int *siglen,
        ec_key_st *eckey)
{
  return ECDSA_sign_ex(type, dgst, dlen, sig, siglen, 0, 0, eckey);
}

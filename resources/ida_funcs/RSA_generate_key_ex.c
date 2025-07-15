int __cdecl RSA_generate_key_ex(rsa_st *rsa, int bits, bignum_st *e_value, bn_gencb_st *cb)
{
  int (*rsa_keygen)(void); // eax

  rsa_keygen = (int (*)(void))rsa->meth->rsa_keygen;
  if ( rsa_keygen )
    return rsa_keygen();
  else
    return rsa_builtin_keygen(bits, rsa, e_value, cb);
}

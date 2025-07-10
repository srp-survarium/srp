int __cdecl ECDSA_sign_ex(
        int type,
        const unsigned __int8 *dgst,
        int dlen,
        unsigned __int8 *sig,
        unsigned int *siglen,
        const bignum_st *kinv,
        const bignum_st *r,
        ec_key_st *eckey)
{
  ec_key_st *v8; // ebx
  ecdsa_data_st *v9; // eax
  const ECDSA_SIG_st *v10; // eax
  ECDSA_SIG_st *v11; // esi
  unsigned int v13; // eax

  RAND_seed();
  v8 = eckey;
  v9 = ecdsa_check(eckey);
  if ( v9 && (v10 = v9->meth->ecdsa_do_sign(dgst, dlen, kinv, r, v8), (v11 = (ECDSA_SIG_st *)v10) != 0) )
  {
    v13 = i2d_ECDSA_SIG(v10, &sig);
    *siglen = v13;
    ECDSA_SIG_free(v11);
    return 1;
  }
  else
  {
    *siglen = 0;
    return 0;
  }
}

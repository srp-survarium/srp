int __cdecl DSA_sign(
        int type,
        const unsigned __int8 *dgst,
        int dlen,
        unsigned __int8 *sig,
        unsigned int *siglen,
        dsa_st *dsa)
{
  DSA_SIG_st *v6; // eax
  DSA_SIG_st *v7; // esi
  unsigned int v9; // eax

  RAND_seed();
  v6 = (DSA_SIG_st *)((int (__cdecl *)(const unsigned __int8 *, int, dsa_st *, const unsigned __int8 *, int))dsa->meth->dsa_do_sign)(
                       dgst,
                       dlen,
                       dsa,
                       dgst,
                       dlen);
  v7 = v6;
  if ( v6 )
  {
    v9 = i2d_DSA_SIG(v6, &sig);
    *siglen = v9;
    DSA_SIG_free(v7);
    return 1;
  }
  else
  {
    *siglen = 0;
    return 0;
  }
}

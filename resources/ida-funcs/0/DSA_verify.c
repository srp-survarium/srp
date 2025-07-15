int __cdecl DSA_verify(
        int type,
        const unsigned __int8 *dgst,
        int dgst_len,
        unsigned __int8 *sigbuf,
        unsigned __int8 *siglen,
        dsa_st *dsa)
{
  int v6; // esi
  DSA_SIG_st *a; // [esp+4h] [ebp-4h] BYREF

  v6 = -1;
  a = DSA_SIG_new();
  if ( !a )
    return -1;
  if ( d2i_DSA_SIG(&a, &sigbuf, siglen) )
    v6 = dsa->meth->dsa_do_verify(dgst, dgst_len, a, dsa);
  DSA_SIG_free(a);
  return v6;
}

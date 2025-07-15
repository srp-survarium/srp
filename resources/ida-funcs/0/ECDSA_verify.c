int __cdecl ECDSA_verify(
        int type,
        const unsigned __int8 *dgst,
        int dgst_len,
        unsigned __int8 *sigbuf,
        int sig_len,
        ec_key_st *eckey)
{
  int v6; // esi
  ECDSA_SIG_st *v8; // esi
  ec_key_st *v9; // edi
  ecdsa_data_st *v10; // eax
  ECDSA_SIG_st *a; // [esp+4h] [ebp-4h] BYREF

  v6 = -1;
  a = ECDSA_SIG_new();
  if ( !a )
    return -1;
  if ( d2i_ECDSA_SIG(&a, (const unsigned __int8 **)&sigbuf, sig_len) )
  {
    v8 = a;
    v9 = eckey;
    v10 = ecdsa_check(eckey);
    if ( !v10 )
    {
      ECDSA_SIG_free(a);
      return 0;
    }
    v6 = v10->meth->ecdsa_do_verify(dgst, dgst_len, v8, v9);
  }
  ECDSA_SIG_free(a);
  return v6;
}

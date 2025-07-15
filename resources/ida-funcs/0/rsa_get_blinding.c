bn_blinding_st *__usercall rsa_get_blinding@<eax>(rsa_st *rsa@<esi>, int a2@<ebx>, int *local, bignum_ctx *ctx)
{
  int v4; // edi
  bn_blinding_st *blinding; // ebx
  const crypto_threadid_st *v6; // eax
  crypto_threadid_st id; // [esp+Ch] [ebp-8h] BYREF

  v4 = 0;
  CRYPTO_lock(0, a2, 5, 9, ".\\crypto\\rsa\\rsa_eay.c", 261);
  if ( !rsa->blinding )
  {
    CRYPTO_lock(0, a2, 6, 9, ".\\crypto\\rsa\\rsa_eay.c", 265);
    CRYPTO_lock(0, a2, 9, 9, ".\\crypto\\rsa\\rsa_eay.c", 266);
    v4 = 1;
    if ( !rsa->blinding )
      rsa->blinding = (bn_blinding_st *)RSA_setup_blinding(rsa, ctx);
  }
  blinding = rsa->blinding;
  if ( blinding )
  {
    CRYPTO_THREADID_current(&id);
    v6 = BN_BLINDING_thread_id(blinding);
    if ( CRYPTO_THREADID_cmp(&id, v6) )
    {
      *local = 0;
      if ( !rsa->mt_blinding )
      {
        if ( !v4 )
        {
          CRYPTO_lock(0, (int)blinding, 6, 9, ".\\crypto\\rsa\\rsa_eay.c", 298);
          CRYPTO_lock(0, (int)blinding, 9, 9, ".\\crypto\\rsa\\rsa_eay.c", 299);
          v4 = 1;
        }
        if ( !rsa->mt_blinding )
          rsa->mt_blinding = (bn_blinding_st *)RSA_setup_blinding(rsa, ctx);
      }
      blinding = rsa->mt_blinding;
    }
    else
    {
      *local = 1;
    }
  }
  if ( v4 )
    CRYPTO_lock(v4, (int)blinding, 10, 9, ".\\crypto\\rsa\\rsa_eay.c", 311);
  else
    CRYPTO_lock(0, (int)blinding, 6, 9, ".\\crypto\\rsa\\rsa_eay.c", 313);
  return blinding;
}

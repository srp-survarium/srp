bn_blinding_st *__usercall rsa_get_blinding@<eax>(rsa_st *rsa@<esi>, int *local, bignum_ctx *ctx)
{
  unsigned int v3; // edi
  bn_blinding_st *blinding; // ebx
  const crypto_threadid_st *v5; // eax
  crypto_threadid_st id; // [esp+Ch] [ebp-8h] BYREF

  v3 = 0;
  CRYPTO_lock(0, 5, 9, ".\\crypto\\rsa\\rsa_eay.c", 261);
  if ( !rsa->blinding )
  {
    CRYPTO_lock(0, 6, 9, ".\\crypto\\rsa\\rsa_eay.c", 265);
    CRYPTO_lock(0, 9, 9, ".\\crypto\\rsa\\rsa_eay.c", 266);
    v3 = 1;
    if ( !rsa->blinding )
      rsa->blinding = (bn_blinding_st *)RSA_setup_blinding(rsa, ctx);
  }
  blinding = rsa->blinding;
  if ( blinding )
  {
    CRYPTO_THREADID_current(&id);
    v5 = BN_BLINDING_thread_id(blinding);
    if ( CRYPTO_THREADID_cmp(&id, v5) )
    {
      *local = 0;
      if ( !rsa->mt_blinding )
      {
        if ( !v3 )
        {
          CRYPTO_lock(0, 6, 9, ".\\crypto\\rsa\\rsa_eay.c", 298);
          CRYPTO_lock(0, 9, 9, ".\\crypto\\rsa\\rsa_eay.c", 299);
          v3 = 1;
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
  if ( v3 )
    CRYPTO_lock(v3, 10, 9, ".\\crypto\\rsa\\rsa_eay.c", 311);
  else
    CRYPTO_lock(0, 6, 9, ".\\crypto\\rsa\\rsa_eay.c", 313);
  return blinding;
}

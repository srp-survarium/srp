bn_mont_ctx_st *__usercall BN_MONT_CTX_set_locked@<eax>(
        int a1@<edi>,
        bn_mont_ctx_st **pmont,
        int lock,
        const bignum_st *mod,
        bignum_ctx *ctx)
{
  int v5; // ebx
  bn_mont_ctx_st *v6; // ebp
  int v7; // edi

  v5 = 0;
  CRYPTO_lock(a1, 0, 5, lock, ".\\crypto\\bn\\bn_mont.c", 542);
  if ( !*pmont )
  {
    CRYPTO_lock((int)pmont, 0, 6, lock, ".\\crypto\\bn\\bn_mont.c", 545);
    CRYPTO_lock((int)pmont, 0, 9, lock, ".\\crypto\\bn\\bn_mont.c", 546);
    v5 = 1;
    if ( !*pmont )
    {
      v6 = BN_MONT_CTX_new();
      if ( !v6 || BN_MONT_CTX_set(1, v6, mod, ctx) )
        *pmont = v6;
      else
        BN_MONT_CTX_free(v6);
    }
  }
  v7 = (int)*pmont;
  if ( v5 )
    CRYPTO_lock(v7, v5, 10, lock, ".\\crypto\\bn\\bn_mont.c", 562);
  else
    CRYPTO_lock(v7, 0, 6, lock, ".\\crypto\\bn\\bn_mont.c", 564);
  return (bn_mont_ctx_st *)v7;
}

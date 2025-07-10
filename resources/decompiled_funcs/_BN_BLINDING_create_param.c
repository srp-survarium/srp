bn_blinding_st *__cdecl BN_BLINDING_create_param(
        bn_blinding_st *b,
        const bignum_st *e,
        bignum_st *m,
        bignum_ctx *ctx,
        int (__cdecl *bn_mod_exp)(bignum_st *, const bignum_st *, const bignum_st *, const bignum_st *, bignum_ctx *, bn_mont_ctx_st *),
        bn_mont_ctx_st *m_ctx)
{
  int v6; // ebx
  bn_blinding_st *v7; // eax
  bn_blinding_st *v8; // esi
  bignum_st *v10; // eax
  bignum_st *v11; // eax
  bignum_st *v12; // eax
  int (__cdecl *v14)(bignum_st *, const bignum_st *, const bignum_st *, const bignum_st *, bignum_ctx *, bn_mont_ctx_st *); // edx

  v6 = 32;
  if ( b )
  {
    v8 = b;
  }
  else
  {
    v7 = (bn_blinding_st *)CRYPTO_malloc(44, ".\\crypto\\bn\\bn_blind.c", 143);
    v8 = v7;
    if ( !v7 )
    {
      ERR_put_error(3u, 102, 65, ".\\crypto\\bn\\bn_blind.c", 145);
      return 0;
    }
    memset((int)v7, 0, sizeof(bn_blinding_st));
    v10 = BN_dup(m);
    v8->mod = v10;
    if ( !v10 )
    {
LABEL_37:
      BN_BLINDING_free(v8);
      return 0;
    }
    if ( (m->flags & 4) != 0 )
      v10->flags |= 4u;
    v8->counter = -1;
    CRYPTO_THREADID_current(&v8->tid);
  }
  if ( !v8 )
    goto err_110;
  if ( !v8->A )
  {
    v11 = BN_new();
    v8->A = v11;
    if ( !v11 )
      goto err_110;
  }
  if ( !v8->Ai )
  {
    v12 = BN_new();
    v8->Ai = v12;
    if ( !v12 )
      goto err_110;
  }
  if ( e )
  {
    if ( v8->e )
      BN_free(v8->e);
    v8->e = BN_dup(e);
  }
  if ( !v8->e )
    goto err_110;
  if ( bn_mod_exp )
    v8->bn_mod_exp = bn_mod_exp;
  if ( m_ctx )
    v8->m_ctx = m_ctx;
  if ( !BN_rand_range(v8->A, v8->mod) )
  {
err_110:
    if ( b || !v8 )
      return v8;
    goto LABEL_37;
  }
  while ( !BN_mod_inverse(v8->Ai, v8->A, v8->mod, ctx) )
  {
    if ( (ERR_peek_last_error() & 0xFFF) != 0x6C )
      goto err_110;
    if ( !v6-- )
    {
      ERR_put_error(3u, 128, 113, ".\\crypto\\bn\\bn_blind.c", 353);
      goto err_110;
    }
    ERR_clear_error();
    if ( !BN_rand_range(v8->A, v8->mod) )
      goto err_110;
  }
  v14 = v8->bn_mod_exp;
  if ( v14 && v8->m_ctx )
  {
    if ( v14(v8->A, v8->A, v8->e, v8->mod, ctx, v8->m_ctx) )
      return v8;
    goto err_110;
  }
  if ( !BN_mod_exp(v8->A, v8->A, v8->e, v8->mod, ctx) )
    goto err_110;
  return v8;
}

int __cdecl BN_GF2m_mod_solve_quad_arr(bignum_st *r, const bignum_st *a_, int *p, bignum_ctx *ctx)
{
  bignum_pool_item *v6; // ebp
  bignum_pool_item *v7; // ebx
  int v8; // ebp
  bignum_pool_item *v9; // ebp
  bignum_pool_item *rnd; // [esp+4h] [ebp-18h]
  int v11; // [esp+8h] [ebp-14h]
  bignum_st *b; // [esp+Ch] [ebp-10h]
  int v13; // [esp+10h] [ebp-Ch]
  bignum_pool_item *ra; // [esp+14h] [ebp-8h]
  int v15; // [esp+18h] [ebp-4h]
  bignum_pool_item *pa; // [esp+28h] [ebp+Ch]

  v13 = 0;
  v11 = 0;
  if ( !*p )
  {
    BN_set_word(r, 0);
    return 1;
  }
  BN_CTX_start(ctx);
  v6 = BN_CTX_get(ctx);
  b = (bignum_st *)v6;
  v7 = BN_CTX_get(ctx);
  pa = BN_CTX_get(ctx);
  if ( !pa || !BN_GF2m_mod_arr(v6->vals, a_, p) )
    goto err_178;
  if ( !v6->vals[0].top )
  {
    BN_set_word(r, 0);
LABEL_34:
    v13 = 1;
    goto err_178;
  }
  if ( (*(_BYTE *)p & 1) == 0 )
  {
    rnd = BN_CTX_get(ctx);
    v9 = BN_CTX_get(ctx);
    ra = BN_CTX_get(ctx);
    if ( ra )
    {
      while ( BN_rand(rnd->vals, *p, 0, 0) )
      {
        if ( !BN_GF2m_mod_arr(rnd->vals, rnd->vals, p) )
          break;
        BN_set_word(v7->vals, 0);
        if ( !BN_copy(pa->vals, rnd->vals) )
          break;
        v15 = 1;
        if ( *p - 1 >= 1 )
        {
          while ( BN_GF2m_mod_sqr_arr(v7->vals, v7->vals, p, ctx)
               && BN_GF2m_mod_sqr_arr(v9->vals, pa->vals, p, ctx)
               && BN_GF2m_mod_mul_arr(ra->vals, v9->vals, b, p, ctx)
               && BN_GF2m_add(v7->vals, v7->vals, ra->vals)
               && BN_GF2m_add(pa->vals, v9->vals, rnd->vals) )
          {
            if ( ++v15 > *p - 1 )
              goto LABEL_29;
          }
          goto err_178;
        }
LABEL_29:
        ++v11;
        if ( pa->vals[0].top || v11 >= 50 )
        {
          if ( pa->vals[0].top )
            goto LABEL_14;
          ERR_put_error(3u, 135, 113, ".\\crypto\\bn\\bn_gf2m.c", 927);
          BN_CTX_end(ctx);
          return 0;
        }
      }
    }
    goto err_178;
  }
  if ( BN_copy(v7->vals, v6->vals) )
  {
    v8 = 1;
    if ( (*p - 1) / 2 >= 1 )
    {
      while ( BN_GF2m_mod_sqr_arr(v7->vals, v7->vals, p, ctx)
           && BN_GF2m_mod_sqr_arr(v7->vals, v7->vals, p, ctx)
           && BN_GF2m_add(v7->vals, v7->vals, b) )
      {
        if ( ++v8 > (*p - 1) / 2 )
          goto LABEL_14;
      }
      goto err_178;
    }
LABEL_14:
    if ( BN_GF2m_mod_sqr_arr(pa->vals, v7->vals, p, ctx) && BN_GF2m_add(pa->vals, v7->vals, pa->vals) )
    {
      if ( BN_ucmp(pa->vals, b) )
      {
        ERR_put_error(3u, 135, 116, ".\\crypto\\bn\\bn_gf2m.c", 936);
        BN_CTX_end(ctx);
        return 0;
      }
      if ( BN_copy(r, v7->vals) )
        goto LABEL_34;
    }
  }
err_178:
  BN_CTX_end(ctx);
  return v13;
}

int __usercall BN_GF2m_mod_solve_quad_arr@<eax>(
        int a1@<ebx>,
        bignum_st *r,
        const bignum_st *a_,
        int *p,
        bignum_ctx *ctx)
{
  bignum_pool_item *v7; // ebp
  bignum_pool_item *v8; // ebx
  int v9; // ebp
  bignum_pool_item *v10; // ebp
  bignum_pool_item *rnd; // [esp+4h] [ebp-18h]
  int v12; // [esp+8h] [ebp-14h]
  bignum_st *b; // [esp+Ch] [ebp-10h]
  int v14; // [esp+10h] [ebp-Ch]
  bignum_pool_item *v15; // [esp+14h] [ebp-8h]
  int v16; // [esp+18h] [ebp-4h]
  bignum_pool_item *pa; // [esp+28h] [ebp+Ch]

  v14 = 0;
  v12 = 0;
  if ( !*p )
  {
    BN_set_word(a1, r, 0);
    return 1;
  }
  BN_CTX_start(a1, ctx);
  v7 = BN_CTX_get(a1, ctx);
  b = (bignum_st *)v7;
  v8 = BN_CTX_get(a1, ctx);
  pa = BN_CTX_get((int)v8, ctx);
  if ( !pa || !BN_GF2m_mod_arr((int)v8, v7->vals, a_, p) )
    goto err_180;
  if ( !v7->vals[0].top )
  {
    BN_set_word((int)v8, r, 0);
LABEL_34:
    v14 = 1;
    goto err_180;
  }
  if ( (*(_BYTE *)p & 1) == 0 )
  {
    rnd = BN_CTX_get((int)v8, ctx);
    v10 = BN_CTX_get((int)v8, ctx);
    v15 = BN_CTX_get((int)v8, ctx);
    if ( v15 )
    {
      while ( BN_rand((int)v8, rnd->vals, *p, 0, 0) )
      {
        if ( !BN_GF2m_mod_arr((int)v8, rnd->vals, rnd->vals, p) )
          break;
        BN_set_word((int)v8, v8->vals, 0);
        if ( !BN_copy(pa->vals, rnd->vals) )
          break;
        v16 = 1;
        if ( *p - 1 >= 1 )
        {
          while ( BN_GF2m_mod_sqr_arr(v8->vals, v8->vals, p, ctx)
               && BN_GF2m_mod_sqr_arr(v10->vals, pa->vals, p, ctx)
               && BN_GF2m_mod_mul_arr(v15->vals, v10->vals, b, p, ctx)
               && BN_GF2m_add(v8->vals, v8->vals, v15->vals)
               && BN_GF2m_add(pa->vals, v10->vals, rnd->vals) )
          {
            if ( ++v16 > *p - 1 )
              goto LABEL_29;
          }
          goto err_180;
        }
LABEL_29:
        ++v12;
        if ( pa->vals[0].top || v12 >= 50 )
        {
          if ( pa->vals[0].top )
            goto LABEL_14;
          ERR_put_error((int)v8, 3u, 135, 113, ".\\crypto\\bn\\bn_gf2m.c", 927);
          BN_CTX_end(ctx);
          return 0;
        }
      }
    }
    goto err_180;
  }
  if ( BN_copy(v8->vals, v7->vals) )
  {
    v9 = 1;
    if ( (*p - 1) / 2 >= 1 )
    {
      while ( BN_GF2m_mod_sqr_arr(v8->vals, v8->vals, p, ctx)
           && BN_GF2m_mod_sqr_arr(v8->vals, v8->vals, p, ctx)
           && BN_GF2m_add(v8->vals, v8->vals, b) )
      {
        if ( ++v9 > (*p - 1) / 2 )
          goto LABEL_14;
      }
      goto err_180;
    }
LABEL_14:
    if ( BN_GF2m_mod_sqr_arr(pa->vals, v8->vals, p, ctx) && BN_GF2m_add(pa->vals, v8->vals, pa->vals) )
    {
      if ( BN_ucmp(pa->vals, b) )
      {
        ERR_put_error((int)v8, 3u, 135, 116, ".\\crypto\\bn\\bn_gf2m.c", 936);
        BN_CTX_end(ctx);
        return 0;
      }
      if ( BN_copy(r, v8->vals) )
        goto LABEL_34;
    }
  }
err_180:
  BN_CTX_end(ctx);
  return v14;
}

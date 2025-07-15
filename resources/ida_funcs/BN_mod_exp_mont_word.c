int __cdecl BN_mod_exp_mont_word(
        bignum_st *rr,
        unsigned int a,
        const bignum_st *p,
        const bignum_st *m,
        bignum_ctx *ctx,
        bn_mont_ctx_st *in_mont)
{
  int top; // eax
  unsigned int v8; // ecx
  bignum_pool_item *v9; // edi
  bignum_pool_item *v10; // esi
  bignum_pool_item *v11; // eax
  bignum_st *v12; // ebx
  bn_mont_ctx_st *v13; // eax
  unsigned int v14; // edi
  int v15; // ecx
  bool v16; // sf
  int v17; // ebx
  bignum_pool_item *v18; // eax
  unsigned int v19; // ebx
  bignum_pool_item *v20; // eax
  int v21; // eax
  bn_mont_ctx_st *mont; // [esp+8h] [ebp-14h]
  int v23; // [esp+Ch] [ebp-10h]
  bignum_st *rm; // [esp+10h] [ebp-Ch]
  int n; // [esp+14h] [ebp-8h]
  int na; // [esp+14h] [ebp-8h]
  int v27; // [esp+18h] [ebp-4h]

  mont = 0;
  v27 = 0;
  if ( (p->flags & 4) != 0 )
  {
    ERR_put_error(3u, 117, 66, ".\\crypto\\bn\\bn_exp.c", 752);
    return -1;
  }
  top = m->top;
  if ( top > 0 )
  {
    v8 = *m->d;
    if ( (v8 & 1) != 0 )
    {
      if ( top == 1 )
        a %= v8;
      n = BN_num_bits(p);
      if ( !n )
        return BN_set_word(rr, 1u);
      if ( !a )
      {
        BN_set_word(rr, 0);
        return 1;
      }
      BN_CTX_start(ctx);
      v9 = BN_CTX_get(ctx);
      v10 = BN_CTX_get(ctx);
      v11 = BN_CTX_get(ctx);
      v12 = (bignum_st *)v11;
      rm = (bignum_st *)v11;
      if ( !v9 || !v10 || !v11 )
      {
err_143:
        if ( !in_mont )
        {
LABEL_51:
          if ( mont )
            BN_MONT_CTX_free(mont);
        }
LABEL_53:
        BN_CTX_end(ctx);
        return v27;
      }
      if ( in_mont )
      {
        mont = in_mont;
      }
      else
      {
        v13 = BN_MONT_CTX_new();
        mont = v13;
        if ( !v13 )
          goto LABEL_53;
        if ( !BN_MONT_CTX_set(v13, m, ctx) )
          goto LABEL_51;
      }
      v14 = a;
      v15 = 1;
      v16 = n - 2 < 0;
      v23 = 1;
      na = n - 2;
      if ( !v16 )
      {
        do
        {
          v17 = v14 * v14;
          if ( v14 * v14 / v14 != v14 )
          {
            if ( v15 )
            {
              if ( !BN_set_word(v10->vals, v14) || !BN_mod_mul_montgomery(v10->vals, v10->vals, &mont->RR, mont, ctx) )
                goto err_143;
              v23 = 0;
            }
            else
            {
              if ( !BN_mul_word(v10->vals, v14) || !BN_div(0, rm, v10->vals, m, ctx) )
                goto err_143;
              v18 = v10;
              v10 = (bignum_pool_item *)rm;
              rm = (bignum_st *)v18;
            }
            v15 = v23;
            v17 = 1;
          }
          v14 = v17;
          if ( !v15 && !BN_mod_mul_montgomery(v10->vals, v10->vals, v10->vals, mont, ctx) )
            goto err_143;
          if ( BN_is_bit_set(p, na) )
          {
            v19 = a * v17;
            if ( v19 / a != v14 )
            {
              if ( v23 )
              {
                if ( !BN_set_word(v10->vals, v14) || !BN_mod_mul_montgomery(v10->vals, v10->vals, &mont->RR, mont, ctx) )
                  goto err_143;
                v23 = 0;
              }
              else
              {
                if ( !BN_mul_word(v10->vals, v14) || !BN_div(0, rm, v10->vals, m, ctx) )
                  goto err_143;
                v20 = v10;
                v10 = (bignum_pool_item *)rm;
                rm = (bignum_st *)v20;
              }
              v19 = a;
            }
            v14 = v19;
          }
          v16 = --na < 0;
          v15 = v23;
        }
        while ( !v16 );
        v12 = rm;
      }
      if ( v14 == 1 )
      {
        if ( v15 )
        {
          v21 = BN_set_word(rr, 1u);
LABEL_48:
          if ( v21 )
            v27 = 1;
          goto err_143;
        }
      }
      else if ( v15 )
      {
        if ( !BN_set_word(v10->vals, v14) || !BN_mod_mul_montgomery(v10->vals, v10->vals, &mont->RR, mont, ctx) )
          goto err_143;
      }
      else
      {
        if ( !BN_mul_word(v10->vals, v14) || !BN_div(0, v12, v10->vals, m, ctx) )
          goto err_143;
        v10 = (bignum_pool_item *)v12;
      }
      v21 = BN_from_montgomery(rr, v10->vals, mont, ctx);
      goto LABEL_48;
    }
  }
  ERR_put_error(3u, 117, 102, ".\\crypto\\bn\\bn_exp.c", 761);
  return 0;
}

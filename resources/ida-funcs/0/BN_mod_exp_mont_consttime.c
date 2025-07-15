int __cdecl BN_mod_exp_mont_consttime(
        bignum_st *rr,
        const bignum_st *a,
        const bignum_st *p,
        const bignum_st *m,
        bignum_ctx *ctx,
        bn_mont_ctx_st *in_mont)
{
  int v7; // esi
  int v9; // edi
  bignum_ctx *v10; // ebp
  bn_mont_ctx_st *v11; // eax
  int v12; // ebp
  char *v13; // eax
  const bignum_st *v14; // eax
  bignum_pool_item *v15; // eax
  const bignum_st *v16; // esi
  int v17; // ecx
  int v18; // edi
  int v19; // ebx
  int v20; // edi
  int v21; // esi
  unsigned int is_bit_set; // eax
  bn_mont_ctx_st *mont; // [esp+Ch] [ebp-28h]
  bignum_st *rm; // [esp+10h] [ebp-24h]
  bignum_pool_item *b; // [esp+14h] [ebp-20h]
  unsigned __int8 *buf; // [esp+18h] [ebp-1Ch]
  bignum_pool_item *r; // [esp+1Ch] [ebp-18h]
  int count; // [esp+20h] [ebp-14h]
  void *str; // [esp+24h] [ebp-10h]
  int top; // [esp+28h] [ebp-Ch]
  int v31; // [esp+2Ch] [ebp-8h]
  int v32; // [esp+30h] [ebp-4h]
  int mod; // [esp+44h] [ebp+10h]

  v7 = m->top;
  v31 = 0;
  mont = 0;
  str = 0;
  count = 0;
  buf = 0;
  b = 0;
  rm = 0;
  top = v7;
  if ( (*(_BYTE *)m->d & 1) == 0 )
  {
    ERR_put_error(3u, 124, 102, ".\\crypto\\bn\\bn_exp.c", 595);
    return 0;
  }
  v9 = BN_num_bits(p);
  v32 = v9;
  if ( !v9 )
    return BN_set_word(rr, 1u);
  v10 = ctx;
  BN_CTX_start(ctx);
  r = BN_CTX_get(ctx);
  if ( !r )
    goto err_142;
  if ( in_mont )
  {
    mont = in_mont;
    goto LABEL_10;
  }
  v11 = BN_MONT_CTX_new();
  mont = v11;
  if ( v11 )
  {
    if ( !BN_MONT_CTX_set(v11, m, ctx) )
      goto LABEL_45;
LABEL_10:
    if ( v9 <= 937 )
    {
      if ( v9 <= 306 )
      {
        if ( v9 <= 89 )
          mod = 2 * (v9 > 22) + 1;
        else
          mod = 4;
      }
      else
      {
        mod = 5;
      }
    }
    else
    {
      mod = 6;
    }
    v12 = 1 << mod;
    count = 4 * v7 * (1 << mod);
    v13 = CRYPTO_malloc(count + 64, ".\\crypto\\bn\\bn_exp.c", 629);
    str = v13;
    if ( v13 )
    {
      buf = (unsigned __int8 *)((char *)v13 - ((unsigned __int8)v13 & 0x3F) + 64);
      memset((int)buf, 0, count);
      v14 = BN_value_one();
      if ( BN_mod_mul_montgomery(r->vals, v14, &mont->RR, mont, ctx) )
      {
        if ( MOD_EXP_CTIME_COPY_TO_PREBUF(r->vals, v7, buf, 0, v12) )
        {
          b = BN_CTX_get(ctx);
          v15 = BN_CTX_get(ctx);
          rm = (bignum_st *)v15;
          if ( b )
          {
            if ( v15 )
            {
              v16 = a;
              if ( a->neg || BN_ucmp(a, m) >= 0 )
              {
                if ( !BN_div(0, rm, a, m, ctx) )
                  goto err_142;
                v16 = rm;
              }
              if ( BN_mod_mul_montgomery(rm, v16, &mont->RR, mont, ctx)
                && BN_copy(b->vals, rm)
                && MOD_EXP_CTIME_COPY_TO_PREBUF(rm, top, buf, 1, v12) )
              {
                v17 = mod;
                if ( mod <= 1 || (v18 = 2, v12 <= 2) )
                {
LABEL_35:
                  v19 = mod * ((v17 + v32 - 1) / v17) - 1;
                  if ( v19 < 0 )
                  {
LABEL_42:
                    if ( BN_from_montgomery(rr, r->vals, mont, ctx) )
                      v31 = 1;
                  }
                  else
                  {
                    while ( 1 )
                    {
                      v20 = 0;
                      v21 = 0;
                      if ( mod > 0 )
                        break;
LABEL_39:
                      if ( !MOD_EXP_CTIME_COPY_FROM_PREBUF(b->vals, top, buf, v21, v12)
                        || !BN_mod_mul_montgomery(r->vals, r->vals, b->vals, mont, ctx) )
                      {
                        goto err_142;
                      }
                      if ( v19 < 0 )
                        goto LABEL_42;
                    }
                    while ( BN_mod_mul_montgomery(r->vals, r->vals, r->vals, mont, ctx) )
                    {
                      is_bit_set = BN_is_bit_set(p, v19);
                      ++v20;
                      --v19;
                      v21 = is_bit_set + 2 * v21;
                      if ( v20 >= mod )
                        goto LABEL_39;
                    }
                  }
                }
                else
                {
                  while ( BN_mod_mul_montgomery(b->vals, rm, b->vals, mont, ctx)
                       && MOD_EXP_CTIME_COPY_TO_PREBUF(b->vals, top, buf, v18, v12) )
                  {
                    if ( ++v18 >= v12 )
                    {
                      v17 = mod;
                      goto LABEL_35;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
err_142:
    v10 = ctx;
    if ( in_mont )
    {
LABEL_47:
      if ( buf )
      {
        OPENSSL_cleanse(buf, count);
        CRYPTO_free(str);
      }
      if ( rm )
        BN_clear(rm);
      if ( b )
        BN_clear(b->vals);
      goto LABEL_53;
    }
LABEL_45:
    if ( mont )
      BN_MONT_CTX_free(mont);
    goto LABEL_47;
  }
LABEL_53:
  BN_CTX_end(v10);
  return v31;
}

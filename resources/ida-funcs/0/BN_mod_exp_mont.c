int __cdecl BN_mod_exp_mont(
        bignum_st *rr,
        const bignum_st *a,
        const bignum_st *p,
        const bignum_st *m,
        bignum_ctx *ctx,
        bn_mont_ctx_st *in_mont)
{
  bignum_ctx *v7; // edi
  bignum_pool_item *v8; // eax
  bignum_st *v9; // esi
  bn_mont_ctx_st *v10; // eax
  const bignum_st *v11; // eax
  int v12; // ebx
  int v13; // ebx
  int v14; // esi
  bignum_pool_item *v15; // eax
  int v16; // ebx
  const bignum_st *v17; // eax
  bignum_st *v18; // esi
  int v19; // edi
  int v20; // esi
  int v21; // ebp
  int v22; // ebx
  int v23; // edi
  int v24; // ebx
  int v25; // esi
  bool v26; // sf
  bignum_st *v27; // [esp-18h] [ebp-B8h]
  bn_mont_ctx_st *mont; // [esp+4h] [ebp-9Ch]
  bignum_pool_item *r; // [esp+8h] [ebp-98h]
  bignum_st *ra; // [esp+8h] [ebp-98h]
  int v31; // [esp+Ch] [ebp-94h]
  int v32; // [esp+Ch] [ebp-94h]
  int v33; // [esp+10h] [ebp-90h]
  bignum_pool_item *v34; // [esp+14h] [ebp-8Ch]
  int v35; // [esp+18h] [ebp-88h]
  bignum_st *b; // [esp+1Ch] [ebp-84h]
  bignum_st *v37[32]; // [esp+20h] [ebp-80h]

  v35 = 0;
  mont = 0;
  if ( (p->flags & 4) != 0 )
    return BN_mod_exp_mont_consttime(rr, a, p, m, ctx, in_mont);
  if ( m->top > 0 && (*(_BYTE *)m->d & 1) != 0 )
  {
    v31 = BN_num_bits(p);
    if ( !v31 )
      return BN_set_word(rr, 1u);
    v7 = ctx;
    BN_CTX_start(ctx);
    r = BN_CTX_get(ctx);
    v34 = BN_CTX_get(ctx);
    v8 = BN_CTX_get(ctx);
    v9 = (bignum_st *)v8;
    v37[0] = (bignum_st *)v8;
    if ( !r || !v34 || !v8 )
      goto err_144;
    if ( in_mont )
    {
      mont = in_mont;
    }
    else
    {
      v10 = BN_MONT_CTX_new();
      mont = v10;
      if ( !v10 )
        goto LABEL_61;
      if ( !BN_MONT_CTX_set(v10, m, ctx) )
        goto LABEL_59;
    }
    if ( a->neg || BN_ucmp(a, m) >= 0 )
    {
      if ( !BN_nnmod(v9, a, m, ctx) )
        goto err_144;
      v11 = v9;
    }
    else
    {
      v11 = a;
    }
    if ( !v11->top )
    {
      BN_set_word(rr, 0);
      v35 = 1;
      goto err_144;
    }
    b = &mont->RR;
    if ( !BN_mod_mul_montgomery(v9, v11, &mont->RR, mont, ctx) )
    {
err_144:
      if ( !in_mont )
      {
LABEL_59:
        if ( mont )
          BN_MONT_CTX_free(mont);
      }
LABEL_61:
      BN_CTX_end(v7);
      return v35;
    }
    v12 = v31;
    if ( v31 <= 671 )
    {
      if ( v31 <= 239 )
      {
        if ( v31 <= 79 )
        {
          v33 = 2 * (v31 > 23) + 1;
          if ( __OFSUB__(v33, 1) || v33 == 1 )
            goto LABEL_35;
        }
        else
        {
          v33 = 4;
        }
      }
      else
      {
        v33 = 5;
      }
    }
    else
    {
      v33 = 6;
    }
    if ( !BN_mod_mul_montgomery(r->vals, v9, v9, mont, ctx) )
      goto err_144;
    v13 = 1 << (v33 - 1);
    v14 = 1;
    if ( v13 > 1 )
    {
      do
      {
        v15 = BN_CTX_get(ctx);
        v37[v14] = (bignum_st *)v15;
        if ( !v15 || !BN_mod_mul_montgomery(v15->vals, v37[v14 - 1], r->vals, mont, ctx) )
          goto err_144;
      }
      while ( ++v14 < v13 );
    }
    v12 = v31;
LABEL_35:
    v16 = v12 - 1;
    v27 = b;
    v32 = 1;
    ra = (bignum_st *)v16;
    v17 = BN_value_one();
    v18 = (bignum_st *)v34;
    if ( BN_mod_mul_montgomery(v34->vals, v17, v27, mont, ctx) )
    {
      while ( 1 )
      {
        while ( !BN_is_bit_set(p, v16) )
        {
          if ( !v32 && !BN_mod_mul_montgomery(v18, v18, v18, mont, v7) )
            goto err_144;
          if ( !v16 )
            goto LABEL_55;
          ra = (bignum_st *)--v16;
        }
        v19 = 1;
        v20 = 1;
        v21 = 0;
        if ( v33 > 1 )
        {
          v22 = v16 - 1;
          do
          {
            if ( v22 < 0 )
              break;
            if ( BN_is_bit_set(p, v22) )
            {
              v23 = v19 << (v20 - v21);
              v21 = v20;
              v19 = v23 | 1;
            }
            ++v20;
            --v22;
          }
          while ( v20 < v33 );
        }
        v24 = v21 + 1;
        if ( !v32 )
        {
          v25 = 0;
          if ( v24 > 0 )
          {
            while ( BN_mod_mul_montgomery(v34->vals, v34->vals, v34->vals, mont, ctx) )
            {
              if ( ++v25 >= v24 )
                goto LABEL_53;
            }
LABEL_57:
            v7 = ctx;
            goto err_144;
          }
        }
LABEL_53:
        if ( !BN_mod_mul_montgomery(v34->vals, v34->vals, v37[v19 >> 1], mont, ctx) )
          goto LABEL_57;
        v7 = ctx;
        v18 = (bignum_st *)v34;
        v26 = (int)ra - 1 - v21 < 0;
        ra = (bignum_st *)((char *)ra - 1 - v21);
        v32 = 0;
        if ( v26 )
          break;
        v16 = (int)ra;
      }
LABEL_55:
      if ( BN_from_montgomery(rr, v18, mont, v7) )
        v35 = 1;
    }
    goto err_144;
  }
  ERR_put_error(3u, 109, 102, ".\\crypto\\bn\\bn_exp.c", 394);
  return 0;
}

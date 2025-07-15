int __usercall BN_mod_exp_mont@<eax>(
        int a1@<ebx>,
        bignum_st *rr,
        bignum_pool_item *a,
        const bignum_st *p,
        const bignum_st *m,
        bignum_ctx *ctx,
        bn_mont_ctx_st *in_mont)
{
  bignum_ctx *v8; // edi
  bignum_pool_item *v9; // eax
  bignum_pool_item *v10; // esi
  bn_mont_ctx_st *v11; // eax
  bignum_pool_item *v12; // eax
  int v13; // ebx
  int v14; // ebx
  int v15; // esi
  bignum_pool_item *v16; // eax
  int v17; // ebx
  bignum_pool_item *v18; // eax
  bignum_pool_item *v19; // esi
  int v20; // edi
  int v21; // esi
  int v22; // ebp
  int v23; // ebx
  int v24; // edi
  int v25; // ebx
  int v26; // esi
  bool v27; // sf
  bignum_pool_item *v28; // [esp-18h] [ebp-B8h]
  bn_mont_ctx_st *mont; // [esp+4h] [ebp-9Ch]
  bignum_pool_item *r; // [esp+8h] [ebp-98h]
  bignum_st *ra; // [esp+8h] [ebp-98h]
  int v32; // [esp+Ch] [ebp-94h]
  int v33; // [esp+Ch] [ebp-94h]
  int v34; // [esp+10h] [ebp-90h]
  bignum_pool_item *v35; // [esp+14h] [ebp-8Ch]
  int v36; // [esp+18h] [ebp-88h]
  bignum_st *b; // [esp+1Ch] [ebp-84h]
  bignum_st *v38[32]; // [esp+20h] [ebp-80h]

  v36 = 0;
  mont = 0;
  if ( (p->flags & 4) != 0 )
    return BN_mod_exp_mont_consttime(rr, a, p, m, ctx, in_mont);
  if ( m->top > 0 && (*(_BYTE *)m->d & 1) != 0 )
  {
    v32 = BN_num_bits(p);
    if ( !v32 )
      return BN_set_word(a1, rr, 1u);
    v8 = ctx;
    BN_CTX_start(a1, ctx);
    r = BN_CTX_get(a1, ctx);
    v35 = BN_CTX_get((int)r, ctx);
    v9 = BN_CTX_get((int)r, ctx);
    v10 = v9;
    v38[0] = (bignum_st *)v9;
    if ( !r || !v35 || !v9 )
      goto err_146;
    if ( in_mont )
    {
      mont = in_mont;
    }
    else
    {
      v11 = BN_MONT_CTX_new();
      mont = v11;
      if ( !v11 )
        goto LABEL_61;
      if ( !BN_MONT_CTX_set(v11, m, ctx) )
        goto LABEL_59;
    }
    if ( a->vals[0].neg || BN_ucmp(a->vals, m) >= 0 )
    {
      if ( !BN_nnmod(v10->vals, a->vals, m, ctx) )
        goto err_146;
      v12 = v10;
    }
    else
    {
      v12 = a;
    }
    if ( !v12->vals[0].top )
    {
      BN_set_word((int)a, rr, 0);
      v36 = 1;
      goto err_146;
    }
    b = &mont->RR;
    if ( !BN_mod_mul_montgomery(v10->vals, v12, (bignum_pool_item *)&mont->RR, mont, ctx) )
    {
err_146:
      if ( !in_mont )
      {
LABEL_59:
        if ( mont )
          BN_MONT_CTX_free(mont);
      }
LABEL_61:
      BN_CTX_end(v8);
      return v36;
    }
    v13 = v32;
    if ( v32 <= 671 )
    {
      if ( v32 <= 239 )
      {
        if ( v32 <= 79 )
        {
          v34 = 2 * (v32 > 23) + 1;
          if ( __OFSUB__(v34, 1) || v34 == 1 )
            goto LABEL_35;
        }
        else
        {
          v34 = 4;
        }
      }
      else
      {
        v34 = 5;
      }
    }
    else
    {
      v34 = 6;
    }
    if ( !BN_mod_mul_montgomery(r->vals, v10, v10, mont, ctx) )
      goto err_146;
    v14 = 1 << (v34 - 1);
    v15 = 1;
    if ( v14 > 1 )
    {
      do
      {
        v16 = BN_CTX_get(v14, ctx);
        v38[v15] = (bignum_st *)v16;
        if ( !v16 || !BN_mod_mul_montgomery(v16->vals, (bignum_pool_item *)v38[v15 - 1], r, mont, ctx) )
          goto err_146;
      }
      while ( ++v15 < v14 );
    }
    v13 = v32;
LABEL_35:
    v17 = v13 - 1;
    v28 = (bignum_pool_item *)b;
    v33 = 1;
    ra = (bignum_st *)v17;
    v18 = (bignum_pool_item *)BN_value_one();
    v19 = v35;
    if ( BN_mod_mul_montgomery(v35->vals, v18, v28, mont, ctx) )
    {
      while ( 1 )
      {
        while ( !BN_is_bit_set(p, v17) )
        {
          if ( !v33 && !BN_mod_mul_montgomery(v19->vals, v19, v19, mont, v8) )
            goto err_146;
          if ( !v17 )
            goto LABEL_55;
          ra = (bignum_st *)--v17;
        }
        v20 = 1;
        v21 = 1;
        v22 = 0;
        if ( v34 > 1 )
        {
          v23 = v17 - 1;
          do
          {
            if ( v23 < 0 )
              break;
            if ( BN_is_bit_set(p, v23) )
            {
              v24 = v20 << (v21 - v22);
              v22 = v21;
              v20 = v24 | 1;
            }
            ++v21;
            --v23;
          }
          while ( v21 < v34 );
        }
        v25 = v22 + 1;
        if ( !v33 )
        {
          v26 = 0;
          if ( v25 > 0 )
          {
            while ( BN_mod_mul_montgomery(v35->vals, v35, v35, mont, ctx) )
            {
              if ( ++v26 >= v25 )
                goto LABEL_53;
            }
LABEL_57:
            v8 = ctx;
            goto err_146;
          }
        }
LABEL_53:
        if ( !BN_mod_mul_montgomery(v35->vals, v35, (bignum_pool_item *)v38[v20 >> 1], mont, ctx) )
          goto LABEL_57;
        v8 = ctx;
        v19 = v35;
        v27 = (int)ra - 1 - v22 < 0;
        ra = (bignum_st *)((char *)ra - 1 - v22);
        v33 = 0;
        if ( v27 )
          break;
        v17 = (int)ra;
      }
LABEL_55:
      if ( BN_from_montgomery(rr, v19->vals, mont, v8) )
        v36 = 1;
    }
    goto err_146;
  }
  ERR_put_error(a1, 3u, 109, 102, ".\\crypto\\bn\\bn_exp.c", 394);
  return 0;
}

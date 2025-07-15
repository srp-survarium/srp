int __usercall BN_mod_exp_recp@<eax>(
        int a1@<ebx>,
        bignum_pool_item *r,
        const bignum_st *a,
        const bignum_st *p,
        const bignum_st *m,
        bignum_ctx *ctx)
{
  bignum_ctx *v7; // ebp
  bignum_pool_item *v8; // ebx
  bignum_pool_item *v9; // eax
  bignum_pool_item *v10; // edi
  int v11; // eax
  int v12; // eax
  int v13; // edi
  int v14; // esi
  bignum_pool_item *v15; // eax
  bignum_pool_item *v16; // esi
  int v17; // edi
  int v18; // ebp
  int v19; // esi
  int v20; // ebx
  int v21; // edi
  int v22; // ebp
  int v23; // edi
  int v24; // esi
  bool v25; // sf
  int v26; // [esp+0h] [ebp-C4h]
  int v27; // [esp+0h] [ebp-C4h]
  int v28; // [esp+4h] [ebp-C0h]
  int v29; // [esp+8h] [ebp-BCh]
  int v30; // [esp+Ch] [ebp-B8h]
  bn_recp_ctx_st recp; // [esp+10h] [ebp-B4h] BYREF
  bignum_st *y[32]; // [esp+44h] [ebp-80h]

  v30 = 0;
  if ( (p->flags & 4) != 0 )
  {
    ERR_put_error(a1, 3u, 125, 66, ".\\crypto\\bn\\bn_exp.c", 252);
    return -1;
  }
  v26 = BN_num_bits(p);
  if ( !v26 )
    return BN_set_word(a1, r->vals, 1u);
  v7 = ctx;
  BN_CTX_start(a1, ctx);
  v8 = BN_CTX_get(a1, ctx);
  v9 = BN_CTX_get((int)v8, ctx);
  v10 = v9;
  y[0] = (bignum_st *)v9;
  if ( v8 && v9 )
  {
    BN_RECP_CTX_init(&recp);
    if ( !m->neg )
    {
      v11 = BN_RECP_CTX_set(&recp, m);
      goto LABEL_11;
    }
    if ( BN_copy(v8->vals, m) )
    {
      v8->vals[0].neg = 0;
      v11 = BN_RECP_CTX_set(&recp, v8->vals);
LABEL_11:
      if ( v11 <= 0 || !BN_nnmod(v10->vals, a, m, ctx) )
        goto err_143;
      if ( !v10->vals[0].top )
      {
        BN_set_word((int)v8, r->vals, 0);
        v30 = 1;
        goto err_143;
      }
      v12 = v26;
      if ( v26 <= 671 )
      {
        if ( v26 <= 239 )
        {
          if ( v26 <= 79 )
          {
            v28 = 2 * (v26 > 23) + 1;
            if ( __OFSUB__(v28, 1) || v28 == 1 )
              goto LABEL_28;
          }
          else
          {
            v28 = 4;
          }
        }
        else
        {
          v28 = 5;
        }
      }
      else
      {
        v28 = 6;
      }
      if ( !BN_mod_mul_reciprocal(v8, v10, v10, (bignum_pool_item *)&recp, ctx) )
        goto err_143;
      v13 = 1 << (v28 - 1);
      v14 = 1;
      if ( v13 > 1 )
      {
        do
        {
          v15 = BN_CTX_get((int)v8, ctx);
          y[v14] = (bignum_st *)v15;
          if ( !v15
            || !BN_mod_mul_reciprocal(
                  v15,
                  *((bignum_pool_item **)&recp.flags + v14),
                  v8,
                  (bignum_pool_item *)&recp,
                  ctx) )
          {
            goto err_143;
          }
        }
        while ( ++v14 < v13 );
      }
      v12 = v26;
LABEL_28:
      v16 = r;
      v17 = v12 - 1;
      v27 = 1;
      v29 = v12 - 1;
      if ( BN_set_word((int)v8, r->vals, 1u) )
      {
        while ( 1 )
        {
          while ( !BN_is_bit_set(p, v17) )
          {
            if ( !v27 && !BN_mod_mul_reciprocal(v16, v16, v16, (bignum_pool_item *)&recp, v7) )
              goto err_143;
            if ( !v17 )
              goto LABEL_48;
            v29 = --v17;
          }
          v18 = 1;
          v19 = 1;
          v20 = 0;
          if ( v28 > 1 )
          {
            v21 = v17 - 1;
            do
            {
              if ( v21 < 0 )
                break;
              if ( BN_is_bit_set(p, v21) )
              {
                v22 = v18 << (v19 - v20);
                v20 = v19;
                v18 = v22 | 1;
              }
              ++v19;
              --v21;
            }
            while ( v19 < v28 );
          }
          v23 = v20 + 1;
          if ( !v27 )
          {
            v24 = 0;
            if ( v23 > 0 )
              break;
          }
LABEL_46:
          if ( !BN_mod_mul_reciprocal(r, r, (bignum_pool_item *)y[v18 >> 1], (bignum_pool_item *)&recp, ctx) )
            goto LABEL_49;
          v7 = ctx;
          v25 = -1 - v20 + v29 < 0;
          v29 += -1 - v20;
          v27 = 0;
          if ( v25 )
          {
LABEL_48:
            v30 = 1;
            goto err_143;
          }
          v16 = r;
          v17 = v29;
        }
        while ( BN_mod_mul_reciprocal(r, r, r, (bignum_pool_item *)&recp, ctx) )
        {
          if ( ++v24 >= v23 )
            goto LABEL_46;
        }
LABEL_49:
        v7 = ctx;
      }
    }
  }
err_143:
  BN_CTX_end(v7);
  BN_RECP_CTX_free(&recp);
  return v30;
}

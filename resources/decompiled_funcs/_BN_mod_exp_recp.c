int __cdecl BN_mod_exp_recp(bignum_st *r, const bignum_st *a, const bignum_st *p, const bignum_st *m, bignum_ctx *ctx)
{
  bignum_ctx *v6; // ebp
  bignum_pool_item *v7; // ebx
  bignum_pool_item *v8; // eax
  bignum_st *v9; // edi
  int v10; // eax
  int v11; // eax
  int v12; // edi
  int v13; // esi
  bignum_pool_item *v14; // eax
  bignum_st *v15; // esi
  int v16; // edi
  int v17; // ebp
  int v18; // esi
  int v19; // ebx
  int v20; // edi
  int v21; // ebp
  int v22; // edi
  int v23; // esi
  bool v24; // sf
  int v25; // [esp+0h] [ebp-C4h]
  int v26; // [esp+0h] [ebp-C4h]
  int v27; // [esp+4h] [ebp-C0h]
  int v28; // [esp+8h] [ebp-BCh]
  int v29; // [esp+Ch] [ebp-B8h]
  bn_recp_ctx_st recp; // [esp+10h] [ebp-B4h] BYREF
  bignum_st *y[32]; // [esp+44h] [ebp-80h]

  v29 = 0;
  if ( (p->flags & 4) != 0 )
  {
    ERR_put_error(3u, 125, 66, ".\\crypto\\bn\\bn_exp.c", 252);
    return -1;
  }
  v25 = BN_num_bits(p);
  if ( !v25 )
    return BN_set_word(r, 1u);
  v6 = ctx;
  BN_CTX_start(ctx);
  v7 = BN_CTX_get(ctx);
  v8 = BN_CTX_get(ctx);
  v9 = (bignum_st *)v8;
  y[0] = (bignum_st *)v8;
  if ( v7 && v8 )
  {
    BN_RECP_CTX_init(&recp);
    if ( !m->neg )
    {
      v10 = BN_RECP_CTX_set(&recp, m, ctx);
      goto LABEL_11;
    }
    if ( BN_copy(v7->vals, m) )
    {
      v7->vals[0].neg = 0;
      v10 = BN_RECP_CTX_set(&recp, v7->vals, ctx);
LABEL_11:
      if ( v10 <= 0 || !BN_nnmod(v9, a, m, ctx) )
        goto err_141;
      if ( !v9->top )
      {
        BN_set_word(r, 0);
        v29 = 1;
        goto err_141;
      }
      v11 = v25;
      if ( v25 <= 671 )
      {
        if ( v25 <= 239 )
        {
          if ( v25 <= 79 )
          {
            v27 = 2 * (v25 > 23) + 1;
            if ( __OFSUB__(v27, 1) || v27 == 1 )
              goto LABEL_28;
          }
          else
          {
            v27 = 4;
          }
        }
        else
        {
          v27 = 5;
        }
      }
      else
      {
        v27 = 6;
      }
      if ( !BN_mod_mul_reciprocal(v7->vals, v9, v9, &recp, ctx) )
        goto err_141;
      v12 = 1 << (v27 - 1);
      v13 = 1;
      if ( v12 > 1 )
      {
        do
        {
          v14 = BN_CTX_get(ctx);
          y[v13] = (bignum_st *)v14;
          if ( !v14 || !BN_mod_mul_reciprocal(v14->vals, *((const bignum_st **)&recp.flags + v13), v7->vals, &recp, ctx) )
            goto err_141;
        }
        while ( ++v13 < v12 );
      }
      v11 = v25;
LABEL_28:
      v15 = r;
      v16 = v11 - 1;
      v26 = 1;
      v28 = v11 - 1;
      if ( BN_set_word(r, 1u) )
      {
        while ( 1 )
        {
          while ( !BN_is_bit_set(p, v16) )
          {
            if ( !v26 && !BN_mod_mul_reciprocal(v15, v15, v15, &recp, v6) )
              goto err_141;
            if ( !v16 )
              goto LABEL_48;
            v28 = --v16;
          }
          v17 = 1;
          v18 = 1;
          v19 = 0;
          if ( v27 > 1 )
          {
            v20 = v16 - 1;
            do
            {
              if ( v20 < 0 )
                break;
              if ( BN_is_bit_set(p, v20) )
              {
                v21 = v17 << (v18 - v19);
                v19 = v18;
                v17 = v21 | 1;
              }
              ++v18;
              --v20;
            }
            while ( v18 < v27 );
          }
          v22 = v19 + 1;
          if ( !v26 )
          {
            v23 = 0;
            if ( v22 > 0 )
              break;
          }
LABEL_46:
          if ( !BN_mod_mul_reciprocal(r, r, y[v17 >> 1], &recp, ctx) )
            goto LABEL_49;
          v6 = ctx;
          v24 = -1 - v19 + v28 < 0;
          v28 += -1 - v19;
          v26 = 0;
          if ( v24 )
          {
LABEL_48:
            v29 = 1;
            goto err_141;
          }
          v15 = r;
          v16 = v28;
        }
        while ( BN_mod_mul_reciprocal(r, r, r, &recp, ctx) )
        {
          if ( ++v23 >= v22 )
            goto LABEL_46;
        }
LABEL_49:
        v6 = ctx;
      }
    }
  }
err_141:
  BN_CTX_end(v6);
  BN_RECP_CTX_free(&recp);
  return v29;
}

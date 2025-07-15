bignum_st *__usercall BN_mod_inverse_no_branch@<eax>(
        bignum_ctx *ctx@<ebx>,
        bignum_st *in,
        const bignum_st *a,
        const bignum_st *n)
{
  bignum_pool_item *v4; // esi
  bignum_pool_item *v5; // edi
  bignum_pool_item *v6; // ebp
  bignum_st *v7; // eax
  bignum_pool_item *v8; // ebp
  bignum_pool_item *v9; // edx
  int v10; // eax
  const bignum_st *v11; // edi
  bignum_st *v12; // eax
  bignum_ctx *v14; // [esp+0h] [ebp-54h]
  bignum_st *r; // [esp+10h] [ebp-44h]
  bignum_st *v16; // [esp+14h] [ebp-40h]
  bignum_pool_item *aa; // [esp+18h] [ebp-3Ch]
  bignum_pool_item *rm; // [esp+1Ch] [ebp-38h]
  int v19; // [esp+20h] [ebp-34h]
  bignum_pool_item *dv; // [esp+24h] [ebp-30h]
  bignum_st m; // [esp+2Ch] [ebp-28h] BYREF
  bignum_st num; // [esp+40h] [ebp-14h] BYREF

  r = 0;
  BN_CTX_start((int)ctx, v14);
  v4 = BN_CTX_get((int)ctx, ctx);
  v5 = BN_CTX_get((int)ctx, ctx);
  aa = BN_CTX_get((int)ctx, ctx);
  dv = BN_CTX_get((int)ctx, ctx);
  rm = BN_CTX_get((int)ctx, ctx);
  v6 = BN_CTX_get((int)ctx, ctx);
  v16 = (bignum_st *)v6;
  if ( BN_CTX_get((int)ctx, ctx) )
  {
    v7 = in;
    if ( !in )
      v7 = BN_new((int)ctx);
    r = v7;
    if ( v7 )
    {
      BN_set_word((int)ctx, aa->vals, 1u);
      BN_set_word((int)ctx, v6->vals, 0);
      if ( BN_copy(v5->vals, a) )
      {
        if ( BN_copy(v4->vals, n) )
        {
          if ( (v4->vals[0].neg = 0, !v5->vals[0].neg) && BN_ucmp(v5->vals, v4->vals) < 0
            || (m.d = v5->vals[0].d,
                m.top = v5->vals[0].top,
                m.dmax = v5->vals[0].dmax,
                m.neg = v5->vals[0].neg,
                m.flags = m.flags & 1 | v5->vals[0].flags & 0xFFFFFFFE | 6,
                BN_nnmod(v5->vals, &m, v4->vals, ctx)) )
          {
            v19 = -1;
            if ( v5->vals[0].top )
            {
              while ( 1 )
              {
                num.d = v4->vals[0].d;
                num.top = v4->vals[0].top;
                num.dmax = v4->vals[0].dmax;
                num.neg = v4->vals[0].neg;
                num.flags = num.flags & 1 | v4->vals[0].flags & 0xFFFFFFFE | 6;
                if ( !BN_div(dv, rm->vals, &num, v5->vals, ctx) )
                  break;
                v8 = v4;
                v4 = v5;
                v5 = rm;
                if ( !BN_mul(v8, dv, aa, ctx) || !BN_add(v8->vals, v8->vals, v16) )
                  break;
                v9 = aa;
                v10 = -v19;
                rm = (bignum_pool_item *)v16;
                v16 = (bignum_st *)aa;
                aa = v8;
                v19 = -v19;
                if ( !v5->vals[0].top )
                {
                  v6 = v9;
                  if ( v10 < 0 )
                    goto LABEL_16;
                  v11 = n;
                  goto LABEL_19;
                }
              }
            }
            else
            {
LABEL_16:
              v11 = n;
              if ( BN_sub(v6->vals, n, v6->vals) )
              {
LABEL_19:
                if ( v4->vals[0].top == 1 && *v4->vals[0].d == 1 && !v4->vals[0].neg )
                {
                  if ( v6->vals[0].neg || BN_ucmp(v6->vals, v11) >= 0 )
                    v12 = (bignum_st *)BN_nnmod(r, v6->vals, v11, ctx);
                  else
                    v12 = BN_copy(r, v6->vals);
                  if ( v12 )
                  {
                    BN_CTX_end(ctx);
                    return r;
                  }
                }
                else
                {
                  ERR_put_error((int)ctx, 3u, 139, 108, ".\\crypto\\bn\\bn_gcd.c", 645);
                }
              }
            }
          }
        }
      }
    }
  }
  if ( !in )
    BN_free(r);
  BN_CTX_end(ctx);
  return 0;
}

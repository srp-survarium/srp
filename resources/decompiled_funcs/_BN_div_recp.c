int __cdecl BN_div_recp(
        bignum_pool_item *dv,
        bignum_pool_item *rem,
        const bignum_st *m,
        bignum_pool_item *recp,
        bignum_ctx *ctx)
{
  bignum_ctx *v5; // edi
  bignum_pool_item *v6; // esi
  bignum_pool_item *v7; // ebp
  bignum_pool_item *v8; // eax
  bignum_pool_item *v9; // ebx
  int result; // eax
  int v11; // edi
  int v12; // edi
  int v13; // ecx
  int neg; // eax
  int v15; // [esp+14h] [ebp-4h]
  bignum_pool_item *v16; // [esp+1Ch] [ebp+4h]

  v5 = ctx;
  v15 = 0;
  BN_CTX_start(ctx);
  v6 = BN_CTX_get(ctx);
  v7 = BN_CTX_get(ctx);
  v8 = dv;
  if ( !dv )
    v8 = BN_CTX_get(ctx);
  v9 = rem;
  v16 = v8;
  if ( !rem )
    v9 = BN_CTX_get(ctx);
  if ( !v6 || !v7 || !v16 || !v9 )
  {
err_188:
    BN_CTX_end(v5);
    return v15;
  }
  if ( BN_ucmp(m, recp->vals) >= 0 )
  {
    v11 = BN_num_bits(m);
    if ( 2 * (int)recp->vals[2].d > v11 )
      v11 = 2 * (int)recp->vals[2].d;
    if ( v11 != recp->vals[2].top )
      recp->vals[2].top = BN_reciprocal((bignum_pool_item *)&recp->vals[1], recp->vals, v11, ctx);
    if ( recp->vals[2].top != -1 )
    {
      if ( BN_rshift(v6->vals, m, (int)recp->vals[2].d) )
      {
        if ( BN_mul(v7, v6, (bignum_pool_item *)&recp->vals[1], ctx) )
        {
          if ( BN_rshift(v16->vals, v7->vals, v11 - (unsigned int)recp->vals[2].d) )
          {
            v16->vals[0].neg = 0;
            if ( BN_mul(v7, recp, v16, ctx) )
            {
              if ( BN_usub(v9->vals, m, v7->vals) )
              {
                v12 = 0;
                v9->vals[0].neg = 0;
                if ( BN_ucmp(v9->vals, recp->vals) < 0 )
                {
LABEL_27:
                  if ( v9->vals[0].top )
                    neg = m->neg;
                  else
                    neg = 0;
                  v9->vals[0].neg = neg;
                  v15 = 1;
                  v16->vals[0].neg = recp->vals[0].neg ^ m->neg;
                }
                else
                {
                  while ( 1 )
                  {
                    v13 = v12++;
                    if ( v13 > 2 )
                      break;
                    if ( !BN_usub(v9->vals, v9->vals, recp->vals) || !BN_add_word(v16->vals, 1u) )
                      goto LABEL_32;
                    if ( BN_ucmp(v9->vals, recp->vals) < 0 )
                      goto LABEL_27;
                  }
                  ERR_put_error(3u, 130, 101, ".\\crypto\\bn\\bn_recp.c", 194);
                }
              }
            }
          }
        }
      }
    }
LABEL_32:
    v5 = ctx;
    goto err_188;
  }
  BN_set_word(v16->vals, 0);
  result = (int)BN_copy(v9->vals, m);
  if ( result )
  {
    BN_CTX_end(ctx);
    return 1;
  }
  return result;
}

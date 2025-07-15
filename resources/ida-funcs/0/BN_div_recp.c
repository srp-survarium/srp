int __usercall BN_div_recp@<eax>(
        int a1@<ebx>,
        bignum_pool_item *dv,
        bignum_pool_item *rem,
        const bignum_st *m,
        bignum_pool_item *recp,
        bignum_ctx *ctx)
{
  bignum_ctx *v6; // edi
  bignum_pool_item *v7; // esi
  bignum_pool_item *v8; // ebp
  bignum_pool_item *v9; // eax
  bignum_pool_item *v10; // ebx
  int result; // eax
  int v12; // edi
  int v13; // edi
  int v14; // ecx
  int neg; // eax
  int v16; // [esp+14h] [ebp-4h]
  bignum_pool_item *v17; // [esp+1Ch] [ebp+4h]

  v6 = ctx;
  v16 = 0;
  BN_CTX_start(a1, ctx);
  v7 = BN_CTX_get(a1, ctx);
  v8 = BN_CTX_get(a1, ctx);
  v9 = dv;
  if ( !dv )
    v9 = BN_CTX_get(a1, ctx);
  v10 = rem;
  v17 = v9;
  if ( !rem )
    v10 = BN_CTX_get(0, ctx);
  if ( !v7 || !v8 || !v17 || !v10 )
  {
err_190:
    BN_CTX_end(v6);
    return v16;
  }
  if ( BN_ucmp(m, recp->vals) >= 0 )
  {
    v12 = BN_num_bits(m);
    if ( 2 * (int)recp->vals[2].d > v12 )
      v12 = 2 * (int)recp->vals[2].d;
    if ( v12 != recp->vals[2].top )
      recp->vals[2].top = BN_reciprocal((bignum_pool_item *)&recp->vals[1], recp->vals, v12, ctx);
    if ( recp->vals[2].top != -1 )
    {
      if ( BN_rshift(v7->vals, m, (int)recp->vals[2].d) )
      {
        if ( BN_mul(v8, v7, (bignum_pool_item *)&recp->vals[1], ctx) )
        {
          if ( BN_rshift(v17->vals, v8->vals, v12 - (unsigned int)recp->vals[2].d) )
          {
            v17->vals[0].neg = 0;
            if ( BN_mul(v8, recp, v17, ctx) )
            {
              if ( BN_usub(v10->vals, m, v8->vals) )
              {
                v13 = 0;
                v10->vals[0].neg = 0;
                if ( BN_ucmp(v10->vals, recp->vals) < 0 )
                {
LABEL_27:
                  if ( v10->vals[0].top )
                    neg = m->neg;
                  else
                    neg = 0;
                  v10->vals[0].neg = neg;
                  v16 = 1;
                  v17->vals[0].neg = recp->vals[0].neg ^ m->neg;
                }
                else
                {
                  while ( 1 )
                  {
                    v14 = v13++;
                    if ( v14 > 2 )
                      break;
                    if ( !BN_usub(v10->vals, v10->vals, recp->vals) || !BN_add_word((int)v10, v17->vals, 1u) )
                      goto LABEL_32;
                    if ( BN_ucmp(v10->vals, recp->vals) < 0 )
                      goto LABEL_27;
                  }
                  ERR_put_error((int)v10, 3u, 130, 101, ".\\crypto\\bn\\bn_recp.c", 194);
                }
              }
            }
          }
        }
      }
    }
LABEL_32:
    v6 = ctx;
    goto err_190;
  }
  BN_set_word((int)v10, v17->vals, 0);
  result = (int)BN_copy(v10->vals, m);
  if ( result )
  {
    BN_CTX_end(ctx);
    return 1;
  }
  return result;
}

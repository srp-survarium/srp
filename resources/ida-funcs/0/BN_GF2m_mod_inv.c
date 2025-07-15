int __cdecl BN_GF2m_mod_inv(bignum_st *r, const bignum_st *a, const bignum_st *p, bignum_ctx *ctx)
{
  bignum_ctx *v4; // ebx
  bignum_pool_item *v5; // edi
  bignum_pool_item *v6; // esi
  bignum_pool_item *v7; // ebp
  int top; // eax
  bool v9; // zf
  int v10; // ebx
  bignum_pool_item *v11; // eax
  bignum_pool_item *v12; // eax
  bignum_pool_item *v14; // [esp+10h] [ebp-8h]

  v4 = ctx;
  BN_CTX_start((int)ctx, ctx);
  v5 = BN_CTX_get((int)v4, v4);
  v14 = BN_CTX_get((int)v4, v4);
  v6 = BN_CTX_get((int)v4, v4);
  v7 = BN_CTX_get((int)v4, v4);
  if ( !v7
    || !BN_set_word((int)ctx, v5->vals, 1u)
    || !BN_GF2m_mod(v6->vals, a, p)
    || !BN_copy(v7->vals, p)
    || !v6->vals[0].top )
  {
err_176:
    BN_CTX_end(v4);
    return 0;
  }
  while ( 1 )
  {
    while ( 1 )
    {
      top = v6->vals[0].top;
      v9 = top == 0;
      if ( top > 0 )
        break;
LABEL_9:
      if ( v9
        || !BN_rshift1(v6->vals, v6->vals)
        || v5->vals[0].top > 0 && (*(_BYTE *)v5->vals[0].d & 1) != 0 && !BN_GF2m_add(v5->vals, v5->vals, p)
        || !BN_rshift1(v5->vals, v5->vals) )
      {
        goto err_176;
      }
    }
    if ( (*(_BYTE *)v6->vals[0].d & 1) == 0 )
    {
      v9 = top == 0;
      goto LABEL_9;
    }
    if ( top == 1 && *v6->vals[0].d == 1 )
      break;
    v10 = BN_num_bits(v7->vals);
    if ( BN_num_bits(v6->vals) < v10 )
    {
      v11 = v6;
      v6 = v7;
      v7 = v11;
      v12 = v5;
      v5 = v14;
      v14 = v12;
    }
    if ( !BN_GF2m_add(v6->vals, v6->vals, v7->vals) || !BN_GF2m_add(v5->vals, v5->vals, v14->vals) )
    {
      v4 = ctx;
      goto err_176;
    }
    v4 = ctx;
  }
  if ( !BN_copy(r, v5->vals) )
    goto err_176;
  BN_CTX_end(v4);
  return 1;
}

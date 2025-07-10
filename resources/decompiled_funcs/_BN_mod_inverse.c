bignum_st *__cdecl BN_mod_inverse(bignum_st *in, const bignum_st *a, const bignum_st *n, bignum_ctx *ctx)
{
  bignum_pool_item *v4; // edi
  bignum_pool_item *v5; // ebx
  bignum_pool_item *v6; // ebp
  bignum_st *v7; // eax
  int v8; // ebx
  int v9; // ebx
  int v10; // eax
  int v11; // esi
  int v12; // eax
  bignum_st *v13; // esi
  int v14; // eax
  bignum_st *v15; // eax
  int v16; // ecx
  bignum_st *v17; // eax
  bignum_pool_item *d; // [esp+4h] [ebp-1Ch]
  bignum_pool_item *r; // [esp+8h] [ebp-18h]
  bignum_pool_item *aa; // [esp+Ch] [ebp-14h]
  bignum_st *v22; // [esp+10h] [ebp-10h]
  bignum_pool_item *v23; // [esp+14h] [ebp-Ch]
  bignum_st *v24; // [esp+18h] [ebp-8h]
  int v25; // [esp+1Ch] [ebp-4h]
  int b; // [esp+28h] [ebp+8h]

  v22 = 0;
  v24 = 0;
  if ( (a->flags & 4) != 0 || (n->flags & 4) != 0 )
    return BN_mod_inverse_no_branch(ctx, in, a, n);
  BN_CTX_start(ctx);
  d = BN_CTX_get(ctx);
  v4 = BN_CTX_get(ctx);
  aa = BN_CTX_get(ctx);
  v5 = BN_CTX_get(ctx);
  v6 = BN_CTX_get(ctx);
  r = BN_CTX_get(ctx);
  v23 = BN_CTX_get(ctx);
  v7 = in;
  if ( !v23 )
    goto LABEL_86;
  if ( !in )
    v7 = BN_new();
  v22 = v7;
  if ( !v7 )
    goto LABEL_86;
  BN_set_word(aa->vals, 1u);
  BN_set_word(r->vals, 0);
  if ( !BN_copy(v4->vals, a) || !BN_copy(d->vals, n) )
    goto LABEL_86;
  d->vals[0].neg = 0;
  if ( (v4->vals[0].neg || BN_ucmp(v4->vals, d->vals) >= 0) && !BN_nnmod(v4->vals, v4->vals, d->vals, ctx) )
    goto LABEL_86;
  b = -1;
  if ( n->top > 0 && (*(_BYTE *)n->d & 1) != 0 && BN_num_bits(n) <= 2048 )
  {
    if ( !v4->vals[0].top )
      goto LABEL_75;
    while ( 1 )
    {
      v8 = 0;
      if ( !BN_is_bit_set(v4->vals, 0) )
        break;
LABEL_24:
      v9 = 0;
      if ( !BN_is_bit_set(d->vals, 0) )
      {
        while ( 1 )
        {
          ++v9;
          if ( r->vals[0].top > 0 && (*(_BYTE *)r->vals[0].d & 1) != 0 && !BN_uadd(r->vals, r->vals, n) )
            goto LABEL_86;
          if ( !BN_rshift1(r->vals, r->vals) )
            goto LABEL_86;
          if ( BN_is_bit_set(d->vals, v9) )
          {
            if ( v9 > 0 && !BN_rshift(d->vals, d->vals, v9) )
              goto LABEL_86;
            break;
          }
        }
      }
      if ( BN_ucmp(v4->vals, d->vals) < 0 )
      {
        if ( !BN_uadd(r->vals, r->vals, aa->vals) )
          goto LABEL_86;
        v10 = BN_usub(d->vals, d->vals, v4->vals);
      }
      else
      {
        if ( !BN_uadd(aa->vals, aa->vals, r->vals) )
          goto LABEL_86;
        v10 = BN_usub(v4->vals, v4->vals, d->vals);
      }
      if ( !v10 )
        goto LABEL_86;
      if ( !v4->vals[0].top )
        goto LABEL_75;
    }
    while ( 1 )
    {
      ++v8;
      if ( aa->vals[0].top > 0 && (*(_BYTE *)aa->vals[0].d & 1) != 0 && !BN_uadd(aa->vals, aa->vals, n) )
        goto LABEL_86;
      if ( !BN_rshift1(aa->vals, aa->vals) )
        goto LABEL_86;
      if ( BN_is_bit_set(v4->vals, v8) )
      {
        if ( v8 > 0 && !BN_rshift(v4->vals, v4->vals, v8) )
          goto LABEL_86;
        goto LABEL_24;
      }
    }
  }
  if ( !v4->vals[0].top )
    goto LABEL_75;
  do
  {
    v11 = BN_num_bits(v4->vals);
    if ( BN_num_bits(d->vals) == v11 )
    {
      if ( !BN_set_word(v5->vals, 1u) )
        goto LABEL_86;
LABEL_43:
      v12 = BN_sub(v6->vals, d->vals, v4->vals);
      goto LABEL_56;
    }
    v25 = BN_num_bits(v4->vals) + 1;
    if ( BN_num_bits(d->vals) == v25 )
    {
      if ( !BN_lshift1(v23->vals, v4->vals) )
        goto LABEL_86;
      if ( BN_ucmp(d->vals, v23->vals) < 0 )
      {
        if ( !BN_set_word(v5->vals, 1u) )
          goto LABEL_86;
        goto LABEL_43;
      }
      if ( !BN_sub(v6->vals, d->vals, v23->vals) || !BN_add(v5->vals, v23->vals, v4->vals) )
        goto LABEL_86;
      if ( BN_ucmp(d->vals, v5->vals) >= 0 )
      {
        if ( !BN_set_word(v5->vals, 3u) )
          goto LABEL_86;
        v12 = BN_sub(v6->vals, v6->vals, v4->vals);
      }
      else
      {
        v12 = BN_set_word(v5->vals, 2u);
      }
    }
    else
    {
      v12 = BN_div(v5->vals, v6->vals, d->vals, v4->vals, ctx);
    }
LABEL_56:
    if ( !v12 )
      goto LABEL_86;
    v13 = (bignum_st *)d;
    d = v4;
    v4 = v6;
    if ( v5->vals[0].top == 1 )
    {
      if ( *v5->vals[0].d == 1 && !v5->vals[0].neg )
      {
        v14 = BN_add(v13, aa->vals, r->vals);
        goto LABEL_72;
      }
      if ( *v5->vals[0].d != 2 || v5->vals[0].neg )
      {
        if ( *v5->vals[0].d != 4 || v5->vals[0].neg )
        {
          if ( !BN_copy(v13, aa->vals) )
            goto LABEL_86;
          v15 = (bignum_st *)BN_mul_word(v13, *v5->vals[0].d);
        }
        else
        {
          v15 = BN_lshift(v13, aa->vals, 2);
        }
      }
      else
      {
        v15 = (bignum_st *)BN_lshift1(v13, aa->vals);
      }
    }
    else
    {
      v15 = (bignum_st *)BN_mul(v13, v5->vals, aa->vals, ctx);
    }
    if ( !v15 )
      goto LABEL_86;
    v14 = BN_add(v13, v13, r->vals);
LABEL_72:
    if ( !v14 )
      goto LABEL_86;
    v6 = r;
    v16 = -b;
    r = aa;
    aa = (bignum_pool_item *)v13;
    b = -b;
  }
  while ( v4->vals[0].top );
  if ( v16 < 0 )
  {
LABEL_75:
    if ( BN_sub(r->vals, n, r->vals) )
      goto LABEL_76;
    goto LABEL_86;
  }
LABEL_76:
  if ( d->vals[0].top != 1 || *d->vals[0].d != 1 || d->vals[0].neg )
  {
    ERR_put_error(3u, 110, 108, ".\\crypto\\bn\\bn_gcd.c", 491);
    goto LABEL_86;
  }
  if ( r->vals[0].neg || BN_ucmp(r->vals, n) >= 0 )
    v17 = (bignum_st *)BN_nnmod(v22, r->vals, n, ctx);
  else
    v17 = BN_copy(v22, r->vals);
  if ( v17 )
  {
    v24 = v22;
  }
  else
  {
LABEL_86:
    if ( !in )
      BN_free(v22);
  }
  BN_CTX_end(ctx);
  return v24;
}

bignum_st *__usercall BN_mod_inverse@<eax>(
        int a1@<ebx>,
        bignum_st *in,
        const bignum_st *a,
        const bignum_st *n,
        bignum_ctx *ctx)
{
  bignum_pool_item *v5; // edi
  bignum_pool_item *v6; // ebx
  bignum_pool_item *v7; // ebp
  bignum_st *v8; // eax
  int v9; // ebx
  int v10; // ebx
  int v11; // eax
  int v12; // esi
  int v13; // eax
  bignum_pool_item *v14; // esi
  int v15; // eax
  bignum_st *v16; // eax
  int v17; // ecx
  bignum_st *v18; // eax
  bignum_pool_item *d; // [esp+4h] [ebp-1Ch]
  bignum_pool_item *r; // [esp+8h] [ebp-18h]
  bignum_pool_item *aa; // [esp+Ch] [ebp-14h]
  bignum_st *v23; // [esp+10h] [ebp-10h]
  bignum_pool_item *v24; // [esp+14h] [ebp-Ch]
  bignum_st *v25; // [esp+18h] [ebp-8h]
  int v26; // [esp+1Ch] [ebp-4h]
  int b; // [esp+28h] [ebp+8h]

  v23 = 0;
  v25 = 0;
  if ( (a->flags & 4) != 0 || (n->flags & 4) != 0 )
    return BN_mod_inverse_no_branch(ctx, in, a, n);
  BN_CTX_start(a1, ctx);
  d = BN_CTX_get(a1, ctx);
  v5 = BN_CTX_get(a1, ctx);
  aa = BN_CTX_get(a1, ctx);
  v6 = BN_CTX_get(a1, ctx);
  v7 = BN_CTX_get((int)v6, ctx);
  r = BN_CTX_get((int)v6, ctx);
  v24 = BN_CTX_get((int)v6, ctx);
  v8 = in;
  if ( !v24 )
    goto LABEL_86;
  if ( !in )
    v8 = BN_new((int)v6);
  v23 = v8;
  if ( !v8 )
    goto LABEL_86;
  BN_set_word((int)v6, aa->vals, 1u);
  BN_set_word((int)v6, r->vals, 0);
  if ( !BN_copy(v5->vals, a) || !BN_copy(d->vals, n) )
    goto LABEL_86;
  d->vals[0].neg = 0;
  if ( (v5->vals[0].neg || BN_ucmp(v5->vals, d->vals) >= 0) && !BN_nnmod(v5->vals, v5->vals, d->vals, ctx) )
    goto LABEL_86;
  b = -1;
  if ( n->top > 0 && (*(_BYTE *)n->d & 1) != 0 && BN_num_bits(n) <= 2048 )
  {
    if ( !v5->vals[0].top )
      goto LABEL_75;
    while ( 1 )
    {
      v9 = 0;
      if ( !BN_is_bit_set(v5->vals, 0) )
        break;
LABEL_24:
      v10 = 0;
      if ( !BN_is_bit_set(d->vals, 0) )
      {
        while ( 1 )
        {
          ++v10;
          if ( r->vals[0].top > 0 && (*(_BYTE *)r->vals[0].d & 1) != 0 && !BN_uadd(r->vals, r->vals, n) )
            goto LABEL_86;
          if ( !BN_rshift1(r->vals, r->vals) )
            goto LABEL_86;
          if ( BN_is_bit_set(d->vals, v10) )
          {
            if ( v10 > 0 && !BN_rshift(d->vals, d->vals, v10) )
              goto LABEL_86;
            break;
          }
        }
      }
      v6 = d;
      if ( BN_ucmp(v5->vals, d->vals) < 0 )
      {
        if ( !BN_uadd(r->vals, r->vals, aa->vals) )
          goto LABEL_86;
        v11 = BN_usub(d->vals, d->vals, v5->vals);
      }
      else
      {
        if ( !BN_uadd(aa->vals, aa->vals, r->vals) )
          goto LABEL_86;
        v11 = BN_usub(v5->vals, v5->vals, d->vals);
      }
      if ( !v11 )
        goto LABEL_86;
      if ( !v5->vals[0].top )
        goto LABEL_75;
    }
    while ( 1 )
    {
      ++v9;
      if ( aa->vals[0].top > 0 && (*(_BYTE *)aa->vals[0].d & 1) != 0 && !BN_uadd(aa->vals, aa->vals, n) )
        goto LABEL_86;
      if ( !BN_rshift1(aa->vals, aa->vals) )
        goto LABEL_86;
      if ( BN_is_bit_set(v5->vals, v9) )
      {
        if ( v9 > 0 && !BN_rshift(v5->vals, v5->vals, v9) )
          goto LABEL_86;
        goto LABEL_24;
      }
    }
  }
  if ( !v5->vals[0].top )
    goto LABEL_75;
  do
  {
    v12 = BN_num_bits(v5->vals);
    if ( BN_num_bits(d->vals) == v12 )
    {
      if ( !BN_set_word((int)v6, v6->vals, 1u) )
        goto LABEL_86;
LABEL_43:
      v13 = BN_sub(v7->vals, d->vals, v5->vals);
      goto LABEL_56;
    }
    v26 = BN_num_bits(v5->vals) + 1;
    if ( BN_num_bits(d->vals) == v26 )
    {
      if ( !BN_lshift1(v24->vals, v5->vals) )
        goto LABEL_86;
      if ( BN_ucmp(d->vals, v24->vals) < 0 )
      {
        if ( !BN_set_word((int)v6, v6->vals, 1u) )
          goto LABEL_86;
        goto LABEL_43;
      }
      if ( !BN_sub(v7->vals, d->vals, v24->vals) || !BN_add(v6->vals, v24->vals, v5->vals) )
        goto LABEL_86;
      if ( BN_ucmp(d->vals, v6->vals) >= 0 )
      {
        if ( !BN_set_word((int)v6, v6->vals, 3u) )
          goto LABEL_86;
        v13 = BN_sub(v7->vals, v7->vals, v5->vals);
      }
      else
      {
        v13 = BN_set_word((int)v6, v6->vals, 2u);
      }
    }
    else
    {
      v13 = BN_div(v6, v7->vals, d->vals, v5->vals, ctx);
    }
LABEL_56:
    if ( !v13 )
      goto LABEL_86;
    v14 = d;
    d = v5;
    v5 = v7;
    if ( v6->vals[0].top == 1 )
    {
      if ( *v6->vals[0].d == 1 && !v6->vals[0].neg )
      {
        v15 = BN_add(v14->vals, aa->vals, r->vals);
        goto LABEL_72;
      }
      if ( *v6->vals[0].d != 2 || v6->vals[0].neg )
      {
        if ( *v6->vals[0].d != 4 || v6->vals[0].neg )
        {
          if ( !BN_copy(v14->vals, aa->vals) )
            goto LABEL_86;
          v16 = (bignum_st *)BN_mul_word((int)v6, v14->vals, *v6->vals[0].d);
        }
        else
        {
          v16 = BN_lshift(v14->vals, aa->vals, 2);
        }
      }
      else
      {
        v16 = (bignum_st *)BN_lshift1(v14->vals, aa->vals);
      }
    }
    else
    {
      v16 = (bignum_st *)BN_mul(v14, v6, aa, ctx);
    }
    if ( !v16 )
      goto LABEL_86;
    v15 = BN_add(v14->vals, v14->vals, r->vals);
LABEL_72:
    if ( !v15 )
      goto LABEL_86;
    v7 = r;
    v17 = -b;
    r = aa;
    aa = v14;
    b = -b;
  }
  while ( v5->vals[0].top );
  if ( v17 < 0 )
  {
LABEL_75:
    if ( BN_sub(r->vals, n, r->vals) )
      goto LABEL_76;
    goto LABEL_86;
  }
LABEL_76:
  if ( d->vals[0].top != 1 || *d->vals[0].d != 1 || d->vals[0].neg )
  {
    ERR_put_error((int)v6, 3u, 110, 108, ".\\crypto\\bn\\bn_gcd.c", 491);
    goto LABEL_86;
  }
  if ( r->vals[0].neg || BN_ucmp(r->vals, n) >= 0 )
    v18 = (bignum_st *)BN_nnmod(v23, r->vals, n, ctx);
  else
    v18 = BN_copy(v23, r->vals);
  if ( v18 )
  {
    v25 = v23;
  }
  else
  {
LABEL_86:
    if ( !in )
      BN_free(v23);
  }
  BN_CTX_end(ctx);
  return v25;
}

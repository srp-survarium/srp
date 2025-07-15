int __cdecl BN_kronecker(const bignum_st *a, const bignum_st *b, bignum_ctx *ctx)
{
  int v4; // esi
  bignum_pool_item *v5; // edi
  bignum_pool_item *v6; // ebp
  int v7; // ebx
  bignum_st *v8; // eax
  bignum_st *v9; // eax
  int top; // eax
  int v11; // eax
  int i; // ebx
  int v13; // eax
  unsigned int v14; // eax
  int v15; // eax
  unsigned int v16; // ecx
  int v17; // eax
  bignum_pool_item *v18; // eax
  int result; // eax
  int v20; // [esp+10h] [ebp-4h]

  v20 = -2;
  v4 = 0;
  BN_CTX_start((int)ctx, ctx);
  v5 = BN_CTX_get((int)ctx, ctx);
  v6 = BN_CTX_get((int)ctx, ctx);
  v7 = 0;
  if ( !v6 )
    goto end_11;
  v8 = BN_copy(v5->vals, a);
  v4 = v8 == 0;
  if ( !v8 )
    goto end_11;
  v9 = BN_copy(v6->vals, b);
  v4 = v9 == 0;
  if ( !v9 )
    goto end_11;
  top = v6->vals[0].top;
  if ( !top )
  {
    if ( v5->vals[0].top == 1 && *v5->vals[0].d == 1 )
    {
      v20 = 1;
      goto end_11;
    }
    goto LABEL_50;
  }
  if ( (v5->vals[0].top <= 0 || (*(_BYTE *)v5->vals[0].d & 1) == 0) && (top <= 0 || (*(_BYTE *)v6->vals[0].d & 1) == 0) )
  {
LABEL_50:
    v20 = 0;
    goto end_11;
  }
  if ( !BN_is_bit_set(v6->vals, 0) )
  {
    do
      ++v7;
    while ( !BN_is_bit_set(v6->vals, v7) );
  }
  v11 = BN_rshift(v6->vals, v6->vals, v7);
  v4 = v11 == 0;
  if ( v11 )
  {
    if ( (v7 & 1) != 0 )
    {
      if ( v5->vals[0].top == v4 )
        v20 = tab[0];
      else
        v20 = tab[*v5->vals[0].d & 7];
    }
    else
    {
      v20 = 1;
    }
    if ( v6->vals[0].neg )
    {
      v6->vals[0].neg = 0;
      if ( v5->vals[0].neg )
        v20 = -v20;
    }
    if ( v5->vals[0].top )
    {
      while ( 1 )
      {
        for ( i = 0; !BN_is_bit_set(v5->vals, i); ++i )
          ;
        v13 = BN_rshift(v5->vals, v5->vals, i);
        v4 = v13 == 0;
        if ( !v13 )
          break;
        if ( (i & 1) != 0 )
        {
          if ( v6->vals[0].top == v4 )
            LOBYTE(v14) = 0;
          else
            v14 = *v6->vals[0].d;
          v20 *= tab[v14 & 7];
        }
        if ( v5->vals[0].neg )
        {
          if ( v5->vals[0].top )
            v15 = ~*v5->vals[0].d;
          else
            LOBYTE(v15) = -1;
        }
        else if ( v5->vals[0].top )
        {
          v15 = *v5->vals[0].d;
        }
        else
        {
          LOBYTE(v15) = 0;
        }
        if ( v6->vals[0].top )
          v16 = *v6->vals[0].d;
        else
          LOBYTE(v16) = 0;
        if ( ((unsigned __int8)v15 & (unsigned __int8)v16 & 2) != 0 )
          v20 = -v20;
        v17 = BN_nnmod(i, v6->vals, v6->vals, v5->vals, ctx);
        v4 = v17 == 0;
        if ( !v17 )
          break;
        v18 = v5;
        v5 = v6;
        v18->vals[0].neg = v4;
        v6 = v18;
        if ( v5->vals[0].top == v4 )
          goto LABEL_46;
      }
    }
    else
    {
LABEL_46:
      if ( v6->vals[0].top != 1 || *v6->vals[0].d != 1 || v6->vals[0].neg )
        v20 = 0;
    }
  }
end_11:
  BN_CTX_end(ctx);
  result = -2;
  if ( !v4 )
    return v20;
  return result;
}

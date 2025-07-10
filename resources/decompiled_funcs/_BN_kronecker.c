int __cdecl BN_kronecker(const bignum_st *a, const bignum_st *b, bignum_ctx *ctx)
{
  int v3; // esi
  bignum_pool_item *v4; // edi
  bignum_pool_item *v5; // ebp
  int v6; // ebx
  bignum_st *v7; // eax
  bignum_st *v8; // eax
  int top; // eax
  int v10; // eax
  int i; // ebx
  int v12; // eax
  unsigned int v13; // eax
  int v14; // eax
  unsigned int v15; // ecx
  int v16; // eax
  bignum_pool_item *v17; // eax
  int result; // eax
  int v19; // [esp+10h] [ebp-4h]

  v19 = -2;
  v3 = 0;
  BN_CTX_start(ctx);
  v4 = BN_CTX_get(ctx);
  v5 = BN_CTX_get(ctx);
  v6 = 0;
  if ( !v5 )
    goto end_11;
  v7 = BN_copy(v4->vals, a);
  v3 = v7 == 0;
  if ( !v7 )
    goto end_11;
  v8 = BN_copy(v5->vals, b);
  v3 = v8 == 0;
  if ( !v8 )
    goto end_11;
  top = v5->vals[0].top;
  if ( !top )
  {
    if ( v4->vals[0].top == 1 && *v4->vals[0].d == 1 )
    {
      v19 = 1;
      goto end_11;
    }
    goto LABEL_50;
  }
  if ( (v4->vals[0].top <= 0 || (*(_BYTE *)v4->vals[0].d & 1) == 0) && (top <= 0 || (*(_BYTE *)v5->vals[0].d & 1) == 0) )
  {
LABEL_50:
    v19 = 0;
    goto end_11;
  }
  if ( !BN_is_bit_set(v5->vals, 0) )
  {
    do
      ++v6;
    while ( !BN_is_bit_set(v5->vals, v6) );
  }
  v10 = BN_rshift(v5->vals, v5->vals, v6);
  v3 = v10 == 0;
  if ( v10 )
  {
    if ( (v6 & 1) != 0 )
    {
      if ( v4->vals[0].top == v3 )
        v19 = tab[0];
      else
        v19 = tab[*v4->vals[0].d & 7];
    }
    else
    {
      v19 = 1;
    }
    if ( v5->vals[0].neg )
    {
      v5->vals[0].neg = 0;
      if ( v4->vals[0].neg )
        v19 = -v19;
    }
    if ( v4->vals[0].top )
    {
      while ( 1 )
      {
        for ( i = 0; !BN_is_bit_set(v4->vals, i); ++i )
          ;
        v12 = BN_rshift(v4->vals, v4->vals, i);
        v3 = v12 == 0;
        if ( !v12 )
          break;
        if ( (i & 1) != 0 )
        {
          if ( v5->vals[0].top == v3 )
            LOBYTE(v13) = 0;
          else
            v13 = *v5->vals[0].d;
          v19 *= tab[v13 & 7];
        }
        if ( v4->vals[0].neg )
        {
          if ( v4->vals[0].top )
            v14 = ~*v4->vals[0].d;
          else
            LOBYTE(v14) = -1;
        }
        else if ( v4->vals[0].top )
        {
          v14 = *v4->vals[0].d;
        }
        else
        {
          LOBYTE(v14) = 0;
        }
        if ( v5->vals[0].top )
          v15 = *v5->vals[0].d;
        else
          LOBYTE(v15) = 0;
        if ( ((unsigned __int8)v14 & (unsigned __int8)v15 & 2) != 0 )
          v19 = -v19;
        v16 = BN_nnmod(v5->vals, v5->vals, v4->vals, ctx);
        v3 = v16 == 0;
        if ( !v16 )
          break;
        v17 = v4;
        v4 = v5;
        v17->vals[0].neg = v3;
        v5 = v17;
        if ( v4->vals[0].top == v3 )
          goto LABEL_46;
      }
    }
    else
    {
LABEL_46:
      if ( v5->vals[0].top != 1 || *v5->vals[0].d != 1 || v5->vals[0].neg )
        v19 = 0;
    }
  }
end_11:
  BN_CTX_end(ctx);
  result = -2;
  if ( !v3 )
    return v19;
  return result;
}

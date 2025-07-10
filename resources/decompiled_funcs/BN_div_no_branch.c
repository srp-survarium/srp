int __cdecl BN_div_no_branch(bignum_st *rm, const bignum_st *num, const bignum_st *divisor, bignum_ctx *ctx)
{
  bignum_st *dv; // ecx
  bignum_st *v5; // esi
  bignum_ctx *v7; // ebx
  bignum_pool_item *v8; // edi
  bignum_pool_item *v9; // ebp
  int v10; // esi
  int top; // ecx
  int v12; // eax
  unsigned int *v13; // eax
  bignum_st *v14; // eax
  int i; // eax
  bignum_st *v16; // eax
  int v17; // ebx
  unsigned int *d; // ebp
  int v19; // esi
  unsigned int *v20; // ebp
  bignum_pool_item *v21; // ecx
  bool v22; // cc
  bignum_st *v23; // eax
  int v24; // edx
  bignum_st *v25; // eax
  unsigned int v26; // eax
  unsigned int v27; // edi
  int v28; // esi
  unsigned int v29; // edi
  unsigned __int64 v30; // rax
  int v31; // edi
  bool v32; // zf
  int v33; // eax
  unsigned int *v34; // edx
  int neg; // ebx
  int v37; // eax
  unsigned int *v38; // edx
  bignum_pool_item *b; // [esp+4h] [ebp-44h]
  unsigned int *v41; // [esp+8h] [ebp-40h]
  unsigned int v42; // [esp+Ch] [ebp-3Ch]
  unsigned int v43; // [esp+10h] [ebp-38h]
  int v44; // [esp+14h] [ebp-34h]
  bignum_pool_item *v45; // [esp+18h] [ebp-30h]
  bignum_pool_item *v46; // [esp+1Ch] [ebp-2Ch]
  int v47; // [esp+20h] [ebp-28h]
  bignum_pool_item *v48; // [esp+24h] [ebp-24h]
  int n; // [esp+28h] [ebp-20h]
  int v50; // [esp+2Ch] [ebp-1Ch]
  int v51; // [esp+34h] [ebp-14h]
  bignum_st *a; // [esp+54h] [ebp+Ch]

  v5 = dv;
  if ( !divisor->top )
  {
    ERR_put_error(3u, 138, 103, ".\\crypto\\bn\\bn_div.c", 442);
    return 0;
  }
  v7 = ctx;
  BN_CTX_start(ctx);
  v45 = BN_CTX_get(ctx);
  v8 = BN_CTX_get(ctx);
  v48 = v8;
  v9 = BN_CTX_get(ctx);
  v46 = v9;
  if ( v5 )
    b = (bignum_pool_item *)v5;
  else
    b = BN_CTX_get(ctx);
  if ( !v9 )
    goto err_158;
  if ( !b )
    goto err_158;
  v10 = 32 - BN_num_bits(divisor) % 32;
  if ( !BN_lshift(v9->vals, divisor, v10) )
    goto err_158;
  v9->vals[0].neg = 0;
  n = v10 + 32;
  if ( !BN_lshift(v8->vals, num, v10 + 32) )
    goto err_158;
  top = v8->vals[0].top;
  v8->vals[0].neg = 0;
  v12 = v9->vals[0].top;
  if ( top > v12 + 1 )
  {
    if ( top + 1 > v8->vals[0].dmax )
      v16 = bn_expand2(v8->vals, (unsigned int *)(top + 1));
    else
      v16 = (bignum_st *)v8;
    if ( !v16 )
      goto err_158;
    v8->vals[0].d[v8->vals[0].top++] = 0;
  }
  else
  {
    v13 = (unsigned int *)(v12 + 2);
    if ( (int)v13 > v8->vals[0].dmax )
      v14 = bn_expand2(v8->vals, v13);
    else
      v14 = (bignum_st *)v8;
    if ( !v14 )
      goto err_158;
    for ( i = v8->vals[0].top; i < v9->vals[0].top + 2; ++i )
      v8->vals[0].d[i] = 0;
    v8->vals[0].top = v9->vals[0].top + 2;
  }
  v17 = v9->vals[0].top;
  d = v9->vals[0].d;
  v19 = v8->vals[0].top - v17;
  v51 = (int)&v8->vals[0].d[v19];
  v44 = v17;
  v42 = d[v17 - 1];
  if ( v17 == 1 )
    v43 = 0;
  else
    v43 = d[v17 - 2];
  v20 = &v8->vals[0].d[v8->vals[0].top - 1];
  v21 = b;
  v22 = v19 + 1 <= b->vals[0].dmax;
  v41 = v20;
  b->vals[0].neg = num->neg ^ divisor->neg;
  if ( v22 )
  {
    v23 = (bignum_st *)b;
  }
  else
  {
    v23 = bn_expand2(b->vals, (unsigned int *)(v19 + 1));
    v21 = b;
  }
  if ( !v23
    || ((v24 = v19 - 1,
         a = (bignum_st *)&v21->vals[0].d[v19 - 1],
         v21->vals[0].top = v19 - 1,
         v17 + 1 > v45->vals[0].dmax)
      ? (v25 = bn_expand2(v45->vals, (unsigned int *)(v17 + 1)), v24 = v19 - 1, v21 = b)
      : (bignum_pool_item *)(v25 = (bignum_st *)v45),
        !v25) )
  {
    v7 = ctx;
err_158:
    BN_CTX_end(v7);
    return 0;
  }
  if ( v21->vals[0].top )
    a = (bignum_st *)((char *)a - 4);
  else
    v21->vals[0].neg = 0;
  if ( v24 > 0 )
  {
    v47 = v24;
    do
    {
      v26 = *v20;
      v27 = *(v20 - 1);
      if ( *v20 == v42 )
      {
        v28 = -1;
      }
      else
      {
        v28 = __PAIR64__(v26, v27) / v42;
        v29 = __PAIR64__(v26, v27) % v42;
        v30 = (unsigned int)v28 * (unsigned __int64)v43;
        v50 = v28 * v43;
        if ( v30 > __PAIR64__(v29, *(v20 - 2)) )
        {
          do
          {
            v29 += v42;
            --v28;
            if ( v29 < v42 )
              break;
            HIDWORD(v30) = (__PAIR64__(HIDWORD(v30), v50) - v43) >> 32;
            v50 -= v43;
          }
          while ( __PAIR64__(HIDWORD(v30), v50) > __PAIR64__(v29, *(v41 - 2)) );
        }
        v17 = v44;
        v20 = v41;
      }
      v45->vals[0].d[v17] = bn_mul_words(v45->vals[0].d, v46->vals[0].d, v17, v28);
      v31 = v51 - 4;
      v51 = v31;
      if ( bn_sub_words(v31, v31, v45->vals[0].d, v17 + 1) )
      {
        --v28;
        if ( bn_add_words(v31, v31, v46->vals[0].d, v17) )
          ++*v20;
      }
      a->d = (unsigned int *)v28;
      --v20;
      v32 = v47-- == 1;
      v41 = v20;
      a = (bignum_st *)((char *)a - 4);
    }
    while ( !v32 );
    v8 = v48;
    v21 = b;
  }
  v33 = v8->vals[0].top;
  if ( v33 > 0 )
  {
    v34 = &v8->vals[0].d[v33 - 1];
    do
    {
      if ( *v34-- )
        break;
      --v33;
    }
    while ( v33 > 0 );
    v8->vals[0].top = v33;
  }
  if ( rm )
  {
    neg = num->neg;
    BN_rshift(rm, v8->vals, n);
    v21 = b;
    if ( rm->top )
      rm->neg = neg;
  }
  v37 = v21->vals[0].top;
  if ( v37 > 0 )
  {
    v38 = &v21->vals[0].d[v37 - 1];
    do
    {
      if ( *v38-- )
        break;
      --v37;
    }
    while ( v37 > 0 );
    v21->vals[0].top = v37;
  }
  BN_CTX_end(ctx);
  return 1;
}

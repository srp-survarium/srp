int __usercall BN_div_no_branch@<eax>(
        bignum_pool_item *a1@<ecx>,
        int a2@<ebx>,
        bignum_st *rm,
        const bignum_st *num,
        const bignum_st *divisor,
        bignum_ctx *ctx)
{
  bignum_ctx *v8; // ebx
  bignum_pool_item *v9; // edi
  bignum_pool_item *v10; // ebp
  int v11; // esi
  int top; // ecx
  int v13; // eax
  int v14; // eax
  bignum_st *v15; // eax
  int i; // eax
  bignum_st *v17; // eax
  int v18; // ebx
  unsigned int *d; // ebp
  int v20; // esi
  unsigned int *v21; // ebp
  bignum_pool_item *v22; // ecx
  bool v23; // cc
  bignum_st *v24; // eax
  int v25; // edx
  bignum_st *v26; // eax
  unsigned int v27; // eax
  unsigned int v28; // edi
  int v29; // esi
  unsigned int v30; // edi
  unsigned __int64 v31; // rax
  int v32; // edi
  bool v33; // zf
  int v34; // eax
  unsigned int *v35; // edx
  int neg; // ebx
  int v38; // eax
  unsigned int *v39; // edx
  bignum_pool_item *b; // [esp+4h] [ebp-44h]
  unsigned int *v42; // [esp+8h] [ebp-40h]
  unsigned int v43; // [esp+Ch] [ebp-3Ch]
  unsigned int v44; // [esp+10h] [ebp-38h]
  int v45; // [esp+14h] [ebp-34h]
  bignum_pool_item *v46; // [esp+18h] [ebp-30h]
  bignum_pool_item *v47; // [esp+1Ch] [ebp-2Ch]
  int v48; // [esp+20h] [ebp-28h]
  bignum_pool_item *v49; // [esp+24h] [ebp-24h]
  int n; // [esp+28h] [ebp-20h]
  int v51; // [esp+2Ch] [ebp-1Ch]
  int v52; // [esp+34h] [ebp-14h]
  bignum_st *a; // [esp+54h] [ebp+Ch]

  if ( !divisor->top )
  {
    ERR_put_error(a2, 3u, 138, 103, ".\\crypto\\bn\\bn_div.c", 442);
    return 0;
  }
  v8 = ctx;
  BN_CTX_start((int)ctx, ctx);
  v46 = BN_CTX_get((int)v8, v8);
  v9 = BN_CTX_get((int)v8, v8);
  v49 = v9;
  v10 = BN_CTX_get((int)v8, v8);
  v47 = v10;
  if ( a1 )
    b = a1;
  else
    b = BN_CTX_get((int)ctx, ctx);
  if ( !v10 )
    goto err_160;
  if ( !b )
    goto err_160;
  v11 = 32 - BN_num_bits(divisor) % 32;
  if ( !BN_lshift(v10->vals, divisor, v11) )
    goto err_160;
  v10->vals[0].neg = 0;
  n = v11 + 32;
  if ( !BN_lshift(v9->vals, num, v11 + 32) )
    goto err_160;
  top = v9->vals[0].top;
  v9->vals[0].neg = 0;
  v13 = v10->vals[0].top;
  if ( top > v13 + 1 )
  {
    if ( top + 1 > v9->vals[0].dmax )
      v17 = bn_expand2(v9->vals, top + 1);
    else
      v17 = (bignum_st *)v9;
    if ( !v17 )
      goto err_160;
    v9->vals[0].d[v9->vals[0].top++] = 0;
  }
  else
  {
    v14 = v13 + 2;
    if ( v14 > v9->vals[0].dmax )
      v15 = bn_expand2(v9->vals, v14);
    else
      v15 = (bignum_st *)v9;
    if ( !v15 )
      goto err_160;
    for ( i = v9->vals[0].top; i < v10->vals[0].top + 2; ++i )
      v9->vals[0].d[i] = 0;
    v9->vals[0].top = v10->vals[0].top + 2;
  }
  v18 = v10->vals[0].top;
  d = v10->vals[0].d;
  v20 = v9->vals[0].top - v18;
  v52 = (int)&v9->vals[0].d[v20];
  v45 = v18;
  v43 = d[v18 - 1];
  if ( v18 == 1 )
    v44 = 0;
  else
    v44 = d[v18 - 2];
  v21 = &v9->vals[0].d[v9->vals[0].top - 1];
  v22 = b;
  v23 = v20 + 1 <= b->vals[0].dmax;
  v42 = v21;
  b->vals[0].neg = num->neg ^ divisor->neg;
  if ( v23 )
  {
    v24 = (bignum_st *)b;
  }
  else
  {
    v24 = bn_expand2(b->vals, v20 + 1);
    v22 = b;
  }
  if ( !v24
    || ((v25 = v20 - 1,
         a = (bignum_st *)&v22->vals[0].d[v20 - 1],
         v22->vals[0].top = v20 - 1,
         v18 + 1 > v46->vals[0].dmax)
      ? (v26 = bn_expand2(v46->vals, v18 + 1), v25 = v20 - 1, v22 = b)
      : (bignum_pool_item *)(v26 = (bignum_st *)v46),
        !v26) )
  {
    v8 = ctx;
err_160:
    BN_CTX_end(v8);
    return 0;
  }
  if ( v22->vals[0].top )
    a = (bignum_st *)((char *)a - 4);
  else
    v22->vals[0].neg = 0;
  if ( v25 > 0 )
  {
    v48 = v25;
    do
    {
      v27 = *v21;
      v28 = *(v21 - 1);
      if ( *v21 == v43 )
      {
        v29 = -1;
      }
      else
      {
        v29 = __PAIR64__(v27, v28) / v43;
        v30 = __PAIR64__(v27, v28) % v43;
        v31 = (unsigned int)v29 * (unsigned __int64)v44;
        v51 = v29 * v44;
        if ( v31 > __PAIR64__(v30, *(v21 - 2)) )
        {
          do
          {
            v30 += v43;
            --v29;
            if ( v30 < v43 )
              break;
            HIDWORD(v31) = (__PAIR64__(HIDWORD(v31), v51) - v44) >> 32;
            v51 -= v44;
          }
          while ( __PAIR64__(HIDWORD(v31), v51) > __PAIR64__(v30, *(v42 - 2)) );
        }
        v18 = v45;
        v21 = v42;
      }
      v46->vals[0].d[v18] = bn_mul_words(v46->vals[0].d, v47->vals[0].d, v18, v29);
      v32 = v52 - 4;
      v52 = v32;
      if ( bn_sub_words(v32, v32, v46->vals[0].d, v18 + 1) )
      {
        --v29;
        if ( bn_add_words(v32, v32, v47->vals[0].d, v18) )
          ++*v21;
      }
      a->d = (unsigned int *)v29;
      --v21;
      v33 = v48-- == 1;
      v42 = v21;
      a = (bignum_st *)((char *)a - 4);
    }
    while ( !v33 );
    v9 = v49;
    v22 = b;
  }
  v34 = v9->vals[0].top;
  if ( v34 > 0 )
  {
    v35 = &v9->vals[0].d[v34 - 1];
    do
    {
      if ( *v35-- )
        break;
      --v34;
    }
    while ( v34 > 0 );
    v9->vals[0].top = v34;
  }
  if ( rm )
  {
    neg = num->neg;
    BN_rshift(rm, v9->vals, n);
    v22 = b;
    if ( rm->top )
      rm->neg = neg;
  }
  v38 = v22->vals[0].top;
  if ( v38 > 0 )
  {
    v39 = &v22->vals[0].d[v38 - 1];
    do
    {
      if ( *v39-- )
        break;
      --v38;
    }
    while ( v38 > 0 );
    v22->vals[0].top = v38;
  }
  BN_CTX_end(ctx);
  return 1;
}

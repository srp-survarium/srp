int __cdecl BN_div(
        bignum_pool_item *dv,
        bignum_st *rm,
        const bignum_st *num,
        const bignum_st *divisor,
        bignum_ctx *ctx)
{
  int top; // eax
  bignum_ctx *v7; // ebx
  bignum_pool_item *v8; // esi
  bignum_pool_item *v9; // edi
  bignum_pool_item *v10; // ebp
  bignum_pool_item *v11; // eax
  int v12; // esi
  int v13; // eax
  int v14; // ebx
  int v15; // esi
  unsigned int *d; // ebp
  bignum_st *v17; // ecx
  unsigned int *v18; // ebp
  bool v19; // cc
  bignum_st *v20; // eax
  bignum_st *v22; // eax
  int v23; // esi
  unsigned int v24; // eax
  unsigned int v25; // edi
  int v26; // esi
  unsigned int v27; // edi
  unsigned __int64 v28; // rax
  bool v29; // zf
  int v30; // eax
  unsigned int *v31; // ecx
  int neg; // ebx
  bignum_st *v34; // [esp+4h] [ebp-44h]
  bignum_st *v35; // [esp+4h] [ebp-44h]
  unsigned int *v36; // [esp+8h] [ebp-40h]
  int *v37; // [esp+Ch] [ebp-3Ch]
  bignum_st *v38; // [esp+10h] [ebp-38h]
  unsigned int v39; // [esp+14h] [ebp-34h]
  unsigned int v40; // [esp+18h] [ebp-30h]
  int v41; // [esp+1Ch] [ebp-2Ch]
  bignum_st *v42; // [esp+20h] [ebp-28h]
  bignum_pool_item *v43; // [esp+24h] [ebp-24h]
  int n; // [esp+28h] [ebp-20h]
  int v45; // [esp+2Ch] [ebp-1Ch]
  bignum_st v46; // [esp+34h] [ebp-14h] BYREF

  top = num->top;
  if ( top > 0 && !num->d[top - 1] )
  {
    ERR_put_error(3u, 107, 107, ".\\crypto\\bn\\bn_div.c", 195);
    return 0;
  }
  if ( (num->flags & 4) != 0 || (divisor->flags & 4) != 0 )
    return BN_div_no_branch(rm, num, divisor, ctx);
  if ( !divisor->top )
  {
    ERR_put_error(3u, 107, 103, ".\\crypto\\bn\\bn_div.c", 213);
    return 0;
  }
  if ( BN_ucmp(num, divisor) >= 0 )
  {
    v7 = ctx;
    BN_CTX_start(ctx);
    v8 = BN_CTX_get(ctx);
    v42 = (bignum_st *)v8;
    v9 = BN_CTX_get(ctx);
    v43 = v9;
    v10 = BN_CTX_get(ctx);
    v11 = dv;
    v38 = (bignum_st *)v10;
    if ( !dv )
      v11 = BN_CTX_get(ctx);
    v34 = (bignum_st *)v11;
    if ( v10 )
    {
      if ( v11 )
      {
        if ( v8 )
        {
          if ( v9 )
          {
            v12 = 32 - BN_num_bits(divisor) % 32;
            if ( BN_lshift(v10->vals, divisor, v12) )
            {
              v10->vals[0].neg = 0;
              n = v12 + 32;
              if ( BN_lshift(v9->vals, num, v12 + 32) )
              {
                v13 = v9->vals[0].top;
                v9->vals[0].neg = 0;
                v14 = v10->vals[0].top;
                v15 = v13 - v14;
                v46.neg = 0;
                v46.d = &v9->vals[0].d[v13 - v14];
                v46.top = v14;
                v46.dmax = v9->vals[0].dmax - (v13 - v14);
                d = v10->vals[0].d;
                v41 = v14;
                v39 = d[v14 - 1];
                if ( v14 == 1 )
                  v40 = 0;
                else
                  v40 = d[v14 - 2];
                v17 = v34;
                v18 = &v9->vals[0].d[v13 - 1];
                v19 = v15 + 1 <= v34->dmax;
                v36 = v18;
                v34->neg = num->neg ^ divisor->neg;
                if ( v19 )
                {
                  v20 = v34;
                }
                else
                {
                  v20 = bn_expand2(v34, (unsigned int *)(v15 + 1));
                  v17 = v34;
                }
                if ( v20 )
                {
                  v17->top = v15;
                  v37 = (int *)&v17->d[v15 - 1];
                  if ( v14 + 1 > v42->dmax ? bn_expand2(v42, (unsigned int *)(v14 + 1)) : v42 )
                  {
                    if ( BN_ucmp(&v46, v38) < 0 )
                    {
                      v22 = v34;
                      --v34->top;
                    }
                    else
                    {
                      bn_sub_words(v46.d, v46.d, v38->d, v14);
                      v22 = v34;
                      *v37 = 1;
                    }
                    if ( v22->top )
                      --v37;
                    else
                      v22->neg = 0;
                    v23 = v15 - 1;
                    if ( v23 > 0 )
                    {
                      v35 = (bignum_st *)v23;
                      do
                      {
                        v24 = *v18;
                        v25 = *(v18 - 1);
                        if ( *v18 == v39 )
                        {
                          v26 = -1;
                        }
                        else
                        {
                          v26 = __PAIR64__(v24, v25) / v39;
                          v27 = __PAIR64__(v24, v25) % v39;
                          v28 = (unsigned int)v26 * (unsigned __int64)v40;
                          v45 = v26 * v40;
                          if ( v28 > __PAIR64__(v27, *(v18 - 2)) )
                          {
                            do
                            {
                              v27 += v39;
                              --v26;
                              if ( v27 < v39 )
                                break;
                              HIDWORD(v28) = (__PAIR64__(HIDWORD(v28), v45) - v40) >> 32;
                              v45 -= v40;
                            }
                            while ( __PAIR64__(HIDWORD(v28), v45) > __PAIR64__(v27, *(v36 - 2)) );
                          }
                          v14 = v41;
                          v18 = v36;
                        }
                        v42->d[v14] = bn_mul_words(v42->d, v38->d, v14, v26);
                        --v46.d;
                        if ( bn_sub_words(v46.d, v46.d, v42->d, v14 + 1) )
                        {
                          --v26;
                          if ( bn_add_words(v46.d, v46.d, v38->d, v14) )
                            ++*v18;
                        }
                        *v37 = v26;
                        --v18;
                        v29 = v35 == (bignum_st *)1;
                        v35 = (bignum_st *)((char *)v35 - 1);
                        v36 = v18;
                        --v37;
                      }
                      while ( !v29 );
                      v9 = v43;
                    }
                    v30 = v9->vals[0].top;
                    if ( v30 > 0 )
                    {
                      v31 = &v9->vals[0].d[v30 - 1];
                      do
                      {
                        if ( *v31-- )
                          break;
                        --v30;
                      }
                      while ( v30 > 0 );
                      v9->vals[0].top = v30;
                    }
                    if ( rm )
                    {
                      neg = num->neg;
                      BN_rshift(rm, v9->vals, n);
                      if ( rm->top )
                        rm->neg = neg;
                    }
                    BN_CTX_end(ctx);
                    return 1;
                  }
                }
                v7 = ctx;
              }
            }
          }
        }
      }
    }
    BN_CTX_end(v7);
    return 0;
  }
  if ( rm && !BN_copy(rm, num) )
    return 0;
  if ( dv )
    BN_set_word(dv->vals, 0);
  return 1;
}

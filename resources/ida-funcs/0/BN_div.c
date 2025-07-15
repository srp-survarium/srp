int __usercall BN_div@<eax>(
        int a1@<ebx>,
        bignum_pool_item *dv,
        bignum_st *rm,
        const bignum_st *num,
        const bignum_st *divisor,
        bignum_ctx *ctx)
{
  int top; // eax
  bignum_ctx *v8; // ebx
  bignum_pool_item *v9; // esi
  bignum_pool_item *v10; // edi
  bignum_pool_item *v11; // ebp
  bignum_pool_item *v12; // eax
  int v13; // esi
  int v14; // eax
  int v15; // ebx
  int v16; // esi
  unsigned int *d; // ebp
  bignum_st *v18; // ecx
  unsigned int *v19; // ebp
  bool v20; // cc
  bignum_st *v21; // eax
  bignum_st *v23; // eax
  int v24; // esi
  unsigned int v25; // eax
  unsigned int v26; // edi
  int v27; // esi
  unsigned int v28; // edi
  unsigned __int64 v29; // rax
  bool v30; // zf
  int v31; // eax
  unsigned int *v32; // ecx
  int neg; // ebx
  bignum_st *v35; // [esp+4h] [ebp-44h]
  bignum_st *v36; // [esp+4h] [ebp-44h]
  unsigned int *v37; // [esp+8h] [ebp-40h]
  int *v38; // [esp+Ch] [ebp-3Ch]
  bignum_st *v39; // [esp+10h] [ebp-38h]
  unsigned int v40; // [esp+14h] [ebp-34h]
  unsigned int v41; // [esp+18h] [ebp-30h]
  int v42; // [esp+1Ch] [ebp-2Ch]
  bignum_st *v43; // [esp+20h] [ebp-28h]
  bignum_pool_item *v44; // [esp+24h] [ebp-24h]
  int n; // [esp+28h] [ebp-20h]
  int v46; // [esp+2Ch] [ebp-1Ch]
  bignum_st v47; // [esp+34h] [ebp-14h] BYREF

  top = num->top;
  if ( top > 0 && !num->d[top - 1] )
  {
    ERR_put_error(a1, 3u, 107, 107, ".\\crypto\\bn\\bn_div.c", 195);
    return 0;
  }
  if ( (num->flags & 4) != 0 || (divisor->flags & 4) != 0 )
    return BN_div_no_branch(dv, a1, rm, num, divisor, ctx);
  if ( !divisor->top )
  {
    ERR_put_error(a1, 3u, 107, 103, ".\\crypto\\bn\\bn_div.c", 213);
    return 0;
  }
  if ( BN_ucmp(num, divisor) >= 0 )
  {
    v8 = ctx;
    BN_CTX_start((int)ctx, ctx);
    v9 = BN_CTX_get((int)v8, v8);
    v43 = (bignum_st *)v9;
    v10 = BN_CTX_get((int)v8, v8);
    v44 = v10;
    v11 = BN_CTX_get((int)v8, v8);
    v12 = dv;
    v39 = (bignum_st *)v11;
    if ( !dv )
      v12 = BN_CTX_get((int)ctx, ctx);
    v35 = (bignum_st *)v12;
    if ( v11 )
    {
      if ( v12 )
      {
        if ( v9 )
        {
          if ( v10 )
          {
            v13 = 32 - BN_num_bits(divisor) % 32;
            if ( BN_lshift(v11->vals, divisor, v13) )
            {
              v11->vals[0].neg = 0;
              n = v13 + 32;
              if ( BN_lshift(v10->vals, num, v13 + 32) )
              {
                v14 = v10->vals[0].top;
                v10->vals[0].neg = 0;
                v15 = v11->vals[0].top;
                v16 = v14 - v15;
                v47.neg = 0;
                v47.d = &v10->vals[0].d[v14 - v15];
                v47.top = v15;
                v47.dmax = v10->vals[0].dmax - (v14 - v15);
                d = v11->vals[0].d;
                v42 = v15;
                v40 = d[v15 - 1];
                if ( v15 == 1 )
                  v41 = 0;
                else
                  v41 = d[v15 - 2];
                v18 = v35;
                v19 = &v10->vals[0].d[v14 - 1];
                v20 = v16 + 1 <= v35->dmax;
                v37 = v19;
                v35->neg = num->neg ^ divisor->neg;
                if ( v20 )
                {
                  v21 = v35;
                }
                else
                {
                  v21 = bn_expand2(v35, v16 + 1);
                  v18 = v35;
                }
                if ( v21 )
                {
                  v18->top = v16;
                  v38 = (int *)&v18->d[v16 - 1];
                  if ( v15 + 1 > v43->dmax ? bn_expand2(v43, v15 + 1) : v43 )
                  {
                    if ( BN_ucmp(&v47, v39) < 0 )
                    {
                      v23 = v35;
                      --v35->top;
                    }
                    else
                    {
                      bn_sub_words(v47.d, v47.d, v39->d, v15);
                      v23 = v35;
                      *v38 = 1;
                    }
                    if ( v23->top )
                      --v38;
                    else
                      v23->neg = 0;
                    v24 = v16 - 1;
                    if ( v24 > 0 )
                    {
                      v36 = (bignum_st *)v24;
                      do
                      {
                        v25 = *v19;
                        v26 = *(v19 - 1);
                        if ( *v19 == v40 )
                        {
                          v27 = -1;
                        }
                        else
                        {
                          v27 = __PAIR64__(v25, v26) / v40;
                          v28 = __PAIR64__(v25, v26) % v40;
                          v29 = (unsigned int)v27 * (unsigned __int64)v41;
                          v46 = v27 * v41;
                          if ( v29 > __PAIR64__(v28, *(v19 - 2)) )
                          {
                            do
                            {
                              v28 += v40;
                              --v27;
                              if ( v28 < v40 )
                                break;
                              HIDWORD(v29) = (__PAIR64__(HIDWORD(v29), v46) - v41) >> 32;
                              v46 -= v41;
                            }
                            while ( __PAIR64__(HIDWORD(v29), v46) > __PAIR64__(v28, *(v37 - 2)) );
                          }
                          v15 = v42;
                          v19 = v37;
                        }
                        v43->d[v15] = bn_mul_words(v43->d, v39->d, v15, v27);
                        --v47.d;
                        if ( bn_sub_words(v47.d, v47.d, v43->d, v15 + 1) )
                        {
                          --v27;
                          if ( bn_add_words(v47.d, v47.d, v39->d, v15) )
                            ++*v19;
                        }
                        *v38 = v27;
                        --v19;
                        v30 = v36 == (bignum_st *)1;
                        v36 = (bignum_st *)((char *)v36 - 1);
                        v37 = v19;
                        --v38;
                      }
                      while ( !v30 );
                      v10 = v44;
                    }
                    v31 = v10->vals[0].top;
                    if ( v31 > 0 )
                    {
                      v32 = &v10->vals[0].d[v31 - 1];
                      do
                      {
                        if ( *v32-- )
                          break;
                        --v31;
                      }
                      while ( v31 > 0 );
                      v10->vals[0].top = v31;
                    }
                    if ( rm )
                    {
                      neg = num->neg;
                      BN_rshift(rm, v10->vals, n);
                      if ( rm->top )
                        rm->neg = neg;
                    }
                    BN_CTX_end(ctx);
                    return 1;
                  }
                }
                v8 = ctx;
              }
            }
          }
        }
      }
    }
    BN_CTX_end(v8);
    return 0;
  }
  if ( rm && !BN_copy(rm, num) )
    return 0;
  if ( dv )
    BN_set_word(a1, dv->vals, 0);
  return 1;
}

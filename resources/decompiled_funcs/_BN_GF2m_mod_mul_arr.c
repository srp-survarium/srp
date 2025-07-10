bignum_pool_item *__cdecl BN_GF2m_mod_mul_arr(
        bignum_st *r,
        const bignum_st *a,
        const bignum_st *b,
        int *p,
        bignum_ctx *ctx)
{
  const bignum_st *v5; // ebx
  bignum_pool_item *v7; // ebp
  int top; // eax
  int v9; // ecx
  int v10; // esi
  int v12; // eax
  int v13; // ecx
  int v14; // edi
  int v15; // eax
  int v16; // esi
  int v17; // edx
  unsigned int v18; // ebx
  unsigned int v19; // ecx
  unsigned int v20; // edx
  unsigned int v21; // eax
  unsigned int v22; // eax
  int v23; // eax
  unsigned int *v24; // ecx
  unsigned int ba; // [esp+8h] [ebp-34h]
  int v27; // [esp+Ch] [ebp-30h]
  unsigned int v28; // [esp+10h] [ebp-2Ch]
  unsigned int v29; // [esp+14h] [ebp-28h]
  int v30; // [esp+18h] [ebp-24h]
  int v31; // [esp+1Ch] [ebp-20h]
  unsigned int v32; // [esp+24h] [ebp-18h] BYREF
  unsigned int v33; // [esp+28h] [ebp-14h] BYREF
  unsigned int v34; // [esp+2Ch] [ebp-10h] BYREF
  unsigned int v35; // [esp+30h] [ebp-Ch] BYREF
  unsigned int r0; // [esp+34h] [ebp-8h] BYREF
  unsigned int r1; // [esp+38h] [ebp-4h] BYREF

  v5 = b;
  v31 = 0;
  if ( a == b )
    return BN_GF2m_mod_sqr_arr(r, a, p, ctx);
  BN_CTX_start(ctx);
  v7 = BN_CTX_get(ctx);
  if ( v7 )
  {
    top = a->top;
    v9 = b->top;
    v10 = top + v9 + 4;
    if ( v10 > v7->vals[0].dmax ? bn_expand2(v7->vals, (unsigned int *)(top + v9 + 4)) : (bignum_st *)v7 )
    {
      v12 = 0;
      for ( v7->vals[0].top = v10; v12 < v10; ++v12 )
        v7->vals[0].d[v12] = 0;
      v13 = b->top;
      v14 = 0;
      v30 = 0;
      if ( v13 > 0 )
      {
        v15 = a->top;
        do
        {
          v16 = v14;
          v28 = v5->d[v14];
          if ( v14 + 1 == v13 )
            ba = 0;
          else
            ba = v5->d[v14 + 1];
          v17 = 0;
          v27 = 0;
          if ( v15 > 0 )
          {
            while ( 1 )
            {
              v29 = a->d[v17];
              v18 = v17 + 1 == v15 ? 0 : a->d[v17 + 1];
              bn_GF2m_mul_1x1(&r0, ba, &r1, v18);
              bn_GF2m_mul_1x1(&v34, v28, &v35, v29);
              bn_GF2m_mul_1x1(&v33, v28 ^ ba, &v32, v29 ^ v18);
              v19 = r1;
              v20 = v35 ^ r1 ^ v32 ^ r0;
              v21 = v33 ^ v32 ^ v34;
              v7->vals[0].d[v16] ^= v34;
              v22 = v20 ^ v19 ^ v21;
              v7->vals[0].d[v16 + 1] ^= v22;
              v35 = v22;
              v7->vals[0].d[v16 + 2] ^= v20;
              r0 = v20;
              v7->vals[0].d[v16 + 3] ^= v19;
              v15 = a->top;
              v16 += 2;
              v27 += 2;
              if ( v27 >= v15 )
                break;
              v17 = v27;
            }
            v14 = v30;
          }
          v5 = b;
          v13 = b->top;
          v14 += 2;
          v30 = v14;
        }
        while ( v14 < v13 );
      }
      v23 = v7->vals[0].top;
      if ( v23 > 0 )
      {
        v24 = &v7->vals[0].d[v23 - 1];
        do
        {
          if ( *v24-- )
            break;
          --v23;
        }
        while ( v23 > 0 );
        v7->vals[0].top = v23;
      }
      if ( BN_GF2m_mod_arr(r, v7->vals, p) )
        v31 = 1;
    }
  }
  BN_CTX_end(ctx);
  return (bignum_pool_item *)v31;
}

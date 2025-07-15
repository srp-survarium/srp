bignum_pool_item *__cdecl BN_GF2m_mod_sqr_arr(bignum_st *r, const bignum_st *a, int *p, bignum_ctx *ctx)
{
  int v4; // ebp
  bignum_pool_item *result; // eax
  bignum_pool_item *v6; // esi
  int v7; // ecx
  unsigned int v8; // edx
  int v9; // edi
  unsigned int *v10; // eax

  v4 = 0;
  BN_CTX_start((int)ctx, ctx);
  result = BN_CTX_get((int)ctx, ctx);
  v6 = result;
  if ( result )
  {
    if ( 2 * a->top > result->vals[0].dmax )
      result = (bignum_pool_item *)bn_expand2(result->vals, 2 * a->top);
    if ( result )
    {
      v7 = a->top - 1;
      if ( v7 >= 0 )
      {
        do
        {
          v6->vals[0].d[2 * v7 + 1] = SQR_tb[HIWORD(a->d[v7]) & 0xF]
                                    | ((SQR_tb[(a->d[v7] >> 20) & 0xF]
                                      | ((SQR_tb[HIBYTE(a->d[v7]) & 0xF] | (SQR_tb[a->d[v7] >> 28] << 8)) << 8)) << 8);
          v8 = SQR_tb[a->d[v7] & 0xF]
             | ((SQR_tb[(a->d[v7] >> 4) & 0xF]
               | ((SQR_tb[(a->d[v7] >> 8) & 0xF] | (SQR_tb[(unsigned __int8)HIBYTE(LOWORD(a->d[v7])) >> 4] << 8)) << 8)) << 8);
          --v7;
          v6->vals[0].d[2 * v7 + 2] = v8;
        }
        while ( v7 >= 0 );
        v4 = 0;
      }
      v9 = 2 * a->top;
      v6->vals[0].top = v9;
      if ( v9 > 0 )
      {
        v10 = &v6->vals[0].d[v9 - 1];
        do
        {
          if ( *v10-- )
            break;
          --v9;
        }
        while ( v9 > 0 );
        v6->vals[0].top = v9;
      }
      if ( BN_GF2m_mod_arr((int)ctx, r, v6->vals, p) )
        v4 = 1;
    }
    BN_CTX_end(ctx);
    return (bignum_pool_item *)v4;
  }
  return result;
}

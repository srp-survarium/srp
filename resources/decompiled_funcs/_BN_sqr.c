int __cdecl BN_sqr(bignum_pool_item *r, bignum_pool_item *a, bignum_ctx *ctx)
{
  int top; // ebx
  bignum_pool_item *v5; // esi
  bignum_pool_item *v6; // eax
  bignum_st *v7; // edi
  unsigned int *p_tmp; // eax
  int v10; // eax
  bignum_st *v11; // eax
  bignum_st *v12; // eax
  unsigned int v13; // ebx
  int v14; // esi
  unsigned int *words; // [esp+8h] [ebp-88h]
  unsigned int tmp; // [esp+10h] [ebp-80h] BYREF

  top = a->vals[0].top;
  if ( top <= 0 )
  {
    r->vals[0].top = 0;
    return 1;
  }
  BN_CTX_start(ctx);
  v5 = r;
  if ( a == r )
    v5 = BN_CTX_get(ctx);
  v6 = BN_CTX_get(ctx);
  v7 = (bignum_st *)v6;
  if ( v5 && v6 )
  {
    words = (unsigned int *)(2 * top);
    if ( 2 * top > v5->vals[0].dmax ? bn_expand2(v5->vals, (unsigned int *)(2 * top)) : (bignum_st *)v5 )
    {
      if ( top == 4 )
      {
        bn_sqr_comba4(v5->vals[0].d, a->vals[0].d);
LABEL_29:
        v5->vals[0].neg = 0;
        v13 = a->vals[0].d[top - 1];
        if ( v13 == (unsigned __int16)v13 )
          v5->vals[0].top = (int)words - 1;
        else
          v5->vals[0].top = (int)words;
        if ( v5 != r )
          BN_copy(r->vals, v5->vals);
        v14 = 1;
        goto err_186;
      }
      if ( top == 8 )
      {
        bn_sqr_comba8(v5->vals[0].d, a->vals[0].d);
        goto LABEL_29;
      }
      if ( top < 16 )
      {
        p_tmp = &tmp;
LABEL_28:
        bn_sqr_normal(v5->vals[0].d, a->vals[0].d, top, p_tmp);
        goto LABEL_29;
      }
      v10 = 1 << (BN_num_bits_word(top) - 1);
      if ( top == v10 )
      {
        if ( 4 * v10 > v7->dmax )
          v11 = bn_expand2(v7, (unsigned int *)(4 * v10));
        else
          v11 = v7;
        if ( v11 )
        {
          bn_sqr_recursive(v5->vals[0].d, a->vals[0].d, top, v7->d);
          goto LABEL_29;
        }
      }
      else
      {
        if ( (int)words > v7->dmax )
          v12 = bn_expand2(v7, words);
        else
          v12 = v7;
        if ( v12 )
        {
          p_tmp = v7->d;
          goto LABEL_28;
        }
      }
    }
  }
  v14 = 0;
err_186:
  BN_CTX_end(ctx);
  return v14;
}

int __cdecl BN_mul(bignum_pool_item *r, bignum_pool_item *a, bignum_pool_item *b, bignum_ctx *ctx)
{
  int top; // ebp
  int v5; // ebx
  bignum_pool_item *v6; // esi
  int v7; // edi
  bignum_st *v8; // eax
  int v9; // edi
  bignum_pool_item *v10; // ecx
  int v11; // edx
  bignum_st *v12; // eax
  bignum_st *v13; // eax
  int v14; // edx
  bignum_st *v15; // eax
  bignum_st *v16; // eax
  bignum_st *v17; // eax
  int v18; // eax
  unsigned int *v19; // ecx
  char v22; // [esp+Ch] [ebp-10h]
  bignum_pool_item *v23; // [esp+Ch] [ebp-10h]
  int words; // [esp+10h] [ebp-Ch]
  int v25; // [esp+14h] [ebp-8h]

  top = b->vals[0].top;
  v5 = a->vals[0].top;
  v25 = 0;
  v22 = 0;
  if ( v5 && top )
  {
    words = v5 + top;
    BN_CTX_start(v5, ctx);
    if ( r == a || r == b )
    {
      v6 = BN_CTX_get(v5, ctx);
      if ( !v6 )
        goto err_116;
    }
    else
    {
      v6 = r;
    }
    v7 = v5 - top;
    v6->vals[0].neg = b->vals[0].neg ^ a->vals[0].neg;
    if ( v5 == top && v5 == 8 )
    {
      if ( v6->vals[0].dmax < 16 )
        v8 = bn_expand2(v6->vals, 16);
      else
        v8 = (bignum_st *)v6;
      if ( v8 )
      {
        v6->vals[0].top = 16;
        bn_mul_comba8(v6->vals[0].d, a->vals[0].d, b->vals[0].d);
end_5:
        v18 = v6->vals[0].top;
        if ( v18 > 0 )
        {
          v19 = &v6->vals[0].d[v18 - 1];
          do
          {
            if ( *v19-- )
              break;
            --v18;
          }
          while ( v18 > 0 );
          v6->vals[0].top = v18;
        }
        if ( r != v6 )
          BN_copy(r->vals, v6->vals);
        v25 = 1;
      }
    }
    else if ( v5 < 16 || top < 16 || (unsigned int)(v7 + 1) > 2 )
    {
      if ( words > v6->vals[0].dmax )
        v17 = bn_expand2(v6->vals, words);
      else
        v17 = (bignum_st *)v6;
      if ( v17 )
      {
        v6->vals[0].top = words;
        bn_mul_normal(v6->vals[0].d, a->vals[0].d, v5, b->vals[0].d, top);
        goto end_5;
      }
    }
    else
    {
      if ( v7 >= 0 )
        v22 = BN_num_bits_word(v5);
      if ( v7 == -1 )
        v22 = BN_num_bits_word(top);
      v9 = 1 << (v22 - 1);
      v10 = BN_CTX_get(v5, ctx);
      v23 = v10;
      if ( !v10 )
        goto err_116;
      if ( v5 > v9 || top > v9 )
      {
        v14 = 8 * v9;
        if ( 8 * v9 > v10->vals[0].dmax )
        {
          v15 = bn_expand2(v10->vals, 8 * v9);
          v10 = v23;
          v14 = 8 * v9;
        }
        else
        {
          v15 = (bignum_st *)v10;
        }
        if ( v15 )
        {
          if ( v14 > v6->vals[0].dmax )
          {
            v16 = bn_expand2(v6->vals, v14);
            v10 = v23;
          }
          else
          {
            v16 = (bignum_st *)v6;
          }
          if ( v16 )
          {
            bn_mul_part_recursive(v6->vals[0].d, a->vals[0].d, b->vals[0].d, v9, v5 - v9, top - v9, v10->vals[0].d);
            v6->vals[0].top = words;
            goto end_5;
          }
        }
      }
      else
      {
        v11 = 4 * v9;
        if ( 4 * v9 > v10->vals[0].dmax )
        {
          v12 = bn_expand2(v10->vals, 4 * v9);
          v10 = v23;
          v11 = 4 * v9;
        }
        else
        {
          v12 = (bignum_st *)v10;
        }
        if ( v12 )
        {
          if ( v11 > v6->vals[0].dmax )
          {
            v13 = bn_expand2(v6->vals, v11);
            v10 = v23;
          }
          else
          {
            v13 = (bignum_st *)v6;
          }
          if ( v13 )
          {
            bn_mul_recursive(v6->vals[0].d, a->vals[0].d, b->vals[0].d, v9, v5 - v9, top - v9, v10->vals[0].d);
            v6->vals[0].top = words;
            goto end_5;
          }
        }
      }
    }
err_116:
    BN_CTX_end(ctx);
    return v25;
  }
  BN_set_word(v5, r->vals, 0);
  return 1;
}

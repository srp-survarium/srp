bignum_pool_item *__cdecl BN_mod_sqrt(bignum_pool_item *in, const bignum_st *a, const bignum_st *p, bignum_ctx *ctx)
{
  int top; // eax
  bignum_st *v6; // edi
  unsigned int v7; // ecx
  const bignum_st *v8; // eax
  int v9; // ecx
  bignum_pool_item *v10; // edi
  bignum_pool_item *v11; // ebx
  bignum_st *v12; // eax
  int v14; // eax
  int (__cdecl *v15)(bignum_st *, const bignum_st *, const bignum_st *); // eax
  int v16; // eax
  int v17; // ebx
  unsigned int v18; // eax
  unsigned int is_bit_set; // eax
  bignum_pool_item *v20; // [esp+10h] [ebp-1Ch]
  bignum_st *v21; // [esp+10h] [ebp-1Ch]
  bignum_pool_item *aa; // [esp+14h] [ebp-18h]
  int w; // [esp+18h] [ebp-14h]
  unsigned int wa; // [esp+18h] [ebp-14h]
  bignum_pool_item *v25; // [esp+1Ch] [ebp-10h]
  bignum_pool_item *r; // [esp+20h] [ebp-Ch]
  int n; // [esp+24h] [ebp-8h]
  bignum_pool_item *b; // [esp+28h] [ebp-4h]
  bignum_pool_item *d; // [esp+38h] [ebp+Ch]

  top = p->top;
  v6 = (bignum_st *)in;
  v20 = in;
  if ( top > 0 )
  {
    v7 = *p->d;
    if ( (v7 & 1) != 0 && (top != 1 || v7 != 1) )
    {
      v8 = a;
      v9 = a->top;
      if ( v9 && (v9 != 1 || *a->d != 1 || a->neg) )
      {
        BN_CTX_start((int)in, ctx);
        r = BN_CTX_get((int)in, ctx);
        v25 = BN_CTX_get((int)in, ctx);
        aa = BN_CTX_get((int)in, ctx);
        v10 = BN_CTX_get((int)in, ctx);
        d = BN_CTX_get((int)in, ctx);
        v11 = BN_CTX_get((int)in, ctx);
        b = v11;
        if ( !v11 )
          goto LABEL_33;
        if ( in || (v20 = (bignum_pool_item *)BN_new((int)v11)) != 0 )
        {
          if ( !BN_nnmod((int)v11, r->vals, a, p, ctx) )
            goto LABEL_33;
          n = 1;
          if ( BN_is_bit_set(p, 1) )
            goto LABEL_113;
          do
            ++n;
          while ( !BN_is_bit_set(p, n) );
          if ( n == 1 )
          {
LABEL_113:
            if ( BN_rshift(aa->vals, p, 2) )
            {
              aa->vals[0].neg = 0;
              if ( BN_add_word((int)v11, aa->vals, 1u) )
              {
                v12 = (bignum_st *)BN_mod_exp((int)v11, v20, r, aa->vals, p, ctx);
LABEL_29:
                if ( v12 && BN_mod_sqr((int)v11, d, v20, p, ctx) )
                {
                  if ( !BN_cmp(d->vals, r->vals) )
                  {
LABEL_37:
                    BN_CTX_end(ctx);
                    return v20;
                  }
                  ERR_put_error((int)v11, 3u, 121, 111, ".\\crypto\\bn\\bn_sqrt.c", 376);
                }
                goto LABEL_33;
              }
            }
            goto LABEL_33;
          }
          if ( n == 2 )
          {
            if ( !BN_mod_lshift1_quick(v10->vals, r->vals, p) )
              goto LABEL_33;
            if ( !BN_rshift(aa->vals, p, 3) )
              goto LABEL_33;
            aa->vals[0].neg = 0;
            if ( !BN_mod_exp((int)v11, v25, v10, aa->vals, p, ctx)
              || !BN_mod_sqr((int)v11, v11, v25, p, ctx)
              || !BN_mod_mul(v10->vals, v10, v11, p, ctx)
              || !BN_sub_word((int)v11, v10->vals, 1u)
              || !BN_mod_mul(d->vals, r, v25, p, ctx)
              || !BN_mod_mul(d->vals, d, v10, p, ctx) )
            {
              goto LABEL_33;
            }
            goto LABEL_28;
          }
          if ( !BN_copy(aa->vals, p) )
            goto LABEL_33;
          aa->vals[0].neg = 0;
          w = 2;
          while ( 1 )
          {
            if ( w < 22 )
              goto LABEL_47;
            v14 = BN_num_bits(p);
            if ( !BN_pseudo_rand((int)v11, v11->vals, v14, 0, 0) )
              goto LABEL_33;
            if ( BN_ucmp(v11->vals, p) >= 0 )
            {
              v15 = BN_add;
              if ( !p->neg )
                v15 = BN_sub;
              if ( !v15(v11->vals, v11->vals, p) )
                goto LABEL_33;
            }
            if ( !v11->vals[0].top )
            {
LABEL_47:
              if ( !BN_set_word((int)v11, v11->vals, w) )
                goto LABEL_33;
            }
            v16 = BN_kronecker(v11->vals, aa->vals, ctx);
            if ( v16 < -1 )
              goto LABEL_33;
            if ( !v16 )
            {
              ERR_put_error((int)v11, 3u, 121, 112, ".\\crypto\\bn\\bn_sqrt.c", 236);
              goto LABEL_33;
            }
            if ( v16 != 1 )
              break;
            if ( ++w >= 82 )
              goto LABEL_52;
          }
          if ( v16 != -1 )
          {
LABEL_52:
            ERR_put_error((int)v11, 3u, 121, 113, ".\\crypto\\bn\\bn_sqrt.c", 249);
            goto LABEL_33;
          }
          if ( !BN_rshift(aa->vals, aa->vals, n) || !BN_mod_exp((int)v11, v11, v11, aa->vals, p, ctx) )
            goto LABEL_33;
          if ( v11->vals[0].top == 1 && *v11->vals[0].d == 1 && !v11->vals[0].neg )
          {
            ERR_put_error((int)v11, 3u, 121, 112, ".\\crypto\\bn\\bn_sqrt.c", 261);
            goto LABEL_33;
          }
          if ( !BN_rshift1(v10->vals, aa->vals) )
          {
LABEL_33:
            if ( v20 )
            {
              if ( v20 != in )
                BN_clear_free(v20->vals);
            }
            goto LABEL_36;
          }
          if ( v10->vals[0].top )
          {
            if ( !BN_mod_exp((int)v11, d, r, v10->vals, p, ctx) )
              goto LABEL_33;
            if ( !d->vals[0].top )
              goto LABEL_65;
          }
          else
          {
            if ( !BN_nnmod((int)v11, v10->vals, r->vals, p, ctx) )
              goto LABEL_33;
            if ( !v10->vals[0].top )
            {
LABEL_65:
              BN_set_word((int)v11, v20->vals, 0);
              BN_CTX_end(ctx);
              return v20;
            }
            if ( !BN_set_word((int)v11, d->vals, 1u) )
              goto LABEL_33;
          }
          if ( !BN_mod_sqr((int)v11, v25, d, p, ctx)
            || !BN_mod_mul(v25->vals, v25, r, p, ctx)
            || !BN_mod_mul(d->vals, d, r, p, ctx) )
          {
            goto LABEL_33;
          }
          while ( 2 )
          {
            if ( v25->vals[0].top != 1 || *v25->vals[0].d != 1 || v25->vals[0].neg )
            {
              v17 = 1;
              wa = 1;
              if ( BN_mod_sqr(1, v10, v25, p, ctx) )
              {
                while ( v10->vals[0].top != 1 || *v10->vals[0].d != 1 || v10->vals[0].neg )
                {
                  wa = ++v17;
                  if ( v17 == n )
                  {
                    ERR_put_error(v17, 3u, 121, 111, ".\\crypto\\bn\\bn_sqrt.c", 346);
                    goto LABEL_33;
                  }
                  if ( !BN_mod_mul(v10->vals, v10, v10, p, ctx) )
                    goto LABEL_33;
                }
                if ( !BN_copy(v10->vals, b->vals) )
                  goto LABEL_33;
                v11 = (bignum_pool_item *)(n - wa - 1);
                if ( (int)v11 <= 0 )
                {
LABEL_87:
                  if ( BN_mod_mul(b->vals, v10, v10, p, ctx)
                    && BN_mod_mul(d->vals, d, v10, p, ctx)
                    && BN_mod_mul(v25->vals, v25, b, p, ctx) )
                  {
                    n = wa;
                    continue;
                  }
                }
                else
                {
                  while ( BN_mod_sqr((int)v11, v10, v10, p, ctx) )
                  {
                    v11 = (bignum_pool_item *)((char *)v11 - 1);
                    if ( (int)v11 <= 0 )
                      goto LABEL_87;
                  }
                }
              }
              goto LABEL_33;
            }
            break;
          }
LABEL_28:
          v12 = BN_copy(v20->vals, d->vals);
          goto LABEL_29;
        }
LABEL_36:
        v20 = 0;
        goto LABEL_37;
      }
      if ( !in )
      {
        v21 = BN_new(0);
        if ( !v21 )
          goto LABEL_36;
        v8 = a;
        v6 = v21;
      }
      v18 = v8->top == 1 && *v8->d == 1 && !v8->neg;
      if ( !BN_set_word((int)in, v6, v18) )
      {
LABEL_101:
        if ( v6 != (bignum_st *)in )
        {
          BN_free(v6);
          return 0;
        }
        return 0;
      }
      return (bignum_pool_item *)v6;
    }
  }
  if ( top == 1 && *p->d == 2 )
  {
    if ( !in )
    {
      v6 = BN_new(0);
      if ( !v6 )
        goto LABEL_36;
    }
    is_bit_set = BN_is_bit_set(a, 0);
    if ( !BN_set_word((int)in, v6, is_bit_set) )
      goto LABEL_101;
    return (bignum_pool_item *)v6;
  }
  ERR_put_error((int)in, 3u, 121, 112, ".\\crypto\\bn\\bn_sqrt.c", 94);
  return 0;
}

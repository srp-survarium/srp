int __usercall BN_mod_exp_mont_word@<eax>(
        int a1@<ebx>,
        bignum_st *rr,
        unsigned int a,
        const bignum_st *p,
        const bignum_st *m,
        bignum_ctx *ctx,
        bn_mont_ctx_st *in_mont)
{
  int top; // eax
  unsigned int v9; // ecx
  bignum_pool_item *v10; // edi
  bignum_pool_item *v11; // esi
  bignum_pool_item *v12; // eax
  bignum_st *v13; // ebx
  bn_mont_ctx_st *v14; // eax
  unsigned int v15; // edi
  int v16; // ecx
  bool v17; // sf
  int v18; // ebx
  bignum_pool_item *v19; // eax
  unsigned int v20; // ebx
  bignum_pool_item *v21; // eax
  int v22; // eax
  bn_mont_ctx_st *mont; // [esp+8h] [ebp-14h]
  int v24; // [esp+Ch] [ebp-10h]
  bignum_st *rm; // [esp+10h] [ebp-Ch]
  int v26; // [esp+14h] [ebp-8h]
  int v27; // [esp+14h] [ebp-8h]
  int v28; // [esp+18h] [ebp-4h]

  mont = 0;
  v28 = 0;
  if ( (p->flags & 4) != 0 )
  {
    ERR_put_error(a1, 3u, 117, 66, ".\\crypto\\bn\\bn_exp.c", 752);
    return -1;
  }
  top = m->top;
  if ( top > 0 )
  {
    v9 = *m->d;
    if ( (v9 & 1) != 0 )
    {
      if ( top == 1 )
        a %= v9;
      v26 = BN_num_bits(p);
      if ( !v26 )
        return BN_set_word(a1, rr, 1u);
      if ( !a )
      {
        BN_set_word(a1, rr, 0);
        return 1;
      }
      BN_CTX_start(a1, ctx);
      v10 = BN_CTX_get(a1, ctx);
      v11 = BN_CTX_get(a1, ctx);
      v12 = BN_CTX_get(a1, ctx);
      v13 = (bignum_st *)v12;
      rm = (bignum_st *)v12;
      if ( !v10 || !v11 || !v12 )
      {
err_145:
        if ( !in_mont )
        {
LABEL_51:
          if ( mont )
            BN_MONT_CTX_free(mont);
        }
LABEL_53:
        BN_CTX_end(ctx);
        return v28;
      }
      if ( in_mont )
      {
        mont = in_mont;
      }
      else
      {
        v14 = BN_MONT_CTX_new();
        mont = v14;
        if ( !v14 )
          goto LABEL_53;
        if ( !BN_MONT_CTX_set(v14, m, ctx) )
          goto LABEL_51;
      }
      v15 = a;
      v16 = 1;
      v17 = v26 - 2 < 0;
      v24 = 1;
      v27 = v26 - 2;
      if ( !v17 )
      {
        do
        {
          v18 = v15 * v15;
          if ( v15 * v15 / v15 != v15 )
          {
            if ( v16 )
            {
              if ( !BN_set_word(v18, v11->vals, v15)
                || !BN_mod_mul_montgomery(v11->vals, v11, (bignum_pool_item *)&mont->RR, mont, ctx) )
              {
                goto err_145;
              }
              v24 = 0;
            }
            else
            {
              if ( !BN_mul_word(v18, v11->vals, v15) || !BN_div(0, rm, v11->vals, m, ctx) )
                goto err_145;
              v19 = v11;
              v11 = (bignum_pool_item *)rm;
              rm = (bignum_st *)v19;
            }
            v16 = v24;
            v18 = 1;
          }
          v15 = v18;
          if ( !v16 && !BN_mod_mul_montgomery(v11->vals, v11, v11, mont, ctx) )
            goto err_145;
          if ( BN_is_bit_set(p, v27) )
          {
            v20 = a * v18;
            if ( v20 / a != v15 )
            {
              if ( v24 )
              {
                if ( !BN_set_word(v20, v11->vals, v15)
                  || !BN_mod_mul_montgomery(v11->vals, v11, (bignum_pool_item *)&mont->RR, mont, ctx) )
                {
                  goto err_145;
                }
                v24 = 0;
              }
              else
              {
                if ( !BN_mul_word(v20, v11->vals, v15) || !BN_div(0, rm, v11->vals, m, ctx) )
                  goto err_145;
                v21 = v11;
                v11 = (bignum_pool_item *)rm;
                rm = (bignum_st *)v21;
              }
              v20 = a;
            }
            v15 = v20;
          }
          v17 = --v27 < 0;
          v16 = v24;
        }
        while ( !v17 );
        v13 = rm;
      }
      if ( v15 == 1 )
      {
        if ( v16 )
        {
          v22 = BN_set_word((int)v13, rr, 1u);
LABEL_48:
          if ( v22 )
            v28 = 1;
          goto err_145;
        }
      }
      else if ( v16 )
      {
        if ( !BN_set_word((int)v13, v11->vals, v15)
          || !BN_mod_mul_montgomery(v11->vals, v11, (bignum_pool_item *)&mont->RR, mont, ctx) )
        {
          goto err_145;
        }
      }
      else
      {
        if ( !BN_mul_word((int)v13, v11->vals, v15) || !BN_div(0, v13, v11->vals, m, ctx) )
          goto err_145;
        v11 = (bignum_pool_item *)v13;
      }
      v22 = BN_from_montgomery(rr, v11->vals, mont, ctx);
      goto LABEL_48;
    }
  }
  ERR_put_error(a1, 3u, 117, 102, ".\\crypto\\bn\\bn_exp.c", 761);
  return 0;
}

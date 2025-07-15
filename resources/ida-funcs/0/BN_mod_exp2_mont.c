int __usercall BN_mod_exp2_mont@<eax>(
        int ebx0@<ebx>,
        bignum_st *rr,
        bignum_pool_item *a1,
        const bignum_st *p1,
        bignum_pool_item *a2,
        const bignum_st *p2,
        const bignum_st *m,
        bignum_ctx *ctx,
        bn_mont_ctx_st *in_mont)
{
  int v10; // esi
  int v11; // eax
  bignum_ctx *v12; // ebx
  bignum_pool_item *v13; // edi
  bignum_pool_item *v14; // eax
  bn_mont_ctx_st *v15; // ebp
  bn_mont_ctx_st *v16; // eax
  int v17; // edi
  bignum_pool_item *v18; // eax
  bignum_pool_item *v19; // esi
  int v20; // edi
  int v21; // esi
  bignum_pool_item *v22; // eax
  bignum_pool_item *v23; // eax
  int v24; // edi
  int v25; // esi
  bignum_pool_item *v26; // eax
  int v27; // esi
  int v28; // edi
  bignum_pool_item *v29; // eax
  int v30; // ebp
  int i; // esi
  bool v32; // cc
  int v33; // ebx
  int j; // edi
  int v35; // ebx
  bignum_pool_item *v36; // [esp+4h] [ebp-12Ch]
  int v37; // [esp+4h] [ebp-12Ch]
  bn_mont_ctx_st *mont; // [esp+8h] [ebp-128h]
  int v39; // [esp+Ch] [ebp-124h]
  int v40; // [esp+10h] [ebp-120h]
  bignum_pool_item *p_RR; // [esp+10h] [ebp-120h]
  bignum_pool_item *v42; // [esp+14h] [ebp-11Ch]
  int v43; // [esp+18h] [ebp-118h]
  int v44; // [esp+18h] [ebp-118h]
  int v45; // [esp+1Ch] [ebp-114h]
  int v46; // [esp+20h] [ebp-110h]
  int v47; // [esp+24h] [ebp-10Ch]
  int v48; // [esp+28h] [ebp-108h]
  int v49; // [esp+2Ch] [ebp-104h]
  bignum_st *v50[32]; // [esp+30h] [ebp-100h]
  bignum_st *v51[32]; // [esp+B0h] [ebp-80h]

  v45 = 0;
  mont = 0;
  if ( (*(_BYTE *)m->d & 1) == 0 )
  {
    ERR_put_error(ebx0, 3u, 118, 102, ".\\crypto\\bn\\bn_exp2.c", 138);
    return 0;
  }
  v10 = BN_num_bits(p1);
  v11 = BN_num_bits(p2);
  v40 = v11;
  if ( !v10 && !v11 )
    return BN_set_word(ebx0, rr, 1u);
  v43 = v10;
  if ( v10 <= v11 )
    v43 = v11;
  v12 = ctx;
  BN_CTX_start((int)ctx, ctx);
  v36 = BN_CTX_get((int)v12, v12);
  v13 = BN_CTX_get((int)v12, v12);
  v42 = v13;
  v51[0] = (bignum_st *)BN_CTX_get((int)v12, v12);
  v14 = BN_CTX_get((int)v12, v12);
  v15 = in_mont;
  v50[0] = (bignum_st *)v14;
  if ( v36 && v13 && v51[0] && v14 )
  {
    if ( in_mont )
    {
      mont = in_mont;
    }
    else
    {
      v16 = BN_MONT_CTX_new();
      v15 = v16;
      mont = v16;
      if ( !v16 )
        goto LABEL_94;
      if ( !BN_MONT_CTX_set((int)ctx, v16, m, ctx) )
        goto LABEL_92;
    }
    if ( v10 <= 671 )
    {
      if ( v10 <= 239 )
      {
        if ( v10 <= 79 )
        {
          v17 = 2 * (v10 > 23) + 1;
          v46 = v17;
        }
        else
        {
          v17 = 4;
          v46 = 4;
        }
      }
      else
      {
        v17 = 5;
        v46 = 5;
      }
    }
    else
    {
      v17 = 6;
      v46 = 6;
    }
    if ( v40 <= 671 )
    {
      if ( v40 <= 239 )
      {
        if ( v40 <= 79 )
          v39 = 2 * (v40 > 23) + 1;
        else
          v39 = 4;
      }
      else
      {
        v39 = 5;
      }
    }
    else
    {
      v39 = 6;
    }
    if ( a1->vals[0].neg || BN_ucmp(a1->vals, m) >= 0 )
    {
      v19 = (bignum_pool_item *)v51[0];
      if ( !BN_div((int)ctx, 0, v51[0], a1->vals, m, ctx) )
        goto err_163;
      v18 = (bignum_pool_item *)v51[0];
    }
    else
    {
      v18 = a1;
      v19 = (bignum_pool_item *)v51[0];
    }
    if ( !v18->vals[0].top )
    {
      BN_set_word((int)ctx, rr, 0);
LABEL_89:
      v45 = 1;
      goto err_163;
    }
    p_RR = (bignum_pool_item *)&v15->RR;
    if ( !BN_mod_mul_montgomery(v19->vals, v18, (bignum_pool_item *)&v15->RR, v15, ctx) )
      goto err_163;
    if ( v17 <= 1 )
      goto LABEL_44;
    if ( !BN_mod_mul_montgomery(v36->vals, v19, v19, v15, ctx) )
      goto err_163;
    v20 = 1 << (v17 - 1);
    v21 = 1;
    if ( v20 <= 1 )
    {
LABEL_44:
      if ( a2->vals[0].neg || BN_ucmp(a2->vals, m) >= 0 )
      {
        if ( !BN_div((int)ctx, 0, v50[0], a2->vals, m, ctx) )
          goto err_163;
        v23 = (bignum_pool_item *)v50[0];
      }
      else
      {
        v23 = a2;
      }
      if ( !v23->vals[0].top )
      {
        BN_set_word((int)ctx, rr, 0);
        goto LABEL_89;
      }
      if ( !BN_mod_mul_montgomery(v50[0], v23, p_RR, v15, ctx) )
        goto err_163;
      if ( v39 <= 1 )
        goto LABEL_58;
      if ( !BN_mod_mul_montgomery(v36->vals, (bignum_pool_item *)v50[0], (bignum_pool_item *)v50[0], v15, ctx) )
        goto err_163;
      v24 = 1 << (v39 - 1);
      v25 = 1;
      if ( v24 <= 1 )
      {
LABEL_58:
        v27 = 0;
        v48 = 1;
        v28 = 0;
        v47 = 0;
        v49 = 0;
        v29 = (bignum_pool_item *)BN_value_one();
        if ( !BN_mod_mul_montgomery(v42->vals, v29, p_RR, v15, ctx) )
          goto err_163;
        v37 = v43 - 1;
        if ( v43 - 1 < 0 )
        {
LABEL_88:
          if ( !BN_from_montgomery(rr, v42->vals, mont, v12) )
            goto err_163;
          goto LABEL_89;
        }
        v30 = v43 - 2;
        v44 = 2 - v39;
        while ( v48 || BN_mod_mul_montgomery(v42->vals, v42, v42, mont, v12) )
        {
          if ( !v27 && BN_is_bit_set(p1, v37) )
          {
            for ( i = 2 - v46 + v30; !BN_is_bit_set(p1, i); ++i )
              ;
            v32 = v30 < i;
            v47 = i;
            v27 = 1;
            v33 = v30;
            if ( !v32 )
            {
              do
              {
                v27 *= 2;
                if ( BN_is_bit_set(p1, v33) )
                  ++v27;
                --v33;
              }
              while ( v33 >= v47 );
            }
          }
          if ( !v28 && BN_is_bit_set(p2, v37) )
          {
            for ( j = v44 + v30; !BN_is_bit_set(p2, j); ++j )
              ;
            v32 = v30 < j;
            v49 = j;
            v28 = 1;
            v35 = v30;
            if ( !v32 )
            {
              do
              {
                v28 *= 2;
                if ( BN_is_bit_set(p2, v35) )
                  ++v28;
                --v35;
              }
              while ( v35 >= v49 );
            }
          }
          if ( v27 && v37 == v47 )
          {
            if ( !BN_mod_mul_montgomery(v42->vals, v42, (bignum_pool_item *)v51[v27 >> 1], mont, ctx) )
              break;
            v27 = 0;
            v48 = 0;
          }
          if ( v28 && v37 == v49 )
          {
            if ( !BN_mod_mul_montgomery(v42->vals, v42, (bignum_pool_item *)v50[v28 >> 1], mont, ctx) )
              break;
            v28 = 0;
            v48 = 0;
          }
          v12 = ctx;
          --v30;
          if ( --v37 < 0 )
            goto LABEL_88;
        }
      }
      else
      {
        while ( 1 )
        {
          v26 = BN_CTX_get((int)ctx, ctx);
          v50[v25] = (bignum_st *)v26;
          if ( !v26 || !BN_mod_mul_montgomery(v26->vals, (bignum_pool_item *)v50[v25 - 1], v36, v15, ctx) )
            break;
          if ( ++v25 >= v24 )
            goto LABEL_58;
        }
      }
    }
    else
    {
      while ( 1 )
      {
        v22 = BN_CTX_get((int)ctx, ctx);
        v51[v21] = (bignum_st *)v22;
        if ( !v22 || !BN_mod_mul_montgomery(v22->vals, (bignum_pool_item *)v50[v21 + 31], v36, v15, ctx) )
          break;
        if ( ++v21 >= v20 )
          goto LABEL_44;
      }
    }
  }
err_163:
  v12 = ctx;
  if ( !in_mont )
  {
    v15 = mont;
LABEL_92:
    if ( v15 )
      BN_MONT_CTX_free(v15);
  }
LABEL_94:
  BN_CTX_end(v12);
  return v45;
}

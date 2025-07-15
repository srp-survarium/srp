int __cdecl BN_mod_exp2_mont(
        bignum_st *rr,
        bignum_pool_item *a1,
        const bignum_st *p1,
        bignum_pool_item *a2,
        const bignum_st *p2,
        const bignum_st *m,
        bignum_ctx *ctx,
        bn_mont_ctx_st *in_mont)
{
  int v9; // esi
  int v10; // eax
  bignum_ctx *v11; // ebx
  bignum_pool_item *v12; // edi
  bignum_pool_item *v13; // eax
  bn_mont_ctx_st *v14; // ebp
  bn_mont_ctx_st *v15; // eax
  int v16; // edi
  bignum_pool_item *v17; // eax
  bignum_pool_item *v18; // esi
  int v19; // edi
  int v20; // esi
  bignum_pool_item *v21; // eax
  bignum_pool_item *v22; // eax
  int v23; // edi
  int v24; // esi
  bignum_pool_item *v25; // eax
  int v26; // esi
  int v27; // edi
  bignum_pool_item *v28; // eax
  int v29; // ebp
  int i; // esi
  bool v31; // cc
  int v32; // ebx
  bignum_st *j; // edi
  int v34; // ebx
  bignum_pool_item *r; // [esp+4h] [ebp-12Ch]
  bignum_st *ra; // [esp+4h] [ebp-12Ch]
  bn_mont_ctx_st *v37; // [esp+8h] [ebp-128h]
  int v38; // [esp+Ch] [ebp-124h]
  int b; // [esp+10h] [ebp-120h]
  bignum_pool_item *ba; // [esp+10h] [ebp-120h]
  bignum_pool_item *v41; // [esp+14h] [ebp-11Ch]
  int v42; // [esp+18h] [ebp-118h]
  int v43; // [esp+18h] [ebp-118h]
  int v44; // [esp+1Ch] [ebp-114h]
  int v45; // [esp+20h] [ebp-110h]
  bignum_st *v46; // [esp+24h] [ebp-10Ch]
  int v47; // [esp+28h] [ebp-108h]
  bignum_st *v48; // [esp+2Ch] [ebp-104h]
  bignum_st *v49[32]; // [esp+30h] [ebp-100h]
  bignum_st *rm[32]; // [esp+B0h] [ebp-80h]

  v44 = 0;
  v37 = 0;
  if ( (*(_BYTE *)m->d & 1) == 0 )
  {
    ERR_put_error(3u, 118, 102, ".\\crypto\\bn\\bn_exp2.c", 138);
    return 0;
  }
  v9 = BN_num_bits(p1);
  v10 = BN_num_bits(p2);
  b = v10;
  if ( !v9 && !v10 )
    return BN_set_word(rr, 1u);
  v42 = v9;
  if ( v9 <= v10 )
    v42 = v10;
  v11 = ctx;
  BN_CTX_start(ctx);
  r = BN_CTX_get(ctx);
  v12 = BN_CTX_get(ctx);
  v41 = v12;
  rm[0] = (bignum_st *)BN_CTX_get(ctx);
  v13 = BN_CTX_get(ctx);
  v14 = in_mont;
  v49[0] = (bignum_st *)v13;
  if ( r && v12 && rm[0] && v13 )
  {
    if ( in_mont )
    {
      v37 = in_mont;
    }
    else
    {
      v15 = BN_MONT_CTX_new();
      v14 = v15;
      v37 = v15;
      if ( !v15 )
        goto LABEL_94;
      if ( !BN_MONT_CTX_set(v15, m, ctx) )
        goto LABEL_92;
    }
    if ( v9 <= 671 )
    {
      if ( v9 <= 239 )
      {
        if ( v9 <= 79 )
        {
          v16 = 2 * (v9 > 23) + 1;
          v45 = v16;
        }
        else
        {
          v16 = 4;
          v45 = 4;
        }
      }
      else
      {
        v16 = 5;
        v45 = 5;
      }
    }
    else
    {
      v16 = 6;
      v45 = 6;
    }
    if ( b <= 671 )
    {
      if ( b <= 239 )
      {
        if ( b <= 79 )
          v38 = 2 * (b > 23) + 1;
        else
          v38 = 4;
      }
      else
      {
        v38 = 5;
      }
    }
    else
    {
      v38 = 6;
    }
    if ( a1->vals[0].neg || BN_ucmp(a1->vals, m) >= 0 )
    {
      v18 = (bignum_pool_item *)rm[0];
      if ( !BN_div(0, rm[0], a1->vals, m, ctx) )
        goto err_161;
      v17 = (bignum_pool_item *)rm[0];
    }
    else
    {
      v17 = a1;
      v18 = (bignum_pool_item *)rm[0];
    }
    if ( !v17->vals[0].top )
    {
      BN_set_word(rr, 0);
LABEL_89:
      v44 = 1;
      goto err_161;
    }
    ba = (bignum_pool_item *)&v14->RR;
    if ( !BN_mod_mul_montgomery(v18->vals, v17, (bignum_pool_item *)&v14->RR, v14, ctx) )
      goto err_161;
    if ( v16 <= 1 )
      goto LABEL_44;
    if ( !BN_mod_mul_montgomery(r->vals, v18, v18, v14, ctx) )
      goto err_161;
    v19 = 1 << (v16 - 1);
    v20 = 1;
    if ( v19 <= 1 )
    {
LABEL_44:
      if ( a2->vals[0].neg || BN_ucmp(a2->vals, m) >= 0 )
      {
        if ( !BN_div(0, v49[0], a2->vals, m, ctx) )
          goto err_161;
        v22 = (bignum_pool_item *)v49[0];
      }
      else
      {
        v22 = a2;
      }
      if ( !v22->vals[0].top )
      {
        BN_set_word(rr, 0);
        goto LABEL_89;
      }
      if ( !BN_mod_mul_montgomery(v49[0], v22, ba, v14, ctx) )
        goto err_161;
      if ( v38 <= 1 )
        goto LABEL_58;
      if ( !BN_mod_mul_montgomery(r->vals, (bignum_pool_item *)v49[0], (bignum_pool_item *)v49[0], v14, ctx) )
        goto err_161;
      v23 = 1 << (v38 - 1);
      v24 = 1;
      if ( v23 <= 1 )
      {
LABEL_58:
        v26 = 0;
        v47 = 1;
        v27 = 0;
        v46 = 0;
        v48 = 0;
        v28 = (bignum_pool_item *)BN_value_one();
        if ( !BN_mod_mul_montgomery(v41->vals, v28, ba, v14, ctx) )
          goto err_161;
        ra = (bignum_st *)(v42 - 1);
        if ( v42 - 1 < 0 )
        {
LABEL_88:
          if ( !BN_from_montgomery(rr, v41->vals, v37, v11) )
            goto err_161;
          goto LABEL_89;
        }
        v29 = v42 - 2;
        v43 = 2 - v38;
        while ( v47 || BN_mod_mul_montgomery(v41->vals, v41, v41, v37, v11) )
        {
          if ( !v26 && BN_is_bit_set(p1, (int)ra) )
          {
            for ( i = 2 - v45 + v29; !BN_is_bit_set(p1, i); ++i )
              ;
            v31 = v29 < i;
            v46 = (bignum_st *)i;
            v26 = 1;
            v32 = v29;
            if ( !v31 )
            {
              do
              {
                v26 *= 2;
                if ( BN_is_bit_set(p1, v32) )
                  ++v26;
                --v32;
              }
              while ( v32 >= (int)v46 );
            }
          }
          if ( !v27 && BN_is_bit_set(p2, (int)ra) )
          {
            for ( j = (bignum_st *)(v43 + v29); !BN_is_bit_set(p2, (int)j); j = (bignum_st *)((char *)j + 1) )
              ;
            v31 = v29 < (int)j;
            v48 = j;
            v27 = 1;
            v34 = v29;
            if ( !v31 )
            {
              do
              {
                v27 *= 2;
                if ( BN_is_bit_set(p2, v34) )
                  ++v27;
                --v34;
              }
              while ( v34 >= (int)v48 );
            }
          }
          if ( v26 && ra == v46 )
          {
            if ( !BN_mod_mul_montgomery(v41->vals, v41, (bignum_pool_item *)rm[v26 >> 1], v37, ctx) )
              break;
            v26 = 0;
            v47 = 0;
          }
          if ( v27 && ra == v48 )
          {
            if ( !BN_mod_mul_montgomery(v41->vals, v41, (bignum_pool_item *)v49[v27 >> 1], v37, ctx) )
              break;
            v27 = 0;
            v47 = 0;
          }
          v11 = ctx;
          --v29;
          ra = (bignum_st *)((char *)ra - 1);
          if ( (int)ra < 0 )
            goto LABEL_88;
        }
      }
      else
      {
        while ( 1 )
        {
          v25 = BN_CTX_get(ctx);
          v49[v24] = (bignum_st *)v25;
          if ( !v25 || !BN_mod_mul_montgomery(v25->vals, (bignum_pool_item *)v49[v24 - 1], r, v14, ctx) )
            break;
          if ( ++v24 >= v23 )
            goto LABEL_58;
        }
      }
    }
    else
    {
      while ( 1 )
      {
        v21 = BN_CTX_get(ctx);
        rm[v20] = (bignum_st *)v21;
        if ( !v21 || !BN_mod_mul_montgomery(v21->vals, (bignum_pool_item *)v49[v20 + 31], r, v14, ctx) )
          break;
        if ( ++v20 >= v19 )
          goto LABEL_44;
      }
    }
  }
err_161:
  v11 = ctx;
  if ( !in_mont )
  {
    v14 = v37;
LABEL_92:
    if ( v14 )
      BN_MONT_CTX_free(v14);
  }
LABEL_94:
  BN_CTX_end(v11);
  return v44;
}

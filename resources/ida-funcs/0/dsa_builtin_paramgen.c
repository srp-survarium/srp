int __usercall dsa_builtin_paramgen@<eax>(
        int a1@<ebx>,
        dsa_st *ret,
        unsigned int bits,
        unsigned int qbits,
        const env_md_st *evpmd,
        const __m128i *seed_in,
        unsigned int seed_len,
        int *counter_ret,
        unsigned int *h_ret,
        bn_gencb_st *cb)
{
  unsigned int v10; // esi
  unsigned int v13; // eax
  unsigned int v14; // eax
  bool v15; // cc
  bignum_ctx *v16; // ebx
  bignum_pool_item *v17; // ebp
  const bignum_st *v18; // eax
  int v19; // eax
  int v20; // edi
  int v21; // edi
  int i; // eax
  bool v23; // zf
  signed int v24; // eax
  int is_prime_fasttest; // eax
  int v26; // edi
  int j; // eax
  const bignum_st *v28; // eax
  int v29; // eax
  const bignum_st *v30; // eax
  bignum_st *v31; // esi
  const bignum_st *v32; // eax
  bignum_st *p; // eax
  bignum_st *v34; // eax
  bignum_pool_item *num; // [esp+10h] [ebp-C8h]
  bignum_pool_item *reta; // [esp+14h] [ebp-C4h]
  int v37; // [esp+18h] [ebp-C0h]
  const env_md_st *v38; // [esp+1Ch] [ebp-BCh]
  bn_mont_ctx_st *mont; // [esp+20h] [ebp-B8h]
  bignum_pool_item *a; // [esp+24h] [ebp-B4h]
  unsigned int v41; // [esp+28h] [ebp-B0h]
  int v42; // [esp+2Ch] [ebp-ACh]
  signed int v43; // [esp+30h] [ebp-A8h]
  int b; // [esp+34h] [ebp-A4h]
  bignum_pool_item *rm; // [esp+38h] [ebp-A0h]
  bignum_pool_item *mod; // [esp+44h] [ebp-94h]
  bignum_pool_item *r; // [esp+4Ch] [ebp-8Ch]
  bignum_st *rr; // [esp+50h] [ebp-88h]
  unsigned __int8 s[32]; // [esp+54h] [ebp-84h] BYREF
  unsigned __int8 v50[32]; // [esp+74h] [ebp-64h] BYREF
  __m128i dst[2]; // [esp+94h] [ebp-44h] BYREF
  unsigned __int8 v52[32]; // [esp+B4h] [ebp-24h] BYREF
  unsigned int v53; // [esp+E0h] [ebp+8h]

  v10 = qbits >> 3;
  v38 = evpmd;
  v42 = 0;
  b = 0;
  v41 = 2;
  if ( qbits >> 3 != 20 && v10 != 28 && v10 != 32 )
    return 0;
  if ( !evpmd )
    v38 = EVP_sha1();
  v13 = bits;
  if ( bits < 0x200 )
    v13 = 512;
  v53 = (v13 + 63) >> 6 << 6;
  v14 = seed_len;
  if ( !seed_len )
    goto LABEL_12;
  v15 = seed_len <= v10;
  if ( seed_len < v10 )
  {
    seed_in = 0;
LABEL_12:
    v15 = seed_len <= v10;
  }
  if ( !v15 )
  {
    v14 = qbits >> 3;
    seed_len = qbits >> 3;
  }
  if ( seed_in )
    memcpy((int)dst, seed_in, v14);
  v16 = BN_CTX_new(a1);
  if ( v16 )
  {
    mont = BN_MONT_CTX_new();
    if ( mont )
    {
      BN_CTX_start((int)v16, v16);
      v17 = BN_CTX_get((int)v16, v16);
      rr = (bignum_st *)BN_CTX_get((int)v16, v16);
      a = BN_CTX_get((int)v16, v16);
      reta = BN_CTX_get((int)v16, v16);
      r = BN_CTX_get((int)v16, v16);
      rm = BN_CTX_get((int)v16, v16);
      mod = BN_CTX_get((int)v16, v16);
      num = BN_CTX_get((int)v16, v16);
      v18 = BN_value_one();
      if ( BN_lshift(num->vals, v18, v53 - 1) )
      {
LABEL_20:
        do
        {
          v19 = BN_GENCB_call(cb, 0, b);
          v20 = ++b;
          if ( !v19 )
            break;
          if ( seed_len )
          {
            v21 = 0;
            seed_len = 0;
          }
          else
          {
            RAND_pseudo_bytes(v20);
            v21 = 1;
          }
          memcpy((int)v50, dst, v10);
          memcpy((int)v52, dst, v10);
          for ( i = v10 - 1; i >= 0; --i )
          {
            v23 = v50[i]++ == 0xFF;
            if ( !v23 )
              break;
          }
          EVP_Digest(v21, (engine_st *)v16, dst, v10, s, 0, v38, 0);
          EVP_Digest(v21, (engine_st *)v16, v50, v10, v52, 0, v38, 0);
          v24 = 0;
          if ( qbits >> 3 )
          {
            do
            {
              s[v24] ^= v52[v24];
              ++v24;
            }
            while ( v24 < (int)v10 );
          }
          s[0] |= 0x80u;
          s[v10 - 1] |= 1u;
          if ( !BN_bin2bn(s, v10, reta->vals) )
            break;
          is_prime_fasttest = BN_is_prime_fasttest_ex(reta->vals, 50, v16, v21, cb);
          if ( is_prime_fasttest > 0 )
          {
            if ( BN_GENCB_call(cb, 2, 0) && BN_GENCB_call(cb, 3, 0) )
            {
              v37 = 0;
              v43 = (v53 - 1) / 0xA0;
              while ( !v37 || BN_GENCB_call(cb, 0, v37) )
              {
                BN_set_word((int)v16, a->vals, 0);
                v26 = 0;
                if ( v43 >= 0 )
                {
                  do
                  {
                    for ( j = v10 - 1; j >= 0; --j )
                    {
                      v23 = v50[j]++ == 0xFF;
                      if ( !v23 )
                        break;
                    }
                    EVP_Digest(v26, (engine_st *)v16, v50, v10, s, 0, v38, 0);
                    if ( !BN_bin2bn(s, v10, v17->vals)
                      || !BN_lshift(v17->vals, v17->vals, v26 * 8 * v10)
                      || !BN_add(a->vals, a->vals, v17->vals) )
                    {
                      goto LABEL_85;
                    }
                  }
                  while ( ++v26 <= v43 );
                }
                if ( !BN_mask_bits(a->vals, v53 - 1) )
                  goto LABEL_85;
                if ( !BN_copy(r->vals, a->vals) )
                  goto LABEL_85;
                if ( !BN_add(r->vals, r->vals, num->vals) )
                  goto LABEL_85;
                if ( !BN_lshift1(v17->vals, reta->vals) )
                  goto LABEL_85;
                if ( !BN_div(0, rm->vals, r->vals, v17->vals, v16) )
                  goto LABEL_85;
                v28 = BN_value_one();
                if ( !BN_sub(v17->vals, rm->vals, v28) || !BN_sub(mod->vals, r->vals, v17->vals) )
                  goto LABEL_85;
                if ( BN_cmp(mod->vals, num->vals) >= 0 )
                {
                  v29 = BN_is_prime_fasttest_ex(mod->vals, 50, v16, 1, cb);
                  if ( v29 > 0 )
                  {
                    if ( BN_GENCB_call(cb, 2, 1) )
                    {
                      v30 = BN_value_one();
                      if ( BN_sub(num->vals, mod->vals, v30) )
                      {
                        if ( BN_div(v17, 0, num->vals, reta->vals, v16) )
                        {
                          if ( BN_set_word((int)v16, num->vals, 2u) )
                          {
                            if ( BN_MONT_CTX_set(mont, mod->vals, v16) )
                            {
                              v31 = rr;
                              if ( BN_mod_exp_mont((int)v16, rr, num, v17->vals, mod->vals, v16, mont) )
                              {
                                while ( v31->top == 1 && *v31->d == 1 && !v31->neg )
                                {
                                  v32 = BN_value_one();
                                  if ( BN_add(num->vals, num->vals, v32) )
                                  {
                                    ++v41;
                                    if ( BN_mod_exp_mont((int)v16, v31, num, v17->vals, mod->vals, v16, mont) )
                                      continue;
                                  }
                                  goto LABEL_85;
                                }
                                if ( BN_GENCB_call(cb, 3, 1) )
                                {
                                  p = ret->p;
                                  v42 = 1;
                                  if ( p )
                                    BN_free(p);
                                  if ( ret->q )
                                    BN_free(ret->q);
                                  if ( ret->g )
                                    BN_free(ret->g);
                                  ret->p = BN_dup((int)v16, mod->vals);
                                  ret->q = BN_dup((int)v16, reta->vals);
                                  v34 = BN_dup((int)v16, v31);
                                  v23 = ret->p == 0;
                                  ret->g = v34;
                                  if ( !v23 && ret->q && v34 )
                                  {
                                    if ( counter_ret )
                                      *counter_ret = v37;
                                    if ( h_ret )
                                      *h_ret = v41;
                                  }
                                  else
                                  {
                                    v42 = 0;
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                    goto LABEL_85;
                  }
                  if ( v29 )
                    goto LABEL_85;
                }
                if ( ++v37 >= 4096 )
                  goto LABEL_20;
              }
            }
            break;
          }
        }
        while ( !is_prime_fasttest );
      }
    }
LABEL_85:
    BN_CTX_end(v16);
    BN_CTX_free(v16);
    if ( mont )
      BN_MONT_CTX_free(mont);
  }
  return v42;
}

int __cdecl dsa_builtin_paramgen(
        dsa_st *ret,
        unsigned int bits,
        unsigned int qbits,
        const env_md_st *evpmd,
        unsigned __int8 *seed_in,
        unsigned int seed_len,
        int *counter_ret,
        unsigned int *h_ret,
        bn_gencb_st *cb)
{
  unsigned int v9; // esi
  unsigned int v12; // eax
  unsigned int v13; // eax
  bool v14; // cc
  bignum_ctx *v15; // ebx
  bignum_pool_item *v16; // ebp
  const bignum_st *v17; // eax
  unsigned int v19; // edi
  int i; // eax
  bool v21; // zf
  signed int v22; // eax
  int is_prime_fasttest; // eax
  unsigned int v24; // edi
  int j; // eax
  const bignum_st *v26; // eax
  int v27; // eax
  const bignum_st *v28; // eax
  bignum_st *v29; // esi
  const bignum_st *v30; // eax
  bignum_st *p; // eax
  bignum_st *v32; // eax
  bignum_pool_item *num; // [esp+10h] [ebp-C8h]
  bignum_pool_item *reta; // [esp+14h] [ebp-C4h]
  int v35; // [esp+18h] [ebp-C0h]
  const env_md_st *type; // [esp+1Ch] [ebp-BCh]
  bn_mont_ctx_st *mont; // [esp+20h] [ebp-B8h]
  bignum_pool_item *a; // [esp+24h] [ebp-B4h]
  unsigned int v39; // [esp+28h] [ebp-B0h]
  int v40; // [esp+2Ch] [ebp-ACh]
  signed int v41; // [esp+30h] [ebp-A8h]
  int b; // [esp+34h] [ebp-A4h]
  bignum_pool_item *rm; // [esp+38h] [ebp-A0h]
  bignum_pool_item *mod; // [esp+44h] [ebp-94h]
  bignum_pool_item *r; // [esp+4Ch] [ebp-8Ch]
  bignum_st *rr; // [esp+50h] [ebp-88h]
  unsigned __int8 md[32]; // [esp+54h] [ebp-84h] BYREF
  unsigned __int8 data[32]; // [esp+74h] [ebp-64h] BYREF
  unsigned __int8 dst[32]; // [esp+94h] [ebp-44h] BYREF
  unsigned __int8 v50[32]; // [esp+B4h] [ebp-24h] BYREF
  unsigned int v51; // [esp+E0h] [ebp+8h]

  v9 = qbits >> 3;
  type = evpmd;
  v40 = 0;
  b = 0;
  v39 = 2;
  if ( qbits >> 3 != 20 && v9 != 28 && v9 != 32 )
    return 0;
  if ( !evpmd )
    type = EVP_sha1();
  v12 = bits;
  if ( bits < 0x200 )
    v12 = 512;
  v51 = (v12 + 63) >> 6 << 6;
  v13 = seed_len;
  if ( !seed_len )
    goto LABEL_12;
  v14 = seed_len <= v9;
  if ( seed_len < v9 )
  {
    seed_in = 0;
LABEL_12:
    v14 = seed_len <= v9;
  }
  if ( !v14 )
  {
    v13 = qbits >> 3;
    seed_len = qbits >> 3;
  }
  if ( seed_in )
    memcpy(dst, seed_in, v13);
  v15 = BN_CTX_new();
  if ( v15 )
  {
    mont = BN_MONT_CTX_new();
    if ( mont )
    {
      BN_CTX_start(v15);
      v16 = BN_CTX_get(v15);
      rr = (bignum_st *)BN_CTX_get(v15);
      a = BN_CTX_get(v15);
      reta = BN_CTX_get(v15);
      r = BN_CTX_get(v15);
      rm = BN_CTX_get(v15);
      mod = BN_CTX_get(v15);
      num = BN_CTX_get(v15);
      v17 = BN_value_one();
      if ( BN_lshift(num->vals, v17, v51 - 1) )
      {
LABEL_20:
        do
        {
          if ( !BN_GENCB_call(cb, 0, b++) )
            break;
          if ( seed_len )
          {
            v19 = 0;
            seed_len = 0;
          }
          else
          {
            RAND_pseudo_bytes();
            v19 = 1;
          }
          memcpy(data, dst, v9);
          memcpy(v50, dst, v9);
          for ( i = v9 - 1; i >= 0; --i )
          {
            v21 = data[i]++ == 0xFF;
            if ( !v21 )
              break;
          }
          EVP_Digest(v19, dst, v9, md, 0, type, 0);
          EVP_Digest(v19, data, v9, v50, 0, type, 0);
          v22 = 0;
          if ( qbits >> 3 )
          {
            do
            {
              md[v22] ^= v50[v22];
              ++v22;
            }
            while ( v22 < (int)v9 );
          }
          md[0] |= 0x80u;
          md[v9 - 1] |= 1u;
          if ( !BN_bin2bn(md, v9, reta->vals) )
            break;
          is_prime_fasttest = BN_is_prime_fasttest_ex(reta->vals, 50, v15, v19, cb);
          if ( is_prime_fasttest > 0 )
          {
            if ( BN_GENCB_call(cb, 2, 0) && BN_GENCB_call(cb, 3, 0) )
            {
              v35 = 0;
              v41 = (v51 - 1) / 0xA0;
              while ( !v35 || BN_GENCB_call(cb, 0, v35) )
              {
                BN_set_word(a->vals, 0);
                v24 = 0;
                if ( v41 >= 0 )
                {
                  do
                  {
                    for ( j = v9 - 1; j >= 0; --j )
                    {
                      v21 = data[j]++ == 0xFF;
                      if ( !v21 )
                        break;
                    }
                    EVP_Digest(v24, data, v9, md, 0, type, 0);
                    if ( !BN_bin2bn(md, v9, v16->vals)
                      || !BN_lshift(v16->vals, v16->vals, v24 * 8 * v9)
                      || !BN_add(a->vals, a->vals, v16->vals) )
                    {
                      goto LABEL_85;
                    }
                  }
                  while ( (int)++v24 <= v41 );
                }
                if ( !BN_mask_bits(a->vals, v51 - 1) )
                  goto LABEL_85;
                if ( !BN_copy(r->vals, a->vals) )
                  goto LABEL_85;
                if ( !BN_add(r->vals, r->vals, num->vals) )
                  goto LABEL_85;
                if ( !BN_lshift1(v16->vals, reta->vals) )
                  goto LABEL_85;
                if ( !BN_div(0, rm->vals, r->vals, v16->vals, v15) )
                  goto LABEL_85;
                v26 = BN_value_one();
                if ( !BN_sub(v16->vals, rm->vals, v26) || !BN_sub(mod->vals, r->vals, v16->vals) )
                  goto LABEL_85;
                if ( BN_cmp(mod->vals, num->vals) >= 0 )
                {
                  v27 = BN_is_prime_fasttest_ex(mod->vals, 50, v15, 1, cb);
                  if ( v27 > 0 )
                  {
                    if ( BN_GENCB_call(cb, 2, 1) )
                    {
                      v28 = BN_value_one();
                      if ( BN_sub(num->vals, mod->vals, v28) )
                      {
                        if ( BN_div(v16->vals, 0, num->vals, reta->vals, v15) )
                        {
                          if ( BN_set_word(num->vals, 2u) )
                          {
                            if ( BN_MONT_CTX_set(mont, mod->vals, v15) )
                            {
                              v29 = rr;
                              if ( BN_mod_exp_mont(rr, num->vals, v16->vals, mod->vals, v15, mont) )
                              {
                                while ( v29->top == 1 && *v29->d == 1 && !v29->neg )
                                {
                                  v30 = BN_value_one();
                                  if ( BN_add(num->vals, num->vals, v30) )
                                  {
                                    ++v39;
                                    if ( BN_mod_exp_mont(v29, num->vals, v16->vals, mod->vals, v15, mont) )
                                      continue;
                                  }
                                  goto LABEL_85;
                                }
                                if ( BN_GENCB_call(cb, 3, 1) )
                                {
                                  p = ret->p;
                                  v40 = 1;
                                  if ( p )
                                    BN_free(p);
                                  if ( ret->q )
                                    BN_free(ret->q);
                                  if ( ret->g )
                                    BN_free(ret->g);
                                  ret->p = BN_dup(mod->vals);
                                  ret->q = BN_dup(reta->vals);
                                  v32 = BN_dup(v29);
                                  v21 = ret->p == 0;
                                  ret->g = v32;
                                  if ( !v21 && ret->q && v32 )
                                  {
                                    if ( counter_ret )
                                      *counter_ret = v35;
                                    if ( h_ret )
                                      *h_ret = v39;
                                  }
                                  else
                                  {
                                    v40 = 0;
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
                  if ( v27 )
                    goto LABEL_85;
                }
                if ( ++v35 >= 4096 )
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
    BN_CTX_end(v15);
    BN_CTX_free(v15);
    if ( mont )
      BN_MONT_CTX_free(mont);
  }
  return v40;
}

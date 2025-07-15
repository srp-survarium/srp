int __usercall BN_is_prime_fasttest_ex@<eax>(
        int a1@<ebx>,
        bignum_st *a,
        int checks,
        bignum_ctx *ctx_passed,
        int do_trial_division,
        bn_gencb_st *cb)
{
  const bignum_st *v6; // eax
  int result; // eax
  const unsigned __int16 *v8; // edi
  bignum_ctx *v9; // edi
  bignum_pool_item *v10; // eax
  bignum_pool_item *v11; // ebp
  bignum_pool_item *v12; // esi
  int v13; // ebx
  bn_mont_ctx_st *v14; // eax
  int v15; // eax
  int v16; // ebx
  bignum_st *b; // [esp+8h] [ebp-18h]
  bn_mont_ctx_st *mont; // [esp+Ch] [ebp-14h]
  int v19; // [esp+10h] [ebp-10h]
  int v20; // [esp+14h] [ebp-Ch]
  bignum_pool_item *r; // [esp+18h] [ebp-8h]
  int v22; // [esp+1Ch] [ebp-4h]

  v19 = -1;
  mont = 0;
  v6 = BN_value_one();
  if ( BN_cmp(a, v6) <= 0 )
    return 0;
  if ( !checks )
  {
    if ( BN_num_bits(a) < 1300 )
    {
      if ( BN_num_bits(a) < 850 )
      {
        if ( BN_num_bits(a) < 650 )
        {
          if ( BN_num_bits(a) < 550 )
          {
            if ( BN_num_bits(a) < 450 )
            {
              if ( BN_num_bits(a) < 400 )
              {
                if ( BN_num_bits(a) < 350 )
                {
                  if ( BN_num_bits(a) < 300 )
                  {
                    if ( BN_num_bits(a) < 250 )
                    {
                      if ( BN_num_bits(a) < 200 )
                        checks = BN_num_bits(a) < 150 ? 27 : 18;
                      else
                        checks = 15;
                    }
                    else
                    {
                      checks = 12;
                    }
                  }
                  else
                  {
                    checks = 9;
                  }
                }
                else
                {
                  checks = 8;
                }
              }
              else
              {
                checks = 7;
              }
            }
            else
            {
              checks = 6;
            }
          }
          else
          {
            checks = 5;
          }
        }
        else
        {
          checks = 4;
        }
      }
      else
      {
        checks = 3;
      }
    }
    else
    {
      checks = 2;
    }
  }
  result = a->top;
  if ( result > 0 && (*(_BYTE *)a->d & 1) != 0 )
  {
    if ( do_trial_division )
    {
      v8 = &primes[1];
      do
      {
        if ( !BN_mod_word(a, *v8) )
          return 0;
        ++v8;
      }
      while ( (int)v8 < (int)"%lu:%s:%s:%d:%s\n" );
      if ( !BN_GENCB_call(cb, 1, -1) )
        return v19;
    }
    v9 = ctx_passed;
    if ( !ctx_passed )
    {
      v9 = BN_CTX_new(a1);
      if ( !v9 )
        return v19;
    }
    BN_CTX_start(a1, v9);
    if ( a->neg )
    {
      v10 = BN_CTX_get(a1, v9);
      a1 = (int)v10;
      if ( !v10 )
      {
err_195:
        if ( v9 )
        {
          BN_CTX_end(v9);
          if ( !ctx_passed )
            BN_CTX_free(v9);
        }
        if ( mont )
          BN_MONT_CTX_free(mont);
        return v19;
      }
      BN_copy(v10->vals, a);
      *(_DWORD *)(a1 + 12) = 0;
      b = (bignum_st *)a1;
    }
    else
    {
      b = a;
    }
    v11 = BN_CTX_get(a1, v9);
    r = BN_CTX_get(a1, v9);
    v12 = BN_CTX_get(a1, v9);
    if ( v12 && BN_copy(v11->vals, b) && BN_sub_word(a1, v11->vals, 1u) )
    {
      if ( v11->vals[0].top )
      {
        v13 = 1;
        v20 = 1;
        if ( !BN_is_bit_set(v11->vals, 1) )
        {
          do
            ++v13;
          while ( !BN_is_bit_set(v11->vals, v13) );
          v20 = v13;
        }
        if ( BN_rshift(r->vals, v11->vals, v13) )
        {
          v14 = BN_MONT_CTX_new();
          mont = v14;
          if ( v14 )
          {
            if ( BN_MONT_CTX_set(v13, v14, b, v9) )
            {
              v22 = 0;
              if ( checks <= 0 )
              {
LABEL_59:
                v19 = 1;
              }
              else
              {
                while ( BN_pseudo_rand_range(v13, v12->vals, v11->vals) )
                {
                  if ( !BN_add_word(v13, v12->vals, 1u) )
                    break;
                  v15 = witness(v12, b, r->vals, v9, v11->vals, v13, mont);
                  if ( v15 == -1 )
                    break;
                  if ( v15 )
                    goto LABEL_43;
                  v16 = v22;
                  if ( !BN_GENCB_call(cb, 1, v22) )
                    break;
                  ++v22;
                  if ( v16 + 1 >= checks )
                    goto LABEL_59;
                  v13 = v20;
                }
              }
            }
          }
        }
      }
      else
      {
LABEL_43:
        v19 = 0;
      }
    }
    goto err_195;
  }
  if ( result != 1 || *a->d != 2 || a->neg )
    return 0;
  return result;
}

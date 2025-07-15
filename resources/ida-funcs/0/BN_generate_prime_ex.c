int __cdecl BN_generate_prime_ex(
        bignum_st *ret,
        int bits,
        int safe,
        const bignum_st *add,
        const bignum_st *rem,
        bn_gencb_st *cb)
{
  const bignum_st *v6; // ebx
  bignum_ctx *v7; // eax
  bignum_ctx *v8; // ebp
  int v9; // eax
  int v10; // eax
  void (__cdecl *cb_1)(int, int, void *); // eax
  int v12; // eax
  int i; // ebx
  int is_prime_fasttest; // eax
  int v16; // eax
  int v17; // [esp-10h] [ebp-2Ch]
  int checks; // [esp+Ch] [ebp-10h]
  int v19; // [esp+10h] [ebp-Ch]
  bignum_pool_item *r; // [esp+14h] [ebp-8h]
  int v21; // [esp+18h] [ebp-4h]

  v6 = (const bignum_st *)bits;
  v21 = 0;
  v19 = 0;
  if ( bits < 1300 )
  {
    if ( bits < 850 )
    {
      if ( bits < 650 )
      {
        if ( bits < 550 )
        {
          if ( bits < 450 )
          {
            if ( bits < 400 )
            {
              if ( bits < 350 )
              {
                if ( bits < 300 )
                {
                  if ( bits < 250 )
                  {
                    if ( bits < 200 )
                      checks = bits < 150 ? 27 : 18;
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
  v7 = BN_CTX_new(bits);
  v8 = v7;
  if ( !v7 )
    return 0;
  BN_CTX_start(bits, v7);
  r = BN_CTX_get(bits, v8);
  if ( r )
  {
    while ( 1 )
    {
      if ( add )
      {
        v17 = (int)v6;
        if ( safe )
        {
          v6 = (const bignum_st *)v8;
          v9 = probable_prime_dh_safe(v8, ret, v17, add, rem);
        }
        else
        {
          v6 = rem;
          v9 = probable_prime_dh(ret, rem, v17, add, v8);
        }
      }
      else
      {
        v9 = probable_prime(ret, (int)v6);
      }
      if ( !v9 )
        goto err_196;
      if ( !cb )
        goto LABEL_39;
      if ( cb->ver == 1 )
        break;
      if ( cb->ver == 2 )
        v10 = ((int (__cdecl *)(_DWORD, int, bn_gencb_st *))cb->cb.cb_1)(0, v19, cb);
      else
        v10 = 0;
LABEL_40:
      ++v19;
      if ( !v10 )
        goto err_196;
      if ( safe )
      {
        if ( BN_rshift1(r->vals, ret) )
        {
          for ( i = 0; i < checks; ++i )
          {
            is_prime_fasttest = BN_is_prime_fasttest_ex(i, ret, 1, v8, 0, cb);
            if ( is_prime_fasttest == -1 )
              goto err_196;
            if ( !is_prime_fasttest )
              goto LABEL_25;
            v16 = BN_is_prime_fasttest_ex(i, r->vals, 1, v8, 0, cb);
            if ( v16 == -1 )
              goto err_196;
            if ( !v16 )
              goto LABEL_25;
            if ( !BN_GENCB_call(cb, 2, v19 - 1) )
              goto err_196;
          }
LABEL_44:
          v21 = 1;
          goto err_196;
        }
        goto err_196;
      }
      v12 = BN_is_prime_fasttest_ex((int)v6, ret, checks, v8, 0, cb);
      if ( v12 == -1 )
        goto err_196;
      if ( v12 )
        goto LABEL_44;
LABEL_25:
      v6 = (const bignum_st *)bits;
    }
    cb_1 = cb->cb.cb_1;
    if ( cb_1 )
      cb_1(0, v19, cb->arg);
LABEL_39:
    v10 = 1;
    goto LABEL_40;
  }
err_196:
  BN_CTX_end(v8);
  BN_CTX_free(v8);
  return v21;
}

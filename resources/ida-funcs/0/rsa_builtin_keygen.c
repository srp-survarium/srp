int __usercall rsa_builtin_keygen@<eax>(
        int bits@<ecx>,
        rsa_st *rsa@<edx>,
        int a3@<ebx>,
        bignum_st *e_value,
        bn_gencb_st *cb)
{
  bignum_ctx *v7; // eax
  bignum_ctx *v8; // ebx
  int v9; // ebx
  bignum_st *v10; // eax
  bignum_st *v11; // eax
  bignum_st *v12; // eax
  bignum_st *v13; // eax
  bignum_st *v14; // eax
  bignum_st *v15; // eax
  bignum_st *v16; // eax
  bignum_st *v17; // eax
  const bignum_st *v18; // eax
  int v19; // eax
  int v20; // esi
  int v22; // edi
  const bignum_st *v23; // eax
  bignum_st *p; // eax
  const bignum_st *v26; // eax
  const bignum_st *v27; // eax
  bignum_st *p_n; // eax
  bignum_st *v29; // eax
  bignum_st *d; // edi
  bignum_st *v31; // eax
  bignum_st *v32; // ecx
  bignum_ctx *ctx; // [esp+10h] [ebp-54h]
  int v34; // [esp+14h] [ebp-50h]
  bignum_pool_item *r; // [esp+18h] [ebp-4Ch]
  bignum_pool_item *divisor; // [esp+1Ch] [ebp-48h]
  int v37; // [esp+20h] [ebp-44h]
  bignum_pool_item *v38; // [esp+24h] [ebp-40h]
  bignum_st n; // [esp+28h] [ebp-3Ch] BYREF
  bignum_st num; // [esp+3Ch] [ebp-28h] BYREF
  bignum_st v41; // [esp+50h] [ebp-14h] BYREF

  v34 = 0;
  v7 = BN_CTX_new(a3);
  v8 = v7;
  ctx = v7;
  if ( v7 )
  {
    BN_CTX_start((int)v7, v7);
    v38 = BN_CTX_get((int)v8, v8);
    divisor = BN_CTX_get((int)v8, v8);
    r = BN_CTX_get((int)v8, v8);
    if ( BN_CTX_get((int)v8, v8) )
    {
      v9 = (bits + 1) / 2;
      v37 = bits - v9;
      if ( rsa->n || (v10 = BN_new(v9), (rsa->n = v10) != 0) )
      {
        if ( rsa->d || (v11 = BN_new(v9), (rsa->d = v11) != 0) )
        {
          if ( rsa->e || (v12 = BN_new(v9), (rsa->e = v12) != 0) )
          {
            if ( rsa->p || (v13 = BN_new(v9), (rsa->p = v13) != 0) )
            {
              if ( rsa->q || (v14 = BN_new(v9), (rsa->q = v14) != 0) )
              {
                if ( rsa->dmp1 || (v15 = BN_new(v9), (rsa->dmp1 = v15) != 0) )
                {
                  if ( rsa->dmq1 || (v16 = BN_new(v9), (rsa->dmq1 = v16) != 0) )
                  {
                    if ( rsa->iqmp || (v17 = BN_new(v9), (rsa->iqmp = v17) != 0) )
                    {
                      BN_copy(rsa->e, e_value);
                      if ( BN_generate_prime_ex(rsa->p, v9, 0, 0, 0, cb) )
                      {
                        do
                        {
                          v18 = BN_value_one();
                          if ( !BN_sub(r->vals, rsa->p, v18) || !BN_gcd(divisor->vals, r->vals, rsa->e, ctx) )
                            break;
                          if ( divisor->vals[0].top == 1 && *divisor->vals[0].d == 1 && !divisor->vals[0].neg )
                          {
                            if ( BN_GENCB_call(cb, 3, 0) )
                            {
LABEL_33:
                              v22 = 0;
                              while ( BN_generate_prime_ex(rsa->q, v37, 0, 0, 0, cb) )
                              {
                                if ( !BN_cmp(rsa->p, rsa->q) && (unsigned int)++v22 < 3 )
                                  continue;
                                if ( v22 == 3 )
                                {
                                  v20 = 0;
                                  ERR_put_error(v9, 4u, 129, 120, ".\\crypto\\rsa\\rsa_gen.c", 144);
                                  v8 = ctx;
                                  goto LABEL_29;
                                }
                                v23 = BN_value_one();
                                if ( BN_sub(r->vals, rsa->q, v23) )
                                {
                                  v9 = (int)divisor;
                                  if ( BN_gcd(divisor->vals, r->vals, rsa->e, ctx) )
                                  {
                                    if ( divisor->vals[0].top == 1 && *divisor->vals[0].d == 1 && !divisor->vals[0].neg )
                                    {
                                      if ( BN_GENCB_call(cb, 3, 1) )
                                      {
                                        if ( BN_cmp(rsa->p, rsa->q) < 0 )
                                        {
                                          p = rsa->p;
                                          rsa->p = rsa->q;
                                          rsa->q = p;
                                        }
                                        if ( BN_mul(
                                               (bignum_pool_item *)rsa->n,
                                               (bignum_pool_item *)rsa->p,
                                               (bignum_pool_item *)rsa->q,
                                               ctx) )
                                        {
                                          v26 = BN_value_one();
                                          if ( BN_sub(divisor->vals, rsa->p, v26) )
                                          {
                                            v27 = BN_value_one();
                                            if ( BN_sub(r->vals, rsa->q, v27) )
                                            {
                                              if ( BN_mul(v38, divisor, r, ctx) )
                                              {
                                                if ( (rsa->flags & 0x100) != 0 )
                                                {
                                                  p_n = (bignum_st *)v38;
                                                }
                                                else
                                                {
                                                  n.d = v38->vals[0].d;
                                                  n.top = v38->vals[0].top;
                                                  n.dmax = v38->vals[0].dmax;
                                                  n.neg = v38->vals[0].neg;
                                                  p_n = &n;
                                                  n.flags = n.flags & 1 | v38->vals[0].flags & 0xFFFFFFFE | 6;
                                                }
                                                if ( BN_mod_inverse((int)divisor, rsa->d, rsa->e, p_n, ctx) )
                                                {
                                                  if ( (rsa->flags & 0x100) != 0 )
                                                  {
                                                    d = rsa->d;
                                                  }
                                                  else
                                                  {
                                                    v29 = rsa->d;
                                                    num.d = v29->d;
                                                    num.top = v29->top;
                                                    num.dmax = v29->dmax;
                                                    num.neg = v29->neg;
                                                    d = &num;
                                                    num.flags = num.flags & 1 | v29->flags & 0xFFFFFFFE | 6;
                                                  }
                                                  if ( BN_div(0, rsa->dmp1, d, divisor->vals, ctx)
                                                    && BN_div(0, rsa->dmq1, d, r->vals, ctx) )
                                                  {
                                                    if ( (rsa->flags & 0x100) != 0 )
                                                    {
                                                      v32 = rsa->p;
                                                    }
                                                    else
                                                    {
                                                      v31 = rsa->p;
                                                      v41.d = v31->d;
                                                      v41.top = v31->top;
                                                      v41.dmax = v31->dmax;
                                                      v41.neg = v31->neg;
                                                      v32 = &v41;
                                                      v41.flags = v41.flags & 1 | v31->flags & 0xFFFFFFFE | 6;
                                                    }
                                                    if ( BN_mod_inverse((int)divisor, rsa->iqmp, rsa->q, v32, ctx) )
                                                    {
                                                      v8 = ctx;
                                                      v20 = 1;
                                                      goto LABEL_29;
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                    else if ( BN_GENCB_call(cb, 2, v34++) )
                                    {
                                      goto LABEL_33;
                                    }
                                  }
                                }
                                goto LABEL_27;
                              }
                            }
                            break;
                          }
                          v19 = BN_GENCB_call(cb, 2, v34++);
                        }
                        while ( v19 && BN_generate_prime_ex(rsa->p, v9, 0, 0, 0, cb) );
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
LABEL_27:
      v8 = ctx;
    }
  }
  ERR_put_error((int)v8, 4u, 129, 3, ".\\crypto\\rsa\\rsa_gen.c", 208);
  v20 = 0;
LABEL_29:
  if ( v8 )
  {
    BN_CTX_end(v8);
    BN_CTX_free(v8);
  }
  return v20;
}

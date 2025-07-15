int __fastcall rsa_builtin_keygen(int bits, rsa_st *rsa, bignum_st *e_value, bn_gencb_st *cb)
{
  bignum_ctx *v6; // eax
  bignum_ctx *v7; // ebx
  int v8; // ebx
  bignum_st *v9; // eax
  bignum_st *v10; // eax
  bignum_st *v11; // eax
  bignum_st *v12; // eax
  bignum_st *v13; // eax
  bignum_st *v14; // eax
  bignum_st *v15; // eax
  bignum_st *v16; // eax
  const bignum_st *v17; // eax
  int v18; // eax
  int v19; // esi
  int v21; // edi
  const bignum_st *v22; // eax
  bignum_st *p; // eax
  const bignum_st *v25; // eax
  const bignum_st *v26; // eax
  bignum_st *p_n; // eax
  bignum_st *v28; // eax
  bignum_st *d; // edi
  bignum_st *v30; // eax
  bignum_st *v31; // ecx
  bignum_ctx *ctx; // [esp+10h] [ebp-54h]
  int v33; // [esp+14h] [ebp-50h]
  bignum_pool_item *r; // [esp+18h] [ebp-4Ch]
  bignum_pool_item *a; // [esp+1Ch] [ebp-48h]
  int v36; // [esp+20h] [ebp-44h]
  bignum_pool_item *v37; // [esp+24h] [ebp-40h]
  bignum_st n; // [esp+28h] [ebp-3Ch] BYREF
  bignum_st num; // [esp+3Ch] [ebp-28h] BYREF
  bignum_st v40; // [esp+50h] [ebp-14h] BYREF

  v33 = 0;
  v6 = BN_CTX_new();
  v7 = v6;
  ctx = v6;
  if ( v6 )
  {
    BN_CTX_start(v6);
    v37 = BN_CTX_get(v7);
    a = BN_CTX_get(v7);
    r = BN_CTX_get(v7);
    if ( BN_CTX_get(v7) )
    {
      v8 = (bits + 1) / 2;
      v36 = bits - v8;
      if ( rsa->n || (v9 = BN_new(), (rsa->n = v9) != 0) )
      {
        if ( rsa->d || (v10 = BN_new(), (rsa->d = v10) != 0) )
        {
          if ( rsa->e || (v11 = BN_new(), (rsa->e = v11) != 0) )
          {
            if ( rsa->p || (v12 = BN_new(), (rsa->p = v12) != 0) )
            {
              if ( rsa->q || (v13 = BN_new(), (rsa->q = v13) != 0) )
              {
                if ( rsa->dmp1 || (v14 = BN_new(), (rsa->dmp1 = v14) != 0) )
                {
                  if ( rsa->dmq1 || (v15 = BN_new(), (rsa->dmq1 = v15) != 0) )
                  {
                    if ( rsa->iqmp || (v16 = BN_new(), (rsa->iqmp = v16) != 0) )
                    {
                      BN_copy(rsa->e, e_value);
                      if ( BN_generate_prime_ex(rsa->p, v8, 0, 0, 0, cb) )
                      {
                        do
                        {
                          v17 = BN_value_one();
                          if ( !BN_sub(r->vals, rsa->p, v17) || !BN_gcd(a->vals, r->vals, rsa->e, ctx) )
                            break;
                          if ( a->vals[0].top == 1 && *a->vals[0].d == 1 && !a->vals[0].neg )
                          {
                            if ( BN_GENCB_call(cb, 3, 0) )
                            {
LABEL_33:
                              v21 = 0;
                              while ( BN_generate_prime_ex(rsa->q, v36, 0, 0, 0, cb) )
                              {
                                if ( !BN_cmp(rsa->p, rsa->q) && (unsigned int)++v21 < 3 )
                                  continue;
                                if ( v21 == 3 )
                                {
                                  v19 = 0;
                                  ERR_put_error(4u, 129, 120, ".\\crypto\\rsa\\rsa_gen.c", 144);
                                  v7 = ctx;
                                  goto LABEL_29;
                                }
                                v22 = BN_value_one();
                                if ( BN_sub(r->vals, rsa->q, v22) && BN_gcd(a->vals, r->vals, rsa->e, ctx) )
                                {
                                  if ( a->vals[0].top == 1 && *a->vals[0].d == 1 && !a->vals[0].neg )
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
                                        v25 = BN_value_one();
                                        if ( BN_sub(a->vals, rsa->p, v25) )
                                        {
                                          v26 = BN_value_one();
                                          if ( BN_sub(r->vals, rsa->q, v26) )
                                          {
                                            if ( BN_mul(v37, a, r, ctx) )
                                            {
                                              if ( (rsa->flags & 0x100) != 0 )
                                              {
                                                p_n = (bignum_st *)v37;
                                              }
                                              else
                                              {
                                                n.d = v37->vals[0].d;
                                                n.top = v37->vals[0].top;
                                                n.dmax = v37->vals[0].dmax;
                                                n.neg = v37->vals[0].neg;
                                                p_n = &n;
                                                n.flags = n.flags & 1 | v37->vals[0].flags & 0xFFFFFFFE | 6;
                                              }
                                              if ( BN_mod_inverse(rsa->d, rsa->e, p_n, ctx) )
                                              {
                                                if ( (rsa->flags & 0x100) != 0 )
                                                {
                                                  d = rsa->d;
                                                }
                                                else
                                                {
                                                  v28 = rsa->d;
                                                  num.d = v28->d;
                                                  num.top = v28->top;
                                                  num.dmax = v28->dmax;
                                                  num.neg = v28->neg;
                                                  d = &num;
                                                  num.flags = num.flags & 1 | v28->flags & 0xFFFFFFFE | 6;
                                                }
                                                if ( BN_div(0, rsa->dmp1, d, a->vals, ctx)
                                                  && BN_div(0, rsa->dmq1, d, r->vals, ctx) )
                                                {
                                                  if ( (rsa->flags & 0x100) != 0 )
                                                  {
                                                    v31 = rsa->p;
                                                  }
                                                  else
                                                  {
                                                    v30 = rsa->p;
                                                    v40.d = v30->d;
                                                    v40.top = v30->top;
                                                    v40.dmax = v30->dmax;
                                                    v40.neg = v30->neg;
                                                    v31 = &v40;
                                                    v40.flags = v40.flags & 1 | v30->flags & 0xFFFFFFFE | 6;
                                                  }
                                                  if ( BN_mod_inverse(rsa->iqmp, rsa->q, v31, ctx) )
                                                  {
                                                    v7 = ctx;
                                                    v19 = 1;
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
                                  else if ( BN_GENCB_call(cb, 2, v33++) )
                                  {
                                    goto LABEL_33;
                                  }
                                }
                                goto LABEL_27;
                              }
                            }
                            break;
                          }
                          v18 = BN_GENCB_call(cb, 2, v33++);
                        }
                        while ( v18 && BN_generate_prime_ex(rsa->p, v8, 0, 0, 0, cb) );
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
      v7 = ctx;
    }
  }
  ERR_put_error(4u, 129, 3, ".\\crypto\\rsa\\rsa_gen.c", 208);
  v19 = 0;
LABEL_29:
  if ( v7 )
  {
    BN_CTX_end(v7);
    BN_CTX_free(v7);
  }
  return v19;
}

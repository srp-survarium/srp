int __cdecl RSA_eay_mod_exp(bignum_st *r0, const bignum_st *I, rsa_st *rsa, bignum_ctx *ctx)
{
  bignum_st *v4; // ebx
  bignum_st *v5; // eax
  bool v6; // zf
  bignum_st *p; // eax
  bignum_st *p_a; // ebp
  bignum_st *q; // eax
  int dmax; // ecx
  unsigned int *d; // edx
  int flags; // eax
  bignum_st *v13; // edx
  int v14; // eax
  bignum_st *v15; // eax
  bignum_st *dmq1; // ecx
  int v17; // edx
  unsigned int *v18; // eax
  int v19; // ecx
  bignum_st *v20; // eax
  int v21; // eax
  bignum_st *v22; // eax
  bignum_st *dmp1; // ecx
  const bignum_st *v24; // eax
  bignum_st *v25; // eax
  const bignum_st *v26; // eax
  bignum_st *e; // ecx
  bignum_st *n; // eax
  bignum_st *v29; // ebx
  bignum_st *v30; // eax
  bignum_st *v31; // ecx
  bignum_st *b; // [esp+10h] [ebp-88h]
  const bignum_st *mod; // [esp+14h] [ebp-84h]
  int v35; // [esp+18h] [ebp-80h]
  bignum_st v36; // [esp+1Ch] [ebp-7Ch] BYREF
  bignum_st v37; // [esp+30h] [ebp-68h] BYREF
  bignum_st *rm; // [esp+44h] [ebp-54h]
  bignum_st a; // [esp+48h] [ebp-50h] BYREF
  _DWORD v40[4]; // [esp+5Ch] [ebp-3Ch] BYREF
  unsigned int v41; // [esp+6Ch] [ebp-2Ch]
  _DWORD v42[4]; // [esp+70h] [ebp-28h] BYREF
  unsigned int v43; // [esp+80h] [ebp-18h]
  bignum_st v44; // [esp+84h] [ebp-14h] BYREF

  v35 = 0;
  BN_CTX_start(ctx);
  v4 = BN_CTX_get(ctx);
  b = BN_CTX_get(ctx);
  v5 = BN_CTX_get(ctx);
  v6 = (rsa->flags & 0x100) == 0;
  rm = v5;
  if ( v6 )
  {
    BN_init(&a);
    p = rsa->p;
    a.d = p->d;
    a.top = p->top;
    a.dmax = p->dmax;
    a.neg = p->neg;
    p_a = &a;
    a.flags = a.flags & 1 | p->flags & 0xFFFFFFFE | 6;
    BN_init(&v36);
    mod = &v36;
    q = rsa->q;
    v36.d = q->d;
    v36.top = q->top;
    v36.dmax = q->dmax;
    v36.neg = q->neg;
    v36.flags = v36.flags & 1 | q->flags & 0xFFFFFFFE | 6;
  }
  else
  {
    p_a = rsa->p;
    mod = rsa->q;
  }
  if ( ((rsa->flags & 4) == 0
     || BN_MONT_CTX_set_locked(&rsa->_method_mod_p, 9, p_a, ctx)
     && BN_MONT_CTX_set_locked(&rsa->_method_mod_q, 9, mod, ctx))
    && ((rsa->flags & 2) == 0 || BN_MONT_CTX_set_locked(&rsa->_method_mod_n, 9, rsa->n, ctx)) )
  {
    if ( (rsa->flags & 0x100) != 0 )
    {
      v14 = BN_div(0, v4, I, rsa->q, ctx);
    }
    else
    {
      dmax = I->dmax;
      d = I->d;
      v37.top = I->top;
      flags = I->flags;
      v37.dmax = dmax;
      v37.d = d;
      v37.neg = I->neg;
      v13 = rsa->q;
      v37.flags = v37.flags & 1 | flags & 0xFFFFFFFE | 6;
      v14 = BN_div(0, v4, &v37, v13, ctx);
    }
    if ( v14 )
    {
      if ( (rsa->flags & 0x100) != 0 )
      {
        dmq1 = rsa->dmq1;
      }
      else
      {
        v15 = rsa->dmq1;
        v40[0] = v15->d;
        v40[1] = v15->top;
        v40[2] = v15->dmax;
        v40[3] = v15->neg;
        dmq1 = (bignum_st *)v40;
        v41 = v41 & 1 | v15->flags & 0xFFFFFFFE | 6;
      }
      if ( rsa->meth->bn_mod_exp(b, v4, dmq1, rsa->q, ctx, rsa->_method_mod_q) )
      {
        if ( (rsa->flags & 0x100) != 0 )
        {
          v21 = BN_div(0, v4, I, rsa->p, ctx);
        }
        else
        {
          v17 = I->dmax;
          v18 = I->d;
          v37.top = I->top;
          v19 = I->flags;
          v37.dmax = v17;
          v37.d = v18;
          v37.neg = I->neg;
          v20 = rsa->p;
          v37.flags = v37.flags & 1 | v19 & 0xFFFFFFFE | 6;
          v21 = BN_div(0, v4, &v37, v20, ctx);
        }
        if ( v21 )
        {
          if ( (rsa->flags & 0x100) != 0 )
          {
            dmp1 = rsa->dmp1;
          }
          else
          {
            v22 = rsa->dmp1;
            v42[0] = v22->d;
            v42[1] = v22->top;
            v42[2] = v22->dmax;
            v42[3] = v22->neg;
            dmp1 = (bignum_st *)v42;
            v43 = v43 & 1 | v22->flags & 0xFFFFFFFE | 6;
          }
          if ( rsa->meth->bn_mod_exp(r0, v4, dmp1, rsa->p, ctx, rsa->_method_mod_p) && BN_sub(r0, r0, b) )
          {
            v24 = r0;
            if ( r0->neg )
            {
              if ( !BN_add(r0, r0, rsa->p) )
                goto err_109;
              v24 = r0;
            }
            if ( BN_mul(v4, v24, rsa->iqmp, ctx) )
            {
              if ( (rsa->flags & 0x100) != 0 )
              {
                v25 = v4;
              }
              else
              {
                v44.d = v4->d;
                v44.top = v4->top;
                v44.dmax = v4->dmax;
                v44.neg = v4->neg;
                v25 = &v44;
                v44.flags = v44.flags & 1 | v4->flags & 0xFFFFFFFE | 6;
              }
              if ( BN_div(0, r0, v25, rsa->p, ctx) )
              {
                v26 = r0;
                if ( r0->neg )
                {
                  if ( !BN_add(r0, r0, rsa->p) )
                    goto err_109;
                  v26 = r0;
                }
                if ( BN_mul(v4, v26, rsa->q, ctx) && BN_add(r0, v4, b) )
                {
                  e = rsa->e;
                  if ( !e )
                    goto LABEL_51;
                  n = rsa->n;
                  if ( !n )
                    goto LABEL_51;
                  v29 = rm;
                  if ( rsa->meth->bn_mod_exp(rm, r0, e, n, ctx, rsa->_method_mod_n)
                    && BN_sub(v29, v29, I)
                    && BN_div(0, v29, v29, rsa->n, ctx)
                    && (!v29->neg || BN_add(v29, v29, rsa->n)) )
                  {
                    if ( !v29->top
                      || ((rsa->flags & 0x100) != 0
                        ? (v31 = rsa->d)
                        : (bignum_st *)(v30 = rsa->d,
                                        v36.d = v30->d,
                                        v36.top = v30->top,
                                        v36.dmax = v30->dmax,
                                        v36.neg = v30->neg,
                                        v31 = &v36,
                                        v36.flags = v36.flags & 1 | v30->flags & 0xFFFFFFFE | 6),
                          rsa->meth->bn_mod_exp(r0, I, v31, rsa->n, ctx, rsa->_method_mod_n)) )
                    {
LABEL_51:
                      v35 = 1;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
err_109:
  BN_CTX_end(ctx);
  return v35;
}

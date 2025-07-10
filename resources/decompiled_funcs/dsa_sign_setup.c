int __cdecl dsa_sign_setup(dsa_st *dsa, bignum_ctx *ctx_in, bignum_st **kinvp, bignum_st **rp)
{
  bignum_st *v4; // edi
  bignum_ctx *v5; // ebp
  int flags; // eax
  int v7; // ebx
  bignum_st *p_a; // ecx
  int (__cdecl *bn_mod_exp)(dsa_st *, bignum_st *, bignum_st *, const bignum_st *, const bignum_st *, bignum_ctx *, bn_mont_ctx_st *); // eax
  bignum_st *v11; // esi
  bn_mont_ctx_st *method_mont_p; // [esp-Ch] [ebp-40h]
  int v14; // [esp+8h] [ebp-2Ch]
  bignum_st a; // [esp+Ch] [ebp-28h] BYREF
  bignum_st r; // [esp+20h] [ebp-14h] BYREF

  v4 = 0;
  v14 = 0;
  if ( dsa->p && dsa->q && dsa->g )
  {
    BN_init(&a);
    BN_init(&r);
    v5 = ctx_in;
    if ( ctx_in || (v5 = BN_CTX_new()) != 0 )
    {
      v4 = BN_new();
      if ( v4 )
      {
        while ( BN_rand_range(&a, dsa->q) )
        {
          if ( a.top )
          {
            flags = dsa->flags;
            if ( (flags & 2) == 0 )
              a.flags |= 4u;
            if ( (flags & 1) == 0 || BN_MONT_CTX_set_locked(&dsa->method_mont_p, 8, dsa->p, v5) )
            {
              if ( (dsa->flags & 2) != 0 )
              {
                p_a = &a;
              }
              else
              {
                if ( !BN_copy(&r, &a) )
                  break;
                if ( !BN_add(&r, &r, dsa->q) )
                  break;
                v7 = BN_num_bits(&r);
                if ( v7 <= BN_num_bits(dsa->q) && !BN_add(&r, &r, dsa->q) )
                  break;
                p_a = &r;
              }
              bn_mod_exp = dsa->meth->bn_mod_exp;
              method_mont_p = dsa->method_mont_p;
              if ( bn_mod_exp
                 ? bn_mod_exp(dsa, v4, dsa->g, p_a, dsa->p, v5, method_mont_p)
                 : BN_mod_exp_mont(v4, dsa->g, p_a, dsa->p, v5, method_mont_p) )
              {
                if ( BN_div(0, v4, v4, dsa->q, v5) )
                {
                  v11 = BN_mod_inverse(0, &a, dsa->q, v5);
                  if ( v11 )
                  {
                    if ( *kinvp )
                      BN_clear_free(*kinvp);
                    *kinvp = v11;
                    if ( *rp )
                      BN_clear_free(*rp);
                    *rp = v4;
                    v14 = 1;
                    goto LABEL_33;
                  }
                }
              }
            }
            break;
          }
        }
      }
    }
    ERR_put_error(0xAu, 107, 3, ".\\crypto\\dsa\\dsa_ossl.c", 283);
    if ( v4 )
      BN_clear_free(v4);
LABEL_33:
    if ( !ctx_in )
      BN_CTX_free(v5);
    BN_clear_free(&a);
    BN_clear_free(&r);
    return v14;
  }
  else
  {
    ERR_put_error(0xAu, 107, 101, ".\\crypto\\dsa\\dsa_ossl.c", 210);
    return 0;
  }
}

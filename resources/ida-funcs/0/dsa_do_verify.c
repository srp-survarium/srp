int __cdecl dsa_do_verify(unsigned __int8 *dgst, int dgst_len, DSA_SIG_st *sig, dsa_st *dsa)
{
  bn_mont_ctx_st *v4; // ebx
  bignum_st *q; // eax
  int v6; // eax
  int v7; // ebp
  bignum_ctx *v9; // edi
  bignum_st *r; // eax
  bignum_st *s; // eax
  int v12; // ecx
  int (__cdecl *dsa_mod_exp)(dsa_st *, bignum_st *, bignum_st *, bignum_st *, bignum_st *, bignum_st *, bignum_st *, bignum_ctx *, bn_mont_ctx_st *); // eax
  int v14; // eax
  int v15; // esi
  bignum_st a; // [esp+Ch] [ebp-3Ch] BYREF
  bignum_st in; // [esp+20h] [ebp-28h] BYREF
  bignum_st rr; // [esp+34h] [ebp-14h] BYREF

  v4 = 0;
  if ( !dsa->p || (q = dsa->q) == 0 || !dsa->g )
  {
    ERR_put_error(0, 0xAu, 113, 101, ".\\crypto\\dsa\\dsa_ossl.c", 302);
    return -1;
  }
  v6 = BN_num_bits(q);
  v7 = v6;
  if ( v6 != 160 && v6 != 224 && v6 != 256 )
  {
    ERR_put_error(0, 0xAu, 113, 102, ".\\crypto\\dsa\\dsa_ossl.c", 310);
    return -1;
  }
  if ( BN_num_bits(dsa->p) > 10000 )
  {
    ERR_put_error(0, 0xAu, 113, 103, ".\\crypto\\dsa\\dsa_ossl.c", 316);
    return -1;
  }
  BN_init(&a);
  BN_init(&in);
  BN_init(&rr);
  v9 = BN_CTX_new(0);
  if ( !v9 )
    goto LABEL_34;
  r = sig->r;
  if ( !sig->r->top || r->neg || BN_ucmp(r, dsa->q) >= 0 || (s = sig->s, !s->top) || s->neg || BN_ucmp(s, dsa->q) >= 0 )
  {
    v15 = 0;
LABEL_35:
    ERR_put_error((int)v4, 0xAu, 113, 3, ".\\crypto\\dsa\\dsa_ossl.c", 378);
    goto LABEL_36;
  }
  if ( !BN_mod_inverse(0, &in, sig->s, dsa->q, v9) )
    goto LABEL_34;
  v12 = dgst_len;
  if ( dgst_len > v7 >> 3 )
    v12 = v7 >> 3;
  if ( !BN_bin2bn(dgst, v12, &a)
    || !BN_mod_mul(&a, (bignum_pool_item *)&a, (bignum_pool_item *)&in, dsa->q, v9)
    || !BN_mod_mul(&in, (bignum_pool_item *)sig->r, (bignum_pool_item *)&in, dsa->q, v9)
    || (dsa->flags & 1) != 0 && (v4 = BN_MONT_CTX_set_locked((int)v9, &dsa->method_mont_p, 8, dsa->p, v9)) == 0
    || ((dsa_mod_exp = dsa->meth->dsa_mod_exp) == 0
      ? (v14 = BN_mod_exp2_mont(
                 &rr,
                 (bignum_pool_item *)dsa->g,
                 &a,
                 (bignum_pool_item *)dsa->pub_key,
                 &in,
                 dsa->p,
                 v9,
                 v4))
      : (v14 = dsa_mod_exp(dsa, &rr, dsa->g, &a, dsa->pub_key, &in, dsa->p, v9, v4)),
        !v14 || !BN_div(0, &a, &rr, dsa->q, v9)) )
  {
LABEL_34:
    v15 = -1;
    goto LABEL_35;
  }
  v15 = BN_ucmp(&a, sig->r) == 0;
  if ( v15 != 1 )
    goto LABEL_35;
LABEL_36:
  if ( v9 )
    BN_CTX_free(v9);
  BN_free(&a);
  BN_free(&in);
  BN_free(&rr);
  return v15;
}

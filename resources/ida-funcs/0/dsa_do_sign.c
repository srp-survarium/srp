DSA_SIG_st *__cdecl dsa_do_sign(unsigned __int8 *dgst, int dlen, dsa_st *dsa)
{
  bignum_pool_item *v3; // edi
  bignum_ctx *v4; // ebx
  bignum_st *v5; // eax
  int v6; // kr00_4
  int v7; // eax
  DSA_SIG_st *v8; // eax
  DSA_SIG_st *v9; // esi
  bignum_pool_item *b; // [esp+10h] [ebp-38h]
  bignum_pool_item *kinv; // [esp+14h] [ebp-34h]
  __int16 v13; // [esp+1Ch] [ebp-2Ch]
  bignum_st a; // [esp+20h] [ebp-28h] BYREF
  bignum_st r; // [esp+34h] [ebp-14h] BYREF

  kinv = 0;
  b = 0;
  v3 = 0;
  v4 = 0;
  v13 = 3;
  BN_init(&a);
  BN_init(&r);
  if ( !dsa->p || !dsa->q || !dsa->g )
  {
    v13 = 101;
    v9 = 0;
    goto LABEL_22;
  }
  v3 = (bignum_pool_item *)BN_new(0);
  if ( !v3 )
    goto LABEL_21;
  v4 = BN_CTX_new(0);
  if ( !v4 )
    goto LABEL_21;
  if ( dsa->kinv )
  {
    v5 = dsa->r;
    if ( v5 )
    {
      kinv = (bignum_pool_item *)dsa->kinv;
      dsa->kinv = 0;
      b = (bignum_pool_item *)v5;
      dsa->r = 0;
      goto LABEL_10;
    }
  }
  if ( !DSA_sign_setup(dsa) )
  {
LABEL_21:
    v9 = 0;
    goto LABEL_22;
  }
LABEL_10:
  v6 = BN_num_bits(dsa->q) + 7;
  v7 = dlen;
  if ( dlen > v6 / 8 )
    v7 = (BN_num_bits(dsa->q) + 7) / 8;
  if ( !BN_bin2bn(dgst, v7, &a)
    || !BN_mod_mul(&r, (bignum_pool_item *)dsa->priv_key, b, dsa->q, v4)
    || !BN_add(v3->vals, &r, &a)
    || BN_cmp(v3->vals, dsa->q) > 0 && !BN_sub(v3->vals, v3->vals, dsa->q)
    || !BN_mod_mul(v3->vals, v3, kinv, dsa->q, v4) )
  {
    goto LABEL_21;
  }
  v8 = DSA_SIG_new();
  v9 = v8;
  if ( v8 )
  {
    v8->r = (bignum_st *)b;
    v8->s = (bignum_st *)v3;
    goto LABEL_23;
  }
LABEL_22:
  ERR_put_error((int)v4, 0xAu, 112, v13, ".\\crypto\\dsa\\dsa_ossl.c", 190);
  BN_free(b->vals);
  BN_free(v3->vals);
LABEL_23:
  if ( v4 )
    BN_CTX_free(v4);
  BN_clear_free(&a);
  BN_clear_free(&r);
  if ( kinv )
    BN_clear_free(kinv->vals);
  return v9;
}

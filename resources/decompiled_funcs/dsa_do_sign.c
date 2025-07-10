DSA_SIG_st *__cdecl dsa_do_sign(unsigned __int8 *dgst, int dlen, dsa_st *dsa)
{
  bignum_st *v3; // edi
  bignum_ctx *v4; // ebx
  bignum_st *v5; // eax
  int v6; // kr00_4
  int v7; // eax
  DSA_SIG_st *v8; // eax
  DSA_SIG_st *v9; // esi
  bignum_st *rp; // [esp+10h] [ebp-38h]
  bignum_st *kinvp; // [esp+14h] [ebp-34h]
  __int16 reason; // [esp+1Ch] [ebp-2Ch]
  bignum_st a; // [esp+20h] [ebp-28h] BYREF
  bignum_st r; // [esp+34h] [ebp-14h] BYREF

  kinvp = 0;
  rp = 0;
  v3 = 0;
  v4 = 0;
  reason = 3;
  BN_init(&a);
  BN_init(&r);
  if ( !dsa->p || !dsa->q || !dsa->g )
  {
    reason = 101;
    v9 = 0;
    goto LABEL_22;
  }
  v3 = BN_new();
  if ( !v3 )
    goto LABEL_21;
  v4 = BN_CTX_new();
  if ( !v4 )
    goto LABEL_21;
  if ( dsa->kinv )
  {
    v5 = dsa->r;
    if ( v5 )
    {
      kinvp = dsa->kinv;
      dsa->kinv = 0;
      rp = v5;
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
    || !BN_mod_mul(&r, dsa->priv_key, rp, dsa->q, v4)
    || !BN_add(v3, &r, &a)
    || BN_cmp(v3, dsa->q) > 0 && !BN_sub(v3, v3, dsa->q)
    || !BN_mod_mul(v3, v3, kinvp, dsa->q, v4) )
  {
    goto LABEL_21;
  }
  v8 = DSA_SIG_new();
  v9 = v8;
  if ( v8 )
  {
    v8->r = rp;
    v8->s = v3;
    goto LABEL_23;
  }
LABEL_22:
  ERR_put_error(0xAu, 112, reason, ".\\crypto\\dsa\\dsa_ossl.c", 190);
  BN_free(rp);
  BN_free(v3);
LABEL_23:
  if ( v4 )
    BN_CTX_free(v4);
  BN_clear_free(&a);
  BN_clear_free(&r);
  if ( kinvp )
    BN_clear_free(kinvp);
  return v9;
}

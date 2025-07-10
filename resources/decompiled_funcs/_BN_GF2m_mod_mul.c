bignum_pool_item *__cdecl BN_GF2m_mod_mul(
        bignum_st *r,
        const bignum_st *a,
        const bignum_st *b,
        const bignum_st *p,
        bignum_ctx *ctx)
{
  int v5; // esi
  int *v6; // eax
  int *v7; // edi
  int v8; // eax
  int v9; // ebx
  bignum_pool_item *v10; // ebx

  v5 = BN_num_bits(p) + 1;
  v6 = (int *)CRYPTO_malloc(4 * v5, ".\\crypto\\bn\\bn_gf2m.c", 446);
  v7 = v6;
  if ( !v6 )
    return 0;
  v8 = BN_GF2m_poly2arr(p, v6, v5);
  v9 = v8;
  if ( v8 && v8 <= v5 )
  {
    v10 = BN_GF2m_mod_mul_arr(r, a, b, v7, ctx);
    CRYPTO_free(v7);
    return v10;
  }
  else
  {
    ERR_put_error(3u, 133, 106, ".\\crypto\\bn\\bn_gf2m.c", 450);
    CRYPTO_free(v7);
    return (bignum_pool_item *)v9;
  }
}

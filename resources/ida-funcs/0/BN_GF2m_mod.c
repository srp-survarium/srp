int __cdecl BN_GF2m_mod(bignum_st *r, const bignum_st *a, const bignum_st *p)
{
  int v3; // esi
  int *v4; // eax
  int *v5; // edi
  int v6; // eax
  int v7; // ebx
  int v8; // ebx

  v3 = BN_num_bits(p) + 1;
  v4 = (int *)CRYPTO_malloc(4 * v3, ".\\crypto\\bn\\bn_gf2m.c", 367);
  v5 = v4;
  if ( !v4 )
    return 0;
  v6 = BN_GF2m_poly2arr(p, v4, v3);
  v7 = v6;
  if ( v6 && v6 <= v3 )
  {
    v8 = BN_GF2m_mod_arr(v6, r, a, v5);
    CRYPTO_free(v5);
    return v8;
  }
  else
  {
    ERR_put_error(v6, 3u, 131, 106, ".\\crypto\\bn\\bn_gf2m.c", 371);
    CRYPTO_free(v5);
    return v7;
  }
}

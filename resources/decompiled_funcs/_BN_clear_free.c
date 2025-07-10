void __cdecl BN_clear_free(bignum_st *a)
{
  int v1; // edi

  if ( a )
  {
    if ( a->d )
    {
      OPENSSL_cleanse(a->d, 4 * a->dmax);
      if ( (a->flags & 2) == 0 )
        CRYPTO_free(a->d);
    }
    v1 = a->flags & 1;
    OPENSSL_cleanse(a, 20);
    if ( v1 )
      CRYPTO_free(a);
  }
}

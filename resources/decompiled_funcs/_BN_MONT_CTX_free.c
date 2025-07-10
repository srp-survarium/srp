void __cdecl BN_MONT_CTX_free(bn_mont_ctx_st *mont)
{
  if ( mont )
  {
    BN_free(&mont->RR);
    BN_free(&mont->N);
    BN_free(&mont->Ni);
    if ( (mont->flags & 1) != 0 )
      CRYPTO_free(mont);
  }
}

void __cdecl BN_RECP_CTX_free(bn_recp_ctx_st *recp)
{
  if ( recp )
  {
    BN_free(&recp->N);
    BN_free(&recp->Nr);
    if ( (recp->flags & 1) != 0 )
      CRYPTO_free(recp);
  }
}

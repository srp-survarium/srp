int __cdecl HMAC_CTX_copy(hmac_ctx_st *dctx, hmac_ctx_st *sctx)
{
  if ( !EVP_MD_CTX_copy(&dctx->i_ctx, &sctx->i_ctx)
    || !EVP_MD_CTX_copy(&dctx->o_ctx, &sctx->o_ctx)
    || !EVP_MD_CTX_copy(&dctx->md_ctx, &sctx->md_ctx) )
  {
    return 0;
  }
  qmemcpy(dctx->key, sctx->key, sizeof(dctx->key));
  dctx->key_length = sctx->key_length;
  dctx->md = sctx->md;
  return 1;
}

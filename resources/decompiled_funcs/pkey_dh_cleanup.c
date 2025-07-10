void __cdecl pkey_dh_cleanup(evp_pkey_ctx_st *ctx)
{
  if ( ctx->data )
    CRYPTO_free(ctx->data);
}

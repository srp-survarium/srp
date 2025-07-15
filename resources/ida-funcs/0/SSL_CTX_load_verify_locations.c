int __cdecl SSL_CTX_load_verify_locations(ssl_ctx_st *ctx, const char *CAfile, const char *CApath)
{
  return X509_STORE_load_locations(ctx->cert_store, CAfile, CApath);
}

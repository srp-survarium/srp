void __cdecl X509_STORE_CTX_set_verify_cb(x509_store_ctx_st *ctx, int (__cdecl *verify_cb)(int, x509_store_ctx_st *))
{
  ctx->verify_cb = verify_cb;
}

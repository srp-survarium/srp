int __cdecl hmac_signctx_init(evp_pkey_ctx_st *ctx, env_md_ctx_st *mctx)
{
  HMAC_CTX_set_flags((hmac_ctx_st *)((char *)ctx->data + 20), mctx->flags & 0xFFFFFEFF);
  EVP_MD_CTX_set_flags(mctx, 256);
  mctx->update = (int (__cdecl *)(env_md_ctx_st *, const void *, unsigned int))int_update;
  return 1;
}

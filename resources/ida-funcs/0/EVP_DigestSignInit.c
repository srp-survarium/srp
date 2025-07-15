BOOL __cdecl EVP_DigestSignInit(
        env_md_ctx_st *ctx,
        evp_pkey_ctx_st **pctx,
        engine_st *type,
        engine_st *e,
        evp_pkey_st *pkey)
{
  return do_sigver_init(ctx, type, pkey, pctx, e, 0);
}

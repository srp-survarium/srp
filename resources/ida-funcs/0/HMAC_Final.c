BOOL __cdecl HMAC_Final(hmac_ctx_st *ctx, unsigned __int8 *md, unsigned int *len)
{
  env_md_ctx_st *p_md_ctx; // esi
  unsigned int v5; // [esp+10h] [ebp-48h] BYREF
  unsigned __int8 v6[64]; // [esp+14h] [ebp-44h] BYREF

  p_md_ctx = &ctx->md_ctx;
  return EVP_DigestFinal_ex((int)ctx, (int)md, &ctx->md_ctx, v6, &v5)
      && EVP_MD_CTX_copy_ex((int)md, p_md_ctx, &ctx->o_ctx)
      && EVP_DigestUpdate(p_md_ctx)
      && EVP_DigestFinal_ex((int)&ctx->o_ctx, (int)md, p_md_ctx, md, len);
}

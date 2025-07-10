BOOL __cdecl HMAC_Final(hmac_ctx_st *ctx, unsigned __int8 *md, unsigned int *len)
{
  env_md_ctx_st *p_md_ctx; // esi
  unsigned int size; // [esp+10h] [ebp-48h] BYREF
  unsigned __int8 mda[64]; // [esp+14h] [ebp-44h] BYREF

  p_md_ctx = &ctx->md_ctx;
  return EVP_DigestFinal_ex((unsigned int)ctx, &ctx->md_ctx, mda, &size)
      && EVP_MD_CTX_copy_ex(p_md_ctx, &ctx->o_ctx)
      && EVP_DigestUpdate(p_md_ctx)
      && EVP_DigestFinal_ex((unsigned int)&ctx->o_ctx, p_md_ctx, md, len);
}

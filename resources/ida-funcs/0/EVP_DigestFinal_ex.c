int __usercall EVP_DigestFinal_ex@<eax>(
        unsigned int a1@<edi>,
        env_md_ctx_st *ctx,
        unsigned __int8 *md,
        unsigned int *size)
{
  int v4; // edi
  int (__cdecl *cleanup)(env_md_ctx_st *); // eax

  if ( ctx->digest->md_size > 64 )
    OpenSSLDie(a1, (unsigned int)ctx, ".\\crypto\\evp\\digest.c", 250, "ctx->digest->md_size <= EVP_MAX_MD_SIZE");
  v4 = ctx->digest->final(ctx, md);
  if ( size )
    *size = ctx->digest->md_size;
  cleanup = ctx->digest->cleanup;
  if ( cleanup )
  {
    cleanup(ctx);
    EVP_MD_CTX_set_flags(ctx, 2);
  }
  memset((int)ctx->md_data, 0, ctx->digest->ctx_size);
  return v4;
}

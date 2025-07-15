int __usercall EVP_DigestFinal_ex@<eax>(
        int a1@<edi>,
        int a2@<ebx>,
        env_md_ctx_st *ctx,
        unsigned __int8 *md,
        unsigned int *size)
{
  int v5; // edi
  int (__cdecl *cleanup)(env_md_ctx_st *); // eax

  if ( ctx->digest->md_size > 64 )
    OpenSSLDie(a1, (int)ctx, a2, ".\\crypto\\evp\\digest.c", 250, "ctx->digest->md_size <= EVP_MAX_MD_SIZE");
  v5 = ctx->digest->final(ctx, md);
  if ( size )
    *size = ctx->digest->md_size;
  cleanup = ctx->digest->cleanup;
  if ( cleanup )
  {
    cleanup(ctx);
    EVP_MD_CTX_set_flags(ctx, 2);
  }
  memset((int)ctx->md_data, 0, ctx->digest->ctx_size);
  return v5;
}

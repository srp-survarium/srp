int __cdecl pkey_rsa_init(evp_pkey_ctx_st *ctx)
{
  int *v1; // eax

  v1 = (int *)CRYPTO_malloc(32, ".\\crypto\\rsa\\rsa_pmeth.c", 91);
  if ( !v1 )
    return 0;
  v1[1] = 0;
  v1[5] = 0;
  v1[7] = 0;
  *v1 = 1024;
  v1[4] = 1;
  v1[6] = -2;
  ctx->data = v1;
  ctx->keygen_info = v1 + 2;
  ctx->keygen_info_count = 2;
  return 1;
}

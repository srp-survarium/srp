int __cdecl pkey_dsa_init(evp_pkey_ctx_st *ctx)
{
  int *v1; // eax

  v1 = (int *)CRYPTO_malloc(24, ".\\crypto\\dsa\\dsa_pmeth.c", 84);
  if ( !v1 )
    return 0;
  v1[2] = 0;
  v1[5] = 0;
  *v1 = 1024;
  v1[1] = 160;
  ctx->data = v1;
  ctx->keygen_info = v1 + 3;
  ctx->keygen_info_count = 2;
  return 1;
}

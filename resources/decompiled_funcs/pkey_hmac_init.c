int __cdecl pkey_hmac_init(evp_pkey_ctx_st *ctx)
{
  char *v1; // esi

  v1 = (char *)CRYPTO_malloc(228, ".\\crypto\\hmac\\hm_pmeth.c", 78);
  if ( !v1 )
    return 0;
  *(_DWORD *)v1 = 0;
  *((_DWORD *)v1 + 3) = 0;
  *((_DWORD *)v1 + 1) = 0;
  *((_DWORD *)v1 + 4) = 0;
  *((_DWORD *)v1 + 2) = 4;
  HMAC_CTX_init((hmac_ctx_st *)(v1 + 20));
  ctx->keygen_info_count = 0;
  ctx->data = v1;
  return 1;
}

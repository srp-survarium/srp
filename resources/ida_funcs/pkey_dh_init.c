int __cdecl pkey_dh_init(evp_pkey_ctx_st *ctx)
{
  int result; // eax

  result = (int)CRYPTO_malloc(20, ".\\crypto\\dh\\dh_pmeth.c", 83);
  if ( result )
  {
    *(_DWORD *)result = 1024;
    *(_DWORD *)(result + 4) = 2;
    *(_DWORD *)(result + 8) = 0;
    ctx->data = (void *)result;
    ctx->keygen_info = (int *)(result + 12);
    ctx->keygen_info_count = 2;
    return 1;
  }
  return result;
}

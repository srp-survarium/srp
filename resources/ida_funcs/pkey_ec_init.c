int __cdecl pkey_ec_init(evp_pkey_ctx_st *ctx)
{
  int result; // eax

  result = (int)CRYPTO_malloc(8, ".\\crypto\\ec\\ec_pmeth.c", 80);
  if ( result )
  {
    *(_DWORD *)result = 0;
    *(_DWORD *)(result + 4) = 0;
    ctx->data = (void *)result;
    return 1;
  }
  return result;
}

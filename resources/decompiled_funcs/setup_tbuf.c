BOOL __usercall setup_tbuf@<eax>(RSA_PKEY_CTX *ctx@<esi>, evp_pkey_ctx_st *pk)
{
  int v3; // eax
  unsigned __int8 *v4; // eax

  if ( ctx->tbuf )
    return 1;
  v3 = EVP_PKEY_size(pk->pkey);
  v4 = (unsigned __int8 *)CRYPTO_malloc(v3, ".\\crypto\\rsa\\rsa_pmeth.c", 132);
  ctx->tbuf = v4;
  return v4 != 0;
}

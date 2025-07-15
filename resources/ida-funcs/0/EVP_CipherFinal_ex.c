int __cdecl EVP_CipherFinal_ex(evp_cipher_ctx_st *ctx, unsigned __int8 *out, unsigned int *outl)
{
  if ( ctx->encrypt )
    return EVP_EncryptFinal_ex(ctx, out, outl);
  else
    return EVP_DecryptFinal_ex(ctx, out, (int *)outl);
}

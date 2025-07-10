BOOL __cdecl EVP_CipherUpdate(evp_cipher_ctx_st *ctx, unsigned __int8 *out, int *outl, unsigned __int8 *in, int inl)
{
  if ( ctx->encrypt )
    return EVP_EncryptUpdate(ctx, out, outl, in, inl);
  else
    return EVP_DecryptUpdate(ctx, out, outl, in, inl);
}

int __cdecl EVP_CIPHER_CTX_rand_key(evp_cipher_ctx_st *ctx, unsigned __int8 *key)
{
  if ( (ctx->cipher->flags & 0x200) != 0 )
    return EVP_CIPHER_CTX_ctrl(ctx, 6, 0, key);
  else
    return RAND_bytes() > 0;
}

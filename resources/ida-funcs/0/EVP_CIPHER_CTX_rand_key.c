int __usercall EVP_CIPHER_CTX_rand_key@<eax>(int a1@<ebx>, int a2@<edi>, evp_cipher_ctx_st *ctx, unsigned __int8 *key)
{
  if ( (ctx->cipher->flags & 0x200) != 0 )
    return EVP_CIPHER_CTX_ctrl(a1, ctx, 6, 0, key);
  else
    return RAND_bytes(a2) > 0;
}

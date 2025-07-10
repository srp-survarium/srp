int __cdecl rc4_cipher(evp_cipher_ctx_st *ctx, unsigned __int8 *out, const unsigned __int8 *in, unsigned int inl)
{
  RC4(ctx->cipher_data, inl, in, out);
  return 1;
}

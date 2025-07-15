int __cdecl null_cipher(evp_cipher_ctx_st *ctx, const __m128i *out, const __m128i *in, unsigned int inl)
{
  if ( in != out )
    memcpy((int)out, in, inl);
  return 1;
}

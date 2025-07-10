int __cdecl null_cipher(evp_cipher_ctx_st *ctx, unsigned __int8 *out, unsigned __int8 *in, unsigned int inl)
{
  if ( in != out )
    memcpy(out, in, inl);
  return 1;
}

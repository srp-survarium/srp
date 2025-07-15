int __cdecl pkey_rsa_decrypt(
        evp_pkey_ctx_st *ctx,
        unsigned __int8 *out,
        unsigned int *outlen,
        const unsigned __int8 *in,
        int inlen)
{
  int result; // eax

  result = RSA_private_decrypt(inlen, in, out, ctx->pkey->pkey.rsa);
  if ( result >= 0 )
  {
    *outlen = result;
    return 1;
  }
  return result;
}

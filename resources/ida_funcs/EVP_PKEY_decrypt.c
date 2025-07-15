int __cdecl EVP_PKEY_decrypt(
        evp_pkey_ctx_st *ctx,
        unsigned __int8 *out,
        unsigned int *outlen,
        const unsigned __int8 *in,
        unsigned int inlen)
{
  const evp_pkey_method_st *pmeth; // eax
  unsigned int v7; // eax

  if ( ctx && (pmeth = ctx->pmeth) != 0 && pmeth->decrypt )
  {
    if ( ctx->operation != 512 )
    {
      ERR_put_error(6u, 104, 151, ".\\crypto\\evp\\pmeth_fn.c", 259);
      return -1;
    }
    if ( (pmeth->flags & 2) == 0 )
      return ctx->pmeth->decrypt(ctx, out, outlen, in, inlen);
    v7 = EVP_PKEY_size(ctx->pkey);
    if ( !out )
    {
      *outlen = v7;
      return 1;
    }
    if ( *outlen < v7 )
    {
      ERR_put_error(6u, 104, 155, ".\\crypto\\evp\\pmeth_fn.c", 262);
      return 0;
    }
    else
    {
      return ctx->pmeth->decrypt(ctx, out, outlen, in, inlen);
    }
  }
  else
  {
    ERR_put_error(6u, 104, 150, ".\\crypto\\evp\\pmeth_fn.c", 254);
    return -2;
  }
}

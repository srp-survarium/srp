int __cdecl EVP_PKEY_sign(
        evp_pkey_ctx_st *ctx,
        unsigned __int8 *sig,
        unsigned int *siglen,
        const unsigned __int8 *tbs,
        unsigned int tbslen)
{
  const evp_pkey_method_st *pmeth; // eax
  unsigned int v7; // eax

  if ( ctx && (pmeth = ctx->pmeth) != 0 && pmeth->sign )
  {
    if ( ctx->operation != 8 )
    {
      ERR_put_error(6u, 140, 151, ".\\crypto\\evp\\pmeth_fn.c", 112);
      return -1;
    }
    if ( (pmeth->flags & 2) == 0 )
      return ctx->pmeth->sign(ctx, sig, siglen, tbs, tbslen);
    v7 = EVP_PKEY_size(ctx->pkey);
    if ( !sig )
    {
      *siglen = v7;
      return 1;
    }
    if ( *siglen < v7 )
    {
      ERR_put_error(6u, 140, 155, ".\\crypto\\evp\\pmeth_fn.c", 115);
      return 0;
    }
    else
    {
      return ctx->pmeth->sign(ctx, sig, siglen, tbs, tbslen);
    }
  }
  else
  {
    ERR_put_error(6u, 140, 150, ".\\crypto\\evp\\pmeth_fn.c", 107);
    return -2;
  }
}

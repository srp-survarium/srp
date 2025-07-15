int __cdecl EVP_PKEY_keygen(evp_pkey_ctx_st *ctx, evp_pkey_st **ppkey)
{
  int v3; // edi

  if ( ctx && ctx->pmeth && ctx->pmeth->keygen )
  {
    if ( ctx->operation == 4 )
    {
      if ( ppkey )
      {
        if ( !*ppkey )
          *ppkey = EVP_PKEY_new();
        v3 = ctx->pmeth->keygen(ctx, *ppkey);
        if ( v3 <= 0 )
        {
          EVP_PKEY_free(*ppkey);
          *ppkey = 0;
        }
        return v3;
      }
      else
      {
        return -1;
      }
    }
    else
    {
      ERR_put_error(6u, 146, 151, ".\\crypto\\evp\\pmeth_gn.c", 146);
      return -1;
    }
  }
  else
  {
    ERR_put_error(6u, 146, 150, ".\\crypto\\evp\\pmeth_gn.c", 141);
    return -2;
  }
}

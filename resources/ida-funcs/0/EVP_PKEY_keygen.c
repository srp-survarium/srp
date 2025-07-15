int __usercall EVP_PKEY_keygen@<eax>(int a1@<ebx>, evp_pkey_ctx_st *ctx, evp_pkey_st **ppkey)
{
  int v4; // edi

  if ( ctx && ctx->pmeth && ctx->pmeth->keygen )
  {
    if ( ctx->operation == 4 )
    {
      if ( ppkey )
      {
        if ( !*ppkey )
          *ppkey = EVP_PKEY_new(a1);
        v4 = ctx->pmeth->keygen(ctx, *ppkey);
        if ( v4 <= 0 )
        {
          EVP_PKEY_free(v4, *ppkey);
          *ppkey = 0;
        }
        return v4;
      }
      else
      {
        return -1;
      }
    }
    else
    {
      ERR_put_error(a1, 6u, 146, 151, ".\\crypto\\evp\\pmeth_gn.c", 146);
      return -1;
    }
  }
  else
  {
    ERR_put_error(a1, 6u, 146, 150, ".\\crypto\\evp\\pmeth_gn.c", 141);
    return -2;
  }
}

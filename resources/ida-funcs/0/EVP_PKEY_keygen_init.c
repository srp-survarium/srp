int __cdecl EVP_PKEY_keygen_init(evp_pkey_ctx_st *ctx)
{
  const evp_pkey_method_st *pmeth; // eax
  int (__cdecl *keygen_init)(evp_pkey_ctx_st *); // eax
  int result; // eax

  if ( ctx && (pmeth = ctx->pmeth) != 0 && pmeth->keygen )
  {
    ctx->operation = 4;
    keygen_init = pmeth->keygen_init;
    if ( keygen_init )
    {
      result = keygen_init(ctx);
      if ( result <= 0 )
        ctx->operation = 0;
    }
    else
    {
      return 1;
    }
  }
  else
  {
    ERR_put_error(6u, 147, 150, ".\\crypto\\evp\\pmeth_gn.c", 122);
    return -2;
  }
  return result;
}

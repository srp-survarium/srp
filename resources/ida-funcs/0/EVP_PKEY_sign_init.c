int __cdecl EVP_PKEY_sign_init(evp_pkey_ctx_st *ctx)
{
  const evp_pkey_method_st *pmeth; // eax
  int (__cdecl *sign_init)(evp_pkey_ctx_st *); // eax
  int result; // eax

  if ( ctx && (pmeth = ctx->pmeth) != 0 && pmeth->sign )
  {
    ctx->operation = 8;
    sign_init = pmeth->sign_init;
    if ( sign_init )
    {
      result = sign_init(ctx);
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
    ERR_put_error(6u, 141, 150, ".\\crypto\\evp\\pmeth_fn.c", 88);
    return -2;
  }
  return result;
}

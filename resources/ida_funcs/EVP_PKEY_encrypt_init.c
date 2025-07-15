int __cdecl EVP_PKEY_encrypt_init(evp_pkey_ctx_st *ctx)
{
  const evp_pkey_method_st *pmeth; // eax
  int (__cdecl *encrypt_init)(evp_pkey_ctx_st *); // eax
  int result; // eax

  if ( ctx && (pmeth = ctx->pmeth) != 0 && pmeth->encrypt )
  {
    ctx->operation = 256;
    encrypt_init = pmeth->encrypt_init;
    if ( encrypt_init )
    {
      result = encrypt_init(ctx);
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
    ERR_put_error(6u, 139, 150, ".\\crypto\\evp\\pmeth_fn.c", 198);
    return -2;
  }
  return result;
}

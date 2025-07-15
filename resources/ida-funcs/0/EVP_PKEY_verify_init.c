int __usercall EVP_PKEY_verify_init@<eax>(int a1@<ebx>, evp_pkey_ctx_st *ctx)
{
  const evp_pkey_method_st *pmeth; // eax
  int (__cdecl *verify_init)(evp_pkey_ctx_st *); // eax
  int result; // eax

  if ( ctx && (pmeth = ctx->pmeth) != 0 && pmeth->verify )
  {
    ctx->operation = 16;
    verify_init = pmeth->verify_init;
    if ( verify_init )
    {
      result = verify_init(ctx);
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
    ERR_put_error(a1, 6u, 143, 150, ".\\crypto\\evp\\pmeth_fn.c", 125);
    return -2;
  }
  return result;
}

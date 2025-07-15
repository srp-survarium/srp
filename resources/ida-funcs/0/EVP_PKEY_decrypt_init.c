int __usercall EVP_PKEY_decrypt_init@<eax>(int a1@<ebx>, evp_pkey_ctx_st *ctx)
{
  const evp_pkey_method_st *pmeth; // eax
  int (__cdecl *decrypt_init)(evp_pkey_ctx_st *); // eax
  int result; // eax

  if ( ctx && (pmeth = ctx->pmeth) != 0 && pmeth->decrypt )
  {
    ctx->operation = 512;
    decrypt_init = pmeth->decrypt_init;
    if ( decrypt_init )
    {
      result = decrypt_init(ctx);
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
    ERR_put_error(a1, 6u, 138, 150, ".\\crypto\\evp\\pmeth_fn.c", 235);
    return -2;
  }
  return result;
}

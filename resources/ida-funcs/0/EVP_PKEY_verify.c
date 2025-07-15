int __usercall EVP_PKEY_verify@<eax>(int a1@<ebx>, evp_pkey_ctx_st *ctx)
{
  int (*verify)(void); // eax

  if ( ctx && ctx->pmeth && (verify = (int (*)(void))ctx->pmeth->verify) != 0 )
  {
    if ( ctx->operation == 16 )
    {
      return verify();
    }
    else
    {
      ERR_put_error(a1, 6u, 142, 151, ".\\crypto\\evp\\pmeth_fn.c", 149);
      return -1;
    }
  }
  else
  {
    ERR_put_error(a1, 6u, 142, 150, ".\\crypto\\evp\\pmeth_fn.c", 144);
    return -2;
  }
}

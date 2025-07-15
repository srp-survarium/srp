int __usercall EVP_CIPHER_CTX_ctrl@<eax>(int a1@<ebx>, evp_cipher_ctx_st *ctx, int type, int arg, void *ptr)
{
  int result; // eax
  int (__cdecl *ctrl)(evp_cipher_ctx_st *, int, int, void *); // eax

  if ( ctx->cipher )
  {
    ctrl = ctx->cipher->ctrl;
    if ( ctrl )
    {
      result = ctrl(ctx, type, arg, ptr);
      if ( result == -1 )
      {
        ERR_put_error(a1, 6u, 124, 133, ".\\crypto\\evp\\evp_enc.c", 555);
        return 0;
      }
    }
    else
    {
      ERR_put_error(a1, 6u, 124, 132, ".\\crypto\\evp\\evp_enc.c", 549);
      return 0;
    }
  }
  else
  {
    ERR_put_error(a1, 6u, 124, 131, ".\\crypto\\evp\\evp_enc.c", 544);
    return 0;
  }
  return result;
}

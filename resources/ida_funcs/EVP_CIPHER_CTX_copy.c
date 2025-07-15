int __usercall EVP_CIPHER_CTX_copy@<eax>(unsigned int a1@<edi>, evp_cipher_ctx_st *out, evp_cipher_ctx_st *in)
{
  int ctx_size; // eax
  void *v5; // eax

  if ( in && in->cipher )
  {
    if ( in->engine && !ENGINE_init(a1, in->engine) )
    {
      ERR_put_error(6u, 163, 38, ".\\crypto\\evp\\evp_enc.c", 581);
      return 0;
    }
    EVP_CIPHER_CTX_cleanup(a1, out);
    qmemcpy(out, in, sizeof(evp_cipher_ctx_st));
    if ( in->cipher_data )
    {
      ctx_size = in->cipher->ctx_size;
      if ( ctx_size )
      {
        v5 = CRYPTO_malloc(ctx_size, ".\\crypto\\evp\\evp_enc.c", 591);
        out->cipher_data = v5;
        if ( !v5 )
        {
          ERR_put_error(6u, 163, 65, ".\\crypto\\evp\\evp_enc.c", 594);
          return 0;
        }
        memcpy((unsigned __int8 *)v5, (unsigned __int8 *)in->cipher_data, in->cipher->ctx_size);
      }
    }
    if ( (in->cipher->flags & 0x400) != 0 )
      return in->cipher->ctrl(in, 8, 0, out);
    else
      return 1;
  }
  else
  {
    ERR_put_error(6u, 163, 111, ".\\crypto\\evp\\evp_enc.c", 574);
    return 0;
  }
}

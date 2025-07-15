int __usercall EVP_CIPHER_CTX_cleanup@<eax>(int a1@<edi>, int a2@<ebx>, evp_cipher_ctx_st *c)
{
  int (__cdecl *cleanup)(evp_cipher_ctx_st *); // eax
  int result; // eax
  void *cipher_data; // eax

  if ( c->cipher )
  {
    cleanup = c->cipher->cleanup;
    if ( cleanup )
    {
      result = cleanup(c);
      if ( !result )
        return result;
    }
    cipher_data = c->cipher_data;
    if ( cipher_data )
      OPENSSL_cleanse(cipher_data, c->cipher->ctx_size);
  }
  if ( c->cipher_data )
    CRYPTO_free(c->cipher_data);
  if ( c->engine )
    ENGINE_finish(a1, a2, c->engine);
  memset((int)c, 0, sizeof(evp_cipher_ctx_st));
  return 1;
}

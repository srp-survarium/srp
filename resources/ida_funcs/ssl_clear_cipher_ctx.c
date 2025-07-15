void __cdecl ssl_clear_cipher_ctx(ssl_st *s)
{
  if ( s->enc_read_ctx )
  {
    EVP_CIPHER_CTX_cleanup(0, s->enc_read_ctx);
    CRYPTO_free(s->enc_read_ctx);
    s->enc_read_ctx = 0;
  }
  if ( s->enc_write_ctx )
  {
    EVP_CIPHER_CTX_cleanup(0, s->enc_write_ctx);
    CRYPTO_free(s->enc_write_ctx);
    s->enc_write_ctx = 0;
  }
  if ( s->expand )
  {
    COMP_CTX_free(s->expand);
    s->expand = 0;
  }
  if ( s->compress )
  {
    COMP_CTX_free(s->compress);
    s->compress = 0;
  }
}

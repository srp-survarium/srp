void __cdecl SSL_set_accept_state(ssl_st *s)
{
  const ssl_method_st *method; // eax

  method = s->method;
  s->server = 1;
  s->shutdown = 0;
  s->state = 24576;
  s->handshake_func = method->ssl_accept;
  ssl_clear_cipher_ctx(s);
  if ( s->read_hash )
    EVP_MD_CTX_destroy(0, s->read_hash);
  s->read_hash = 0;
  if ( s->write_hash )
    EVP_MD_CTX_destroy(0, s->write_hash);
  s->write_hash = 0;
}

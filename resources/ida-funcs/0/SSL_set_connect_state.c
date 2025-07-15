void __usercall SSL_set_connect_state(int a1@<ebx>, ssl_st *s)
{
  const ssl_method_st *method; // eax

  method = s->method;
  s->server = 0;
  s->shutdown = 0;
  s->state = 20480;
  s->handshake_func = method->ssl_connect;
  ssl_clear_cipher_ctx(a1, s);
  if ( s->read_hash )
    EVP_MD_CTX_destroy(0, a1, s->read_hash);
  s->read_hash = 0;
  if ( s->write_hash )
    EVP_MD_CTX_destroy(0, a1, s->write_hash);
  s->write_hash = 0;
}

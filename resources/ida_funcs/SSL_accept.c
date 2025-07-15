int __cdecl SSL_accept(ssl_st *s)
{
  if ( !s->handshake_func )
    SSL_set_accept_state(s);
  return s->method->ssl_accept(s);
}

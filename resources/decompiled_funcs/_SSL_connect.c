int __cdecl SSL_connect(ssl_st *s)
{
  if ( !s->handshake_func )
    SSL_set_connect_state(s);
  return s->method->ssl_connect(s);
}

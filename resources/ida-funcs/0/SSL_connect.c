int __usercall SSL_connect@<eax>(int a1@<ebx>, ssl_st *s)
{
  if ( !s->handshake_func )
    SSL_set_connect_state(a1, s);
  return s->method->ssl_connect(s);
}

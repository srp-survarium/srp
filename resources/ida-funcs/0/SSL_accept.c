int __usercall SSL_accept@<eax>(int a1@<ebx>, ssl_st *s)
{
  if ( !s->handshake_func )
    SSL_set_accept_state(a1, s);
  return s->method->ssl_accept(s);
}

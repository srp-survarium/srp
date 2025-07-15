void __usercall tls1_free(unsigned int a1@<edi>, ssl_st *s)
{
  if ( s->tlsext_session_ticket )
    CRYPTO_free(s->tlsext_session_ticket);
  ssl3_free(a1, s);
}

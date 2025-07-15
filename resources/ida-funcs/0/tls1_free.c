void __usercall tls1_free(int a1@<edi>, int a2@<ebx>, ssl_st *s)
{
  if ( s->tlsext_session_ticket )
    CRYPTO_free(s->tlsext_session_ticket);
  ssl3_free(a1, a2, s);
}

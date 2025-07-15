void __cdecl ssl2_free(ssl_st *s)
{
  ssl2_state_st *s2; // esi

  if ( s )
  {
    s2 = s->s2;
    if ( s2->rbuf )
      CRYPTO_free(s2->rbuf);
    if ( s2->wbuf )
      CRYPTO_free(s2->wbuf);
    OPENSSL_cleanse(s2, 288);
    CRYPTO_free(s2);
    s->s2 = 0;
  }
}

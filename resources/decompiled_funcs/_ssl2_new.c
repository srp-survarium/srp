int __cdecl ssl2_new(ssl_st *s)
{
  ssl2_state_st *v1; // eax
  ssl2_state_st *v2; // esi
  unsigned __int8 *v3; // eax
  unsigned __int8 *v4; // eax

  v1 = (ssl2_state_st *)CRYPTO_malloc(288, ".\\ssl\\s2_lib.c", 323);
  v2 = v1;
  if ( !v1 )
    return 0;
  memset((int)v1, 0, sizeof(ssl2_state_st));
  v3 = (unsigned __int8 *)CRYPTO_malloc(32769, ".\\ssl\\s2_lib.c", 331);
  v2->rbuf = v3;
  if ( !v3 || (v4 = (unsigned __int8 *)CRYPTO_malloc(32770, ".\\ssl\\s2_lib.c", 335), (v2->wbuf = v4) == 0) )
  {
    if ( v2->wbuf )
      CRYPTO_free(v2->wbuf);
    if ( v2->rbuf )
      CRYPTO_free(v2->rbuf);
    CRYPTO_free(v2);
    return 0;
  }
  s->s2 = v2;
  ssl2_clear(s);
  return 1;
}

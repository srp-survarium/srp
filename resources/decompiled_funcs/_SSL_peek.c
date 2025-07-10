int __cdecl SSL_peek(ssl_st *s)
{
  if ( s->handshake_func )
  {
    if ( (s->shutdown & 2) != 0 )
      return 0;
    else
      return ((int (*)(void))s->method->ssl_peek)();
  }
  else
  {
    ERR_put_error(0x14u, 270, 276, ".\\ssl\\ssl_lib.c", 961);
    return -1;
  }
}

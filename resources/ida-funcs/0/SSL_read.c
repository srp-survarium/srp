int __cdecl SSL_read(ssl_st *s)
{
  if ( s->handshake_func )
  {
    if ( (s->shutdown & 2) != 0 )
    {
      s->rwstate = 1;
      return 0;
    }
    else
    {
      return ((int (*)(void))s->method->ssl_read)();
    }
  }
  else
  {
    ERR_put_error(0x14u, 223, 276, ".\\ssl\\ssl_lib.c", 945);
    return -1;
  }
}

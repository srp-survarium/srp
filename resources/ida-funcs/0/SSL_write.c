int __cdecl SSL_write(ssl_st *s)
{
  if ( s->handshake_func )
  {
    if ( (s->shutdown & 1) != 0 )
    {
      s->rwstate = 1;
      ERR_put_error(0x14u, 208, 207, ".\\ssl\\ssl_lib.c", 983);
      return -1;
    }
    else
    {
      return ((int (*)(void))s->method->ssl_write)();
    }
  }
  else
  {
    ERR_put_error(0x14u, 208, 276, ".\\ssl\\ssl_lib.c", 976);
    return -1;
  }
}

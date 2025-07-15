int __usercall SSL_write@<eax>(int a1@<ebx>, ssl_st *s)
{
  if ( s->handshake_func )
  {
    if ( (s->shutdown & 1) != 0 )
    {
      s->rwstate = 1;
      ERR_put_error(a1, 0x14u, 208, 207, ".\\ssl\\ssl_lib.c", 983);
      return -1;
    }
    else
    {
      return ((int (*)(void))s->method->ssl_write)();
    }
  }
  else
  {
    ERR_put_error(a1, 0x14u, 208, 276, ".\\ssl\\ssl_lib.c", 976);
    return -1;
  }
}

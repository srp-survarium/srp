int __usercall SSL_read@<eax>(int a1@<ebx>, ssl_st *s)
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
    ERR_put_error(a1, 0x14u, 223, 276, ".\\ssl\\ssl_lib.c", 945);
    return -1;
  }
}

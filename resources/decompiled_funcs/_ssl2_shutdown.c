int __cdecl ssl2_shutdown(ssl_st *s)
{
  s->shutdown = 3;
  return 1;
}

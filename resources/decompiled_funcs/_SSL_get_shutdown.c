int __cdecl SSL_get_shutdown(const ssl_st *s)
{
  return s->shutdown;
}

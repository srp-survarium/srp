int __cdecl SSL_get_default_timeout(const ssl_st *s)
{
  return s->method->get_timeout();
}

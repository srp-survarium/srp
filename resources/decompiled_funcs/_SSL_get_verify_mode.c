int __cdecl SSL_get_verify_mode(const ssl_st *s)
{
  return s->verify_mode;
}

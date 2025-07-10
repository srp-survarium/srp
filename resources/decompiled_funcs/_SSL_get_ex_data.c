void *__cdecl SSL_get_ex_data(const ssl_st *s, int idx)
{
  return CRYPTO_get_ex_data(&s->ex_data, idx);
}

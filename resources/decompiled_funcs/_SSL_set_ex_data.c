int __cdecl SSL_set_ex_data(ssl_st *s, int idx, void *arg)
{
  return CRYPTO_set_ex_data(&s->ex_data, idx, arg);
}

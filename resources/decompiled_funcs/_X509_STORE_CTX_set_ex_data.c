int __cdecl X509_STORE_CTX_set_ex_data(ssl_ctx_st *s, int idx, void *arg)
{
  return CRYPTO_set_ex_data(&s->ex_data, idx, arg);
}

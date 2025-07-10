void *__cdecl X509_STORE_CTX_get_ex_data(const ssl_ctx_st *s, int idx)
{
  return CRYPTO_get_ex_data(&s->ex_data, idx);
}

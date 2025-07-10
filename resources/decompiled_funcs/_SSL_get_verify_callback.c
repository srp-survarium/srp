int (__cdecl *__cdecl SSL_get_verify_callback(const ssl_st *s))(int, x509_store_ctx_st *)
{
  return s->verify_callback;
}

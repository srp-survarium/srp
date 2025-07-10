void __cdecl SSL_set_verify(ssl_st *s, int mode, int (__cdecl *callback)(int, x509_store_ctx_st *))
{
  s->verify_mode = mode;
  if ( callback )
    s->verify_callback = callback;
}

stack_st_SSL_CIPHER *__cdecl SSL_get_ciphers(const ssl_st *s)
{
  stack_st_SSL_CIPHER *result; // eax
  ssl_ctx_st *ctx; // eax

  if ( !s )
    return 0;
  result = s->cipher_list;
  if ( !result )
  {
    ctx = s->ctx;
    if ( !ctx )
      return 0;
    result = ctx->cipher_list;
    if ( !result )
      return 0;
  }
  return result;
}
